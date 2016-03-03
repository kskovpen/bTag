#!/bin/env zsh

fpathMC="/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/BTV/25ns_763/"
fpathDATA="/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/BTV/25ns_763_v2/"

dataStr="BTagMu"

liDATA=($(/usr/bin/rfdir ${fpathDATA} | egrep -e "$dataStr" | awk '{print $9}'))
liMC=($(/usr/bin/rfdir ${fpathMC} | egrep -v "$dataStr" | awk '{print $9}'))

fpathDATAXRD=$(echo ${fpathDATA} | sed "s%/dpm%root://sbgse1.in2p3.fr//dpm%g")
fpathMCXRD=$(echo ${fpathMC} | sed "s%/dpm%root://sbgse1.in2p3.fr//dpm%g")

nFilesDATA=35 # per job
nFilesMC=30
outDir="lists/"

rm -rf ${outDir}
mkdir ${outDir}

# DATA

rm -f /tmp/tempDATA.txt
for line in $liDATA
do
  echo $line
  d1=$(echo $line)
  liDATA2=$(/usr/bin/rfdir ${fpathDATA}${d1} | awk '{print $9}')
  d2=($(echo $liDATA2))
  for id2 in $d2
  do
    liDATA3=$(/usr/bin/rfdir ${fpathDATA}${d1}/${id2})
    d3=$(echo $liDATA3 | awk '{print $9}')
    liDATA4=($(/usr/bin/rfdir ${fpathDATA}${d1}/${id2}/${d3} | awk '{print $9}'))
    for d4 in $liDATA4
    do
      liDATA5=($(/usr/bin/rfdir ${fpathDATA}${d1}/${id2}/${d3}/${d4} | awk '{print $9}'))
      for line2 in $liDATA5
      do
        f1=$(echo $line2)
        file=$(echo ${fpathDATAXRD}${d1}/${id2}/${d3}/${d4}/${f1})
        echo "${file}" >> /tmp/tempDATA.txt
      done
    done
    split -a 5 -l ${nFilesDATA} -d /tmp/tempDATA.txt /tmp/${d1}_
    lsfi=($(ls /tmp/${d1}_*))
    jid=0
    for fil in $lsfi
    do
      if [[ $#d2 != 1 ]]; then
        mv ${fil} ${outDir}${d1}_${id2}_ID${jid}.txt
      else
        mv ${fil} ${outDir}${d1}_ID${jid}.txt
      fi
      jid=$[$jid+1]
    done
    rm -f /tmp/tempDATA.txt
  done
done

# MC

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

