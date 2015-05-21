#include "../include/Syst.h"

LTANA::Syst::Syst()
{
}

LTANA::Syst::~Syst()
{
}

void LTANA::Syst::init()
{   
   helper = new Helper();

   _sysNameDown[0]  = "";
   _sysNameDown[1]  = "_pu_down";
   _sysNameDown[2]  = "_gsplit_down";
   _sysNameDown[3]  = "_bfrag_down";
   _sysNameDown[4]  = "_cdfrag_down";
   _sysNameDown[5]  = "_cfrag_down";
   _sysNameDown[6]  = "_ksl_down";
   _sysNameDown[7]  = "_ntrkgen_down";
   _sysNameDown[8]  = "_jes_down";
   _sysNameDown[9]  = "_jer_down";
   _sysNameDown[10] = "_ntrk_down";
   _sysNameDown[11] = "_njet_down";
   _sysNameDown[12] = "_mupt_down";
   _sysNameDown[13] = "_jeta_down";

   _sysNameUp[0]  = "";
   _sysNameUp[1]  = "_pu_up";
   _sysNameUp[2]  = "_gsplit_up";
   _sysNameUp[3]  = "_bfrag_up";
   _sysNameUp[4]  = "_cdfrag_up";
   _sysNameUp[5]  = "_cfrag_up";
   _sysNameUp[6]  = "_ksl_up";
   _sysNameUp[7]  = "_ntrkgen_up";
   _sysNameUp[8]  = "_jes_up";
   _sysNameUp[9]  = "_jer_up";
   _sysNameUp[10] = "_ntrk_up";
   _sysNameUp[11] = "_njet_up";
   _sysNameUp[12] = "_mupt_up";
   _sysNameUp[13] = "_jeta_up";
   
   jesTotal = new JetCorrectionUncertainty(*(new JetCorrectorParameters("/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/test/Summer13_V5_DATA_UncertaintySources_AK5PF.txt", "Total")));

   // JER taken from https://twiki.cern.ch/twiki/bin/view/CMS/JetResolution
   
   cJER[0] = 1.052; // 0.0-0.5
   cJER[1] = 1.057; // 0.5-1.1
   cJER[2] = 1.096; // 1.1-1.7
   cJER[3] = 1.134; // 1.7-2.3
   cJER[4] = 1.288; // 2.3-5.0
   
   cJER_down[0] = 0.990;
   cJER_down[1] = 1.001;
   cJER_down[2] = 1.032;
   cJER_down[3] = 1.042;
   cJER_down[4] = 1.089;

   cJER_up[0] = 1.115;
   cJER_up[1] = 1.114;
   cJER_up[2] = 1.161;
   cJER_up[3] = 1.228;
   cJER_up[4] = 1.488;

   if( !isdata )
     {	
	nPtRelPtBins = 15;
	TString PtRelPtBin[] = {
	   "Pt2030", "Pt3040", "Pt4050", "Pt5060", "Pt6070"
	   , "Pt7080", "Pt80100", "Pt100120", "Pt120160", "Pt160210"
	   , "Pt210260", "Pt260320", "Pt320400", "Pt400500", "Pt500" 
	};
	
	for( int ptb=0;ptb<nPtRelPtBins;ptb++ )
	  {      
	     for(int ib=0;ib<100;ib++ )
	       {
		  BTemplateCorrections[ib][ptb][0] = 1.;
		  BTemplateCorrections[ib][ptb][1] = 1.;
	       }
	     
	     std::ifstream MnusCorrectionsFile; 
	     MnusCorrectionsFile.open("./PtRelFall12/EnergyFraction_" + PtRelPtBin[ptb] + "_m5.txt");
	     while( MnusCorrectionsFile )
	       {
		  float xBin, efcorr;
		  MnusCorrectionsFile >> xBin >> efcorr;
		  if ( efcorr > 4. ) efcorr = 1.;
		  int ib = int(xBin/0.02);
		  BTemplateCorrections[ib][ptb][0] = efcorr;
	       }
	     
	     std::ifstream PlusCorrectionsFile; 
	     PlusCorrectionsFile.open("./PtRelFall12/EnergyFraction_" + PtRelPtBin[ptb] + "_p5.txt");
	     while( PlusCorrectionsFile )
	       {
		  float xBin, efcorr;
		  PlusCorrectionsFile >> xBin >> efcorr;
		  if ( efcorr > 4. ) efcorr = 1.;
		  int ib = int(xBin/0.02);
		  BTemplateCorrections[ib][ptb][1] = efcorr;
	       }
	  }
     }
   
   initRePU();
}

