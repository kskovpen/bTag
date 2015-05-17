#!/bin/env zsh

jName=${1}
if [[ ${jName} == "" ]]; then
  echo "Please specify the run name"
  exit 1
fi

que="vo.sbg.in2p3.fr"

export HOME=$(pwd)

nmax=-1

dout="/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/run/"

fpath="${HOME}/lists/"

runName="hist${jName}"
logName="log${jName}"

rm -rf ${runName}
mkdir ${runName}
rm -rf ${logName}
mkdir ${logName}

nmax=-1
doRW=0
doAnalysis=0
year=2011
sp2011=0

fxsec="xsec/table.txt"

flist=$(ls ${fpath})

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
    nmax=${nmax}
  else
    isdata=0
    datamc="MC"
    nmax=${nmax}
  fi

  sp2011=0
  if [[ $fl2 == "JetRun2011" ]]; then
    sp2011=1
  fi

  fout=$(echo ${runName}/${dataset}/${line}_${jidx} | sed 's%.txt%%g')
  lout=$(echo ${line}_${jidx} | sed 's%.txt%%g')

  qsub -q ${que} -o ${logName}/${sample}.log -j oe job.sh \
-v dout=${dout},line2=${fpath}${line},fout=${fout},isdata=${isdata},\
noe=${noe},xsec=${xsec},eff=${eff},nmax=${nmax},lout=${lout},\
doRW=${doRW},doAnalysis=${doAnalysis},year=${year},sp2011=${sp2011}
done
