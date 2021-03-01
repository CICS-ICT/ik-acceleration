#include "tools.hpp"

namespace TOOLS {

    TOOLS::TOOLS(float _chain[MAX_DEGREE][18], bool _joint_type[MAX_DEGREE], int _N) {
        // N = _N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 12; j++) {
                tip[i][j] = _chain[i][j];
            }
            for (int j = 0; j < 6; j++) {
                joint[i][j] = _chain[i][j+12];
            }
            joint_type[i] = _joint_type[i];
        }
    }

    void TOOLS::my_fk_solver(float q_in[MAX_DEGREE], float ret[12])
    {
        float temp_joint[12];
        float temp_end[12];
        float temp_pos[3];
        float end[12];
        clear_frame(end);
        for (int i = 0; i < N; i++) {
            if (joint_type[i]) {
                // trans
                // end.M*tip.M
                mul_MM(end, tip[i], temp_end);
                // joint.pos
                add_cp(joint[i]+3, joint[i], q_in[i], temp_pos);
                // joint.pos+tip.pos
                add_pp(temp_pos, tip[i]+9, temp_pos);
                // end.M*(joint.pos+tip.pos)
                mul_Mp(end, temp_pos, temp_end+9);
                // end.M*(joint.pos+tip.pos)+end.p
                add_pp(temp_end+9, end+9, end+9);
                assign_9(temp_end, end);
            } else {
                // rot
                rot2M(joint[i], q_in[i], temp_joint);
                assign_3(joint[i]+3, temp_joint+9);
                mul_FF(end, temp_joint, temp_end);
                mul_FF(temp_end, tip[i], end);
            }
        }
        assign_12(end, ret);

        // float T[MAX_DEGREE*2][12];
        // float joint_F[MAX_DEGREE][12];

        // LOOP_FK_Joint:
        // for (int i = 0; i < N; i++) {
        //     if (joint_type[i]) {
        //         // trans
        //         // tip.M
        //         assign_9(tip[i], T[i]);
        //         // joint.p
        //         add_cp(joint[i]+3, joint[i], q_in[i], T[i]+9);
        //         // joint.p+tip.p (tip.p=0?)
        //         add_pp(T[i]+9, tip[i]+9, T[i]+9);
        //     } else {
        //         // rot
        //         // joint.pos
        //         rot2M(joint[i], q_in[i], joint_F[i]);
        //         assign_3(joint[i]+3, joint_F[i]+9);
        //         // joint.pos*tip
        //         mul_FF(joint_F[i], tip[i], T[i]);
        //     }
        // }

        // LOOP_FK_left:
        // for (int i = N; i < MAX_DEGREE; i++) {
        //     clear_frame(T[i]);
        // }

        // LOOP_FK_64:
        // for (int k = 0; k < 64; k++) {
        //     mul_FF(T[k*2], T[k*2+1], T[k+128]);
        // }
        // LOOP_FK_32:
        // for (int k = 0; k < 32; k++) {
        //     mul_FF(T[k*2+128], T[k*2+129], T[k+192]);
        // }
        // LOOP_FK_16:
        // for (int k = 0; k < 16; k++) {
        //     mul_FF(T[k*2+192], T[k*2+193], T[k+224]);
        // }
        // LOOP_FK_8:
        // for (int k = 0; k < 8; k++) {
        //     mul_FF(T[k*2+224], T[k*2+225], T[k+240]);
        // }
        // LOOP_FK_4:
        // for (int k = 0; k < 4; k++) {
        //     mul_FF(T[k*2+240], T[k*2+241], T[k+248]);
        // }
        // LOOP_FK_2:
        // for (int k = 0; k < 2; k++) {
        //     mul_FF(T[k*2+248], T[k*2+249], T[k+252]);
        // }
        // mul_FF(T[252], T[253], T[254]);
        // assign_12(T[254], ret);
    }

    void TOOLS::my_jac_solver(float q_in[MAX_DEGREE], float end_pos[3], float jac[6][MAX_DEGREE])
    {
        float temp_F[12];
        float temp_joint[12];
        float temp_end[12];
        float temp_twist[6];
        float temp_pos[3];
        float temp_arm[3];
        clear_frame(temp_F);
        for (int i = 0; i < N; i++) {
            temp_twist[3] = 0;
            temp_twist[4] = 0;
            temp_twist[5] = 0;
            if (joint_type[i]) {
                // trans

                // jac
                mul_cp(joint[i], 1.0, temp_pos);
                mul_Mp(temp_F, temp_pos, temp_twist);

                // fk
                mul_MM(temp_F, tip[i], temp_end);
                add_cp(joint[i]+3, joint[i], q_in[i], temp_pos);
                add_pp(temp_pos, tip[i]+9, temp_pos);
                mul_Mp(temp_F, temp_pos, temp_end+9);
                add_pp(temp_end+9, temp_F+9, temp_F+9);
                assign_9(temp_end, temp_F);
            } else {
                // rot

                // jac
                // twist rot
                mul_cp(joint[i], 1.0, temp_pos);
                mul_Mp(temp_F, temp_pos, temp_twist+3);
                // rot axis
                mul_Mp(temp_F, joint[i], temp_pos);
                // rot arm
                mul_Fp(temp_F, joint[i]+3, temp_arm);
                sub_pp(end_pos, temp_arm, temp_arm);
                // twist vel
                cross(temp_pos, temp_arm, temp_twist);

                // fk
                rot2M(joint[i], q_in[i], temp_joint);
                assign_3(joint[i]+3, temp_joint+9);
                mul_FF(temp_F, temp_joint, temp_end);
                mul_FF(temp_end, tip[i], temp_F);
            }
            jac[0][i] = temp_twist[0];
            jac[1][i] = temp_twist[1];
            jac[2][i] = temp_twist[2];
            jac[3][i] = temp_twist[3];
            jac[4][i] = temp_twist[4];
            jac[5][i] = temp_twist[5];
        }
    }

    void TOOLS::diff(float b1[12], float b2[12], float ret[6]) {
        float rot[3];
        float b12[9];
        float b1_M_inverse[9];
        b1_M_inverse[0] = b1[0];
        b1_M_inverse[1] = b1[3];
        b1_M_inverse[2] = b1[6];
        b1_M_inverse[3] = b1[1];
        b1_M_inverse[4] = b1[4];
        b1_M_inverse[5] = b1[7];
        b1_M_inverse[6] = b1[2];
        b1_M_inverse[7] = b1[5];
        b1_M_inverse[8] = b1[8];
        mul_MM(b1_M_inverse, b2, b12);
        M2rot(b12, rot);
        mul_Mp(b1, rot, ret+3);
        ret[0] = b2[9] - b1[9];
        ret[1] = b2[10] - b1[10];
        ret[2] = b2[11] - b1[11];
    }

}
