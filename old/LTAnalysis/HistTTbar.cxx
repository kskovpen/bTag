#include "HistTTbar.h"
#include "RangesTTbar.h"

LTANA::HistTTbar::HistTTbar()
{
}

LTANA::HistTTbar::~HistTTbar()
{
}

void LTANA::HistTTbar::init()
{      
//   rnd = new TRandom3(666);

/*   _fd0s = new TFile("/home/kskovpen/work/testarea/WRHN2012/ANALYSIS_v09/17.2.4.4/SKYPlot/run/macro/d0s.root");
   _gd0s = (TGraphErrors*)_fd0s->Get("sf");
*/   
/////   std::string foutName = "hist/"+std::string(foutname)+".root";
   std::string foutName = "hist.root";
   _fout = new TFile(foutName.c_str(),"RECREATE");
//   std::string fevcName = "ev.txt";
//   _fevc.open(fevcName.c_str());

   muptcut = 5.;
//   muptcut = 8.;
   
   rw_n = 1;
   name_rw[0] = "1d_eta";
//   name_rw[0] = "1d_mupt";
//   name_rw[0] = "1d_ntrk";
//   name_rw[0] = "1d_njet";
//   name_rw[0] = "1d_pt";

   name_rw_2d = "2d_ntrk_vs_mupt";
   
   name_rw_3d = "3d_ntrk_pt_mupt";
   
   initRePU();
   
   hname.clear();

//   psSf.clear();

   int nbins = 100;
//   int nbins3d = 10;

   histname_jet_3d_n = 0;
//   histname_jet_3d[0] = "h_j1_ntrk_vs_pt_vs_mupt_";

//   histname_jet_2d_n = 4;
   histname_jet_2d_n = 0;
//   histname_jet_2d[0] = "h_j1_JP_vs_pt_";
//   histname_jet_2d[1] = "h_j1_JP_vs_mupt_";
//   histname_jet_2d[2] = "h_j1_JP_vs_ntrk_";
//   histname_jet_2d[3] = "h_j1_ntrk_vs_mupt_";
   
//   histname_jet_n = 17;
//   histname_jet_n = 2;
   histname_jet_n = 6;
   histname_jet[0] = "h_j1_pt_";
   histname_jet[1] = "h_j1_JP_";
   histname_jet[2] = "h_j1_ntrk_";
   histname_jet[3] = "h_j1_njet_";
   histname_jet[4] = "h_j1_eta_";
   histname_jet[5] = "h_j1_mupt_"; // has to be the last in the list

//   histname_jet[0] = "h_j1_pt_";
//   histname_jet[1] = "h_j1_JP_";

/*   histname_jet[4] = "h_j1_mupt_";
   histname_jet[5] = "h_j1_eta_";
   histname_jet[6] = "h_j1_phi_";
   histname_jet[7] = "h_j1_mass_";
//   histname_jet[7] = "h_j1_mueta_";
//   histname_jet[8] = "h_j1_muphi_";
//   histname_jet[9] = "h_j1_muptrel_";
   histname_jet[8] = "h_j1_svntrk_";
   histname_jet[9] = "h_j1_svmass_";
//   histname_jet[12] = "h_j1_npv_";
//   histname_jet[13] = "h_j1_npu_";
   histname_jet[10] = "h_j1_nmuon_";
   histname_jet[11] = "h_j1_nsv_";
  */
//   histname_jet[2] = "h_j1_pthat_";

   sel_n = 6;
   sel[0] = "nosel";
   sel[1] = "pt30t50";
   sel[2] = "pt50t80";
   sel[3] = "pt80t120";
   sel[4] = "pt120t210";
   sel[5] = "pt210t320";
//   sel[6] = "pt320t500";
//   sel[7] = "pt500t800";

   jPtMin[0] = 30; jPtMax[0] = 50;
   jPtMin[1] = 50; jPtMax[1] = 80;
   jPtMin[2] = 80; jPtMax[2] = 120;
   jPtMin[3] = 120; jPtMax[3] = 210;
   jPtMin[4] = 210; jPtMax[4] = 320;
//   jPtMin[5] = 320; jPtMax[5] = 500;
//   jPtMin[6] = 500; jPtMax[6] = 800;
   
   eta_n = 1;
   eta[0] = "nosel";

   selb_n = 5;
   selb[0] = "nosel";
   selb[1] = "combSvx0p244"; // Loose
   selb[2] = "combSvx0p679"; // Medium
   selb[3] = "combSvx0p898"; // Tight
   selb[4] = "UNTAGbc";

   seladd_n = 1;
   seladd[0] = "";
//   seladd[1] = "_ntrkGE1";
//   seladd[2] = "_ntrkGE2";
//   seladd[3] = "_ntrkGE4";
//   seladd[4] = "_ntrkGE7";
//   seladd[5] = "_ntrkGE10";
   
   flav_n = 4;
   flav[0] = "ajet";
   flav[1] = "bjet";
   flav[2] = "cjet";
   flav[3] = "ljet";

//   sys_low_n = 10;
////   sys_low_n = 1;
////   sys_low[0]   = "";
/*   sys_low[1]   = "_pu_low";
   sys_low[2]   = "_gsplit_low";
   sys_low[3]   = "_bfrag_low";
   sys_low[4]   = "_cdfrag_low";
   sys_low[5]   = "_cfrag_low";
   sys_low[6]   = "_ksl_low";
   sys_low[7]   = "_ntrkgen_low";
   sys_low[8]   = "_jes_low";
   sys_low[9]   = "_jer_low";*/
//   sys_low[3]   = "_smcALL_low";
//   sys_low[4]   = "_smearDIR_low";

/////   sys_up_n = sys_low_n-1;
/*   sys_up[0]   = "_pu_up";
   sys_up[1]   = "_gsplit_up";
   sys_up[2]   = "_bfrag_up";
   sys_up[3]   = "_cdfrag_up";
   sys_up[4]   = "_cfrag_up";
   sys_up[5]   = "_ksl_up";
   sys_up[6]   = "_ntrkgen_up";
   sys_up[7]   = "_jes_up";
   sys_up[8]   = "_jer_up";*/
//   sys_up[2]   = "_smcALL_up";
//   sys_up[3]   = "_smearDIR_up";

//   sys_low_n = 5;
   sys_low_n = 1;
   sys_low[0]   = "";
/*   sys_low[1]   = "_pu_low";
   sys_low[2]   = "_bfrag_low";
   sys_low[3]   = "_jes_low";
   sys_low[4]   = "_jer_low";
*/
   sys_up_n = sys_low_n-1;
/*   sys_up[0]   = "_pu_up";
   sys_up[1]   = "_bfrag_up";
   sys_up[2]   = "_jes_up";
   sys_up[3]   = "_jer_up";
*/  
   sys_n = sys_low_n + sys_up_n;
   
   for(int is1=0;is1<sys_low_n;is1++)
     {
	sys[is1] = sys_low[is1];
     }   
   for(int is2=0;is2<sys_up_n;is2++)
     {
	sys[sys_low_n+is2] = sys_up[is2];
     }   

   rwBin.clear();
   rwSf.clear();
   rwBin_btag.clear();
   rwSf_btag.clear();
   
   _s_Jet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m1d_Jet = new std::map<std::string, TH1D*>();

   _s2_Jet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m2d_Jet = new std::map<std::string, TH2D*>();

   _s3_Jet = new std::vector<std::pair<std::vector<std::string>,double*> >();
   _m3d_Jet = new std::map<std::string, TH3D*>();

   std::vector<double*> set_hist_jet;
   set_hist_jet.clear();

   std::vector<double*> set_hist_jet_2d;
   set_hist_jet_2d.clear();

   std::vector<double*> set_hist_jet_3d;
   set_hist_jet_3d.clear();

   set_hist_jet.push_back(RANGETTBAR::set_j_pt);
   set_hist_jet.push_back(RANGETTBAR::set_j_JP);
   set_hist_jet.push_back(RANGETTBAR::set_j_ntrk);
   set_hist_jet.push_back(RANGETTBAR::set_j_njet);
   set_hist_jet.push_back(RANGETTBAR::set_j_eta);
   
////   set_hist_jet.push_back(RANGE::set_j_mupt);
//   set_hist_jet.push_back(RANGE::set_j_eta);
//   set_hist_jet.push_back(RANGE::set_j_phi);
//   set_hist_jet.push_back(RANGE::set_j_mass);
//   set_hist_jet.push_back(set_j_mueta);
//   set_hist_jet.push_back(set_j_muphi);
//   set_hist_jet.push_back(set_j_muptrel);
//   set_hist_jet.push_back(RANGE::set_j_svntrk);
//   set_hist_jet.push_back(RANGE::set_j_svmass);
//   set_hist_jet.push_back(set_j_npv);
//   set_hist_jet.push_back(set_j_npu);
//   set_hist_jet.push_back(RANGE::set_j_nmuon);
//   set_hist_jet.push_back(RANGE::set_j_nsv);
  
//   set_hist_jet_2d.push_back(set_j_2d_ntrk_vs_pt);
//   set_hist_jet_2d.push_back(set_j_2d_ntrk_vs_mupt);

   set_hist_jet_2d.push_back(RANGETTBAR::set_j_2d_JP_vs_pt);
   set_hist_jet_2d.push_back(RANGETTBAR::set_j_2d_JP_vs_mupt);
   set_hist_jet_2d.push_back(RANGETTBAR::set_j_2d_JP_vs_ntrk);
   set_hist_jet_2d.push_back(RANGETTBAR::set_j_2d_ntrk_vs_mupt);
   
//   set_hist_jet_3d.push_back(set_j_3d_ntrk_vs_pt_vs_mupt);
   
//   set_hist_event.push_back(set_event_mjjMax);

   std::string titl;
   
   for(int j=0;j<flav_n;j++)
     {	
	for(int ss=0;ss<sel_n;ss++)
	  {
	     for(int se=0;se<eta_n;se++)
	       {
		  for(int ssb=0;ssb<selb_n;ssb++)
		    {
		       for(int ssa=0;ssa<seladd_n;ssa++)
			 {
			    for(int h=0;h<histname_jet_n;h++)
			      {
				 std::string hn = histname_jet[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa];
				 hname.push_back(hn);
				 
				 for(int s=0;s<sys_n;s++)
				   {
				      titl = hn+sys[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sys[s]);
				      if( h == 5 )
					_s_Jet->push_back(std::make_pair(names,RANGETTBAR::set_j_mupt[ss]));
//				      else if( h == 1 )
//				      else if( h == 4 )
//					_s_Jet->push_back(std::make_pair(names,RANGE::set_j_JP[ss]));
				      else
					_s_Jet->push_back(std::make_pair(names,set_hist_jet.at(h)));
				   }				 
			      }

			    for(int h=0;h<histname_jet_2d_n;h++)
			      {
				 std::string hn = histname_jet_2d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa];
				 hname.push_back(hn);
				 
				 for(int s=0;s<sys_n;s++)
				   {
				      titl = hn+sys[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sys[s]);

				      _s2_Jet->push_back(std::make_pair(names,set_hist_jet_2d.at(h)));
				   }				 
			      }

			    for(int h=0;h<histname_jet_3d_n;h++)
			      {
				 std::string hn = histname_jet_3d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa];
				 hname.push_back(hn);
				 
				 for(int s=0;s<sys_n;s++)
				   {
				      titl = hn+sys[s];
				      std::vector<std::string> names;
				      names.clear();
				      names.push_back(titl);
				      names.push_back(sys[s]);

				      _s3_Jet->push_back(std::make_pair(names,set_hist_jet_3d.at(h)));
				   }				 
			      }
			 }
		    }		  
	       }
	  }
     }   
   
   for(int i=0;i<_s_Jet->size();i++)
     {
	TH1D *_h1d = new TH1D(_s_Jet->at(i).first.at(0).c_str(),
			      _s_Jet->at(i).first.at(0).c_str(),
			      _s_Jet->at(i).second[0],
			      _s_Jet->at(i).second[1],
			      _s_Jet->at(i).second[2]);
	
	_h1d->Sumw2();
	
	_m1d_Jet->insert(std::pair<std::string,TH1D*>(_s_Jet->at(i).first.at(0),_h1d));
     }
	
   for(int i=0;i<_s2_Jet->size();i++)
     {
	TH2D *_h2d = new TH2D(_s2_Jet->at(i).first.at(0).c_str(),
			      _s2_Jet->at(i).first.at(0).c_str(),
			      _s2_Jet->at(i).second[0],
			      _s2_Jet->at(i).second[1],
			      _s2_Jet->at(i).second[2],
			      _s2_Jet->at(i).second[3],
			      _s2_Jet->at(i).second[4],
			      _s2_Jet->at(i).second[5]);
	
	_h2d->Sumw2();
	
	_m2d_Jet->insert(std::pair<std::string,TH2D*>(_s2_Jet->at(i).first.at(0),_h2d));
     }

   for(int i=0;i<_s3_Jet->size();i++)
     {
	TH3D *_h3d = new TH3D(_s3_Jet->at(i).first.at(0).c_str(),
			      _s3_Jet->at(i).first.at(0).c_str(),
			      _s3_Jet->at(i).second[0],
			      _s3_Jet->at(i).second[1],
			      _s3_Jet->at(i).second[2],
			      _s3_Jet->at(i).second[3],
			      _s3_Jet->at(i).second[4],
			      _s3_Jet->at(i).second[5],
			      _s3_Jet->at(i).second[6],
			      _s3_Jet->at(i).second[7],
			      _s3_Jet->at(i).second[8]);
	
	_h3d->Sumw2();
	
	_m3d_Jet->insert(std::pair<std::string,TH3D*>(_s3_Jet->at(i).first.at(0),_h3d));
     }

   if( doRW )
     {       
	std::cout << "Read corrections" << std::endl;
	
	TFile fcor("corrections.root");
	
	if( !fcor.IsOpen() )
	  {
	     std::cout << "Input file with RW factors can not be opened !" << std::endl;
	     exit(1);
	  }
	if( doRW == 1 )
	  {	     
	     for(int isf=0;isf<rw_n;isf++)
	       {
		  std::vector<std::vector<std::pair<double,double> > > v_ptBin;
		  std::vector<std::vector<std::pair<double,double> > > v_ptSf;
		  v_ptBin.clear();
		  v_ptSf.clear();
		  
		  for(int ipt=0;ipt<sel_n;ipt++)
		    {		       
		       std::string sfname = "sf_"+sel[ipt]+"_nosel_"+name_rw[isf];
		       TH1D *hSF = (TH1D*)fcor.Get(sfname.c_str());
		       std::cout << sfname << std::endl;
		       
		       std::vector<std::pair<double,double> > v_valBin;
		       std::vector<std::pair<double,double> > v_valSf;
		       v_valBin.clear();
		       v_valSf.clear();
		       
		       int nb = hSF->GetXaxis()->GetNbins();
		       for(int ib=1;ib<=nb;ib++)
			 {		  
			    float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
			    float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
			    float sf = hSF->GetBinContent(ib);
			    float sferr = hSF->GetBinError(ib);
			    
			    std::pair<double,double> binfo = std::make_pair(pt1,pt2);
			    std::pair<double,double> sfinfo = std::make_pair(sf,sferr);
			    v_valBin.push_back(binfo);
			    v_valSf.push_back(sfinfo);
			 }
		       v_ptBin.push_back(v_valBin);
		       v_ptSf.push_back(v_valSf);
		    }	     
		  rwBin.push_back(v_ptBin);
		  rwSf.push_back(v_ptSf);
		  //
		  v_ptBin.clear();
		  v_ptSf.clear();
		  
		  for(int ipt=0;ipt<sel_n;ipt++)
		    {		       
		       std::string sfname = "sf_"+sel[ipt]+"_"+selb[1]+"_"+name_rw[isf];
		       TH1D *hSF = (TH1D*)fcor.Get(sfname.c_str());
		       std::cout << sfname << std::endl;
		       
		       std::vector<std::pair<double,double> > v_valBin;
		       std::vector<std::pair<double,double> > v_valSf;
		       v_valBin.clear();
		       v_valSf.clear();
		       
		       int nb = hSF->GetXaxis()->GetNbins();
		       for(int ib=1;ib<=nb;ib++)
			 {		  
			    float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
			    float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
			    float sf = hSF->GetBinContent(ib);
			    float sferr = hSF->GetBinError(ib);
			    
			    std::pair<double,double> binfo = std::make_pair(pt1,pt2);
			    std::pair<double,double> sfinfo = std::make_pair(sf,sferr);
			    v_valBin.push_back(binfo);
			    v_valSf.push_back(sfinfo);
			 }
		       v_ptBin.push_back(v_valBin);
		       v_ptSf.push_back(v_valSf);
		    }	     
		  rwBin_btag.push_back(v_ptBin);
		  rwSf_btag.push_back(v_ptSf);
	       }		
	  }
/*	if( doRW == 2 )
	  {
	     std::vector<std::vector<std::pair<double,double> > > v_pt2DBinX;
	     std::vector<std::vector<std::pair<double,double> > > v_pt2DBinY;
	     std::vector<std::vector<std::pair<double,double> > > v_pt2DSf;
	     v_pt2DBinX.clear();
	     v_pt2DBinY.clear();
	     v_pt2DSf.clear();
		  
	     for(int ipt=0;ipt<sel_n;ipt++)
	       {		       
		  std::string sfname = "sf_"+sel[ipt]+"_nosel_"+name_rw_2d;
		  TH2D *hSF = (TH2D*)fcor.Get(sfname.c_str());
		  std::cout << sfname << std::endl;
		       
		  std::vector<std::pair<double,double> > v_val2DBinX;
		  std::vector<std::pair<double,double> > v_val2DBinY;
		  std::vector<std::pair<double,double> > v_val2DSf;
		  v_val2DBinX.clear();
		  v_val2DBinY.clear();
		  v_val2DSf.clear();
		       
		  int nbX = hSF->GetXaxis()->GetNbins();
		  for(int ib=1;ib<=nbX;ib++)
		    {		  
		       float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val2DBinX.push_back(binfo);
		    }
		  v_pt2DBinX.push_back(v_val2DBinX);

		  int nbY = hSF->GetYaxis()->GetNbins();
		  for(int ib=1;ib<=nbY;ib++)
		    {		  
		       float pt1 = hSF->GetYaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetYaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val2DBinY.push_back(binfo);
		    }
		  v_pt2DBinY.push_back(v_val2DBinY);

		  for(int ibx=1;ibx<=nbX;ibx++)
		    {		  
		       for(int iby=1;iby<=nbY;iby++)
			 {		  
			    float sf = hSF->GetBinContent(ibx,iby);
			    float sferr = hSF->GetBinError(ibx,iby);
			    
			    std::pair<double,double> sfinfo = std::make_pair(sf,sferr);
			    v_val2DSf.push_back(sfinfo);
			 }		       
		    }
		  
		  v_pt2DSf.push_back(v_val2DSf);
	       }
	     
	     rw2DBinX.push_back(v_pt2DBinX);
	     rw2DBinY.push_back(v_pt2DBinY);
	     
	     rw2DSf.push_back(v_pt2DSf);
	  }	
	if( doRW == 3 )
	  {
	     std::vector<std::vector<std::pair<double,double> > > v_pt3DBinX;
	     std::vector<std::vector<std::pair<double,double> > > v_pt3DBinY;
	     std::vector<std::vector<std::pair<double,double> > > v_pt3DBinZ;
	     std::vector<std::vector<std::pair<double,double> > > v_pt3DSf;
	     v_pt3DBinX.clear();
	     v_pt3DBinY.clear();
	     v_pt3DBinZ.clear();
	     v_pt3DSf.clear();
		  
	     for(int ipt=0;ipt<sel_n;ipt++)
	       {		       
		  std::string sfname = "sf_"+sel[ipt]+"_nosel_"+name_rw_3d;
		  TH3D *hSF = (TH3D*)fcor.Get(sfname.c_str());
		  std::cout << sfname << std::endl;
		       
		  std::vector<std::pair<double,double> > v_val3DBinX;
		  std::vector<std::pair<double,double> > v_val3DBinY;
		  std::vector<std::pair<double,double> > v_val3DBinZ;
		  std::vector<std::pair<double,double> > v_val3DSf;
		  v_val3DBinX.clear();
		  v_val3DBinY.clear();
		  v_val3DBinZ.clear();
		  v_val3DSf.clear();
		       
		  int nbX = hSF->GetXaxis()->GetNbins();
		  for(int ib=1;ib<=nbX;ib++)
		    {		  
		       float pt1 = hSF->GetXaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetXaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val3DBinX.push_back(binfo);
		    }
		  v_pt3DBinX.push_back(v_val3DBinX);

		  int nbY = hSF->GetYaxis()->GetNbins();
		  for(int ib=1;ib<=nbY;ib++)
		    {		  
		       float pt1 = hSF->GetYaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetYaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val3DBinY.push_back(binfo);
		    }
		  v_pt3DBinY.push_back(v_val3DBinY);

		  int nbZ = hSF->GetZaxis()->GetNbins();
		  for(int ib=1;ib<=nbZ;ib++)
		    {		  
		       float pt1 = hSF->GetZaxis()->GetBinLowEdge(ib);
		       float pt2 = hSF->GetZaxis()->GetBinUpEdge(ib);
		       
		       std::pair<double,double> binfo = std::make_pair(pt1,pt2);
		       v_val3DBinZ.push_back(binfo);
		    }
		  v_pt3DBinZ.push_back(v_val3DBinZ);
		  
		  for(int ibx=1;ibx<=nbX;ibx++)
		    {		  
		       for(int iby=1;iby<=nbY;iby++)
			 {		  
			    for(int ibz=1;ibz<=nbZ;ibz++)
			      {		  
				 float sf = hSF->GetBinContent(ibx,iby,ibz);
				 float sferr = hSF->GetBinError(ibx,iby,ibz);
				 
				 std::pair<double,double> sfinfo = std::make_pair(sf,sferr);
				 v_val3DSf.push_back(sfinfo);
			      }
			 }		       
		    }
		  
		  v_pt3DSf.push_back(v_val3DSf);
	       }
	     
	     rw3DBinX.push_back(v_pt3DBinX);
	     rw3DBinY.push_back(v_pt3DBinY);
	     rw3DBinZ.push_back(v_pt3DBinZ);
	     
	     rw3DSf.push_back(v_pt3DSf);
	  }	*/
	fcor.Close();
     }
