import FWCore.ParameterSet.Config as cms

from FWCore.ParameterSet.VarParsing import VarParsing
import os

process = cms.Process("SimTree")

options = VarParsing('analysis')
options.register('runOnRECO',False,VarParsing.multiplicity.singleton,VarParsing.varType.bool,'Run on GEN-SIM-RECO')
options.parseArguments()

process.load("FWCore.MessageService.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000

process.load("SimGeneral.HepPDTESSource.pythiapdt_cfi")

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#    "/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/00972E0A-44A5-E511-BF0E-0CC47A4C8ECA.root"
#"/store/mc/RunIISummer15GS/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM/MCRUN2_71_V1-v1/10000/3273739A-7D79-E511-8EDE-50E549336049.root"
#"file:gensim-CE70AD2F-6D7B-E511-8417-18A905704650.root"
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/1AFAB25F-D9A4-E511-8190-0CC47A4D7636.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/1C0ED168-FBA4-E511-90E2-0026189438ED.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/1CC6EA79-D7A4-E511-8A13-0CC47A7452D0.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/068C5338-1EA5-E511-83B3-0025905A60F4.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/063D712D-0FA5-E511-96EC-0CC47A4D7614.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/063B5DE3-D8A4-E511-82D3-002618943922.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/04E8E74A-E6A4-E511-8347-0025905B858E.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/04C553EA-07A5-E511-9BFA-002618943984.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/04AF725D-E1A4-E511-80D0-0CC47A4C8E96.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/0462AA17-C9A4-E511-9C56-008CFA111170.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/0446F640-4CA5-E511-9989-00266CFFA240.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/FC9768A1-0CA5-E511-905B-008CFA0F50F4.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/FC8809B5-07A5-E511-AEEF-002618943973.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/FC833800-CAA4-E511-A0E2-008CFA197404.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/FC0BB9D9-DDA4-E511-BC62-0CC47A4D765A.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/FAAC1093-D3A4-E511-A84C-0CC47A4C8E2E.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/FA78BDAC-FAA4-E511-8792-008CFA197410.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/FA67D53D-E0A4-E511-A0D5-0CC47A4D7628.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/FA15ABA4-DCA4-E511-8D67-0CC47A4C8EE8.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/D8559E51-C4A4-E511-99C1-008CFA197CA8.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/44CC316C-4CA5-E511-8927-0CC47A78A456.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/425DA724-49A5-E511-9F51-008CFA197DB8.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/3EA840C5-4AA5-E511-BA6A-0CC47A4D76AC.root",
#"dcap://maite.iihe.ac.be/pnfs/iihe/cms/store/user/kskovpen/BTV/GENSIMRECODEBUG/02D7CFB1-09A5-E511-A019-0CC47A7452D0.root"

"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/00972E0A-44A5-E511-BF0E-0CC47A4C8ECA.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/00C57F77-43A5-E511-9B20-00261894386F.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/00DD06AB-4DA5-E511-9AF4-0025905B8610.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/022D407D-45A5-E511-BDA5-008CFA1111D0.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/040BD09A-49A5-E511-B8E4-0025905B85D6.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/06184DA0-49A5-E511-A807-0CC47A4D76A2.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/08219A86-47A5-E511-B395-008CFA197C10.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/08815CB4-47A5-E511-BD41-008CFA1111AC.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/08B13C67-48A5-E511-B505-0CC47A4D75F2.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/08B59555-4DA5-E511-987E-008CFA197918.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/08C933E9-4DA5-E511-BC95-0025905B85EE.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/0AA25362-48A5-E511-9069-0CC47A4D7604.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/0EC1E1D3-48A5-E511-AE95-0025905A6138.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/1086C330-4DA5-E511-9440-008CFA197D74.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/1207E270-43A5-E511-92BC-0CC47A4C8E1C.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/12B5C772-4EA5-E511-BE8C-008CFA110C5C.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/12BDC91E-DEA5-E511-A385-003048FFD7D4.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/1446B818-48A5-E511-A04F-0CC47A4C8E22.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/1617BF8A-4CA5-E511-8699-008CFA1979AC.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/164E1B35-46A5-E511-8E97-0CC47A78A4A0.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/16654FF1-48A5-E511-980C-0CC47A78A3F8.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/169DCCAE-4EA5-E511-9BCD-008CFA11123C.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/18E42D0A-49A5-E511-9AA6-0CC47A4C8E38.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/1C06310E-4EA5-E511-AF68-008CFA197D0C.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/1C0CB8BC-49A5-E511-A3D3-0CC47A4C8EE2.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/1C3F0A2E-49A5-E511-915D-0CC47A4C8ECE.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/1ED852A4-49A5-E511-8B26-0025905A6076.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2092FB1D-4DA5-E511-949A-008CFA1979EC.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2206C657-4BA5-E511-B13C-008CFA1974D8.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/223C98F3-42A5-E511-BBB1-0026189438AC.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/22EED97A-40A5-E511-90DC-0CC47A4D76C6.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/22F2647A-4DA5-E511-80FD-0025905A6122.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2657260C-4BA5-E511-A4A5-00259055079C.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2831D963-46A5-E511-8E56-0CC47A4D763C.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/286C7210-DEA5-E511-AA9F-0CC47A4D76D6.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/28A286B0-44A5-E511-8C24-0CC47A4D763C.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2A050916-DEA5-E511-BBA5-0025905822B6.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2A10989B-46A5-E511-AC25-0026189438EA.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2C0B6476-52A5-E511-85C0-008CFA197BDC.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2C340B57-47A5-E511-BD02-008CFA197D74.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2E6B0EBF-4DA5-E511-8D5F-0025905A611E.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/2E8E458E-4CA5-E511-B4BB-008CFA197D74.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/321BA924-49A5-E511-B139-0CC47A4D75F4.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/3245CF51-49A5-E511-819B-008CFA1111D0.root",
"/store/mc/RunIIFall15DR76/QCD_Pt_300to470_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/40000/364B1AA4-4CA5-E511-AF95-008CFA110C5C.root"

#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/18ED4E15-94A7-E511-8EBB-00A0D1EE8A70.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/18C98D13-94A7-E511-A943-008CFA197AA0.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/18A6E48F-A2A7-E511-A5A5-1CC1DE18D026.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/16FFBD0A-8EA7-E511-B6D5-0025904C66F0.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/16C57830-A1A7-E511-BEC7-008CFA197460.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/16817141-95A7-E511-AB81-0025904CDDFA.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/161F3341-9FA7-E511-AE25-002590DE6E5E.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/143CC422-94A7-E511-BCF8-001EC9AF02D2.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/12A8477C-93A7-E511-B990-0025904CDDEC.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/122D0037-96A7-E511-BEE9-0025904C63F8.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/122A8017-9DA7-E511-A17A-001EC9B218D0.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/10F8404B-96A7-E511-B7BB-3417EBE6FFFD.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/06559C4D-95A7-E511-8D31-0025905C42FE.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/06A2218D-A1A7-E511-A4F7-842B2B7680DF.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/088117AB-9DA7-E511-9A2D-008CFA1113DC.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/08A33997-9AA7-E511-BDC0-0025904C63FA.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/0AE8F1E7-90A7-E511-82C4-0025905C95FA.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/0AF654A7-A1A7-E511-BFB7-008CFA1979A0.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/0C8F9713-9EA7-E511-9728-008CFA197DA8.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/0E6C9D5E-A0A7-E511-8CF6-001EC9AF17F9.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/0EFAFFBD-8CA7-E511-B0E7-0025904C66F0.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/102EB4E7-96A7-E511-B1FF-0025905C2CBC.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/10372227-9FA7-E511-A766-008CFA197C80.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/106E82CD-98A7-E511-AEE9-0025904C67B4.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/10856906-99A7-E511-A639-001EC9AF2573.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FE8273A1-76A7-E511-AE21-008CFA1979EC.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FEBE3466-6EA7-E511-9D6D-0CC47A0107D0.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FEC4DA46-7DA7-E511-A7F1-0025905C9742.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FECC0B44-7EA7-E511-B4AE-008CFA197BC4.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/000EB3B9-F5A7-E511-9B37-0025904C6622.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/0022C24D-A3A7-E511-BF25-002590DD7E50.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/00403318-90A7-E511-AA87-0025904C6374.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/009F26EC-9BA7-E511-960F-008CFA165F48.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/00A76B5A-95A7-E511-963D-008CFA197918.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/02E43CC9-98A7-E511-84EC-0025905C96E8.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/0433D5F7-9EA7-E511-AA95-008CFA197C10.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/04375743-FFA7-E511-A71F-0025904B7C42.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/043C908E-94A7-E511-B62B-0025904C641E.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/04AF6F58-FFA7-E511-BBBC-0025905C4262.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60001/04C148D4-A2A7-E511-882E-008CFA197DB8.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/F8BF3540-7AA7-E511-B39F-002590DE3AC0.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/F8E4CECB-7BA7-E511-8261-001E67397CAB.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FA1ED93A-8FA7-E511-BEC6-3417EBE7047A.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FA7F4E58-69A7-E511-A146-003048947BBB.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FAA1CF58-7AA7-E511-BE65-0025905C42B6.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FAEE1527-7DA7-E511-916E-008CFA197990.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FAF3FBF1-7BA7-E511-AAE9-008CFA1974CC.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FC76AA41-76A7-E511-8F9F-0025904CF75A.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FC7ABA03-73A7-E511-98B2-0025905C2CE8.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FCA0A1E2-72A7-E511-945F-008CFA197B48.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FCD4AA52-75A7-E511-A566-0025905C3D96.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FE0D8AF7-88A7-E511-9A8A-D4AE5269F656.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FE67460B-87A7-E511-995F-D4AE5269F919.root",
#"/store/mc/RunIIFall15DR76/QCD_Pt_30to50_TuneCUETP8M1_13TeV_pythia8/GEN-SIM-RECODEBUG/PU25nsData2015v1Recodebug_76X_mcRun2_asymptotic_v12-v1/60000/FE713841-8CA7-E511-9C47-D8D385FF33B9.root"
   )
)

