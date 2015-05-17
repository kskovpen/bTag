#!/bin/env zsh

userareaRF="/dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/bTag/"

dire=($(/usr/bin/rfdir ${userareaRF} | awk '{print $9}' | egrep -E 'HISTO|LOG'))

for i in ${dire}
do
/usr/bin/rfrm -rf ${userareaRF}${i}
done
