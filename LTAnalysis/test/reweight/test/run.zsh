#!/bin/env zsh

sysDir="/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/reweight"
aStyle="/home/kskovpen/plugins/atlasstyle-00-03-04_gcc491"
export LD_LIBRARY_PATH=${sysDir}:${aStyle}:${LD_LIBRARY_PATH}:$ROOTSYS/lib

#inDir="histMJPTETA_MERGED"
inDir="histMJCSVL_NTRK_MERGED"
#inDir="histMJAWAY_NTRK_MERGED"

typ="1d"
#typ="2d"

over=0

../rw ${inDir} ${typ} ${over}
