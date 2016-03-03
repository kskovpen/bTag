#!/bin/env zsh

runName="hist${1}"

#tool="Hist"
tool="HistBoost"

#fpath="lists/"
fpath=""

nmaxDATA=100000
nmaxMC=1000
nmax=1000
njobMax=16
doRW=0
sample=0 # 0-mu-enriched 1-inclusive

fxsec="xsec/table.txt"

rm -f log/*
rm -rf ${runName}
mkdir ${runName}

#flist=$(ls ${fpath} | grep "QCD_Pt-600to800_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8_ID0.txt")
#flist=$(ls ${fpath} | grep "BTagMu_Run2015D-16Dec2015-v1_SILVER_ID50.txt")
flist="list.txt"
echo $flist | while read line
do
jidx=0
sample=$(echo $line | sed 's%.txt%%g')
dataset=$(echo $sample | sed 's%_ID..*%%g')
if [[ ! -d ${runName}/${dataset} ]]; then
mkdir ${runName}/${dataset}
fi
linexsec=$(grep ${sample}FFF $fxsec)
noe=$(echo $linexsec | awk '{print $2}')
xsec=$(echo $linexsec | awk '{print $3}')
eff=$(echo $linexsec | awk '{print $4}')
if [[ $noe == "" ]]; then
noe=1
fi
if [[ $xsec == "" ]]; then
xsec=1
fi
if [[ $eff == "" ]]; then
eff=1
fi
fl=$(echo $sample | cut -c1-1)
fl2=$(echo $sample | cut -c1-10)
datamc=""
if [[ $fl == "R" || $fl == "B" ]]; then
isdata=1
datamc="DATA"
nmax=${nmaxDATA}
else
isdata=0
datamc="MC"
nmax=${nmaxMC}
fi

#cat ${fpath}${line} | while read line2
#do
fout=$(echo ${runName}/${dataset}/${line}_${jidx} | sed 's%.txt%%g')
lout=$(echo ${line}_${jidx} | sed 's%.txt%%g')

list=($(pgrep LTAnalysis))
njobs=${#list[@]}

if [[ $njobs -ge ${njobMax} ]]; then
while true
do
sleep 1
list=($(pgrep LTAnalysis))
njobs=${#list[@]}
if [[ $njobs -lt ${njobMax} ]]; then
break
fi
done
fi

echo ${line} ${datamc}

.././LTAnalysis ${fpath}${line} ${fout} ${isdata} ${noe} ${xsec} ${eff} ${nmax} ${doRW} ${tool} ${sample}

jidx=$[$jidx+1]
done
