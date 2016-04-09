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

#include "SimAnalysis/SimAnalysis/interface/SimTree.hh"

class SimAnalysis : public edm::EDAnalyzer
{
 public:

   explicit SimAnalysis(const edm::ParameterSet&);
   ~SimAnalysis();

   static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

 private:

   virtual void analyze(const edm::Event&, const edm::EventSetup&) override;

   virtual void beginRun(const edm::Run&, const edm::EventSetup&) override;
   virtual void endRun(const edm::Run&, const edm::EventSetup&) override;

   HepMC::GenParticle* GetMother(HepMC::GenParticle* part);
   reco::GenParticle* GetMother(reco::GenParticle* part);
   SimTrack* GetMother(SimTrack* part);
   
   edm::EDGetTokenT<std::vector<SimVertex> > simVerticesToken_;
   edm::EDGetTokenT<std::vector<SimTrack> > simTracksToken_;
   edm::EDGetTokenT<edm::HepMCProduct> hepMCToken_;
   edm::EDGetTokenT<std::vector<reco::GenParticle> > genParticlesToken_;
   edm::EDGetTokenT<std::vector<reco::PFJet> > pfJetToken_;
   edm::EDGetTokenT<std::vector<pat::Jet> > patJetToken_;
   edm::EDGetTokenT<std::vector<reco::Muon> > recoMuonToken_;
   edm::EDGetTokenT<std::vector<pat::Muon> > patMuonToken_;
   
   edm::ESHandle<HepPDT::ParticleDataTable> pdt;
   
   edm::Handle<std::vector<SimVertex> > simVerticesHandle;
   edm::Handle<std::vector<SimTrack> > simTracksHandle;
   edm::Handle<std::vector<reco::PFJet> > pfJetHandle;
   edm::Handle<std::vector<pat::Jet> > patJetHandle;
   edm::Handle<std::vector<reco::Muon> > recoMuonHandle;
   edm::Handle<std::vector<pat::Muon> > patMuonHandle;
   
   SimTree *ftree;

   bool runOnRECO_;
   
   TH1F *hcount;
   
   const edm::Service<TFileService> fs;
};

SimAnalysis::SimAnalysis(const edm::ParameterSet& iConfig)
{
   simVerticesToken_    = consumes<std::vector<SimVertex> >(iConfig.getParameter<edm::InputTag>("simVerticesInput"));
   simTracksToken_    = consumes<std::vector<SimTrack> >(iConfig.getParameter<edm::InputTag>("simTracksInput"));
   hepMCToken_    = consumes<edm::HepMCProduct>(iConfig.getParameter<edm::InputTag>("hepMCInput"));
   genParticlesToken_    = consumes<std::vector<reco::GenParticle> >(iConfig.getParameter<edm::InputTag>("genParticlesInput"));
   pfJetToken_    = consumes<std::vector<reco::PFJet> >(iConfig.getParameter<edm::InputTag>("pfJetInput"));
   patJetToken_    = consumes<std::vector<pat::Jet> >(iConfig.getParameter<edm::InputTag>("patJetInput"));
   recoMuonToken_    = consumes<std::vector<reco::Muon> >(iConfig.getParameter<edm::InputTag>("recoMuonInput"));
   patMuonToken_    = consumes<std::vector<pat::Muon> >(iConfig.getParameter<edm::InputTag>("patMuonInput"));

   runOnRECO_ = iConfig.getParameter<bool>("runOnRECO");
   
   TFile& f = fs->file();   
   f.SetCompressionAlgorithm(ROOT::kZLIB);
   f.SetCompressionLevel(9);
   ftree = new SimTree(fs->make<TTree>("tree","tree"));   
   ftree->CreateBranches(32000);
   
   hcount = fs->make<TH1F>("hcount","hcount",1,0.,1.);
}

SimAnalysis::~SimAnalysis()
{
}

