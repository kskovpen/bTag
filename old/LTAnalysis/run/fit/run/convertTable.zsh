#!/bin/env zsh

if [[ $1 == "" ]]; then
fpath="results/"
else
fpath=$1
fi

flist=$(ls ${fpath} | grep .tex)

echo $flist | while read line
do
echo "convert $line"
pdflatex --interaction batchmode --output-directory ${fpath} ${fpath}${line}
done

rm -f ${fpath}*.log
rm -f ${fpath}*.aux
