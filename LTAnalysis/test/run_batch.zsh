#!/bin/env zsh

cp /tmp/x509up_u7989 /home-pbs/kskovpen/proxy/.

#tool="Hist"
tool="HistBoost"
#tool="Trigger"

jName=${1}
if [[ ${jName} == "" ]]; then
  echo "Please specify the run name"
  exit 1
fi

nmax=-1
doRW=0
samptype=0 #0-mu,1-incl

#que="sbg_local"
que="cms_local"

export HOME=$(pwd)

dout="/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/"

fpath="${HOME}/lists/"
###fpath="${HOME}/listsTEST/"
if [[ ${samptype} == 1 ]]; then
  fpath="${HOME}/listsIncl/"
fi

runName="hist${jName}"
logName="log${jName}"

rm -rf ${runName}
mkdir ${runName}
rm -rf ${logName}
mkdir ${logName}

fxsec="xsec/table.txt"
###fxsec="xsec/tableLocal.txt"
if [[ ${samptype} == 1 ]]; then
  fxsec="xsec/tableIncl.txt"
fi

flist=$(ls ${fpath})

echo $flist | while read line
do
  jidx=0
  sample=$(echo $line | sed 's%.txt%%g')
  dataset=$(echo $sample | sed 's%_ID..*%%g')
  if [[ ! -d ${runName}/${dataset} ]]; then
    mkdir ${runName}/${dataset}
  fi
  linexsec=$(grep ${dataset}FFF $fxsec)
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
  fl2=$(echo $sample | cut -c1-11)
  datamc=""
  if [[ $fl == "R" || $fl == "J" || $fl == "B" ]]; then
    isdata=1
    datamc="DATA"
    nmax=${nmax}
  else
    isdata=0
    datamc="MC"
    nmax=${nmax}
  fi

  fout=$(echo ${runName}/${dataset}/${line}_${jidx} | sed 's%.txt%%g')
  lout=$(echo ${line}_${jidx} | sed 's%.txt%%g')

  echo "${dataset}: $noe $xsec $eff isdata=$isdata" 
  qsub -N LTAnalysis -q ${que} -o ${logName}/${sample}.log -j oe job.sh \
-v dout=${dout},line2=${fpath}${line},fout=${fout},isdata=${isdata},\
noe=${noe},xsec=${xsec},eff=${eff},nmax=${nmax},\
doRW=${doRW},tool=${tool},samptype=${samptype}
done
