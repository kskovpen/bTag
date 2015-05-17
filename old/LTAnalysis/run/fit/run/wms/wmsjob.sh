#!/bin/sh

export LFC_HOST=sbglfc1.in2p3.fr

echo "=====  Begin  =====" 
date
echo "The program is running on $HOSTNAME"
date
echo "=====  End  ====="

lsb_release -a

WDIR=$(pwd)

runmode=${1}
sysidx=${2}
transfer0=${3}
ana=${4}
anaName=${5}
runName=${6}
voName=${7}

dpathDATA="/opt/sbg/scratch1/${voName}/kskovpen/${anaName}/${runName}DATA"
dpathLOG="/opt/sbg/scratch1/${voName}/kskovpen/${anaName}/${runName}LOG"

flog="log"

export ROOTSYS=/cvmfs/cms.cern.ch/slc6_amd64_gcc472/lcg/root/5.32.00
source $ROOTSYS/bin/thisroot.sh
rootV=$(root-config --version)
echo "ROOT v${rootV} has been set up"

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${WDIR}

export LD_LIBRARY_PATH=\
/cvmfs/cms.cern.ch/slc6_amd64_gcc472/external/gcc/4.7.2/lib64:\
/usr/lib64:\
/cvmfs/cms.cern.ch/slc6_amd64_gcc472/external/gcc/4.7.2/lib:\
/cvmfs/cms.cern.ch/slc6_amd64_gcc472/cms/cmssw/CMSSW_5_3_11/external/slc6_amd64_gcc472/lib/:\
$LD_LIBRARY_PATH

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:atlasstyle-00-03-04/

export PATH=/cvmfs/cms.cern.ch/slc6_amd64_gcc472/external/gcc/4.7.2/bin:$PATH

export LD_PRELOAD=/usr/lib64/libglobus_gssapi_gsi.so.4

gzip -d code.tar.gz
tar -xvf code.tar
echo "done unpacking"
make
echo "done compiling"
mkdir results/
mkdir pics/
mkdir input/

mkdir histSYS
mkdir histSYS/DATA
mkdir histSYS/MC
srmcp srm://sbgse1.in2p3.fr:8446/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/bTag/FITINPUT/DATA.root file:///${WDIR}/histSYS/DATA/data.root
srmcp srm://sbgse1.in2p3.fr:8446/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/bTag/FITINPUT/MC.root file:///${WDIR}/histSYS/MC/data.root

fin="results/eff${runmode}.txt"
sysarr=(${sysidx//s/ })
for i in ${sysarr[@]}
do
echo "Fitting ${i}"
./fit ${runmode} ${i}
chmod u+x plotFit.sh
./plotFit.sh ${fin} ${ana}

if [[ ${transfer0} == 0 && ${i} == 0 ]]; then
continue
fi

##dpath="srm://sbgse1.in2p3.fr:8446/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/bTag/FIT"
##srmcp -retry_num 4 -retry_timeout 30000 file:///${WDIR}/${fin} \
##${dpath}/eff${runmode}_${i}.txt
##srmcp -retry_num 4 -retry_timeout 30000 file:///${WDIR}/results/fit_EFF_beauty_${runmode}.root \
##${dpath}/fit_EFF_beauty_${runmode}_${i}.root
##srmcp -retry_num 4 -retry_timeout 30000 file:///${WDIR}/results/fit_EFF_charm_${runmode}.root \
##${dpath}/fit_EFF_charm_${runmode}_${i}.root
##srmcp -retry_num 4 -retry_timeout 30000 file:///${WDIR}/results/fit_FIT123_beforeBTAG.root \
##${dpath}/fit_FIT123_beforeBTAG_${i}.root
##srmcp -retry_num 4 -retry_timeout 30000 file:///${WDIR}/results/fit_FIT123_afterBTAG.root \
##${dpath}/fit_FIT123_afterBTAG_${i}.root

cp ${WDIR}/${fin} ${dpathDATA}/eff${runmode}_${i}.txt
cp ${WDIR}/results/fit_EFF_beauty_${runmode}.root ${dpathDATA}/fit_EFF_beauty_${runmode}_${i}.root
cp ${WDIR}/results/fit_EFF_charm_${runmode}.root ${dpathDATA}/fit_EFF_charm_${runmode}_${i}.root
cp ${WDIR}/results/fit_FIT123_beforeBTAG.root ${dpathDATA}/fit_FIT123_beforeBTAG_${i}.root
cp ${WDIR}/results/fit_FIT123_afterBTAG.root ${dpathDATA}/fit_FIT123_afterBTAG_${i}.root
done

rm -rf *.C *.cxx *.h Makefile fit atlas* *.zsh
rm -rf pics
rm -rf results
rm -rf histSYS

rm code.tar
rm plotFit.sh
rm wmsjob.sh
rm -rf input

echo "need to clean ?"
ls 
