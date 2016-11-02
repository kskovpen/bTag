#include "../include/Hist.h"

SIMPLOT::Hist::Hist()
{
}

SIMPLOT::Hist::~Hist()
{
}

void SIMPLOT::Hist::init()
{
   std::string foutName = std::string(foutname)+".root";

   _fout = new TFile(foutName.c_str(),"RECREATE");

   _fout->cd();

   h_passFilt = new TH1F("h_passFilt","h_passFilt",6,0.,6.);
   h_passFilt->Sumw2();

   h_hasGenMu = new TH1F("h_hasGenMu","h_hasGenMu",4,0.,4.);
   h_hasGenMu->Sumw2();

   h_hasRecMu = new TH1F("h_hasRecMu","h_hasRecMu",2,0.,2.);
   h_hasRecMu->Sumw2();
}

void SIMPLOT::Hist::fill()
{
   std::vector<int> *simTrkId = ntP->simTrkId;
   std::vector<float> *simTrkPt = ntP->simTrkPt;
   std::vector<float> *simTrkEta = ntP->simTrkEta;
   std::vector<float> *simTrkPhi = ntP->simTrkPhi;

   std::vector<int> *nSimHitRPC = ntP->nSimHitRPC;
   std::vector<int> *nSimHitCSC = ntP->nSimHitCSC;
   std::vector<int> *nSimHitDT = ntP->nSimHitDT;

   std::vector<int> *nSimHitRPCRECO = ntP->nSimHitRPCRECO;
   std::vector<int> *nSimHitRPC2RECO = ntP->nSimHitRPC2RECO;
   std::vector<int> *nSimHitCSCStripRECO = ntP->nSimHitCSCStripRECO;
   std::vector<int> *nSimHitCSCWireRECO = ntP->nSimHitCSCWireRECO;
   std::vector<int> *nSimHitDTRECO = ntP->nSimHitDTRECO;
   
   std::vector<float> *muGenPt = ntP->muGenPt;
   std::vector<float> *muGenEta = ntP->muGenEta;
   std::vector<float> *muGenPhi = ntP->muGenPhi;
   std::vector<int> *muGenStatus = ntP->muGenStatus;

   std::vector<float> *muRecPt = ntP->muRecPt;
   std::vector<float> *muRecEta = ntP->muRecEta;
   std::vector<float> *muRecPhi = ntP->muRecPhi;
   std::vector<int> *muRecNumberOfValidMuonRPCHits = ntP->muRecNumberOfValidMuonRPCHits;
   std::vector<int> *muRecNumberOfValidMuonCSCHits = ntP->muRecNumberOfValidMuonCSCHits;
   std::vector<int> *muRecNumberOfValidMuonDTHits = ntP->muRecNumberOfValidMuonDTHits;
   std::vector<int> *muRecNumberOfValidMuonHits = ntP->muRecNumberOfValidMuonHits;
   std::vector<int> *muRecNumberOfMatches = ntP->muRecNumberOfMatches;
   std::vector<int> *muRecNumberOfValidHits = ntP->muRecNumberOfValidHits;
   std::vector<int> *muRecNumberOfValidPixelHits = ntP->muRecNumberOfValidPixelHits;
   std::vector<int> *muRecNumberOfHits = ntP->muRecNumberOfHits;
   std::vector<int> *muRecNormalizedChi2GlobalTrack = ntP->muRecNormalizedChi2GlobalTrack;
   std::vector<int> *muRecNormalizedChi2InnerTrack = ntP->muRecNormalizedChi2InnerTrack;

   bool hasGenMu = 0;
   
   int nGenMu = muGenPt->size();
   
   for(int im=0;im<nGenMu;im++)
     {	
	if( muGenStatus->at(im) != 1 ) continue;
	if( muGenPt->at(im) < 5. || fabs(muGenEta->at(im)) > 2.4 ) continue;
	
	hasGenMu = 1;
     }   
   
   h_hasGenMu->Fill(0.);
   if( hasGenMu ) h_hasGenMu->Fill(1.);

   int hasRecMu = 0;
   
   int nRecMu = muRecPt->size();
   
   for(int im=0;im<nRecMu;im++)
     {	
	if( muRecPt->at(im) < 5. || fabs(muRecEta->at(im)) > 2.4 ) continue;
//	if( muRecNumberOfValidMuonRPCHits->at(im) == 0 && 
//	    muRecNumberOfValidMuonCSCHits->at(im) == 0 &&
//	    muRecNumberOfValidMuonDTHits->at(im) == 0 
//	  ) continue;

	bool passSel = BTVMuonSelection(muRecNumberOfValidMuonHits->at(im),
					muRecNumberOfMatches->at(im),
					muRecNumberOfValidHits->at(im),
					muRecNumberOfValidPixelHits->at(im),
					muRecNumberOfHits->at(im),
					muRecNormalizedChi2GlobalTrack->at(im),
					muRecNormalizedChi2InnerTrack->at(im),
					1,
					1);
	
	if( !passSel ) continue;
	
	hasRecMu++;
     }   

   h_hasRecMu->Fill(bool(hasRecMu));
   
   if( hasGenMu && (hasRecMu>0) ) h_hasGenMu->Fill(2.);
   if( hasGenMu && !(hasRecMu>0) ) h_hasGenMu->Fill(3.);
   
   bool passFilt = 0;
   int nSimHits = 0;
   int nSimHitsRPC2 = 0;
   
   int nSimTrk = simTrkId->size();

   for(int it=0;it<nSimTrk;it++)
     {
	bool pt = (simTrkPt->at(it) > 3.);
	bool mupt = (simTrkPt->at(it) > 3.);
	bool id = (abs(simTrkId->at(it)) == 13);
	bool rpc2 = (runOnReco) ? (nSimHitRPC2RECO->at(it) > 0) : 0;
	
//	if( !pt ) continue;
//	if( !(id && mupt) && !(pt) ) continue;
	if( !mupt || !id ) continue;
//	if( !((pt && rpc2)|| id) ) continue;
//	if( !(pt && rpc2) ) continue;
//	if( !id ) continue;
	
	if( runOnReco )
	  {	     
	     int nHits = nSimHitRPCRECO->at(it)+nSimHitCSCStripRECO->at(it)+nSimHitCSCWireRECO->at(it)+nSimHitDTRECO->at(it);
	     if( nHits < 1 ) continue;
	     
	     nSimHits += bool(nHits);
	  }
	else
	  {	     
	     int nHits = nSimHitRPC->at(it)+nSimHitCSC->at(it)+nSimHitDT->at(it);
	     if( nHits < 1 ) continue;
	     
	     nSimHits += bool(nHits);
	  }	
     }
   
   passFilt = (nSimHits > 0);

   hasRecMu = (hasRecMu > 0);

   h_passFilt->Fill(0.);
   if( hasRecMu ) h_passFilt->Fill(1.);
   if( passFilt ) h_passFilt->Fill(2.);
   if( passFilt && hasRecMu ) h_passFilt->Fill(3.);
   if( !hasRecMu ) h_passFilt->Fill(4.);
   if( !hasRecMu && passFilt ) h_passFilt->Fill(5.);
}

