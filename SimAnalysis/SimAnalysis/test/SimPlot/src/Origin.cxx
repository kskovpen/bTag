#include "../include/Origin.h"

SIMPLOT::Origin::Origin()
{
}

SIMPLOT::Origin::~Origin()
{
}

void SIMPLOT::Origin::init()
{
   std::string foutName = std::string(foutname)+".root";

   _fout = new TFile(foutName.c_str(),"RECREATE");

   _fout->cd();

   h_mu1_id = new TH1F("h_mu1_id","h_mu1_id",7,0,7);
   h_mu1_id->Sumw2();
   h_mu2_id = new TH1F("h_mu2_id","h_mu2_id",7,0,7);
   h_mu2_id->Sumw2();

   h_mu1_partonId = new TH1F("h_mu1_partonId","h_mu1_partonId",4,0,4);
   h_mu1_partonId->Sumw2();
   h_mu2_partonId = new TH1F("h_mu2_partonId","h_mu2_partonId",4,0,4);
   h_mu2_partonId->Sumw2();

   h_muRec1_id = new TH1F("h_muRec1_id","h_muRec1_id",3,0,3);
   h_muRec1_id->Sumw2();
   h_muRec2_id = new TH1F("h_muRec2_id","h_muRec2_id",3,0,3);
   h_muRec2_id->Sumw2();
   
   h_mu1_pt = new TH1F("h_mu1_pt","h_mu1_pt",30,0,50);
   h_mu1_pt->Sumw2();
   h_mu2_pt = new TH1F("h_mu2_pt","h_mu2_pt",30,0,50);
   h_mu2_pt->Sumw2();

   h_muAll1_pt = new TH1F("h_muAll1_pt","h_muAll1_pt",30,0,50);
   h_muAll1_pt->Sumw2();
   h_muAll2_pt = new TH1F("h_muAll2_pt","h_muAll2_pt",30,0,50);
   h_muAll2_pt->Sumw2();
   
   h_mu1_rpv = new TH1F("h_mu1_rpv","h_mu1_rpv",30,0,650);
   h_mu1_rpv->Sumw2();
   h_mu2_rpv = new TH1F("h_mu2_rpv","h_mu2_rpv",30,0,650);
   h_mu2_rpv->Sumw2();
   
   h_muSim1_pt = new TH1F("h_muSim1_pt","h_muSim1_pt",30,0,50);
   h_muSim1_pt->Sumw2();
   h_muSim2_pt = new TH1F("h_muSim2_pt","h_muSim2_pt",30,0,50);
   h_muSim2_pt->Sumw2();

   h_muRec1_pt = new TH1F("h_muRec1_pt","h_muRec1_pt",30,0,50);
   h_muRec1_pt->Sumw2();
   h_muRec2_pt = new TH1F("h_muRec2_pt","h_muRec2_pt",30,0,50);
   h_muRec2_pt->Sumw2();

   h_muAllBD1_pt = new TH1F("h_muAllBD1_pt","h_muAllBD1_pt",30,0,50);
   h_muAllBD1_pt->Sumw2();
   h_muAllBD2_pt = new TH1F("h_muAllBD2_pt","h_muAllBD2_pt",30,0,50);
   h_muAllBD2_pt->Sumw2();

   h_muAllOTHER1_pt = new TH1F("h_muAllOTHER1_pt","h_muAllOTHER1_pt",30,0,50);
   h_muAllOTHER1_pt->Sumw2();
   h_muGenOTHER1_pt = new TH1F("h_muGenOTHER1_pt","h_muGenOTHER1_pt",30,0,50);
   h_muGenOTHER1_pt->Sumw2();
   h_muSimOTHER1_pt = new TH1F("h_muSimOTHER1_pt","h_muSimOTHER1_pt",30,0,50);
   h_muSimOTHER1_pt->Sumw2();

   h_muAllOTHER2_pt = new TH1F("h_muAllOTHER2_pt","h_muAllOTHER2_pt",30,0,50);
   h_muAllOTHER2_pt->Sumw2();
   h_muGenOTHER2_pt = new TH1F("h_muGenOTHER2_pt","h_muGenOTHER2_pt",30,0,50);
   h_muGenOTHER2_pt->Sumw2();
   h_muSimOTHER2_pt = new TH1F("h_muSimOTHER2_pt","h_muSimOTHER2_pt",30,0,50);
   h_muSimOTHER2_pt->Sumw2();
   
   h_muAllPK1_pt = new TH1F("h_muAllPK1_pt","h_muAllPK1_pt",30,0,50);
   h_muAllPK1_pt->Sumw2();
   h_muAllPK2_pt = new TH1F("h_muAllPK2_pt","h_muAllPK2_pt",30,0,50);
   h_muAllPK2_pt->Sumw2();

   h_muAllBDMatchedRec1_pt = new TH1F("h_muAllBDMatchedRec1_pt","h_muAllBDMatchedRec1_pt",30,0,50);
   h_muAllBDMatchedRec1_pt->Sumw2();
   h_muAllBDMatchedRec2_pt = new TH1F("h_muAllBDMatchedRec2_pt","h_muAllBDMatchedRec2_pt",30,0,50);
   h_muAllBDMatchedRec2_pt->Sumw2();

   h_muAllPKMatchedRec1_pt = new TH1F("h_muAllPKMatchedRec1_pt","h_muAllPKMatchedRec1_pt",30,0,50);
   h_muAllPKMatchedRec1_pt->Sumw2();
   h_muAllPKMatchedRec2_pt = new TH1F("h_muAllPKMatchedRec2_pt","h_muAllPKMatchedRec2_pt",30,0,50);
   h_muAllPKMatchedRec2_pt->Sumw2();
   
   h_muGenMatchedRec1_pt = new TH1F("h_muGenMatchedRec1_pt","h_muGenMatchedRec1_pt",30,0,50);
   h_muGenMatchedRec1_pt->Sumw2();
   h_muGenMatchedRec2_pt = new TH1F("h_muGenMatchedRec2_pt","h_muGenMatchedRec2_pt",30,0,50);
   h_muGenMatchedRec2_pt->Sumw2();

   h_muSimMatchedRec1_pt = new TH1F("h_muSimMatchedRec1_pt","h_muSimMatchedRec1_pt",30,0,50);
   h_muSimMatchedRec1_pt->Sumw2();
   h_muSimMatchedRec2_pt = new TH1F("h_muSimMatchedRec2_pt","h_muSimMatchedRec2_pt",30,0,50);
   h_muSimMatchedRec2_pt->Sumw2();

   h_muAllMatchedRec1_pt = new TH1F("h_muAllMatchedRec1_pt","h_muAllMatchedRec1_pt",30,0,50);
   h_muAllMatchedRec1_pt->Sumw2();
   h_muAllMatchedRec2_pt = new TH1F("h_muAllMatchedRec2_pt","h_muAllMatchedRec2_pt",30,0,50);
   h_muAllMatchedRec2_pt->Sumw2();
   
   h_muRecClosestMuGen1_dr = new TH1F("h_muRecClosestMuGen1_dr","h_muRecClosestMuGen1_dr",30,0,1);
   h_muRecClosestMuGen1_dr->Sumw2();
   h_muRecClosestMuGen2_dr = new TH1F("h_muRecClosestMuGen2_dr","h_muRecClosestMuGen2_dr",30,0,1);
   h_muRecClosestMuGen2_dr->Sumw2();

   h_muRecClosestMuSim1_dr = new TH1F("h_muRecClosestMuSim1_dr","h_muRecClosestMuSim1_dr",30,0,5);
   h_muRecClosestMuSim1_dr->Sumw2();
   h_muRecClosestMuSim2_dr = new TH1F("h_muRecClosestMuSim2_dr","h_muRecClosestMuSim2_dr",30,0,5);
   h_muRecClosestMuSim2_dr->Sumw2();

   h_muGenClosestMuRec1_dr = new TH1F("h_muGenClosestMuRec1_dr","h_muGenClosestMuRec1_dr",30,0,5);
   h_muGenClosestMuRec1_dr->Sumw2();
   h_muGenClosestMuRec2_dr = new TH1F("h_muGenClosestMuRec2_dr","h_muGenClosestMuRec2_dr",30,0,5);
   h_muGenClosestMuRec2_dr->Sumw2();

   h_muSimClosestMuRec1_dr = new TH1F("h_muSimClosestMuRec1_dr","h_muSimClosestMuRec1_dr",30,0,5);
   h_muSimClosestMuRec1_dr->Sumw2();
   h_muSimClosestMuRec2_dr = new TH1F("h_muSimClosestMuRec2_dr","h_muSimClosestMuRec2_dr",30,0,5);
   h_muSimClosestMuRec2_dr->Sumw2();
   
   h_mu1_RhoPhi = new TH2F("h_mu1_RhoPhi","h_mu1_RhoPhi",100,-250.,250.,100,-250.,250.);
   h_mu1_RhoPhi->Sumw2();
   h_mu2_RhoPhi = new TH2F("h_mu2_RhoPhi","h_mu2_RhoPhi",100,-250.,250.,100,-250.,250.);
   h_mu2_RhoPhi->Sumw2();

   h_muSim1_RhoPhi = new TH2F("h_muSim1_RhoPhi","h_muSim1_RhoPhi",100,-250.,250.,100,-250.,250.);
   h_muSim1_RhoPhi->Sumw2();
   h_muSim2_RhoPhi = new TH2F("h_muSim2_RhoPhi","h_muSim2_RhoPhi",100,-250.,250.,100,-250.,250.);
   h_muSim2_RhoPhi->Sumw2();

   h_muSim1_rpv = new TH1F("h_muSim1_rpv","h_muSim1_rpv",30,0,650);
   h_muSim1_rpv->Sumw2();
   h_muSim2_rpv = new TH1F("h_muSim2_rpv","h_muSim2_rpv",30,0,650);
   h_muSim2_rpv->Sumw2();

   h_muJet1_pt = new TH1F("h_muJet1_pt","h_muJet1_pt",30,0,300);
   h_muJet1_pt->Sumw2();
   h_muJet2_pt = new TH1F("h_muJet2_pt","h_muJet2_pt",30,0,300);
   h_muJet2_pt->Sumw2();

   h_muBJet1_pt = new TH1F("h_muBJet1_pt","h_muBJet1_pt",30,0,300);
   h_muBJet1_pt->Sumw2();
   h_muBJet2_pt = new TH1F("h_muBJet2_pt","h_muBJet2_pt",30,0,300);
   h_muBJet2_pt->Sumw2();

   h_muCJet1_pt = new TH1F("h_muCJet1_pt","h_muCJet1_pt",30,0,300);
   h_muCJet1_pt->Sumw2();
   h_muCJet2_pt = new TH1F("h_muCJet2_pt","h_muCJet2_pt",30,0,300);
   h_muCJet2_pt->Sumw2();

   h_muLJet1_pt = new TH1F("h_muLJet1_pt","h_muLJet1_pt",30,0,300);
   h_muLJet1_pt->Sumw2();
   h_muLJet2_pt = new TH1F("h_muLJet2_pt","h_muLJet2_pt",30,0,300);
   h_muLJet2_pt->Sumw2();

   h_muPK1_gensim = new TH1F("h_muPK1_gensim","h_muPK1_gensim",2,0,2);
   h_muPK1_gensim->Sumw2();
   h_muPK2_gensim = new TH1F("h_muPK2_gensim","h_muPK2_gensim",3,0,3);
   h_muPK2_gensim->Sumw2();
   h_muPK21_gensim = new TH1F("h_muPK21_gensim","h_muPK21_gensim",2,0,2);
   h_muPK21_gensim->Sumw2();

   h_muNOTPK2_gensim = new TH1F("h_muNOTPK2_gensim","h_muNOTPK2_gensim",3,0,3);
   h_muNOTPK2_gensim->Sumw2();
   
   h_muOTHER1_gensim = new TH1F("h_muOTHER1_gensim","h_muOTHER1_gensim",2,0,2);
   h_muOTHER1_gensim->Sumw2();
   h_muOTHER2_gensim = new TH1F("h_muOTHER2_gensim","h_muOTHER2_gensim",3,0,3);
   h_muOTHER2_gensim->Sumw2();
   h_muOTHER21_gensim = new TH1F("h_muOTHER21_gensim","h_muOTHER21_gensim",2,0,2);
   h_muOTHER21_gensim->Sumw2();
   
   h_muFake_pt = new TH1F("h_muFake_pt","h_muFake_pt",30,0,50);
   h_muFake_pt->Sumw2();

   h_muReal_pt = new TH1F("h_muReal_pt","h_muReal_pt",30,0,50);
   h_muReal_pt->Sumw2();

   h_muVal1_pt = new TH1F("h_muVal1_pt","h_muVal1_pt",30,0,50);
   h_muVal1_pt->Sumw2();
   h_muVal2_pt = new TH1F("h_muVal2_pt","h_muVal2_pt",30,0,50);
   h_muVal2_pt->Sumw2();
   h_muVal3_pt = new TH1F("h_muVal3_pt","h_muVal3_pt",30,0,50);
   h_muVal3_pt->Sumw2();

   h_muValUncor1_pt = new TH1F("h_muValUncor1_pt","h_muValUncor1_pt",30,0,50);
   h_muValUncor1_pt->Sumw2();
   h_muValUncor2_pt = new TH1F("h_muValUncor2_pt","h_muValUncor2_pt",30,0,50);
   h_muValUncor2_pt->Sumw2();
   h_muValUncor3_pt = new TH1F("h_muValUncor3_pt","h_muValUncor3_pt",30,0,50);
   h_muValUncor3_pt->Sumw2();

   h_muRecVal1_pt = new TH1F("h_muRecVal1_pt","h_muRecVal1_pt",30,0,50);
   h_muRecVal1_pt->Sumw2();
   h_muRecVal2_pt = new TH1F("h_muRecVal2_pt","h_muRecVal2_pt",30,0,50);
   h_muRecVal2_pt->Sumw2();
   h_muRecVal3_pt = new TH1F("h_muRecVal3_pt","h_muRecVal3_pt",30,0,50);
   h_muRecVal3_pt->Sumw2();

   h_muRecValUncor1_pt = new TH1F("h_muRecValUncor1_pt","h_muRecValUncor1_pt",30,0,50);
   h_muRecValUncor1_pt->Sumw2();
   h_muRecValUncor2_pt = new TH1F("h_muRecValUncor2_pt","h_muRecValUncor2_pt",30,0,50);
   h_muRecValUncor2_pt->Sumw2();
   h_muRecValUncor3_pt = new TH1F("h_muRecValUncor3_pt","h_muRecValUncor3_pt",30,0,50);
   h_muRecValUncor3_pt->Sumw2();

   h_muPythiaGeant_N = new TH1F("h_muPythiaGeant_N","h_muPythiaGeant_N",20,0,20);
   h_muPythiaGeant_N->Sumw2();

   h_muGeant_N = new TH1F("h_muGeant_N","h_muGeant_N",5,0,5);
   h_muGeant_N->Sumw2();
   
   // muon reco parameters
   
   h_muFake_trackerLayersWithMeasurement = new TH1F("h_muFake_trackerLayersWithMeasurement","h_muFake_trackerLayersWithMeasurement",30,0,30);
   h_muFake_numberOfValidMuonHits = new TH1F("h_muFake_numberOfValidMuonHits","h_muFake_numberOfValidMuonHits",100,0,100);
   h_muFake_numberOfMatches = new TH1F("h_muFake_numberOfMatches","h_muFake_numberOfMatches",10,0,10);
   h_muFake_numberOfMatchedStations = new TH1F("h_muFake_numberOfMatchedStations","h_muFake_numberOfMatchedStations",10,0,10);
   h_muFake_numberOfValidHits = new TH1F("h_muFake_numberOfValidHits","h_muFake_numberOfValidHits",40,0,40);
   h_muFake_numberOfValidPixelHits = new TH1F("h_muFake_numberOfValidPixelHits","h_muFake_numberOfValidPixelHits",10,0,10);
   h_muFake_numberOfHits = new TH1F("h_muFake_numberOfHits","h_muFake_numberOfHits",5,0,5);
   h_muFake_normalizedChi2GlobalTrack = new TH1F("h_muFake_normalizedChi2GlobalTrack","h_muFake_normalizedChi2GlobalTrack",10,0,10);
   h_muFake_normalizedChi2InnerTrack = new TH1F("h_muFake_normalizedChi2InnerTrack","h_muFake_normalizedChi2InnerTrack",10,0,10);
   
   h_muReal_trackerLayersWithMeasurement = new TH1F("h_muReal_trackerLayersWithMeasurement","h_muReal_trackerLayersWithMeasurement",30,0,30);
   h_muReal_numberOfValidMuonHits = new TH1F("h_muReal_numberOfValidMuonHits","h_muReal_numberOfValidMuonHits",100,0,100);
   h_muReal_numberOfMatches = new TH1F("h_muReal_numberOfMatches","h_muReal_numberOfMatches",10,0,10);
   h_muReal_numberOfMatchedStations = new TH1F("h_muReal_numberOfMatchedStations","h_muReal_numberOfMatchedStations",10,0,10);
   h_muReal_numberOfValidHits = new TH1F("h_muReal_numberOfValidHits","h_muReal_numberOfValidHits",40,0,40);
   h_muReal_numberOfValidPixelHits = new TH1F("h_muReal_numberOfValidPixelHits","h_muReal_numberOfValidPixelHits",10,0,10);
   h_muReal_numberOfHits = new TH1F("h_muReal_numberOfHits","h_muReal_numberOfHits",5,0,5);
   h_muReal_normalizedChi2GlobalTrack = new TH1F("h_muReal_normalizedChi2GlobalTrack","h_muReal_normalizedChi2GlobalTrack",10,0,10);
   h_muReal_normalizedChi2InnerTrack = new TH1F("h_muReal_normalizedChi2InnerTrack","h_muReal_normalizedChi2InnerTrack",10,0,10);
}

