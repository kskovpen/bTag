#!/bin/env zsh

fpathMC="/opt/sbg/scratch1/cms/kskovpen/bTag/NTUPLES/13TeV_50ns/"
fpathDATA="/opt/sbg/scratch1/cms/kskovpen/bTag/NTUPLES/13TeV_50ns/"

fpathMCCalib="${fpathMC}QCD_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A/"
fpathMCNoCalib="${fpathMC}QCD_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_RunIISpring15DR74-Asympt50ns_MCRUN2_74_V9A_noJP/"

liDATACalib=($(ls ${fpathDATA} | egrep -v "QCD" | grep "JPCalib"))
liDATANoCalib=($(ls ${fpathDATA} | egrep -v "QCD" | egrep -v "JPCalib"))
liMCCalib=($(ls ${fpathMCCalib}))
liMCNoCalib=($(ls ${fpathMCNoCalib}))

nFilesDATA=10 # per job
#nFilesDATA=10000
#nFilesMC=10000
nFilesMC=20
#outDir="listsSTAT/"
outDir="lists"

rm -rf ${outDir}
mkdir ${outDir}

# calib data
rm -f /tmp/tempDATA.txt
for line in $liDATACalib
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

# non calib data
rm -f /tmp/tempDATA.txt
for line in $liDATANoCalib
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
mv ${fil} ${outDir}/${d1}_JPNoCalib_ID${jid}.txt
jid=$[$jid+1]
done
rm -f /tmp/tempDATA.txt
done

# calib MC
rm -f /tmp/tempMC.txt
for line in $liMCCalib
do
d1=$(echo $line)
liMC2=$(ls ${fpathMCCalib}${d1})
echo $liMC2 | while read line2
do
f1=$(echo $line2)
file=$(echo ${fpathMCCalib}${d1}/${f1})
echo "${file}" >> /tmp/tempMC.txt
done
split -a 5 -l ${nFilesMC} -d /tmp/tempMC.txt /tmp/${d1}_
lsfi=$(ls /tmp/${d1}_*)
jid=0
echo $lsfi | while read fil
do
mv ${fil} ${outDir}/${d1}_JPCalib_ID${jid}.txt
jid=$[$jid+1]
done
rm -f /tmp/tempMC.txt
done

# non calib MC
rm -f /tmp/tempMC.txt
for line in $liMCNoCalib
do
d1=$(echo $line)
liMC2=$(ls ${fpathMCNoCalib}${d1})
echo $liMC2 | while read line2
do
f1=$(echo $line2)
file=$(echo ${fpathMCNoCalib}${d1}/${f1})
echo "${file}" >> /tmp/tempMC.txt
done
split -a 5 -l ${nFilesMC} -d /tmp/tempMC.txt /tmp/${d1}_
lsfi=$(ls /tmp/${d1}_*)
jid=0
echo $lsfi | while read fil
do
mv ${fil} ${outDir}/${d1}_JPNoCalib_ID${jid}.txt
jid=$[$jid+1]
done
rm -f /tmp/tempMC.txt
done