/*
   // read out LUMI after PRESCALE
   ifstream infilePS;
   
   if( doLUMI )
     {       
	infilePS.open("/home/kskovpen/work/testarea/JetTag/ANALYSIS_v12/17.2.4.4/JTPlot2012Lite/run/macro/fit/run/LUMIPRESCALE.txt");
	
	if( !infilePS.is_open() )
	  {
	     std::cout << "Input file with LUMI data can not be opened !" << std::endl;
	     exit(1);
	  }   
	while( !infilePS.eof() )
	  {
	     int nbin;
	     float sf;
	     infilePS >> nbin >> sf;
	     psSf.push_back(sf);
	  }
	infilePS.close();
     }*/
   
   jesTotal = new JetCorrectionUncertainty(*(new JetCorrectorParameters("Summer13_V5_DATA_UncertaintySources_AK5PF.txt", "Total")));      

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
   
   for(int j=0;j<flav_n;j++)
     {	
	for(int ss=0;ss<sel_n;ss++)
	  {
	     for(int se=0;se<eta_n;se++)
	       {   
		  for(int ssb=0;ssb<selb_n;ssb++)
		    {
		       for(int ssa=0;ssa<seladd_n;ssa++)
			 {
			    for(int s=0;s<sys_n;s++)
			      {
				 for(int h=0;h<histname_jet_n;h++)
				   {
				      histNAMES[j][ss][se][ssb][ssa][h][s] =
					histname_jet[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa]+sys[s];
				   }

				 for(int h=0;h<histname_jet_2d_n;h++)
				   {
				      histNAMES_2d[j][ss][se][ssb][ssa][h][s] =
					histname_jet_2d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa]+sys[s];
				   }

				 for(int h=0;h<histname_jet_3d_n;h++)
				   {
				      histNAMES_3d[j][ss][se][ssb][ssa][h][s] =
					histname_jet_3d[h]+flav[j]+"_"+sel[ss]+"_"+eta[se]+"_"+selb[ssb]+seladd[ssa]+sys[s];
				   }
			      }			    
			 }		       
		    }		  
	       }
	  }
     }
   
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
	
   std::cout << "Initialisation done" << std::endl;
}

