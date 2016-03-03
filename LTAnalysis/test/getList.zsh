#!/bin/env zsh

#fpathMC="/opt/sbg/scratch1/cms/kskovpen/bTag/NTUPLES/13TeV_7414/"
#fpathDATA="/opt/sbg/scratch1/cms/kskovpen/bTag/NTUPLES/13TeV_7414/"
fpathMC="/opt/sbg/scratch1/cms/kskovpen/bTag/NTUPLES/13TeV_763/"
fpathDATA="/opt/sbg/scratch1/cms/kskovpen/bTag/NTUPLES/13TeV_763/"

fpathMC="${fpathMC}QCD_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIIFall15MiniAODv1-PU25nsData2015v1_76X_mcRun2_asymptotic_v12/"
###fpathMC="${fpathMC}QCD_TuneCUETP8M1_13TeV_pythia8_RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12/"

liDATA=($(ls ${fpathDATA} | egrep -v "QCD"))
liMC=($(ls ${fpathMC}))

nFilesDATA=35 # per job
###nFilesDATA=5 # per job
#nFilesDATA=10000
#nFilesMC=10000
nFilesMC=30
###nFilesMC=5
#outDir="listsSTAT/"
#outDir="lists/"
#outDir="listsIncl/"
outDir="listsTEST/"

rm -rf ${outDir}
mkdir ${outDir}

# data
rm -f /tmp/tempDATA.txt
for line in $liDATA
do
d1=$(echo $line)
liDATA2=$(ls ${fpathDATA}${d1})
echo $liDATA2 | while read line2
do
f1=$(echo $line2)
file=$(echo ${fpathDATA}${d1}/${f1})
echo "${file}" >> /tmp/tempDATA.txt
done
split -a 5 -l ${nFilesDATA} -d /tmp/tempDATA.txt /tmp/${d1}_
lsfi=$(ls /tmp/${d1}_*)
jid=0
echo $lsfi | while read fil
do
mv ${fil} ${outDir}/${d1}_ID${jid}.txt
jid=$[$jid+1]
done
rm -f /tmp/tempDATA.txt
done

# MC
rm -f /tmp/tempMC.txt
for line in $liMC
do
d1=$(echo $line)
liMC2=$(ls ${fpathMC}${d1})
echo $liMC2 | while read line2
do
f1=$(echo $line2)
file=$(echo ${fpathMC}${d1}/${f1})
echo "${file}" >> /tmp/tempMC.txt
done
split -a 5 -l ${nFilesMC} -d /tmp/tempMC.txt /tmp/${d1}_
lsfi=$(ls /tmp/${d1}_*)
jid=0
echo $lsfi | while read fil
do
mv ${fil} ${outDir}/${d1}_ID${jid}.txt
jid=$[$jid+1]
done
rm -f /tmp/tempMC.txt
done
