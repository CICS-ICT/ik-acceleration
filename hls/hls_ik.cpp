#include "hls_ik.hpp"

namespace HLS_IK {

    const float HLS::Random_Matrix[768] = {
        -0.215199,0.381915,-0.959088,-0.864555,-0.626460,-0.863995,0.339871,0.848700,-0.223797,0.079770,-0.170687,0.921566,-0.657668,-0.783003,0.426868,0.810253,0.481296,0.036145,-0.319357,0.688280,-0.750808,-0.864272,-0.030965,0.708601,-0.959398,-0.023081,-0.097569,0.687062,-0.142865,-0.478885,-0.585161,0.641936,0.903029,-0.544248,0.777381,-0.723431,-0.408243,0.117253,-0.874731,0.367960,-0.802977,-0.045418,0.289526,-0.460646,0.171579,-0.283606,-0.650393,-0.347125,0.752539,0.030251,-0.658845,-0.998269,0.165979,0.310190,0.710332,0.206581,-0.712892,-0.387237,-0.106357,0.144244,0.133878,0.308482,-0.213820,0.036907,0.764234,-0.436439,0.313476,-0.644009,0.680814,0.438745,0.723951,0.877837,-0.606672,0.013477,-0.582809,0.564907,0.729871,-0.233201,-0.782218,0.482410,0.797049,-0.441063,0.484141,-0.036971,0.869127,0.194473,-0.830390,-0.843765,0.807236,0.063253,0.300479,-0.058886,-0.628265,-0.913341,0.978021,-0.864031,-0.349780,0.291497,-0.508040,-0.668966,-0.269757,-0.784089,-0.791129,0.123570,0.229388,-0.373938,-0.311523,-0.040741,0.392861,-0.093741,-0.558330,0.189910,0.465196,0.925811,-0.847061,0.334323,0.120284,-0.677451,0.490558,-0.072480,0.385802,-0.208963,0.868634,0.757537,-0.122304,0.846655,0.893506,0.527916,0.138152,-0.614534,0.858951,0.868395,-0.398623,-0.932178,-0.008035,0.830765,-0.306116,0.680442,-0.209975,-0.913255,-0.413299,0.231694,0.276655,-0.948103,0.157505,0.429594,0.386220,-0.722211,0.752143,-0.123222,0.205309,0.137945,0.667815,0.073942,-0.104517,-0.454489,-0.079403,-0.211011,-0.926572,-0.941251,0.174455,0.932379,0.927144,0.775832,-0.999800,-0.080891,0.606597,-0.305916,-0.400449,-0.603378,-0.219171,0.186252,0.628316,-0.942516,0.238149,-0.214179,0.487078,-0.375631,0.063609,0.239221,0.501147,-0.731082,-0.622834,0.168962,0.342860,0.272649,0.714474,-0.736543,-0.938362,0.787902,-0.677793,0.236093,0.720280,-0.750649,0.011925,0.720481,0.168459,-0.381477,-0.585435,0.768010,0.015144,0.195394,-0.045738,-0.356540,0.252878,-0.807590,0.429281,-0.260044,-0.183221,-0.507110,0.979177,-0.682073,-0.238192,-0.643657,0.486889,-0.895332,0.628991,0.201363,-0.631874,0.690629,-0.010735,-0.309668,-0.073278,-0.290455,-0.060317,0.938648,-0.569974,-0.891857,-0.442829,-0.155409,0.876152,0.572315,-0.960014,-0.169586,-0.784225,0.292864,0.022825,0.645056,-0.967181,0.839604,-0.862054,-0.988004,-0.842469,-0.100246,-0.631662,0.644420,0.004422,0.997330,-0.154217,0.372548,0.687959,0.835047,-0.937120,-0.385319,-0.455407,0.002563,-0.446671,-0.025381,0.110706,0.110500,0.819211,-0.013142,-0.317185,0.859196,0.817273,-0.101410,0.152060,-0.159903,-0.456354,0.184879,-0.320299,-0.318408,0.196875,-0.162768,0.581346,0.565214,-0.518349,-0.414232,0.562543,0.327434,0.958316,0.250502,0.162481,-0.978804,0.865184,0.707074,0.023760,-0.581487,-0.318307,-0.865534,0.529013,-0.499096,0.121324,-0.788172,-0.639900,-0.061403,0.110418,0.512159,0.778694,0.654064,-0.302961,-0.541605,-0.664344,0.893914,0.295627,0.917002,0.459127,0.777278,-0.497230,0.021671,0.104712,-0.538914,-0.727827,-0.732807,-0.517717,-0.862643,0.974267,0.506043,-0.444129,-0.344040,0.640509,-0.915116,0.156864,-0.238167,-0.703288,0.516963,0.700430,0.407129,0.029123,0.479124,0.061193,0.726162,0.937519,0.396849,0.620075,0.233145,0.313851,0.079203,0.010423,0.816621,-0.899126,-0.884865,-0.722292,-0.626953,-0.617672,-0.240010,-0.489595,-0.643405,-0.733967,0.066275,0.012555,0.906542,0.151159,-0.830581,-0.331626,0.447871,0.686382,-0.631196,-0.145000,-0.284495,0.847928,0.916193,-0.558333,0.785446,0.313042,-0.938258,0.018592,-0.373106,0.140945,-0.970985,-0.556485,0.241819,-0.855850,-0.278778,0.614867,-0.473521,0.481213,-0.874729,-0.116926,0.747246,0.191546,0.895629,0.653788,-0.657295,-0.934952,-0.677838,0.790576,0.751430,-0.309034,-0.354424,-0.533064,-0.461106,-0.438231,-0.091397,-0.675660,0.874812,-0.029655,0.342932,-0.498295,-0.888709,0.371948,-0.054780,0.353110,0.516098,0.666442,-0.032023,-0.957423,0.147655,0.093248,-0.074350,-0.105099,-0.715206,-0.178721,-0.451311,-0.372500,-0.113673,-0.129149,-0.581925,-0.362242,0.561818,0.063651,0.104693,-0.899288,0.625420,-0.986704,-0.574948,0.500232,-0.016359,0.767984,-0.998063,0.094932,0.139932,-0.052843,-0.551958,-0.343970,-0.386401,0.416018,-0.301394,0.761255,-0.490734,0.624257,-0.343844,-0.205940,-0.554464,0.204845,0.421560,0.331863,-0.924304,0.839635,0.969621,0.637514,-0.096713,0.074314,0.738225,-0.471293,0.087610,-0.836723,-0.971061,-0.928748,0.931262,-0.969124,0.166183,0.071193,-0.021967,0.614225,0.727223,0.591632,0.030243,-0.574171,0.352887,0.539509,-0.949914,-0.990957,-0.666431,-0.504378,0.213888,0.755128,0.827486,0.289584,0.594764,0.797107,-0.072902,-0.501950,-0.128578,-0.334677,0.026757,0.959032,-0.171400,0.055696,-0.969716,-0.240138,0.086572,0.196467,0.831055,-0.935395,-0.189309,0.558278,0.656237,0.840934,0.984108,0.009124,0.380443,-0.965806,0.018167,0.714012,-0.470183,-0.767945,0.469140,-0.642697,0.521639,0.063904,-0.845590,-0.551263,0.561954,0.025831,0.114060,-0.411289,-0.015137,0.942660,0.644407,0.015147,-0.297478,-0.269021,-0.788386,-0.466422,-0.204416,0.022305,-0.908144,-0.548179,-0.136761,-0.924036,0.460946,-0.756318,-0.889842,-0.520887,0.957694,-0.360025,-0.288832,0.426834,-0.002723,-0.767193,-0.509263,0.151687,-0.318457,-0.947309,-0.822482,0.795603,-0.358599,0.162382,0.738263,-0.714192,-0.822472,-0.559215,0.016787,-0.610858,-0.025637,0.812371,0.411447,0.066219,-0.735808,-0.725314,0.142183,0.725138,-0.481632,0.252341,-0.795750,-0.523938,0.892315,-0.084582,0.902896,-0.110407,0.148225,-0.606367,-0.958720,0.829768,-0.553677,-0.781202,0.625371,0.087725,0.381179,0.363634,0.373533,0.558708,0.804420,-0.609680,0.947850,-0.221217,-0.797309,0.359297,0.845001,-0.533117,0.633983,-0.012816,-0.807980,-0.847648,-0.760475,-0.603729,-0.371586,-0.868160,0.311689,-0.468691,0.021433,-0.540086,-0.075058,0.062712,-0.710318,0.371265,0.281510,0.915053,-0.541010,-0.337310,0.278687,0.832523,-0.778602,0.083107,-0.777158,-0.830752,0.861889,-0.574467,0.528545,0.706891,-0.107585,0.162528,-0.305925,0.084436,0.314880,-0.066400,0.480707,0.943294,0.065440,-0.207604,-0.525397,-0.913127,0.252310,0.399545,0.149585,0.541992,-0.229189,-0.568904,0.457045,0.229801,0.093785,-0.264268,0.062323,0.315183,0.818839,0.285165,0.484431,0.680728,0.710698,0.012975,0.387619,-0.396886,-0.824497,-0.918306,0.687550,0.490383,0.015294,0.168256,0.433677,-0.919266,0.960652,0.908280,-0.832394,0.212962,0.307825,0.317192,-0.245046,-0.921364,0.748287,-0.788002,0.308436,-0.157927,-0.052270,-0.629241,-0.842744,-0.233431,0.655925,0.641687,-0.552703,0.366623,-0.345338,0.834916,0.969737,-0.169835,0.916610,0.657286,-0.679451,-0.068097,-0.174457,0.754225,0.012637,-0.213805,0.662505,0.180243,0.999157,-0.029670,-0.502565,-0.245890,0.048966,-0.754278,-0.033891,-0.642597,0.087795,0.913838,-0.271838,0.245051,-0.319593,-0.615913,-0.113262,0.127704,0.750710,0.541400,-0.037380,0.720447,-0.628434,-0.120771,0.377733,-0.307886,0.811133,-0.796724,-0.553660,-0.176231,-0.010529,-0.891155,-0.995987,-0.011373,0.079175,-0.498552,0.742738,-0.871858,-0.252829,-0.291154,-0.514456,0.834966,-0.377315,0.213706,0.080017,0.303092,0.597793,0.966755,-0.569204,0.348503,0.508156,0.393415,0.068950,0.879722,-0.727356,-0.553317,-0.428164,-0.916223,-0.350042,0.018176,-0.092454,0.639429,0.127021,-0.088441,-0.371943,-0.793804,0.413007,-0.629206,-0.665662,-0.839822,0.079641,-0.180118,0.995144,0.702326,-0.966412
    };

