#!/bin/env zsh

runName="hist${1}"

fpath="lists/"

#nmaxDATA=500000
#nmaxMC=20000
nmaxDATA=1000
nmaxMC=1000
nmax=1000
njobMax=16
doRW=0
doAnalysis=0
year=2011
sp2011=0

fxsec="xsec/table.txt"
#fxsec="xsec/ttbar.txt"

rm -f log/*
rm -rf ${runName}
mkdir ${runName}

flist=$(ls ${fpath} | grep "Pt-170to300_ID0.txt")
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
if [[ $fl == "B" || $fl == "M" || $fl == "J" ]]; then 
isdata=1
datamc="DATA"
nmax=${nmaxDATA}
else
isdata=0
datamc="MC"
nmax=${nmaxMC}
fi

sp2011=0
if [[ $fl2 == "JetRun2011" ]]; then
sp2011=1
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

echo ${line} ${datamc} ${sp2011}
#nohup ./job.sh ${fpath}${line} ${fout} ${isdata} ${noe} ${xsec} ${eff} ${nmax} ${lout} ${doRW} ${doAnalysis} ${year} ${sp2011} > /tmp/${lout}.log 2>&1&
#sleep 1
.././LTAnalysis ${fpath}${line} ${fout} ${isdata} ${noe} ${xsec} ${eff} ${nmax} ${lout} ${doRW} ${doAnalysis} ${year} ${sp2011}

jidx=$[$jidx+1]
done