void LTANA::HistTTbar::fill()
{
   double w = noe/(xsec*eff);
   float pthat = ntPT->pthat;

   if( isdata ) w = 1.;
   
   // correction factors
   if( !isdata )
     {
	// trigger eff x lepton reco+id
	w *= 0.978*0.986;
     }   
   
   float mc_weight = ntPT->mcweight;
   if( !isdata ) w *= mc_weight;
   
   std::string foutnameStr = std::string(foutname);

   if( foutnameStr.find("DY") != std::string::npos &&
       !isdata )
     {
	w *= 1.33;
     }   
   
   int npu = ntPT->nPU;
   if( ntPT->Run < 0 ) npu = int(ntPT->nPUtrue);
   if( npu > 49 ) npu = 49;
//   float wPU = WeightPU[npu];
//   if( !isdata ) w *= wPU;

//   int jidx = 0; // highest-Pt jet
   int jidx = -1; // all jets

   // Event
   
   if( ntPT->ttbar_chan != 2 ) return;
   
//   if( ntPT->nMuon == 0 ) return;

   int ntNJET = ntPT->nJet;
   
   // Trigger

   bool passEE = 0;
   bool passMM = 0;
   bool passEM = 0;
   
   int trigTTbar = ntPT->trig_ttbar;
   
   if( trigTTbar >= 20 )
     {
	passEM = 1;
	trigTTbar -= 20;
     }
   if( trigTTbar >= 10 )
     {
	passEM = 1;
	trigTTbar -= 10;
     }
   if( trigTTbar >= 4 )
     {
	passMM = 1;
	trigTTbar -= 4;
     }
   if( trigTTbar >= 2 )
     {
	passMM = 1;
	trigTTbar -= 2;
     }
   if( trigTTbar >= 1 )
     {
	passEE = 1;
     }	

   if( !passEM ) return;

   // Loop on jets
   
   int nJetMax = (jidx >= 0 && ntNJET >= jidx) ? jidx+1 : ntNJET;

   for(int ij=0;ij<nJetMax;ij++)
     {
	if( ntPT->Jet_ProbaP[ij] == 0 ) continue;	

	Jet_Proba_New = ntPT->Jet_ProbaP[ij];
	if( Jet_Proba_New == 0. ) Jet_Proba_New = -1.;
	
//	std::cout << "jet#" << ij << " " << ntP->nTrkInc << std::endl;
	
	v_jet = new TLorentzVector(0,0,0,0);
	v_jet_sys_jesTotalUp = new TLorentzVector(0,0,0,0);
	v_jet_sys_jesTotalLow = new TLorentzVector(0,0,0,0);
	v_jet_sys_jerTotalUp = new TLorentzVector(0,0,0,0);
	v_jet_sys_jerTotalLow = new TLorentzVector(0,0,0,0);
	v_mu = new TLorentzVector(0,0,0,0);

	bool passSel = true;
	
	float jeta = ntPT->Jet_eta[ij];
	float jphi = ntPT->Jet_phi[ij];
//	float jm = ntPT->Jet_mass[ij];
	float residual = 1.;
	if( ntPT->Run > 0 ) residual = ntPT->Jet_residual[ij];
	float jpt = ntPT->Jet_pt[ij] * residual;
	
	// JER

//	v_jet_sys_jerTotalUp->SetPtEtaPhiM(jpt,jeta,jphi,jm);
//	v_jet_sys_jerTotalLow->SetPtEtaPhiM(jpt,jeta,jphi,jm);
	v_jet_sys_jerTotalUp->SetPtEtaPhiM(jpt,jeta,jphi,0.);
	v_jet_sys_jerTotalLow->SetPtEtaPhiM(jpt,jeta,jphi,0.);
	
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
		  double genpt = ntPT->Jet_genpt[ij];
		  if( genpt >= 0. )
		    {
		       jpt_c = genpt + cJER[etaIdx]*(jpt-genpt);
		       
		       double jpt_c_down = genpt + cJER_down[etaIdx]*(jpt-genpt);
		       double jpt_c_up = genpt + cJER_up[etaIdx]*(jpt-genpt);
		       
		       if( jpt_c < 0. ) jpt_c = 0.;
		       if( jpt_c_down < 0. ) jpt_c_down = 0.;
		       if( jpt_c_up < 0. ) jpt_c_up = 0.;
		       
//		       v_jet_sys_jerTotalUp->SetPtEtaPhiM(jpt_c_up,jeta,jphi,jm);
//		       v_jet_sys_jerTotalLow->SetPtEtaPhiM(jpt_c_down,jeta,jphi,jm);

		       v_jet_sys_jerTotalUp->SetPtEtaPhiM(jpt_c_up,jeta,jphi,0.);
		       v_jet_sys_jerTotalLow->SetPtEtaPhiM(jpt_c_down,jeta,jphi,0.);
		       
//		  std::cout << jpt_c << "-" << jpt_c_down << "+" << jpt_c_up << std::endl;
		    }
	       }	     

	     jpt = jpt_c;
	  }	
	     
//	v_jet->SetPtEtaPhiM(jpt,jeta,jphi,jm);
	v_jet->SetPtEtaPhiM(jpt,jeta,jphi,0.);
	
	if( jpt < 20. || jpt > 1500. ) passSel = false;
	if( fabs(jeta) > 2.4 ) passSel = false;

//	if( ntP->Evt == 983779189 && ij == 1 )
//	  std::cout << "jet#" << ij << " pt=" << ntP->Jet_pt[ij] <<
//	  " eta=" << ntP->Jet_eta[ij] <<
//	  " passSel=" << passSel << std::endl;
	
	int njet = ntNJET;
	
//	int ntrk = ntPT->Jet_ntracks[ij];
	int ntrk = nTrk(ij);
////	if( ntrk == 0 ) passSel = false;
	
//	v_jet_sys_jesTotalUp->SetPtEtaPhiM(jpt,jeta,jphi,jm);
//	v_jet_sys_jesTotalLow->SetPtEtaPhiM(jpt,jeta,jphi,jm);

	v_jet_sys_jesTotalUp->SetPtEtaPhiM(jpt,jeta,jphi,0.);
	v_jet_sys_jesTotalLow->SetPtEtaPhiM(jpt,jeta,jphi,0.);
	
	// JES
	jesTotal->setJetPt(jpt);
	jesTotal->setJetEta(jeta);
	double uncert = jesTotal->getUncertainty(true);
	
	v_jet_sys_jesTotalUp->SetPtEtaPhiE(jpt*(1.+uncert),
					   jeta,
					   v_jet->Phi(),
					   v_jet->E()*(1.+uncert));
	
	v_jet_sys_jesTotalLow->SetPtEtaPhiE(jpt*(1.-uncert),
					    jeta,
					    v_jet->Phi(),
					    v_jet->E()*(1.-uncert));
	
	// muon-in-jet
