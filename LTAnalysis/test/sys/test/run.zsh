#!/bin/env zsh

hdir="/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/"
sysDir="${hdir}sys"
aStyle="/home/kskovpen/plugins/atlasstyle-00-03-04_gcc491"
export LD_LIBRARY_PATH=${sysDir}:${aStyle}:${LD_LIBRARY_PATH}:$ROOTSYS/lib
# if you want to just plot sf specify the same nominal hist dirs

rm -rf pics
mkdir pics

tag="M"

#inDirNOMINAL="histMJCSVTSYS_MERGED"
#inDirRW=("histMJCSVTSYS_MERGED")
#inDirRW2=("histMJCSVTSYS_MERGED")

inDirNOMINAL="histMJCSV${tag}SYS_MERGED"
inDirRW=("histMJCSV${tag}_NTRK_MERGED" \
"histMJCSV${tag}_NTRK_NJET_MERGED" "histMJCSV${tag}_NTRK_MUPT_MERGED" \
"histMJCSV${tag}_MERGED")
inDirRW2=("histMJCSV${tag}_MERGED" \
"histMJCSV${tag}_MERGED" "histMJCSV${tag}_MERGED" \
"histMJCSV${tag}_MERGED")

#inDirNOMINAL="histMJCSVLSYS_MERGED"
#inDirRW=("histMJCSVL_NTRK_MERGED" "histMJCSVL_NTRK_JETA_MERGED" "histMJCSVLSYS_MERGED")
#inDirRW2=("histMJCSVLSYS_MERGED" "histMJCSVLSYS_MERGED" "histMJCSVLSYS_MERGED")

#rw=("pt")
rw=("ntrk" "njet" "mupt" "true")
#rw=("ntrk" "jeta" "true")
#rw=("true")

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