void LTANA::Syst::JEC(int ij)
{	
   _v_jet = new TLorentzVector(0,0,0,0);
   _v_jet_sys_jesTotalUp = new TLorentzVector(0,0,0,0);
   _v_jet_sys_jesTotalDown = new TLorentzVector(0,0,0,0);
   _v_jet_sys_jerTotalUp = new TLorentzVector(0,0,0,0);
   _v_jet_sys_jerTotalDown = new TLorentzVector(0,0,0,0);
	
   float jeta = ntP->Jet_eta[ij];
   float jphi = ntP->Jet_phi[ij];
   float jm = ntP->Jet_mass[ij];
   float residual = 1.;
   if( ntP->Run > 0 ) residual = ntP->Jet_residual[ij];
   float jpt = ntP->Jet_pt[ij] * residual;

   // JER

   _v_jet_sys_jerTotalUp->SetPtEtaPhiM(jpt,jeta,jphi,jm);
   _v_jet_sys_jerTotalDown->SetPtEtaPhiM(jpt,jeta,jphi,jm);
	
   if( !isdata )
     {	    
	int etaIdx = -1;
	if( fabs(jeta) >= 0. && fabs(jeta) < 0.5 ) etaIdx = 0;
	if( fabs(jeta) >= 0.5 && fabs(jeta) < 1.1 ) etaIdx = 1;
	if( fabs(jeta) >= 1.1 && fabs(jeta) < 1.7 ) etaIdx = 2;
	if( fabs(jeta) >= 1.7 && fabs(jeta) < 2.3 ) etaIdx = 3;
	if( fabs(jeta) >= 2.3 && fabs(jeta) < 5.0 ) etaIdx = 4;
	
	double jpt_c = jpt;
	if( etaIdx >= 0 )
	  {		  
	     double genpt = ntP->Jet_genpt[ij];
	     if( genpt >= 0. )
	       {
		  jpt_c = genpt + cJER[etaIdx]*(jpt-genpt);
		  
		  double jpt_c_down = genpt + cJER_down[etaIdx]*(jpt-genpt);
		  double jpt_c_up = genpt + cJER_up[etaIdx]*(jpt-genpt);
		  
		  if( jpt_c < 0. ) jpt_c = 0.;
		  if( jpt_c_down < 0. ) jpt_c_down = 0.;
		  if( jpt_c_up < 0. ) jpt_c_up = 0.;
		  
		  _v_jet_sys_jerTotalUp->SetPtEtaPhiM(jpt_c_up,jeta,jphi,jm);
		  _v_jet_sys_jerTotalDown->SetPtEtaPhiM(jpt_c_down,jeta,jphi,jm);
	       }
	  }	     
	
	jpt = jpt_c;
     }	
   
   _v_jet->SetPtEtaPhiM(jpt,jeta,jphi,jm);
	
   _v_jet_sys_jesTotalUp->SetPtEtaPhiM(jpt,jeta,jphi,jm);
   _v_jet_sys_jesTotalDown->SetPtEtaPhiM(jpt,jeta,jphi,jm);

   // JES
   jesTotal->setJetPt(jpt);
   jesTotal->setJetEta(jeta);
   double uncert = jesTotal->getUncertainty(true);
   
   _v_jet_sys_jesTotalUp->SetPtEtaPhiE(jpt*(1.+uncert),
				       jeta,
				       _v_jet->Phi(),
				       _v_jet->E()*(1.+uncert));
   
   _v_jet_sys_jesTotalDown->SetPtEtaPhiE(jpt*(1.-uncert),
					 jeta,
					 _v_jet->Phi(),
					 _v_jet->E()*(1.-uncert));
   
}

// pileup reweighting sys
float LTANA::Syst::Pileup(int npu,int isys)
{	
   float sf = 1.;
   float wPU = WeightPU[npu];
   bool isUp = (isys == SYS_PU_UP);
   bool isDown = (isys == SYS_PU_DOWN);
   if( isUp || isDown )
     {	
	if( isUp ) wPU = WeightPUmax[npu];
	else if( isDown ) wPU = WeightPUmin[npu];
	
	if( !isdata ) sf *= wPU;
     }   
   
   return sf;
}

