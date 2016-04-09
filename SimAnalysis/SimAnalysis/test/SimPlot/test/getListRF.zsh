#!/bin/env zsh

fpathMC="/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/SimAnalysis/v20160409/"

liMC=($(/usr/bin/rfdir ${fpathMC} | awk '{print $9}'))

fpathMCXRD=$(echo ${fpathMC} | sed "s%/dpm%root://sbgse1.in2p3.fr//dpm%g")

nFilesMC=20
outDir="lists/"

rm -rf ${outDir}
mkdir ${outDir}

rm -f /tmp/tempMC.txt
for line in $liMC
do
  echo $line
  d1=$(echo $line)
  liMC2=$(/usr/bin/rfdir ${fpathMC}${d1} | awk '{print $9}')
  d2=($(echo $liMC2))
  for id2 in $d2
  do
    liMC3=$(/usr/bin/rfdir ${fpathMC}${d1}/${id2})
    d3=$(echo $liMC3 | awk '{print $9}')
    liMC4=($(/usr/bin/rfdir ${fpathMC}${d1}/${id2}/${d3} | awk '{print $9}'))
    for d4 in $liMC4
    do
      liMC5=($(/usr/bin/rfdir ${fpathMC}${d1}/${id2}/${d3}/${d4} | awk '{print $9}'))
      for line2 in $liMC5
      do
        f1=$(echo $line2)
        file=$(echo ${fpathMCXRD}${d1}/${id2}/${d3}/${d4}/${f1})
        echo "${file}" >> /tmp/tempMC.txt
      done
    done
    split -a 5 -l ${nFilesMC} -d /tmp/tempMC.txt /tmp/${d1}_
    lsfi=($(ls /tmp/${d1}_*))
    jid=0
    for fil in $lsfi
    do
      sampStrip=$(echo $id2 | sed "s%_RunIISpring15MiniAODv2_.*%%g")
      if [[ $#d2 != 1 && ${d1} != "tHFCNC13TeV" ]]; then
        mv ${fil} ${outDir}${d1}_${sampStrip}_ID${jid}.txt
      else
        if [[ ${d1} == "tHFCNC13TeV" ]]; then
          mv ${fil} ${outDir}${d1}"_"$(echo ${id2} | sed "s%_AODFASTSIM_.*%%g")_ID${jid}.txt
        else
          mv ${fil} ${outDir}${d1}_ID${jid}.txt
	fi
      fi
      jid=$[$jid+1]
    done
    rm -f /tmp/tempMC.txt
  done
done

