import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing
import os

#from PhysicsTools.PatAlgos.patTemplate_cfg import *
#process.options.allowUnscheduled = cms.untracked.bool(True)

#options = VarParsing('analysis')
#options.register('isData',False,VarParsing.multiplicity.singleton,VarParsing.varType.int,'Run on real data')
#options.register('confFile', 'conf.xml', VarParsing.multiplicity.singleton, VarParsing.varType.string, "Flattree variables configuration")
#options.register('bufferSize', 32000, VarParsing.multiplicity.singleton, VarParsing.varType.int, "Buffer size for branches of the flat tree")
#options.parseArguments()

process = cms.Process("SimTree")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/4E296536-7D79-E511-BFC0-0026B92779F1.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/76FF794B-A579-E511-AA37-28924A33BBAA.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/C2582320-7D79-E511-8288-28924A33B8AE.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/F07E8D2A-7D79-E511-8858-0026B94DBDC9.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/F26BC517-7D79-E511-920A-28924A3504DA.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/FCC47644-7D79-E511-A2CF-0026B94DBDC9.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/08FB58BA-5679-E511-951B-28924A33B8AE.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/1482D640-5679-E511-9C9F-009C02AAB484.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/382513CE-5679-E511-BDC6-28924A3504DA.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/540AD3D5-5679-E511-83E9-28924A33AF26.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/629EA73C-5679-E511-8823-28924A33B8AE.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/7882063E-5679-E511-BBFB-28924A33AFC2.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/7A113835-5679-E511-B659-28924A3504DA.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/8293A7B8-5679-E511-B60E-0023AEEEB55F.root',
'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt-170to300_MuEnrichedPt5_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/8A59F7B3-5679-E511-8B21-0026B9278637.root'

#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/1E4C245D-D97B-E511-9FE9-0026B94DBDE3.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/38DB237D-397B-E511-B96C-009C02AABB60.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/428F6B7C-397B-E511-8BBC-28924A38DC1E.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/68A9677C-397B-E511-8810-0023AEEEB226.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/A2BDA47D-397B-E511-AB57-28924A33B8AE.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/10F208F6-787B-E511-BAEF-0026B94DBDD6.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/12024EF4-787B-E511-9EEC-3417EBE47FE5.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/5CFD509C-797B-E511-A99E-3417EBE47FE5.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/78E63337-797B-E511-91F2-0026B9278637.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/7AB17348-797B-E511-9DD6-0026B9278637.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/7C5695FD-787B-E511-9C42-0026B94DBDC9.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/8658823B-797B-E511-890E-0026B92786AC.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/9890B522-797B-E511-B0DD-009C02AABB60.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/A4038513-117C-E511-9F75-28924A33B062.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/20000/DEB83205-797B-E511-9498-0026B927865E.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/40000/30BAF13A-D17B-E511-B34B-0023AEEEB6FA.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/40000/3606FDC0-027B-E511-BC71-0026B92786AC.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/40000/44CC2AC9-027B-E511-9653-0026B94DBD7B.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/40000/9A7BCFB5-027B-E511-AE93-009C02AAB258.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/40000/C80CDFB9-027B-E511-BFC2-0026B94DBDC9.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/40000/DCFD43BE-027B-E511-A1C7-0026B9277A3F.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/102C6F6D-667B-E511-B22E-28924A33AF26.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/2013D17D-667B-E511-A343-0023AEEEB559.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/2434D1CB-667B-E511-86A3-009C02AAB554.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/42B50277-637B-E511-88EE-28924A33B9AA.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/709F22C3-667B-E511-BAEB-3417EBE47EBC.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/727D0BC3-667B-E511-BD1F-0023AEEEB226.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/8AF3FFBD-667B-E511-9FE9-28924A33B9AA.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/AA316668-617B-E511-A606-28924A35056A.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/BA7C9F7B-317C-E511-B490-0026B94DBE17.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/BAE43E81-617B-E511-8EC0-BC305B390A0B.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/C446D3E8-627B-E511-9645-BC305B390A0B.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/D060ECDB-627B-E511-A3D4-28924A33B9AA.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/D8C02C2B-617B-E511-B910-28924A33AFD2.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/EC629D9F-617B-E511-81AD-28924A33B9AA.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/60000/F472E549-667B-E511-8C08-0026B92779BD.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/14F07515-8B7B-E511-9760-BC305B390A18.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/1A1B0FFB-8A7B-E511-9F36-0026B9277A18.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/1C3C2D27-E17B-E511-806A-0023AEEEB226.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/2A27B4F8-8A7B-E511-A4A6-28924A33B8AE.root',
#'root://sbgse1.in2p3.fr//dpm/in2p3.fr/home/cms/phedex/store/mc/RunIISummer15GS/QCD_Pt_170to300_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/80000/50B4ACB9-8C7B-E511-9AEA-BC305B390A3F.root'
    )
)

process.TFileService = cms.Service("TFileService", fileName = cms.string("output.root"))

process.options = cms.untracked.PSet(
     wantSummary = cms.untracked.bool(False),
     allowUnscheduled = cms.untracked.bool(True)
)

process.SimTree = cms.EDAnalyzer('SimAnalysis',

#                  dataFormat = cms.string("AOD"),

#                  bufferSize        = cms.int32(options.bufferSize),
#                  confFile          = cms.string(options.confFile),

#                  isData            = cms.bool(options.isData),

                   simVerticesInput = cms.InputTag("g4SimHits","","SIM"),
                   simTracksInput = cms.InputTag("g4SimHits","","SIM"),
                   genParticlesInput = cms.InputTag("genParticles","","SIM"),
                   hepMCInput = cms.InputTag("generator","","SIM")

#                  vertexInput       = cms.InputTag("offlinePrimaryVertices"),
#                  electronInput     = cms.InputTag("patElectronsPFlow"),
#                  muonInput         = cms.InputTag("patMuonsPFlow"),
#                  tauInput          = cms.InputTag("patTausPFlow"),
#                  jetInput          = cms.InputTag("patJetsPFlow"),
#                  metInput          = cms.InputTag("patMETsPFlow"),
#                  rhoInput          = cms.InputTag("fixedGridRhoAll"),
#                  genParticlesInput = cms.InputTag("genParticles")
)

#process.TFileService = cms.Service("TFileService",
#                                   fileName = cms.string("output.root")
#)

process.p = cms.Path(process.SimTree)
