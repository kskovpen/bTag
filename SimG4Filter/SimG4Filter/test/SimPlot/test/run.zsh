#!/bin/env zsh

flist="pt300to470.txt"
#flist="pt30to50.txt"

runOnReco=1

echo $flist | while read line
do

fout="output"

.././SimPlot ${line} ${fout} ${runOnReco}
done
