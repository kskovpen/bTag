#!/bin/env zsh

fitDir="/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/sysAna/run/fit/run/corr2DRW"
aStyle="/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/sysAna/run/fit/run/corr2DRW/atlasstyle-00-03-04"
export LD_LIBRARY_PATH=${fitDir}:${aStyle}:${LD_LIBRARY_PATH}:$ROOTSYS/lib

./corr2DRW

