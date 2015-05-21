#!/bin/env zsh

sysDir="/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/test/reweight"
aStyle="/home/kskovpen/plugins/atlasstyle-00-03-04_gcc491"
export LD_LIBRARY_PATH=${sysDir}:${aStyle}:${LD_LIBRARY_PATH}:$ROOTSYS/lib

inDir="histMJSYS_MERGED"

typ="1d"
over=0

../rw ${inDir} ${typ} ${over}
