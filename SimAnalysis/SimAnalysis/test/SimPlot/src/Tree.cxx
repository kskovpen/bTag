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

   momId = 0;
   muPt = 0;
   muEta = 0;
   muStatus = 0;
   partonId = 0;

   muPosX = 0;
   muPosY = 0;
   muPosZ = 0;
   muRpv = 0;

   muSimPosX = 0;
   muSimPosY = 0;
   muSimPosZ = 0;
   muSimRpv = 0;
   
   muSimPt = 0;
   muSimEta = 0;
   
   fChain->SetBranchAddress("momId", &momId, &b_momId);
   fChain->SetBranchAddress("muPt", &muPt, &b_muPt);
   fChain->SetBranchAddress("muEta", &muEta, &b_muEta);
   fChain->SetBranchAddress("muStatus", &muStatus, &b_muStatus);
   fChain->SetBranchAddress("partonId", &partonId, &b_partonId);

   fChain->SetBranchAddress("muPosX", &muPosX, &b_muPosX);
   fChain->SetBranchAddress("muPosY", &muPosY, &b_muPosY);
   fChain->SetBranchAddress("muPosZ", &muPosZ, &b_muPosZ);
   fChain->SetBranchAddress("muRpv", &muRpv, &b_muRpv);

   fChain->SetBranchAddress("muSimPosX", &muSimPosX, &b_muSimPosX);
   fChain->SetBranchAddress("muSimPosY", &muSimPosY, &b_muSimPosY);
   fChain->SetBranchAddress("muSimPosZ", &muSimPosZ, &b_muSimPosZ);
   fChain->SetBranchAddress("muSimRpv", &muSimRpv, &b_muSimRpv);
   
   fChain->SetBranchAddress("muSimPt", &muSimPt, &b_muSimPt);
   fChain->SetBranchAddress("muSimEta", &muSimEta, &b_muSimEta);
}
