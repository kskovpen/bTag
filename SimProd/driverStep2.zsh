#!/bin/env zsh

cmsDriver.py step2 \
--filein file:BTV-RunIIFall15DR76-00001_step1.root \
--fileout file:BTV-RunIIFall15DR76-00001.root \
--mc \
--eventcontent RECOSIM \
--runUnscheduled \
--datatier GEN-SIM-RECO \
--conditions 76X_mcRun2_asymptotic_v12 \
--step RAW2DIGI,L1Reco,RECO,EI \
--era Run2_25ns \
--python_filename BTV-RunIIFall15DR76-00001_2_cfg.py \
--no_exec \
--customise Configuration/DataProcessing/Utils.addMonitoring -n 2 || exit $? ;
