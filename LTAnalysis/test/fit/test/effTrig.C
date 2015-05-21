TFile *fbatch_MC[100];
TFile *fbatch_DATA[100];

std::string toolMC = "plot_AtB11_TRIG_v1_AtB11_NORW";
std::string fpathMC = "/gcf/atlas/data/JTNtuple_hist/run_"+toolMC+"/";
std::string toolDATA = "plot_AtB11_TRIG_v1_AtB11_NORW";
std::string fpathDATA = "/gcf/atlas/data/JTNtuple_hist/run_"+toolDATA+"/";

const int nper = 12;
std::string per[nper] =
{"A",
 "B1",
 "B2",
 "B3",
 "B4",
 "B5",
 "B6",
 "B7",
 "B8",
 "B9",
 "B10",
 "B11"
};   

const int ntrig = 35;
std::string trig[ntrig] =
{"EF_j15_a4tchad",
 "EF_j25_a4tchad",
 "EF_j55_a4tchad",
 "EF_j80_a4tchad",
 "EF_j110_a4tchad",
 "EF_j145_a4tchad",
 "EF_j220_a4tchad",
 "EF_j280_a4tchad",
 "EF_j360_a4tchad",
 "EF_j380_a4tthad",
 "EF_j460_a4tchad",
 "EF_mu4T_j15_a4tchad_matched",
 "EF_mu4T_j15_a4tchad_matchedZ",
 "EF_mu4T_j25_a4tchad_matched",
 "EF_mu4T_j25_a4tchad_matchedZ",
 "EF_mu4T_j35_a4tchad_matched",
 "EF_mu4T_j35_a4tchad_matchedZ",
 "EF_mu4T_j55_a4tchad_L2FS_matched",
 "EF_mu4T_j55_a4tchad_L2FS_matchedZ",
 "EF_mu4T_j55_a4tchad_matched",
 "EF_mu4T_j55_a4tchad_matchedZ",
 "EF_mu4T_j80_a4tchad_L2FS_matched",
 "EF_mu4T_j80_a4tchad_matched",
 "EF_mu4T_j110_a4tchad_L2FS_matched",
 "EF_mu4T_j110_a4tchad_matched",
 "EF_mu4T_j145_a4tchad_L2FS_matched",
 "EF_mu4T_j145_a4tchad_matched",
 "EF_mu4T_j180_a4tchad_L2FS_matched",
 "EF_mu4T_j180_a4tchad_matched",
 "EF_mu4T_j220_a4tchad_L2FS_matched",
 "EF_mu4T_j220_a4tchad_matched",
 "EF_mu4T_j280_a4tchad_matched",
 "EF_mu4T_j280_a4tchad_L2FS_matched",
 "EF_mu4T_j360_a4tchad_matched",
 "EF_mu4T_j360_a4tchad_L2FS_matched"
};

const int nptbinsReal = 6;
float ptbinsReal[nptbinsReal] = {0.110,0.140,0.200,0.260,0.340,0.500};

const int nptbins = 29;
float ptbins[nptbins] = {
   0.110,0.115,0.120,0.125,0.130,0.135,0.140,
     0.145,0.150,0.155,0.160,0.170,0.180,0.190,0.200,
     0.210,0.220,0.230,0.240,
     0.250,0.260,0.280,0.300,0.320,0.340,
     0.380,0.420,0.460,0.500};

