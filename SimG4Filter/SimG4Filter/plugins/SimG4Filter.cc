#include <memory>
#include <iostream>
#include <sstream>

#include "TRegexp.h"
#include "TString.h"
#include "Compression.h"

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "CLHEP/Units/GlobalSystemOfUnits.h"

#include "SimGeneral/HepPDTRecord/interface/ParticleDataTable.h"
#include "SimDataFormats/Vertex/interface/SimVertex.h"
#include "SimDataFormats/Track/interface/SimTrack.h"
#include "SimDataFormats/Track/interface/SimTrackContainer.h"
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/MuonReco/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "DataFormats/MuonDetId/interface/CSCDetId.h"
#include "DataFormats/MuonDetId/interface/DTChamberId.h"

#include "Geometry/Records/interface/MuonGeometryRecord.h"
#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/CSCGeometry/interface/CSCGeometry.h"
#include "Geometry/DTGeometry/interface/DTGeometry.h"

#include "SimDataFormats/TrackingHit/interface/PSimHitContainer.h"

#include "SimDataFormats/RPCDigiSimLink/interface/RPCDigiSimLink.h"
#include "SimDataFormats/TrackerDigiSimLink/interface/StripDigiSimLink.h"
#include "SimDataFormats/DigiSimLinks/interface/DTDigiSimLink.h"
#include "SimDataFormats/DigiSimLinks/interface/DTDigiSimLinkCollection.h"

#include "DataFormats/Common/interface/DetSetVector.h"

#include "SimG4Filter/SimG4Filter/interface/SimTree.hh"

class SimG4Filter : public edm::EDAnalyzer
{
 public:

   explicit SimG4Filter(const edm::ParameterSet&);
   ~SimG4Filter();

   static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);
   
   float DeltaR(float eta1,float phi1,float eta2,float phi2);

 private:

   virtual void analyze(const edm::Event&, const edm::EventSetup&) override;

   virtual void beginRun(const edm::Run&, const edm::EventSetup&) override;
   virtual void endRun(const edm::Run&, const edm::EventSetup&) override;
   
   edm::EDGetTokenT<std::vector<SimTrack> > simTracksToken_;
   edm::EDGetTokenT<edm::PSimHitContainer> simHitsMuonRPCToken_;
   edm::EDGetTokenT<edm::PSimHitContainer> simHitsMuonCSCToken_;
   edm::EDGetTokenT<edm::PSimHitContainer> simHitsMuonDTToken_;
   edm::EDGetTokenT<edm::DetSetVector<RPCDigiSimLink> > RPCDigiSimLinkToken_;
   edm::EDGetTokenT<edm::DetSetVector<StripDigiSimLink> > CSCStripDigiSimLinkToken_;
   edm::EDGetTokenT<edm::DetSetVector<StripDigiSimLink> > CSCWireDigiSimLinkToken_;
   edm::EDGetTokenT<MuonDigiCollection<DTLayerId,DTDigiSimLink> > DTDigiSimLinkToken_;
   edm::EDGetTokenT<std::vector<reco::Muon> > recoMuonToken_;
   edm::EDGetTokenT<std::vector<reco::GenParticle> > genParticlesToken_;
   
   edm::ESHandle<HepPDT::ParticleDataTable> pdt;
   
   edm::Handle<std::vector<SimTrack> > simTracksHandle;
   edm::Handle<edm::PSimHitContainer> simHitsMuonRPCHandle;
   edm::Handle<edm::PSimHitContainer> simHitsMuonCSCHandle;
   edm::Handle<edm::PSimHitContainer> simHitsMuonDTHandle;
   edm::Handle<edm::DetSetVector<RPCDigiSimLink> > RPCDigiSimLinkHandle;
   edm::Handle<edm::DetSetVector<StripDigiSimLink> > CSCStripDigiSimLinkHandle;
   edm::Handle<edm::DetSetVector<StripDigiSimLink> > CSCWireDigiSimLinkHandle;
   edm::Handle<MuonDigiCollection<DTLayerId,DTDigiSimLink> > DTDigiSimLinkHandle;
   edm::Handle<std::vector<reco::Muon> > recoMuonHandle;

   edm::ESHandle<RPCGeometry> theRPCGeomESH;
   edm::ESHandle<CSCGeometry> theCSCGeomESH;
   edm::ESHandle<DTGeometry> theDTGeomESH;
   
   SimTree *ftree;

   bool runOnRECO_;
   
   TH1F *hcount;
   
   const edm::Service<TFileService> fs;
};

