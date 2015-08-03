#!/bin/env zsh

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../

fname="../../histCFIT/data.root"
pt="pt20t30"
tag="CSVL"
outdir="/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/CFIT/batch/"
dirname="results"

./test ${fname} ${pt} ${tag} ${outdir} ${dirname}
