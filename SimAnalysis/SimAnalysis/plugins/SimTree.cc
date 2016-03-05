#include "SimAnalysis/SimAnalysis/interface/SimTree.hh"

void SimTree::Init()
{
   primVtxX.clear();
   primVtxY.clear();
   primVtxZ.clear();
   
   momId.clear();
   momPt.clear();
   momEta.clear();
   
   muR.clear();
   muRpv.clear();
   muPosX.clear();
   muPosY.clear();
   muPosZ.clear();
   muPt.clear();
   muEta.clear();
   muStatus.clear();

   muSimPt.clear();
   muSimEta.clear();
   muSimR.clear();
   muSimRpv.clear();
   muSimPosX.clear();
   muSimPosY.clear();
   muSimPosZ.clear();   
   
   partonId.clear();
   partonPt.clear();
   partonEta.clear();

/*   momGenId.clear();
   momGenPt.clear();
   momGenEta.clear();
   
   muGenPt.clear();
   muGenEta.clear();

   partonGenId.clear();
   partonGenPt.clear();
   partonGenEta.clear();*/
}

void SimTree::CreateBranches(int buffersize = 32000)
{
   tree->Branch("primVtxX", "std::vector<float>", &primVtxX, buffersize);
   tree->Branch("primVtxY", "std::vector<float>", &primVtxY, buffersize);
   tree->Branch("primVtxZ", "std::vector<float>", &primVtxZ, buffersize);
   
   tree->Branch("momId", "std::vector<int>", &momId, buffersize);
   tree->Branch("momPt", "std::vector<float>", &momPt, buffersize);
   tree->Branch("momEta", "std::vector<float>", &momEta, buffersize);
   
   tree->Branch("muR", "std::vector<float>", &muR, buffersize);
   tree->Branch("muRpv", "std::vector<float>", &muRpv, buffersize);
   tree->Branch("muPosX", "std::vector<float>", &muPosX, buffersize);
   tree->Branch("muPosY", "std::vector<float>", &muPosY, buffersize);
   tree->Branch("muPosZ", "std::vector<float>", &muPosZ, buffersize);
   tree->Branch("muPt", "std::vector<float>", &muPt, buffersize);
   tree->Branch("muEta", "std::vector<float>", &muEta, buffersize);
   tree->Branch("muStatus", "std::vector<int>", &muStatus, buffersize);

   tree->Branch("muSimR", "std::vector<float>", &muSimR, buffersize);
   tree->Branch("muSimRpv", "std::vector<float>", &muSimRpv, buffersize);
   tree->Branch("muSimPosX", "std::vector<float>", &muSimPosX, buffersize);
   tree->Branch("muSimPosY", "std::vector<float>", &muSimPosY, buffersize);
   tree->Branch("muSimPosZ", "std::vector<float>", &muSimPosZ, buffersize);
   tree->Branch("muSimPt", "std::vector<float>", &muSimPt, buffersize);
   tree->Branch("muSimEta", "std::vector<float>", &muSimEta, buffersize);
   
   tree->Branch("partonId", "std::vector<int>", &partonId, buffersize);
   tree->Branch("partonPt", "std::vector<float>", &partonPt, buffersize);
   tree->Branch("partonEta", "std::vector<float>", &partonEta, buffersize);

/*   tree->Branch("momGenId", "std::vector<int>", &momGenId, buffersize);
   tree->Branch("momGenPt", "std::vector<float>", &momGenPt, buffersize);
   tree->Branch("momGenEta", "std::vector<float>", &momGenEta, buffersize);
   
   tree->Branch("muGenPt", "std::vector<float>", &muGenPt, buffersize);
   tree->Branch("muGenEta", "std::vector<float>", &muGenEta, buffersize);

   tree->Branch("partonGenId", "std::vector<int>", &partonGenId, buffersize);
   tree->Branch("partonGenPt", "std::vector<float>", &partonGenPt, buffersize);
   tree->Branch("partonGenEta", "std::vector<float>", &partonGenEta, buffersize);*/
}
