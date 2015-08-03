#include <memory>
#include <iostream>
#include <sstream>

#include "FWCore/Common/interface/TriggerNames.h"
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/PatCandidates/interface/PackedTriggerPrescales.h"
#include "DataFormats/PatCandidates/interface/TriggerObjectStandAlone.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "Trigger/TrigTreeProducer/interface/Tree.hh"

#include "DataFormats/PatCandidates/interface/Jet.h"

#include "TROOT.h"
#include "Compression.h"

class TrigMatching : public edm::EDAnalyzer
{
   
 public:
   
   explicit TrigMatching(const edm::ParameterSet&);
   ~TrigMatching();
   
   static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
   
 private:
   
   virtual void beginJob() override;
   virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
   virtual void endJob() override;
   
   Tree* ftree;
   const edm::Service<TFileService> fs;
   
   TH1D* hcount;
   TH1D* hweight;

   std::string dataFormat_;
   bool isData_;

   edm::EDGetTokenT<edm::TriggerResults> triggerBits_;
   edm::EDGetTokenT<pat::TriggerObjectStandAloneCollection> triggerObjects_;
   edm::EDGetTokenT<pat::PackedTriggerPrescales> triggerPrescales_;
   std::vector<std::string> triggerNames_;
   edm::EDGetTokenT<pat::JetCollection> jetInput_;
};

TrigMatching::TrigMatching(const edm::ParameterSet& iConfig)
{
   TFile& f = fs->file();
   f.SetCompressionAlgorithm(ROOT::kZLIB);
   f.SetCompressionLevel(9);
   ftree = new Tree(fs->make<TTree>("tree","tree"));

   isData_            = iConfig.getParameter<bool>("isData");
   triggerBits_       = consumes<edm::TriggerResults>(iConfig.getParameter<edm::InputTag>("triggerBits"));
   triggerObjects_    = consumes<pat::TriggerObjectStandAloneCollection>(iConfig.getParameter<edm::InputTag>("triggerObjects"));
   triggerPrescales_  = consumes<pat::PackedTriggerPrescales>(iConfig.getParameter<edm::InputTag>("triggerPrescales"));
   triggerNames_      = iConfig.getParameter<std::vector<std::string > >("triggerNames");
   jetInput_          = consumes<pat::JetCollection>(iConfig.getParameter<edm::InputTag>("jetInput"));

   ftree->CreateBranches();
   
   hcount = fs->make<TH1D>("hcount","hcount",1,0.,1.);
   hweight = fs->make<TH1D>("hweight","hweight",1,0.,1.);
}

TrigMatching::~TrigMatching()
{
}

void TrigMatching::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   hcount->SetBinContent(1,hcount->GetBinContent(1)+1);

   ftree->Init();

   
//   ftree->ev_run = iEvent.id().run();
//   ftree->ev_id = iEvent.id().event();
//   ftree->ev_lumi = iEvent.id().luminosityBlock();
   
//   float mc_weight = 1.;
   
