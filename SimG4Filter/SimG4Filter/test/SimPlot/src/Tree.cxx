#include "../include/Tree.h"

SIMPLOT::Tree::Tree(TChain *ch,char *fname,std::string treename)
{
   ch = new TChain(treename.c_str());
   
   std::ifstream infile;
   infile.open(fname);
   std::string ifile = "";
   while( getline(infile, ifile) )
     {	
	std::string fnameStr = std::string(ifile);

	ch->Add(fnameStr.c_str());
	std::cout << "file: " << fnameStr << std::endl;
     }   
   infile.close();
   Init(ch);
}

SIMPLOT::Tree::~Tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t SIMPLOT::Tree::GetEntry(Long64_t entry)
{
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t SIMPLOT::Tree::LoadTree(Long64_t entry)
{
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}

void SIMPLOT::Tree::registerInputBranches(TChain *tr)
{
   tr->SetBranchStatus("*",1);
   
   std::cout << "Successfully initialized input branches" << std::endl;
}

void SIMPLOT::Tree::Init(TChain *tree)
{
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;

   simTrkId = 0;
   simTrkPt = 0;
   simTrkEta = 0;
   simTrkPhi = 0;

   nSimHitRPC = 0;
   nSimHitCSC = 0;
   nSimHitDT = 0;

   nSimHitRPCRECO = 0;
   nSimHitRPC2RECO = 0;
   nSimHitCSCStripRECO = 0;
   nSimHitCSCWireRECO = 0;
   nSimHitDTRECO = 0;
   
   muGenPt = 0;
   muGenEta = 0;
   muGenPhi = 0;
   muGenStatus = 0;

   muRecPt = 0;
   muRecEta = 0;
   muRecPhi = 0;
   muRecNumberOfValidMuonRPCHits = 0;
   muRecNumberOfValidMuonCSCHits = 0;
   muRecNumberOfValidMuonDTHits = 0;
   muRecNumberOfValidMuonHits = 0;
   muRecNumberOfMatches = 0;
   muRecNumberOfValidHits = 0;
   muRecNumberOfValidPixelHits = 0;
   muRecNumberOfHits = 0;
   muRecNormalizedChi2GlobalTrack = 0;
   muRecNormalizedChi2InnerTrack = 0;
   
   fChain->SetBranchAddress("simTrkId", &simTrkId, &b_simTrkId);
   fChain->SetBranchAddress("simTrkPt", &simTrkPt, &b_simTrkPt);
   fChain->SetBranchAddress("simTrkEta", &simTrkEta, &b_simTrkEta);
   fChain->SetBranchAddress("simTrkPhi", &simTrkPhi, &b_simTrkPhi);
   
   fChain->SetBranchAddress("nSimHitRPC", &nSimHitRPC, &b_nSimHitRPC);
   fChain->SetBranchAddress("nSimHitCSC", &nSimHitCSC, &b_nSimHitCSC);
   fChain->SetBranchAddress("nSimHitDT", &nSimHitDT, &b_nSimHitDT);
   
   fChain->SetBranchAddress("nSimHitRPCRECO", &nSimHitRPCRECO, &b_nSimHitRPCRECO);
   fChain->SetBranchAddress("nSimHitRPC2RECO", &nSimHitRPC2RECO, &b_nSimHitRPC2RECO);
   fChain->SetBranchAddress("nSimHitCSCStripRECO", &nSimHitCSCStripRECO, &b_nSimHitCSCStripRECO);
   fChain->SetBranchAddress("nSimHitCSCWireRECO", &nSimHitCSCWireRECO, &b_nSimHitCSCWireRECO);
   fChain->SetBranchAddress("nSimHitDTRECO", &nSimHitDTRECO, &b_nSimHitDTRECO);
   
   fChain->SetBranchAddress("muGenPt", &muGenPt, &b_muGenPt);
   fChain->SetBranchAddress("muGenEta", &muGenEta, &b_muGenEta);
   fChain->SetBranchAddress("muGenPhi", &muGenPhi, &b_muGenPhi);
   fChain->SetBranchAddress("muGenStatus", &muGenStatus, &b_muGenStatus);

   fChain->SetBranchAddress("muRecPt", &muRecPt, &b_muRecPt);
   fChain->SetBranchAddress("muRecEta", &muRecEta, &b_muRecEta);
   fChain->SetBranchAddress("muRecPhi", &muRecPhi, &b_muRecPhi);
   fChain->SetBranchAddress("muRecNumberOfValidMuonRPCHits", &muRecNumberOfValidMuonRPCHits, &b_muRecNumberOfValidMuonRPCHits);
   fChain->SetBranchAddress("muRecNumberOfValidMuonCSCHits", &muRecNumberOfValidMuonCSCHits, &b_muRecNumberOfValidMuonCSCHits);
   fChain->SetBranchAddress("muRecNumberOfValidMuonDTHits", &muRecNumberOfValidMuonDTHits, &b_muRecNumberOfValidMuonDTHits);
   fChain->SetBranchAddress("muRecNumberOfValidMuonHits", &muRecNumberOfValidMuonHits, &b_muRecNumberOfValidMuonHits);
   fChain->SetBranchAddress("muRecNumberOfMatches", &muRecNumberOfMatches, &b_muRecNumberOfMatches);
   fChain->SetBranchAddress("muRecNumberOfValidHits", &muRecNumberOfValidHits, &b_muRecNumberOfValidHits);
   fChain->SetBranchAddress("muRecNumberOfValidPixelHits", &muRecNumberOfValidPixelHits, &b_muRecNumberOfValidPixelHits);
   fChain->SetBranchAddress("muRecNumberOfHits", &muRecNumberOfHits, &b_muRecNumberOfHits);
   fChain->SetBranchAddress("muRecNormalizedChi2GlobalTrack", &muRecNormalizedChi2GlobalTrack, &b_muRecNormalizedChi2GlobalTrack);
   fChain->SetBranchAddress("muRecNormalizedChi2InnerTrack", &muRecNormalizedChi2InnerTrack, &b_muRecNormalizedChi2InnerTrack);
}
