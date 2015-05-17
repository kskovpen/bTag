#!/bin/env zsh

fitDir="/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/run/fit"
aStyle="/home/kskovpen/plugins/atlasstyle-00-03-04_gcc491"
export LD_LIBRARY_PATH=${fitDir}:${aStyle}:${LD_LIBRARY_PATH}:$ROOTSYS/lib

ana=1 #1-QCD,2-TTBAR,3-BINV2

cleandir=1 # clean results dir ?

# Use: ./fit "sysName"
# Systematics options:
# ALL, NONE,
# JES, JER, SMCALL, JETDIR,
# JESup, JESdown, JERup, JERdown, SMCALLup, SMCALLdown, JETDIRup, JETDIRdown
#../fit "NONE" 0
#../fit "JES" 0
#../fit "JESdown" 0

mod="ALL" 

#idxsys=(0 1 -1 2 -2 3 -3 4 -4 5 -5 6 -6 7 -7 8 -8 9 -9 10 -10)
#idxsys=(666 667 668 669 670 671 672 673 674 675)
idxsys=(0)

pfr="results"
pto="results/SFSYSLOCAL"
if [[ ${cleandir} == 1 ]]; then
rm -rf ${pto}/*
fi

for i in ${idxsys[@]}
#for i in {666..766}
#for i in {666..675}
do
echo "##### FIT ${i} #####"
../fit ${mod} ${i}
fin="${pfr}/eff${mod}.txt"
echo "##### PRINT ${i} #####"
./plotFit.zsh ${fin} ${ana}
cp ${fin} ${pto}/eff${mod}_${i}.txt
cp ${pfr}/table_heavy_1_${mod}.tex ${pto}/table_heavy_1_${mod}_${i}.tex
cp ${pfr}/table_heavy_2_${mod}.tex ${pto}/table_heavy_2_${mod}_${i}.tex
cp ${pfr}/table_heavy_1_${mod}.pdf ${pto}/table_heavy_1_${mod}_${i}.pdf
cp ${pfr}/table_heavy_2_${mod}.pdf ${pto}/table_heavy_2_${mod}_${i}.pdf
cp ${pfr}/fit_EFF_beauty_${mod}.root ${pto}/fit_EFF_beauty_${mod}_${i}.root
cp ${pfr}/fit_FIT123_beforeBTAG.root ${pto}/fit_FIT123_beforeBTAG_${i}.root
cp ${pfr}/fit_FIT123_afterBTAG.root ${pto}/fit_FIT123_afterBTAG_${i}.root

cp ${pfr}/table_inc_heavy_1_ALL.tex ${pto}/table_inc_heavy_1_${mod}_${i}.tex
cp ${pfr}/table_inc_heavy_2_ALL.tex ${pto}/table_inc_heavy_2_${mod}_${i}.tex
done