void SIMPLOT::Hist::close()
{
   _fout->Write();
   _fout->Close();
}

int SIMPLOT::Hist::pdgIdLabel(int pdgId)
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

int SIMPLOT::Hist::partonIdLabel(int partonId)
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

float SIMPLOT::Hist::DeltaR(float eta1,float phi1,float eta2,float phi2)
{
   float DeltaPhi = TMath::Abs(phi2 - phi1);
   if (DeltaPhi > 3.141593 ) DeltaPhi -= 2.*3.141593;
   return TMath::Sqrt( (eta2-eta1)*(eta2-eta1) + DeltaPhi*DeltaPhi );
}

bool SIMPLOT::Hist::BTVMuonSelection(int numberOfValidMuonHits,
				     int numberOfMatches,
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

/*bool SIMPLOT::Hist::BTVDoubleMuonSelection(float pt,
					   int numberOfValidHits,
					   int numberOfValidPixelHits,
					   float normalizedChi2GlobalTrack,
					   bool isPFMuon,
					   bool isGlobalMuon
					  )
{
   bool pass = 1;
   
   if( !isPFMuon ) pass = 0;
   if( !isGlobalMuon ) pass = 0;
   if( pt < 1 ) pass = 0;
   if( numberOfValidHits <= 7 ) pass = 0;
   if( numberOfValidPixelHits <= 1 ) pass = 0;
   if( normalizedChi2GlobalTrack >= 5 ) pass = 0;
   
   return pass;
}*/
