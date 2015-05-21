#!/bin/env zsh

gpref="results/ptrw_pt"
gpost=".txt"
fpt20t30="${gpref}20t30${gpost}"
fpt30t40="${gpref}30t40${gpost}"
fpt40t50="${gpref}40t50${gpost}"
fpt50t60="${gpref}50t60${gpost}"
fpt60t75="${gpref}60t75${gpost}"
fpt75t90="${gpref}75t90${gpost}"
fpt90t110="${gpref}90t110${gpost}"
fpt110t140="${gpref}110t140${gpost}"
fpt140t200="${gpref}140t200${gpost}"
fpt200t300="${gpref}200t300${gpost}"
fpt300t400="${gpref}300t400${gpost}"
fpt400t500="${gpref}400t500${gpost}"
fpt500t700="${gpref}500t700${gpost}"
fpt700t1000="${gpref}700t1000${gpost}"
fpt1000t1500="${gpref}1000t1500${gpost}"
fpt1500t2000="${gpref}1500t2000${gpost}"

output="results/ptrw_merged0.txt"
rm -f $output
cat \
$fpt20t30 \
$fpt30t40 \
$fpt40t50 \
$fpt50t60 \
$fpt60t75 \
$fpt75t90 \
$fpt90t110 \
$fpt110t140 \
$fpt140t200 \
$fpt200t300 \
$fpt300t400 \
$fpt400t500 \
$fpt500t700 \
$fpt700t1000 \
$fpt1000t1500 \
$fpt1500t2000 \
> $output
cp $output results/ptrw_merged.txt

root -l -b makeFitPlotPTRW.C
