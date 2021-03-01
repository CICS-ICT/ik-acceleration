#ifndef RAND_IK_HPP
#define RAND_IK_HPP

#include "config.hpp"
#include <boost/date_time.hpp>
#include <kdl/chainjnttojacsolver.hpp>
#include <kdl/chainfksolverpos_recursive.hpp>

namespace RAND_IK {

    enum BasicJointType { RotJoint, TransJoint, Continuous };

    struct DebugInfo
    {
        double parallel_time_random;
        double parallel_time_search;
        double ratio_a;
        double ratio_d;
    };

    class RAND_IK
    {
    public:
        RAND_IK(const KDL::Chain& _chain, int _steps=100, double _eps=1e-5);
        ~RAND_IK(){};

        int CartToJnt(const KDL::JntArray &q_init, const KDL::Frame &p_in, KDL::JntArray &q_out, DebugInfo &info);

    private:
        int steps;
        double eps;
        KDL::Chain chain;

        std::unique_ptr<KDL::ChainJntToJacSolver> jacsolver;
        std::unique_ptr<KDL::ChainFkSolverPos_recursive> fksolver;

        std::vector<BasicJointType> types;

        inline static double squaredNorm(KDL::Twist &t) {
            double sum = 0;
            for (int i = 0; i < 3; i++) {
                sum += t.vel.data[i] * t.vel.data[i];
                sum += t.rot.data[i] * t.rot.data[i];
            }
            return sum;
        }
    };

}

#endif
