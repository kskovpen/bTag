#include <vector>
#include <fstream>
#include <iostream>
#include <utility>

void grepEventFireworks()
{
   gROOT->SetBatch(1);

   int eventId, runId, lumiId;
   float j1Pt, j2Pt;
   
   TFile *f = TFile::Open("histFIREWORKS_MERGED/Run2015B_BTagMu_JPCalib/data.root");
   TTree *tr = (TTree*)f->Get("EventTree");
   tr->SetBranchAddress("eventId",&eventId);
   tr->SetBranchAddress("runId",&runId);
   tr->SetBranchAddress("lumiId",&lumiId);
   tr->SetBranchAddress("j1Pt",&j1Pt);
   tr->SetBranchAddress("j2Pt",&j2Pt);
   
   int nEvt = tr->GetEntries();
   
   std::ofstream fout("eventFireworks.txt");
   
   std::vector<float> evList;
   std::vector<int> runList;
   std::vector<int> eventList;
   std::vector<int> lumiList;
   std::vector<float> j1PtList;
   std::vector<float> j2PtList;
   
   for(int i=0;i<nEvt;i++)
     {       
	tr->GetEntry(i);
	
	float par = (j1Pt+j2Pt);
	
	evList.push_back(par);
	eventList.push_back(eventId);
	runList.push_back(runId);
	lumiList.push_back(lumiId);
	j1PtList.push_back(j1Pt);
	j2PtList.push_back(j2Pt);
     }
   std::vector<float> evListUNSORT = evList;
   
   std::sort(evList.begin(),evList.end(),std::greater<float>());
      
   std::vector<int> idx;
   
   for(int i=0;i<evList.size();i++)
     {
	int idxNEW = -1;
	for(int j=0;j<evListUNSORT.size();j++)
	  {
	     if( evList[i] == evListUNSORT[j] )
	       {
		  idx.push_back(j);
		  idxNEW = j;
		  break;
	       }	     
	  }	
	if( idxNEW == -1 )
	  {
	     std::cout << "Wrong procedure !" << std::endl;
	     exit(1);
	  }	
     }
   
   for(int i=0;i<idx.size();i++)
     {	
	int id = idx[i];
	std::cout <<
	  runList[id] <<
	  ":" << lumiList[id] << 
	  ":" << eventList[id] << std::endl;
//	  " j1Pt = " << j1PtList[id] <<
//	  " j2Pt = " << j2PtList[id] << std::endl;
     }   
	  
   fout.close();
   
   f->Close();
   
   gApplication->Terminate();   
}
