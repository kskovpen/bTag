import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing
import os, sys

options = VarParsing('analysis')
options.register('isData',False,VarParsing.multiplicity.singleton,VarParsing.varType.bool,'Run on real data')
options.parseArguments()

process = cms.Process("TrigTree")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi");
process.load("Geometry.CaloEventSetup.CaloGeometry_cfi");
process.load("Geometry.CaloEventSetup.CaloTopology_cfi");

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.load('Configuration.StandardSequences.Services_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')

process.GlobalTag.globaltag = 'MCRUN2_74_V9A::All'

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    'file://MINIAOD.root'
#    'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/ttH/testFiles/MiniAOD/ttH_ev_2.root'
    )
)

process.TFileService = cms.Service("TFileService", fileName = cms.string("output.root"))

process.TrigTree = cms.EDAnalyzer('TrigTree',

                  isData            = cms.bool(options.isData),
                  triggerBits = cms.InputTag("TriggerResults","","HLT"),
                  triggerPrescales = cms.InputTag("patTrigger"),
                  triggerObjects = cms.InputTag("selectedPatTrigger"),
                  triggerNames = cms.vstring(
                                               "HLT_BTagMu_DiJet20_Mu5_v1"
                  ),
                  jetInput = cms.InputTag("slimmedJets")
)

process.p = cms.Path(
process.TrigTree)
    
    
