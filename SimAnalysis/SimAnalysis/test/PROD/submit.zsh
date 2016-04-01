#!/bin/env zsh

slist="list.txt"
pset="crabConfigTemplate.py"
ver="v20160401"
prodv="/store/user/kskovpen/SimAnalysis/${ver}/"

rm -f crabConfig.py*

samp=()
is=1
cat ${slist} | while read line
do
  samp[${is}]=${line}
  is=$[$is+1]
done

for i in ${samp}
do
  spl=($(echo $i | tr "/" "\n"))
  pubdn=$(echo "${spl[2]}_${spl[3]}" | sed 's%-%_%g')
  nam=$(echo "${spl[1]}" | sed 's%-%_%g')
  reqn=$(echo "${nam}_${pubdn}" | sed 's%_RunIISummer15GS_MCRUN2_71_V1_v1%%g' \
  | sed 's%_RunIISpring15DR74_AsymptNoPUReco_MCRUN2_74_V9A_v1%%g' \
  | sed 's%_RunIISpring15DR74_Asympt25nsRecodebug_MCRUN2_74_V9_v1%%g')
  cat ${pset} | sed "s%INPUTDATASET%${i}%g" \
  | sed "s%OUTLFN%${prodv}%g" \
  | sed "s%REQUESTNAME%${reqn}%g" \
  | sed "s%PUBLISHDATANAME%${pubdn}%g" \
  > crabConfig.py
  
  echo "${reqn}"
  crab submit
  
done

rm -f crabConfig.py*
