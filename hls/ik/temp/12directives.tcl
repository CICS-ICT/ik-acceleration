############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_inline "HLS::clear_frame"
set_directive_inline "HLS::clear_6"
set_directive_inline "HLS::assign_3"
set_directive_inline "HLS::assign_6"
set_directive_inline "HLS::assign_9"
set_directive_inline "HLS::assign_12"
set_directive_inline "HLS::add_pp"
set_directive_inline "HLS::add_cp"
set_directive_inline "HLS::sub_cp6"
set_directive_inline "HLS::sub_pp"
set_directive_inline "HLS::dot"
set_directive_inline "HLS::dot6"
set_directive_inline "HLS::cross"
set_directive_inline "HLS::mul_cp"
set_directive_inline "HLS::mul_Mp"
set_directive_inline "HLS::mul_MM"
set_directive_inline "HLS::mul_Fp"
set_directive_inline "HLS::mul_FF"
set_directive_inline "HLS::rot2M"
set_directive_inline "HLS::M2rot"
set_directive_inline -off "HLS::diff"
set_directive_unroll "HLS::my_fk_solver/LOOP_FK_64"
set_directive_unroll "HLS::my_fk_solver/LOOP_FK_32"
set_directive_unroll "HLS::my_fk_solver/LOOP_FK_16"
set_directive_unroll "HLS::my_fk_solver/LOOP_FK_8"
set_directive_unroll "HLS::my_fk_solver/LOOP_FK_4"
set_directive_unroll "HLS::my_fk_solver/LOOP_FK_2"
set_directive_pipeline -II 20 "HLS::my_jac_solver/LOOP_my_jac_solver"
set_directive_inline -off "HLS::mul_Mp_block"
set_directive_inline -off "HLS::mul_MM_block"
set_directive_inline -off "HLS::mul_Fp_block"
set_directive_inline -off "HLS::mul_FF_block"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_2"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_4"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_8"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_16"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_32"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_64"
set_directive_pipeline "HLS::my_fk_solver/LOOP_FK_left"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_left"
set_directive_dependence -type intra -dependent false "HLS::my_fk_solver/LOOP_FK_left"
set_directive_pipeline "HLS::my_fk_solver/LOOP_FK_Joint"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_Joint"
set_directive_pipeline "HLS::my_fk_solver/LOOP_FK_Trans"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_Trans"
set_directive_pipeline "HLS::my_fk_solver/LOOP_FK_Rot"
set_directive_dependence -type inter -dependent false "HLS::my_fk_solver/LOOP_FK_Rot"
set_directive_unroll -factor 16 "HLS::my_ik/LOOP_init"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_init"
set_directive_array_partition -type block -factor 128 -dim 1 "HLS::my_ik/LOOP_ITER" JT
set_directive_pipeline "HLS::my_ik/LOOP_JJTe_1"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_JJTe_1"
set_directive_pipeline -II 16 "HLS::my_ik/LOOP_JJTe_2"
set_directive_dependence -type intra -dependent false "HLS::my_ik/LOOP_JJTe_2"
set_directive_dataflow "HLS::my_ik/LOOP_main"
set_directive_unroll -factor 16 "HLS::my_ik/LOOP_update"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_update"
set_directive_unroll -factor 16 "HLS::my_ik/LOOP_return"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_return"
set_directive_pipeline -II 20 "HLS::my_fk_solver/LOOP_my_fk_solver"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_main"
set_directive_array_partition -type block -factor 100 -dim 1 "HLS::my_ik/LOOP_ITER" Re
set_directive_array_partition -type block -factor 100 -dim 1 "HLS::my_ik/LOOP_ITER" JRe
set_directive_array_partition -type block -factor 10 -dim 1 "HLS::my_ik/LOOP_ITER" q_test
set_directive_array_partition -type block -factor 10 -dim 1 "HLS::my_ik/LOOP_ITER" p_in_LMU
set_directive_array_partition -type complete -dim 1 "HLS::my_ik/LOOP_ITER" f_LMU
set_directive_array_partition -type complete -dim 1 "HLS::my_ik/LOOP_ITER" e_LMU
set_directive_array_partition -type complete -dim 1 "HLS::my_ik/LOOP_ITER" e_norm
set_directive_array_partition -type complete -dim 1 "HLS::my_ik/LOOP_ITER" e
set_directive_array_partition -type complete -dim 1 "HLS::my_ik/LOOP_ITER" err
set_directive_array_partition -type complete -dim 1 "HLS::my_ik/LOOP_ITER" JJTe
set_directive_pipeline -II 101 "HLS::my_ik/LOOP_random_method_JRe"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_random_method_JRe"
set_directive_unroll -factor 16 "HLS::my_ik/LOOP_random_method_delta_q"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_random_method_delta_q"
set_directive_dependence -type intra -dependent false "HLS::my_ik/LOOP_random_method_delta_q"
set_directive_pipeline -II 8 "HLS::my_ik/LOOP_random_method_delta_q"
set_directive_pipeline -II 51 "HLS::my_ik/LOOP_LM_init"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_LM_init"
set_directive_dependence -type intra -dependent false "HLS::my_ik/LOOP_LM_init"
set_directive_array_partition -type complete -dim 1 "HLS::my_ik" p_in
set_directive_unroll "HLS::my_ik/LOOP_LM_main"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_LM_main"
set_directive_unroll -factor 16 "HLS::my_ik/LOOP_LM_update"
set_directive_pipeline -II 8 "HLS::my_ik/LOOP_LM_update"
set_directive_dependence -type inter -dependent false "HLS::my_ik/LOOP_LM_update"
set_directive_dependence -type intra -dependent false "HLS::my_ik/LOOP_LM_update"
set_directive_unroll -factor 4 "HLS::my_ik/LOOP_JJTe_2"
set_directive_array_partition -type complete -dim 1 "HLS::my_ik/LOOP_ITER" f