    const float HLS::step_length[LMU_number] = {
        0.01, 0.02, 0.05, 0.1, 0.2, 0.5, 1, 2, 5, 10
    };

    HLS::HLS(float _chain[MAX_DEGREE][18], bool _joint_type[MAX_DEGREE], int _N, int _steps, float _eps) {
        // N = _N;
        steps = _steps;
        eps = _eps;
        G_joint_rot_index = 0;
        G_joint_trans_index = 0;
        LOOP_init:
        for (int i = 0; i < N; i++) {
            LOOP_init_1:
            for (int j = 0; j < 12; j++) {
                // tip[i][j] = _chain[i][j];
                LOOP_init_1_1:
                for (int k = 0; k < LMU_number; k++) {
                    float tip_ij = _chain[i][j];
                    G_tip[k][i][j] = tip_ij;
                }
            }
            LOOP_init_2:
            for (int j = 0; j < 6; j++) {
                // joint[i][j] = _chain[i][j+12];
                LOOP_init_2_1:
                for (int k = 0; k < LMU_number; k++) {
                    float joint_j = _chain[i][j+12];
                    G_joint[k][i][j] = joint_j;
                }
            }
            if (_joint_type[i]) {
                // trans
                // joint_type[i] = 1;
                // joint_trans[G_joint_trans_index] = i;
                LOOP_init_3:
                for (int k = 0; k < LMU_number; k++) {
                    G_joint_type[k][i] = 1;
                    G_joint_trans[k][G_joint_trans_index] = i;
                }
                G_joint_trans_index++;
            } else {
                // rot
                // joint_type[i] = 0;
                // joint_rot[G_joint_rot_index] = i;
                LOOP_init_4:
                for (int k = 0; k < LMU_number; k++) {
                    G_joint_type[k][i] = 0;
                    G_joint_rot[k][G_joint_rot_index] = i;
                }
                G_joint_rot_index++;
            }
        }

    }

