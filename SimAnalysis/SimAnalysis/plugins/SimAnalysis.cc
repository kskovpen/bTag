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
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

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
   reco::GenParticle* GetMother(reco::GenParticle* part,
				const std::vector<reco::GenParticle>* genParticles);
   
   edm::EDGetTokenT<std::vector<SimVertex> > simVerticesToken_;
   edm::EDGetTokenT<std::vector<SimTrack> > simTracksToken_;
   edm::EDGetTokenT<edm::HepMCProduct> hepMCToken_;
   edm::EDGetTokenT<std::vector<reco::GenParticle> > genParticlesToken_;
   
   edm::ESHandle<HepPDT::ParticleDataTable> pdt;
   
   SimTree *ftree;
   
   TH1F *hcount;
   
   const edm::Service<TFileService> fs;
};

SimAnalysis::SimAnalysis(const edm::ParameterSet& iConfig)
{
   simVerticesToken_    = consumes<std::vector<SimVertex> >(iConfig.getParameter<edm::InputTag>("simVerticesInput"));
   simTracksToken_    = consumes<std::vector<SimTrack> >(iConfig.getParameter<edm::InputTag>("simTracksInput"));
   hepMCToken_    = consumes<edm::HepMCProduct>(iConfig.getParameter<edm::InputTag>("hepMCInput"));
   genParticlesToken_    = consumes<std::vector<reco::GenParticle> >(iConfig.getParameter<edm::InputTag>("genParticlesInput"));

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
   edm::Handle<std::vector<SimVertex> > simVerticesHandle;
   iEvent.getByToken(simVerticesToken_,simVerticesHandle);

   // Sim Tracks
   edm::Handle<std::vector<SimTrack> > simTracksHandle;
   iEvent.getByToken(simTracksToken_,simTracksHandle);

   // Hep MC
   edm::Handle<edm::HepMCProduct> hepMCHandle;
   iEvent.getByToken(hepMCToken_,hepMCHandle);

   // Gen Particles
   edm::Handle<std::vector<reco::GenParticle> > genParticlesHandle;
   iEvent.getByToken(genParticlesToken_,genParticlesHandle);
   
   const std::vector<SimVertex> &simVertices = *simVerticesHandle.product();
   const std::vector<SimTrack> &simTracks = *simTracksHandle.product();
   const HepMC::GenEvent *hepMC = hepMCHandle->GetEvent();
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
	int genPartIdx = simTracks[it].genpartIndex();
	int pdgIdG4 = simTracks[it].type();
	
	// non-generated muons
	if( genPartIdx == -1 && abs(pdgIdG4) == 13 )
	  {
	     float muSimPt = simTracks[it].momentum().pt();
	     float muSimEta = simTracks[it].momentum().eta();
	     
	     ftree->muSimPt.push_back(muSimPt);
	     ftree->muSimEta.push_back(muSimEta);	     	     
	     
	     for(int iv=0;iv<nVertices;iv++)
	       {
		  int vertexIdx = simVertices[iv].vertexId();
		  
		  if( vertexIdx == simTracks[it].vertIndex() )
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

	// generated muons
	if( genPartIdx != -1 )
	  {
	     HepMC::GenParticle* part = hepMC->barcode_to_particle(genPartIdx);
	     
	     int partId = part->pdg_id();
	     float partPt = part->momentum().perp();
	     
//	     if( abs(partId) == 13 && partPt > 5. )
	     if( abs(partId) == 13 )
	       {
		  float muPt = partPt;
		  float muEta = part->momentum().eta();
		  
		  ftree->muPt.push_back(muPt);
		  ftree->muEta.push_back(muEta);

		  HepMC::GenParticle *mom = GetMother(part);

		  int momId = mom->pdg_id();
		  float momPt = mom->momentum().perp();
		  float momEta = mom->momentum().eta();
		  
		  ftree->momId.push_back(momId);
		  ftree->momPt.push_back(momPt);
		  ftree->momEta.push_back(momEta);

		  HepMC::GenVertex *vert = part->production_vertex();
		  HepMC::ThreeVector p = vert->point3d();
		  float muPosX = p.x();
		  float muPosY = p.y();
		  float muPosZ = p.z();
		  float muR = p.r(); // in mm
		  
		  double muRpv = sqrt(pow(muPosX*mm-primVtxX,2)+
				      pow(muPosY*mm-primVtxY,2)+
				      pow(muPosZ*mm-primVtxZ,2));
		  
		  ftree->muR.push_back(muR);
		  ftree->muRpv.push_back(muRpv);
		  ftree->muPosX.push_back(muPosX);
		  ftree->muPosY.push_back(muPosY);
		  ftree->muPosZ.push_back(muPosZ);
		  
		  HepMC::GenParticle *momParton = mom;
		  int qId = 666;
		  while( abs(qId) >= 6 && abs(qId) != 21 )
		    {
		       HepMC::GenParticle *momIter = GetMother(momParton);
		       qId = momIter->pdg_id();
		       momParton = momIter;
		    }
		  
		  int partonId = momParton->pdg_id();
		  float partonPt = momParton->momentum().perp();
		  float partonEta = momParton->momentum().eta();
		  
		  ftree->partonId.push_back(partonId);
		  ftree->partonPt.push_back(partonPt);
		  ftree->partonEta.push_back(partonEta);
		  
//		  const HepPDT::ParticleData* PData = pdt->particle(HepPDT::ParticleID(momId));
//		  if( momId == 333 )
//		    std::cout << PData->name() << " " << momId << std::endl;
	       }	     
	  }		  
     }	     

   // sanity check with GenParticles only
/*   int nGenParticles = genParticles.size();
   for(int ip=0;ip<nGenParticles;ip++)
     {
	reco::GenParticle gen = genParticles[ip];
	
	int genId = gen.pdgId();
	float genPt = gen.pt();
	
//	if( abs(genId) == 13 && genPt > 5. )
	if( abs(genId) == 13 )
	  {
	     float muPt = genPt;
	     float muEta = gen.eta();
		  
	     ftree->muGenPt.push_back(muPt);
	     ftree->muGenEta.push_back(muEta);

	     reco::GenParticle *mom = GetMother(&gen,&genParticles);
	     
	     int momId = mom->pdgId();
	     float momPt = mom->pt();
	     float momEta = mom->eta();

	     ftree->momGenId.push_back(momId);
	     ftree->momGenPt.push_back(momPt);
	     ftree->momGenEta.push_back(momEta);
	     
	     reco::GenParticle *momParton = mom;
	     int qId = 666;
	     while( abs(qId) >= 6 && abs(qId) != 21 )
	       {
		  reco::GenParticle *momIter = GetMother(momParton,&genParticles);
		  qId = momIter->pdgId();
		  momParton = momIter;
	       }

	     int partonId = momParton->pdgId();
	     float partonPt = momParton->pt();
	     float partonEta = momParton->eta();
	     
	     ftree->partonGenId.push_back(partonId);
	     ftree->partonGenPt.push_back(partonPt);
	     ftree->partonGenEta.push_back(partonEta);
	  }		
     }*/
   
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

reco::GenParticle* SimAnalysis::GetMother(reco::GenParticle* part,
					  const std::vector<reco::GenParticle>* genParticles)
{
   for( unsigned int j=0;j<part->numberOfMothers();++j )
     {
	const reco::GenParticle *mom = dynamic_cast<const reco::GenParticle*>(part->mother(j));
	reco::GenParticle *mother = const_cast<reco::GenParticle*>(mom);
	if( mother->pdgId() == part->pdgId() ) return GetMother(mother,genParticles);
	return mother;
     }	
   
   return part;
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