#process.load("Geometry.CMSCommonData.cmsIdealGeometryXML_cfi")
process.load("Geometry.MuonCommonData.muonIdealGeometryXML_cfi")
process.load("Geometry.RPCGeometry.rpcGeometry_cfi")
process.load("Geometry.CSCGeometry.cscGeometry_cfi")
process.load("Geometry.DTGeometry.dtGeometry_cfi")
process.load("Geometry.MuonNumbering.muonNumberingInitialization_cfi")

process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff")
from Configuration.AlCa.GlobalTag import GlobalTag
process.GlobalTag.globaltag = "80X_mcRun2_asymptotic_2016_v3"

process.TFileService = cms.Service("TFileService", fileName = cms.string("output.root"))

process.options = cms.untracked.PSet(
     wantSummary = cms.untracked.bool(False),
     allowUnscheduled = cms.untracked.bool(True)
)

process.SimTree = cms.EDAnalyzer('SimG4Filter',

                   runOnRECO = cms.bool(options.runOnRECO),
                   simTracksInput = cms.InputTag("g4SimHits","","SIM"),
                   simHitsMuonRPCInput = cms.InputTag("g4SimHits","MuonRPCHits","SIM"),
                   simHitsMuonCSCInput = cms.InputTag("g4SimHits","MuonCSCHits","SIM"),
                   simHitsMuonDTInput = cms.InputTag("g4SimHits","MuonDTHits","SIM"),
                   RPCDigiSimLinkInput = cms.InputTag("simMuonRPCDigis","RPCDigiSimLink","HLT"),
                   CSCStripDigiSimLinkInput = cms.InputTag("simMuonCSCDigis","MuonCSCStripDigiSimLinks","HLT"),
                   CSCWireDigiSimLinkInput = cms.InputTag("simMuonCSCDigis","MuonCSCWireDigiSimLinks","HLT"),
                   DTDigiSimLinkInput = cms.InputTag("simMuonDTDigis","","HLT"),
                   recoMuonInput = cms.InputTag("muons","","RECO"),
#                   genParticlesInput = cms.InputTag("genParticles","","SIM")
                   genParticlesInput = cms.InputTag("genParticles","","HLT")
)
    
process.p = cms.Path(process.SimTree)
