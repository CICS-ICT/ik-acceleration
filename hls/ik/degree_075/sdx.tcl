# ==============================================================
# File generated on Fri Jul 26 13:03:45 CST 2019
# Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
# SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
# IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
# Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
# ==============================================================
add_files -tb ../../tools.cpp -cflags { -Wno-unknown-pragmas}
add_files -tb ../../ik_tests.cpp -cflags { -I../../../../../../../opt/ros/kinetic/include  -I../../../../../../../usr/include/eigen3  -Wno-unknown-pragmas}
add_files hls_ik.cpp
set_part xq7vx690trf1157-2i
create_clock -name default -period 10
set_clock_uncertainty 12.5% default
set_directive_inline HLS::clear_frame 
set_directive_inline HLS::clear_6 
set_directive_inline HLS::assign_3 
set_directive_inline HLS::assign_6 
set_directive_inline HLS::assign_9 
set_directive_inline HLS::assign_12 
set_directive_inline HLS::add_pp 
set_directive_inline HLS::add_cp 
set_directive_inline HLS::sub_cp6 
set_directive_inline HLS::sub_pp 
set_directive_inline HLS::dot 
set_directive_inline HLS::dot6 
set_directive_inline HLS::cross 
set_directive_inline HLS::mul_cp 
set_directive_inline HLS::mul_Mp 
set_directive_inline HLS::mul_MM 
set_directive_inline HLS::mul_Fp 
set_directive_inline HLS::mul_FF 
set_directive_inline HLS::rot2M 
set_directive_inline HLS::M2rot 
set_directive_inline HLS::diff -off
set_directive_unroll HLS::my_fk_solver/LOOP_FK_64 
set_directive_unroll HLS::my_fk_solver/LOOP_FK_32 
set_directive_unroll HLS::my_fk_solver/LOOP_FK_16 
set_directive_unroll HLS::my_fk_solver/LOOP_FK_8 
set_directive_unroll HLS::my_fk_solver/LOOP_FK_4 
set_directive_unroll HLS::my_fk_solver/LOOP_FK_2 
set_directive_pipeline HLS::my_jac_solver/LOOP_my_jac_solver -II 20
set_directive_inline HLS::mul_Mp_block -off
set_directive_inline HLS::mul_MM_block -off
set_directive_inline HLS::mul_Fp_block -off
set_directive_inline HLS::mul_FF_block -off
set_directive_dependence HLS::my_fk_solver/LOOP_FK_2 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_4 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_8 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_16 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_32 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_64 
set_directive_pipeline HLS::my_fk_solver/LOOP_FK_left 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_left 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_left 
set_directive_pipeline HLS::my_fk_solver/LOOP_FK_Joint 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_Joint 
set_directive_pipeline HLS::my_fk_solver/LOOP_FK_Trans 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_Trans 
set_directive_pipeline HLS::my_fk_solver/LOOP_FK_Rot 
set_directive_dependence HLS::my_fk_solver/LOOP_FK_Rot 
set_directive_unroll HLS::my_ik/LOOP_init -factor 16
set_directive_dependence HLS::my_ik/LOOP_init 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_pipeline HLS::my_ik/LOOP_JJTe_1 
set_directive_dependence HLS::my_ik/LOOP_JJTe_1 
set_directive_pipeline HLS::my_ik/LOOP_JJTe_2 -II 4
set_directive_dependence HLS::my_ik/LOOP_JJTe_2 
set_directive_dataflow HLS::my_ik/LOOP_main 
set_directive_unroll HLS::my_ik/LOOP_update -factor 16
set_directive_dependence HLS::my_ik/LOOP_update 
set_directive_unroll HLS::my_ik/LOOP_return -factor 16
set_directive_dependence HLS::my_ik/LOOP_return 
set_directive_pipeline HLS::my_fk_solver/LOOP_my_fk_solver -II 20
set_directive_dependence HLS::my_ik/LOOP_main 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_pipeline HLS::my_ik/LOOP_random_method_JRe -II 75
set_directive_dependence HLS::my_ik/LOOP_random_method_JRe 
set_directive_unroll HLS::my_ik/LOOP_random_method_delta_q -factor 16
set_directive_dependence HLS::my_ik/LOOP_random_method_delta_q 
set_directive_dependence HLS::my_ik/LOOP_random_method_delta_q 
set_directive_pipeline HLS::my_ik/LOOP_random_method_delta_q -II 8
set_directive_pipeline HLS::my_ik/LOOP_LM_init -II 38
set_directive_dependence HLS::my_ik/LOOP_LM_init 
set_directive_dependence HLS::my_ik/LOOP_LM_init 
set_directive_array_partition HLS::my_ik 
set_directive_unroll HLS::my_ik/LOOP_LM_main 
set_directive_dependence HLS::my_ik/LOOP_LM_main 
set_directive_unroll HLS::my_ik/LOOP_LM_update -factor 16
set_directive_pipeline HLS::my_ik/LOOP_LM_update -II 8
set_directive_dependence HLS::my_ik/LOOP_LM_update 
set_directive_dependence HLS::my_ik/LOOP_LM_update 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
set_directive_dependence HLS::my_ik/LOOP_JJTe_2_1 
set_directive_dependence HLS::my_ik/LOOP_JRe_1 
set_directive_dependence HLS::my_ik/LOOP_JRe_2 
set_directive_dependence HLS::my_ik/LOOP_JRe_2_1 
set_directive_dependence HLS::my_ik/LOOP_LM_init_1 
set_directive_dependence HLS::my_ik/LOOP_LM_init_1 
set_directive_dependence HLS::my_ik/LOOP_LM_init_2 
set_directive_dependence HLS::my_ik/LOOP_LM_init_2 
set_directive_array_partition HLS::my_ik/LOOP_ITER 