//	std::vector<int> muidx;
	muidx.clear();

	for(int imu=0;imu<ntPT->nMuon;imu++)
	  {
	     if( ntPT->Muon_IdxJet[imu] == ij )
	       {	    
/*		  if( ntPT->Muon_isGlobal[imu] == 0 ) continue;
		  if( ntPT->Muon_pt[imu] < muptcut ) continue;
		  if( ntPT->Muon_nMuHit[imu] == 0 ) continue;
		  if( ntPT->Muon_nTkHit[imu] < 11 ) continue;
		  if( ntPT->Muon_nPixHit[imu] < 2 ) continue;
		  if( ntPT->Muon_nOutHit[imu] > 2 ) continue;
		  if( ntPT->Muon_nMatched[imu] < 2 ) continue;
		  if( ntPT->Muon_chi2[imu] > 10. ) continue;
		  if( ntPT->Muon_chi2Tk[imu] > 10. ) continue;
		  if( fabs(ntPT->Muon_eta[imu]) > 2.4 ) continue;*/
		  muidx.push_back(imu);
	       }
	  }
	bool passMuonInJet = (muidx.size() > 0);
	
	int jFlavour = ntPT->Jet_flavour[ij];
	if( jFlavour >= 1 && jFlavour <= 3 ) jFlavour = 1;

	std::string flavch = "NOTFOUND";
	int flavchI = 0;
	if( jFlavour == 5 )  {flavch = "bjet"; flavchI = 1;}
	if( jFlavour == 4 )  {flavch = "cjet"; flavchI = 2;}
	if( jFlavour == 1 || jFlavour == 21 )  {flavch = "ljet"; flavchI = 3;}
	
	std::string selch = "NOTFOUND";
	std::string etach = "NOTFOUND";
	std::string selbch = "NOTFOUND";
   
	float drjmu = -666;
	if( passMuonInJet )
	  {
	     for(int im=0;im<muidx.size();im++)
	       {		  
		  float mupt = ntPT->Muon_pt[muidx[im]];
		  float mueta = ntPT->Muon_eta[muidx[im]];
		  float muphi = ntPT->Muon_phi[muidx[im]];
		  float mum = 0.10566;
		  v_mu->SetPtEtaPhiM(mupt,mueta,muphi,mum);
		  drjmu = v_jet->DeltaR(*v_mu);
		  if( drjmu < 0.4 ) break;
	       }	     
	  }	
	
