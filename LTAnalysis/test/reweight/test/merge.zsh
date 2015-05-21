#!/bin/env zsh

mpath="/opt/sbg/cms/ui5_data1/kskovpen/bTag/CMSSW_5_3_11/src/sysAna/run/"
ipath="${1}/"
opath="histSYS/"

flist=$(ls ${mpath}${ipath} | grep Pt)

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

flist=$(ls ${mpath}${ipath} | grep BTag)

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