SimG4Filter::SimG4Filter(const edm::ParameterSet& iConfig)
{
   simTracksToken_    = consumes<std::vector<SimTrack> >(iConfig.getParameter<edm::InputTag>("simTracksInput"));
   simHitsMuonRPCToken_ = consumes<edm::PSimHitContainer>(iConfig.getParameter<edm::InputTag>("simHitsMuonRPCInput"));
   simHitsMuonCSCToken_ = consumes<edm::PSimHitContainer>(iConfig.getParameter<edm::InputTag>("simHitsMuonCSCInput"));
   simHitsMuonDTToken_ = consumes<edm::PSimHitContainer>(iConfig.getParameter<edm::InputTag>("simHitsMuonDTInput"));
   RPCDigiSimLinkToken_ = consumes<edm::DetSetVector<RPCDigiSimLink> >(iConfig.getParameter<edm::InputTag>("RPCDigiSimLinkInput"));
   CSCStripDigiSimLinkToken_ = consumes<edm::DetSetVector<StripDigiSimLink> >(iConfig.getParameter<edm::InputTag>("CSCStripDigiSimLinkInput"));
   CSCWireDigiSimLinkToken_ = consumes<edm::DetSetVector<StripDigiSimLink> >(iConfig.getParameter<edm::InputTag>("CSCWireDigiSimLinkInput"));
   DTDigiSimLinkToken_ = consumes<MuonDigiCollection<DTLayerId,DTDigiSimLink> >(iConfig.getParameter<edm::InputTag>("DTDigiSimLinkInput"));
   recoMuonToken_    = consumes<std::vector<reco::Muon> >(iConfig.getParameter<edm::InputTag>("recoMuonInput"));
   genParticlesToken_    = consumes<std::vector<reco::GenParticle> >(iConfig.getParameter<edm::InputTag>("genParticlesInput"));

   runOnRECO_ = iConfig.getParameter<bool>("runOnRECO");
   
   TFile& f = fs->file();   
   f.SetCompressionAlgorithm(ROOT::kZLIB);
   f.SetCompressionLevel(9);
   ftree = new SimTree(fs->make<TTree>("tree","tree"));   
   ftree->CreateBranches(32000);
   
   hcount = fs->make<TH1F>("hcount","hcount",1,0.,1.);
}

SimG4Filter::~SimG4Filter()
{
}

