#ifndef HLS_IK_HPP
#define HLS_IK_HPP

#include "hls_math.h"
#include "config.hpp"

namespace HLS_IK {

    class HLS
    {
    public:
        HLS(float _chain[MAX_DEGREE][18], bool _joint_type[MAX_DEGREE], int _N, int _steps=1000, float _eps=1e-5);
        ~HLS(){};

        int my_ik(float q_init[MAX_DEGREE], float p_in[12], float q_out[MAX_DEGREE]);
        // void my_fk_solver(float q_in[MAX_DEGREE], float end[12]);
        // void my_fk_solver(float q_in[MAX_DEGREE], float ret[12], float tip[MAX_DEGREE][12], float joint[MAX_DEGREE][6], int joint_trans[MAX_DEGREE], int joint_rot[MAX_DEGREE], int joint_trans_index, int joint_rot_index);
        void my_fk_solver(float q_in[MAX_DEGREE], float ret[12], float tip[MAX_DEGREE][12], float joint[MAX_DEGREE][6], bool joint_type[MAX_DEGREE]);
        // void my_jac_solver(float q_in[MAX_DEGREE], float end_pos[3], float jacT[MAX_DEGREE][6]);
        void my_jac_solver(float q_in[MAX_DEGREE], float end_pos[3], float jac[6][MAX_DEGREE], float &range, float tip[MAX_DEGREE][12], float joint[MAX_DEGREE][6], bool joint_type[MAX_DEGREE]);
        void diff(float b1[12], float b2[12], float ret[6]);

        // int N;
        int steps;
        float eps;
        int G_joint_rot_index;
        int G_joint_trans_index;

        // joint_type: 0 Rot, 1 Trans. 
        // joint 0:3 axis, 3:6 origin.
        // tip 0:9 M, 9:12 p.
        bool G_joint_type[LMU_number][MAX_DEGREE];
        int G_joint_trans[LMU_number][MAX_DEGREE];
        int G_joint_rot[LMU_number][MAX_DEGREE];
        float G_joint[LMU_number][MAX_DEGREE][6];
        float G_tip[LMU_number][MAX_DEGREE][12];

        static const float Random_Matrix[768];
        static const float step_length[LMU_number];

        void clear_frame(float in[12]);
        void clear_6(float in[6]);
        void assign_3(float in[3], float out[3]);
        void assign_6(float in[6], float out[6]);
        void assign_9(float in[9], float out[9]);
        void assign_12(float in[12], float out[12]);
        void add_pp(float l[3], float r[3], float ret[3]);
        void add_cp(float l[3], float r[3], float c, float ret[3]);
        void sub_cp6(float l[6], float r[6], float c, float ret[6]);
        void sub_pp(float l[3], float r[3], float ret[3]);
        float dot(float l[3], float r[3]);
        float dot6(float l[6], float r[6]);
        void cross(float l[3], float r[3], float ret[3]);
        void mul_cp(float l[3], float c, float ret[3]);
        void mul_Mp(float M[9], float p[3], float ret[3]);
        void mul_MM(float l[9], float r[9], float ret[9]);
        void mul_Fp(float F[12], float p[3], float ret[3]);
        void mul_FF(float l[12], float r[12], float ret[12]);
        void mul_Mp_block(float M[9], float p[3], float ret[3]);
        void mul_MM_block(float l[9], float r[9], float ret[9]);
        void mul_Fp_block(float F[12], float p[3], float ret[3]);
        void mul_FF_block(float l[12], float r[12], float ret[12]);
        void rot2M(float rotvec[3], float angle, float M[9]);
        void M2rot(float M[9], float axis[3]);
        // void jac_transpose(float jac[6][MAX_DEGREE], float jacT[MAX_DEGREE][6]);
        // void R_generate(float jac[6][MAX_DEGREE], float R[MAX_DEGREE][6], float c, int index);
        // void JRe_calculate(float J[6][MAX_DEGREE], float R[MAX_DEGREE][6], float e[6], float ret[6]);
        // void dist_estimate(float Jac[6][MAX_DEGREE], float Rt[MAX_DEGREE][6], float e[6], float range, float *dt, float *at, int offset);
        // void dist_calculate(float q_out[MAX_DEGREE], float delta_q[MAX_DEGREE], float p_in[12], float *dt, float ratio);
        void direction_determination(float JT[MAX_DEGREE][6], float e[6], float range, int sp, float delta_q[MAX_DEGREE], float &alpha);
        void line_minimization(float q_out[MAX_DEGREE], float delta_q[MAX_DEGREE], float p_in[12], float alpha, float q_next[MAX_DEGREE], float *error_min);

    };

}

int hls_ik(int _N, int steps, float eps, float hls_chain[MAX_DEGREE][18], bool hls_joint_type[MAX_DEGREE], float q_in[MAX_DEGREE], float f_in[12], float q_out[MAX_DEGREE]);

#endif