void effTrig()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine("#include <string>");
   gROOT->ProcessLine("#include <TH1F.h>");
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   int runID;
   float jPt;
   float SF;
   bool trigDec[ntrig];

   TChain *tr[2];
   
   tr[0] = new TChain("treeTrig");
   tr[1] = new TChain("treeTrig");
   
   for(int ic=0;ic<2;ic++)
     {	
	tr[ic]->SetBranchAddress("jPt",&jPt);
	tr[ic]->SetBranchAddress("runID",&runID);
	tr[ic]->SetBranchAddress("SF",&SF);
	for(int it=0;it<ntrig;it++)
	  {	     
	     tr[ic]->SetBranchAddress(trig[it].c_str(),&trigDec[it]);
	  }	
     }   

   for(int i=0;i<v_data.size();i++)
     {
	std::string fname = fpathDATA+v_data.at(i);	
	tr[0]->Add(fname.c_str());
     }

   for(int i=0;i<v_mc_filt.size();i++)
     {
	std::string fname = fpathMC+v_mc_filt.at(i);
	tr[1]->Add(fname.c_str());
     }

   std::string histname_data[ntrig][nper];
   std::string histname_datacomb[ntrig];
   std::string histname_mc[ntrig];
   float icTrig_data[nptbins][ntrig][nper];
   float icCount_data[nptbins][nper];
   float icTrigw2_data[nptbins][ntrig][nper];
   float icCountw2_data[nptbins][nper];
   float icTrig_datacomb[nptbins][ntrig];
   float icCount_datacomb[nptbins];
   float icTrigw2_datacomb[nptbins][ntrig];
   float icCountw2_datacomb[nptbins];
   float icTrig_mc[nptbins][ntrig];
   float icCount_mc[nptbins];
   float icTrigw2_mc[nptbins][ntrig];
   float icCountw2_mc[nptbins];
   TH1F *h_trig_jPt_data[ntrig][nper];
   TH1F *h_trig_jPt_datacomb[ntrig];
   TH1F *h_trig_jPt_mc[ntrig];

   std::cout << "Process data per period" << std::endl;
   
   // data
   for(int ip=0;ip<nper;ip++)
     {	
	for(int ipt=0;ipt<nptbins;ipt++)
	  {	       
	     icCount_data[ipt][ip] = 0.;
	     icCountw2_data[ipt][ip] = 0.;
	  }	    
	
	for(int it=0;it<ntrig;it++)
	  {
	     histname_data[it][ip] = "trigEff_jPt_"+trig[it]+"_"+per[ip];
	     std::string hname = histname_data[it][ip]+"_data";
	     h_trig_jPt_data[it][ip] = new TH1F(hname.c_str(),hname.c_str(),nptbins-1,ptbins);
	     for(int ipt=0;ipt<nptbins;ipt++)
	       {
		  icTrig_data[ipt][it][ip] = 0.;
		  icTrigw2_data[ipt][it][ip] = 0.;
	       }	
	  }
	
	int nev = tr[0]->GetEntries();
	
	for(int i=0;i<nev;i++)
	  {
	     tr[0]->GetEntry(i);
	     
	     int runPeriod = getPeriod(runID);
	     float jetPt = jPt/1000.;
	     
	     if( jetPt >= 0.5 || jetPt <= 0.110 ) continue;
	     
	     int ptidx = -1;
	     for(int ipt=1;ipt<nptbins;ipt++)
	       {
		  if( jetPt >= ptbins[ipt-1] &&
		      jetPt < ptbins[ipt] )
		    ptidx = ipt-1;
	       }	
	     
	     icCount_data[ptidx][runPeriod-1] += SF;
	     icCountw2_data[ptidx][runPeriod-1] += SF*SF;

	     for(int it=0;it<ntrig;it++)
	       {		  
		  if( trigDec[it] ) 
		    {
		       icTrig_data[ptidx][it][runPeriod-1] += SF;
		       icTrigw2_data[ptidx][it][runPeriod-1] += SF*SF;
		    }		  
	       }	     
	  }
     }   

   std::cout << "Process data" << std::endl;
   
   // mc, data combined
   for(int ipt=0;ipt<nptbins;ipt++)
     {	       
	icCount_datacomb[ipt] = 0.;
	icCountw2_datacomb[ipt] = 0.;
	icCount_mc[ipt] = 0.;
	icCountw2_mc[ipt] = 0.;
     }	    
   
   for(int it=0;it<ntrig;it++)
     {
	histname_datacomb[it] = "trigEff_jPt_"+trig[it];
	std::string hname = histname_datacomb[it]+"_datacomb";
	h_trig_jPt_datacomb[it] = new TH1F(hname.c_str(),hname.c_str(),nptbins-1,ptbins);
	for(int ipt=0;ipt<nptbins;ipt++)
	  {
	     icTrig_datacomb[ipt][it] = 0.;
	     icTrigw2_datacomb[ipt][it] = 0.;
	  }	

	histname_mc[it] = "trigEff_jPt_"+trig[it];
	std::string hname = histname_mc[it]+"_mc";
	h_trig_jPt_mc[it] = new TH1F(hname.c_str(),hname.c_str(),nptbins-1,ptbins);
	for(int ipt=0;ipt<nptbins;ipt++)
	  {
	     icTrig_mc[ipt][it] = 0.;
	     icTrigw2_mc[ipt][it] = 0.;
	  }	
     }
   
   int nev_datacomb = tr[0]->GetEntries();
   int nev_mc = tr[1]->GetEntries();
   
   for(int i=0;i<nev_datacomb;i++)
     {
	tr[0]->GetEntry(i);
	
	float jetPt = jPt/1000.;
	
	if( jetPt >= 0.5 || jetPt <= 0.110 ) continue;
	
	int ptidx = -1;
	for(int ipt=1;ipt<nptbins;ipt++)
	  {
	     if( jetPt >= ptbins[ipt-1] &&
		 jetPt < ptbins[ipt] )
	       ptidx = ipt-1;
	  }	
	
	icCount_datacomb[ptidx] += SF;
	icCountw2_datacomb[ptidx] += SF*SF;

	for(int it=0;it<ntrig;it++)
	  {
	     if( trigDec[it] )
	       {
		  icTrig_datacomb[ptidx][it] += SF;
		  icTrigw2_datacomb[ptidx][it] += SF*SF;
	       }	     
	  }	
     }   

   std::cout << "Process MC" << std::endl;
   
   for(int i=0;i<nev_mc;i++)
     {
	tr[1]->GetEntry(i);
	
	float jetPt = jPt/1000.;
	
	if( jetPt >= 0.5 || jetPt <= 0.110 ) continue;
	
	int ptidx = -1;
	for(int ipt=1;ipt<nptbins;ipt++)
	  {
	     if( jetPt >= ptbins[ipt-1] &&
		 jetPt < ptbins[ipt] )
	       ptidx = ipt-1;
	  }	
	
	icCount_mc[ptidx] += SF;
	icCountw2_mc[ptidx] += SF*SF;

	for(int it=0;it<ntrig;it++)
	  {
	     if( trigDec[it] )
	       {
		  icTrig_mc[ptidx][it] += SF;
		  icTrigw2_mc[ptidx][it] += SF*SF;
	       }	     
	  }	
     }   

   std::cout << "Produce plots" << std::endl;

   TLegend *leg = new TLegend(0.75,0.60,0.90,0.45);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   TLine *lpt[nptbinsReal];
   for(int ipt=0;ipt<nptbinsReal;ipt++)
     {
	lpt[ipt] = new TLine(ptbinsReal[ipt],0,ptbinsReal[ipt],1.0);
	lpt[ipt]->SetLineStyle(2);
	lpt[ipt]->SetLineWidth(2);
	lpt[ipt]->SetLineColor(kBlue-9);
     }   
   
   for(int ip=0;ip<nper;ip++)
     {	
	for(int it=0;it<ntrig;it++)
	  {
	     for(int ipt=0;ipt<nptbins;ipt++)
	       {
		  double eff_data = (icCount_data[ipt][ip] > 0) ? icTrig_data[ipt][it][ip]/icCount_data[ipt][ip] : 0.;
		  double efferr_data = errf(icTrig_data[ipt][it][ip],sqrt(icTrigw2_data[ipt][it][ip]),icCount_data[ipt][ip],sqrt(icCountw2_data[ipt][ip]));

		  if( ip == 0 )
		    {		       
		       double eff_mc = (icCount_mc[ipt] > 0) ? icTrig_mc[ipt][it]/icCount_mc[ipt] : 0.;
		       double efferr_mc = errf(icTrig_mc[ipt][it],sqrt(icTrigw2_mc[ipt][it]),icCount_mc[ipt],sqrt(icCountw2_mc[ipt]));

		       h_trig_jPt_mc[it]->SetBinContent(ipt+1,eff_mc);
		       h_trig_jPt_mc[it]->SetBinError(ipt+1,efferr_mc);

		       double eff_datacomb = (icCount_datacomb[ipt] > 0) ? icTrig_datacomb[ipt][it]/icCount_datacomb[ipt] : 0.;
		       double efferr_datacomb = errf(icTrig_datacomb[ipt][it],sqrt(icTrigw2_datacomb[ipt][it]),icCount_datacomb[ipt],sqrt(icCountw2_datacomb[ipt]));

		       h_trig_jPt_datacomb[it]->SetBinContent(ipt+1,eff_datacomb);
		       h_trig_jPt_datacomb[it]->SetBinError(ipt+1,efferr_datacomb);
		    }
		       
		  h_trig_jPt_data[it][ip]->SetBinContent(ipt+1,eff_data);
		  h_trig_jPt_data[it][ip]->SetBinError(ipt+1,efferr_data);
	       }
	     
	     h_trig_jPt_data[it][ip]->SetMarkerStyle(20);
	     h_trig_jPt_data[it][ip]->SetMarkerSize(0.8);
	     h_trig_jPt_data[it][ip]->SetMarkerColor(kBlack);
	     h_trig_jPt_data[it][ip]->SetLineColor(kBlack);
	     h_trig_jPt_data[it][ip]->Draw("e1");
	     h_trig_jPt_data[it][ip]->GetXaxis()->SetTitle("P_{T} [TeV]");
	     h_trig_jPt_data[it][ip]->GetYaxis()->SetTitle("Efficiency");

	     double m_data = h_trig_jPt_data[it][ip]->GetMaximum();
	     h_trig_jPt_data[it][ip]->SetMaximum(m_data*1.1);

	     c1->Update();
	     double ymax = gPad->GetUymax();
	     for(int il=0;il<nptbinsReal;il++)
	       {
		  lpt[il]->SetY2(ymax);
		  lpt[il]->Draw("same");
	       }	     
	     
	     std::string fsave = "pics/"+histname_data[it][ip]+"_data_alone.eps";
	     c1->Print(fsave.c_str());
	     c1->Clear();		     
	     
	     h_trig_jPt_data[it][ip]->SetMaximum(m_data);

	     h_trig_jPt_data[it][ip]->Draw("e1");

	     h_trig_jPt_mc[it]->SetMarkerStyle(26);
	     h_trig_jPt_mc[it]->SetMarkerSize(0.8);
	     h_trig_jPt_mc[it]->SetMarkerColor(kRed);
	     h_trig_jPt_mc[it]->SetLineColor(kRed);
	     h_trig_jPt_mc[it]->Draw("e1 same");
	     h_trig_jPt_mc[it]->GetXaxis()->SetTitle("P_{T} [TeV]");
	     h_trig_jPt_mc[it]->GetYaxis()->SetTitle("Efficiency");
	     
	     leg->AddEntry(h_trig_jPt_data[it][ip],"Data","lep");
	     leg->AddEntry(h_trig_jPt_mc[it],"MC","lep");
	     leg->Draw();
	     
	     h_trig_jPt_data[it][ip]->GetYaxis()->SetRangeUser(0.0,1.0);
	     
	     c1->Update();
	     double ymax = gPad->GetUymax();
	     for(int il=0;il<nptbinsReal;il++)
	       {
		  lpt[il]->SetY2(ymax);
		  lpt[il]->Draw("same");
	       }	     
	     
	     std::string fsave = "pics/"+histname_data[it][ip]+".eps";
	     c1->Print(fsave.c_str());
	     leg->Clear();
	     c1->Clear();		     
	     
	     h_trig_jPt_data[it][ip]->SetMaximum(m_data);
	     
	     if( ip == 0 )	       
	       {
		  // mc alone
		  h_trig_jPt_mc[it]->Draw("e1");

		  double m_mc = h_trig_jPt_mc[it]->GetMaximum();
		  h_trig_jPt_mc[it]->GetYaxis()->SetRangeUser(0.0,1.0);
		  
		  c1->Update();
		  double ymax = gPad->GetUymax();
		  for(int il=0;il<nptbinsReal;il++)
		    {
		       lpt[il]->SetY2(ymax);
		       lpt[il]->Draw("same");
		    }	     
		  
		  std::string fsave = "pics/"+histname_mc[it]+"_mc_alone.eps";
		  c1->Print(fsave.c_str());
		  c1->Clear();		     
		  
		  h_trig_jPt_mc[it]->SetMaximum(m_mc);
		  
		  // datacomb alone
		  h_trig_jPt_datacomb[it]->SetMarkerStyle(20);
		  h_trig_jPt_datacomb[it]->SetMarkerSize(0.8);
		  h_trig_jPt_datacomb[it]->SetMarkerColor(kBlack);
		  h_trig_jPt_datacomb[it]->SetLineColor(kBlack);
		  h_trig_jPt_datacomb[it]->GetXaxis()->SetTitle("P_{T} [TeV]");
		  h_trig_jPt_datacomb[it]->GetYaxis()->SetTitle("Efficiency");
		  h_trig_jPt_datacomb[it]->Draw("e1");
		  
		  double m_datacomb = h_trig_jPt_datacomb[it]->GetMaximum();
		  h_trig_jPt_datacomb[it]->SetMaximum(m_datacomb*1.1);
		  
		  c1->Update();
		  double ymax = gPad->GetUymax();
		  for(int il=0;il<nptbinsReal;il++)
		    {
		       lpt[il]->SetY2(ymax);
		       lpt[il]->Draw("same");
		    }	     
		  
		  std::string fsave = "pics/"+histname_datacomb[it]+"_datacomb_alone.eps";
		  c1->Print(fsave.c_str());
		  c1->Clear();		     
		  
		  h_trig_jPt_datacomb[it]->SetMaximum(m_datacomb);
		  
		  // datacomb + mc
		  h_trig_jPt_datacomb[it]->Draw("e1");
		  h_trig_jPt_mc[it]->Draw("e1 same");
		  
		  h_trig_jPt_datacomb[it]->GetYaxis()->SetRangeUser(0.0,1.0);
		  
		  c1->Update();
		  double ymax = gPad->GetUymax();
		  for(int il=0;il<nptbinsReal;il++)
		    {
		       lpt[il]->SetY2(ymax);
		       lpt[il]->Draw("same");
		    }	     

		  leg->AddEntry(h_trig_jPt_datacomb[it],"Data","lep");
		  leg->AddEntry(h_trig_jPt_mc[it],"MC","lep");
		  leg->Draw();
		  
		  std::string fsave = "pics/"+histname_datacomb[it]+".eps";
		  c1->Print(fsave.c_str());
		  leg->Clear();
		  c1->Clear();		     		  
		  
		  h_trig_jPt_datacomb[it]->SetMaximum(m_datacomb);
	       }	     
	  }
     }

   gApplication->Terminate();
}

