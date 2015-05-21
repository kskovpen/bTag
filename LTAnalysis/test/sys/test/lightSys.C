void lightSys()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");
   
   gROOT->ProcessLine(".L addbin.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   const int nf = 3;
   std::string fpathMC[nf] = 
     {
	"../../histLOOSESYS/MC/data.root",
	"../../histMEDIUMSYS/MC/data.root",
	"../../histTIGHTSYS/MC/data.root"
     };
   
   TFile *fMC[nf];
   for(int i=0;i<nf;i++)
     {	
	fMC[i] = TFile::Open(fpathMC[i].c_str());
     }   

   TLegend *leg = new TLegend(0.65,0.90,0.85,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   const int npt = 17;
   std::string ptname[npt] = {
      "pt20t30",
      "pt30t40",
      "pt40t50",
      "pt50t60",
      "pt60t70",
      "pt70t80",
      "pt80t100",
      "pt100t120",
      "pt120t160",
      "pt160t210",
      "pt210t260",
      "pt260t320",
      "pt320t400",
      "pt400t500",
      "pt500t600",
      "pt600t800",
      "pt800t1000"
   };
//   std::string btagname = "combSvx0p244";
//   std::string btagname = "combSvx0p679";
//   std::string btagname = "combSvx0p898";
// std::string btagname = "UNTAGbc";
   std::string btagname = "nosel";
   
   TH1D *h_JP[nf][npt];
   TH1D *h_JP_sys_up[nf][npt];
   TH1D *h_JP_sys_low[nf][npt];
      
   for(int ipt=0;ipt<npt;ipt++)
     {
	TH1D *h_sys[nf];
	
	for(int i=0;i<nf;i++)
	  {	     
	     std::string hname_JP = "h_j1_JP_ljet_"+ptname[ipt]+"_nosel_"+btagname;
	     h_JP[i][ipt] = (TH1D*)fMC[i]->Get(hname_JP.c_str());
	     std::string hname_JP_sys_up = hname_JP+"_val_up";
	     h_JP_sys_up[i][ipt] = (TH1D*)fMC[i]->Get(hname_JP_sys_up.c_str());
	     std::string hname_JP_sys_low = hname_JP+"_val_low";
	     h_JP_sys_low[i][ipt] = (TH1D*)fMC[i]->Get(hname_JP_sys_low.c_str());

	     double int_JP = h_JP[i][ipt]->Integral();
	
	     if( int_JP > 0. ) 
	       {
		  h_JP[i][ipt]->Scale(1./int_JP);
		  h_JP_sys_up[i][ipt]->Scale(1./int_JP);
		  h_JP_sys_low[i][ipt]->Scale(1./int_JP);
	       }
	     
	     std::string hname = "h_sys_"+std::string(Form("%d",i));
	     h_sys[i] = (TH1D*)h_JP[i][ipt]->Clone(hname.c_str());
	     
	     int nbins = h_JP[i][ipt]->GetXaxis()->GetNbins();
	     for(int ib=0;ib<=nbins+1;ib++)
	       {
		  double v0 = h_JP[i][ipt]->GetBinContent(ib);
		  double v0err = h_JP[i][ipt]->GetBinError(ib);
		  double vUp = h_JP_sys_up[i][ipt]->GetBinContent(ib);
		  double vLow = h_JP_sys_low[i][ipt]->GetBinContent(ib);
		  double vnew = 1.;
		  if( v0 > 0. && v0err > 0. )
		    {
		       if( fabs(v0/v0err) > 5. )
			 vnew = 1.+(vUp-v0)/v0;		       
		    }		  
		  h_sys[i]->SetBinContent(ib,vnew);
	       }	     
	  }
	
	// draw
	h_sys[0]->Draw("hist");
	h_sys[0]->SetMarkerColor(kBlack);
	h_sys[0]->SetMarkerSize(0.7);
	h_sys[0]->SetLineColor(kBlack);
	h_sys[0]->SetLineStyle(1);

	h_sys[1]->Draw("hist same");
	h_sys[1]->SetMarkerColor(kRed);
	h_sys[1]->SetMarkerSize(0.7);
	h_sys[1]->SetLineColor(kRed);
	h_sys[1]->SetLineStyle(2);
	
	h_sys[2]->Draw("hist same");
	h_sys[2]->SetMarkerColor(kBlue);
	h_sys[2]->SetMarkerSize(0.7);
	h_sys[2]->SetLineColor(kBlue);
	h_sys[2]->SetLineStyle(3);

	leg->AddEntry(h_sys[0],"CSVL","l");
	leg->AddEntry(h_sys[1],"CSVM","l");
	leg->AddEntry(h_sys[2],"CSVT","l");
	h_sys[0]->GetXaxis()->SetTitle("Jet probability");
	h_sys[0]->GetYaxis()->SetRangeUser(0.,2.0);
	
	std::string fsave = "pics/syscomp_ljet_data_"+ptname[ipt]+".eps";
	c1->Print(fsave.c_str());
	c1->Clear();
	leg->Clear();
     }   
   
   gApplication->Terminate();
}
