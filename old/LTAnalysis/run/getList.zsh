#!/bin/env zsh

fpath="/opt/sbg/scratch1/cms/kskovpen/bTag/NTUPLES/Legacy7TeV/"

fpathMC="${fpath}QCD_MuEnrichedPt5_TuneZ2_7TeV_pythia6_Summer11LegDR-PU_S13_START53_LV6/"

liDATA=($(ls ${fpath} | egrep -v "QCD"))
liMC=($(ls ${fpathMC}))

nFilesDATA=1 # per job
#nFilesMC=10000
nFilesMC=1
#outDir="listsSTAT/"
outDir="lists"

rm -rf ${outDir}
mkdir ${outDir}

rm -f /tmp/tempDATA.txt
for line in $liDATA
do
d1=$(echo $line)
liDATA2=$(ls ${fpath}${d1})
echo $liDATA2 | while read line2
do
f1=$(echo $line2)
file=$(echo ${fpath}${d1}/${f1})
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

