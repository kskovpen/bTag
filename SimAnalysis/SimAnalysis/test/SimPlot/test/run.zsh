#!/bin/env zsh

name="${1}"
if [[ $name == "" ]]; then
  echo "Please specify the run name"
  exit 1
fi

runName="plot${name}"

rm -f log/*
rm -rf ${runName}
mkdir ${runName}

flist="list.txt"
echo $flist | while read line
do

fout="${runName}/output"

.././SimPlot ${line} ${fout}
done