// gluon splitting sys
float LTANA::Syst::GluonSplitting(int ij,int flavch,int isys)
{
   float sf = 1.;
   
   if( (isys == SYS_GSPLIT_DOWN || 
	isys == SYS_GSPLIT_UP) &&
       !isdata )
     {		       
	bool GSPc = false, GSPb = false;
	
	if( flavch == 2 )
	  {
	     for( int k=0;k<ntP->ncQuarks;k++ )
	       {
		  if( ntP->cQuark_status[k] != 2 ) continue;
		  double dRqj = helper->DeltaR(ntP->Jet_eta[ij],
					       ntP->Jet_phi[ij], 
					       ntP->cQuark_eta[k], 
					       ntP->cQuark_phi[k]);
		  if( k == ntP->ncQuarks-1 ) continue;
		  if( dRqj > 0.5 ) continue;
		  for( int l=k+1;l<ntP->ncQuarks;l++ )
		    {
		       if( ntP->cQuark_status[l] != 2 ) continue;
		       double dRqj2 = helper->DeltaR(ntP->Jet_eta[ij], 
						     ntP->Jet_phi[ij], 
						     ntP->cQuark_eta[l], 
						     ntP->cQuark_phi[l]);
		       if( ntP->cQuark_pdgID[k] * ntP->cQuark_pdgID[l] > 0 ) continue;
		       if( dRqj2 < 0.5 ) GSPc = true;
		    }			    
	       }		       
	  }		  
	
	if( flavch == 1 )
	  {
	     for( int k=0;k<ntP->nbQuarks;k++ )
	       {
		  if( ntP->bQuark_status[k] != 2 ) continue;
		  double dRqj = helper->DeltaR(ntP->Jet_eta[ij],
					       ntP->Jet_phi[ij], 
					       ntP->bQuark_eta[k], 
					       ntP->bQuark_phi[k]);
		  if( k == ntP->nbQuarks-1 ) continue;
		  if( dRqj > 0.5 ) continue;
		  for( int l=k+1;l<ntP->nbQuarks;l++ )
		    {
		       if( ntP->bQuark_status[l] != 2 ) continue;
		       double dRqj2 = helper->DeltaR(ntP->Jet_eta[ij], 
						     ntP->Jet_phi[ij], 
						     ntP->bQuark_eta[l], 
						     ntP->bQuark_phi[l]);
		       if( ntP->bQuark_pdgID[k] * ntP->bQuark_pdgID[l] > 0 ) continue;
		       if( dRqj2 < 0.5 ) GSPb = true;
		    }			    
	       }		       
	  }		  
	
	if( 
	   isys == SYS_GSPLIT_DOWN &&
	   ((GSPc && flavch == 2) || (GSPb && flavch == 1))
	  ) sf *= 0.5;
	if( 
	   isys == SYS_GSPLIT_UP &&
	   ((GSPc && flavch == 2) || (GSPb && flavch == 1))
	  ) sf *= 1.5;
     }
   
   return sf;
}