void SimAnalysis::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   using namespace edm;

   hcount->SetBinContent(1,hcount->GetBinContent(1)+1);
   
   ftree->Init();
   
   // Sim Vertices
   iEvent.getByToken(simVerticesToken_,simVerticesHandle);

   // Sim Tracks
   iEvent.getByToken(simTracksToken_,simTracksHandle);

   // Hep MC
   edm::Handle<edm::HepMCProduct> hepMCHandle;
   iEvent.getByToken(hepMCToken_,hepMCHandle);

   // Gen Particles
   edm::Handle<std::vector<reco::GenParticle> > genParticlesHandle;
   iEvent.getByToken(genParticlesToken_,genParticlesHandle);

   if( runOnRECO_ )
     {	
	// PF Jets
	iEvent.getByToken(pfJetToken_,pfJetHandle);
	
	// PAT Jets
	iEvent.getByToken(patJetToken_,patJetHandle);

	// PF Muons
	iEvent.getByToken(recoMuonToken_,recoMuonHandle);

	// PAT Muons
	iEvent.getByToken(patMuonToken_,patMuonHandle);
     }   

   // GEN-SIM specific data
   
   const std::vector<SimVertex> &simVertices = *simVerticesHandle.product();
   const std::vector<SimTrack> &simTracks = *simTracksHandle.product();
//   const HepMC::GenEvent *hepMC = hepMCHandle->GetEvent();
   const std::vector<reco::GenParticle> &genParticles = *genParticlesHandle.product();

   float primVtxX = genParticles[2].vertex().x();
   float primVtxY = genParticles[2].vertex().y();
   float primVtxZ = genParticles[2].vertex().z();

   ftree->primVtxX.push_back(primVtxX);
   ftree->primVtxY.push_back(primVtxY);
   ftree->primVtxZ.push_back(primVtxZ);
   
   int nVertices = simVertices.size();
   int nTracks = simTracks.size();

   for(int it=0;it<nTracks;it++)
     {
	SimTrack simTrk = simTracks[it];
	
	int genPartIdx = simTrk.genpartIndex();
	int pdgIdG4 = simTrk.type();
	
	// simulated muons
	if( genPartIdx == -1 && abs(pdgIdG4) == 13 )
	  {
	     float muSimPt = simTrk.momentum().pt();
	     float muSimEta = simTrk.momentum().eta();
	     float muSimPhi = simTrk.momentum().phi();
	     
	     ftree->muSimPt.push_back(muSimPt);
	     ftree->muSimEta.push_back(muSimEta);
	     ftree->muSimPhi.push_back(muSimPhi);

	     SimTrack *mom = GetMother(&simTrk);
	     int momId = mom->type();
	     ftree->muSimMomId.push_back(momId);

	     for(int iv=0;iv<nVertices;iv++)
	       {
		  int vertexIdx = simVertices[iv].vertexId();
		  
		  if( vertexIdx == simTrk.vertIndex() )
		    {
		       SimVertex vert = simVertices[iv];
		       
		       float R = vert.position().r();
		       float posX = vert.position().x();
		       float posY = vert.position().y();
		       float posZ = vert.position().z();
		       
		       double Rpv = sqrt(pow(posX*mm-primVtxX,2)+
					 pow(posY*mm-primVtxY,2)+
					 pow(posZ*mm-primVtxZ,2));
		       
		       ftree->muSimRpv.push_back(Rpv);
		       
		       ftree->muSimR.push_back(R);
		       ftree->muSimPosX.push_back(posX);
		       ftree->muSimPosY.push_back(posY);
		       ftree->muSimPosZ.push_back(posZ);
		       		       
		       break;
		    }		  
	       }
	  }
     }   

   // generated muons
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
	     
	     ftree->muPt.push_back(muPt);
	     ftree->muEta.push_back(muEta);
	     ftree->muPhi.push_back(muPhi);
	     ftree->muStatus.push_back(muStatus);

	     reco::GenParticle *mom = GetMother(&part);

	     int momId = mom->pdgId();
	     float momPt = mom->pt();
	     float momEta = mom->eta();
	     float momPhi = mom->phi();
	     
	     ftree->momId.push_back(momId);
	     ftree->momPt.push_back(momPt);
	     ftree->momEta.push_back(momEta);
	     ftree->momPhi.push_back(momPhi);
	     
	     float muPosX = part.vx();
	     float muPosY = part.vy();
	     float muPosZ = part.vz();
	     float muR = sqrt(muPosX*muPosX+muPosY*muPosY+muPosZ*muPosZ);

	     double muRpv = sqrt(pow(muPosX*mm-primVtxX,2)+
				 pow(muPosY*mm-primVtxY,2)+
				 pow(muPosZ*mm-primVtxZ,2));
	     
	     ftree->muR.push_back(muR);
	     ftree->muRpv.push_back(muRpv);
	     ftree->muPosX.push_back(muPosX);
	     ftree->muPosY.push_back(muPosY);
	     ftree->muPosZ.push_back(muPosZ);

	     reco::GenParticle *momParton = mom;
	     int qId = 666;
	     while( abs(qId) >= 6 && abs(qId) != 21 )
	       {
		  reco::GenParticle *momIter = GetMother(momParton);
		  qId = momIter->pdgId();
		  momParton = momIter;
	       }
	     
	     int partonId = momParton->pdgId();
	     float partonPt = momParton->pt();
	     float partonEta = momParton->eta();
	     float partonPhi = momParton->phi();
	     
	     ftree->partonId.push_back(partonId);
	     ftree->partonPt.push_back(partonPt);
	     ftree->partonEta.push_back(partonEta);
	     ftree->partonPhi.push_back(partonPhi);
	     
