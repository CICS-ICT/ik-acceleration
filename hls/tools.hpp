#ifndef TOOLS_HPP
#define TOOLS_HPP

#include "config.hpp"
#include <cmath>

namespace TOOLS {

    class TOOLS
    {
    public:
        TOOLS(float _chain[MAX_DEGREE][18], bool _joint_type[MAX_DEGREE], int _N);
        ~TOOLS(){};

        void my_fk_solver(float q_in[MAX_DEGREE], float end[12]);
        void my_jac_solver(float q_in[MAX_DEGREE], float end_pos[3], float jac[6][MAX_DEGREE]);
        void diff(float b1[12], float b2[12], float ret[6]);

    private:
        // int N;
        int steps;

        // joint_type: 0 Rot, 1 Trans. 
        // joint 0:3 axis, 3:6 origin.
        // tip 0:9 M, 9:12 p.
        bool joint_type[MAX_DEGREE];
        float joint[MAX_DEGREE][6];
        float tip[MAX_DEGREE][12];


        inline static void clear_frame(float in[12]) {
            in[0] = 1; in[1] = 0; in[2] = 0;
            in[3] = 0; in[4] = 1; in[5] = 0;
            in[6] = 0; in[7] = 0; in[8] = 1;
            in[9] = 0;
            in[10] = 0;
            in[11] = 0;
        }

        inline static void clear_6(float in[6]) {
            in[0] = 0; in[1] = 0; in[2] = 0;
            in[3] = 0; in[4] = 0; in[5] = 0;
        }

        inline static void assign_3(float in[3], float out[3]) {
            out[0] = in[0];
            out[1] = in[1];
            out[2] = in[2];
        }

        inline static void assign_6(float in[6], float out[6]) {
            out[0] = in[0];
            out[1] = in[1];
            out[2] = in[2];
            out[3] = in[3];
            out[4] = in[4];
            out[5] = in[5];
        }

        inline static void assign_9(float in[9], float out[9]) {
            out[0] = in[0];
            out[1] = in[1];
            out[2] = in[2];
            out[3] = in[3];
            out[4] = in[4];
            out[5] = in[5];
            out[6] = in[6];
            out[7] = in[7];
            out[8] = in[8];
        }

        inline static void assign_12(float in[12], float out[12]) {
            out[0] = in[0];
            out[1] = in[1];
            out[2] = in[2];
            out[3] = in[3];
            out[4] = in[4];
            out[5] = in[5];
            out[6] = in[6];
            out[7] = in[7];
            out[8] = in[8];
            out[9] = in[9];
            out[10] = in[10];
            out[11] = in[11];
        }

        inline static void add_pp(float l[3], float r[3], float ret[3]) {
            ret[0] = l[0] + r[0];
            ret[1] = l[1] + r[1];
            ret[2] = l[2] + r[2];
        }

        inline static void add_cp(float l[3], float r[3], float c, float ret[3]) {
            ret[0] = l[0] + c * r[0];
            ret[1] = l[1] + c * r[1];
            ret[2] = l[2] + c * r[2];
        }

        inline static void sub_cp6(float l[6], float r[6], float c, float ret[6]) {
            ret[0] = l[0] - c * r[0];
            ret[1] = l[1] - c * r[1];
            ret[2] = l[2] - c * r[2];
            ret[3] = l[3] - c * r[3];
            ret[4] = l[4] - c * r[4];
            ret[5] = l[5] - c * r[5];
        }

        inline static void sub_pp(float l[3], float r[3], float ret[3]) {
            ret[0] = l[0] - r[0];
            ret[1] = l[1] - r[1];
            ret[2] = l[2] - r[2];
        }

        inline static float dot(float l[3], float r[3]) {
            return l[0]*r[0]+l[1]*r[1]+l[2]*r[2];
        }

        inline static float dot6(float l[6], float r[6]) {
            return l[0]*r[0] + l[1]*r[1] + l[2]*r[2] + l[3]*r[3] + l[4]*r[4] + l[5]*r[5];
        }

        inline static void cross(float l[3], float r[3], float ret[3]) {
            ret[0] = l[1]*r[2]-l[2]*r[1];
            ret[1] = l[2]*r[0]-l[0]*r[2];
            ret[2] = l[0]*r[1]-l[1]*r[0];
        }

        inline static void mul_cp(float l[3], float c, float ret[3]) {
            ret[0] = c * l[0];
            ret[1] = c * l[1];
            ret[2] = c * l[2];
        }

        inline static void mul_Mp(float M[9], float p[3], float ret[3]) {
            ret[0]=M[0]*p[0]+M[1]*p[1]+M[2]*p[2];
            ret[1]=M[3]*p[0]+M[4]*p[1]+M[5]*p[2];
            ret[2]=M[6]*p[0]+M[7]*p[1]+M[8]*p[2];
        }

