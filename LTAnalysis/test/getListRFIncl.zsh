#!/bin/env zsh

fpathMC="/dpm/in2p3.fr/home/cms/phedex/store/user/vanhovep/CMSSW_7_6_3/MC/"
fpathDATA="/dpm/in2p3.fr/home/cms/phedex/store/user/vanhovep/CMSSW_7_6_3/Data/"

dataStr="JetHT"

liDATA=($(/usr/bin/rfdir ${fpathDATA} | egrep -e "$dataStr" | awk '{print $9}'))
liMC=($(/usr/bin/rfdir ${fpathMC} | egrep -v "$dataStr" | grep "PU25nsData2015v1_76X" | awk '{print $9}'))

fpathDATAXRD=$(echo ${fpathDATA} | sed "s%/dpm%root://sbgse1.in2p3.fr//dpm%g")
fpathMCXRD=$(echo ${fpathMC} | sed "s%/dpm%root://sbgse1.in2p3.fr//dpm%g")

nFilesDATA=35 # per job
nFilesMC=30
outDir="listsIncl/"

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
    echo $d3 | while read line2
    do
      f1=$(echo $line2)
      file=$(echo ${fpathDATAXRD}${d1}/${id2}/${f1})
      echo "${file}" >> /tmp/tempDATA.txt
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
    echo $d3 | while read line2
    do
      f1=$(echo $line2)
      file=$(echo ${fpathMCXRD}${d1}/${id2}/${f1})
      echo "${file}" >> /tmp/tempMC.txt
    done

    split -a 5 -l ${nFilesMC} -d /tmp/tempMC.txt /tmp/${d1}_
    lsfi=($(ls /tmp/${d1}_*))
    jid=0
    for fil in $lsfi
    do
      if [[ $#d2 != 1 ]]; then
	mv ${fil} ${outDir}$(echo ${d1} | sed "s%QCD_TuneCUETP8M1_13TeV_pythia8_RunIIFall15MiniAODv2-PU25nsData2015v1_76X_mcRun2_asymptotic_v12%%g")${id2}_ID${jid}.txt
      else
        mv ${fil} ${outDir}${d1}_ID${jid}.txt
      fi
      jid=$[$jid+1]
    done
    rm -f /tmp/tempMC.txt
  done
done