// v1/v0
double errf(double v1,double ve1,double v0,double ve0)
{
   if( v0 == 0 ) return pow(10.,-10);
   
   double err = sqrt(pow(v0-v1,2)*ve1*ve1+v1*v1*(ve0*ve0-ve1*ve1))/v0/v0;
   
   return err;
}

int getPeriod(int runNumber)
{
   int runPeriod = 0;
   if( runNumber >= 200804 && runNumber <= 201556 ) runPeriod = 1; // A
   if( runNumber >= 202660 && runNumber <= 202798 ) runPeriod = 2; // B1
   if( runNumber >= 202965 && runNumber <= 203027 ) runPeriod = 3; // B2
   if( runNumber >= 203169 && runNumber <= 203195 ) runPeriod = 4; // B3
   if( runNumber >= 203228 && runNumber <= 203524 ) runPeriod = 5; // B4
   if( runNumber >= 203602 && runNumber <= 203680 ) runPeriod = 6; // B5
   if( runNumber >= 203719 && runNumber <= 203792 ) runPeriod = 7; // B6
   if( runNumber >= 203875 && runNumber <= 203876 ) runPeriod = 8; // B7
   if( runNumber >= 203934 && runNumber <= 204073 ) runPeriod = 9; // B8
   if( runNumber >= 204134 && runNumber <= 204158 ) runPeriod = 10; // B9
   if( runNumber >= 204240 && runNumber <= 204442 ) runPeriod = 11; // B10
   if( runNumber >= 204474 && runNumber <= 204668 ) runPeriod = 12; // B11
   return runPeriod;
}
