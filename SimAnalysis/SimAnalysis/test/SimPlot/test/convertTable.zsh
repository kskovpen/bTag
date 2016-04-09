#!/bin/env zsh

cdir=$(pwd)

flist=$(ls ${cdir} | grep .tex)

echo $flist | while read line
do
echo "convert $line"
pdflatex --interaction batchmode --output-directory ${cdir} ${cdir}/${line}
done

rm -f ${cdir}/*.log
rm -f ${cdir}/*.aux
