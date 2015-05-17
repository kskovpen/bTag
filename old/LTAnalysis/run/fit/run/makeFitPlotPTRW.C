void makeFitPlotPTRW()
{   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   c1->Draw();
   c1->cd();
   
   gStyle->SetHistTopMargin(0);

   TLegend *leg = new TLegend(0.70,0.90,0.90,0.55);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   int Nbins = 153;
/*
   std::string tname = "results/table_ptrw.tex";
   std::string tname_inc = "results/table_ptrw_inc.tex";
   
   std::ofstream ft(tname.c_str());
   std::ofstream fti(tname_inc.c_str());
   
   std::string header1 = "\\documentclass[a4paper]{article} \n
\\usepackage[english]{babel} \n
\\usepackage{graphicx} \n
\\begin{document}";
   
   std::string header2 = "
\\begin{table}[hbt!] \n
\\small \n
\\begin{center} \n
\\resizebox{16cm}{!}{ \n
\\begin{tabular}{|c|c|c|c|c|c|c|c|} \n
\\hline";
				
   ft << header1 << std::endl;
   ft << header2 << std::endl;
   
   fti << header2 << std::endl;
  */ 
   std::ifstream f("results/ptrw_merged.txt");

   int nb[10000];
   double x1[10000];
   double x2[10000];
   double sf[10000];
   double sferr[10000];

   int i = 0;
   while( ! f.eof() )
     {
	f >> nb[i] >> x1[i] >> x2[i] >> sf[i] >> sferr[i];
	if( ! (sf[i] == 1 && sferr[i] == 0) )
	  i++;
     }   

   f.close();

   std::ofstream fout("results/jtplotPtRW.txt");
   
   TH1F *h_sf = new TH1F("h_sf","h_sf",Nbins,xbins);
   for(int j=0;j<i;j++)
     {
	h_sf->SetBinContent(nb[j]+1,sf[j]);
	h_sf->SetBinError(nb[j]+1,sferr[j]);
	fout << nb[j] << " " << x1[j] << " " << x2[j] << " " << sf[j] << " " << sferr[j] << std::endl;
     }      

   fout.close();      
   
   h_sf->Draw("e1");
   h_sf->SetMaximum(3.0);
   h_sf->SetMarkerSize(0.5);
   h_sf->GetXaxis()->SetRange(0,Nbins-7);
   h_sf->GetXaxis()->SetTitle("P_{T} [TeV]");
   h_sf->GetYaxis()->SetTitle("Data/MC");
   
   const int nxl = 25;
//   double xl[nxl] = {0.020,0.030,0.040,0.050,0.060,0.075,0.090,0.110,0.140,0.200,0.260,0.340,0.500};
   double xl[nxl] = {0.020,0.030,0.040,0.050,0.060,0.075,0.090,
	0.110,0.140,0.200,0.260,0.300,0.340,0.400,0.450,0.500,
	0.550,0.600,0.700,0.850,1.000,1.250,1.500,1.750,2.000};
   for(int i=0;i<nxl;i++)
     {	
	TLine *lpt = new TLine(xl[i],0,xl[i],3.0);
	lpt->SetLineStyle(2);
	lpt->SetLineWidth(2);
	lpt->SetLineColor(kBlue-9);
	lpt->Draw("same");
     }   

   h_sf->GetXaxis()->SetRangeUser(0.02,0.5);
   c1->SetLogx(1);
   c1->Print("pics/fit_PTRW.eps");
   
   gApplication->Terminate();
}
