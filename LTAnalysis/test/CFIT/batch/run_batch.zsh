#!/bin/env zsh

#que="sbg_local_short"
que="cms_local_short"

export WDIR="/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/CFIT/batch"

#outdir="results_away"
#outdir="results_nominal"
outdir="results"

rm -rf jobs
mkdir jobs

rm -rf ${outdir}
mkdir ${outdir}

logName="logs"
rm -rf ${logName}
mkdir ${logName}

tag="CSVT"
#tag="CMVAT"
fname="/home-pbs/kskovpen/bTagRun2/CMSSW_7_4_6_patch6/src/LTAnalysis/test/histCFIT/data.root"

#pt=("pt20t30" "pt30t50" \
#"pt50t70" "pt70t100" \
#"pt100t140" "pt140t200" \
#"pt200t300" "pt300t670")

#pt=("pt200t220" "pt220t250" "pt250t300" "pt300t400" "pt400t650")

pt=("pt30t80" "pt80t140" "pt140t180" "pt180t240" "pt240t420")

for i in $pt
do
  mkdir jobs/${i}
  cd jobs/${i}
  cp ${WDIR}/test .
  cp ${WDIR}/../libCFIT.so .
  cp ${WDIR}/../cfitDict_rdict.pcm .
  cp ${WDIR}/job.sh .

#  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${WDIR}/jobs/${pt}
#  cd -
#  cd ${WDIR}/jobs/${i}
#  ./test ${fname} ${i} ${tag} ${WDIR} ${outdir}
#  cd -
  
  qsub -N CFIT -q ${que} -o ${WDIR}/${logName}/${i}.log -j oe job.sh \
-v fname=${fname},pt=${i},tag=${tag},hdir=${WDIR},outdir=${outdir}
  cd -
done

