#!/bin/env zsh

doCheck=0

datapath="listsSTAT/"

tmpPath="/opt/sbg/data/sbgse24/data1/cms/kskovpen/Entries"

rm -rf ${tmpPath}
mkdir ${tmpPath}

#li=$(ls ${datapath} | grep "Pt")
#li=$(ls ${datapath} | grep "Run")
li=$(ls ${datapath})
#fout="xsec/stat.txt"
fout="xsec/STAT.txt"
rm -rf bad.txt

rm -f ${fout}

echo $li | while read line
do

#  isdata=$(echo $line | egrep -e "Run2015")
  isdata=""
  if [[ ${isdata} != "" ]]; then
    fname=$(echo $line | sed 's%.txt%%g')
    echo "${fname}       666" >> ${fout}
    continue
  else
  
    fin=$(echo ${datapath}${line})
    fl=${fin}
  
    fnameDATASET=$(echo $line | sed 's%.txt%%g' | sed 's%_ID.*%%g')
    echo ${fnameDATASET}
  
    #fpath=$(head -1 ${fl} | sed 's%JetTree_mc_1.*%%g')
    #fpath=$(head -1 ${fl} | sed 's%JetTree_mc_FatJets_Subjets_1.*%%g')
    fpath=$(head -1 ${fl} | sed 's%JetTree_data_FatJets_Subjets_1.*%%g' | sed 's%JetTree_mc_FatJets_Subjets_1.*%%g')
  
    li=($(ls ${fpath}))

    farr=()
    idx=1
    for fname in $li
    do
      farr[$idx]=${fpath}$fname
      idx=$[$idx+1]
    done
    hadd -f ${tmpPath}/data.root ${farr[*]}

    stat=$(root -b -l getEntriesRoot.C\(\""${tmpPath}/data.root"\"\) | grep -v "Warning" | \
grep -v "Processing" | sed '/^$/d')

    rm -rf ${tmpPath}/data.root

    echo "${fnameDATASET}       ${stat}" | sed 's%Processing.*%%g' >> ${fout}

  fi
  
done