//	     const HepPDT::ParticleData* PData = pdt->particle(HepPDT::ParticleID(momId));
//	     if( momId == 333 )
//	       std::cout << PData->name() << " " << momId << std::endl;*/
	  }
     }

   // RECO specific data
   
   if( runOnRECO_ )
     {	
	const std::vector<reco::PFJet> &pfJets = *pfJetHandle.product();
	const std::vector<pat::Jet> &patJets = *patJetHandle.product();
	const std::vector<reco::Muon> &recoMuons = *recoMuonHandle.product();
	const std::vector<pat::Muon> &patMuons = *patMuonHandle.product();

	int nPFJets = pfJets.size();
	int nPATJets = patJets.size();
	int nRecoMuons = recoMuons.size();
	int nPATMuons = patMuons.size();
	
	// pf jets
	for(int ij=0;ij<nPFJets;ij++)
	  {
	     reco::PFJet jet = pfJets[ij];
	     
	     float pt = jet.pt();
	     float eta = jet.eta();
	     float phi = jet.phi();
	     
	     ftree->pfjetPt.push_back(pt);
	     ftree->pfjetEta.push_back(eta);
	     ftree->pfjetPhi.push_back(phi);
	  }
	
	// pat jets
	for(int ij=0;ij<nPATJets;ij++)
	  {
	     pat::Jet jet = patJets[ij];
	     
	     float pt = jet.pt();
	     float eta = jet.eta();
	     float phi = jet.phi();
	     int pFlavour = jet.partonFlavour();
	     int hFlavour = jet.hadronFlavour();
	     
	     ftree->patjetPt.push_back(pt);
	     ftree->patjetEta.push_back(eta);
	     ftree->patjetPhi.push_back(phi);
	     ftree->patjetPartonFlavour.push_back(pFlavour);
	     ftree->patjetHadronFlavour.push_back(hFlavour);
	  }
	
	// reco muons
	for(int im=0;im<nRecoMuons;im++)
	  {
	     reco::Muon muon = recoMuons[im];
	     
	     float pt = muon.pt();
	     float eta = muon.eta();
	     float phi = muon.phi();

	     bool isPFMuon = muon.isPFMuon();
	     bool isGlobalMuon = muon.isGlobalMuon();
	     int numberOfValidMuonHits = (muon.outerTrack().isNonnull()) ? muon.outerTrack()->hitPattern().numberOfValidMuonHits() : -1;
	     int numberOfMatches = muon.numberOfMatches();
	     int numberOfValidHits = (muon.innerTrack().isNonnull()) ? muon.innerTrack()->hitPattern().numberOfValidHits() : -1;
	     int numberOfValidPixelHits = (muon.innerTrack().isNonnull()) ? muon.innerTrack()->hitPattern().numberOfValidPixelHits() : -1;
	     int numberOfHits = (muon.innerTrack().isNonnull()) ? muon.innerTrack()->hitPattern().numberOfHits(reco::HitPattern::MISSING_OUTER_HITS) : -1;	     
	     float normalizedChi2GlobalTrack = (muon.globalTrack().isNonnull()) ? muon.globalTrack()->normalizedChi2() : -1;
	     float normalizedChi2InnerTrack = (muon.innerTrack().isNonnull()) ? muon.innerTrack()->normalizedChi2() : -1;
	     int numberOfValidMuonHitsGlobalTrack = (muon.globalTrack().isNonnull()) ? muon.globalTrack()->hitPattern().numberOfValidMuonHits() : -1;
	     int trackerLayersWithMeasurement = (muon.globalTrack().isNonnull()) ? muon.globalTrack()->hitPattern().trackerLayersWithMeasurement() : -1;
	     int numberOfMatchedStations = muon.numberOfMatchedStations();
	     
	     ftree->recomuonPt.push_back(pt);
	     ftree->recomuonEta.push_back(eta);
	     ftree->recomuonPhi.push_back(phi);

	     ftree->recomuonIsPFMuon.push_back(isPFMuon);
	     ftree->recomuonIsGlobalMuon.push_back(isGlobalMuon);
	     ftree->recomuonNumberOfValidMuonHits.push_back(numberOfValidMuonHits);
	     ftree->recomuonNumberOfMatches.push_back(numberOfMatches);
	     ftree->recomuonNumberOfValidHits.push_back(numberOfValidHits);
	     ftree->recomuonNumberOfValidPixelHits.push_back(numberOfValidPixelHits);
	     ftree->recomuonNumberOfHits.push_back(numberOfHits);
	     ftree->recomuonNormalizedChi2GlobalTrack.push_back(normalizedChi2GlobalTrack);
	     ftree->recomuonNormalizedChi2InnerTrack.push_back(normalizedChi2InnerTrack);
	     ftree->recomuonNumberOfValidMuonHitsGlobalTrack.push_back(numberOfValidMuonHitsGlobalTrack);
	     ftree->recomuonTrackerLayersWithMeasurement.push_back(trackerLayersWithMeasurement);
	     ftree->recomuonNumberOfMatchedStations.push_back(numberOfMatchedStations);
	  }
	
	// pat muons
	for(int im=0;im<nPATMuons;im++)
	  {
	     pat::Muon muon = patMuons[im];
	     
	     float pt = muon.pt();
	     float eta = muon.eta();
	     float phi = muon.phi();

	     bool isPFMuon = muon.isPFMuon();
	     bool isGlobalMuon = muon.isGlobalMuon();
	     int numberOfValidMuonHits = (muon.outerTrack().isNonnull()) ? muon.outerTrack()->hitPattern().numberOfValidMuonHits() : -1;
	     int numberOfMatches = muon.numberOfMatches();
	     int numberOfValidHits = (muon.innerTrack().isNonnull()) ? muon.innerTrack()->hitPattern().numberOfValidHits() : -1;
	     int numberOfValidPixelHits = (muon.innerTrack().isNonnull()) ? muon.innerTrack()->hitPattern().numberOfValidPixelHits() : -1;
	     int numberOfHits = (muon.innerTrack().isNonnull()) ? muon.innerTrack()->hitPattern().numberOfHits(reco::HitPattern::MISSING_OUTER_HITS) : -1;	     
	     float normalizedChi2GlobalTrack = (muon.globalTrack().isNonnull()) ? muon.globalTrack()->normalizedChi2() : -1;
	     float normalizedChi2InnerTrack = (muon.innerTrack().isNonnull()) ? muon.innerTrack()->normalizedChi2() : -1;
	     int numberOfValidMuonHitsGlobalTrack = (muon.globalTrack().isNonnull()) ? muon.globalTrack()->hitPattern().numberOfValidMuonHits() : -1;
	     int trackerLayersWithMeasurement = (muon.globalTrack().isNonnull()) ? muon.globalTrack()->hitPattern().trackerLayersWithMeasurement() : -1;
	     int numberOfMatchedStations = muon.numberOfMatchedStations();
	     	     	     
	     ftree->patmuonPt.push_back(pt);
	     ftree->patmuonEta.push_back(eta);
	     ftree->patmuonPhi.push_back(phi);
	     
	     ftree->patmuonIsPFMuon.push_back(isPFMuon);
	     ftree->patmuonIsGlobalMuon.push_back(isGlobalMuon);
	     ftree->patmuonNumberOfValidMuonHits.push_back(numberOfValidMuonHits);
	     ftree->patmuonNumberOfMatches.push_back(numberOfMatches);
	     ftree->patmuonNumberOfValidHits.push_back(numberOfValidHits);
	     ftree->patmuonNumberOfValidPixelHits.push_back(numberOfValidPixelHits);
	     ftree->patmuonNumberOfHits.push_back(numberOfHits);
	     ftree->patmuonNormalizedChi2GlobalTrack.push_back(normalizedChi2GlobalTrack);
	     ftree->patmuonNormalizedChi2InnerTrack.push_back(normalizedChi2InnerTrack);
	     ftree->patmuonNumberOfValidMuonHitsGlobalTrack.push_back(numberOfValidMuonHitsGlobalTrack);
	     ftree->patmuonTrackerLayersWithMeasurement.push_back(trackerLayersWithMeasurement);
	     ftree->patmuonNumberOfMatchedStations.push_back(numberOfMatchedStations);
	  }
     }   
   
   ftree->tree->Fill();
}

