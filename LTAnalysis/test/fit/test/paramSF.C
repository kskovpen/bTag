void paramSF()
{
   gROOT->SetBatch(1);

   std::string ver = "CSV";
   std::string tag = "LOOSE";
   const int nrun = 6;
   int run[nrun] = {1,3,8,2,7,9};
   
   TH1D *h_param = new TH1D("h_param","h_param",6,0.,6.);

   h_param->GetXaxis()->SetBinLabel(1,"10");
   h_param->GetXaxis()->SetBinLabel(2,"20");
   h_param->GetXaxis()->SetBinLabel(3,"25");
   h_param->GetXaxis()->SetBinLabel(4,"30");
   h_param->GetXaxis()->SetBinLabel(5,"50");
   h_param->GetXaxis()->SetBinLabel(6,"75");
   
   TH1D *h_param_max = (TH1D*)h_param->Clone("h_param_max");
   
   for(int i=0;i<nrun;i++)
     {	
	std::string sf = "results/SF_"+tag+"_2011FINAL"+ver+"_"+std::string(Form("%d",run[i]))+"_beauty.root";
	TFile *f = TFile::Open(sf.c_str());
	TH1F *hSF = (TH1F*)f->Get("hSF");
	int nbins = hSF->GetXaxis()->GetNbins();
	
	double diff = 0.;
	double diffMax = 0.;
	
	for(int ib=1;ib<=nbins;ib++)
	  {
	     double v1 = hSF->GetBinContent(ib);
	     double v2 = v1;
	     if( ib < nbins ) v2 = hSF->GetBinContent(ib+1);
	     diff += fabs(v2-v1);
	     if( fabs(v2-v1) > diffMax ) diffMax = fabs(v2-v1);
	  }
	
	h_param->SetBinContent(i+1,diff);
	h_param_max->SetBinContent(i+1,diffMax);
     }   

   h_param->SetMinimum(0.);
   h_param_max->SetMinimum(0.);
   
   TCanvas *c1 = new TCanvas();
   
   h_param->Draw("hist");
   c1->Print("pics/param.eps");
   c1->Clear();

   h_param_max->Draw("hist");
   c1->Print("pics/param_max.eps");
   c1->Clear();
   
   gApplication->Terminate();
}
