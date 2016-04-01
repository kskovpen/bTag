#!/bin/env zsh

cmsDriver.py step1 \
--filein "dbs:/QCD_Pt-120to170_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/RunIISummer15GS-MCRUN2_71_V1-v1/GEN-SIM" \
--fileout file:BTV-RunIIFall15DR76-00001_step1.root \
--pileup_input "dbs:/MinBias_TuneCUETP8M1_13TeV-pythia8/RunIISummer15GS-MCRUN2_71_V1-v2/GEN-SIM" \
--mc \
--eventcontent RAWSIM \
--pileup 2015_25ns_FallMC_matchData_PoissonOOTPU \
--datatier GEN-SIM-RAW \
--conditions 76X_mcRun2_asymptotic_v12 \
--step DIGI,L1,DIGI2RAW,HLT:@frozen25ns \
--era Run2_25ns \
--python_filename BTV-RunIIFall15DR76-00001_1_cfg.py \
--no_exec \
--customise Configuration/DataProcessing/Utils.addMonitoring -n 2 || exit $? ;