void SIMPLOT::Origin::fill()
{
   std::vector<int> *momId = ntP->momId;
   std::vector<float> *muPt = ntP->muPt;
   std::vector<float> *muEta = ntP->muEta;
   std::vector<float> *muPhi = ntP->muPhi;
   std::vector<int> *muStatus = ntP->muStatus;
   std::vector<int> *partonId = ntP->partonId;
   std::vector<float> *muPosX = ntP->muPosX;
   std::vector<float> *muPosY = ntP->muPosY;
   std::vector<float> *muPosZ = ntP->muPosZ;
   std::vector<float> *muRpv = ntP->muRpv;

   std::vector<float> *muSimPosX = ntP->muSimPosX;
   std::vector<float> *muSimPosY = ntP->muSimPosY;
   std::vector<float> *muSimPosZ = ntP->muSimPosZ;
   std::vector<float> *muSimRpv = ntP->muSimRpv;
   std::vector<float> *muSimPt = ntP->muSimPt;
   std::vector<float> *muSimEta = ntP->muSimEta;
   std::vector<float> *muSimPhi = ntP->muSimPhi;
   std::vector<int> *muSimMomId = ntP->muSimMomId;
/*   
   std::vector<float> *muRecPt = ntP->patmuonPt;
   std::vector<float> *muRecEta = ntP->patmuonEta;
   std::vector<float> *muRecPhi = ntP->patmuonPhi;
   std::vector<int> *muRecNumberOfValidMuonHits = ntP->patmuonNumberOfValidMuonHits;
   std::vector<int> *muRecNumberOfMatches = ntP->patmuonNumberOfMatches;
   std::vector<int> *muRecNumberOfMatchedStations = ntP->patmuonNumberOfMatchedStations;
   std::vector<int> *muRecTrackerLayersWithMeasurement = ntP->patmuonTrackerLayersWithMeasurement;
   std::vector<int> *muRecNumberOfValidHits = ntP->patmuonNumberOfValidHits;
   std::vector<int> *muRecNumberOfValidPixelHits = ntP->patmuonNumberOfValidPixelHits;
   std::vector<int> *muRecNumberOfHits = ntP->patmuonNumberOfHits;
   std::vector<float> *muRecNormalizedChi2GlobalTrack = ntP->patmuonNormalizedChi2GlobalTrack;
   std::vector<float> *muRecNormalizedChi2InnerTrack = ntP->patmuonNormalizedChi2InnerTrack;
   std::vector<bool> *muRecIsPFMuon = ntP->patmuonIsPFMuon;
   std::vector<bool> *muRecIsGlobalMuon = ntP->patmuonIsGlobalMuon;
*/
   std::vector<float> *muRecPt = ntP->recomuonPt;
   std::vector<float> *muRecEta = ntP->recomuonEta;
   std::vector<float> *muRecPhi = ntP->recomuonPhi;
   std::vector<int> *muRecNumberOfValidMuonHits = ntP->recomuonNumberOfValidMuonHits;
   std::vector<int> *muRecNumberOfMatches = ntP->recomuonNumberOfMatches;
   std::vector<int> *muRecNumberOfMatchedStations = ntP->recomuonNumberOfMatchedStations;
   std::vector<int> *muRecTrackerLayersWithMeasurement = ntP->recomuonTrackerLayersWithMeasurement;
   std::vector<int> *muRecNumberOfValidHits = ntP->recomuonNumberOfValidHits;
   std::vector<int> *muRecNumberOfValidPixelHits = ntP->recomuonNumberOfValidPixelHits;
   std::vector<int> *muRecNumberOfHits = ntP->recomuonNumberOfHits;
   std::vector<float> *muRecNormalizedChi2GlobalTrack = ntP->recomuonNormalizedChi2GlobalTrack;
   std::vector<float> *muRecNormalizedChi2InnerTrack = ntP->recomuonNormalizedChi2InnerTrack;
   std::vector<bool> *muRecIsPFMuon = ntP->recomuonIsPFMuon;
   std::vector<bool> *muRecIsGlobalMuon = ntP->recomuonIsGlobalMuon;
   
   std::vector<float> *patjetPt = ntP->patjetPt;
   std::vector<float> *patjetEta = ntP->patjetEta;
   std::vector<float> *patjetPhi = ntP->patjetPhi;
   std::vector<int> *patjetPartonFlavour = ntP->patjetPartonFlavour;
   std::vector<int> *patjetHadronFlavour = ntP->patjetHadronFlavour;
   
   float w = xsec*eff/noe;
   
   float ptCut = 5.;
   
   int nMu = momId->size();
   int nMuSim = muSimPt->size();
   int nMuRec = muRecPt->size();
   int nJet = patjetPt->size();

   std::vector<int> muonGen;
   std::vector<int> muonSim;
   std::vector<int> muonRec;
   
   for(int im=0;im<nMu;im++)
     {
	int pId = partonId->at(im);
	int iBinParton = partonIdLabel(pId);
//	if( iBinParton != 1 && iBinParton != 0 ) continue;
//	if( iBinParton != 3 ) continue;
	float muonPt = muPt->at(im);
	float muonEta = muEta->at(im);
	int muonStatus = muStatus->at(im);
	if( muonStatus != 1 ) continue;
	if( muonPt < ptCut || fabs(muonEta) > 2.4 ) continue;	
	muonGen.push_back(im);
     }

   for(int im=0;im<nMuSim;im++)
     {
	float muonPt = muSimPt->at(im);
	float muonEta = muSimEta->at(im);
//	int momId = muSimMomId->at(im);
//	int iBin = pdgIdLabel(momId);
//	if( iBin == 0 || iBin == 1 ) continue;
	if( muonPt < ptCut || fabs(muonEta) > 2.4 ) continue;
	muonSim.push_back(im);
     }

   for(int im=0;im<nMuRec;im++)
     {
	float muonPt = muRecPt->at(im);
	float muonEta = muRecEta->at(im);
//	if( muonPt < ptCut || fabs(muonEta) > 2.4 ) continue;
	muonRec.push_back(im);
     }

   int nMuSel = muonGen.size();
   int nMuSimSel = muonSim.size();
   int nMuRecSel = muonRec.size();
   
   if( nMuSel >= 1 ) nSel++;
   
   for(int im=0;im<nMuSel;im++)
     {
	int idxGen = muonGen[im];
	  
	float muonPt = muPt->at(idxGen);
	int muId = momId->at(idxGen);
	int pId = partonId->at(idxGen);

	float muonPosX = muPosX->at(idxGen);
	float muonPosY = muPosY->at(idxGen);
	float muonPosZ = muPosZ->at(idxGen);
	float muonRpv = muRpv->at(idxGen);
	
	int iBin = pdgIdLabel(muId);
	int iBinParton = partonIdLabel(pId);
			
	if( nMuSel >= 1 )
	  {
	     h_mu1_id->Fill(iBin,w);
	     h_mu1_pt->Fill(muonPt,w);
	     h_muAll1_pt->Fill(muonPt,w);
	     h_mu1_partonId->Fill(iBinParton,w);
	     h_mu1_rpv->Fill(muonRpv,w);
	     h_mu1_RhoPhi->Fill(muonPosX,muonPosY,w);	     
	  }
	if( nMuSel >= 2 )
	  {
	     h_mu2_id->Fill(iBin,w);
	     h_mu2_pt->Fill(muonPt,w);
	     h_muAll2_pt->Fill(muonPt,w);
	     h_mu2_partonId->Fill(iBinParton,w);
	     h_mu2_rpv->Fill(muonRpv,w);
	     h_mu2_RhoPhi->Fill(muonPosX,muonPosY,w);
	  }
     }   

   for(int im=0;im<nMuSimSel;im++)
     {
	int idxSim = muonSim[im];
	  
	float muonPt = muSimPt->at(idxSim);

	float muonPosX = muSimPosX->at(idxSim);
	float muonPosY = muSimPosY->at(idxSim);
	float muonPosZ = muSimPosZ->at(idxSim);
	float muonRpv = muSimRpv->at(idxSim);
	
	if( nMuSimSel >= 1 )
	  {
	     h_muSim1_pt->Fill(muonPt,w);
	     h_muAll1_pt->Fill(muonPt,w);
	     h_muSim1_rpv->Fill(muonRpv,w);
	     h_muSim1_RhoPhi->Fill(muonPosX,muonPosY,w);
	  }
	if( nMuSimSel >= 2 )
	  {
	     h_muSim2_pt->Fill(muonPt,w);
	     h_muAll2_pt->Fill(muonPt,w);
	     h_muSim2_rpv->Fill(muonRpv,w);
	     h_muSim2_RhoPhi->Fill(muonPosX,muonPosY,w);
	  }
     }   

   // create a merged list of gen and sim muons

   std::vector<GenSim> muonGenAll;
   std::vector<GenSim> muonSimAll;
   std::vector<GenSim> muonGenSim;
   std::vector<GenSim> muonGenSimPK;
   std::vector<GenSim> muonGenSimNonPK;
   std::vector<GenSim> muonGenPK;
   std::vector<GenSim> muonGenNonPK;
   
   for(int ig=0;ig<nMuSel;ig++)
     {
	GenSim el; 
	el.idx = muonGen[ig];
	el.type = 0;
	el.pt = muPt->at(el.idx);
	el.eta = muEta->at(el.idx);
	el.phi = muPhi->at(el.idx);
	float muId = momId->at(el.idx);
	int iBin = pdgIdLabel(muId);	
	el.pdgId = iBin;
	muonGenSim.push_back(el);
	muonGenAll.push_back(el);
	if( iBin == 2 || iBin == 5 ) 
	  {
	     muonGenSimPK.push_back(el);
	     muonGenPK.push_back(el);
	  }	
	else
	  {
	     muonGenNonPK.push_back(el);
	     muonGenSimNonPK.push_back(el);
	  }	
     }   

   for(int ig=0;ig<nMuSimSel;ig++)
     {
	GenSim el; 
	el.idx = muonSim[ig];
	el.type = 1;
	el.pt = muSimPt->at(el.idx);
	el.eta = muSimEta->at(el.idx);
	el.phi = muSimPhi->at(el.idx);
	float muId = muSimMomId->at(el.idx);
	int iBin = pdgIdLabel(muId);	
	el.pdgId = iBin;
	muonGenSim.push_back(el);
	muonSimAll.push_back(el);
	if( iBin == 2 || iBin == 5 ) muonGenSimPK.push_back(el);
	else muonGenSimNonPK.push_back(el);
     }   

   // sort by pT
   
   std::sort(muonGenSim.begin(),muonGenSim.end(),sortByPt);
   
   // reco matching
   
   int nGenSim = muonGenSim.size();
   int nGenAll = muonGenAll.size();
   int nSimAll = muonSimAll.size();

   if( nGenSim == 1 )
     {
	if( muonGenSim.at(0).pdgId == 2 ||
	    muonGenSim.at(0).pdgId == 5 ) 
	  h_muPK1_gensim->Fill(muonGenSim.at(0).type,w);
	if( muonGenSim.at(0).pdgId != 0 &&
	    muonGenSim.at(0).pdgId != 1 &&
	    muonGenSim.at(0).pdgId != 2 &&
	    muonGenSim.at(0).pdgId != 5
	  )
	  h_muOTHER1_gensim->Fill(muonGenSim.at(0).type,w);
     }
   if( nGenSim == 2 )
     {
	if( (muonGenSim.at(0).pdgId == 2 || muonGenSim.at(0).pdgId == 5) &&
	    (muonGenSim.at(1).pdgId == 2 || muonGenSim.at(1).pdgId == 5) )
	  {		     
	     if( muonGenSim.at(0).type == 0 && muonGenSim.at(1).type == 0 ) h_muPK2_gensim->Fill(0.,w);
	     if( (muonGenSim.at(0).type == 0 && muonGenSim.at(1).type == 1) ||
		 (muonGenSim.at(0).type == 1 && muonGenSim.at(1).type == 0) ) h_muPK2_gensim->Fill(1.,w);
	     if( muonGenSim.at(0).type == 1 && muonGenSim.at(1).type == 1 ) h_muPK2_gensim->Fill(2.,w);
	  }	
	else if( (muonGenSim.at(0).pdgId == 2 || muonGenSim.at(0).pdgId == 5) )
	  {		     
	     if( muonGenSim.at(0).type == 0 ) h_muPK21_gensim->Fill(0.,w);
	     if( muonGenSim.at(0).type == 1 ) h_muPK21_gensim->Fill(1.,w);
	  }	
	else if( (muonGenSim.at(1).pdgId == 2 || muonGenSim.at(1).pdgId == 5) )
	  {		     
	     if( muonGenSim.at(1).type == 0 ) h_muPK21_gensim->Fill(0.,w);
	     if( muonGenSim.at(1).type == 1 ) h_muPK21_gensim->Fill(1.,w);
	  }
	
	if( (muonGenSim.at(0).pdgId != 0 && muonGenSim.at(0).pdgId != 1) &&
	    (muonGenSim.at(1).pdgId != 0 && muonGenSim.at(1).pdgId != 1) &&
	    (muonGenSim.at(0).pdgId != 2 && muonGenSim.at(0).pdgId != 5) &&
	    (muonGenSim.at(1).pdgId != 2 && muonGenSim.at(1).pdgId != 5)
	  )
	  {		     
	     if( muonGenSim.at(0).type == 0 && muonGenSim.at(1).type == 0 ) h_muOTHER2_gensim->Fill(0.,w);
	     if( (muonGenSim.at(0).type == 0 && muonGenSim.at(1).type == 1) ||
		 (muonGenSim.at(0).type == 1 && muonGenSim.at(1).type == 0) ) h_muOTHER2_gensim->Fill(1.,w);
	     if( muonGenSim.at(0).type == 1 && muonGenSim.at(1).type == 1 ) h_muOTHER2_gensim->Fill(2.,w);
	  }	
	else if( (muonGenSim.at(0).pdgId != 0 && muonGenSim.at(0).pdgId != 1) &&
		 (muonGenSim.at(0).pdgId != 2 && muonGenSim.at(0).pdgId != 5) )
	  {		     
	     if( muonGenSim.at(0).type == 0 ) h_muOTHER21_gensim->Fill(0.,w);
	     if( muonGenSim.at(0).type == 1 ) h_muOTHER21_gensim->Fill(1.,w);
	  }	
	else if( (muonGenSim.at(1).pdgId != 0 && muonGenSim.at(1).pdgId != 1) &&
		 (muonGenSim.at(1).pdgId != 2 && muonGenSim.at(1).pdgId != 5) )
	  {		     
	     if( muonGenSim.at(1).type == 0 ) h_muOTHER21_gensim->Fill(0.,w);
	     if( muonGenSim.at(1).type == 1 ) h_muOTHER21_gensim->Fill(1.,w);
	  }	

	if( (muonGenSim.at(0).pdgId != 2 && muonGenSim.at(0).pdgId != 5) &&
	    (muonGenSim.at(1).pdgId != 2 && muonGenSim.at(1).pdgId != 5)
	  )
	  {		     
	     if( muonGenSim.at(0).type == 0 && muonGenSim.at(1).type == 0 ) h_muNOTPK2_gensim->Fill(0.,w);
	     if( (muonGenSim.at(0).type == 0 && muonGenSim.at(1).type == 1) ||
		 (muonGenSim.at(0).type == 1 && muonGenSim.at(1).type == 0) ) h_muNOTPK2_gensim->Fill(1.,w);
	     if( muonGenSim.at(0).type == 1 && muonGenSim.at(1).type == 1 ) h_muNOTPK2_gensim->Fill(2.,w);
	  }	
     }
   
   for(int im=0;im<nGenSim;im++)
     {
	float muonPt = muonGenSim.at(im).pt;
	
	if( muonGenSim.at(im).pdgId == 0 ||
	    muonGenSim.at(im).pdgId == 1 ) h_muAllBD1_pt->Fill(muonPt,w);
	else if( muonGenSim.at(im).pdgId == 2 ||
		 muonGenSim.at(im).pdgId == 5 )
	  h_muAllPK1_pt->Fill(muonPt,w);
	else 
	  {
	     h_muAllOTHER1_pt->Fill(muonPt,w);
	     if( muonGenSim.at(im).type == 0 ) h_muGenOTHER1_pt->Fill(muonPt,w);
	     if( muonGenSim.at(im).type == 1 ) h_muSimOTHER1_pt->Fill(muonPt,w);
	  }	
	
	if( nGenSim >= 2 )
	  {
	     if( muonGenSim.at(im).pdgId == 0 ||
		 muonGenSim.at(im).pdgId == 1 ) h_muAllBD2_pt->Fill(muonPt,w);
	     else if( muonGenSim.at(im).pdgId == 2 ||
		      muonGenSim.at(im).pdgId == 5 ) 
	       h_muAllPK2_pt->Fill(muonPt,w);
	  }	
	
	float drMin = 666.;
	int idxMin = 666;
	for(int imr=0;imr<nMuRecSel;imr++)
	  {	 
	     int idxRec = muonRec[imr];

	     float muonRecPt = muRecPt->at(idxRec);
	     float muonRecEta = muRecEta->at(idxRec);
	     float muonRecPhi = muRecPhi->at(idxRec);	     
	     
	     float dr = DeltaR(muonGenSim.at(im).eta,muonGenSim.at(im).phi,muonRecEta,muonRecPhi);
	     if( dr < drMin ) 
	       {
		  drMin = dr;
		  idxMin = im;
	       }	     
	  }
	muonGenSim.at(im).idxReco = idxMin;
	muonGenSim.at(im).drReco = drMin;
     }

   for(int im=0;im<nGenSim;im++)
     {   
	float muonPt = muonGenSim.at(im).pt;

	bool isBD = (muonGenSim.at(im).pdgId == 0 || muonGenSim.at(im).pdgId == 1);
	bool isPK = (muonGenSim.at(im).pdgId == 2 || muonGenSim.at(im).pdgId == 5);
	
	if( isBD && muonGenSim.at(im).drReco > 0.2 ) continue;
	if( isPK && muonGenSim.at(im).drReco > 10. ) continue;
	
	if( nGenSim >= 1 )
	  {	     	     
	     if( isBD ) h_muAllBDMatchedRec1_pt->Fill(muonPt,w);
	     else if( isPK ) h_muAllPKMatchedRec1_pt->Fill(muonPt,w);	
	  }
     }   

   int nGenSimPK = muonGenSimPK.size();
   int nGenPK = muonGenPK.size();
   
   int nGenSimNonPK = muonGenSimNonPK.size();
   int nGenNonPK = muonGenNonPK.size();
   
   // Pythia/Geant4 categories for scale factor derivation
     {	
	// nMu = 0
	if( nGenSim == 0 )
	  {
	     h_muGeant_N->Fill(0.,w); // g0
	  }	
   
	// nMu = 1
	if( nGenSim == 1 )
	  {	     
	     h_muGeant_N->Fill(1.,w); // g1

	     if( nSimAll == 0 )
	       {	     
		  if( nGenPK == 1 && nGenNonPK == 0 ) h_muPythiaGeant_N->Fill(0.,w); // x3
		  if( nGenPK == 0 && nGenNonPK == 1 ) h_muPythiaGeant_N->Fill(1.,w); // y1
	       }
	  }	

	// nMu = 2
	if( nGenSim == 2 )
	  {
	     h_muGeant_N->Fill(2.,w); // g2

	     if( nSimAll == 0 )
	       {
		  if( nGenPK == 0 && nGenNonPK == 2 ) h_muPythiaGeant_N->Fill(9.,w); // z1
		  if( nGenPK == 1 && nGenNonPK == 1 ) h_muPythiaGeant_N->Fill(7.,w); // y3
		  if( nGenPK == 2 && nGenNonPK == 0 ) h_muPythiaGeant_N->Fill(4.,w); // x6
	       }
	     
	     if( nSimAll == 1 )
	       {
		  if( nGenPK == 1 && nGenNonPK == 0 ) h_muPythiaGeant_N->Fill(2.,w); // x5
		  if( nGenPK == 0 && nGenNonPK == 1 ) h_muPythiaGeant_N->Fill(6.,w); // y2
	       }	
	  }   

	// nMu = 3
	if( nGenSim == 3 )
	  {
	     h_muGeant_N->Fill(3.,w); // g3

	     if( nSimAll == 0 )
	       {
		  if( nGenPK == 3 && nGenNonPK == 0 ) h_muPythiaGeant_N->Fill(12.,w); // x10
		  if( nGenPK == 2 && nGenNonPK == 1 ) h_muPythiaGeant_N->Fill(15.,w); // y6
		  if( nGenPK == 1 && nGenNonPK == 2 ) h_muPythiaGeant_N->Fill(17.,w); // z3
		  if( nGenPK == 0 && nGenNonPK == 3 ) h_muPythiaGeant_N->Fill(18.,w); // h1
	       }
	     
	     if( nSimAll == 1 )
	       {
		  if( nGenPK == 2 && nGenNonPK == 0 ) h_muPythiaGeant_N->Fill(11.,w); // x9
		  if( nGenPK == 1 && nGenNonPK == 1 ) h_muPythiaGeant_N->Fill(14.,w); // y5
		  if( nGenPK == 0 && nGenNonPK == 2 ) h_muPythiaGeant_N->Fill(16.,w); // z2
	       }	

	     if( nSimAll == 2 )
	       {
		  if( nGenPK == 1 && nGenNonPK == 0 ) h_muPythiaGeant_N->Fill(10.,w); // x8
		  if( nGenPK == 0 && nGenNonPK == 1 ) h_muPythiaGeant_N->Fill(13.,w); // y4
	       }	
	  }   
     }   

   // generator validation for pi/K corrections

   for(int ig=0;ig<nGenSim;ig++)
     {	
	float muonPt = muonGenSim.at(ig).pt;

	float sf = 1.;
	if( nGenPK == 0 ) sf *= 1.;
	if( nGenPK == 1 ) sf *= 1.10042;
	if( nGenPK == 2 ) sf *= -2.51481;
	if( nGenPK == 3 ) sf *= 2.47126;
	
	if( nGenSim == 1 )
	  {	     
	     h_muVal1_pt->Fill(muonPt,w*sf);
	     h_muValUncor1_pt->Fill(muonPt,w);
	  }	
	if( nGenSim == 2 )
	  {	     
	     h_muVal2_pt->Fill(muonPt,w*sf);
	     h_muValUncor2_pt->Fill(muonPt,w);
	  }	
	if( nGenSim == 3 )
	  {	     
	     h_muVal3_pt->Fill(muonPt,w*sf);
	     h_muValUncor3_pt->Fill(muonPt,w);
	  }	
     }
   
   // validation with reconstructed muons

   std::vector<int> muAll;
   std::vector<int> muFake;
   std::vector<int> muReal;
   
   for(int im=0;im<nMuRecSel;im++)
     {
	float muonPt = muRecPt->at(muonRec[im]);
	float muonEta = muRecEta->at(muonRec[im]);
	float muonPhi = muRecPhi->at(muonRec[im]);
	
	if( muonPt < 5. || fabs(muonEta) > 2.4 ) continue;

	// BTV muon selection
	int numberOfValidMuonHits = muRecNumberOfValidMuonHits->at(muonRec[im]);
	int numberOfMatches = muRecNumberOfMatches->at(muonRec[im]);
	int numberOfMatchedStations = muRecNumberOfMatchedStations->at(muonRec[im]);
	int trackerLayersWithMeasurement = muRecTrackerLayersWithMeasurement->at(muonRec[im]);
	int numberOfValidHits = muRecNumberOfValidHits->at(muonRec[im]);
	int numberOfValidPixelHits = muRecNumberOfValidPixelHits->at(muonRec[im]);
	int numberOfHits = muRecNumberOfHits->at(muonRec[im]);
	float normalizedChi2GlobalTrack = muRecNormalizedChi2GlobalTrack->at(muonRec[im]);
	float normalizedChi2InnerTrack = muRecNormalizedChi2InnerTrack->at(muonRec[im]);
	bool isPFMuon = muRecIsPFMuon->at(muonRec[im]);
	bool isGlobalMuon = muRecIsGlobalMuon->at(muonRec[im]);
	     
	bool passBTV = BTVMuonSelection(numberOfValidMuonHits,
					numberOfMatches,
					numberOfMatchedStations,
					trackerLayersWithMeasurement,
					numberOfValidHits,
					numberOfValidPixelHits,
					numberOfHits,
					normalizedChi2GlobalTrack,
					normalizedChi2InnerTrack,
					isPFMuon,
					isGlobalMuon);
	
	if( !passBTV ) continue;
	
	float drGenSimMin = 666.;
	int type = -1;
	int pdgId = -1;
	for(int ig=0;ig<nGenSim;ig++)
	  {
	     float drGen = DeltaR(muonEta,muonPhi,muonGenSim.at(ig).eta,muonGenSim.at(ig).phi);
	     if( drGen < drGenSimMin )
	       {
		  drGenSimMin = drGen;
		  type = muonGenSim.at(ig).type;
		  pdgId = muonGenSim.at(ig).pdgId;
	       }		  
	  }
	
	bool isFake = (type < 0);

	muAll.push_back(muonRec[im]);
	if( isFake ) muFake.push_back(muonRec[im]);
	else muReal.push_back(muonRec[im]);
     }

   int nMuAll = muAll.size();
   int nMuFake = muFake.size();
   int nMuReal = muReal.size();

   for(int im=0;im<nMuFake;im++)
     {
	float muonPt = muRecPt->at(muFake[im]);
	
	h_muFake_pt->Fill(muonPt,w);
	
	int trackerLayersWithMeasurement = muRecTrackerLayersWithMeasurement->at(muFake[im]);
	int numberOfValidMuonHits = muRecNumberOfValidMuonHits->at(muFake[im]);
	int numberOfMatches = muRecNumberOfMatches->at(muFake[im]);
	int numberOfMatchedStations = muRecNumberOfMatchedStations->at(muFake[im]);
	int numberOfValidHits = muRecNumberOfValidHits->at(muFake[im]);
	int numberOfValidPixelHits = muRecNumberOfValidPixelHits->at(muFake[im]);
	int numberOfHits = muRecNumberOfHits->at(muFake[im]);
	float normalizedChi2GlobalTrack = muRecNormalizedChi2GlobalTrack->at(muFake[im]);
	float normalizedChi2InnerTrack = muRecNormalizedChi2InnerTrack->at(muFake[im]);
	
	h_muFake_trackerLayersWithMeasurement->Fill(trackerLayersWithMeasurement,w);
	h_muFake_numberOfValidMuonHits->Fill(numberOfValidMuonHits,w);
	h_muFake_numberOfMatches->Fill(numberOfMatches,w);
	h_muFake_numberOfMatchedStations->Fill(numberOfMatchedStations,w);
	h_muFake_numberOfValidHits->Fill(numberOfValidHits,w);
	h_muFake_numberOfValidPixelHits->Fill(numberOfValidPixelHits,w);
	h_muFake_numberOfHits->Fill(numberOfHits,w);
	h_muFake_normalizedChi2GlobalTrack->Fill(normalizedChi2GlobalTrack,w);
	h_muFake_normalizedChi2InnerTrack->Fill(normalizedChi2InnerTrack,w);
     }   

   for(int im=0;im<nMuReal;im++)
     {
	float muonPt = muRecPt->at(muReal[im]);
	
	h_muReal_pt->Fill(muonPt,w);
	
	int trackerLayersWithMeasurement = muRecTrackerLayersWithMeasurement->at(muReal[im]);
	int numberOfValidMuonHits = muRecNumberOfValidMuonHits->at(muReal[im]);
	int numberOfMatches = muRecNumberOfMatches->at(muReal[im]);
	int numberOfMatchedStations = muRecNumberOfMatchedStations->at(muReal[im]);
	int numberOfValidHits = muRecNumberOfValidHits->at(muReal[im]);
	int numberOfValidPixelHits = muRecNumberOfValidPixelHits->at(muReal[im]);
	int numberOfHits = muRecNumberOfHits->at(muReal[im]);
	float normalizedChi2GlobalTrack = muRecNormalizedChi2GlobalTrack->at(muReal[im]);
	float normalizedChi2InnerTrack = muRecNormalizedChi2InnerTrack->at(muReal[im]);
	
	h_muReal_trackerLayersWithMeasurement->Fill(trackerLayersWithMeasurement,w);
	h_muReal_numberOfValidMuonHits->Fill(numberOfValidMuonHits,w);
	h_muReal_numberOfMatches->Fill(numberOfMatches,w);
	h_muReal_numberOfMatchedStations->Fill(numberOfMatchedStations,w);
	h_muReal_numberOfValidHits->Fill(numberOfValidHits,w);
	h_muReal_numberOfValidPixelHits->Fill(numberOfValidPixelHits,w);
	h_muReal_numberOfHits->Fill(numberOfHits,w);
	h_muReal_normalizedChi2GlobalTrack->Fill(normalizedChi2GlobalTrack,w);
	h_muReal_normalizedChi2InnerTrack->Fill(normalizedChi2InnerTrack,w);
     }   

   for(int im=0;im<nMuAll;im++)
     {
	float muonPt = muRecPt->at(muAll[im]);

	if( nMuAll == 1 ) h_muRecValUncor1_pt->Fill(muonPt,w);	
	if( nMuAll == 2  ) h_muRecValUncor2_pt->Fill(muonPt,w);
	if( nMuAll == 3  ) h_muRecValUncor3_pt->Fill(muonPt,w);
	
	float sf = 1.;
	if( nGenPK == 1 ) sf *= 1.10042;
	if( nGenPK == 2 ) sf *= -2.51481;
	if( nGenPK == 3 ) sf *= 2.47126;

	if( nMuAll == 1 ) h_muRecVal1_pt->Fill(muonPt,w*sf);
	if( nMuAll == 2 ) h_muRecVal2_pt->Fill(muonPt,w*sf);
	if( nMuAll == 3 ) h_muRecVal3_pt->Fill(muonPt,w*sf);
     }   
   
/*   for(int ij=0;ij<nMuJet;ij++)
     {
	float wSF = 1.;
	
	int idxMuJet = mujet[ij];
		
	float jetPt = patjetPt->at(idxMuJet);
	float jetEta = patjetEta->at(idxMuJet);
	
	int jetHadronFlavour = patjetHadronFlavour->at(idxMuJet);
	
	if( nGenSim == 1 )
	  {
	     bool isPK = (muonGenSim.at(0).pdgId == 2 || muonGenSim.at(0).pdgId == 5);
	     
	     if( isPK && muonGenSim.at(0).type == 0 )
	       wSF = 0.743126;
	  }
/*	if( nGenSim == 2 )
	  {
	     if( (muonGenSim.at(0).pdgId == 2 || muonGenSim.at(0).pdgId == 5) &&
		 (muonGenSim.at(1).pdgId == 2 || muonGenSim.at(1).pdgId == 5) )
	       {		     
		  if( muonGenSim.at(0).type == 0 && muonGenSim.at(1).type == 0 ) h_muPK2_gensim->Fill(0.,w);
		  if( (muonGenSim.at(0).type == 0 && muonGenSim.at(1).type == 1) ||
		      (muonGenSim.at(0).type == 1 && muonGenSim.at(1).type == 0) ) h_muPK2_gensim->Fill(1.,w);
		  if( muonGenSim.at(0).type == 1 && muonGenSim.at(1).type == 1 ) h_muPK2_gensim->Fill(2.,w);
	       }	
	  }
	
	if( nMuJet >= 1 )
	  {
	     h_muJet1_pt->Fill(jetPt,w);
	     if( jetHadronFlavour == 5 ) h_muBJet1_pt->Fill(jetPt,w);
	     else if( jetHadronFlavour == 4 ) h_muCJet1_pt->Fill(jetPt,w);
	     else h_muLJet1_pt->Fill(jetPt,w);
	  }
	if( nMuJet >= 2 )
	  {
	     h_muJet2_pt->Fill(jetPt,w);
	     if( jetHadronFlavour == 5 ) h_muBJet2_pt->Fill(jetPt,w);
	     else if( jetHadronFlavour == 4 ) h_muCJet2_pt->Fill(jetPt,w);
	     else h_muLJet2_pt->Fill(jetPt,w);
	  }
     }*/
   
}

