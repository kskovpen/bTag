#!/bin/env zsh

sysDir="/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/sysAna/run/reweight"
aStyle="/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/sysAna/run/reweight/run/atlasstyle-00-03-04"
export LD_LIBRARY_PATH=${sysDir}:${aStyle}:${LD_LIBRARY_PATH}:$ROOTSYS/lib

inDir="histMJATM_NTRK_2011FINAL"

typ="1d"
over=0

../rw ${inDir} ${typ} ${over}