// b fragmentation sys
float LTANA::Syst::bFrag(int ij,int flavch,int isys)
{
   float sf = 1.;
   
   if( (isys == SYS_BFRAG_DOWN ||
	isys == SYS_BFRAG_UP) &&
       !isdata )
     {		 
	float jPT = ntP->Jet_pt[ij];
	float WeightBFrag = 1.;
	float EnergyFraction = 0.; 
	int iB = -1, iptBin = 0, efbin = -1;
	if( flavch == 1 && 
	    ( isys == SYS_BFRAG_DOWN ||
	      isys == SYS_BFRAG_UP ) )
	  {
	     if( jPT > 500 ) iptBin = 14;
	     else if( jPT > 400 ) iptBin = 13;
	     else if( jPT > 320 ) iptBin = 12;  
	     else if( jPT > 260 ) iptBin = 11;
	     else if( jPT > 210 ) iptBin = 10;
	     else if( jPT > 160 ) iptBin =  9;
	     else if( jPT > 120 ) iptBin =  8;  
	     else if( jPT > 100 ) iptBin =  7;  
	     else if( jPT >  80 ) iptBin =  6;  
	     else if( jPT >  70 ) iptBin =  5;  
	     else if( jPT >  60 ) iptBin =  4;  
	     else if( jPT >  50 ) iptBin =  3;  
	     else if( jPT >  40 ) iptBin =  2;  
	     else if( jPT >  30 ) iptBin =  1;  
	     else                 iptBin =  0;
	     
	     float B_Mass = 0.;
	     for( int ib=0;ib<ntP->nBHadrons;ib++ )
	       {
		  if( helper->DeltaR(ntP->Jet_eta[ij],
				     ntP->Jet_phi[ij], 
				     ntP->BHadron_eta[ib], 
				     ntP->BHadron_phi[ib]) < 0.5 )
		    {
		       if( ntP->BHadron_mass[ib] > B_Mass ) 
			 {
			    B_Mass = ntP->BHadron_mass[ib];
			    iB = ib;
			 }				 
		    }			    
	       }
	     
	     if( iB >= 0 ) 
	       {
		  EnergyFraction = ntP->BHadron_pT[iB]/ntP->Jet_genpt[ij];
		  efbin = int( EnergyFraction / 0.02 );
		  if( efbin >= 0 && efbin < 100 ) 
		    {
		       if( isys == SYS_BFRAG_DOWN ) WeightBFrag = BTemplateCorrections[efbin][iptBin][0];
		       if( isys == SYS_BFRAG_UP ) WeightBFrag = BTemplateCorrections[efbin][iptBin][1];
		    }			    
	       }
			    
	     sf *= WeightBFrag;
	  }
     }	
   
   return sf;
}

// c->D fragmentation sys
float LTANA::Syst::cdFrag(int ij,int flavch,int isys)
{	
   float sf = 1.;
   
   if( (isys == SYS_CDFRAG_DOWN ||
	isys == SYS_CDFRAG_UP) &&
       !isdata )
     {		       
	if( flavch == 2 ||
	    flavch == 1 )
	  {
	     bool isDplusMu = false, isDzeroMu = false, isDsubsMu = false;
	     
	     int ndaughters = 0;
	     for( int k=0;k<ntP->nDHadrons;k++ )
	       {
		  double dR = helper->DeltaR(ntP->DHadron_eta[k], 
					     ntP->DHadron_phi[k], 
					     ntP->Jet_eta[ij], 
					     ntP->Jet_phi[ij]);
		  if( dR > 0.4 ) continue;
		  bool isSemiMu = false;
		  int nd = ntP->DHadron_nDaughters[k];
		  for( int kk=0;kk<nd;kk++ )
		    {
		       if( abs(ntP->DHadron_DaughtersPdgID[kk+ndaughters]) == 13 ) isSemiMu = true;
		    }
		  
		  ndaughters += nd;
		  
		  if( !isSemiMu ) continue;
		  if( abs(ntP->DHadron_pdgID[k]) == 411 ) isDplusMu = true;
		  if( abs(ntP->DHadron_pdgID[k]) == 421 ) isDzeroMu = true;
		  if( abs(ntP->DHadron_pdgID[k]) == 431 ) isDsubsMu = true;
	       }
	     
	     // weight for D->mu decay: Pythia vs PDG2013
	     if( isys == SYS_CDFRAG_DOWN )
	       {			    
		  if( isDplusMu ) sf *= 0.176 / 0.172;
		  if( isDzeroMu ) sf *= 0.067 / 0.077;
		  if( isDsubsMu ) sf *= 0.067 / 0.080;
	       }		       
	  }
     }		  
   
   return sf;
}

