#!/bin/env zsh

fid="wmsid.txt"
storedir="output" 

rm -rf $storedir

cat ${fid} | while read line
do
jid=$(echo $line | awk '{print $2}')
echo $jid
glite-wms-job-output --dir ${storedir} ${jid}
done