HepMC::GenParticle* SimAnalysis::GetMother(HepMC::GenParticle* part)
{
   if( part->production_vertex() ) 
     {	
	HepMC::GenVertex::particle_iterator mother;
	for( mother = part->production_vertex()->particles_begin(HepMC::parents); 
	     mother!= part->production_vertex()->particles_end(HepMC::parents); 
	     mother++ )
	  {	     
	     if( (*mother)->pdg_id() == part->pdg_id() ) return GetMother(*mother);
	     return (*mother);
	  }	
     }
   
   return part;
}

reco::GenParticle* SimAnalysis::GetMother(reco::GenParticle* part)
{
   for( unsigned int j=0;j<part->numberOfMothers();++j )
     {
	const reco::GenParticle *mom = dynamic_cast<const reco::GenParticle*>(part->mother(j));
	reco::GenParticle *mother = const_cast<reco::GenParticle*>(mom);
	if( mother->pdgId() == part->pdgId() ) return GetMother(mother);
	return mother;
     }	
   
   return part;
}

SimTrack* SimAnalysis::GetMother(SimTrack* trk)
{
   if( trk->genpartIndex() == -1 )
     {
	if( trk->noVertex() ) return trk;
	const SimVertex& vtx = (*simVerticesHandle)[trk->vertIndex()];
	if( vtx.noParent() )  return trk;

	for( edm::SimTrackContainer::const_iterator iter=simTracksHandle->begin();
	     iter!=simTracksHandle->end();++iter )
	  {
	     if( (int)iter->trackId() == vtx.parentIndex() )
	       {
		  const SimTrack *mom = &(*iter);
		  SimTrack *mother = const_cast<SimTrack*>(mom);		  
		  if( mother->type() == trk->type() ) return GetMother(mother);
		  return mother;
	       }	     
	  }
     }	
   
   return trk;
}

void SimAnalysis::beginRun(const edm::Run& iRun, const edm::EventSetup& iSetup)
{
   iSetup.getData(pdt);
}

void SimAnalysis::endRun(const edm::Run& iRun, const edm::EventSetup& iSetup)
{
}

void SimAnalysis::fillDescriptions(edm::ConfigurationDescriptions& descriptions)
{
   edm::ParameterSetDescription desc;
   desc.setUnknown();
   descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(SimAnalysis);

