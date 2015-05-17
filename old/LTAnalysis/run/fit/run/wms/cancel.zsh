#!/bin/env zsh

fid="wmsid.txt"

cat ${fid} | while read line
do
jid=$(echo $line | awk '{print $2}')
echo $jid
glite-wms-job-cancel --noint ${jid}
done

