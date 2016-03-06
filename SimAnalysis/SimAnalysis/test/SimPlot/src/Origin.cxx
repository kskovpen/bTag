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
   h_mu2_id = new TH1F("h_mu2_id","h_mu2_id",7,0,7);

   h_mu1_partonId = new TH1F("h_mu1_partonId","h_mu1_partonId",4,0,4);
   h_mu2_partonId = new TH1F("h_mu2_partonId","h_mu2_partonId",4,0,4);
   
   h_mu1_pt = new TH1F("h_mu1_pt","h_mu1_pt",30,0,50);
   h_mu2_pt = new TH1F("h_mu2_pt","h_mu2_pt",30,0,50);

   h_muAll1_pt = new TH1F("h_muAll1_pt","h_muAll1_pt",30,0,50);
   h_muAll2_pt = new TH1F("h_muAll2_pt","h_muAll2_pt",30,0,50);
   
   h_mu1_rpv = new TH1F("h_mu1_rpv","h_mu1_rpv",30,0,65);
   h_mu2_rpv = new TH1F("h_mu2_rpv","h_mu2_rpv",30,0,65);
//   h_mu1_rpv = new TH1F("h_mu1_rpv","h_mu1_rpv",30,0,300);
//   h_mu2_rpv = new TH1F("h_mu2_rpv","h_mu2_rpv",30,0,300);
   
   h_muSim1_pt = new TH1F("h_muSim1_pt","h_muSim1_pt",30,0,50);
   h_muSim2_pt = new TH1F("h_muSim2_pt","h_muSim2_pt",30,0,50);

   h_mu1_RhoPhi = new TH2F("h_mu1_RhoPhi","h_mu1_RhoPhi",100,-25.,25.,100,-25.,25.);
   h_mu2_RhoPhi = new TH2F("h_mu2_RhoPhi","h_mu2_RhoPhi",100,-25.,25.,100,-25.,25.);
//   h_mu1_RhoPhi = new TH2F("h_mu1_RhoPhi","h_mu1_RhoPhi",100,-200.,200.,100,-200.,200.);
//   h_mu2_RhoPhi = new TH2F("h_mu2_RhoPhi","h_mu2_RhoPhi",100,-200.,200.,100,-200.,200.);

   h_muSim1_RhoPhi = new TH2F("h_muSim1_RhoPhi","h_muSim1_RhoPhi",100,-25.,25.,100,-25.,25.);
   h_muSim2_RhoPhi = new TH2F("h_muSim2_RhoPhi","h_muSim2_RhoPhi",100,-25.,25.,100,-25.,25.);
//   h_muSim1_RhoPhi = new TH2F("h_muSim1_RhoPhi","h_muSim1_RhoPhi",100,-200.,200.,100,-200.,200.);
//   h_muSim2_RhoPhi = new TH2F("h_muSim2_RhoPhi","h_muSim2_RhoPhi",100,-200.,200.,100,-200.,200.);

   h_muSim1_rpv = new TH1F("h_muSim1_rpv","h_muSim1_rpv",30,0,65);
   h_muSim2_rpv = new TH1F("h_muSim2_rpv","h_muSim2_rpv",30,0,65);
//   h_muSim1_rpv = new TH1F("h_muSim1_rpv","h_muSim1_rpv",30,0,300);
//   h_muSim2_rpv = new TH1F("h_muSim2_rpv","h_muSim2_rpv",30,0,300);
   
   h_punchThroughEff = new TH1F("h_punchThroughEff","h_punchThroughEff",2,0,2);
}

void SIMPLOT::Origin::fill()
{
   std::vector<int> *momId = ntP->momId;
   std::vector<float> *muPt = ntP->muPt;
   std::vector<float> *muEta = ntP->muEta;
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

//   float w = 139803000.*0.01182/3233125.; // 30-50 Mu-enriched
//   float w = 139803000./1176575.; // 30-50 Inclusive
//   float w = 19222500.*0.02276/1405153.; // 50-80 Mu-enriched
//   float w = 19222500./4447180.; // 50-80 Inclusive
//   float w = 2758420.*0.03844/970870.; // 80-120 Mu-enriched
//   float w = 2758420./1171567.; // 80-120 Inclusive
//   float w = 469797.*0.05362/551131.; // 120-170 Mu-enriched
//   float w = 469797./874927.; // 120-170 Inclusive
//   float w = 117989.*0.07335/642597.; // 170-300 Mu-enriched
   float w = 117989./656676.; // 170-300 Inclusive
//   float w = 7820.25*0.10196/607320.; // 300-470 Mu-enriched
//   float w = 7820.25/572832.; // 300-470 Inclusive
//   float w = 645.528*0.12242/371887.; // 470-600 Mu-enriched
//   float w = 645.528/292410.; // 470-600 Inclusive
//   float w = 187.109*0.13412/334973.; // 600-800 Mu-enriched
//   float w = 187.109/307380.; // 600-800 Inclusive
//   float w = 32.3486*0.14552/265299.; // 800-1000 Mu-enriched
//   float w = 32.3486/293480.; // 800-1000 Inclusive
   
   float ptCut = 5.;
   
   int nMu = momId->size();
   int nMuSim = muSimPt->size();

   std::vector<int> muonGen;
   std::vector<int> muonSim;
   
   for(int im=0;im<nMu;im++)
     {
	int pId = partonId->at(im);
	int iBinParton = partonIdLabel(pId);
//	if( iBinParton != 1 && iBinParton != 0 ) continue;
	if( iBinParton != 3 ) continue;
	float muonPt = muPt->at(im);
	float muonEta = muEta->at(im);
	int muonStatus = muStatus->at(im);
	if( muonStatus != 1 ) continue;
	if( muonPt < 5. || fabs(muonEta) > 2.5 ) continue;	
	muonGen.push_back(im);
     }

   for(int im=0;im<nMuSim;im++)
     {
	float muonPt = muSimPt->at(im);
	float muonEta = muSimEta->at(im);
	if( muonPt < 5. || fabs(muonEta) > 2.5 ) continue;
	muonSim.push_back(im);
     }

   if( muonSim.size() > 0 )
     {	
	if( muonGen.size() > 0 ) h_punchThroughEff->Fill(1);
	else h_punchThroughEff->Fill(0);
     }  
   
   int nMuSel = muonGen.size();
   int nMuSimSel = muonSim.size();

   if( nMuSel >= 1 ) nSel++;
   
   for(int im=0;im<nMuSel;im++)
     {
	int idxGen = muonGen[im];
	  
	float muonPt = muPt->at(idxGen);
	int muId = momId->at(idxGen);
	int pId = partonId->at(idxGen);
	
	float muonPosX = muPosX->at(idxGen)/10.;
	float muonPosY = muPosY->at(idxGen)/10.;
	float muonPosZ = muPosZ->at(idxGen)/10.;
	float muonRpv = muRpv->at(idxGen)/10.;
	
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

	float muonPosX = muSimPosX->at(idxSim)/10.;
	float muonPosY = muSimPosY->at(idxSim)/10.;
	float muonPosZ = muSimPosZ->at(idxSim)/10.;
	float muonRpv = muSimRpv->at(idxSim)/10.;
	
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
