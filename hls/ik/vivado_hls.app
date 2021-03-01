<project xmlns="com.autoesl.autopilot.project" name="ik" top="hls_ik">
    <files>
        <file name="../../tools.cpp" sc="0" tb="1" cflags=" -Wno-unknown-pragmas"/>
        <file name="../../ik_tests.cpp" sc="0" tb="1" cflags="-I../../../../../../../../opt/ros/melodic/include -I../../../../../../../../usr/include/eigen3 -Wno-unknown-pragmas"/>
        <file name="hls_ik.cpp" sc="0" tb="false" cflags=""/>
    </files>
    <includePaths/>
    <libraryPaths/>
    <Simulation argv="">
        <SimFlow name="csim" optimizeCompile="true" ldflags="-L/opt/ros/melodic/lib -lurdf -lkdl_parser -lorocos-kdl" clean="true" csimMode="0" lastCsimMode="0"/>
    </Simulation>
    <solutions xmlns="">
        <solution name="solution1" status="inactive"/>
        <solution name="solution2" status="inactive"/>
        <solution name="solution3" status="inactive"/>
        <solution name="solution4" status="inactive"/>
        <solution name="solution5" status="inactive"/>
        <solution name="solution6" status="inactive"/>
        <solution name="solution7" status="inactive"/>
        <solution name="solution8" status="inactive"/>
        <solution name="solution9" status="inactive"/>
        <solution name="solution10" status="inactive"/>
        <solution name="solution11" status="inactive"/>
        <solution name="solution12" status="inactive"/>
        <solution name="degree_075" status="inactive"/>
        <solution name="degree_050" status="inactive"/>
        <solution name="degree_025" status="inactive"/>
        <solution name="degree_012" status="inactive"/>
        <solution name="degree_006" status="active"/>
        <solution name="Ultra" status="inactive"/>
        <solution name="Degree_100" status="inactive"/>
    </solutions>
</project>

