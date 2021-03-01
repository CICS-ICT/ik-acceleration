############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2018 Xilinx, Inc. All Rights Reserved.
############################################################
open_project ik
set_top hls_ik
add_files hls_ik.cpp
add_files -tb tools.cpp -cflags "-Wno-unknown-pragmas"
add_files -tb ik_tests.cpp -cflags "-I../../../../../../opt/ros/melodic/include -I../../../../../../usr/include/eigen3 -Wno-unknown-pragmas"
open_solution "degree_006"
set_part {xq7vx690trf1157-2i}
create_clock -period 10 -name default
set_clock_uncertainty 12.5%
source "./ik/degree_006/directives.tcl"
csim_design -ldflags {-L/opt/ros/melodic/lib -lurdf -lkdl_parser -lorocos-kdl} -clean -O
csynth_design
cosim_design -ldflags {-L/opt/ros/melodic/lib -lurdf -lkdl_parser -lorocos-kdl} -compiled_library_dir "/opt/ros/kinetic/lib"
export_design -rtl verilog -format ip_catalog
