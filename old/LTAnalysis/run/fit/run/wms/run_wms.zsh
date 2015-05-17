#!/bin/env zsh

anaName="bTag"
runName="CSVL50"
#runName="TCHPT50"
voName="vo.sbg.in2p3.fr"

singleRW=0

analysis=1 # QCD
#analysis=2 # TTBAR
#analysis=3 # BINV2
#analysis=4 # QCD no or partial sys

if [[ ${analysis} == 1 || ${analysis} == 3 ]]; then
  if [[ ${singleRW} == 1 ]]; then
    idxsys_sys1="0s1s-1s2s-2s3s"
    idxsys_sys2="0s-3s4s-4s5s-5"
    idxsys_sys3="0s6s-6s7s-7s8s"
    idxsys_sys4="0s-8s9s-9s10s-10"
  else
    idxsys_sys1="0s1s-1s2s-2s3s"
    idxsys_sys2="0s-3s4s-4s5s-5"
    idxsys_sys3="0s6s-6s7s-7s8s"
    idxsys_sys4="0s-8s9s-9s10s-10"
    idxsys_sys5="0s11s-11s12s-12s13s-13"
  fi
elif [[ ${analysis} == 2 ]]; then
  if [[ ${singleRW} == 1 ]]; then
    idxsys_sys1="0s1s-1s2s-2s3s"
    idxsys_sys2="0s-3s4s-4s5s-5"
  else
    idxsys_sys1="0s1s-1s2s-2s3s"
    idxsys_sys2="0s-3s4s-4s5s-5"
    idxsys_sys3="0s6s-6s7s-7"
    idxsys_sys4="0s8s-8"
  fi
else
#  idxsys_sys1="0s1s-1"
  idxsys_sys1="0"
fi

if [[ ${analysis} == 1 || ${analysis} == 3 ]]; then
if [[ ${singleRW} == 1 ]]; then
tsub=("idxsys_sys1" "idxsys_sys2" \
"idxsys_sys3" "idxsys_sys4" \
"idxsys_stat")
else
tsub=("idxsys_sys1" "idxsys_sys2" \
"idxsys_sys3" "idxsys_sys4" \
"idxsys_sys5" \
"idxsys_stat")
fi
elif [[ ${analysis} == 2 ]]; then
if [[ ${singleRW} == 1 ]]; then
tsub=("idxsys_sys1" "idxsys_sys2" \
"idxsys_stat")
else
tsub=("idxsys_sys1" "idxsys_sys2" \
"idxsys_sys3" "idxsys_sys4" \
"idxsys_stat")
fi
else
#tsub=("idxsys_sys1" \
#"idxsys_stat")
tsub=("idxsys_stat")
fi
#tsub=("idxsys_stat")

idxstat=()
j=1
k=0
for i in {666..766}
#for i in {666..1166}
do
if [[ ${k} == 0 ]]; then
idxstat[${j}]="0"
fi
idxstat[${j}]=${idxstat[${j}]}"s"${i}
if [[ ${k} == 5 ]]; then
j=$[$j+1]
k=0
continue
fi
k=$[$k+1]
done

runmode="ALL"

##dpath="/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/bTag/FIT"
#/usr/bin/rfrm -rf ${dpath}
#/home/kskovpen/bin/rfrmr ${dpath}

##rem=$(/home/kskovpen/bin/rfrmr ${dpath} 2>&1)
##while true
##do
##sleep 1
##list=$(ps x | grep rfremove | grep -v 'grep')
##if [[ $list == "" ]]; then
##break
##fi
##done

##/usr/bin/rfrm -rf ${dpath}
##/usr/bin/rfmkdir ${dpath}

ipath="/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/bTag/FITINPUT"
#srmrmdir srm://sbgse1.in2p3.fr:8446${ipath}
#srmmkdir srm://sbgse1.in2p3.fr:8446${ipath}
/usr/bin/rfrm -rf ${ipath}
/usr/bin/rfmkdir ${ipath}
#srmcp ../../../histSYS/DATA/data.root srm://sbgse1.in2p3.fr:8446${ipath}/DATA.root
#srmcp ../../../histSYS/MC/data.root srm://sbgse1.in2p3.fr:8446${ipath}/MC.root
/usr/bin/rfcp ../../../histSYS/DATA/data.root ${ipath}/DATA.root
/usr/bin/rfcp ../../../histSYS/MC/data.root ${ipath}/MC.root

glite-wms-job-delegate-proxy -e https://sbgwms2.in2p3.fr:7443/glite_wms_wmproxy_server -d kskovpen
##glite-wms-job-delegate-proxy -d kskovpen

wdir="SUBMIT"
rm -rf ${wdir}
jst="wmsid.txt"
mkdir ${wdir}

rm -f ${jst}

rm -f code.tar.gz
tar --exclude='run' -czf code.tar ../../ ../*.C
gzip code.tar

for ig in ${tsub}
do

echo ${ig}

transfer0=0

if [[ ${ig} == "idxsys_stat" ]]; then
idx=0
for i in ${idxstat[@]}
do
transfer0=1
cp j.jdl ${wdir}/temp.jdl
cat ${wdir}/temp.jdl | \
sed "s%runmode%${runmode}%g" | \
sed "s%anaName%${anaName}%g" | \
sed "s%runName%${runName}%g" | \
sed "s%voName%${voName}%g" | \
sed "s%sysidx%${i}%g" | \
sed "s%transfer0%${transfer0}%g" | \
sed "s%analysis%${analysis}%g" \
> ${wdir}/${ig}_${idx}.jdl
rm ${wdir}/temp.jdl
idx=$[$idx+1]
done
continue
fi

cp j.jdl ${wdir}/temp.jdl
if [[ ${ig} == "idxsys_sys1" ]]; then
sysidx=${idxsys_sys1}
fi
if [[ ${ig} == "idxsys_sys2" ]]; then
sysidx=${idxsys_sys2}
fi
if [[ ${ig} == "idxsys_sys3" ]]; then
sysidx=${idxsys_sys3}
fi
if [[ ${ig} == "idxsys_sys4" ]]; then
sysidx=${idxsys_sys4}
fi
if [[ ${ig} == "idxsys_sys5" ]]; then
sysidx=${idxsys_sys5}
fi

cat ${wdir}/temp.jdl | \
sed "s%runmode%${runmode}%g" | \
sed "s%anaName%${anaName}%g" | \
sed "s%runName%${runName}%g" | \
sed "s%voName%${voName}%g" | \
sed "s%sysidx%${sysidx}%g" | \
sed "s%transfer0%${transfer0}%g" | \
sed "s%analysis%${analysis}%g" \
> ${wdir}/${ig}.jdl

rm ${wdir}/temp.jdl
done

outp=$(glite-wms-job-submit -e https://sbgwms2.in2p3.fr:7443/glite_wms_wmproxy_server -a --collection ${wdir}/${sample} 2>&1 | grep "https://sbgwms2.in2p3.fr:9000")
##outp=$(glite-wms-job-submit -a --collection ${wdir}/ 2>&1 | grep "https://sbgwms1.in2p3.fr:9000")
#glite-wms-job-submit -a --collection ${wdir}/
echo "FIT   $outp" >> ${jst}
