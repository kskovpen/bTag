#include "func.h"

int main(int argc, char *argv[])
{
   if( argc < 4 )
     {
	std::cout << "Specify the input directories [NOMINAL], [RW], [RW2] and [sysname]" << std::endl;
	exit(1);
     }   
   
   std::string hdir= "/home-pbs/kskovpen/bTag/CMSSW_7_4_0/src/LTAnalysis/run/";
   
   std::string inDirNOMINAL = argv[1];
   std::string fpathNOMINAL = hdir+inDirNOMINAL+"/";

   std::string inDirRW = argv[2];
   std::string fpathRW = hdir+inDirRW+"/";

   std::string inDirRW2 = argv[3];
   std::string fpathRW2 = hdir+inDirRW2+"/";
   
   rw = argv[4];
   
//   gROOT->ProcessLine(".L atlasstyle-00-03-04/AtlasStyle.C");
//   gROOT->ProcessLine(".L atlasstyle-00-03-04/AtlasUtils.C");
//   gROOT->ProcessLine(".L atlasstyle-00-03-04/AtlasLabels.C");
   
   SetAtlasStyle();

   def();
   
   // suppress verbose from Print
   gErrorIgnoreLevel = 5000;
   
   std::cout.precision(10);

   leg = new TLegend(0.65,0.90,0.88,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

   TFile *f_mc_sys = TFile::Open("../../histSYS/MC/data.root","UPDATE");
   TFile *f_data_sys = TFile::Open("../../histSYS/DATA/data.root","UPDATE");
   
   gStyle->SetHistTopMargin(0);

   TH1::AddDirectory(kFALSE);
   TH2::AddDirectory(kFALSE);

   openData_NOMINAL(fpathNOMINAL);
   openData_RW(fpathRW,fpathRW2);
   
   for(int ibtag=0;ibtag<nbtag;ibtag++)
     {
	std::cout << "run" << btag[ibtag] << std::endl;
	for(int iptbin=0;iptbin<nptbin;iptbin++)
	  {
	     PTname = ptbin[iptbin];
	     
	     for(int iflav=0;iflav<nflav;iflav++)
	       {	
		  std::string sptbin = ptbin[iptbin];
		  int nb[nvar];
		  double intI_NOMINAL[nvar];
		  double intI_RW[nvar];
		  double intI_RW2[nvar];
		  TH1D *h_data_noscale[nvar];
		  TH1D *h_mc_noscale_NOMINAL[nvar];
		  TH1D *h_mc_noscale_RW[nvar];
		  TH1D *h_mc_noscale_RW2[nvar];
		  
		  for(int iv=0;iv<nvar;iv++)
		    {		       
		       std::string histName = var1d[iv] + "_" + flav[iflav] + sptbin + "_nosel" + btag[ibtag];
//		       std::cout << histName << std::endl;
		       readData(histName,iv,1); // NOMINAL
		       readData(histName,iv,0); // RW
		       readData(histName,iv,2); // RW2
		       
		       nb[iv] = h_mc_NOMINAL[iv]->GetXaxis()->GetNbins();
		       
			 {			    
			    std::string data_noscale_name = std::string(h_data[iv]->GetName()) + "_clone_noscale";
			    h_data_noscale[iv] = (TH1D*)h_data[iv]->Clone(data_noscale_name.c_str());		       
			    std::string mc_noscale_name = std::string(h_mc_NOMINAL[iv]->GetName()) + "_clone_noscale_NOMINAL";
			    h_mc_noscale_NOMINAL[iv] = (TH1D*)h_mc_NOMINAL[iv]->Clone(mc_noscale_name.c_str());
		       
			    intI_NOMINAL[iv] = h_mc_NOMINAL[iv]->Integral(0,nb[iv]+1);
			    
			    if( h_mc_NOMINAL[iv]->Integral(0,nb[iv]+1) > 0 ) h_mc_NOMINAL[iv]->Scale(1./h_mc_NOMINAL[iv]->Integral(0,nb[iv]+1));
			    if( h_data[iv]->Integral(0,nb[iv]+1) > 0 ) h_data[iv]->Scale(1./h_data[iv]->Integral(0,nb[iv]+1));
			 }
			 {
			    std::string mc_noscale_name = std::string(h_mc_RW[iv]->GetName()) + "_clone_noscale_RW";
			    h_mc_noscale_RW[iv] = (TH1D*)h_mc_RW[iv]->Clone(mc_noscale_name.c_str());

			    intI_RW[iv] = h_mc_RW[iv]->Integral(0,nb[iv]+1);

//			    if( inDirRW != "histMJ" && inDirRW != "histMJSYS" && inDirRW != "histTTBARSYS"
//			      )
//			      {
//				 if( intI_RW[iv] > 0 ) h_mc_noscale_RW[iv]->Scale(1./intI_RW[iv]);
//				 if( intI_NOMINAL[iv] > 0 ) h_mc_noscale_RW[iv]->Scale(intI_NOMINAL[iv]);
//			      }
      		    
			    if( intI_NOMINAL[iv] > 0 ) h_mc_RW[iv]->Scale(1./intI_NOMINAL[iv]);
			    
//			    if( h_mc_RW[iv]->Integral(0,nb[iv]+1) > 0 ) h_mc_RW[iv]->Scale(1./h_mc_RW[iv]->Integral(0,nb[iv]+1));			    
			 }		       
			 {
			    std::string mc_noscale_name = std::string(h_mc_RW2[iv]->GetName()) + "_clone_noscale_RW2";
			    h_mc_noscale_RW2[iv] = (TH1D*)h_mc_RW2[iv]->Clone(mc_noscale_name.c_str());

			    intI_RW2[iv] = h_mc_RW2[iv]->Integral(0,nb[iv]+1);

//			    if( inDirRW2 != "histMJ" && inDirRW2 != "histMJSYS" && inDirRW2 != "histTTBARSYS"
//			      )
//			      {
//				 if( intI_RW2[iv] > 0 ) h_mc_noscale_RW2[iv]->Scale(1./intI_RW2[iv]);
//				 if( intI_NOMINAL[iv] > 0 ) h_mc_noscale_RW2[iv]->Scale(intI_NOMINAL[iv]);
//			      }

			    if( intI_NOMINAL[iv] > 0 ) h_mc_RW2[iv]->Scale(1./intI_NOMINAL[iv]);
			    
//			    if( h_mc_RW2[iv]->Integral(0,nb[iv]+1) > 0 ) h_mc_RW2[iv]->Scale(1./h_mc_RW2[iv]->Integral(0,nb[iv]+1));
			 }		       
		       
		       if( iflav == 0 )
			 {			    
			    std::string nname = sptbin+btag[ibtag]+"_"+var1d[iv];
			    plotCOMP(h_mc_RW[iv],h_data[iv],nname,titx[iv]);
			 }		       
		    }		  

//		  std::string hnameSAVE = "h_j1_JPRW_"+flav[iflav]+sptbin+"_nosel"+btag[ibtag];
		  std::string hnameSAVE = "h_j1_JP_"+flav[iflav]+sptbin+"_nosel"+btag[ibtag];

		  TH1D *h_mc_RW_sys_low = (TH1D*)h_mc_RW[0]->Clone("h_JP_RW_sys_low");
		  TH1D *h_mc_RW_sys_up = (TH1D*)h_mc_RW[0]->Clone("h_JP_RW_sys_up");

		  doSys(h_mc_NOMINAL[0],
			h_mc_RW[0],
			h_mc_RW2[0],
			h_mc_RW_sys_low,
			h_mc_RW_sys_up);
		  
		  std::string hnameSAVE_sys_low = hnameSAVE + "_"+rw+"_low";
		  TH1D *h_mc_RW_sys_low_noscale = (TH1D*)h_mc_RW_sys_low->Clone(hnameSAVE_sys_low.c_str());
		  std::string hnameSAVE_sys_up = hnameSAVE + "_"+rw+"_up";
		  TH1D *h_mc_RW_sys_up_noscale = (TH1D*)h_mc_RW_sys_up->Clone(hnameSAVE_sys_up.c_str());
		  
		  double integ_noscale;
//		  if( useCorMC )
//		    integ_noscale = intI_RW[0];
//		  else
		    integ_noscale = intI_NOMINAL[0];
		  
		  h_mc_RW_sys_low_noscale->Scale(integ_noscale);
		  h_mc_RW_sys_up_noscale->Scale(integ_noscale);
		  
//		  if( inDirRW == "histMJ" || inDirRW == "histMJSYS" || inDirRW == "histTTBARSYS" )
//		    {
//		       h_mc_RW_sys_low_noscale = (TH1D*)h_mc_noscale_RW[0]->Clone("copy_low");
//		       h_mc_RW_sys_up_noscale = (TH1D*)h_mc_noscale_RW[0]->Clone("copy_up");
//		       h_mc_RW_sys_low_noscale->SetName(hnameSAVE_sys_low.c_str());
//		       h_mc_RW_sys_up_noscale->SetName(hnameSAVE_sys_up.c_str());
//		    }

		  std::string nname = sptbin+btag[ibtag];
		  if( iflav == 0 )
		    {		       
		       plotSF(h_mc_RW[0],
			      h_mc_NOMINAL[0],
			      h_mc_RW_sys_low,
			      h_mc_RW_sys_up,
			      h_data[0],
			      nname);
		    }		  
		  
		  // Update files with the new histograms
		  f_mc_sys->cd();
//		  std::string hnameRW = h_mc_noscale_RW[0]->GetName();
		  TH1D *hval;
		  if( useCorMC )
		    {
		       hval = h_mc_noscale_RW[0];
		       h_mc_noscale_RW[0]->Write(hnameSAVE.c_str(),TObject::kOverwrite);
		    }		  
		  else
		    {
		       TH1D* h_mc_y_noscale_norw = (TH1D*)h_mc_noscale_NOMINAL[0]->Clone(hnameSAVE.c_str());
		       h_mc_y_noscale_norw->Write(hnameSAVE.c_str(),TObject::kOverwrite);
		       hval = h_mc_y_noscale_norw;
		    }		  
		  
		  valSys(hval,
			 h_mc_RW_sys_low_noscale,
			 h_mc_RW_sys_up_noscale);

		  h_mc_RW_sys_low_noscale->Write("",TObject::kOverwrite);
		  h_mc_RW_sys_up_noscale->Write("",TObject::kOverwrite);
		  
		  f_data_sys->cd();
//		  std::string h_data_y_rw_name = "h_j1_JPRW_"+flav[iflav]+sptbin+"_nosel"+btag[ibtag];
		  std::string h_data_y_rw_name = "h_j1_JP_"+flav[iflav]+sptbin+"_nosel"+btag[ibtag];
		  TH1D *h_data_y_rw = (TH1D*)h_data_noscale[0]->Clone(h_data_y_rw_name.c_str());
		  h_data_y_rw->Write("",TObject::kOverwrite);

		  std::string h_data_y_rw_ntrk_sys_low_name = hnameSAVE+"_"+rw+"_low";
		  std::string h_data_y_rw_ntrk_sys_up_name = hnameSAVE+"_"+rw+"_up";
		  TH1D *h_data_y_rw_ntrk_sys_low_noscale = (TH1D*)h_data_noscale[0]->Clone(h_data_y_rw_ntrk_sys_low_name.c_str());
		  TH1D *h_data_y_rw_ntrk_sys_up_noscale = (TH1D*)h_data_noscale[0]->Clone(h_data_y_rw_ntrk_sys_up_name.c_str());
		  h_data_y_rw_ntrk_sys_low_noscale->Write("",TObject::kOverwrite);
		  h_data_y_rw_ntrk_sys_up_noscale->Write("",TObject::kOverwrite);
		  
		  nname = flav[iflav]+sptbin+btag[ibtag];
		  plotSYS(h_mc_noscale_RW[0],
			  h_mc_noscale_RW2[0],
			  h_mc_noscale_NOMINAL[0],
			  h_mc_RW_sys_low_noscale,
			  h_mc_RW_sys_up_noscale,
			  h_data_noscale[0],
			  nname);
	       }	     
	  }	
     }
   
   // light flavour jet systematics from data
/*   for(int iptbin=0;iptbin<nptbin;iptbin++)
     {
	std::string sptbin = ptbin[iptbin];
	
	std::string histName_ajet_untag = "h_j1_JP_ajet_"+sptbin+"_nosel_UNTAGbc";
	std::string histName_bjet_untag = "h_j1_JP_bjet_"+sptbin+"_nosel_UNTAGbc";
	std::string histName_cjet_untag = "h_j1_JP_cjet_"+sptbin+"_nosel_UNTAGbc";
	std::string histName_ljet_untag = "h_j1_JP_ljet_"+sptbin+"_nosel_UNTAGbc";
	
	TH1D *h_untag;
	bool readNOMINAL = 0;
	readDataJP(histName_ajet_untag,0,1);
	h_untag = h_untag_NOMINAL;
	TH1D *h_ajet_untag = (TH1D*)h_untag->Clone("h_ajet_untag");
	readDataJP(histName_bjet_untag,1,readNOMINAL);
	if( readNOMINAL ) h_untag = h_untag_NOMINAL;
	else h_untag = h_untag_RW;
	TH1D *h_bjet_untag = (TH1D*)h_untag->Clone("h_bjet_untag");
	readDataJP(histName_cjet_untag,1,readNOMINAL);
	if( readNOMINAL ) h_untag = h_untag_NOMINAL;
	else h_untag = h_untag_RW;
	TH1D *h_cjet_untag = (TH1D*)h_untag->Clone("h_cjet_untag");
	readDataJP(histName_ljet_untag,1,readNOMINAL);
	if( readNOMINAL ) h_untag = h_untag_NOMINAL;
	else h_untag = h_untag_RW;
	TH1D *h_ljet_untag = (TH1D*)h_untag->Clone("h_ljet_untag");
	
	int nbins = h_ajet_untag->GetXaxis()->GetNbins();
	double int_ajet_untag = h_ajet_untag->Integral(0,nbins+1);
	double int_bjet_untag = h_bjet_untag->Integral(0,nbins+1);
	double int_cjet_untag = h_cjet_untag->Integral(0,nbins+1);
	double int_ljet_untag = h_ljet_untag->Integral(0,nbins+1);
	double int_mc = int_bjet_untag+int_cjet_untag+int_ljet_untag;

	if( int_ajet_untag > 0. ) h_ajet_untag->Scale(1./int_ajet_untag);
	if( int_mc > 0. )
	  {
	     h_bjet_untag->Scale(1./int_mc);
	     h_cjet_untag->Scale(1./int_mc);
	  }	
	TH1D *h_ljet_untag_4stack = (TH1D*)h_ljet_untag->Clone("h_ljet_untag_4stack");
	if( int_mc > 0. ) h_ljet_untag_4stack->Scale(1./int_mc);
	if( int_ljet_untag > 0. ) h_ljet_untag->Scale(1./int_ljet_untag);
	TH1D *h_bjet_untag_4stack = (TH1D*)h_bjet_untag->Clone("h_bjet_untag_4stack");
	TH1D *h_cjet_untag_4stack = (TH1D*)h_cjet_untag->Clone("h_cjet_untag_4stack");
	TH1D *h_ajet_untag_4stack = (TH1D*)h_ajet_untag->Clone("h_ajet_untag_4stack");

	addbin(h_ljet_untag_4stack);
	addbin(h_cjet_untag_4stack);
	addbin(h_bjet_untag_4stack);
	addbin(h_ajet_untag_4stack);
	
	TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
	h_ljet_untag_4stack->SetFillColor(kGreen);
	h_cjet_untag_4stack->SetFillColor(kBlue);
	h_bjet_untag_4stack->SetFillColor(kRed);
	THStack *h_mc = new THStack();
	h_mc->Add(h_ljet_untag_4stack);
	h_mc->Add(h_cjet_untag_4stack);
	h_mc->Add(h_bjet_untag_4stack);
	
	h_mc->Draw("hist");
	h_ajet_untag_4stack->Draw("e1p same");

	double max_mc = h_mc->GetMaximum();
	double max_data = h_ajet_untag_4stack->GetMaximum();
	if( max_mc > max_data ) h_mc->SetMaximum(1.2*max_mc);
	else h_mc->SetMaximum(1.2*max_data);
	
	std::string pname1 = "pics/valstack_ljet_data_"+sptbin+".eps";
	c1->Print(pname1.c_str());
	c1->Clear();
	delete c1;
	
	TH1D *h_ljet_data_untag = (TH1D*)h_ajet_untag->Clone("h_ljet_data_untag");
	h_ljet_data_untag->Add(h_bjet_untag,-1.);
	h_ljet_data_untag->Add(h_cjet_untag,-1.);
	double int_ljet_data_untag = h_ljet_data_untag->Integral();
	if( int_ljet_data_untag > 0. ) h_ljet_data_untag->Scale(1./int_ljet_data_untag);

	TH1D *h_ljet_untag_sys_low = (TH1D*)h_ljet_untag->Clone("h_ljet_untag_sys_low");
	TH1D *h_ljet_untag_sys_up = (TH1D*)h_ljet_untag->Clone("h_ljet_untag_sys_up");
	
	doSys(h_ljet_untag,
	      h_ljet_data_untag,
	      h_ljet_untag_sys_low,
	      h_ljet_untag_sys_up);
	
	TCanvas *c2 = new TCanvas("c2","c2",0,0,600,500);
	
	h_ljet_data_untag->SetLineColor(kRed);
        h_ljet_data_untag->SetMarkerSize(0);
	h_ljet_data_untag->SetLineStyle(2);
	
	h_ljet_data_untag->Draw("hist e1");
	
	TGraphAsymmErrors *gr_mc_merged;
	
	gr_mc_merged = makeErrorBand(h_ljet_untag,
				     h_ljet_untag_sys_up,
				     h_ljet_untag_sys_low);
	
	gr_mc_merged->SetFillStyle(3004);
	gStyle->SetHatchesLineWidth(2);
	gr_mc_merged->Draw("2SAME");
	
	h_ljet_untag->Draw("hist same");
	
	h_ljet_data_untag->SetMaximum(h_ljet_data_untag->GetMaximum()*1.3);
	
	h_ljet_data_untag->GetXaxis()->SetTitle("Jet probability");
	
	std::string pname2 = "pics/valsys_ljet_data_"+sptbin+".eps";
	c2->Print(pname2.c_str());
	c2->Clear();
	delete c2;

	double fracUp[nbins];
	double fracLow[nbins];
	for(int ib=0;ib<=nbins+1;ib++)
	  {
	     double v0 = h_ljet_untag->GetBinContent(ib);
	     double vUp = h_ljet_untag_sys_up->GetBinContent(ib);
	     double vLow = h_ljet_untag_sys_low->GetBinContent(ib);
	     fracUp[ib-1] = (v0 > 0.) ? vUp/v0 : 0.;
	     fracLow[ib-1] = (v0 > 0.) ? vLow/v0 : 0.;
	  }	

	// apply sys
	for(int ibtag=0;ibtag<nbtag;ibtag++)
	  {	
	     for(int iflav=0;iflav<nflav;iflav++)
	       {
		  std::string histName = "h_j1_JP_"+flav[iflav]+sptbin+"_nosel"+btag[ibtag];
	
		  TH1D *h;
		  readDataJP(histName,1,1);
		  h = h_untag_NOMINAL;
		  std::string ljet_name_sys_low = histName+"_val_low";
		  std::string ljet_name_sys_up = histName+"_val_up";
		  TH1D *h_ljet_val_low = (TH1D*)h->Clone(ljet_name_sys_low.c_str());
		  TH1D *h_ljet_val_up = (TH1D*)h->Clone(ljet_name_sys_up.c_str());
		  if( iflav == 3 ) // ljet
		    {		       
		       for(int ib=0;ib<=nbins+1;ib++)
			 {
			    double v0 = h->GetBinContent(ib);
			    double vUp = v0*fracUp[ib-1];
			    double vLow = v0*fracLow[ib-1];
			    h_ljet_val_up->SetBinContent(ib,vUp);
			    h_ljet_val_low->SetBinContent(ib,vLow);
			 }	
		    }		  
	
		  f_mc_sys->cd();
		  h_ljet_val_up->Write("",TObject::kOverwrite);
		  h_ljet_val_low->Write("",TObject::kOverwrite);

		  TCanvas *c3 = new TCanvas("c3","c3",0,0,600,500);
		  
		  h->Draw("hist");
		  
		  TGraphAsymmErrors *gr_mc_merged_sys;
		  
		  gr_mc_merged_sys = makeErrorBand(h,
						   h_ljet_val_up,
						   h_ljet_val_low);
	
		  gr_mc_merged_sys->SetFillStyle(3004);
		  gStyle->SetHatchesLineWidth(2);
		  gr_mc_merged_sys->Draw("2SAME");
		  
		  h->SetMaximum(h->GetMaximum()*1.3);
	
		  h->GetXaxis()->SetTitle("Jet probability");
	
		  std::string pname3 = "pics/sysready_"+flav[iflav]+"val_"+sptbin+btag[ibtag]+".eps";
		  c3->Print(pname3.c_str());
		  c3->Clear();
		  delete c3;
		  
		  readDataJP(histName,0,1);
		  h = h_untag_NOMINAL;
		  TH1D *h_ljet_data_val_low = (TH1D*)h->Clone(ljet_name_sys_low.c_str());
		  TH1D *h_ljet_data_val_up = (TH1D*)h->Clone(ljet_name_sys_up.c_str());		  

		  f_data_sys->cd();
		  h_ljet_data_val_up->Write("",TObject::kOverwrite);
		  h_ljet_data_val_low->Write("",TObject::kOverwrite);
	       }
	  }	
		  
	delete h_ljet_data_untag;
	delete h_ljet_untag_sys_up;
	delete h_ljet_untag_sys_low;
     }*/   

   // close files
   f_mc_sys->Write();
   f_mc_sys->Close();

   f_data_sys->Write();
   f_data_sys->Close();
}
