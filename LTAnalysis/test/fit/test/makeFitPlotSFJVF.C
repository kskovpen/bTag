void makeFitPlotSFJVF()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   bool doSubPlot = 0;

   std::string sel = "MV160";
   std::string var = "Sd0t1";

   const int nf = 2;
   std::string fv[nf] = {"","_JVF0"};

   double sf[100][100];
   double sferr[100][100];
   double sfX[100];
   double sfXerr[100];
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   c1->Draw();
   c1->cd();

   TPad *c1_1;
   if( doSubPlot )
     {	
	c1->Range(0,0,1,1);
	c1_1 = new TPad("c1_1","main",0.01,0.30,0.99,0.99);
	c1_1->Draw();
	c1_1->cd();
     }   
   
   gStyle->SetHistTopMargin(0);

   TLegend *leg = new TLegend(0.70,0.90,0.90,0.70);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

   int nbins = 0;
   int im = 0;

   TH1F *hc;

   TH1F *hsf[nf];
   
   for(int f=0;f<nf;f++)
     {
	std::string fname = "results/sfoverlay/fit_EFF_beauty_"+var+"_"+sel+fv[f]+".root";
	TFile *file = new TFile(fname.c_str());
	TH1F *h = (TH1F*)file->Get("h1c");
	
	nbins = h->GetXaxis()->GetNbins();
	for(int ib=1;ib<nbins+1;ib++)
	  {
	     double cont = h->GetBinContent(ib);
	     double err = h->GetBinError(ib);
	     sfXerr[ib-1] = h->GetBinWidth(ib)/2.0;
	     sfX[ib-1] = h->GetBinLowEdge(ib) + sfXerr[ib-1];
	     sf[ib-1][im] = cont;
	     sferr[ib-1][im] = err;
	  }	     
	
	if( f == 0 ) {h->SetMarkerStyle(20);h->SetMarkerColor(kRed);h->SetLineColor(kRed);}
	if( f == 1 ) {h->SetMarkerStyle(25);h->SetMarkerColor(kBlack);h->SetLineColor(kBlack);}
	if( f == 2 ) {h->SetMarkerStyle(22);h->SetMarkerColor(kBlue);h->SetLineColor(kBlue);}
	if( f == 3 ) {h->SetMarkerStyle(23);h->SetMarkerColor(kMagenta);h->SetLineColor(kMagenta);}
	
	std::string tit = "";
	if( f == 0 ) tit = "JVF > 0.5";
	if( f == 1 ) tit = "JVF > 0";
	if( f == 2 ) tit = "S_{d_{0}}(t_{3})";
	if( f == 3 ) tit = "S_{d_{0}}(#mu)";
	leg->AddEntry(h,tit.c_str(),"lep");

	if( f == 0 ) h->Draw("e1");
	else h->Draw("e1 same");

	ATLASLabel(0.20,0.85,"Internal",1);
	
	h->GetYaxis()->SetRangeUser(0.3,1.6);
	h->GetXaxis()->SetRangeUser(0.0,0.04);
	
	im++;
	
	std::string hname = "hsf"+std::string(Form("%d",f));
	hsf[f] = (TH1F*)h->Clone(hname.c_str());
     }   

   leg->Draw();
   
   gPad->RedrawAxis("g");
      
/*   if( doSubPlot )
     {
	std::string foutStr = "results/fit_EFF_beauty_SFOVERLAY_"+sel+".root";
	TFile *fout = new TFile(foutStr.c_str(),"RECREATE");
	
	int inb = hsf[0]->GetXaxis()->GetNbins();
	const int nb = inb;
	double av[nb];
	double errSum[nb];
	double absv[nb];
	
	for(int ib=1;ib<=nb;ib++)
	  {
	     av[ib-1] = 0.;
	     absv[ib-1] = 0.;
	     errSum[ib-1] = 0.;
	  }	
	
	for(int ih=0;ih<nf;ih++)
	  {
	     for(int ib=1;ib<=nb;ib++)
	       {		  
		  double err = hsf[ih]->GetBinError(ib);
//		  av[ib-1] += (err > 0) ? hsf[ih]->GetBinContent(ib)/pow(err,2) : 0.;
		  av[ib-1] += hsf[ih]->GetBinContent(ib)/float(nf);
		  errSum[ib-1] += (err > 0) ? 1./pow(err,2) : 0.;
	       }	     
	  }	

	for(int ih=0;ih<nf;ih++)
	  {
	     for(int ib=1;ib<=nb;ib++)
	       {	
		  double err = hsf[ih]->GetBinError(ib);
		  absv[ib-1] += pow(err,2);
	       }	     
	  }	
	
	for(int ib=1;ib<=nb;ib++)
	  {
//	     av[ib-1] /= errSum[ib-1];
	  }	

	for(int ib=1;ib<=nb;ib++)
	  {		  
	     absv[ib-1] = sqrt(absv[ib-1])/float(nf);
//	     absv[ib-1] = 1./sqrt(errSum[ib-1]);
	     std::cout << av[ib-1] << " +- " << absv[ib-1] << std::endl;
	  }	     
	
	c1->cd();
	TPad *c1_2 = new TPad("c1_2", "ratio",0.01,0.01,0.99,0.37);
	c1_2->Draw();
	c1_2->cd();  
	c1_2->SetBottomMargin(0.37);
	c1_2->SetGrid(0,1);

	TH1F *h1c = (TH1F*)hsf[0]->Clone("h1c");
	
	for(int ib=1;ib<=nb;ib++)
	  {	
	     h1c->SetBinContent(ib,av[ib-1]);
	     h1c->SetBinError(ib,absv[ib-1]);
	  }	     	
	
	h1c->SetMarkerStyle(20);
	h1c->SetMarkerSize(0.8);
	h1c->GetYaxis()->SetNdivisions(5);
	h1c->GetYaxis()->SetTitle("Data/MC");
	
	h1c->GetYaxis()->SetTitleSize((h1c->GetYaxis()->GetTitleSize())*2);
	h1c->GetYaxis()->SetTitleOffset(h1c->GetYaxis()->GetTitleOffset()/2);
	h1c->GetXaxis()->SetTitleSize((h1c->GetXaxis()->GetTitleSize())*2);
	h1c->GetXaxis()->SetTitleOffset(h1c->GetXaxis()->GetTitleOffset()+0.2);
	
	h1c->GetYaxis()->SetLabelSize((h1c->GetYaxis()->GetLabelSize())*2);
	h1c->GetXaxis()->SetLabelSize((h1c->GetXaxis()->GetLabelSize())*2);
	
	h1c->GetXaxis()->SetTitle(h1c->GetXaxis()->GetTitle());
	
	h1c->SetLineColor(kBlack);
	h1c->SetMarkerColor(kBlack);
	
	h1c->Draw("e1");
	
	h1c->GetYaxis()->SetRangeUser(0.5,1.5);
	
	c1->Update();

	for(int ih=0;ih<nf;ih++)
	  {	     
	     hsf[ih]->Write();
	  }	
	
	fout->Write();
	fout->Close();
     }*/

   std::string fsave = "pics/fit_SFJVF_"+sel+".eps";
   c1->Print(fsave.c_str());
   
   gApplication->Terminate();
}