/////	if( drjmu > 0.4 || drjmu < 0 ) passSel = false;
	
	// END SELECTION
	
	if( passSel )
	  {
//	     if( fabs(jFlavour) == 5 && ntP->Jet_CombSvx[ij] >= 0.679 )
//	       _fevc << ntP->Evt << " " << ntP->Jet_Proba[ij]*10. << " " << jpt << " " << w*WeightPU[npu] << std::endl;
	     
	     bool selbch_res[selb_n];
	     for( int ibt=0;ibt<selb_n;ibt++ ) selbch_res[ibt] = false;
	     
	     float jbtCombSvx = ntPT->Jet_CombSvx[ij];
	     
	     selbch_res[0] = true;
	     if( jbtCombSvx >= 0.244 ) selbch_res[1] = true;
//	     if( jbtCombSvx < 0.679 ) selbch_res[2] = true;
	     if( jbtCombSvx >= 0.679 ) selbch_res[2] = true;
//	     if( jbtCombSvx < 0.244 ) selbch_res[2] = true;
	     if( jbtCombSvx >= 0.898 ) selbch_res[3] = true;
	     if( jbtCombSvx < 0.898 ) selbch_res[4] = true;
	     
//	     if( ntP->Jet_Proba[ij] == 0. && ntP->Jet_CombSvx[ij] > 0.244 )
//	       std::cout << ntP->Jet_CombSvx[ij] << std::endl;

	     bool selach_res[seladd_n];
	     for( int ibt=0;ibt<seladd_n;ibt++ ) selach_res[ibt] = false;

	     selach_res[0] = true;
//	     if( ntrk >= 1 ) selach_res[1] = true;
//	     if( ntrk >= 2 ) selach_res[2] = true;
//	     if( ntrk >= 4 ) selach_res[3] = true;
//	     if( ntrk >= 7 ) selach_res[4] = true;
//	     if( ntrk >= 10 ) selach_res[5] = true;
	     
	     for(int isys=0;isys<sys_n;isys++)
	       {	
		  float jPT = getPt(sys[isys]);
		  
		  double sfj = w;
		  
		  // l-jets are underestimated in MC by 1.27
		  if( flavchI == 3 ) sfj *= 1.27;

		  // pileup reweighting sys
		  float wPU = WeightPU[npu];
		  if( sys[isys] == "_pu_up" ) wPU = WeightPUmax[npu];
		  if( sys[isys] == "_pu_low" ) wPU = WeightPUmin[npu];
		  if( !isdata ) sfj *= wPU;

		  // gluon splitting sys
/*		  if( (sys[isys] == "_gsplit_low" || sys[isys] == "_gsplit_up") &&
		      !isdata )
		    {		       
		       bool GSPc = false, GSPb = false;
		       
		       if( flavch == "cjet" )
			 {
			    for( int k=0;k<ntPT->nCFromGSplit;k++ )
			      {
//				 if( ntPT->cQuark_status[k] != 2 ) continue;
				 double dRqj = DeltaR(ntPT->Jet_eta[ij],
						      ntPT->Jet_phi[ij], 
						      ntPT->cQuark_eta[k], 
						      ntPT->cQuark_phi[k]);
				 if( k == ntPT->ncQuarks-1 ) continue;
				 if( dRqj > 0.5 ) continue;
				 for( int l=k+1;l<ntPT->ncQuarks;l++ )
				   {
				      if( ntPT->cQuark_status[l] != 2 ) continue;
				      double dRqj2 = DeltaR(ntPT->Jet_eta[ij],
							    ntPT->Jet_phi[ij], 
							    ntPT->cQuark_eta[l], 
							    ntPT->cQuark_phi[l]);
				      if( ntPT->cQuark_pdgID[k] * ntPT->cQuark_pdgID[l] > 0 ) continue;
				      if( dRqj2 < 0.5 ) GSPc = true;
				   }			    
			      }		       
			 }		  
		       
		       if( flavch == "bjet" )
			 {
			    for( int k=0;k<ntPT->nbQuarks;k++ )
			      {
				 if( ntPT->bQuark_status[k] != 2 ) continue;
				 double dRqj = DeltaR(ntPT->Jet_eta[ij],
						      ntPT->Jet_phi[ij], 
						      ntPT->bQuark_eta[k], 
						      ntPT->bQuark_phi[k]);
				 if( k == ntPT->nbQuarks-1 ) continue;
				 if( dRqj > 0.5 ) continue;
				 for( int l=k+1;l<ntPT->nbQuarks;l++ )
				   {
				      if( ntPT->bQuark_status[l] != 2 ) continue;
				      double dRqj2 = DeltaR(ntPT->Jet_eta[ij], 
							    ntPT->Jet_phi[ij], 
							    ntPT->bQuark_eta[l], 
							    ntPT->bQuark_phi[l]);
				      if( ntPT->bQuark_pdgID[k] * ntPT->bQuark_pdgID[l] > 0 ) continue;
				      if( dRqj2 < 0.5 ) GSPb = true;
				   }			    
			      }		       
			 }		  
		  
		       if( 
			  sys[isys] == "_gsplit_low" && 
			  ((GSPc && flavch == "cjet") || (GSPb && flavch == "bjet"))
			 ) sfj *= 0.5;
		       if( 
			  sys[isys] == "_gsplit_up" &&
			  ((GSPc && flavch == "cjet") || (GSPb && flavch == "bjet"))
			 ) sfj *= 1.5;
		    }
*/		  
		  // b fragmentation sys
		  if( (sys[isys] == "_bfrag_low" || sys[isys] == "_bfrag_up") &&
		      !isdata )
		    {		       
		       float WeightBFrag = 1.;
		       float EnergyFraction = 0.; 
		       int iB = -1, iptBin = 0, efbin = -1;
		       if( flavch == "bjet" && ( sys[isys] == "_bfrag_low" || sys[isys] == "_bfrag_up" ) )
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
			    for( int ib=0;ib<ntPT->nBHadrons;ib++ )
			      {
				 if( DeltaR(ntPT->Jet_eta[ij],
					    ntPT->Jet_phi[ij], 
					    ntPT->BHadron_eta[ib], 
					    ntPT->BHadron_phi[ib]) < 0.5 )
				   {
				      if( ntPT->BHadron_mass[ib] > B_Mass ) 
					{
					   B_Mass = ntPT->BHadron_mass[ib];
					   iB = ib;
					}				 
				   }			    
			      }
			    
			    if( iB >= 0 ) 
			      {
				 EnergyFraction = ntPT->BHadron_pT[iB]/ntPT->Jet_genpt[ij];
				 efbin = int( EnergyFraction / 0.02 );
				 if( efbin >= 0 && efbin < 100 ) 
				   {
				      if( sys[isys] == "_bfrag_low" ) WeightBFrag = BTemplateCorrections[efbin][iptBin][0];
				      if( sys[isys] == "_bfrag_up" ) WeightBFrag = BTemplateCorrections[efbin][iptBin][1];
				   }			    
			      }
			    
			    sfj *= WeightBFrag;
			 }
		    }		  
		  
		  // c->D fragmentation sys
/*		  if( (sys[isys] == "_cdfrag_low" || sys[isys] == "_cdfrag_up") &&
		      !isdata )
		    {		       
		       if( flavch == "cjet" || flavch == "bjet" )
			 {
			    bool isDplusMu = false, isDzeroMu = false, isDsubsMu = false;
			    
			    int ndaughters = 0;
			    for( int k=0;k<ntPT->nDHadrons;k++ )
			      {
				 double dR = DeltaR(ntPT->DHadron_eta[k], 
						    ntPT->DHadron_phi[k], 
						    ntPT->Jet_eta[ij], 
						    ntPT->Jet_phi[ij]);
				 if( dR > 0.4 ) continue;
				 bool isSemiMu = false;
				 int nd = ntPT->DHadron_nDaughters[k];
				 for( int kk=0;kk<nd;kk++ )
				   {
				      if( abs(ntPT->DHadron_DaughtersPdgID[kk+ndaughters]) == 13 ) isSemiMu = true;
				   }
			    
				 ndaughters += nd;
				 
				 if( !isSemiMu ) continue;
				 if( abs(ntPT->DHadron_pdgID[k]) == 411 ) isDplusMu = true;
				 if( abs(ntPT->DHadron_pdgID[k]) == 421 ) isDzeroMu = true;
				 if( abs(ntPT->DHadron_pdgID[k]) == 431 ) isDsubsMu = true;
			      }
			    
			    // weight for D->mu decay: Pythia vs PDG2013
			    if( sys[isys] == "_cdfrag_low" )
			      {			    
				 if( isDplusMu ) sfj *= 0.176 / 0.172;
				 if( isDzeroMu ) sfj *= 0.067 / 0.077;
				 if( isDsubsMu ) sfj *= 0.067 / 0.080;
			      }		       
			 }
		    }*/
		  
		  // c fragmentation sys
/*		  int nChargedGen1_c = -1, nChargedGen2_c = -1;
		  if( !isdata )
		    {
		       if( flavch == "cjet" )
			 {
			    bool hasCquark = 0;
			    for( int c=0;c<ntPT->ncQuarks;c++ )
			      {
				 double dRc = DeltaR(ntPT->cQuark_eta[c], 
						     ntPT->cQuark_phi[c], 
						     ntPT->Jet_eta[ij], 
						     ntPT->Jet_phi[ij]);
				 if( dRc < 0.3 ) hasCquark = 1;
			      }
			    
			    if( hasCquark )
			      {				 
				 bool isDplus = false, isDzero = false, isDsubs = false, isDbary = false;
				 for( int k=0;k<ntPT->nDHadrons;k++ )
				   {
				      double dR = DeltaR(ntPT->DHadron_eta[k], 
							 ntPT->DHadron_phi[k], 
							 ntPT->Jet_eta[ij], 
							 ntPT->Jet_phi[ij]);
				      if( dR > 0.4 ) continue;
				 
				      if( nChargedGen1_c >= 0 && nChargedGen2_c < 0 ) nChargedGen2_c = ntPT->DHadron_nCharged[k];
				      if( nChargedGen1_c < 0 )  nChargedGen1_c = ntPT->DHadron_nCharged[k];
				      
				      if( abs(ntPT->DHadron_pdgID[k]) == 411 ) isDplus = true;
				      if( abs(ntPT->DHadron_pdgID[k]) == 421 ) isDzero = true;
				      if( abs(ntPT->DHadron_pdgID[k]) == 431 ) isDsubs = true;
				      if((abs(ntPT->DHadron_pdgID[k])/1000)%10 == 4 ) isDbary = true;
				   }		       
				 
				 // weight for c->D fragmentation rate: Pythia vs PDG2008
				 if( sys[isys] == "_cfrag_low" )
				   {
				      // DB
				      if( isDplus ) sfj *= 1.37; // PDG2008(0.246+-0.020)
				      if( isDzero ) sfj *= 0.91; // PDG2008(0.565+-0.032)
				      if( isDsubs ) sfj *= 0.67; // PDG2008(0.080+-0.017)
				      // 0.185072, 0.58923, 0.115961
				   }		       
			      }			    
			 }
		    }		  
*/		  
		  // K0s Lambda sys
/*		  if( (sys[isys] == "_ksl_low" || sys[isys] == "_ksl_up") &&
		      !isdata )
		    {		       
		       int nK0s = 0, nLambda = 0;
		       if( flavch == "ljet" )
			 {
			    for( int k=0;k<ntPT->nGenV0;k++ )
			      {
				 double dR = DeltaR(ntPT->GenV0_eta[k], 
						    ntPT->GenV0_phi[k], 
						    ntPT->Jet_eta[ij], 
						    ntPT->Jet_phi[ij]);
				 if( dR > 0.3 ) continue;
				 int pdgid = abs(ntPT->GenV0_pdgID[k]);
				 if( pdgid == 310 )  nK0s++;
				 if( pdgid == 3122 ) nLambda++;
			      }
			    if( sys[isys] == "_ksl_up" )
			      {			    
				 if( nK0s > 0 )    sfj *= 1.3;
				 if( nLambda > 0 ) sfj *= 1.5;
			      }
			 }
		    }		  
*/		  
		  // generated ntrk in b- and c- hadron decays sys
/*		  if( (sys[isys] == "_ntrkgen_low" || sys[isys] == "_ntrkgen_up") &&
		      !isdata )
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
		       
		       if( flavch == "bjet" )
			 {
			    for( int k=0;k<ntPT->nBHadrons;k++ )
			      {
				 if( ntPT->BHadron_hasBdaughter[k] == 1 ) continue;
				 double dR = DeltaR(ntPT->BHadron_eta[k], 
						    ntPT->BHadron_phi[k], 
						    ntPT->Jet_eta[ij], 
						    ntPT->Jet_phi[ij]);
				 if( dR > 0.4 ) continue;
				 int k1 = ntPT->BHadron_DHadron1[k];
				 int k2 = ntPT->BHadron_DHadron2[k];
				 if( nChargedGen1_b >= 0 && nChargedGen2_b < 0 ) 
				   {
				      nChargedGen2_b  = ntPT->BHadron_nCharged[k];
				      if( k1 >= 0 ) nChargedGen2_b += ntPT->DHadron_nCharged[k1];
				      if( k2 >= 0 ) nChargedGen2_b += ntPT->DHadron_nCharged[k2];
				   }
				 if( nChargedGen1_b < 0 ) 
				   {
				      nChargedGen1_b  = ntPT->BHadron_nCharged[k];
				      if( k1 >= 0 ) nChargedGen1_b += ntPT->DHadron_nCharged[k1];
				      if( k2 >= 0 ) nChargedGen1_b += ntPT->DHadron_nCharged[k2];
				   }
			      }
			 }
		       
		       // Weight in track multiplicity from c-hadron and b-hadron decays
		       int nchgen1_b = nChargedGen1_b, nchgen2_b = nChargedGen2_b;
		       if( nchgen1_b > 19 ) nchgen1_b = 19;
		       if( nchgen2_b > 19 ) nchgen2_b = 19;

		       int nchgen1_c = nChargedGen1_c, nchgen2_c = nChargedGen2_c;
		       if( nchgen1_c > 19 ) nchgen1_c = 19;
		       if( nchgen2_c > 19 ) nchgen2_c = 19;
		       
		       if( sys[isys] == "_ntrkgen_low" )
			 {
			    if( flavch == "cjet" )
			      {
				 if( nchgen1_c >= 0 ) sfj *= WeightCtrkMin[nchgen1_c];
				 if( nchgen2_c >= 0 ) sfj *= WeightCtrkMin[nchgen2_c];
			      }
			    if( flavch == "bjet" )
			      {
				 if( nchgen1_b >= 0 ) sfj *= WeightBtrkMin[nchgen1_b];
				 if( nchgen2_b >= 0 ) sfj *= WeightBtrkMin[nchgen2_b];
			      }
			 }
		       if( sys[isys] == "_ntrkgen_up" )
			 {
			    if( flavch == "cjet" )
			      {			    
				 if( nchgen1_c >= 0 ) sfj *= WeightCtrkMax[nchgen1_c];
				 if( nchgen2_c >= 0 ) sfj *= WeightCtrkMax[nchgen2_c];
			      }		       
			    if( flavch == "bjet" )
			      {			    
				 if( nchgen1_b >= 0 ) sfj *= WeightBtrkMax[nchgen1_b];
				 if( nchgen2_b >= 0 ) sfj *= WeightBtrkMax[nchgen2_b];
			      }
			 }
		    }*/
		  // end sys
		  
		  int jPtBin = 0;   
		  if( jPT >= jPtMin[0] && jPT <= jPtMax[0] )   {selch = "pt30t50"; jPtBin = 1;}
		  if( jPT > jPtMin[1] && jPT <= jPtMax[1] )   {selch = "pt50t80"; jPtBin = 2;}
		  if( jPT > jPtMin[2] && jPT <= jPtMax[2] )   {selch = "pt80t120"; jPtBin = 3;}
		  if( jPT > jPtMin[3] && jPT <= jPtMax[3] )   {selch = "pt120t210"; jPtBin = 4;}
		  if( jPT > jPtMin[4] && jPT <= jPtMax[4] )   {selch = "pt210t320"; jPtBin = 5;}
//		  if( jPT > jPtMin[5] && jPT <= jPtMax[5] )   {selch = "pt320t500"; jPtBin = 6;}
//		  if( jPT > jPtMin[6] && jPT <= jPtMax[6] )   {selch = "pt500t800"; jPtBin = 7;}

		  double jPtMinCur = jPtMin[jPtBin-1];
		  double jPtMaxCur = jPtMax[jPtBin-1];

		  double mupt = -1.;
		  if( muidx.size() > 0 )
		    mupt = ntPT->Muon_pt[muidx[0]];
		  
		  bool jeta_res[eta_n];
		  for( int ibt=0;ibt<eta_n;ibt++ ) jeta_res[ibt] = false;
		  		  
		  jeta_res[0] = true;
//		  if( fabs(jeta) >= 0.0 && fabs(jeta) <= 0.6 )  jetaI = 1;
//		  if( fabs(jeta) > 0.6 && fabs(jeta) <= 1.2 )   jetaI = 2;
//		  if( fabs(jeta) > 1.2 && fabs(jeta) <= 1.8 )   jetaI = 3;
//		  if( fabs(jeta) > 1.8 && fabs(jeta) <= 2.5 )   jetaI = 4;

		  // apply RW
		  double rwSF = 1.;
		  double rwSF_btag = rwSF;
		  double sfj_btag = sfj;
		  if( doRW == 1 && !isdata )
		    {
		       for(int iv=0;iv<rw_n;iv++)
			 {			    
			    std::vector<std::pair<double,double> > rwBinFound =
			      rwBin[iv][jPtBin];
			    std::vector<std::pair<double,double> > rwSfFound =
			      rwSf[iv][jPtBin];

			    std::vector<std::pair<double,double> > rwBinFound_btag =
			      rwBin_btag[iv][jPtBin];
			    std::vector<std::pair<double,double> > rwSfFound_btag =
			      rwSf_btag[iv][jPtBin];
			    
			    if( strcmp(name_rw[iv].c_str(),"1d_ntrk") == 0 )
			      {		
				 rwSF *= getSF(rwBinFound,rwSfFound,ntrk);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,ntrk);
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_njet") == 0 )
			      {		
				 rwSF *= getSF(rwBinFound,rwSfFound,njet);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,njet);
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_mupt") == 0 )
			      {
				 if( muidx.size() > 0 )
				   {				      
				      rwSF *= getSF(rwBinFound,rwSfFound,mupt);
				      rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,mupt);
				   }				 
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_eta") == 0 )
			      {		
				 double jeta = ntPT->Jet_eta[ij];
				 rwSF *= getSF(rwBinFound,rwSfFound,jeta);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,jeta);
			      }
			    if( strcmp(name_rw[iv].c_str(),"1d_pt") == 0 )
			      {		
				 double jptmax = jPtMax[jPtBin-1];
				 double jptmin = jPtMin[jPtBin-1];
				 if( jPtBin-1 < 0 ) {
				    jptmax = 1000.;
				    jptmin = 0.;
				 }	     
				 double vPT = (jPT-jptmin)/(jptmax-jptmin);
				 
				 rwSF *= getSF(rwBinFound,rwSfFound,vPT);
				 rwSF_btag *= getSF(rwBinFound_btag,rwSfFound_btag,vPT);
			      }
			 }		       
		    }
