#!/bin/env zsh

#run="run_plot_PROC_v1"
#run="run_plot_PROC_PS_LATEST"
#run="run_plot_PROC_LATEST4"
#run="run_plot_PROC20130712_sd0t3"
run="run_plot_PROC20130712_sd0mu"

dpath="/gcf/atlas/data/JTNtuple_hist/${run}/"

flist=$(ls ${dpath})

echo $flist | while read dname
do
loc=${dpath}${dname}/hist
rm -f ${loc}/data.root
flist=$(ls ${loc})
farr=()
idx=1
echo $flist | while read fname
do
farr[$idx]=${loc}/$fname
idx=$[$idx+1]
done
hadd -f ${loc}/data.root ${farr[*]}
done
