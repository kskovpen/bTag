from WMCore.Configuration import Configuration
config = Configuration()
config.section_('General')
config.General.transferOutputs = True
config.General.requestName = 'REQUESTNAME'
config.section_('JobType')
config.JobType.psetName = '../run_cfg.py'
config.JobType.pluginName = 'Analysis'
config.JobType.inputFiles = []
config.JobType.disableAutomaticOutputCollection = True
config.JobType.outputFiles = ['output.root']
config.JobType.pyCfgParams = ['runOnRECO=0']
config.section_('Data')
config.Data.totalUnits = -1
#config.Data.totalUnits = 4
config.Data.unitsPerJob = 5
#config.Data.unitsPerJob = 30
config.Data.splitting = 'FileBased'
#config.Data.splitting = 'LumiBased'
config.Data.publication = False
config.Data.ignoreLocality = True
config.Data.inputDataset = 'INPUTDATASET'
#config.Data.inputDBS = 'phys03'
config.Data.outputDatasetTag = 'PUBLISHDATANAME'
config.Data.publishDBS = 'https://cmsweb.cern.ch/dbs/prod/phys03/DBSWriter'
config.Data.outLFNDirBase = 'OUTLFN'
#config.Data.lumiMask = 'GRL/Cert_246908-260627_13TeV_PromptReco_Collisions15_25ns_JSON_v2.txt'
config.section_('User')
config.section_('Site')
config.Site.storageSite = 'T2_FR_IPHC'
#config.Site.whitelist = ['T2_FR_IPHC']
