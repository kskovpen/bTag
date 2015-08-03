#!/bin/env zsh

runName="hist${1}"

tool="Hist"

fpath="lists/"

nmaxDATA=-1
nmaxMC=-1
nmax=-1
njobMax=16
doRW=2

fxsec="xsec/table.txt"

rm -f log/*
rm -rf ${runName}
mkdir ${runName}

flist=$(ls ${fpath} | grep "Pt-300to470_JPCalib_ID0.txt")
echo $flist | while read line
do
jidx=0
sample=$(echo $line | sed 's%.txt%%g')
dataset=$(echo $sample | sed 's%_ID..*%%g')
if [[ ! -d ${runName}/${dataset} ]]; then
mkdir ${runName}/${dataset}
fi
linexsec=$(grep $sample $fxsec)
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
if [[ $fl == "R" ]]; then
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

.././LTAnalysis ${fpath}${line} ${fout} ${isdata} ${noe} ${xsec} ${eff} ${nmax} ${doRW} ${tool}

jidx=$[$jidx+1]
done
