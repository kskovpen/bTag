void makeFitPlotSYS()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   std::string sel = "sel3";
   
   const int nf = 3;
   std::string fv[nf] = {"nbins16","nbins25","nbins36"};
   const int nf2 = 3;
   std::string fv2[nf2] = {"vPTsv0p","vBTsv0p","vPTsv0pVSvBTsv0p"};

   double sf[100][100];
   double sferr[100][100];
   double sfX[100];
   double sfXerr[100];
   
   for(int i=0;i<100;i++)
     {
	sfX[i] = 0.;
	sfXerr[i] = 0.;
	  
	for(int j=0;j<100;j++)
	  {
	     sf[i][j] = 0.;
	     sferr[i][j] = 0.;
	  }
     }   	
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   TPad *c1_1;
   c1->Range(0,0,1,1);
   c1_1 = new TPad("c1_1","main",0.01,0.30,0.99,0.99);
   c1_1->Draw();
   c1_1->cd();
   
   gStyle->SetHistTopMargin(0);

   TLegend *leg = new TLegend(0.70,0.90,0.90,0.55);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);

   int nbins = 0;
   int im = 0;

   TH1F *hc;
   
   for(int f2=0;f2<nf2;f2++)
     {
	for(int f=0;f<nf;f++)
	  {
	     std::string fname = "results/sys/fit_EFF_"+fv[f]+"_"+fv2[f2]+"_"+sel+".root";
	     TFile *file = new TFile(fname.c_str());
	     TH1F *h = (TH1F*)file->Get("h1c");
	     if( f2 == nf2-1 ) hc = (TH1F*)h->Clone("hc");

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
	     
	     if( f == 0 ) {h->SetMarkerStyle(20);}
	     if( f == 1 ) {h->SetMarkerStyle(21);}
	     if( f == 2 ) {h->SetMarkerStyle(22);}

	     if( f2 == 0 ) {h->SetMarkerColor(kRed);h->SetLineColor(kRed);}
	     if( f2 == 1 ) {h->SetMarkerColor(kBlack);h->SetLineColor(kBlack);}
	     if( f2 == 2 ) {h->SetMarkerColor(kBlue);h->SetLineColor(kBlue);}
	     
	     if( f2 == 0 )
	       h->Draw("e1");
	     else
	       h->Draw("e1 same");

	     std::string tit = "";
	     if( fv2[f2] == "vPTsv0p" ) tit += "#Pi^{T}, ";
	     if( fv2[f2] == "vBTsv0p" ) tit += "B^{T}, ";
	     if( fv2[f2] == "vPTsv0pVSvBTsv0p" ) tit += "#Pi^{T} vs B^{T}, ";
	     if( fv[f] == "nbins16" ) tit += "N_{b}=16";
	     if( fv[f] == "nbins25" ) tit += "N_{b}=25";
	     if( fv[f] == "nbins36" ) tit += "N_{b}=36";
	     if( fv[f] == "nbins64" ) tit += "N_{b}=64";
	     if( fv[f] == "nbins100" ) tit += "N_{b}=100";
	     
	     leg->AddEntry(h,tit.c_str(),"lep");
	     
	     im++;
	  }
     }   

   double sfmean[100];
   double sfmax[100];
   double sfmin[100];
   double sfsig[100];
   double v1[100];
   double v2[100];

   for(int i=0;i<100;i++)
     {
	sfmean[i] = 0.;
	sfmax[i] = -10e+10;
	sfmin[i] = 10e+10;
	sfsig[i] = 0.;
	v1[i] = 0.;
	v2[i] = 0.;
     }
   
   for(int is=0;is<nbins;is++)
     {
	for(int is2=0;is2<im;is2++)
	  {	     
	     if(sferr[is][is2] == 0) continue;
	     
	     sfmean[is] += sf[is][is2]/pow(sferr[is][is2],2);
	     if( sf[is][is2] > sfmax[is] ) sfmax[is] = sf[is][is2];
	     if( sf[is][is2] < sfmin[is] ) sfmin[is] = sf[is][is2];
	     v1[is] += 1./pow(sferr[is][is2],2);
	  }	
     }   
   
   for(int is=0;is<nbins;is++)
     {
	if( v1[is] != 0 )
	  {	     
	     sfmean[is] = sfmean[is]/v1[is];
	     sfsig[is] = sqrt(sfsig[is]/v1[is]/(nf+nf2));
	  }
	
	sfmax[is] = sfmax[is] - sfmean[is];
	sfmin[is] = sfmean[is] - sfmin[is];
     }   

   for(int is=0;is<nbins;is++)
     {
	for(int is2=0;is2<im;is2++)
	  {	     
	     if(sferr[is][is2] == 0) continue;
	     
	     sfsig[is] += pow(sfmean[is]-sf[is][is2],2)/pow(sferr[is][is2],2);
	  }	
     }   

   for(int is=0;is<nbins;is++)
     {
	if( v1[is] != 0 )
	  {	     
	     sfsig[is] = sqrt(sfsig[is]/v1[is]/(nf+nf2));
	     std::cout << sfmean[is] << " - "<< sfmin[is] << " + "<< sfmax[is] << std::endl;
	  }	
     }   

   leg->Draw();
   
   c1->cd();
   TPad *c1_2 = new TPad("c1_2", "ratio",0.01,0.01,0.99,0.37);
   c1_2->Draw();
   c1_2->cd();  
   c1_2->SetBottomMargin(0.37);
   c1_2->SetGrid(0,1);

   hc->Reset();
   hc->Draw("e1");
   
   hc->GetYaxis()->SetNdivisions(5);
   hc->GetYaxis()->SetTitle("Mean scale factor");
   
   hc->GetYaxis()->SetTitleSize((hc->GetYaxis()->GetTitleSize())*2);
   hc->GetYaxis()->SetTitleOffset(hc->GetYaxis()->GetTitleOffset()/2);
   hc->GetXaxis()->SetTitleSize((hc->GetXaxis()->GetTitleSize())*2);
   hc->GetXaxis()->SetTitleOffset(hc->GetXaxis()->GetTitleOffset()+0.2);

   hc->GetYaxis()->SetLabelSize((hc->GetYaxis()->GetLabelSize())*2);
   hc->GetXaxis()->SetLabelSize((hc->GetXaxis()->GetLabelSize())*2);

   hc->GetXaxis()->SetTitle(hc->GetXaxis()->GetTitle());

   hc->GetYaxis()->SetRangeUser(0.,2.0);

   hc->SetLineColor(kBlack);
   hc->SetMarkerColor(kBlack);

//   TGraphAsymmErrors* error =
//     new TGraphAsymmErrors(nbins, sfX, sfmean, sfXerr, sfXerr, sfsig, sfsig);
   TGraphAsymmErrors* error =
     new TGraphAsymmErrors(nbins, sfX, sfmean, sfXerr, sfXerr, sfmin, sfmax);

   error->SetMarkerStyle(20);
   error->SetMarkerSize(0.6);
   error->SetMarkerColor(kBlack);
   error->SetLineColor(kBlack);
   error->SetLineWidth(2);
   error->SetFillColor(5);
   error->Draw("2SAME");
   error->Draw("P");

   error->RemovePoint(0);
   error->RemovePoint(0);
   error->RemovePoint(0);
   
   c1->Update();
   
   gPad->RedrawAxis("g");
   
   c1->Print("pics/fit_SYS.eps");
   
   gApplication->Terminate();
}
