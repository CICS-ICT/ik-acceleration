#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <boost/date_time.hpp>

#include "kdl_parser/kdl_parser.hpp"
#include "kdl/chain.hpp"

#include "tools.hpp"
#include "hls_ik.hpp"

float fRand(float min, float max)
{
    float f = (float)rand() / RAND_MAX;
    return min + f * (max - min);
}


int test(int num_samples, std::string chain_start, std::string chain_end, float eps, std::string urdf_file)
{
    srand(time(NULL));

    KDL::Tree tree;
    if (!kdl_parser::treeFromFile(urdf_file, tree)) {
        printf("Failed to extract kdl tree from xml robot description\n");
        return 1;
    }

    KDL::Chain chain;
    if(!tree.getChain(chain_start, chain_end, chain)) {
        printf("Couldn't find chain %s to %s\n",chain_start.c_str(),chain_end.c_str());
        return 2;
    }

    if (chain.getNrOfJoints() != chain.getNrOfSegments()) {
        printf("Do not support this type of robot for now\n");
        return 3;
    }


    // int N = chain.getNrOfJoints();
    int rc;
    int success;
    int success_steps;
    float total_time;
    float success_time;
    float end_twist[6];
    float end_pose[12];
    float end_pose_now[12];
    float end_pose_test[12];
    float jlist_in[MAX_DEGREE];
    float jlist_result[MAX_DEGREE];
    float JointList[num_samples][MAX_DEGREE];
    boost::posix_time::ptime start_time;
    boost::posix_time::time_duration diff;

    // Set up HLS_IK
    float hls_chain[MAX_DEGREE][18];
    bool hls_joint_type[MAX_DEGREE];
    int ttmp = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9; j++) {
            hls_chain[i][j] = chain.getSegment(i).getFrameToTip().M.data[j];
        }
        hls_chain[i][9] = 0;
        hls_chain[i][10] = 0;
        hls_chain[i][11] = 0;
        for (int j = 0; j < 3; j++) {
            hls_chain[i][j+12] = chain.getSegment(i).getJoint().JointAxis().data[j];
            hls_chain[i][j+15] = chain.getSegment(i).getJoint().JointOrigin().data[j];
        }
        hls_joint_type[i] = chain.getSegment(i).getJoint().getType() == 0 ? 0 : 1;
        ttmp += hls_joint_type[i];
    }
    hls_ik(N, 1000, eps, hls_chain, hls_joint_type, jlist_in, end_pose, jlist_result);

    printf("ttmp = %d\n", ttmp);
    printf("N = %d\n", N);

    // Set up TOOLS
    TOOLS::TOOLS tools(hls_chain, hls_joint_type, N);

    // Set up init joint list
    for (int j = 0; j < N; j++) {
        jlist_in[j] = 0;
    }

    // Set up test joint list
    for (int i = 0; i < num_samples; i++) {
        for (int j = 0; j < N; j++) {
            JointList[i][j] = fRand(-1, 1);
        }
    }

    total_time=0;
    success=0;
    success_time = 0;
    success_steps = 0;

    printf("*** Testing HLS_IK with %d random samples, Using %d joints\n", num_samples, N);

    for (int i = 0; i < num_samples; i++) {        
        tools.my_fk_solver(JointList[i], end_pose);

        // hls fk algorithm test
        // hls_solver.my_fk_solver(jlist, end_pose);
        // hls_ik(2, N, 1000, eps, hls_chain, hls_joint_type, JointList[i], end_pose_test, jlist_result);

        // for (int j = 0; j < 12; j++) 
        //     printf("%f ", end_pose[j]);
        // printf("\n");
        // for (int j = 0; j < 12; j++) 
        //     printf("%f ", end_pose_test[j]);
        // printf("\n");
        // bool is_same = 1;
        // for (int j = 0; j < 12; j++) 
        //     if (fabs(end_pose_test[j] - end_pose[j]) > eps)
        //         is_same = 0;
        // if (!is_same) 
        //     printf("No!!!!!!! fk hls\n");

        start_time = boost::posix_time::microsec_clock::local_time();
        rc = hls_ik(N, 1000, eps, hls_chain, hls_joint_type, jlist_in, end_pose, jlist_result);
        diff = boost::posix_time::microsec_clock::local_time() - start_time;

        // validity
        tools.my_fk_solver(jlist_result, end_pose_now);
        tools.diff(end_pose_now, end_pose, end_twist);
        if (rc >= 0 && fabs(end_twist[0]) < eps && fabs(end_twist[1]) < eps && fabs(end_twist[2]) < eps && fabs(end_twist[3]) < eps && fabs(end_twist[4]) < eps && fabs(end_twist[5]) < eps) {
            success++;
            success_steps += rc;
            success_time += diff.total_nanoseconds() / 1e9;
        } else {
            printf("test %d fail\n", i);
            for (int j = 0; j < 6; j++)
                printf("%f ", end_twist[j]);
            printf("\n");
        }

        if (i*100/num_samples%10 == 0)
            printf("%d%% done\n", int(float(i)/num_samples*100));
    }

    printf("HLS_IK success rate:             %f%%\n", 100.0*success/num_samples);
    printf("HLS_IK success average steps:    %f\n", success_steps/(success+1e-10));
    printf("HLS_IK success average time:     %fs\n", success_time/(success+1e-10));

    printf("Test done\n");

    return 0;
}

int main(int argc, char** argv)
{

    int num_samples = 100;
    float eps = 0.00001;

    std::string chain_start = "branch_0";
    std::string chain_end = "branch_100";
    std::string urdf_file = "/home/pnpeasy/Workspace/vivado/ik/hls/urdf/d_0100_1.urdf";

    return test(num_samples, chain_start, chain_end, eps, urdf_file);
}