// c fragmentation sys
float LTANA::Syst::cFrag(int ij,int flavch,int isys)
{
   float sf = 1.;
   
   _nChargedGen1_c = -1; 
   _nChargedGen2_c = -1;
   
   if( !isdata )
     {
	if( flavch == 2 )
	  {
	     bool hasCquark = 0;
	     for( int c=0;c<ntP->ncQuarks;c++ )
	       {
		  double dRc = helper->DeltaR(ntP->cQuark_eta[c], 
					      ntP->cQuark_phi[c], 
					      ntP->Jet_eta[ij], 
					      ntP->Jet_phi[ij]);
		  if( dRc < 0.3 ) hasCquark = 1;
	       }
	     
	     if( hasCquark )
	       {				 
		  bool isDplus = false, isDzero = false, isDsubs = false, isDbary = false;
		  for( int k=0;k<ntP->nDHadrons;k++ )
		    {
		       double dR = helper->DeltaR(ntP->DHadron_eta[k], 
						  ntP->DHadron_phi[k], 
						  ntP->Jet_eta[ij], 
						  ntP->Jet_phi[ij]);
		       if( dR > 0.4 ) continue;
		       
		       if( _nChargedGen1_c >= 0 && _nChargedGen2_c < 0 ) _nChargedGen2_c = ntP->DHadron_nCharged[k];
		       if( _nChargedGen1_c < 0 )  _nChargedGen1_c = ntP->DHadron_nCharged[k];
				      
		       if( abs(ntP->DHadron_pdgID[k]) == 411 ) isDplus = true;
		       if( abs(ntP->DHadron_pdgID[k]) == 421 ) isDzero = true;
		       if( abs(ntP->DHadron_pdgID[k]) == 431 ) isDsubs = true;
		       if((abs(ntP->DHadron_pdgID[k])/1000)%10 == 4 ) isDbary = true;
		    }		       
		  
		  // weight for c->D fragmentation rate: Pythia vs PDG2008
		  if( isys == SYS_CFRAG_DOWN )
		    {
		       // DB
		       if( isDplus ) sf *= 1.37; // PDG2008(0.246+-0.020)
		       if( isDzero ) sf *= 0.91; // PDG2008(0.565+-0.032)
		       if( isDsubs ) sf *= 0.67; // PDG2008(0.080+-0.017)
		       // 0.185072, 0.58923, 0.115961
		    }		       
	       }			    
	  }
     }
   
   return sf;
}

// K0s Lambda sys
float LTANA::Syst::Ks(int ij,int flavch,int isys)
{	
   float sf = 1.;
   
   if( (isys == SYS_KSL_DOWN ||
	isys == SYS_KSL_UP) &&
       !isdata )
     {		       
	int nK0s = 0, nLambda = 0;
	if( flavch == 3 )
	  {
	     for( int k=0;k<ntP->nGenV0;k++ )
	       {
		  double dR = helper->DeltaR(ntP->GenV0_eta[k], 
					     ntP->GenV0_phi[k], 
					     ntP->Jet_eta[ij], 
					     ntP->Jet_phi[ij]);
		  if( dR > 0.3 ) continue;
		  int pdgid = abs(ntP->GenV0_pdgID[k]);
		  if( pdgid == 310 )  nK0s++;
		  if( pdgid == 3122 ) nLambda++;
	       }
	     if( isys == SYS_KSL_UP )
	       {			    
		  if( nK0s > 0 )    sf *= 1.3;
		  if( nLambda > 0 ) sf *= 1.5;
	       }
	  }
     }
   
   return sf;
}