void SIMPLOT::Origin::close()
{
   _fout->Write();
   _fout->Close();
}

int SIMPLOT::Origin::pdgIdLabel(int pdgId)
{
   std::string label = "666";
   int iBin = -1;
   
   int pdgIdAbs = abs(pdgId);

   if( pdgIdAbs == 521 ) {label = "B+-"; iBin = 0;}
   else if( pdgIdAbs == 411 ) {label = "D+-"; iBin = 1;}
   else if( pdgIdAbs == 4232 ) {label = "Xi_c+-"; iBin = 6;}
   else if( pdgIdAbs == 5232 ) {label = "Xi_b0"; iBin = 6;}
   else if( pdgIdAbs == 211 ) {label = "pi+-"; iBin = 5;}
   else if( pdgIdAbs == 431 ) {label = "D_s+-"; iBin = 1;}
   else if( pdgIdAbs == 15 ) {label = "tau+-"; iBin = 4;}
   else if( pdgIdAbs == 321 ) {label = "K+-"; iBin = 2;}
   else if( pdgIdAbs == 511 ) {label = "B0"; iBin = 0;}
   else if( pdgIdAbs == 421 ) {label = "D0"; iBin = 1;}
   else if( pdgIdAbs == 5122 ) {label = "Lambda_b"; iBin = 3;}
   else if( pdgIdAbs == 4122 ) {label = "Lambda_c"; iBin = 3;}
   else if( pdgIdAbs == 531 ) {label = "B_s0"; iBin = 0;}
   else if( pdgIdAbs == 223 ) {label = "omega"; iBin = 6;}
   else if( pdgIdAbs == 130 ) {label = "K_L0"; iBin = 2;}
   else if( pdgIdAbs == 221 ) {label = "eta"; iBin = 6;}
   else if( pdgIdAbs == 113 ) {label = "rho0"; iBin = 6;}
   else if( pdgIdAbs == 443 ) {label = "J/psi"; iBin = 6;}
   else if( pdgIdAbs == 22 ) {label = "photon"; iBin = 6;}
   else if( pdgIdAbs == 5132 ) {label = "Xi_b"; iBin = 6;}
   else if( pdgIdAbs == 4132 ) {label = "Xi_c0"; iBin = 6;}
   else if( pdgIdAbs == 331 ) {label = "eta'"; iBin = 6;}
   else if( pdgIdAbs == 333 ) {label = "phi"; iBin = 6;}
   else
     {
	label = "others";
	iBin = 6;
     }   

   return iBin;
}

