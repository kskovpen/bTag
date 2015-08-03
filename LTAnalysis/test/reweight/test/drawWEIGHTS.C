void drawWEIGHTS()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x common.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);

   TFile *fcor = TFile::Open("../../sys/run/results/corrections.root");

   const int nrw = 1;
   std::string rw[nrw] = {"nseltrk"};
   const int npt = 18;
   std::string pt[npt] = {
      "pt20t30","pt30t40","pt40t50","pt50t60","pt60t70","pt70t80","pt80t100",
      "pt100t120","pt120t160","pt160t210","pt210t260","pt260t320","pt320t400",
      "pt400t500","pt500t600","pt600t800","pt800t1000","pt1000t1400"
   };
   const int nbtag = 4;
   std::string btag[nbtag] = {"nosel","combSvx0p244","combSvx0p679","combSvx0p898"};     
   
   for(int ipt=0;ipt<npt;ipt++)
     {
	for(int irw=0;irw<nrw;irw++)
	  {
	     TH1D *hw[nbtag];

	     double max = 1.;

	     TLegend *leg;
	     leg = new TLegend(0.65,0.90,0.90,0.60);
	     leg->SetFillColor(253);
	     leg->SetBorderSize(0);

	     std::string xtit = "";
	     if( strcmp(rw[irw].c_str(),"nseltrk") == 0 ) xtit = "Number of tracks";
	     else if( strcmp(rw[irw].c_str(),"ntrk") == 0 ) xtit = "Number of tracks";
	     else if( strcmp(rw[irw].c_str(),"njet") == 0 ) xtit = "Number of jets";
	     else if( strcmp(rw[irw].c_str(),"mupt") == 0 ) xtit = "P_{T} (#mu) [GeV]";
	     else if( strcmp(rw[irw].c_str(),"jeta") == 0 ) xtit = "#eta (jet)";
	     
	     for(int ibtag=0;ibtag<nbtag;ibtag++)
	       {		  
		  std::string hname = "sf_"+pt[ipt]+"_"+btag[ibtag]+"_1d_"+rw[irw];
		  hw[ibtag] = (TH1D*)fcor->Get(hname.c_str());

		  int nb = hw[ibtag]->GetXaxis()->GetNbins();
		  for(int ib=1;ib<=nb;ib++)
		    {
		       if( hw[ibtag]->GetBinError(ib) == 0 )
			 {			    
			    hw[ibtag]->SetBinContent(ib,-666);
			 }		       
		    }		 
		  
		  if( hw[ibtag]->GetMaximum() > max ) max = hw[ibtag]->GetMaximum();
		  
		  std::string bt = "";
		  if( strcmp(btag[ibtag].c_str(),"nosel") == 0 ) bt = "No CSV";
		  if( strcmp(btag[ibtag].c_str(),"combSvx0p244") == 0 ) bt = "CSVL";
		  if( strcmp(btag[ibtag].c_str(),"combSvx0p679") == 0 ) bt = "CSVM";
		  if( strcmp(btag[ibtag].c_str(),"combSvx0p898") == 0 ) bt = "CSVT";
		  
		  if( ibtag == 0 )
		    {
		       hw[ibtag]->SetMarkerStyle(20);
		       hw[ibtag]->SetMarkerColor(kBlack);
		       hw[ibtag]->SetMarkerSize(0.8);
		       hw[ibtag]->SetLineColor(kBlack);
		       leg->AddEntry(hw[ibtag],bt.c_str(),"lp");
		    }		  
		  if( ibtag == 1 )
		    {
		       hw[ibtag]->SetMarkerStyle(21);
		       hw[ibtag]->SetMarkerColor(kRed);
		       hw[ibtag]->SetMarkerSize(0.8);
		       hw[ibtag]->SetLineColor(kRed);
		       leg->AddEntry(hw[ibtag],bt.c_str(),"lp");
		    }		  
		  if( ibtag == 2 )
		    {
		       hw[ibtag]->SetMarkerStyle(22);
		       hw[ibtag]->SetMarkerColor(kBlue);
		       hw[ibtag]->SetMarkerSize(0.8);
		       hw[ibtag]->SetLineColor(kBlue);
		       leg->AddEntry(hw[ibtag],bt.c_str(),"lp");
		    }		  
		  if( ibtag == 3 )
		    {
		       hw[ibtag]->SetMarkerStyle(23);
		       hw[ibtag]->SetMarkerColor(kMagenta);
		       hw[ibtag]->SetMarkerSize(0.8);
		       hw[ibtag]->SetLineColor(kMagenta);
		       leg->AddEntry(hw[ibtag],bt.c_str(),"lp");
		    }		  
		  
		  if( ibtag == 0 ) hw[ibtag]->Draw("e1p");
		  else hw[ibtag]->Draw("e1p same");		  		  
	       }	     
	     
	     hw[0]->GetYaxis()->SetRangeUser(0.0,max*1.3);
	     hw[0]->GetXaxis()->SetTitle(xtit.c_str());
	     hw[0]->GetYaxis()->SetTitle("Data/MC");
	     
	     if( strcmp(rw[irw].c_str(),"nseltrk") == 0 ||
		 strcmp(rw[irw].c_str(),"ntrk") == 0 )
	       {		  
		  if( ipt == 0 ) hw[0]->GetXaxis()->SetRangeUser(0,12);
		  if( ipt == 1 ) hw[0]->GetXaxis()->SetRangeUser(0,13);
		  if( ipt == 2 ) hw[0]->GetXaxis()->SetRangeUser(0,14);
		  if( ipt == 3 ) hw[0]->GetXaxis()->SetRangeUser(0,15);
		  if( ipt == 4 ) hw[0]->GetXaxis()->SetRangeUser(0,16);
		  if( ipt == 5 ) hw[0]->GetXaxis()->SetRangeUser(0,18);
		  if( ipt == 6 ) hw[0]->GetXaxis()->SetRangeUser(0,20);
		  if( ipt == 7 ) hw[0]->GetXaxis()->SetRangeUser(0,23);
		  if( ipt == 8 ) hw[0]->GetXaxis()->SetRangeUser(0,25);
		  if( ipt == 9 ) hw[0]->GetXaxis()->SetRangeUser(0,30);
		  if( ipt == 10 ) hw[0]->GetXaxis()->SetRangeUser(0,30);
		  if( ipt == 11 ) hw[0]->GetXaxis()->SetRangeUser(0,32);
		  if( ipt == 12 ) hw[0]->GetXaxis()->SetRangeUser(0,35);
		  if( ipt == 13 ) hw[0]->GetXaxis()->SetRangeUser(0,38);
		  if( ipt == 14 ) hw[0]->GetXaxis()->SetRangeUser(0,40);
		  if( ipt == 15 ) hw[0]->GetXaxis()->SetRangeUser(0,40);
		  if( ipt == 16 ) hw[0]->GetXaxis()->SetRangeUser(0,40);
		  if( ipt == 17 ) hw[0]->GetXaxis()->SetRangeUser(0,40);
	       }	     

	     std::string ptl = ptlabel(pt[ipt]);
	     
	     leg->Draw();
	     
	     std::string fname = "pics/sf_"+pt[ipt]+"_1d_"+rw[irw]+".eps";
	     c1->Print(fname.c_str());
	     leg->Clear();
	     c1->Clear();	     
	  }
     }   
   
