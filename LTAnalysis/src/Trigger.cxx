#include "../include/Trigger.h"

LTANA::Trigger::Trigger()
{
}

LTANA::Trigger::~Trigger()
{
}

void LTANA::Trigger::init()
{
   rnd = new TRandom3(666);
   
   std::string foutName = std::string(foutname)+".root";

   _fout = new TFile(foutName.c_str(),"RECREATE");
   _fout->cd();

   // HLT_BTagMu_DiJet20_Mu5
   const int nBin_HLT_BTagMu_DiJet20_Mu5 = 31;
   double ptBin_HLT_BTagMu_DiJet20_Mu5[nBin_HLT_BTagMu_DiJet20_Mu5] =
     {0,20,25,30,35,40,45,50,55,60,70,80,90,100,110,130,150,170,200,240,280,320,360,400,450,500,550,600,700,800,1000};
   hJetPtAll_HLT_BTagMu_DiJet20_Mu5 = new TH1D("hJetPtAll_HLT_BTagMu_DiJet20_Mu5",
					       "hJetPtAll_HLT_BTagMu_DiJet20_Mu5",
					       nBin_HLT_BTagMu_DiJet20_Mu5-1,
					       ptBin_HLT_BTagMu_DiJet20_Mu5);
   hJetPtAll_HLT_BTagMu_DiJet20_Mu5->Sumw2();   
   hJetPtPass_HLT_BTagMu_DiJet20_Mu5 = new TH1D("hJetPtPass_HLT_BTagMu_DiJet20_Mu5",
						"hJetPtPass_HLT_BTagMu_DiJet20_Mu5",
						nBin_HLT_BTagMu_DiJet20_Mu5-1,
						ptBin_HLT_BTagMu_DiJet20_Mu5);
   hJetPtPass_HLT_BTagMu_DiJet20_Mu5->Sumw2();

   // HLT_BTagMu_DiJet40_Mu5
   const int nBin_HLT_BTagMu_DiJet40_Mu5 = 31;
   double ptBin_HLT_BTagMu_DiJet40_Mu5[nBin_HLT_BTagMu_DiJet40_Mu5] =
     {0,20,25,30,35,40,45,50,55,60,70,80,90,100,110,130,150,170,200,240,280,320,360,400,450,500,550,600,700,800,1000};
   hJetPtAll_HLT_BTagMu_DiJet40_Mu5 = new TH1D("hJetPtAll_HLT_BTagMu_DiJet40_Mu5",
					       "hJetPtAll_HLT_BTagMu_DiJet40_Mu5",
					       nBin_HLT_BTagMu_DiJet40_Mu5-1,
					       ptBin_HLT_BTagMu_DiJet40_Mu5);
   hJetPtAll_HLT_BTagMu_DiJet40_Mu5->Sumw2();   
   hJetPtPass_HLT_BTagMu_DiJet40_Mu5 = new TH1D("hJetPtPass_HLT_BTagMu_DiJet40_Mu5",
						"hJetPtPass_HLT_BTagMu_DiJet40_Mu5",
						nBin_HLT_BTagMu_DiJet40_Mu5-1,
						ptBin_HLT_BTagMu_DiJet40_Mu5);
   hJetPtPass_HLT_BTagMu_DiJet40_Mu5->Sumw2();

   // HLT_BTagMu_DiJet70_Mu5
   const int nBin_HLT_BTagMu_DiJet70_Mu5 = 31;
   double ptBin_HLT_BTagMu_DiJet70_Mu5[nBin_HLT_BTagMu_DiJet70_Mu5] =
     {0,20,25,30,35,40,45,50,55,60,70,80,90,100,110,130,150,170,200,240,280,320,360,400,450,500,550,600,700,800,1000};
   hJetPtAll_HLT_BTagMu_DiJet70_Mu5 = new TH1D("hJetPtAll_HLT_BTagMu_DiJet70_Mu5",
					       "hJetPtAll_HLT_BTagMu_DiJet70_Mu5",
					       nBin_HLT_BTagMu_DiJet70_Mu5-1,
					       ptBin_HLT_BTagMu_DiJet70_Mu5);
   hJetPtAll_HLT_BTagMu_DiJet70_Mu5->Sumw2();   
   hJetPtPass_HLT_BTagMu_DiJet70_Mu5 = new TH1D("hJetPtPass_HLT_BTagMu_DiJet70_Mu5",
						"hJetPtPass_HLT_BTagMu_DiJet70_Mu5",
						nBin_HLT_BTagMu_DiJet70_Mu5-1,
						ptBin_HLT_BTagMu_DiJet70_Mu5);
   hJetPtPass_HLT_BTagMu_DiJet70_Mu5->Sumw2();

   // HLT_BTagMu_DiJet110_Mu5
   const int nBin_HLT_BTagMu_DiJet110_Mu5 = 31;
   double ptBin_HLT_BTagMu_DiJet110_Mu5[nBin_HLT_BTagMu_DiJet110_Mu5] =
     {0,20,25,30,35,40,45,50,55,60,70,80,90,100,110,130,150,170,200,240,280,320,360,400,450,500,550,600,700,800,1000};
   hJetPtAll_HLT_BTagMu_DiJet110_Mu5 = new TH1D("hJetPtAll_HLT_BTagMu_DiJet110_Mu5",
					       "hJetPtAll_HLT_BTagMu_DiJet110_Mu5",
					       nBin_HLT_BTagMu_DiJet110_Mu5-1,
					       ptBin_HLT_BTagMu_DiJet110_Mu5);
   hJetPtAll_HLT_BTagMu_DiJet110_Mu5->Sumw2();   
   hJetPtPass_HLT_BTagMu_DiJet110_Mu5 = new TH1D("hJetPtPass_HLT_BTagMu_DiJet110_Mu5",
						"hJetPtPass_HLT_BTagMu_DiJet110_Mu5",
						nBin_HLT_BTagMu_DiJet110_Mu5-1,
						ptBin_HLT_BTagMu_DiJet110_Mu5);
   hJetPtPass_HLT_BTagMu_DiJet110_Mu5->Sumw2();

   // HLT_BTagMu_Jet300_Mu5
   const int nBin_HLT_BTagMu_Jet300_Mu5 = 31;
   double ptBin_HLT_BTagMu_Jet300_Mu5[nBin_HLT_BTagMu_Jet300_Mu5] =
     {0,20,25,30,35,40,45,50,55,60,70,80,90,100,110,130,150,170,200,240,280,320,360,400,450,500,550,600,700,800,1000};
   hJetPtAll_HLT_BTagMu_Jet300_Mu5 = new TH1D("hJetPtAll_HLT_BTagMu_Jet300_Mu5",
					       "hJetPtAll_HLT_BTagMu_Jet300_Mu5",
					       nBin_HLT_BTagMu_Jet300_Mu5-1,
					       ptBin_HLT_BTagMu_Jet300_Mu5);
   hJetPtAll_HLT_BTagMu_Jet300_Mu5->Sumw2();
   hJetPtPass_HLT_BTagMu_Jet300_Mu5 = new TH1D("hJetPtPass_HLT_BTagMu_Jet300_Mu5",
						"hJetPtPass_HLT_BTagMu_Jet300_Mu5",
						nBin_HLT_BTagMu_Jet300_Mu5-1,
						ptBin_HLT_BTagMu_Jet300_Mu5);
   hJetPtPass_HLT_BTagMu_Jet300_Mu5->Sumw2();
   
   std::cout << "Initialisation done" << std::endl;
}

