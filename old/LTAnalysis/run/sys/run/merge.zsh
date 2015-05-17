#!/bin/env zsh

mpath="/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/run/"
ipath="${1}/"
opath="histSYS/"

#flist=$(ls ${mpath}${ipath} | grep Pt | egrep -v "15to20")
# multijet btag
#flist=$(ls ${mpath}${ipath} | grep Pt)
# ttbar
flist=$(ls ${mpath}${ipath} | egrep -v Run)

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

# multijet btag
#flist=$(ls ${mpath}${ipath} | grep BTag)
# ttbar
flist=$(ls ${mpath}${ipath} | grep Run)

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