void SimG4Filter::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   hcount->SetBinContent(1,hcount->GetBinContent(1)+1);
   
   ftree->Init();

   iEvent.getByToken(simTracksToken_,simTracksHandle);

   edm::Handle<std::vector<reco::GenParticle> > genParticlesHandle;
   iEvent.getByToken(genParticlesToken_,genParticlesHandle);
   
   if( !runOnRECO_ )
     {	   
	iEvent.getByToken(simHitsMuonRPCToken_,simHitsMuonRPCHandle);
	iEvent.getByToken(simHitsMuonCSCToken_,simHitsMuonCSCHandle);
	iEvent.getByToken(simHitsMuonDTToken_,simHitsMuonDTHandle);
     }   
   else
     {	
	iEvent.getByToken(RPCDigiSimLinkToken_,RPCDigiSimLinkHandle);
	iEvent.getByToken(CSCStripDigiSimLinkToken_,CSCStripDigiSimLinkHandle);
	iEvent.getByToken(CSCWireDigiSimLinkToken_,CSCWireDigiSimLinkHandle);
	iEvent.getByToken(DTDigiSimLinkToken_,DTDigiSimLinkHandle);
	
	iEvent.getByToken(recoMuonToken_,recoMuonHandle);
     }   
      
   const std::vector<SimTrack> &simTracks = *simTracksHandle.product();
      
   const std::vector<reco::Muon> &recoMuons = *recoMuonHandle.product();
   
   const std::vector<reco::GenParticle> &genParticles = *genParticlesHandle.product();
   
   int nRecoMuons = (runOnRECO_) ? recoMuons.size() : 0;
   
   int nTracks = simTracks.size();

   int nGenParticles = genParticles.size();
   
   for(int ip=0;ip<nGenParticles;ip++)
     {	
	reco::GenParticle part = genParticles[ip];
	
	int partId = part.pdgId();
	float partPt = part.pt();
	
	if( abs(partId) == 13 )
	  {
	     float muPt = partPt;
	     float muEta = part.eta();
	     float muPhi = part.phi();
	     int muStatus = part.status();
	     int muId = partId;
	     
	     ftree->muGenPt.push_back(muPt);
	     ftree->muGenEta.push_back(muEta);
	     ftree->muGenPhi.push_back(muPhi);
	     ftree->muGenStatus.push_back(muStatus);
	     ftree->muGenId.push_back(muId);
	  }	
     }   

   if( runOnRECO_ )
     {	     
	for(int im=0;im<nRecoMuons;im++)
	  {		  
	     reco::Muon muon = recoMuons[im];
	     
	     float pt = muon.pt();
	     float eta = muon.eta();
	     float phi = muon.phi();
	     
	     bool isPFMuon = muon.isPFMuon();
	     bool isGlobalMuon = muon.isGlobalMuon();
	     
	     if( !isPFMuon || !isGlobalMuon ) continue;
	     
	     ftree->muRecPt.push_back(pt);
	     ftree->muRecEta.push_back(eta);
	     ftree->muRecPhi.push_back(phi);
	     ftree->muRecNumberOfValidMuonRPCHits.push_back(muon.globalTrack()->hitPattern().numberOfValidMuonRPCHits());
	     ftree->muRecNumberOfValidMuonCSCHits.push_back(muon.globalTrack()->hitPattern().numberOfValidMuonCSCHits());
	     ftree->muRecNumberOfValidMuonDTHits.push_back(muon.globalTrack()->hitPattern().numberOfValidMuonDTHits());
	     ftree->muRecNumberOfValidMuonHits.push_back(muon.outerTrack()->hitPattern().numberOfValidMuonHits());
	     ftree->muRecNumberOfMatches.push_back(muon.numberOfMatches());
	     ftree->muRecNumberOfValidHits.push_back(muon.innerTrack()->hitPattern().numberOfValidHits());
	     ftree->muRecNumberOfValidPixelHits.push_back(muon.innerTrack()->hitPattern().numberOfValidPixelHits());
	     ftree->muRecNumberOfHits.push_back(muon.innerTrack()->hitPattern().numberOfHits(reco::HitPattern::MISSING_OUTER_HITS));
	     ftree->muRecNormalizedChi2GlobalTrack.push_back(muon.globalTrack()->normalizedChi2());
	     ftree->muRecNormalizedChi2InnerTrack.push_back(muon.innerTrack()->normalizedChi2());
	  }
     }   
   
   for(int it=0;it<nTracks;it++)
     {
	SimTrack simTrk = simTracks[it];
	
	int pdgIdG4 = simTrk.type();

	ftree->simTrkId.push_back(pdgIdG4);

	ftree->simTrkPt.push_back(simTrk.momentum().pt());
	ftree->simTrkEta.push_back(simTrk.momentum().eta());
	ftree->simTrkPhi.push_back(simTrk.momentum().phi());

	int nSimHitRPCRECO = 0;
	int nSimHitRPC2RECO = 0;
	int nSimHitCSCStripRECO = 0;
	int nSimHitCSCWireRECO = 0;
	int nSimHitDTRECO = 0;
	
	if( runOnRECO_ )
	  {	     
	     for(edm::DetSetVector<RPCDigiSimLink>::const_iterator il=RPCDigiSimLinkHandle->begin();il!=RPCDigiSimLinkHandle->end();il++)
	       {
		  for(edm::DetSet<RPCDigiSimLink>::const_iterator id=il->data.begin();id!=il->data.end();++id)
		    {		  
		       if( id->getTrackId() != simTrk.trackId() ) continue;

		       RPCDetId rpcId(id->getDetUnitId());
		       if( rpcId.station() == 2 ) nSimHitRPC2RECO++;
		       
		       nSimHitRPCRECO++;
		    }		  
	       }		     	     

	     for(edm::DetSetVector<StripDigiSimLink>::const_iterator il=CSCStripDigiSimLinkHandle->begin();il!=CSCStripDigiSimLinkHandle->end();il++)
	       {
		  for(edm::DetSet<StripDigiSimLink>::const_iterator id=il->data.begin();id!=il->data.end();++id)
		    {		  
		       if( id->SimTrackId() != simTrk.trackId() ) continue;

		       nSimHitCSCStripRECO++;
		    }		  
	       }		     	     

	     for(edm::DetSetVector<StripDigiSimLink>::const_iterator il=CSCWireDigiSimLinkHandle->begin();il!=CSCWireDigiSimLinkHandle->end();il++)
	       {
		  for(edm::DetSet<StripDigiSimLink>::const_iterator id=il->data.begin();id!=il->data.end();++id)
		    {		  
		       if( id->SimTrackId() != simTrk.trackId() ) continue;

		       nSimHitCSCWireRECO++;
		    }		  
	       }		     	     
	     
	     for(DTDigiSimLinkCollection::DigiRangeIterator detUnit=DTDigiSimLinkHandle->begin();detUnit!=DTDigiSimLinkHandle->end();++detUnit)
	       {		  
		  const DTDigiSimLinkCollection::Range& range = (*detUnit).second;
		  DTDigiSimLinkCollection::const_iterator link;
		  
		  for (link=range.first; link!=range.second; ++link)
		    {		       
		       if( link->SimTrackId() != simTrk.trackId() ) continue;
		       
		       nSimHitDTRECO++;
		    }		  
	       }		     	     
	  }	

	ftree->nSimHitRPCRECO.push_back(nSimHitRPCRECO);
	ftree->nSimHitRPC2RECO.push_back(nSimHitRPC2RECO);
	ftree->nSimHitCSCStripRECO.push_back(nSimHitCSCStripRECO);
	ftree->nSimHitCSCWireRECO.push_back(nSimHitCSCWireRECO);
	ftree->nSimHitDTRECO.push_back(nSimHitDTRECO);
	
	int nSimHitRPC = 0;
	int nSimHitCSC = 0;
	int nSimHitDT = 0;

	if( !runOnRECO_ )
	  {	     
	     for( PSimHitContainer::const_iterator simHitIt = simHitsMuonRPCHandle->begin();simHitIt!=simHitsMuonRPCHandle->end();simHitIt++ )
	       {
		  if( simHitIt->trackId() != simTrk.trackId() ) continue;
		  
		  nSimHitRPC++;
	     
		  //	     RPCDetId rpcId(simHitIt->detUnitId());
		  //	     const GeomDet* layer = theRPCGeomESH->idToDet(rpcId);
	       }
	     
	     for( PSimHitContainer::const_iterator simHitIt = simHitsMuonCSCHandle->begin();simHitIt!=simHitsMuonCSCHandle->end();simHitIt++ )
	       {
		  if( simHitIt->trackId() != simTrk.trackId() ) continue;
		  
		  nSimHitCSC++;
	       }
	     
	     for( PSimHitContainer::const_iterator simHitIt = simHitsMuonDTHandle->begin();simHitIt!=simHitsMuonDTHandle->end();simHitIt++ )
	       {
		  if( simHitIt->trackId() != simTrk.trackId() ) continue;
		  
		  nSimHitDT++;
	       }
	  }
	
	ftree->nSimHitRPC.push_back(nSimHitRPC);
	ftree->nSimHitCSC.push_back(nSimHitCSC);
	ftree->nSimHitDT.push_back(nSimHitDT);     
     }
   
   ftree->tree->Fill();
}

void SimG4Filter::beginRun(const edm::Run& iRun, const edm::EventSetup& iSetup)
{
   iSetup.getData(pdt);
   
   iSetup.get<MuonGeometryRecord>().get(theRPCGeomESH);
   iSetup.get<MuonGeometryRecord>().get(theCSCGeomESH);
   iSetup.get<MuonGeometryRecord>().get(theDTGeomESH);
}

void SimG4Filter::endRun(const edm::Run& iRun, const edm::EventSetup& iSetup)
{
}

void SimG4Filter::fillDescriptions(edm::ConfigurationDescriptions& descriptions)
{
   edm::ParameterSetDescription desc;
   desc.setUnknown();
   descriptions.addDefault(desc);
}

float SimG4Filter::DeltaR(float eta1,float phi1,float eta2,float phi2)
{   
   float DeltaPhi = TMath::Abs(phi2 - phi1);
   if (DeltaPhi > 3.141593 ) DeltaPhi -= 2.*3.141593;
   return TMath::Sqrt( (eta2-eta1)*(eta2-eta1) + DeltaPhi*DeltaPhi );
}

//define this as a plug-in
DEFINE_FWK_MODULE(SimG4Filter);

