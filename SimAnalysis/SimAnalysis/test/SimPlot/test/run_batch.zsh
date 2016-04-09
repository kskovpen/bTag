#!/bin/env zsh

cp /tmp/x509up_u7989 /home-pbs/kskovpen/proxy/.

jName=${1}
if [[ ${jName} == "" ]]; then
  echo "Please specify the run name"
  exit 1
fi

samp="600to800"

#que="sbg_local"
#que="cms_local"
#que="cms"
que="cms_local_short"

export HOME=$(pwd)

dout="/home-pbs/kskovpen/SimAnalysis/CMSSW_7_6_1/src/SimAnalysis/SimAnalysis/test/SimPlot/test/"

fpath="${HOME}/lists/"

runName="hist${jName}"
logName="log${jName}"

rm -rf ${runName}
mkdir ${runName}
rm -rf ${logName}
mkdir ${logName}

fxsec="xsec/table.txt"

flist=$(ls ${fpath} | grep ${samp})

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
  fl=$(echo $sample | cut -c1-1)
  fl2=$(echo $sample | cut -c1-11)

  fout=$(echo ${runName}/${dataset}/${line}_${jidx} | sed 's%.txt%%g')
  lout=$(echo ${line}_${jidx} | sed 's%.txt%%g')

  echo "${dataset}: $noe $xsec $eff"
  qsub -N SimPlot -q ${que} -o ${logName}/${sample}.log -j oe job.sh \
-v dout=${dout},line2=${fpath}${line},fout=${fout},\
noe=${noe},xsec=${xsec},eff=${eff}
done