/*   if( genEventInfo.isValid() )
     {	
	mc_weight = genEventInfo->weight();
	ftree->mc_id = genEventInfo->signalProcessID();
	ftree->mc_f1 = genEventInfo->pdf()->id.first;
	ftree->mc_f2 = genEventInfo->pdf()->id.second;
	ftree->mc_x1 = genEventInfo->pdf()->x.first;
	ftree->mc_x2 = genEventInfo->pdf()->x.second;
	ftree->mc_scale = genEventInfo->pdf()->scalePDF;
	if( genEventInfo->binningValues().size() > 0 ) ftree->mc_ptHat = genEventInfo->binningValues()[0];
     }
   
   ftree->mc_weight = mc_weight;
   
   hweight->SetBinContent(1,hweight->GetBinContent(1)+ftree->mc_weight);
*/   

   edm::Handle<edm::TriggerResults> triggerBits;
   edm::Handle<pat::TriggerObjectStandAloneCollection> triggerObjects;
   edm::Handle<pat::PackedTriggerPrescales> triggerPrescales;
   edm::Handle<pat::JetCollection> jets;

   iEvent.getByToken(triggerBits_, triggerBits);
   iEvent.getByToken(triggerObjects_, triggerObjects);
   iEvent.getByToken(triggerPrescales_, triggerPrescales);
   iEvent.getByToken(jetInput_,jets);

   // Trigger
   
   const edm::TriggerNames &names = iEvent.triggerNames(*triggerBits);

   int nTrig = triggerNames_.size();
   
   for(int itr=0;itr<nTrig;itr++)
     {	
	float trigPS = -1;
	int trigPass = -1;
	bool found = 0;
   
	std::string triggerName = triggerNames_[itr];
	
	int nTriggerBits = triggerBits->size();
	for(int itb=0;itb<nTriggerBits;itb++)
	  {
	     std::string trigName = names.triggerName(itb);
	     trigPS = triggerPrescales->getPrescaleForIndex(itb);
	     trigPass = triggerBits->accept(itb);
	     
	     if( strcmp(trigName.c_str(),triggerName.c_str()) == 0 )
	       {
		  trigPS = triggerPrescales->getPrescaleForIndex(itb);
		  trigPass = triggerBits->accept(itb);
		  found = 1;
		  break;
	       }	
	  }
	
	ftree->trigID.push_back(itr);
	ftree->trigPS.push_back(trigPS);
	ftree->trigPass.push_back(trigPass);
 
	int objN = 0;

	std::vector<float> objPt;
	std::vector<float> objEta;
	std::vector<float> objPhi;
	
	if( found )
	  {	     
	     for(pat::TriggerObjectStandAlone obj : *triggerObjects) 
	       {
		  obj.unpackPathNames(names);
		  
		  bool isL3 = obj.hasPathName(triggerName.c_str(),false,true);
		  if( isL3 )
		    {		  
		       float pt = obj.pt();
		       float eta = obj.eta();	
		       float phi = obj.phi();
		       
		       objPt.push_back(pt);
		       objEta.push_back(eta);
		       objPhi.push_back(phi);
		       
		       objN++;
		    }	     
	       }
	  }	
	
	ftree->objN.push_back(objN);
	ftree->objPt.push_back(objPt);
	ftree->objEta.push_back(objEta);
	ftree->objPhi.push_back(objPhi);
     }
   
   // Jets
   
   int jetN = jets->size();
   
   ftree->jetN = jetN;
   
   for(int ij=0;ij<jetN;ij++)
     {	
//	float pt = jets->at(ij).pt();
	
//	ftree->objN.push_back(objN);
     }   
   
/*   std::cout << "\n === TRIGGER OBJECTS === " << std::endl;
   for(pat::TriggerObjectStandAlone obj : *triggerObjects)
     {
	obj.unpackPathNames(names);
	std::cout << "\tTrigger object:  pt " << obj.pt() << ", eta " << obj.eta() << ", phi " << obj.phi() << std::endl;
	// Print trigger object collection and type
	std::cout << "\t   Collection: " << obj.collection() << std::endl;
	std::cout << "\t   Type IDs:   ";
	for (unsigned h = 0; h < obj.filterIds().size(); ++h) std::cout << " " << obj.filterIds()[h] ;
	std::cout << std::endl;
	// Print associated trigger filters
	std::cout << "\t   Filters:    ";
	for (unsigned h = 0; h < obj.filterLabels().size(); ++h) std::cout << " " << obj.filterLabels()[h];
	std::cout << std::endl;
	std::vector<std::string> pathNamesAll  = obj.pathNames(false);
	std::vector<std::string> pathNamesLast = obj.pathNames(true);
	// Print all trigger paths, for each one record also if the object is associated to a 'l3' filter (always true for the
	// definition used in the PAT trigger producer) and if it's associated to the last filter of a successfull path (which
	// means that this object did cause this trigger to succeed; however, it doesn't work on some multi-object triggers)
	std::cout << "\t   Paths (" << pathNamesAll.size()<<"/"<<pathNamesLast.size()<<"):    ";
	for (unsigned h = 0, n = pathNamesAll.size(); h < n; ++h) {
	   bool isBoth = obj.hasPathName( pathNamesAll[h], true, true );
	   bool isL3   = obj.hasPathName( pathNamesAll[h], false, true ); 
	   bool isLF   = obj.hasPathName( pathNamesAll[h], true, false ); 
	   bool isNone = obj.hasPathName( pathNamesAll[h], false, false ); 
	   std::cout << "   " << pathNamesAll[h];
	   if (isBoth) std::cout << "(L,3)";
	   if (isL3 && !isBoth) std::cout << "(*,3)";
	   if (isLF && !isBoth) std::cout << "(L,*)";
	   if (isNone && !isBoth && !isL3 && !isLF) std::cout << "(*,*)";
	}
	std::cout << std::endl;
     }
   std::cout << std::endl;*/

   // Fill the output tree
   ftree->tr->Fill();
}

void TrigMatching::beginJob()
{
}

void TrigMatching::endJob()
{
}

void TrigMatching::fillDescriptions(edm::ConfigurationDescriptions& descriptions)
{
   //The following says we do not know what parameters are allowed so do no validation
   // Please change this to state exactly what you do use, even if it is no parameters
   edm::ParameterSetDescription desc;
   desc.setUnknown();
   descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(TrigMatching);