// generated ntrk in b- and c- hadron decays sys
float LTANA::Syst::GenNTrk(int ij,int flavch,int isys)
{	
   float sf = 1.;
   
   if( !isdata )
     {		       		  
	// Weight in number of generated tracks from c-hadrons (+_3%)
	float WeightCtrkMin[] = 
	  {
	     1.83175, 1.09414, 0.969433, 0.957613, 0.944791, 0.93478, 0.951504, 0.933117, 0.933552, 1,
	     1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	  };
	float WeightCtrkMax[] = 
	  {
	     0.941931, 0.935278, 0.959889, 1.05731, 1.11384, 1.28445, 1, 1, 1, 1,
	     1, 1, 1, 1, 1, 1, 1, 1, 1, 1
	  };
	// Weight in number of generated tracks from b-hadrons (+_3%)
	float WeightBtrkMin[] = 
	  {
	     3.4573, 1.70516, 1.12162, 1.05566, 0.945077, 0.996961, 0.925635, 0.987391, 0.917369, 0.969089,
	     0.904673, 0.947409, 0.894847, 0.939174, 0.887052, 1, 1, 1, 1, 1
	  };
	float WeightBtrkMax[] = 
	  {
	     1.06921, 0.876405, 0.89011, 0.937056, 0.960934, 1.09521, 1.00306, 1.17408, 1.01393, 1.22725,
	     1.04056, 1.35842, 1.08842, 1.55228, 1.11446, 1, 1, 1, 1, 1
	  };
	
	int nChargedGen1_b = -1, nChargedGen2_b = -1;
	
	if( flavch == 1 )
	  {
	     for( int k=0;k<ntP->nBHadrons;k++ )
	       {
		  if( ntP->BHadron_hasBdaughter[k] == 1 ) continue;
		  double dR = helper->DeltaR(ntP->BHadron_eta[k], 
					     ntP->BHadron_phi[k], 
					     ntP->Jet_eta[ij], 
					     ntP->Jet_phi[ij]);
		  if( dR > 0.4 ) continue;
		  int k1 = ntP->BHadron_DHadron1[k];
		  int k2 = ntP->BHadron_DHadron2[k];
		  if( nChargedGen1_b >= 0 && nChargedGen2_b < 0 ) 
		    {
		       nChargedGen2_b  = ntP->BHadron_nCharged[k];
		       if( k1 >= 0 ) nChargedGen2_b += ntP->DHadron_nCharged[k1];
		       if( k2 >= 0 ) nChargedGen2_b += ntP->DHadron_nCharged[k2];
		    }
		  if( nChargedGen1_b < 0 ) 
		    {
		       nChargedGen1_b  = ntP->BHadron_nCharged[k];
		       if( k1 >= 0 ) nChargedGen1_b += ntP->DHadron_nCharged[k1];
		       if( k2 >= 0 ) nChargedGen1_b += ntP->DHadron_nCharged[k2];
		    }
	       }
	  }
	
	// Weight in track multiplicity from c-hadron and b-hadron decays
	int nchgen1_b = nChargedGen1_b, nchgen2_b = nChargedGen2_b;
	if( nchgen1_b > 19 ) nchgen1_b = 19;
	if( nchgen2_b > 19 ) nchgen2_b = 19;
	
	int nchgen1_c = _nChargedGen1_c, nchgen2_c = _nChargedGen2_c;
	if( nchgen1_c > 19 ) nchgen1_c = 19;
	if( nchgen2_c > 19 ) nchgen2_c = 19;
	
	if( isys == SYS_NTRKGEN_DOWN )
	  {
	     if( flavch == 2 )
	       {
		  if( nchgen1_c >= 0 ) sf *= WeightCtrkMin[nchgen1_c];
		  if( nchgen2_c >= 0 ) sf *= WeightCtrkMin[nchgen2_c];
	       }
	     if( flavch == 1 )
	       {
		  if( nchgen1_b >= 0 ) sf *= WeightBtrkMin[nchgen1_b];
		  if( nchgen2_b >= 0 ) sf *= WeightBtrkMin[nchgen2_b];
	       }
	  }
	if( isys == SYS_NTRKGEN_UP )
	  {
	     if( flavch == 2 )
	       {			    
		  if( nchgen1_c >= 0 ) sf *= WeightCtrkMax[nchgen1_c];
		  if( nchgen2_c >= 0 ) sf *= WeightCtrkMax[nchgen2_c];
	       }		       
	     if( flavch == 1 )
	       {			    
		  if( nchgen1_b >= 0 ) sf *= WeightBtrkMax[nchgen1_b];
		  if( nchgen2_b >= 0 ) sf *= WeightBtrkMax[nchgen2_b];
	       }
	  }
     } 
   
   return sf;
}