int SIMPLOT::Origin::partonIdLabel(int partonId)
{
   std::string label = "666";
   int iBin = -1;
   
   int partonIdAbs = abs(partonId);

   if( partonIdAbs == 21 ) {label = "Gluon"; iBin = 0;}
   else if( partonIdAbs == 1 || partonIdAbs == 2 || partonIdAbs == 3 ) {label = "Light"; iBin = 1;}
   else if( partonIdAbs == 4 ) {label = "Charm"; iBin = 2;}
   else if( partonIdAbs == 5 ) {label = "Bottom"; iBin = 3;}
   else
     {
	std::cout << "Parton label not found" << std::endl;
	exit(1);
     }   

   return iBin;
}

float SIMPLOT::Origin::DeltaR(float eta1,float phi1,float eta2,float phi2)
{
   float DeltaPhi = TMath::Abs(phi2 - phi1);
   if (DeltaPhi > 3.141593 ) DeltaPhi -= 2.*3.141593;
   return TMath::Sqrt( (eta2-eta1)*(eta2-eta1) + DeltaPhi*DeltaPhi );
}

bool SIMPLOT::Origin::BTVMuonSelection(int numberOfValidMuonHits,
				       int numberOfMatches,
				       int numberOfMatchedStations,
				       int trackerLayersWithMeasurement,
				       int numberOfValidHits,
				       int numberOfValidPixelHits,
				       int numberOfHits,
				       float normalizedChi2GlobalTrack,
				       float normalizedChi2InnerTrack,
				       bool isPFMuon,
				       bool isGlobalMuon
				      )
{
   bool pass = 1;
   
   if( !isPFMuon ) pass = 0;
   if( !isGlobalMuon ) pass = 0;
   if( numberOfValidMuonHits == 0 ) pass = 0;
   if( numberOfMatches <= 1 ) pass = 0;
   if( numberOfValidHits <= 10 ) pass = 0;
   if( numberOfValidPixelHits <= 1 ) pass = 0;
   if( numberOfHits >= 3 ) pass = 0;
   if( normalizedChi2GlobalTrack >= 10 ) pass = 0;
   if( normalizedChi2InnerTrack >= 10 ) pass = 0;   
   
   return pass;
}

bool SIMPLOT::Origin::NewMuonSelection(int numberOfValidMuonHits,
				       int numberOfMatches,
				       int numberOfMatchedStations,
				       int trackerLayersWithMeasurement,
				       int numberOfValidHits,
				       int numberOfValidPixelHits,
				       int numberOfHits,
				       float normalizedChi2GlobalTrack,
				       float normalizedChi2InnerTrack,
				       bool isPFMuon,
				       bool isGlobalMuon
				      )
{
   bool pass = 1;
   
   if( !isPFMuon ) pass = 0;
   if( !isGlobalMuon ) pass = 0;
   if( numberOfValidMuonHits == 0 ) pass = 0;
   if( numberOfMatchedStations <= 2 ) pass = 0;
   if( trackerLayersWithMeasurement <= 5 ) pass = 0;
   if( numberOfValidHits <= 10 ) pass = 0;
   if( numberOfValidPixelHits == 0 ) pass = 0;
   if( numberOfHits >= 3 ) pass = 0;
   if( normalizedChi2GlobalTrack >= 10 ) pass = 0;
   if( normalizedChi2InnerTrack >= 10 ) pass = 0;   
   
   return pass;
}
