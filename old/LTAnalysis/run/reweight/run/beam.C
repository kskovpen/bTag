TFile *fbatch_DATA[100];

std::string tool = "plot_PROC20130628_BEAM";
std::string fpath = "/gcf/atlas/data/JTNtuple_hist/run_"+tool+"/";

void beam()
{   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1F.h>");
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");

   TChain ch_data("treeBEAM");
   TChain ch_mc("treeBEAM");
   
   for(int i=0;i<v_data.size();i++)
     {
	std::string fnameDATA = fpath+v_data.at(i);
	ch_data.Add(fnameDATA.c_str());
     }

   for(int i=0;i<v_mc_filt.size();i++)
     {
	std::string fnameMC = fpath+v_mc_filt.at(i);
	ch_mc.Add(fnameMC.c_str());
     }
   
   float sd0t1, sd0t2, cosphi, jPt;
   
   ch_data.SetBranchAddress("sd0t1",&sd0t1);
   ch_data.SetBranchAddress("sd0t2",&sd0t2);
   ch_data.SetBranchAddress("cosphi",&cosphi);
   ch_data.SetBranchAddress("jPt",&jPt);

   ch_mc.SetBranchAddress("sd0t1",&sd0t1);
   ch_mc.SetBranchAddress("sd0t2",&sd0t2);
   ch_mc.SetBranchAddress("cosphi",&cosphi);
   ch_mc.SetBranchAddress("jPt",&jPt);
   
   TCanvas *c1 = new TCanvas();
   
   std::vector<float> v_sd0t1_data;
   std::vector<float> v_sd0t2_data;
   std::vector<float> v_cosphi_data;
   std::vector<float> v_jPt_data;
   
   const int nent_data = ch_data.GetEntries();
   for(int i=0;i<nent_data;i++)
     {
	ch_data.GetEntry(i);

	if( sd0t1 == -666. || sd0t2 == -666. || cosphi == -666. || jPt == -666. )
	  continue;
	
	v_sd0t1_data.push_back(sd0t1);
	v_sd0t2_data.push_back(sd0t2);
	v_cosphi_data.push_back(cos(cosphi));
	v_jPt_data.push_back(jPt);
     }   

   std::vector<float> v_sd0t1_mc;
   std::vector<float> v_sd0t2_mc;
   std::vector<float> v_cosphi_mc;
   std::vector<float> v_jPt_mc;
   
   const int nent_mc = ch_mc.GetEntries();
   for(int i=0;i<nent_mc;i++)
     {
	ch_mc.GetEntry(i);

	if( sd0t1 == -666. || sd0t2 == -666. || cosphi == -666. || jPt == -666. )
	  continue;
	
	v_sd0t1_mc.push_back(sd0t1);
	v_sd0t2_mc.push_back(sd0t2);
	v_cosphi_mc.push_back(cos(cosphi));
	v_jPt_mc.push_back(jPt);
     }   
   
   std::cout << "Data read" << std::endl;
   
   std::vector<double> cosphiDef;
   cosphiDef.push_back(-1.0);
   cosphiDef.push_back(-0.8);
   cosphiDef.push_back(-0.6);
   cosphiDef.push_back(-0.4);
   cosphiDef.push_back(-0.2);
   cosphiDef.push_back(0.);
   cosphiDef.push_back(0.2);
   cosphiDef.push_back(0.4);
   cosphiDef.push_back(0.6);
   cosphiDef.push_back(0.8);
   cosphiDef.push_back(1.0);
   const int ncosphiDef = cosphiDef.size();

   double avT1T2_data[ncosphiDef+1];
   double avT1_data[ncosphiDef+1];
   double avT2_data[ncosphiDef+1];
   double avT1T2ERR_data[ncosphiDef+1];
   double avT1ERR_data[ncosphiDef+1];
   double avT2ERR_data[ncosphiDef+1];
   double nevents_data[ncosphiDef+1];

   double avT1T2_mc[ncosphiDef+1];
   double avT1_mc[ncosphiDef+1];
   double avT2_mc[ncosphiDef+1];
   double avT1T2ERR_mc[ncosphiDef+1];
   double avT1ERR_mc[ncosphiDef+1];
   double avT2ERR_mc[ncosphiDef+1];
   double nevents_mc[ncosphiDef+1];
   
   double xbins[ncosphiDef];
   
   for(int i=0;i<ncosphiDef+1;i++)
     {
	avT1T2_data[i] = 0.;
	avT1_data[i] = 0.;
	avT2_data[i] = 0.;	
	avT1T2ERR_data[i] = 0.;
	avT1ERR_data[i] = 0.;
	avT2ERR_data[i] = 0.;	
	nevents_data[i] = 0.;

	avT1T2_mc[i] = 0.;
	avT1_mc[i] = 0.;
	avT2_mc[i] = 0.;	
	avT1T2ERR_mc[i] = 0.;
	avT1ERR_mc[i] = 0.;
	avT2ERR_mc[i] = 0.;	
	nevents_mc[i] = 0.;
     }
   
   for(int i=0;i<ncosphiDef;i++)
     {
	xbins[i] = cosphiDef[i];
     }   

   std::cout << "Start calculations" << std::endl;

   const int nel_data = v_sd0t1_data.size();
   for(int i=0;i<nel_data;i++)
     {
	int ib = 0;
	for(int j=0;j<ncosphiDef;j++)
	  {
	     if( v_cosphi_data[i] >= cosphiDef[j] ) 
	       {
		  ib = j+1;
	       }	     
	  }
	
	avT1_data[ib] += v_sd0t1_data[i];
	avT2_data[ib] += v_sd0t2_data[i];
	avT1T2_data[ib] += v_sd0t1_data[i]*v_sd0t2_data[i];
	nevents_data[ib]++;
     }   

   for(int j=0;j<=ncosphiDef;j++)
     {
	if( nevents_data[j] > 1 )
	  { 
	     avT1_data[j] /= nevents_data[j];
	     avT2_data[j] /= nevents_data[j];
	     avT1T2_data[j] /= nevents_data[j];
	  }
     }
   
   for(int i=0;i<nel_data;i++)
     {
	int ib = 0;
	for(int j=0;j<ncosphiDef;j++)
	  {
	     if( v_cosphi_data[i] >= cosphiDef[j] ) 
	       {
		  ib = j+1;
	       }	     
	  }
	
	avT1ERR_data[ib] += pow(v_sd0t1_data[i]-avT1_data[ib],2);
	avT2ERR_data[ib] += pow(v_sd0t2_data[i]-avT2_data[ib],2);
	avT1T2ERR_data[ib] += pow(v_sd0t1_data[i]*v_sd0t2_data[i]-avT1T2_data[ib],2);
     }   
   
   const int nel_mc = v_sd0t1_mc.size();
   for(int i=0;i<nel_mc;i++)
     {
	int ib = 0;
	for(int j=0;j<ncosphiDef;j++)
	  {
	     if( v_cosphi_mc[i] >= cosphiDef[j] ) 
	       {
		  ib = j+1;
	       }	     
	  }
	
	avT1_mc[ib] += v_sd0t1_mc[i];
	avT2_mc[ib] += v_sd0t2_mc[i];
	avT1T2_mc[ib] += v_sd0t1_mc[i]*v_sd0t2_mc[i];
	nevents_mc[ib]++;
     }   

   for(int j=0;j<=ncosphiDef;j++)
     {
	if( nevents_mc[j] > 1 )
	  { 
	     avT1_mc[j] /= nevents_mc[j];
	     avT2_mc[j] /= nevents_mc[j];
	     avT1T2_mc[j] /= nevents_mc[j];
	  }
     }
   
   for(int i=0;i<nel_mc;i++)
     {
	int ib = 0;
	for(int j=0;j<ncosphiDef;j++)
	  {
	     if( v_cosphi_mc[i] >= cosphiDef[j] )
	       {
		  ib = j+1;
	       }	     
	  }
	
	avT1ERR_mc[ib] += pow(v_sd0t1_mc[i]-avT1_mc[ib],2);
	avT2ERR_mc[ib] += pow(v_sd0t2_mc[i]-avT2_mc[ib],2);
	avT1T2ERR_mc[ib] += pow(v_sd0t1_mc[i]*v_sd0t2_mc[i]-avT1T2_mc[ib],2);
     }   
   
   TH1F *h_data = new TH1F("h_data","h_data",ncosphiDef-1,xbins);
   TH1F *h_mc = new TH1F("h_mc","h_mc",ncosphiDef-1,xbins);
   
   for(int j=0;j<=ncosphiDef;j++)
     {
	if( nevents_data[j] > 1 )
	  { 
	     avT1ERR_data[j] /= (nevents_data[j]-1);
	     avT2ERR_data[j] /= (nevents_data[j]-1);
	     avT1T2ERR_data[j] /= (nevents_data[j]-1);
	     
	     avT1ERR_data[j] = sqrt(avT1ERR_data[j]);
	     avT2ERR_data[j] = sqrt(avT2ERR_data[j]);
	     avT1T2ERR_data[j] = sqrt(avT1T2ERR_data[j]);	     
	  }	
	
	double dif_data = avT1T2_data[j] - avT1_data[j]*avT2_data[j];
	double difERR_data = sqrt(pow(avT1T2ERR_data[j],2)+pow(avT1_data[j]*avT2ERR_data[j],2)+
				  pow(avT2_data[j]*avT1ERR_data[j],2));

	h_data->SetBinContent(j,dif_data);
	h_data->SetBinError(j,difERR_data);

	if( nevents_mc[j] > 0. )
	  { 
	     avT1ERR_mc[j] /= (nevents_mc[j]-1);
	     avT2ERR_mc[j] /= (nevents_mc[j]-1);
	     avT1T2ERR_mc[j] /= (nevents_mc[j]-1);
	     
	     avT1ERR_mc[j] = sqrt(avT1ERR_mc[j]);
	     avT2ERR_mc[j] = sqrt(avT2ERR_mc[j]);
	     avT1T2ERR_mc[j] = sqrt(avT1T2ERR_mc[j]);
	  }	
	
	double dif_mc = avT1T2_mc[j] - avT1_mc[j]*avT2_mc[j];
	double difERR_mc = sqrt(pow(avT1T2ERR_mc[j],2)+pow(avT1_mc[j]*avT2ERR_mc[j],2)+
				pow(avT2_mc[j]*avT1ERR_mc[j],2));

	h_mc->SetBinContent(j,dif_mc);
	h_mc->SetBinError(j,difERR_mc);
     }   
/*   
   TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
   leg->SetFillColor(253);                                                                              
   leg->SetBorderSize(0);   
   leg->AddEntry(h_MCfilt_bjet,"Filtered","p");
   leg->AddEntry(h_MCunfilt_bjet,"Unfiltered","p");   
   leg->Draw();

   std::string pname_bjet = "pics/templateFiltComp_bjet_"+var+"_"+ptr+"_"+sel+".eps";
   c1->Print(pname_bjet.c_str());

   leg->Clear();
   c1->Clear();
   
   h_MCfilt_cjet->Draw("hist e1 ");
   h_MCunfilt_cjet->Draw("hist e1 same");
   
   m1 = h_MCfilt_cjet->GetMaximum();
   m2 = h_MCunfilt_cjet->GetMaximum();
   m = (m1 >= m2) ? m1*k : m2*k;
   
   h_MCfilt_cjet->SetMaximum(m);
   
   TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
   leg->SetFillColor(253);                                                                              
   leg->SetBorderSize(0);   
   leg->AddEntry(h_MCfilt_cjet,"Filtered","p");
   leg->AddEntry(h_MCunfilt_cjet,"Unfiltered","p");
   leg->Draw();

   std::string pname_cjet = "pics/templateFiltComp_cjet_"+var+"_"+ptr+"_"+sel+".eps";
   c1->Print(pname_cjet.c_str());

   leg->Clear();
   c1->Clear();
   
   h_MCfilt_ljet->Draw("hist e1");
   h_MCunfilt_ljet->Draw("hist e1 same");
   
   m1 = h_MCfilt_ljet->GetMaximum();
   m2 = h_MCunfilt_ljet->GetMaximum();
   m = (m1 >= m2) ? m1*k : m2*k;
   
   h_MCfilt_ljet->SetMaximum(m);
   
   TLegend *leg = new TLegend(0.65,0.90,0.88,0.75);                                                     
   leg->SetFillColor(253);                                                                              
   leg->SetBorderSize(0);   
   leg->AddEntry(h_MCfilt_ljet,"Filtered","p");
   leg->AddEntry(h_MCunfilt_ljet,"Unfiltered","p");
   leg->Draw();
*/

   h_data->Draw("e1p");   
   std::string beam_data = "pics/beam_data.eps";
   c1->Print(beam_data.c_str());
   c1->Clear();

   h_mc->Draw("e1p");   
   std::string beam_mc = "pics/beam_mc.eps";
   c1->Print(beam_mc.c_str());
   c1->Clear();
   
   gApplication->Terminate();
}

