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
   
   std::vector<float> *muRecPt = ntP->recomuonPt;
   std::vector<float> *muRecEta = ntP->recomuonEta;
   std::vector<float> *muRecPhi = ntP->recomuonPhi;

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
   std::vector<int> mujet;
   
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
	if( muonPt < ptCut || fabs(muonEta) > 2.5 ) continue;	
	muonGen.push_back(im);
     }

   for(int im=0;im<nMuSim;im++)
     {
	float muonPt = muSimPt->at(im);
	float muonEta = muSimEta->at(im);
//	int momId = muSimMomId->at(im);
//	int iBin = pdgIdLabel(momId);
//	if( iBin == 0 || iBin == 1 ) continue;
	if( muonPt < ptCut || fabs(muonEta) > 2.5 ) continue;
	muonSim.push_back(im);
     }

   for(int im=0;im<nMuRec;im++)
     {
	float muonPt = muRecPt->at(im);
	float muonEta = muRecEta->at(im);
	if( muonPt < ptCut || fabs(muonEta) > 2.5 ) continue;
	muonRec.push_back(im);
     }

   for(int ij=0;ij<nJet;ij++)
     {
	float jetPt = patjetPt->at(ij);
	float jetEta = patjetEta->at(ij);
	float jetPhi = patjetPhi->at(ij);
	if( jetPt < 30. || fabs(jetEta) > 2.4 ) continue;

	bool foundInJetMuon = 0;
	for(int im=0;im<muonRec.size();im++)
	  {
	     float dr = DeltaR(jetEta,jetPhi,muRecEta->at(muonRec[im]),muRecPhi->at(muonRec[im]));
	     if( dr < 0.4 )
	       {		  
		  foundInJetMuon = 1;
		  break;
	       }	     
	  }		
	if( foundInJetMuon ) mujet.push_back(ij);
     }
   
   int nMuSel = muonGen.size();
   int nMuSimSel = muonSim.size();
   int nMuRecSel = muonRec.size();
   int nMuJet = mujet.size();

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

   for(int im=0;im<nMuRecSel;im++)
     {
	int idxRec = muonRec[im];
	
/*	float muonPt = muRecPt->at(idxRec);
	float muonEta = muRecEta->at(idxRec);
	float muonPhi = muRecPhi->at(idxRec);

	for(int img=0;img<nMuSel;img++)
	  {
	     int idxGen = muonGen[img];
	     float muGenEta = muEta->at(idxGen);
	     float muGenPhi = muPhi->at(idxGen);
	     
	     float dr = DeltaR(muGenEta,muGenPhi,muonEta,muonPhi);
	     std::cout << dr << std::endl;
	  }
	
	if( nMuRecSel >= 1 )
	  {
	     h_muRec1_pt->Fill(muonPt,w);
	  }
	if( nMuRecSel >= 2 )
	  {
	     h_muRec2_pt->Fill(muonPt,w);
	  }*/
     }   

   for(int ij=0;ij<nMuJet;ij++)
     {
	int idxMuJet = mujet[ij];
	  
	float jetPt = patjetPt->at(idxMuJet);
	int jetHadronFlavour = patjetHadronFlavour->at(idxMuJet);
	
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
     }   
   
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