void LTANA::Trigger::fill()
{
   float pthat = ntP->pthat;

   double ran = rnd->Rndm();
   
   double w = 1.;
   
   if( !isdata )
     {	
	double w015 = 2323780/(1273190000*0.003);
	double w020 = 5280100/(558528000*0.0053);
	double w030 = 4965830/(139803000*0.01182);
	double w050 = 5080290/(19222500*0.02276);
	double w080 = 3887280/(2758420*0.03844);
	double w120 = 4021470/(469797*0.05362);
	double w170 = 3948330/(117989*0.07335);
	double w300 = 3932500/(7820.25*0.10196);
	double w470 = 1935850/(645.528*0.12242);
	double w600 = 1982670/(187.109*0.13412);
	double w800 = 1991700/(32.3486*0.14552);
	double w1000= 1./(1.);

	double ILexp = 1.;
	
	w015 = ILexp/w015;
	w020 = ILexp/w020;
	w030 = ILexp/w030;
	w050 = ILexp/w050;
	w080 = ILexp/w080;
	w120 = ILexp/w120;
	w170 = ILexp/w170;
	w300 = ILexp/w300;
	w470 = ILexp/w470;
	w600 = ILexp/w600;
	w800 = ILexp/w800;
	w1000 = ILexp/w1000;

	if( pthat >=  15. && pthat <  20. ) w = w015;
	else if ( pthat >=  20. && pthat <  30. ) w = w020;
	else if ( pthat >=  30. && pthat <  50. ) w = w030;
	else if ( pthat >=  50. && pthat <  80. ) w = w050;
	else if ( pthat >=  80. && pthat < 120. ) w = w080;
	else if ( pthat >= 120. && pthat < 170. ) w = w120;
	else if ( pthat >= 170. && pthat < 300. ) w = w170;
	else if ( pthat >= 300. && pthat < 470. ) w = w300;
	else if ( pthat >= 470. && pthat < 600. ) w = w470;
	else if ( pthat >= 600. && pthat < 800. ) w = w600;
	else if ( pthat >= 800. && pthat < 1000.) w = w800;
	else if ( pthat >= 1000. )                w = w1000;	
     }   
   
   float mc_weight = ntP->mcweight;
   if( !isdata ) w *= mc_weight;
   
   int npu = ntP->nPU;
   int npv = ntP->nPV;
   if( npu > 34 ) npu = 34;

   int ntNJET = ntP->nJet;

   // Trigger
   
   bool passTrigJet20 = passTrig(35);
   bool passTrigJet40 = passTrig(41);
   bool passTrigJet70 = passTrig(44);
   bool passTrigJet110 = passTrig(47);
   bool passTrigJet300 = passTrig(50);
   
   // Loop on jets

   for(int ij=0;ij<ntNJET;ij++)
     {
	if( ij != 0 ) continue;
	
	float jetPt = ntP->Jet_pt[ij];
	
	hJetPtAll_HLT_BTagMu_DiJet20_Mu5->Fill(jetPt);
	if( passTrigJet20 ) hJetPtPass_HLT_BTagMu_DiJet20_Mu5->Fill(jetPt);

	hJetPtAll_HLT_BTagMu_DiJet40_Mu5->Fill(jetPt);
	if( passTrigJet40 ) hJetPtPass_HLT_BTagMu_DiJet40_Mu5->Fill(jetPt);

	hJetPtAll_HLT_BTagMu_DiJet70_Mu5->Fill(jetPt);
	if( passTrigJet70 ) hJetPtPass_HLT_BTagMu_DiJet70_Mu5->Fill(jetPt);

	hJetPtAll_HLT_BTagMu_DiJet110_Mu5->Fill(jetPt);
	if( passTrigJet110 ) hJetPtPass_HLT_BTagMu_DiJet110_Mu5->Fill(jetPt);

	hJetPtAll_HLT_BTagMu_Jet300_Mu5->Fill(jetPt);
	if( passTrigJet300 ) hJetPtPass_HLT_BTagMu_Jet300_Mu5->Fill(jetPt);
     }   
}

void LTANA::Trigger::close()
{
   _fout->Write();
   _fout->Close();
}

bool LTANA::Trigger::passTrig(int trigIdx)
{
   int bitIdx = trigIdx/32;
   if ( ntP->BitTrigger[bitIdx] & ( 1 << (trigIdx - bitIdx*32) ) ) return true;
   else return false;
}