/*   TLegend *leg;
   leg = new TLegend(0.35,0.50,0.65,0.20);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
  
   TLatex *legl = new TLatex();
   legl->SetNDC();
   legl->SetTextAlign(22);
   legl->SetTextFont(63);
   legl->SetTextSizePixels(30);
   legl->DrawLatex(0.55,0.85,csv.c_str());
*/
   gApplication->Terminate();
}

std::string ptlabel(std::string l)
{   
   std::string ptl = "P_{T}";
   
   if( strcmp(l.c_str(),"nosel") == 0 ) ptl+=" 20-1400 GeV";
   else if( strcmp(l.c_str(),"pt20t30") == 0 ) ptl+=" 20-30 GeV";
   else if( strcmp(l.c_str(),"pt30t40") == 0 ) ptl+=" 30-40 GeV";
   else if( strcmp(l.c_str(),"pt40t50") == 0 ) ptl+=" 40-50 GeV";
   else if( strcmp(l.c_str(),"pt50t60") == 0 ) ptl+=" 50-60 GeV";
   else if( strcmp(l.c_str(),"pt60t70") == 0 ) ptl+=" 60-70 GeV";
   else if( strcmp(l.c_str(),"pt70t80") == 0 ) ptl+=" 70-80 GeV";
   else if( strcmp(l.c_str(),"pt80t100") == 0 ) ptl+=" 80-100 GeV";
   else if( strcmp(l.c_str(),"pt100t120") == 0 ) ptl+=" 100-120 GeV";
   else if( strcmp(l.c_str(),"pt120t160") == 0 ) ptl+=" 120-160 GeV";
   else if( strcmp(l.c_str(),"pt160t210") == 0 ) ptl+=" 160-210 GeV";
   else if( strcmp(l.c_str(),"pt210t260") == 0 ) ptl+=" 210-260 GeV";
   else if( strcmp(l.c_str(),"pt260t320") == 0 ) ptl+=" 260-320 GeV";
   else if( strcmp(l.c_str(),"pt320t400") == 0 ) ptl+=" 320-400 GeV";
   else if( strcmp(l.c_str(),"pt400t500") == 0 ) ptl+=" 400-500 GeV";
   else if( strcmp(l.c_str(),"pt500t600") == 0 ) ptl+=" 500-600 GeV";
   else if( strcmp(l.c_str(),"pt600t800") == 0 ) ptl+=" 600-800 GeV";
   else if( strcmp(l.c_str(),"pt800t1000") == 0 ) ptl+=" 800-1000 GeV";
   else if( strcmp(l.c_str(),"pt1000t1400") == 0 ) ptl+=" 1000-1400 GeV";
   
   else if( strcmp(l.c_str(),"pt30t50") == 0 ) ptl+=" 30-50 GeV";
   else if( strcmp(l.c_str(),"pt50t80") == 0 ) ptl+=" 50-80 GeV";
   else if( strcmp(l.c_str(),"pt80t120") == 0 ) ptl+=" 80-120 GeV";
   else if( strcmp(l.c_str(),"pt120t210") == 0 ) ptl+=" 120-210 GeV";
   else if( strcmp(l.c_str(),"pt210t320") == 0 ) ptl+=" 210-320 GeV";
   
   else
     {
	std::cout << "Pt bin is unknown to create a label" << std::endl;
	exit(1);
     }   
   
   return ptl;
}
