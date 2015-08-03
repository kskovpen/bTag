#include "Trigger/TrigTreeProducer/interface/Tree.hh"

void Tree::Init()
{
   trigID.clear();
   trigPass.clear();
   trigPS.clear();
   
   objN.clear();
   objPt.clear();
   objEta.clear();
   objPhi.clear();
   
   jetN = DEFVAL;
}

void Tree::CreateBranches()
{
   tr->Branch("trigID","std::vector<int>",&trigID,32000);
   tr->Branch("trigPass","std::vector<int>",&trigPass,32000);
   tr->Branch("trigPS","std::vector<float>",&trigPS,32000);
   
   tr->Branch("objN","std::vector<int>",&objN,32000);
   tr->Branch("objPt","std::vector<std::vector<float> >",&objPt,32000);
   tr->Branch("objEta","std::vector<std::vector<float> >",&objEta,32000);
   tr->Branch("objPhi","std::vector<std::vector<float> >",&objPhi,32000);
   
   tr->Branch("jetN",&jetN,"jetN/I",32000);
}
