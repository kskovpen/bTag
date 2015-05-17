#!/bin/env zsh

hdir="/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/run/"
sysDir="${hdir}sys"
aStyle="/home/kskovpen/plugins/atlasstyle-00-03-04_gcc491"
export LD_LIBRARY_PATH=${sysDir}:${aStyle}:${LD_LIBRARY_PATH}:$ROOTSYS/lib
# if you want to just plot sf specify the same nominal hist dirs

#inDirNOMINAL="histMJ_2011FINAL"
#inDirRW=("histMJ_NTRK_2011FINAL")
#inDirRW2=("histMJ_2011FINAL")

inDirNOMINAL="histMJSYS_MERGED"
inDirRW=("histMJSYS_MERGED")
inDirRW2=("histMJSYS_MERGED")

#inDirNOMINAL="histMJSYS_2011FINAL"
#inDirRW=("histMJ_NTRK_2011FINAL" \
#"histMJ_NTRK_NJET_2011FINAL" "histMJ_NTRK_MUPT_2011FINAL" "histMJ_NTRK_JETA_2011FINAL" \
#"histMJSYS_2011FINAL")
#inDirRW2=("histMJ_2011FINAL" \
#"histMJ_2011FINAL" "histMJ_2011FINAL" "histMJ_2011FINAL" \
#"histMJ_2011FINAL")

#inDirNOMINAL="histMJSYS_2011FINAL"
#inDirRW=("histMJ_NTRK_2011FINAL" \
#"histMJ_NTRK_NJET_2011FINAL" "histMJ_NTRK_MUPT_2011FINAL" "histMJ_NTRK_JETA_2011FINAL" \
#"histMJSYS_2011FINAL")
#inDirRW2=("histMJ_2011FINAL" \
#"histMJ_2011FINAL" "histMJ_2011FINAL" "histMJ_2011FINAL" \
#"histMJ_2011FINAL")

#rw=("ntrk")
#rw=("ntrk" "njet" "mupt" "jeta" "true")
rw=("true")

rm -f ../../histSYS/MC/data.root
rm -f ../../histSYS/DATA/data.root
./merge.zsh $inDirNOMINAL

idx=1
for i in ${inDirRW[@]}
do
echo ${i} ${inDirRW2[${idx}]}
../sys ${inDirNOMINAL} ${i} ${inDirRW2[${idx}]} ${rw[${idx}]}
idx=$[$idx+1]
done


#cp -r ../../histSYS/MC/data.root ../../${inDirNOMINAL}SYS/MC/data.root
#cp -r ../../histSYS/DATA/data.root ../../${inDirNOMINAL}SYS/DATA/data.root