    void HLS::clear_frame(float in[12]) {
        in[0] = 1; in[1] = 0; in[2] = 0;
        in[3] = 0; in[4] = 1; in[5] = 0;
        in[6] = 0; in[7] = 0; in[8] = 1;
        in[9] = 0;
        in[10] = 0;
        in[11] = 0;
    }

    void HLS::clear_6(float in[6]) {
        in[0] = 0; in[1] = 0; in[2] = 0;
        in[3] = 0; in[4] = 0; in[5] = 0;
    }

    void HLS::assign_3(float in[3], float out[3]) {
        out[0] = in[0];
        out[1] = in[1];
        out[2] = in[2];
    }

    void HLS::assign_6(float in[6], float out[6]) {
        out[0] = in[0];
        out[1] = in[1];
        out[2] = in[2];
        out[3] = in[3];
        out[4] = in[4];
        out[5] = in[5];
    }

    void HLS::assign_9(float in[9], float out[9]) {
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

    void HLS::assign_12(float in[12], float out[12]) {
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

    void HLS::add_pp(float l[3], float r[3], float ret[3]) {
        ret[0] = l[0] + r[0];
        ret[1] = l[1] + r[1];
        ret[2] = l[2] + r[2];
    }

    void HLS::add_cp(float l[3], float r[3], float c, float ret[3]) {
        ret[0] = l[0] + c * r[0];
        ret[1] = l[1] + c * r[1];
        ret[2] = l[2] + c * r[2];
    }

    void HLS::sub_cp6(float l[6], float r[6], float c, float ret[6]) {
        ret[0] = l[0] - c * r[0];
        ret[1] = l[1] - c * r[1];
        ret[2] = l[2] - c * r[2];
        ret[3] = l[3] - c * r[3];
        ret[4] = l[4] - c * r[4];
        ret[5] = l[5] - c * r[5];
    }

    void HLS::sub_pp(float l[3], float r[3], float ret[3]) {
        ret[0] = l[0] - r[0];
        ret[1] = l[1] - r[1];
        ret[2] = l[2] - r[2];
    }

    float HLS::dot(float l[3], float r[3]) {
        return l[0]*r[0]+l[1]*r[1]+l[2]*r[2];
    }

    float HLS::dot6(float l[6], float r[6]) {
        return l[0]*r[0] + l[1]*r[1] + l[2]*r[2] + l[3]*r[3] + l[4]*r[4] + l[5]*r[5];
    }

    void HLS::cross(float l[3], float r[3], float ret[3]) {
        ret[0] = l[1]*r[2]-l[2]*r[1];
        ret[1] = l[2]*r[0]-l[0]*r[2];
        ret[2] = l[0]*r[1]-l[1]*r[0];
    }

    void HLS::mul_cp(float l[3], float c, float ret[3]) {
        ret[0] = c * l[0];
        ret[1] = c * l[1];
        ret[2] = c * l[2];
    }

    void HLS::mul_Mp(float M[9], float p[3], float ret[3]) {
        ret[0]=M[0]*p[0]+M[1]*p[1]+M[2]*p[2];
        ret[1]=M[3]*p[0]+M[4]*p[1]+M[5]*p[2];
        ret[2]=M[6]*p[0]+M[7]*p[1]+M[8]*p[2];
    }

    void HLS::mul_MM(float l[9], float r[9], float ret[9]) {
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

    void HLS::mul_Fp(float F[12], float p[3], float ret[3]) {
        ret[0]=F[0]*p[0]+F[1]*p[1]+F[2]*p[2]+F[9];
        ret[1]=F[3]*p[0]+F[4]*p[1]+F[5]*p[2]+F[10];
        ret[2]=F[6]*p[0]+F[7]*p[1]+F[8]*p[2]+F[11];
    }

    void HLS::mul_FF(float l[12], float r[12], float ret[12]) {
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

    void HLS::mul_Mp_block(float M[9], float p[3], float ret[3]) {
        ret[0]=M[0]*p[0]+M[1]*p[1]+M[2]*p[2];
        ret[1]=M[3]*p[0]+M[4]*p[1]+M[5]*p[2];
        ret[2]=M[6]*p[0]+M[7]*p[1]+M[8]*p[2];
    }

    void HLS::mul_MM_block(float l[9], float r[9], float ret[9]) {
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

    void HLS::mul_Fp_block(float F[12], float p[3], float ret[3]) {
        ret[0]=F[0]*p[0]+F[1]*p[1]+F[2]*p[2]+F[9];
        ret[1]=F[3]*p[0]+F[4]*p[1]+F[5]*p[2]+F[10];
        ret[2]=F[6]*p[0]+F[7]*p[1]+F[8]*p[2]+F[11];
    }

    void HLS::mul_FF_block(float l[12], float r[12], float ret[12]) {
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

    void HLS::rot2M(float rotvec[3], float angle, float M[9]) {
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

    void HLS::M2rot(float M[9], float axis[3]) {
        float ca = (M[0]+M[4]+M[8]-1)/2;
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
            float x = sqrtf( (M[0]+1)/2);
            float y = sqrtf( (M[4]+1)/2);
            float z = sqrtf( (M[8]+1)/2);
            if ( M[2] < 0) x=-x;
            if ( M[7] < 0) y=-y;
            if ( x*y*M[1] < 0) x=-x;  // this last line can be necessary when z is 0
            // z always >= 0 
            // if z equal to zero 
            axis[0] = x * (float)M_PI;
            axis[1] = y * (float)M_PI;
            axis[2] = z * (float)M_PI;
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

    void HLS::diff(float b1[12], float b2[12], float ret[6]) {
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

    // void HLS::jac_transpose(float jac[6][MAX_DEGREE], float jacT[MAX_DEGREE][6]) {
    //     LOOP_jac_transpose:
    //     for (int j = 0; j < N; j++)
    //         LOOP_jac_transpose_1:
    //         for (int i = 0; i < 6; i++)
    //             jacT[j][i] = jac[i][j];
    // }

    // void HLS::R_generate(float jac[6][MAX_DEGREE], float R[MAX_DEGREE][6], float c, int index) {
    //     int k = 0;
    //     LOOP_R_generate:
    //     for (int j = 0; j < N; j++)
    //         LOOP_R_generate_1:
    //         for (int i = 0; i < 6; i++)
    //             R[j][i] = jac[i][j] + Random_Matrix[(index+k++)%(6*MAX_DEGREE)] * c;
    // }

    // void HLS::JRe_calculate(float J[6][MAX_DEGREE], float R[MAX_DEGREE][6], float e[6], float ret[6]) {
    //     float temp[MAX_DEGREE];
    //     LOOP_JRe_calculate_1:
    //     for (int i = 0; i < N; i++)
    //         temp[i] = dot6(R[i], e);
    //     ret[0] = ret[1] = ret[2] = ret[3] = ret[4] = ret[5] = 0;
    //     LOOP_JRe_calculate_2:
    //     for (int j = 0; j < N; j++) {
    //         LOOP_JRe_calculate_2_1:
    //         for (int i = 0; i < 6; i++) {
    //             ret[i] += J[i][j] * temp[j];
    //         }
    //     }
    // }

    // void HLS::dist_estimate(float J[6][MAX_DEGREE], float Rt[MAX_DEGREE][6], float e[6], float range, float *dt, float *at, int offset) {
    //     float temp_dt[6];
    //     float JRte[6];
    //     R_generate(J, Rt, range*random_ratio, offset);
    //     JRe_calculate(J, Rt, e, JRte);
    //     *at = dot6(e, JRte) / (dot6(JRte, JRte) + 1e-20);
    //     sub_cp6(e, JRte, *at, temp_dt);
    //     *dt = dot6(temp_dt, temp_dt);
    // }

    // void HLS::dist_calculate(float q_out[MAX_DEGREE], float delta_q[MAX_DEGREE], float p_in[12], float *dt, float ratio) {
    //     float fr[12];
    //     float ee[6];
    //     float q_test[MAX_DEGREE];
    //     LOOP_adjust_step_1:
    //     for (int i = 0; i < N; i++)
    //         q_test[i] = q_out[i] + delta_q[i] * ratio;
    //     my_fk_solver(q_test, fr);
    //     diff(fr, p_in, ee);
    //     *dt = dot6(ee, ee);
    // }



    void HLS::my_fk_solver(float q_in[MAX_DEGREE], float ret[12], float tip[MAX_DEGREE][12], float joint[MAX_DEGREE][6], bool joint_type[MAX_DEGREE])
    {
        float temp_joint[12];
        float temp_end[12];
        float temp_pos[3];
        float end[12];
        clear_frame(end);
        LOOP_my_fk_solver:
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

        // // trans
        // LOOP_FK_Trans:
        // for (int k = 0; k < 21; k++) {
        //     int i = joint_trans[k];
        //     // tip.M
        //     assign_9(tip[i], T[i]);
        //     // joint.p
        //     add_cp(joint[i]+3, joint[i], q_in[i], T[i]+9);
        //     // joint.p+tip.p (tip.p=0?)
        //     add_pp(T[i]+9, tip[i]+9, T[i]+9);
        // }
        // // rot
        // LOOP_FK_Rot:
        // for (int k = 0; k < 80; k++) {
        //     int i = joint_rot[k];
        //     // joint.pos
        //     rot2M(joint[i], q_in[i], joint_F[i]);
        //     assign_3(joint[i]+3, joint_F[i]+9);
        //     // joint.pos*tip
        //     mul_FF(joint_F[i], tip[i], T[i]);
        // }

        // // LOOP_FK_Joint:
        // // for (int i = 0; i < N; i++) {
        // //     if (joint_type[i]) {
        // //         // trans
        // //         // tip.M
        // //         assign_9(tip[i], T[i]);
        // //         // joint.p
        // //         add_cp(joint[i]+3, joint[i], q_in[i], T[i]+9);
        // //         // joint.p+tip.p (tip.p=0?)
        // //         add_pp(T[i]+9, tip[i]+9, T[i]+9);
        // //     } else {
        // //         // rot
        // //         // joint.pos
        // //         rot2M(joint[i], q_in[i], joint_F[i]);
        // //         assign_3(joint[i]+3, joint_F[i]+9);
        // //         // joint.pos*tip
        // //         mul_FF(joint_F[i], tip[i], T[i]);
        // //     }
        // // }

        // LOOP_FK_left:
        // for (int i = N; i < MAX_DEGREE; i++) {
        //     clear_frame(T[i]);
        // }

        // LOOP_FK_64:
        // for (int k = 0; k < 64; k++) {
        //     mul_FF_block(T[k*2], T[k*2+1], T[k+128]);
        // }
        // LOOP_FK_32:
        // for (int k = 0; k < 32; k++) {
        //     mul_FF_block(T[k*2+128], T[k*2+129], T[k+192]);
        // }
        // LOOP_FK_16:
        // for (int k = 0; k < 16; k++) {
        //     mul_FF_block(T[k*2+192], T[k*2+193], T[k+224]);
        // }
        // LOOP_FK_8:
        // for (int k = 0; k < 8; k++) {
        //     mul_FF_block(T[k*2+224], T[k*2+225], T[k+240]);
        // }
        // LOOP_FK_4:
        // for (int k = 0; k < 4; k++) {
        //     mul_FF_block(T[k*2+240], T[k*2+241], T[k+248]);
        // }
        // LOOP_FK_2:
        // for (int k = 0; k < 2; k++) {
        //     mul_FF_block(T[k*2+248], T[k*2+249], T[k+252]);
        // }
        // mul_FF_block(T[252], T[253], T[254]);
        // assign_12(T[254], ret);
    }

    void HLS::my_jac_solver(float q_in[MAX_DEGREE], float end_pos[3], float jac[6][MAX_DEGREE], float &range, float tip[MAX_DEGREE][12], float joint[MAX_DEGREE][6], bool joint_type[MAX_DEGREE])
    {
        float temp_F[12];
        float temp_joint[12];
        float temp_end[12];
        float temp_twist[6];
        float temp_pos[3];
        float temp_arm[3];
        clear_frame(temp_F);
        LOOP_my_jac_solver:
        for (int i = 0; i < N; i++) {
            temp_twist[3] = 0;
            temp_twist[4] = 0;
            temp_twist[5] = 0;
            if (joint_type[i]) {
                // trans

                // jac
                mul_cp(joint[i], 1, temp_pos);
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
                mul_cp(joint[i], 1, temp_pos);
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
            if (range < temp_twist[0]) range = temp_twist[0];
            if (range < -temp_twist[0]) range = -temp_twist[0];
            if (range < temp_twist[1]) range = temp_twist[1];
            if (range < -temp_twist[1]) range = -temp_twist[1];
            if (range < temp_twist[2]) range = temp_twist[2];
            if (range < -temp_twist[2]) range = -temp_twist[2];
            if (range < temp_twist[3]) range = temp_twist[3];
            if (range < -temp_twist[3]) range = -temp_twist[3];
            if (range < temp_twist[4]) range = temp_twist[4];
            if (range < -temp_twist[4]) range = -temp_twist[4];
            if (range < temp_twist[5]) range = temp_twist[5];
            if (range < -temp_twist[5]) range = -temp_twist[5];
            jac[0][i] = temp_twist[0];
            jac[1][i] = temp_twist[1];
            jac[2][i] = temp_twist[2];
            jac[3][i] = temp_twist[3];
            jac[4][i] = temp_twist[4];
            jac[5][i] = temp_twist[5];
        }
    }


    // void HLS::direction_determination(float JT[MAX_DEGREE][6], float e[6], float range, int sp, float delta_q[MAX_DEGREE], float &alpha) {
    //     float Re[random_times][MAX_DEGREE];
    //     float JRe[random_times][6];
    //     float at[random_times];
    //     float dt[random_times];
    //     float err[6];
    //     LOOP_random_method_JRe:
    //     for (int k = 0; k < random_times; k++) {
    //         // JRe = J*(R*e);
    //         int index = ((sp*random_times - k) % (6*MAX_DEGREE) + (6*MAX_DEGREE)) % (6*MAX_DEGREE) ;
    //         LOOP_JRe_1:
    //         for (int j = 0; j < N; j++) {
    //             Re[k][j] = 0;
    //             LOOP_JRe_1_1:
    //             for (int i = 0; i < 6; i++) {
    //                 Re[k][j] += (JT[j][i] + Random_Matrix[(index++)%(6*MAX_DEGREE)] * range) * e[i];
    //             }
    //         }
    //         clear_6(JRe[k]);
    //         LOOP_JRe_2:
    //         for (int j = 0; j < N; j++) {
    //             LOOP_JRe_2_1:
    //             for (int i = 0; i < 6; i++) {
    //                 JRe[k][i] += JT[j][i] * Re[k][j];
    //             }
    //         }
    //         at[k] = dot6(e, JRe[k]) / (dot6(JRe[k], JRe[k]) + 1e-20);
    //         sub_cp6(e, JRe[k], at[k], err);
    //         dt[k] = dot6(err, err);
    //     }

    //     int j;
    //     float mini = 1e20;
    //     LOOP_random_method_min:
    //     for (int i = 0; i < random_times; i++) {
    //         if (dt[i] < mini) {
    //             mini = dt[i];
    //             j = i;
    //         }
    //     }

    //     LOOP_random_method_delta_q:
    //     for (int i = 0; i < N; i++) {
    //         delta_q[i] = Re[j][i];
    //     }
    //     alpha = at[j];

    // }

    // void HLS::line_minimization(float q_out[MAX_DEGREE], float delta_q[MAX_DEGREE], float p_in[12], float alpha, float q_next[MAX_DEGREE], float *error_min) {

    //     float p_in_copy[LMU_number][12];
    //     float q_test[LMU_number][MAX_DEGREE];
    //     float f[LMU_number][12];
    //     float e[LMU_number][6];
    //     float e_norm[LMU_number];
    //     LOOP_LM_init:
    //     for (int k = 0; k < LMU_number; k++) {
    //         LOOP_LM_init_1:
    //         for (int i = 0; i < 12; i++) 
    //             p_in_copy[k][i] = p_in[i];
    //         LOOP_LM_init_2:
    //         for (int i = 0; i < N; i++)
    //             q_test[k][i] = q_out[i] + delta_q[i] * step_length[k] * alpha;
    //     }

    //     LOOP_LM_main:
    //     for (int k = 0; k < LMU_number; k++) {
    //         my_fk_solver(q_test[k], f[k], G_tip[k], G_joint[k], G_joint_type[k]);
    //         diff(f[k], p_in_copy[k], e[k]);
    //         e_norm[k] = dot6(e[k], e[k]);
    //     }

    //     int j = 0;
    //     float mini = 1e20;
    //     LOOP_LM_find_min:
    //     for (int k = 0; k < LMU_number; k++) {
    //         if (e_norm[k] < mini) {
    //             mini = e_norm[k];
    //             j = k;
    //         }
    //     }

    //     LOOP_LM_update:
    //     for (int i = 0; i < N; i++)
    //         q_next[i] = q_test[j][i];

    //     *error_min = mini;

    // }


    int HLS::my_ik(float q_init[MAX_DEGREE], float p_target[12], float ret[MAX_DEGREE]) {

        // // random algorithm
        // float Re[random_times][MAX_DEGREE];
        // float JRe[random_times][6];
        // float at[random_times];
        // float dt[random_times];

        // // adjust step
        // float fr[SSU_number][12];
        // float ee[SSU_number][6];
        // float q_test[SSU_number][MAX_DEGREE];

        float q_out[MAX_DEGREE];
        float p_in[12];

        assign_12(p_target,  p_in);

        LOOP_init:
        for (int i = 0; i < N; i++)
            q_out[i] = q_init[i];

        bool find_solution = 0;
        int step;
        LOOP_ITER:
        for (step = 1; step <= steps; ++step) {

            float dj;
            float alpha;
            float dist_esitimate;
            float temp;
            // Twist
            float e[6];
            float err[6];
            float JJTe[6];
            // Frame
            float f[12];
            // JointArr
            float delta_q[MAX_DEGREE];
            // JacobianT
            float Jac[6][MAX_DEGREE];
            float JT[MAX_DEGREE][6];
            // random method
            float Re[random_times][MAX_DEGREE];
            float JRe[random_times][6];
            float at[random_times];
            float dt[random_times];
            // adjust step
            float q_test[LMU_number][MAX_DEGREE];
            float p_in_LMU[LMU_number][12];
            float f_LMU[LMU_number][12];
            float e_LMU[LMU_number][6];
            float e_norm[LMU_number];

            my_fk_solver(q_out, f, G_tip[0], G_joint[0], G_joint_type[0]);

            diff(f, p_in, e);

            if (-eps < e[0] && e[0] < eps &&
                -eps < e[1] && e[1] < eps &&
                -eps < e[2] && e[2] < eps &&
                -eps < e[3] && e[3] < eps &&
                -eps < e[4] && e[4] < eps &&
                -eps < e[5] && e[5] < eps ){
                find_solution = 1;
                break;
            }

            float range;
            my_jac_solver(q_out, f+9, Jac, range, G_tip[0], G_joint[0], G_joint_type[0]);

            // transpose method
            // LOOP_jac_transpose:
            // for (int i = 0; i < 6; i++)
            //     LOOP_jac_transpose_1:
            //     for (int j = 0; j < N; j++)
            //         JT[j][i] = J[i][j];

            // JJTe = J*(JT*e);
            // LOOP_clear_temp_j:
            // for (int i = 0; i < N; i++) {
            //     delta_q[i] = 0;
            // }
            // LOOP_JJTe_1:
            // for (int i = 0; i < 6; i++) {
            //     LOOP_JJTe_1_1:
            //     for (int j = 0; j < N; j++) {
            //         delta_q[j] += J[i][j] * e[i];
            //     }
            // }



            LOOP_JJTe_1:
            for (int j = 0; j < N; j++) {
                delta_q[j] = 0;
                LOOP_JJTe_1_1:
                for (int i = 0; i < 6; i++) {
                    // delta_q[j] += JT[j][i] * e[i];
                    JT[j][i] = Jac[i][j];
                    delta_q[j] += Jac[i][j] * e[i];
                }
            }
            clear_6(JJTe);
            LOOP_JJTe_2:
            for (int j = 0; j < N; j++) {
                LOOP_JJTe_2_1:
                for (int i = 0; i < 6; i++) {
                    JJTe[i] += JT[j][i] * delta_q[j];
                }
            }
            alpha = dot6(e, JJTe) / (dot6(JJTe, JJTe) + float(1e-20));
            sub_cp6(e, JJTe, alpha, err);
            dist_esitimate = dot6(err, err);


            LOOP_random_method_JRe:
            for (int k = 0; k < random_times; k++) {
                // JRe = J*(R*e);
                int index = ((-step*random_times - k) % 768 + 768) % 768 ;
                LOOP_JRe_1:
                for (int j = 0; j < N; j++) {
                    Re[k][j] = 0;
                    LOOP_JRe_1_1:
                    for (int i = 0; i < 6; i++) {
                        Re[k][j] += (JT[j][i] + Random_Matrix[(index++)%768] * range) * e[i];
                    }
                }
                clear_6(JRe[k]);
                LOOP_JRe_2:
                for (int j = 0; j < N; j++) {
                    LOOP_JRe_2_1:
                    for (int i = 0; i < 6; i++) {
                        JRe[k][i] += JT[j][i] * Re[k][j];
                    }
                }
                at[k] = dot6(e, JRe[k]) / (dot6(JRe[k], JRe[k]) + float(1e-20));
                sub_cp6(e, JRe[k], at[k], err);
                dt[k] = dot6(err, err);
            }

            int j = -1;
            float mini = dist_esitimate;
            LOOP_random_method_min:
            for (int i = 0; i < random_times; i++) {
                if (dt[i] < mini) {
                    mini = dt[i];
                    j = i;
                }
            }

            if (j != -1) {
                LOOP_random_method_delta_q:
                for (int i = 0; i < N; i++) {
                    delta_q[i] = Re[j][i];
                }
                alpha = at[j];
            }


            LOOP_LM_init:
            for (int k = 0; k < LMU_number; k++) {
                LOOP_LM_init_1:
                for (int i = 0; i < 12; i++) 
                    p_in_LMU[k][i] = p_in[i];
                LOOP_LM_init_2:
                for (int i = 0; i < N; i++)
                    q_test[k][i] = q_out[i] + delta_q[i] * step_length[k] * alpha;
            }

            LOOP_LM_main:
            for (int k = 0; k < LMU_number; k++) {
                my_fk_solver(q_test[k], f_LMU[k], G_tip[k], G_joint[k], G_joint_type[k]);
                diff(f_LMU[k], p_in_LMU[k], e_LMU[k]);
                e_norm[k] = dot6(e_LMU[k], e_LMU[k]);
            }

            j = 0;
            mini = 1e20;
            LOOP_LM_find_min:
            for (int k = 0; k < LMU_number; k++) {
                if (e_norm[k] < mini) {
                    mini = e_norm[k];
                    j = k;
                }
            }

            LOOP_LM_update:
            for (int i = 0; i < N; i++)
                q_out[i] = q_test[j][i];








            // float q_next[direction_number+1][MAX_DEGREE];
            // float error_min[direction_number+1];
            // float p_in_copy[12];
            // assign_12(p_in, p_in_copy);

            // line_minimization(q_out, delta_q_JT, p_in_copy, alpha_JT, q_next[0], error_min);

            // LOOP_main:
            // for (int k = 1; k <= direction_number; k++) {
            //     float delta_q[MAX_DEGREE];
            //     float alpha;
            //     direction_determination(JT, e, range, -step*direction_number-k, delta_q, alpha);
            //     line_minimization(q_out, delta_q, p_in_copy, alpha, q_next[k], error_min+k);
            // }

            // int j = 0;
            // float mini = 1e20;
            // LOOP_find_min:
            // for (int k = 0; k <= direction_number; k++) {
            //     if (error_min[k] < mini) {
            //         mini = error_min[k];
            //         j = k;
            //     }
            // }

            // LOOP_update:
            // for (int i = 0; i < N; i++)
            //     q_out[i] = q_next[j][i];


            // // adjust step
            // LOOP_adjust_step:
            // for (int k = 0; k < SSU_number; k++) {
            //     float ratio = a * (k+1) * SSU_range_max / SSU_number;
            //     LOOP_adjust_step_1:
            //     for (int i = 0; i < N; i++)
            //         q_test[k][i] = q_out[i] + delta_q[i] * ratio;
            //     my_fk_solver(q_test[k], fr[k]);
            //     diff(fr[k], p_in, ee[k]);
            //     dt[k] = dot6(ee[k], ee[k]);
            // }

            // j = 1;
            // float mini = 1e20;
            // LOOP_adjust_step_mini:
            // for (int k = 0; k < SSU_number; k++) {
            //     if (dt[k] < mini) {
            //         mini = dt[k];
            //         j = k;
            //     }
            // }

            // float ratio = (j+1) * SSU_range_max / SSU_number * a;
            // LOOP_change_qout:
            // for (int i = 0; i < N; i++)
            //     q_out[i] = q_out[i] + delta_q[i] * ratio;


        }

        LOOP_return:
        for (int i = 0; i < N; i++)
            ret[i] = q_out[i];

        if (find_solution) {
            return step;
        } else {
            return -1;
        }
    }

}

int hls_ik(int _N, int steps, float eps, float hls_chain[MAX_DEGREE][18], bool hls_joint_type[MAX_DEGREE], float q_in[MAX_DEGREE], float f_in[12], float q_out[MAX_DEGREE]) {
    static HLS_IK::HLS hls_solver(hls_chain, hls_joint_type, _N, steps, eps);
#pragma HLS ARRAY_PARTITION variable=hls_solver.G_tip block factor=10 dim=1
#pragma HLS ARRAY_PARTITION variable=hls_solver.G_joint block factor=10 dim=1
#pragma HLS ARRAY_PARTITION variable=hls_solver.G_joint_type block factor=10 dim=1
#pragma HLS ARRAY_PARTITION variable=hls_solver.G_joint_trans block factor=10 dim=1
#pragma HLS ARRAY_PARTITION variable=hls_solver.G_joint_rot block factor=10 dim=1
    static bool is_init = 0;
    if (is_init) {
        return hls_solver.my_ik(q_in, f_in, q_out);
    }
    is_init = 1;
    return 0;
}
