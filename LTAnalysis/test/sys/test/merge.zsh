#!/bin/env zsh

mpath="/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/"
ipath="${1}/"
opath="histSYS/"

rm -rf ${mpath}${opath}
mkdir ${mpath}${opath}
mkdir ${mpath}${opath}/MC
mkdir ${mpath}${opath}/DATA

# MC
flist=$(ls ${mpath}${ipath} | egrep -v Run | grep JPCalib)

farr=()
idx=1
echo $flist | while read dname
do
loc=${mpath}${ipath}${dname}/data.root
farr[$idx]=${loc}
idx=$[$idx+1]
done
loco=${mpath}${opath}
hadd -f ${loco}/MC/data.root ${farr[*]}

# DATA
flist=$(ls ${mpath}${ipath} | grep JPCalib | egrep -v JetHT | egrep -v Pt)

farr=()
idx=1
echo $flist | while read dname
do
loc=${mpath}${ipath}${dname}/data.root
farr[$idx]=${loc}
idx=$[$idx+1]
done
loco=${mpath}${opath}
hadd -f ${loco}/DATA/data.root ${farr[*]}
