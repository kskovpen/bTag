#!/bin/env zsh

que="sbg_local"

export WDIR="/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/CFIT/batch"

outdir="results"
#outdir="results_away"

rm -rf jobs
mkdir jobs

rm -rf ${outdir}
mkdir ${outdir}

logName="logs"
rm -rf ${logName}
mkdir ${logName}

tag="CSVM"
fname="/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/histCFIT/data.root"
#pt=("pt20t30" "pt30t40" "pt40t50" "pt50t60" \
#"pt60t70" "pt70t80" "pt80t100" "pt100t120" \
#"pt120t160" "pt160t210" "pt210t260" "pt260t320" \
#"pt320t400" "pt400t500" "pt500t670")
pt=("pt20t30" "pt30t50" \
"pt50t70" "pt70t100" \
"pt100t140" "pt140t200" \
"pt200t300" "pt300t670")

for i in $pt
do
  mkdir jobs/${i}
  cd jobs/${i}
  cp ${WDIR}/test .
  cp ${WDIR}/../libCFIT.so .
  cp ${WDIR}/../cfitDict_rdict.pcm .
  cp ${WDIR}/job.sh .
  qsub -N CFIT -q ${que} -o ${WDIR}/${logName}/${i}.log -j oe job.sh \
-v fname=${fname},pt=${i},tag=${tag},hdir=${WDIR},outdir=${outdir}
  cd -
done