        inline static void mul_MM(float l[9], float r[9], float ret[9]) {
            ret[0]=l[0]*r[0]+l[1]*r[3]+l[2]*r[6];
            ret[1]=l[0]*r[1]+l[1]*r[4]+l[2]*r[7];
            ret[2]=l[0]*r[2]+l[1]*r[5]+l[2]*r[8];
            ret[3]=l[3]*r[0]+l[4]*r[3]+l[5]*r[6];
            ret[4]=l[3]*r[1]+l[4]*r[4]+l[5]*r[7];
            ret[5]=l[3]*r[2]+l[4]*r[5]+l[5]*r[8];
            ret[6]=l[6]*r[0]+l[7]*r[3]+l[8]*r[6];
            ret[7]=l[6]*r[1]+l[7]*r[4]+l[8]*r[7];
            ret[8]=l[6]*r[2]+l[7]*r[5]+l[8]*r[8];
        }

        inline static void mul_Fp(float F[12], float p[3], float ret[3]) {
            ret[0]=F[0]*p[0]+F[1]*p[1]+F[2]*p[2]+F[9];
            ret[1]=F[3]*p[0]+F[4]*p[1]+F[5]*p[2]+F[10];
            ret[2]=F[6]*p[0]+F[7]*p[1]+F[8]*p[2]+F[11];
        }

        inline static void mul_FF(float l[12], float r[12], float ret[12]) {
            ret[0]=l[0]*r[0]+l[1]*r[3]+l[2]*r[6];
            ret[1]=l[0]*r[1]+l[1]*r[4]+l[2]*r[7];
            ret[2]=l[0]*r[2]+l[1]*r[5]+l[2]*r[8];
            ret[3]=l[3]*r[0]+l[4]*r[3]+l[5]*r[6];
            ret[4]=l[3]*r[1]+l[4]*r[4]+l[5]*r[7];
            ret[5]=l[3]*r[2]+l[4]*r[5]+l[5]*r[8];
            ret[6]=l[6]*r[0]+l[7]*r[3]+l[8]*r[6];
            ret[7]=l[6]*r[1]+l[7]*r[4]+l[8]*r[7];
            ret[8]=l[6]*r[2]+l[7]*r[5]+l[8]*r[8];
            ret[9]=l[0]*r[9]+l[1]*r[10]+l[2]*r[11]+l[9];
            ret[10]=l[3]*r[9]+l[4]*r[10]+l[5]*r[11]+l[10];
            ret[11]=l[6]*r[9]+l[7]*r[10]+l[8]*r[11]+l[11];
        }

        static void rot2M(float rotvec[3], float angle, float M[9]) {
            float ct = cosf(angle);
            float st = sinf(angle);
            float vt = 1-ct;
            float m_vt_0=vt*rotvec[0];
            float m_vt_1=vt*rotvec[1];
            float m_vt_2=vt*rotvec[2];
            float m_st_0=rotvec[0]*st;
            float m_st_1=rotvec[1]*st;
            float m_st_2=rotvec[2]*st;
            float m_vt_0_1=m_vt_0*rotvec[1];
            float m_vt_0_2=m_vt_0*rotvec[2];
            float m_vt_1_2=m_vt_1*rotvec[2];
            M[0] = ct      +  m_vt_0*rotvec[0];
            M[1] = -m_st_2 +  m_vt_0_1;
            M[2] = m_st_1  +  m_vt_0_2;
            M[3] = m_st_2  +  m_vt_0_1;
            M[4] = ct      +  m_vt_1*rotvec[1];
            M[5] = -m_st_0 +  m_vt_1_2;
            M[6] = -m_st_1 +  m_vt_0_2;
            M[7] = m_st_0  +  m_vt_1_2;
            M[8] = ct      +  m_vt_2*rotvec[2];
        }

        static void M2rot(float M[9], float axis[3]) {
            float ca = (M[0]+M[4]+M[8]-1)/2.0;
            float t = 1e-9;
            if (ca>1-t) {
                // undefined choose the Z-axis, and angle 0
                // axis = Vector(0,0,1);
                axis[0] = 0;
                axis[1] = 0;
                axis[2] = 0;
            } else if (ca < -1+t) {
                // The case of angles consisting of multiples of M_PI:
                // two solutions, choose a positive Z-component of the axis
                float x = sqrtf( (M[0]+1.0)/2);
                float y = sqrtf( (M[4]+1.0)/2);
                float z = sqrtf( (M[8]+1.0)/2);
                if ( M[2] < 0) x=-x;
                if ( M[7] < 0) y=-y;
                if ( x*y*M[1] < 0) x=-x;  // this last line can be necessary when z is 0
                // z always >= 0 
                // if z equal to zero 
                axis[0] = x * M_PI;
                axis[1] = y * M_PI;
                axis[2] = z * M_PI;
            } else {
                float axis_ratio;
                float mod_axis;
                float axisx, axisy, axisz;
                axisx = M[7]-M[5];
                axisy = M[2]-M[6];
                axisz = M[3]-M[1];
                mod_axis = sqrtf(axisx*axisx+axisy*axisy+axisz*axisz);
                axis_ratio = atan2f(mod_axis/2,ca) / mod_axis;
                axis[0] = axisx * axis_ratio;
                axis[1] = axisy * axis_ratio;
                axis[2] = axisz * axis_ratio;
            }
        }

    };

}


#endif
