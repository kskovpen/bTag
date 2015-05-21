#!/bin/env zsh

jname=$1

fid="wmsid_${jname}.txt"
fre="wmsid_${jname}_RESUBMIT.txt"

rm -f ${fre}

cat ${fid} | while read line
do
jid=$(echo $line | awk '{print $2}')
jname=$(echo $line | awk '{print $1}')
res=$(glite-wms-job-status \
${jid} 2>&1)
wai=$(echo ${res} | grep Waiting)
sub=$(echo ${res} | grep Submitted)
sch=$(echo ${res} | grep Scheduled)
run=$(echo ${res} | grep Running)
can=$(echo ${res} | grep Cancelled)
abo=$(echo ${res} | grep Aborted)
if [[ ${abo} != "" ]]; then
echo "${jname}" >> ${fre}
jstatus="\e[0;31mABORTED\e[0m"
elif [[ ${wai} == "" && ${sub} == "" && ${sch} == "" && ${run} == "" && ${can} == "" ]]; then
jstatus="\e[1;32mDONE\e[0m"
elif [[ ${can} != "" && ${run} == "" ]]; then
jstatus="\e[0;35mCANCELLED\e[0m"
elif [[ ${wai} != "" ]]; then
jstatus="\e[1;33mWAITING\e[0m"
elif [[ ${run} != "" ]]; then
jstatus="\e[0;31mRUNNING\e[0m"
fi
echo "${jname}: ${jstatus}"
done