void LTANA::Syst::initRePU()
{   
   WeightPU[0] = 0.42814;
   WeightPU[1] = 0.852011;
   WeightPU[2] = 1.23782;
   WeightPU[3] = 1.50857;
   WeightPU[4] = 1.67743;
   WeightPU[5] = 1.71335;
   WeightPU[6] = 1.63117;
   WeightPU[7] = 1.4899;
   WeightPU[8] = 1.31817;
   WeightPU[9] = 1.13156;
   WeightPU[10] = 0.959846;
   WeightPU[11] = 0.793424;
   WeightPU[12] = 0.658323;
   WeightPU[13] = 0.536642;
   WeightPU[14] = 0.442476;
   WeightPU[15] = 0.364995;
   WeightPU[16] = 0.301626;
   WeightPU[17] = 0.245887;
   WeightPU[18] = 0.199188;
   WeightPU[19] = 0.158801;
   WeightPU[20] = 0.125015;
   WeightPU[21] = 0.0965054;
   WeightPU[22] = 0.0743175;
   WeightPU[23] = 0.0552261;
   WeightPU[24] = 0.0410448;
   WeightPU[25] = 0.0300012;
   WeightPU[26] = 0.0216022;
   WeightPU[27] = 0.01554;
   WeightPU[28] = 0.0109019;
   WeightPU[29] = 0.0077661;
   WeightPU[30] = 0.00527189;
   WeightPU[31] = 0.00367071;
   WeightPU[32] = 0.00247471;
   WeightPU[33] = 0.0016687;
   WeightPU[34] = 0.00223246;
   WeightPUmin[0] = 0.508648;
   WeightPUmin[1] = 1.00906;
   WeightPUmin[2] = 1.45877;
   WeightPUmin[3] = 1.76461;
   WeightPUmin[4] = 1.94019;
   WeightPUmin[5] = 1.9487;
   WeightPUmin[6] = 1.80937;
   WeightPUmin[7] = 1.59264;
   WeightPUmin[8] = 1.33497;
   WeightPUmin[9] = 1.06071;
   WeightPUmin[10] = 0.80788;
   WeightPUmin[11] = 0.577805;
   WeightPUmin[12] = 0.397835;
   WeightPUmin[13] = 0.257752;
   WeightPUmin[14] = 0.162172;
   WeightPUmin[15] = 0.0985342;
   WeightPUmin[16] = 0.0582882;
   WeightPUmin[17] = 0.0332803;
   WeightPUmin[18] = 0.0185821;
   WeightPUmin[19] = 0.0100938;
   WeightPUmin[20] = 0.0053696;
   WeightPUmin[21] = 0.00278412;
   WeightPUmin[22] = 0.00143351;
   WeightPUmin[23] = 0.000709667;
   WeightPUmin[24] = 0.000350299;
   WeightPUmin[25] = 0.00016959;
   WeightPUmin[26] = 8.06722e-05;
   WeightPUmin[27] = 3.82429e-05;
   WeightPUmin[28] = 1.76357e-05;
   WeightPUmin[29] = 8.23732e-06;
   WeightPUmin[30] = 3.65711e-06;
   WeightPUmin[31] = 1.66109e-06;
   WeightPUmin[32] = 7.28646e-07;
   WeightPUmin[33] = 3.18864e-07;
   WeightPUmin[34] = 2.06626e-07;
   WeightPUmax[0] = 0.321623;
   WeightPUmax[1] = 0.633854;
   WeightPUmax[2] = 0.929572;
   WeightPUmax[3] = 1.1604;
   WeightPUmax[4] = 1.34017;
   WeightPUmax[5] = 1.44133;
   WeightPUmax[6] = 1.46356;
   WeightPUmax[7] = 1.44183;
   WeightPUmax[8] = 1.3872;
   WeightPUmax[9] = 1.30012;
   WeightPUmax[10] = 1.20261;
   WeightPUmax[11] = 1.07688;
   WeightPUmax[12] = 0.957174;
   WeightPUmax[13] = 0.824407;
   WeightPUmax[14] = 0.708206;
   WeightPUmax[15] = 0.601179;
   WeightPUmax[16] = 0.506317;
   WeightPUmax[17] = 0.417744;
   WeightPUmax[18] = 0.340911;
   WeightPUmax[19] = 0.272991;
   WeightPUmax[20] = 0.215471;
   WeightPUmax[21] = 0.166586;
   WeightPUmax[22] = 0.128399;
   WeightPUmax[23] = 0.0954633;
   WeightPUmax[24] = 0.0709704;
   WeightPUmax[25] = 0.0518837;
   WeightPUmax[26] = 0.0373623;
   WeightPUmax[27] = 0.0268788;
   WeightPUmax[28] = 0.0188572;
   WeightPUmax[29] = 0.0134334;
   WeightPUmax[30] = 0.00911912;
   WeightPUmax[31] = 0.00634949;
   WeightPUmax[32] = 0.0042807;
   WeightPUmax[33] = 0.00288649;
   WeightPUmax[34] = 0.00107161;
}

void LTANA::Syst::clear()
{
   delete _v_jet;
   delete _v_jet_sys_jesTotalUp;
   delete _v_jet_sys_jesTotalDown;
   delete _v_jet_sys_jerTotalUp;
   delete _v_jet_sys_jerTotalDown;
}