/*		  if( doRW == 2 && !isdata )
		    {
		       std::vector<std::pair<double,double> > rw2DBinXFound =
			 rw2DBinX[0][jPtBin];
		       std::vector<std::pair<double,double> > rw2DBinYFound =
			 rw2DBinY[0][jPtBin];
		       std::vector<std::pair<double,double> > rw2DSfFound =
			 rw2DSf[0][jPtBin];

		       if( 
			  strcmp(name_rw_2d.c_str(),"2d_ntrk_vs_mupt") == 0
			 )
			 {
			    rwSF *= get2DSF(rw2DBinXFound,rw2DBinYFound,
					    rw2DSfFound,
					    mupt,
					    ntrk);
			 }
		    }
		  if( doRW == 3 && !isdata )
		    {
		       std::vector<std::pair<double,double> > rw3DBinXFound =
			 rw3DBinX[0][jPtBin];
		       std::vector<std::pair<double,double> > rw3DBinYFound =
			 rw3DBinY[0][jPtBin];
		       std::vector<std::pair<double,double> > rw3DBinZFound =
			 rw3DBinZ[0][jPtBin];
		       std::vector<std::pair<double,double> > rw3DSfFound =
			 rw3DSf[0][jPtBin];

		       if( 
			  strcmp(name_rw_3d.c_str(),"3d_ntrk_pt_mupt") == 0
			 )
			 {
			    rwSF *= get3DSF(rw3DBinXFound,rw3DBinYFound,rw3DBinZFound,
					    rw3DSfFound,
					    mupt,
					    (jPT-jPtMinCur)/(jPtMaxCur-jPtMinCur),
					    ntrk);
			 }
		    }*/
		  sfj *= rwSF;
		  sfj_btag *= rwSF_btag;
		  
		  // 1d
		  std::vector<std::string> histNAMESSEL;
		  std::vector<int> histSYS;
		  std::vector<int> histVAR;
		  std::vector<double> sfarr;
		  sfarr.clear();
		  for(int ih=0;ih<histname_jet_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;

			    for(int iha=0;iha<seladd_n;iha++)
			      {
				 if( !selach_res[iha] ) continue;
			    
				 for(int ihe=0;ihe<eta_n;ihe++)
				   {
				      if( !jeta_res[ihe] ) continue;
				      
				      histNAMESSEL.push_back(histNAMES[flavchI][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL.push_back(histNAMES[0][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL.push_back(histNAMES[flavchI][0][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL.push_back(histNAMES[0][0][ihe][ihb][iha][ih][isys]);
				      histSYS.push_back(isys);
				      histVAR.push_back(ih);
/*				      if( ihb != 1 )
					{					   
					   sfarr.push_back(sfj);
					   sfarr.push_back(sfj);
					   sfarr.push_back(sfj);
					   sfarr.push_back(sfj);
					}				      
				      else
					{					   
					   sfarr.push_back(sfj_btag);
					   sfarr.push_back(sfj_btag);
					   sfarr.push_back(sfj_btag);
					   sfarr.push_back(sfj_btag);
					}*/
				   }
			      }
			 }		       
		    }
		  
		  int nHISTSEL = histNAMESSEL.size();
		  for(int ih=0;ih<nHISTSEL;ih++)
		    {		       
		       TH1D *h = _m1d_Jet->find(histNAMESSEL.at(ih))->second;

		       int hidx = int(ih/4);
		       fillThis = true;
		       float var = getVar(sys[histSYS[hidx]],ij,histname_jet[histVAR[hidx]],jPtBin);
		       
		       if( fillThis )
//			 h->Fill(var,sfarr[ih]);
			 h->Fill(var,sfj);
		    }
		  histNAMESSEL.clear();

		  // 2d
		  std::vector<std::string> histNAMESSEL_2d;
		  std::vector<int> histSYS_2d;
		  std::vector<int> histVAR_2d;
		  for(int ih=0;ih<histname_jet_2d_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;

			    for(int iha=0;iha<seladd_n;iha++)
			      {
				 if( !selach_res[iha] ) continue;
			    
				 for(int ihe=0;ihe<eta_n;ihe++)
				   {
				      if( !jeta_res[ihe] ) continue;
				      
				      histNAMESSEL_2d.push_back(histNAMES_2d[flavchI][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_2d.push_back(histNAMES_2d[0][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_2d.push_back(histNAMES_2d[flavchI][0][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_2d.push_back(histNAMES_2d[0][0][ihe][ihb][iha][ih][isys]);
				      histSYS_2d.push_back(isys);
				      histVAR_2d.push_back(ih);
				   }				 
			      }
			 }		       
		    }

		  int nHISTSEL_2d = histNAMESSEL_2d.size();
		  for(int ih=0;ih<nHISTSEL_2d;ih++)
		    {		       
		       TH2D *h_2d = _m2d_Jet->find(histNAMESSEL_2d.at(ih))->second;
		       
		       int hidx = int(ih/4);
		       fillThis = true;
		       std::pair<float,float> var = getVar2d(sys[histSYS_2d[hidx]],ij,histname_jet_2d[histVAR_2d[hidx]],jPtBin);
		       float varX = var.first;
		       float varY = var.second;
		       
		       if( fillThis )
			 h_2d->Fill(varX,varY,sfj);
		    }		  
		  histNAMESSEL_2d.clear();
		  
		  // 3d
		  std::vector<std::string> histNAMESSEL_3d;
		  std::vector<int> histSYS_3d;
		  std::vector<int> histVAR_3d;
		  for(int ih=0;ih<histname_jet_3d_n;ih++)
		    {
		       for(int ihb=0;ihb<selb_n;ihb++)
			 {
			    if( !selbch_res[ihb] ) continue;

			    for(int iha=0;iha<seladd_n;iha++)
			      {
				 if( !selach_res[iha] ) continue;
			    
				 for(int ihe=0;ihe<eta_n;ihe++)
				   {
				      if( !jeta_res[ihe] ) continue;
				      
				      histNAMESSEL_3d.push_back(histNAMES_3d[flavchI][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_3d.push_back(histNAMES_3d[0][jPtBin][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_3d.push_back(histNAMES_3d[flavchI][0][ihe][ihb][iha][ih][isys]);
				      histNAMESSEL_3d.push_back(histNAMES_3d[0][0][ihe][ihb][iha][ih][isys]);
				      histSYS_3d.push_back(isys);
				      histVAR_3d.push_back(ih);
				   }				 
			      }
			 }		       
		    }

		  int nHISTSEL_3d = histNAMESSEL_3d.size();
		  for(int ih=0;ih<nHISTSEL_3d;ih++)
		    {		       
		       TH3D *h_3d = _m3d_Jet->find(histNAMESSEL_3d.at(ih))->second;
		       
		       int hidx = int(ih/4);
		       fillThis = true;
		       std::vector<float> var = getVar3d(sys[histSYS_3d[hidx]],ij,histname_jet_3d[histVAR_3d[hidx]],jPtBin);
		       float varX = var[0];
		       float varY = var[1];
		       float varZ = var[2];
		       
		       if( fillThis )
			 h_3d->Fill(varX,varY,varZ,sfj);
		    }		  
		  histNAMESSEL_3d.clear();		  
	       }
	  }
	
	delete v_mu;
	delete v_jet;
	delete v_jet_sys_jesTotalUp;
	delete v_jet_sys_jesTotalLow;	
	delete v_jet_sys_jerTotalUp;
	delete v_jet_sys_jerTotalLow;	
     }   
}

void LTANA::HistTTbar::close()
{
   _fout->Write();
   _fout->Close();
//   _fevc.close();
   
//   delete rnd;
}

void LTANA::HistTTbar::printout()
{
}

float LTANA::HistTTbar::getVar(std::string sys,int ijet,std::string varName,int ibin)
{
   float var = -666;

   if( ibin-1 < 0 ) return var;
   
   if( ijet <= ntPT->nJet )
     {	   
	if( strcmp(varName.c_str(),"h_j1_JP_") == 0 )
	  {		  
//	     var = ntP->Jet_Proba[ijet]*10.;
	     var = Jet_Proba_New;
	     if( var == 0. ) var = -666.;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_pthat_") == 0 )
	  {		  
	     var = ntPT->pthat/1000.;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_ntrk_") == 0 )
	  {		  
//	     var = ntPT->Jet_ntracks[ijet];
	     var = nTrk(ijet);
	  }	     
	if( strcmp(varName.c_str(),"h_j1_eta_") == 0 )
	  {		  
	     var = ntPT->Jet_eta[ijet];
	  }	     
	if( strcmp(varName.c_str(),"h_j1_phi_") == 0 )
	  {		  
	     var = ntPT->Jet_phi[ijet];
	  }	     
	if( strcmp(varName.c_str(),"h_j1_mass_") == 0 )
	  {		  
//	     var = ntPT->Jet_mass[ijet];
	     var = -666;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_mupt_") == 0 )
	  {
	     if( muidx.size() > 0 )
	       var = ntPT->Muon_pt[muidx[0]];
	     else fillThis = false;
/////	     std::cout << var << " " << fillThis << std::endl;
//	     for(int im=0;im<muidx.size();im++)
//	       {		  
//		  var = ntP->Muon_pt[muidx[im]];
//	       }	     
	  }	     
	if( strcmp(varName.c_str(),"h_j1_mueta_") == 0 )
	  {
	     if( muidx.size() > 0 )
	       var = ntPT->Muon_eta[muidx[0]];
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_muphi_") == 0 )
	  {
	     if( muidx.size() > 0 )
	       var = ntPT->Muon_phi[muidx[0]];
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_muptrel_") == 0 )
	  {
	     if( muidx.size() > 0 )
	       var = ntPT->Muon_ptrel[muidx[0]];
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_svntrk_") == 0 )
	  {
	     if( ijet == 0 && ntPT->nSV > 0 )
	       var = ntPT->SV_nTrk[0];
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_svmass_") == 0 )
	  {
	     if( ijet == 0 && ntPT->nSV > 0 )
	       var = ntPT->SV_mass[0];
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_npv_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntPT->nPV;
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_npu_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntPT->nPU;
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_njet_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntPT->nJet;
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_nmuon_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntPT->nMuon;
	     else fillThis = false;
	  }	     
	if( strcmp(varName.c_str(),"h_j1_nsv_") == 0 )
	  {
	     if( ijet == 0 )
	       var = ntPT->nSV;
	     else fillThis = false;
	  }	     

	if( (sys == "" ||
	     sys == "_smearDIR_low" ||
	     sys == "_sys_up" || sys == "_sys_low" ||
	     sys == "_pu_up" || sys == "_pu_low" ||
	     sys == "_gsplit_up" || sys == "_gsplit_low" ||
	     sys == "_bfrag_up" || sys == "_bfrag_low" ||
	     sys == "_cdfrag_up" || sys == "_cdfrag_low" ||
	     sys == "_cfrag_up" || sys == "_cfrag_low" ||
	     sys == "_ksl_up" || sys == "_ksl_low" ||
	     sys == "_ntrkgen_up" || sys == "_ntrkgen_low"
	    ) || isdata )
	  {
	     if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	       {		  
		  double jptmax = jPtMax[ibin-1];
		  double jptmin = jPtMin[ibin-1];
		  if( ibin-1 < 0 ) {
		     jptmax = 1000.;
		     jptmin = 0.;
		  }	     
		  
		  var = (getPt(sys)-jptmin)/(jptmax-jptmin);
	       }	     
	  }
	else if( sys == "_jes_up" )
	  {
	     if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	       {		  
		  var = v_jet_sys_jesTotalUp->Pt()/1000.;
	       }	     
	  }	
	else if( sys == "_jes_low" )
	  {
	     if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	       {		  
		  var = v_jet_sys_jesTotalLow->Pt()/1000.;
	       }	     
	  }	
	else if( sys == "_jer_up" )
	  {
	     if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	       {		  
		  var = v_jet_sys_jerTotalUp->Pt()/1000.;
	       }	     
	  }	
	else if( sys == "_jer_low" )
	  {
	     if( strcmp(varName.c_str(),"h_j1_pt_") == 0 )
	       {		  
		  var = v_jet_sys_jerTotalLow->Pt()/1000.;
	       }	     
	  }	
	else
	  {
	     std::cout << "No such systematic found: " << sys << std::endl;
	     exit(1);
	  }	
     }   

   return var;
}

std::pair<float,float> LTANA::HistTTbar::getVar2d(std::string sys,int ijet,std::string varName,int ibin)
{
   float varX = -666;
   float varY = -666;
   
   if( ijet <= ntPT->nJet )
     {	   
	if( strcmp(varName.c_str(),"h_j1_JP_vs_ntrk_") == 0 )
	  {		  
//	     varX = ntPT->Jet_ntracks[ijet];
	     varX = nTrk(ijet);
//	     varY = ntPT->Jet_Proba[ijet]*10.;
	     varY = ntPT->Jet_ProbaP[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_JP_vs_pt_") == 0 )
	  {	     	     
	     double jptmax = jPtMax[ibin-1];
	     double jptmin = jPtMin[ibin-1];
	     if( ibin-1 < 0 ) {
		jptmax = 1000.;
		jptmin = 0.;
	     }	     

	     varX = (getPt(sys)-jptmin)/(jptmax-jptmin);
//	     varY = ntPT->Jet_Proba[ijet]*10.;
	     varY = ntPT->Jet_ProbaP[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_ntrk_vs_pt_") == 0 )
	  {	     	     
	     double jptmax = jPtMax[ibin-1];
	     double jptmin = jPtMin[ibin-1];
	     if( ibin-1 < 0 ) {
		jptmax = 1000.;
		jptmin = 0.;
	     }	     

	     varX = (getPt(sys)-jptmin)/(jptmax-jptmin);
//	     varY = ntPT->Jet_ntracks[ijet];
	     varY = nTrk(ijet);
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_JP_vs_mupt_") == 0 )
	  {		  
	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varX = ntPT->Muon_pt[muidx[0]];
	     else fillThis = false;
//	     varY = ntPT->Jet_Proba[ijet]*10.;
	     varY = ntPT->Jet_ProbaP[ijet];
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_ntrk_vs_mupt_") == 0 )
	  {		  
	     if( muidx.size() > 0 )
	       varX = ntPT->Muon_pt[muidx[0]];
	     else fillThis = false;
//	     varY = ntPT->Jet_ntracks[ijet];
	     varY = nTrk(ijet);
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_pt_vs_ntrk_") == 0 )
	  {	     	     
	     double jptmax = jPtMax[ibin-1];
	     double jptmin = jPtMin[ibin-1];
	     if( ibin-1 < 0 ) {
		jptmax = 1000.;
		jptmin = 0.;
	     }	     

//	     varX = ntPT->Jet_ntracks[ijet];
	     varX = nTrk(ijet);
	     varY = (getPt(sys)-jptmin)/(jptmax-jptmin);
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_mupt_vs_ntrk_") == 0 )
	  {	     	     
	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varY = ntPT->Muon_pt[muidx[0]];
	     else fillThis = false;

//	     varX = ntPT->Jet_ntracks[ijet];
	     varX = nTrk(ijet);
	  }	     
	else if( strcmp(varName.c_str(),"h_j1_mupt_vs_pt_") == 0 )
	  {	     	     
	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varY = ntPT->Muon_pt[muidx[0]];
	     else fillThis = false;

	     double jptmax = jPtMax[ibin-1];
	     double jptmin = jPtMin[ibin-1];
	     if( ibin-1 < 0 ) {
		jptmax = 1000.;
		jptmin = 0.;
	     }	     
	     
	     varX = (getPt(sys)-jptmin)/(jptmax-jptmin);
	  }	     
     }   
   
   return std::make_pair(varX,varY);
}

std::vector<float> LTANA::HistTTbar::getVar3d(std::string sys,int ijet,std::string varName,int ibin)
{
   float varX = -666;
   float varY = -666;
   float varZ = -666;
   
   if( ijet <= ntPT->nJet )
     {	   
	if( strcmp(varName.c_str(),"h_j1_ntrk_vs_pt_vs_mupt_") == 0 )
	  {		  
//	     varZ = ntPT->Jet_ntracks[ijet];
	     varZ = nTrk(ijet);
	     
	     double jptmax = jPtMax[ibin-1];
	     double jptmin = jPtMin[ibin-1];
	     if( ibin-1 < 0 ) {
		jptmax = 1000.;
		jptmin = 0.;
	     }	     
	     varY = (getPt(sys)-jptmin)/(jptmax-jptmin);

	     // highest-Pt muon in a jet
	     if( muidx.size() > 0 )
	       varX = ntPT->Muon_pt[muidx[0]];
	  }	     
     }   

   std::vector<float> res;
   res.push_back(varX);
   res.push_back(varY);
   res.push_back(varZ);
   return res;
}

float LTANA::HistTTbar::getPt(std::string sys)
{
   float var = -666;
   
   if( (sys == "" ||
	sys == "_sys_up" || sys == "_sys_low" ||
	sys == "_pu_up" || sys == "_pu_low" ||
	sys == "_gsplit_up" || sys == "_gsplit_low" ||
	sys == "_bfrag_up" || sys == "_bfrag_low" ||
	sys == "_cdfrag_up" || sys == "_cdfrag_low" ||
	sys == "_cfrag_up" || sys == "_cfrag_low" ||
	sys == "_ksl_up" || sys == "_ksl_low" ||
	sys == "_ntrkgen_up" || sys == "_ntrkgen_low"
       )
       ||
       isdata )
     {
	var = v_jet->Pt();
     }
   else if( sys == "_jes_up" )
     {
	var = v_jet_sys_jesTotalUp->Pt();
     }	
   else if( sys == "_jes_low" )
     {
	var = v_jet_sys_jesTotalLow->Pt();
     }
   else if( sys == "_jer_up" )
     {
	var = v_jet_sys_jerTotalUp->Pt();
     }	
   else if( sys == "_jer_low" )
     {
	var = v_jet_sys_jerTotalLow->Pt();
     }	
   else
     {
	std::cout << "No jet Pt for: " << sys << std::endl;
	exit(1);
     }	

   return var;
}

void LTANA::HistTTbar::initRePU()
{   
   WeightPU[0] = 0.243019;
   WeightPU[1] = 0.315341;
   WeightPU[2] = 0.325947;
   WeightPU[3] = 0.211569;
   WeightPU[4] = 0.18514;
   WeightPU[5] = 0.5576;
   WeightPU[6] = 0.443999;
   WeightPU[7] = 0.445924;
   WeightPU[8] = 0.62719;
   WeightPU[9] = 0.942706;
   WeightPU[10] = 1.33418;
   WeightPU[11] = 1.68355;
   WeightPU[12] = 1.73385;
   WeightPU[13] = 1.55081;
   WeightPU[14] = 1.32517;
   WeightPU[15] = 1.15726;
   WeightPU[16] = 1.07075;
   WeightPU[17] = 1.04477;
   WeightPU[18] = 1.06226;
   WeightPU[19] = 1.10593;
   WeightPU[20] = 1.14746;
   WeightPU[21] = 1.17303;
   WeightPU[22] = 1.18548;
   WeightPU[23] = 1.18546;
   WeightPU[24] = 1.16609;
   WeightPU[25] = 1.12119;
   WeightPU[26] = 1.05037;
   WeightPU[27] = 0.957803;
   WeightPU[28] = 0.848249;
   WeightPU[29] = 0.727987;
   WeightPU[30] = 0.604889;
   WeightPU[31] = 0.486587;
   WeightPU[32] = 0.378377;
   WeightPU[33] = 0.283843;
   WeightPU[34] = 0.204733;
   WeightPU[35] = 0.14144;
   WeightPU[36] = 0.0936249;
   WeightPU[37] = 0.0595571;
   WeightPU[38] = 0.0365776;
   WeightPU[39] = 0.0218727;
   WeightPU[40] = 0.0128692;
   WeightPU[41] = 0.00754778;
   WeightPU[42] = 0.00448146;
   WeightPU[43] = 0.00273972;
   WeightPU[44] = 0.00175546;
   WeightPU[45] = 0.00119153;
   WeightPU[46] = 0.000859364;
   WeightPU[47] = 0.000655574;
   WeightPU[48] = 0.000523753;
   WeightPU[49] = 0.000433495;
   WeightPU[50] = 0.000368473;
   WeightPU[51] = 0.000319238;
   WeightPU[52] = 0.000280556;
   WeightPU[53] = 0.000249037;
   WeightPU[54] = 0.000222259;
   WeightPU[55] = 0.000198889;
   WeightPU[56] = 0.000177947;
   WeightPU[57] = 0.000158848;
   WeightPU[58] = 0.000141149;
   WeightPU[59] = 0.00026219;
   WeightPUmin[0] = 0.259393;
   WeightPUmin[1] = 0.434519;
   WeightPUmin[2] = 0.37735;
   WeightPUmin[3] = 0.225517;
   WeightPUmin[4] = 0.302279;
   WeightPUmin[5] = 1.08521;
   WeightPUmin[6] = 0.721086;
   WeightPUmin[7] = 0.680151;
   WeightPUmin[8] = 0.921338;
   WeightPUmin[9] = 1.31871;
   WeightPUmin[10] = 1.81825;
   WeightPUmin[11] = 2.10762;
   WeightPUmin[12] = 1.99973;
   WeightPUmin[13] = 1.72798;
   WeightPUmin[14] = 1.45569;
   WeightPUmin[15] = 1.24972;
   WeightPUmin[16] = 1.13635;
   WeightPUmin[17] = 1.09583;
   WeightPUmin[18] = 1.10338;
   WeightPUmin[19] = 1.13794;
   WeightPUmin[20] = 1.1715;
   WeightPUmin[21] = 1.18818;
   WeightPUmin[22] = 1.18252;
   WeightPUmin[23] = 1.14739;
   WeightPUmin[24] = 1.07844;
   WeightPUmin[25] = 0.980643;
   WeightPUmin[26] = 0.862823;
   WeightPUmin[27] = 0.733342;
   WeightPUmin[28] = 0.600672;
   WeightPUmin[29] = 0.47406;
   WeightPUmin[30] = 0.360466;
   WeightPUmin[31] = 0.263462;
   WeightPUmin[32] = 0.184235;
   WeightPUmin[33] = 0.12289;
   WeightPUmin[34] = 0.0781201;
   WeightPUmin[35] = 0.0473791;
   WeightPUmin[36] = 0.0275978;
   WeightPUmin[37] = 0.0155869;
   WeightPUmin[38] = 0.00863213;
   WeightPUmin[39] = 0.0047608;
   WeightPUmin[40] = 0.0026632;
   WeightPUmin[41] = 0.00154222;
   WeightPUmin[42] = 0.000941929;
   WeightPUmin[43] = 0.000613648;
   WeightPUmin[44] = 0.000427372;
   WeightPUmin[45] = 0.0003153;
   WeightPUmin[46] = 0.000243402;
   WeightPUmin[47] = 0.000194427;
   WeightPUmin[48] = 0.000159188;
   WeightPUmin[49] = 0.000132601;
   WeightPUmin[50] = 0.000111769;
   WeightPUmin[51] = 9.48293e-05;
   WeightPUmin[52] = 8.0714e-05;
   WeightPUmin[53] = 6.86993e-05;
   WeightPUmin[54] = 5.82656e-05;
   WeightPUmin[55] = 4.9159e-05;
   WeightPUmin[56] = 4.11881e-05;
   WeightPUmin[57] = 3.42326e-05;
   WeightPUmin[58] = 2.81834e-05;
   WeightPUmin[59] = 4.83047e-05;
   WeightPUmax[0] = 0.22856;
   WeightPUmax[1] = 0.219793;
   WeightPUmax[2] = 0.293184;
   WeightPUmax[3] = 0.192268;
   WeightPUmax[4] = 0.129795;
   WeightPUmax[5] = 0.289582;
   WeightPUmax[6] = 0.265823;
   WeightPUmax[7] = 0.295872;
   WeightPUmax[8] = 0.425999;
   WeightPUmax[9] = 0.673774;
   WeightPUmax[10] = 0.977477;
   WeightPUmax[11] = 1.29103;
   WeightPUmax[12] = 1.45043;
   WeightPUmax[13] = 1.37586;
   WeightPUmax[14] = 1.20079;
   WeightPUmax[15] = 1.06208;
   WeightPUmax[16] = 0.998691;
   WeightPUmax[17] = 0.989323;
   WeightPUmax[18] = 1.01604;
   WeightPUmax[19] = 1.06718;
   WeightPUmax[20] = 1.11675;
   WeightPUmax[21] = 1.14975;
   WeightPUmax[22] = 1.16997;
   WeightPUmax[23] = 1.18467;
   WeightPUmax[24] = 1.19447;
   WeightPUmax[25] = 1.19354;
   WeightPUmax[26] = 1.17375;
   WeightPUmax[27] = 1.13066;
   WeightPUmax[28] = 1.06431;
   WeightPUmax[29] = 0.97763;
   WeightPUmax[30] = 0.874494;
   WeightPUmax[31] = 0.760469;
   WeightPUmax[32] = 0.642338;
   WeightPUmax[33] = 0.52728;
   WeightPUmax[34] = 0.420179;
   WeightPUmax[35] = 0.32374;
   WeightPUmax[36] = 0.240607;
   WeightPUmax[37] = 0.172234;
   WeightPUmax[38] = 0.118674;
   WeightPUmax[39] = 0.0789503;
   WeightPUmax[40] = 0.0509717;
   WeightPUmax[41] = 0.0321675;
   WeightPUmax[42] = 0.0200234;
   WeightPUmax[43] = 0.0124268;
   WeightPUmax[44] = 0.00780142;
   WeightPUmax[45] = 0.00502405;
   WeightPUmax[46] = 0.00336762;
   WeightPUmax[47] = 0.00237717;
   WeightPUmax[48] = 0.00177511;
   WeightPUmax[49] = 0.00139811;
   WeightPUmax[50] = 0.00115293;
   WeightPUmax[51] = 0.000985738;
   WeightPUmax[52] = 0.000867016;
   WeightPUmax[53] = 0.000779338;
   WeightPUmax[54] = 0.000711555;
   WeightPUmax[55] = 0.000657417;
   WeightPUmax[56] = 0.000612393;
   WeightPUmax[57] = 0.000573434;
   WeightPUmax[58] = 0.000538038;
   WeightPUmax[59] = 0.00106137;
}

double LTANA::HistTTbar::getSF(std::vector<std::pair<double,double> > vBin,
			       std::vector<std::pair<double,double> > vSf,
			       double var)
{
   double sf = 1.;
   
   for( int ib=0;ib<vBin.size();ib++ )
     {
	double blow = vBin.at(ib).first;
	double bup = vBin.at(ib).second;
	
	if( var >= blow && var < bup )
	  {
	     sf = vSf.at(ib).first;
	     break;
	  }	
     }   
   
   return sf;
}

/*double LTANA::Hist::get2DSF(std::vector<std::pair<double,double> > vBinX,
			     std::vector<std::pair<double,double> > vBinY,
 std::vector<std::pair<double,double> > vSf,
			     double varX,
			     double varY)
{
   double sf = 1.;

   int idx = -1;
   int idy = -1;

   int nbx = vBinX.size();
   int nby = vBinY.size();
   
   for( int ib=0;ib<vBinX.size();ib++ )
     {
	double blow = vBinX.at(ib).first;
	double bup = vBinX.at(ib).second;
	
	if( varX >= blow && varX < bup )
	  {
	     idx = ib;
	     break;
	  }	
     }   

   for( int ib=0;ib<vBinY.size();ib++ )
     {
	double blow = vBinY.at(ib).first;
	double bup = vBinY.at(ib).second;
	
	if( varY >= blow && varY < bup )
	  {
	     idy = ib;
	     break;
	  }	
     }   
   
   int id2D = idx*nby+idy;

   if( idx >= 0 && idy >= 0 )
     sf = vSf.at(id2D).first;
   
   return sf;
}

double LTANA::Hist::get3DSF(std::vector<std::pair<double,double> > vBinX,
			     std::vector<std::pair<double,double> > vBinY,
			     std::vector<std::pair<double,double> > vBinZ,
			     std::vector<std::pair<double,double> > vSf,
			     double varX,
			     double varY,
			     double varZ)
{
   double sf = 1.;

   int idx = -1;
   int idy = -1;
   int idz = -1;

   int nbx = vBinX.size();
   int nby = vBinY.size();
   int nbz = vBinZ.size();
   
   for( int ib=0;ib<vBinX.size();ib++ )
     {
	double blow = vBinX.at(ib).first;
	double bup = vBinX.at(ib).second;
	
	if( varX >= blow && varX < bup )
	  {
	     idx = ib;
	     break;
	  }	
     }   

   for( int ib=0;ib<vBinY.size();ib++ )
     {
	double blow = vBinY.at(ib).first;
	double bup = vBinY.at(ib).second;
	
	if( varY >= blow && varY < bup )
	  {
	     idy = ib;
	     break;
	  }	
     }   

   for( int ib=0;ib<vBinZ.size();ib++ )
     {
	double blow = vBinZ.at(ib).first;
	double bup = vBinZ.at(ib).second;
	
	if( varZ >= blow && varZ < bup )
	  {
	     idz = ib;
	     break;
	  }	
     }   
   
   int id3D = idx*nby*nbz+idy*nbz+idz;

   if( idx >= 0 && idy >= 0 && idz >= 0 )
     sf = vSf.at(id3D).first;
   
//   std::cout << idx+1 << " " << idy+1 << " " << idz+1 << " " << sf << std::endl;
   
   return sf;
}*/

double LTANA::HistTTbar::DeltaR(double eta1, double phi1, double eta2, double phi2) 
{
   double DeltaPhi = TMath::Abs(phi2 - phi1);
   if (DeltaPhi > 3.141593 ) DeltaPhi -= 2.*3.141593;
   return TMath::Sqrt( (eta2-eta1)*(eta2-eta1) + DeltaPhi*DeltaPhi );
}

int LTANA::HistTTbar::nTrk(int ji)
{
   int ntracksel=0;

   for(int itrk=ntPT->Jet_nFirstTrack[ji];itrk<ntPT->Jet_nLastTrack[ji];itrk++)
     {
	bool passNhit = false;
	bool passPix = false;
	bool passIPz =false;
	bool passPt = false;
	bool passnormchi2 = false;
	bool passtrkdist = false;
	bool passtrklen = false;
	bool passTrackIP2D = false;
	
	if( ntPT->Track_nHitAll[itrk] >= 8 )       passNhit = true;
	if( ntPT->Track_nHitPixel[itrk] >= 2 )     passPix = true;
	if( fabs(ntPT->Track_dz[itrk]) < 17 )      passIPz = true;
	if( ntPT->Track_pt[itrk] > 1 )             passPt = true;
	if( ntPT->Track_chi2[itrk] < 5 )           passnormchi2 = true;
	if( fabs(ntPT->Track_dist[itrk]) < 0.07 )  passtrkdist = true;
	if( ntPT->Track_length[itrk] < 5 )         passtrklen = true;
	if( fabs(ntPT->Track_IP2D[itrk]) < 0.2 )   passTrackIP2D = true;
	
	 if( passNhit && passPix && passIPz && passPt && passnormchi2 && passtrkdist && passtrklen && passTrackIP2D )
	  {
	     ntracksel++;
	  }	
     }
   
   return ntracksel;
}
