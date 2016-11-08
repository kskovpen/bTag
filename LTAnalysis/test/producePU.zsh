#!/bin/env zsh

# +- 5% variations
xsec=("67735" "71300" "74865")
tag=("Down" "Nom" "Up")

idx=1
for i in ${xsec}
do
echo $i
pileupCalc.py -i /opt/sbg/cms/ui5_data1/kskovpen/bTagProdICHEP/CMSSW_8_0_8_patch1/src/RecoBTag/PerformanceMeasurements/test/PROD/GRL/Cert_271036-274421_13TeV_PromptReco_Collisions16_JSON.txt \
--inputLumiJSON /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/PileUp/pileup_latest.txt \
--calcMode true \
--minBiasXsec ${i} \
--maxPileupBin 50 \
--numPileupBins 50 \
Pileup${tag[${idx}]}.root
idx=$[$idx+1]
done
