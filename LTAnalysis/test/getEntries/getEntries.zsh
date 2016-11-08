#!/bin/env zsh

dpath="srm://maite.iihe.ac.be:8443/"
fpath="pnfs/iihe/cms/store/user/kskovpen/BTV/ICHEPJPDATAv2"

fout="stat.txt"
rm -f ${fout}

li0=$(gfal-ls ${dpath}${fpath} | egrep -v "SingleElectron|BTagMu|BTagCSV|SingleMuon|DoubleEG|DoubleMuon|MuonEG|MET|JetHT|Tau")
echo $li0 | while read line0
do
  echo "##### $line0 #####"
  sp=0
  if [[ $line0 == "tHFCNC13TeV" || $line0 == "BTagMu" || \
  $line0 == "SingleElectron" || $line0 == "SingleMuon" || \
  $line0 == "SinglePhoton" || \
  $line0 == "DoubleEG" || $line0 == "DoubleMuon" || $line0 == "Tau" || \
  $line0 == "MuonEG" || $line0 == "MET" || $line0 == "JetHT" ]]; then
    sp=1
  fi
  
  if [[ $sp == 1 ]]; then
    continue
  fi
  
  li1=$(gfal-ls ${dpath}${fpath}/${line0})
  liarr1=(li1)
  if [[ $#liarr1 -ge 1 ]]; then
    sp=1
  fi
  echo $li1 | while read line1
  do
    if [[ $sp == 1 ]]; then
      echo "##### $line1 #####"
    fi
    li2=$(gfal-ls ${dpath}${fpath}/${line0}/${line1})
    echo $li2 | while read line2
    do
      li3=$(gfal-ls ${dpath}${fpath}/${line0}/${line1}/${line2})
      sp2=0
      liarr3=(li3)
      if [[ $#liarr3 -ge 1 ]]; then
        sp2=1
      fi      
      echo $li3 | while read line3
      do
        li4=($(gfal-ls ${dpath}${fpath}/${line0}/${line1}/${line2}/${line3}))
	sname=${line0}
	if [[ $sp == 1 ]]; then
	  sname=${sname}"_"$(echo ${line1} | sed "s%_AODFASTSIM_.*%%g")
	fi
	if [[ $sp2 == 1 ]]; then
	  sname=${sname}"_"$(echo ${line3})
	fi
	fstw=()
	fstc=()
	idx=1
	nfiles=$#li4
	echo "Number of files = ${nfiles}"
	for i in $li4
	do
	  if [[ ${i} == "failed" ]]; then
	    srmrmdir ${dpath}${fpath}/${line0}/${line1}/${line2}/${line3}/${i}
	    continue
	  fi
	  fil="${dpath}/${fpath}/${line0}/${line1}/${line2}/${line3}/${i}"
	  statStr=$(root -b -l getEntriesRoot.C\(\""${fil}"\"\) | grep -v "Warning" | \
grep -v "Processing" | sed '/^$/d')
          statw=$(echo $statStr | awk '{print $1}')
	  statc=$(echo $statStr | awk '{print $2}')
          fstw[${idx}]=${statw}
	  fstc[${idx}]=${statc}
	  idx=$[${idx}+1]
	done
	sumw=$((${(j[+])fstw}))
	sumc=$((${(j[+])fstc}))

	echo "Total stat = ${sumw} ${sumc}"
	echo "${sname}       ${sumw}       ${sumc}" | sed 's%Processing.*%%g' >> ${fout}
	
      done
    done
  done
  
done
