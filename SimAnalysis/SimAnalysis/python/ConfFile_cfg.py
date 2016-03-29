import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing
import os

process = cms.Process("SimTree")

from PhysicsTools.PatAlgos.patTemplate_cfg import *
process.options.allowUnscheduled = cms.untracked.bool(True)

process.load("CommonTools.ParticleFlow.PF2PAT_cff")
process.load("PhysicsTools.PatAlgos.patSequences_cff")

from PhysicsTools.PatAlgos.tools.pfTools import *
postfix = "PFlow"
jetAlgo = "AK4"
usePF2PAT(process,runPF2PAT=True,jetAlgo=jetAlgo,runOnMC=True,postfix=postfix)

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag.globaltag = "MCRUN2_74_V9A"

process.es_prefer_GBRWrapperRcd = cms.ESPrefer("PoolDBESSource","loadRecoTauTagMVAsFromPrepDBPFlow")

#options = VarParsing('analysis')
#options.register('isData',False,VarParsing.multiplicity.singleton,VarParsing.varType.int,'Run on real data')
#options.register('confFile', 'conf.xml', VarParsing.multiplicity.singleton, VarParsing.varType.string, "Flattree variables configuration")
#options.register('bufferSize', 32000, VarParsing.multiplicity.singleton, VarParsing.varType.int, "Buffer size for branches of the flat tree")
#options.parseArguments()

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(    
"root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/user/kskovpen/Test/MuReco.root"
    )
)

process.TFileService = cms.Service("TFileService", fileName = cms.string("output.root"))

process.options = cms.untracked.PSet(
     wantSummary = cms.untracked.bool(False),
     allowUnscheduled = cms.untracked.bool(True)
)

process.SimTree = cms.EDAnalyzer('SimAnalysis',

                   simVerticesInput = cms.InputTag("g4SimHits","","SIM"),
                   simTracksInput = cms.InputTag("g4SimHits","","SIM"),
                   genParticlesInput = cms.InputTag("genParticles","","HLT"), # GEN-SIM-RECO
#                   genParticlesInput = cms.InputTag("genParticles","","SIM"), # GEN-SIM
                   hepMCInput = cms.InputTag("generator","","SIM"),
                   pfJetInput = cms.InputTag("ak4PFJetsCHS","","RECO"),
                   patJetInput = cms.InputTag("patJetsPFlow"),
                   recoMuonInput = cms.InputTag("muons","","RECO"),
                   patMuonInput = cms.InputTag("patMuonsPFlow")
)

process.p = cms.Path(process.patDefaultSequence*process.SimTree)

from PhysicsTools.PatAlgos.patEventContent_cff import patEventContentNoCleaning
process.out.outputCommands = cms.untracked.vstring('drop *')
