#include "rand_ik.hpp"

namespace RAND_IK {

    RAND_IK::RAND_IK(const KDL::Chain& _chain, int _steps, double _eps):
        chain(_chain), steps(_steps), eps(_eps) {
        jacsolver.reset(new KDL::ChainJntToJacSolver(chain));
        fksolver.reset(new KDL::ChainFkSolverPos_recursive(chain));
    }


    int RAND_IK::CartToJnt(const KDL::JntArray &q_init, const KDL::Frame &p_in, KDL::JntArray &q_out, DebugInfo &info) {

        q_out = q_init;

        int nj = chain.getNrOfJoints();
        KDL::Jacobian J(nj);
        KDL::JntArray delta_q(nj);
        KDL::JntArray q_test(nj);
        KDL::JntArray q_curr(nj);
        KDL::Frame f;
        KDL::Twist delta_twist;
        Eigen::Matrix<double,Eigen::Dynamic,6> Rt;
        Eigen::Matrix<double,Eigen::Dynamic,6> R;
        Eigen::VectorXd JJTe(6);
        Eigen::VectorXd JRe(6);
        Eigen::VectorXd e(6);

        info.parallel_time_random = 0;
        info.parallel_time_search = 0;
        boost::posix_time::ptime start_time;
        boost::posix_time::time_duration diff;

        bool find_solution = 0;
        for (int step = 0; step < steps; ++step) {

            fksolver->JntToCart(q_out,f);
            delta_twist = KDL::diff(f, p_in);

            if(KDL::Equal(delta_twist,KDL::Twist::Zero(),eps)) {
                find_solution = 1;
                break;
            }

            jacsolver->JntToJac(q_out,J);
            e(0) = delta_twist.vel.data[0];
            e(1) = delta_twist.vel.data[1];
            e(2) = delta_twist.vel.data[2];
            e(3) = delta_twist.rot.data[0];
            e(4) = delta_twist.rot.data[1];
            e(5) = delta_twist.rot.data[2];

            // transpose method
            R = J.data.transpose();
            JJTe = J.data*(R*e);
            double a = e.dot(JJTe) / (JJTe.dot(JJTe) + 1e-20);
            double d = (e-a*JJTe).squaredNorm();
            double d0 = d;

            // random method
            double range = std::max(abs(J.data.minCoeff()), abs(J.data.maxCoeff()));
            start_time = boost::posix_time::microsec_clock::local_time();
            for (int i = 0; i < random_times; i++) {
                Rt = J.data.transpose() + Eigen::MatrixXd::Random(nj,6)*range*random_ratio;
                JRe = J.data*(Rt*e);
                double at = e.dot(JRe) / (JRe.dot(JRe) + 1e-20);
                double dt = (e-at*JRe).squaredNorm();
                if (dt < d) {
                    d = dt;
                    a = at;
                    R = Rt;
                }
            }
            diff = boost::posix_time::microsec_clock::local_time() - start_time;
            info.parallel_time_random += diff.total_nanoseconds() / 1e9;
            delta_q.data = R * e;
            info.ratio_d = d / d0;

            // adjust step
            int j = 1;
            double mini = 1e20;
            start_time = boost::posix_time::microsec_clock::local_time();
            for (int k = 1; k <= SSU_number; k++) {
                q_test.data = q_out.data + delta_q.data * k * SSU_range_max / SSU_number * a;
                fksolver->JntToCart(q_test,f);
                delta_twist = KDL::diff(f, p_in);
                double dist = squaredNorm(delta_twist);
                if (dist < mini) {
                    mini = dist;
                    j = k;
                }
            }
            diff = boost::posix_time::microsec_clock::local_time() - start_time;
            info.parallel_time_search += diff.total_nanoseconds() / 1e9;
            info.ratio_a = j * SSU_range_max / SSU_number;
            q_curr.data = q_out.data + delta_q.data * j * SSU_range_max / SSU_number * a;


            q_out=q_curr;

        }


        if (find_solution) {
            return 1;
        } else {
            return -1;
        }
    }

}
