void makeFitPlotFIT12(std::string ptb1Str,
		      std::string ptb2Str,
		      std::string p1Strf1,
		      std::string p2Strf1,
		      std::string p3Strf1,
		      std::string p1errStrf1,
		      std::string p2errStrf1,
		      std::string p3errStrf1,
		      std::string p1Strf2,
		      std::string p2Strf2,
		      std::string p3Strf2,
		      std::string p1errStrf2,
		      std::string p2errStrf2,
		      std::string p3errStrf2,
		      std::string fit1tit,
		      std::string fit2tit
		      )
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x common.C");
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   double ptb1[100];
   double ptb2[100];
   
   double p1f1[100];
   double p2f1[100];
   double p3f1[100];
   double p1errf1[100];
   double p2errf1[100];
   double p3errf1[100];

   double p1f2[100];
   double p2f2[100];
   double p3f2[100];
   double p1errf2[100];
   double p2errf2[100];
   double p3errf2[100];
   
   std::stringstream ptb1Stream(ptb1Str);
   std::stringstream ptb2Stream(ptb2Str);
   
   std::stringstream p1Streamf1(p1Strf1);
   std::stringstream p2Streamf1(p2Strf1);
   std::stringstream p3Streamf1(p3Strf1);
   std::stringstream p1errStreamf1(p1errStrf1);
   std::stringstream p2errStreamf1(p2errStrf1);
   std::stringstream p3errStreamf1(p3errStrf1);

   std::stringstream p1Streamf2(p1Strf2);
   std::stringstream p2Streamf2(p2Strf2);
   std::stringstream p3Streamf2(p3Strf2);
   std::stringstream p1errStreamf2(p1errStrf2);
   std::stringstream p2errStreamf2(p2errStrf2);
   std::stringstream p3errStreamf2(p3errStrf2);
   
   std::string val;

   // FIT1
   int i = 0;
   while( getline(p1Streamf1, val, ',') )
     {	
	p1f1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p2Streamf1, val, ',') )
     {	
	p2f1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p3Streamf1, val, ',') )
     {	
	p3f1[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(p1errStreamf1, val, ',') )
     {	
	p1errf1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p2errStreamf1, val, ',') )
     {	
	p2errf1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p3errStreamf1, val, ',') )
     {	
	p3errf1[i] = atof(val.c_str());
	i++;
     }   

   // FIT2
   i = 0;
   while( getline(p1Streamf2, val, ',') )
     {	
	p1f2[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p2Streamf2, val, ',') )
     {	
	p2f2[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p3Streamf2, val, ',') )
     {	
	p3f2[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(p1errStreamf2, val, ',') )
     {	
	p1errf2[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p2errStreamf2, val, ',') )
     {	
	p2errf2[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p3errStreamf2, val, ',') )
     {	
	p3errf2[i] = atof(val.c_str());
	i++;
     }   
   
   i = 0;
   while( getline(ptb1Stream, val, ',') )
     {	
	ptb1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(ptb2Stream, val, ',') )
     {	
	ptb2[i] = atof(val.c_str());
	i++;
     }        
   int ibn = i;

   double xbins[100];
   int ib = 0;
   
   for(int j=0;j<ibn;j++)
     {
	xbins[j] = ptb1[j];
     }   
   xbins[ibn] = ptb2[ibn-1];
   
   TH1F *h_p1f1 = new TH1F("h_p1f1","h_p1f1",ibn,xbins);
   TH1F *h_p2f1 = new TH1F("h_p2f1","h_p2f1",ibn,xbins);
   TH1F *h_p3f1 = new TH1F("h_p3f1","h_p3f1",ibn,xbins);

   TH1F *h_p1f2 = new TH1F("h_p1f2","h_p1f2",ibn,xbins);
   TH1F *h_p2f2 = new TH1F("h_p2f2","h_p2f2",ibn,xbins);
   TH1F *h_p3f2 = new TH1F("h_p3f2","h_p3f2",ibn,xbins);
   
   for(int j=0;j<ibn;j++)
     {
	if( !(p1f1[j] == p1f2[j]) )
	  {	     
	     h_p1f1->SetBinContent(j+1,p1f1[j]);
	     h_p1f1->SetBinError(j+1,p1errf1[j]);
	     h_p1f2->SetBinContent(j+1,p1f2[j]);
	     h_p1f2->SetBinError(j+1,p1errf2[j]);
	  }	

	if( !(p2f1[j] == p2f2[j]) )
	  {	     	
	     h_p2f1->SetBinContent(j+1,p2f1[j]);
	     h_p2f1->SetBinError(j+1,p2errf1[j]);
	     h_p2f2->SetBinContent(j+1,p2f2[j]);
	     h_p2f2->SetBinError(j+1,p2errf2[j]);
	  }
	
	if( !(p3f1[j] == p3f2[j]) )
	  {	     	
	     h_p3f1->SetBinContent(j+1,p3f1[j]);
	     h_p3f1->SetBinError(j+1,p3errf1[j]);
	     h_p3f2->SetBinContent(j+1,p3f2[j]);
	     h_p3f2->SetBinError(j+1,p3errf2[j]);
	  }	
     }   

   h_p1f1->SetLineColor(46);
   h_p2f1->SetLineColor(38);
   h_p3f1->SetLineColor(30);
   h_p1f1->SetMarkerColor(46);
   h_p2f1->SetMarkerColor(38);
   h_p3f1->SetMarkerColor(30);
   h_p1f1->SetMarkerStyle(20);
   h_p2f1->SetMarkerStyle(21);
   h_p3f1->SetMarkerStyle(22);

   h_p1f2->SetLineColor(46);
   h_p2f2->SetLineColor(38);
   h_p3f2->SetLineColor(30);
   h_p1f2->SetMarkerColor(46);
   h_p2f2->SetMarkerColor(38);
   h_p3f2->SetMarkerColor(30);
   h_p1f2->SetMarkerStyle(24);
   h_p2f2->SetMarkerStyle(25);
   h_p3f2->SetMarkerStyle(26);
   
   h_p1f1->Draw("e1");
   h_p1f2->Draw("e1 same");
   
   h_p1f1->GetYaxis()->SetRangeUser(0.,3.);
   
   h_p1f1->GetXaxis()->SetTitle("P_{T} [TeV]");
   h_p1f1->GetYaxis()->SetTitle("Beauty fit scale factor");

   TLegend *leg = new TLegend(0.75,0.90,0.90,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   leg->AddEntry(h_p1f1,fit1tit.c_str(),"lep");
   leg->AddEntry(h_p1f2,fit2tit.c_str(),"lep");
   
   leg->Draw();
   
   std::string fsave = "pics/fit_FIT12_p1.eps";
   c1->Print(fsave.c_str());
   leg->Clear();
   c1->Clear();   

   h_p2f1->Draw("e1");
   h_p2f2->Draw("e1 same");
   
   h_p2f1->GetYaxis()->SetRangeUser(0.,3.);
   
   h_p2f1->GetXaxis()->SetTitle("P_{T} [TeV]");
   h_p2f1->GetYaxis()->SetTitle("Charm fit scale factor");

   TLegend *leg = new TLegend(0.75,0.90,0.90,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   leg->AddEntry(h_p2f1,fit1tit.c_str(),"lep");
   leg->AddEntry(h_p2f2,fit2tit.c_str(),"lep");
   
   leg->Draw();
   
   std::string fsave = "pics/fit_FIT12_p2.eps";
   c1->Print(fsave.c_str());
   leg->Clear();
   c1->Clear();   
   
   h_p3f1->Draw("e1");
   h_p3f2->Draw("e1 same");
   
   h_p3f1->GetYaxis()->SetRangeUser(0.,3.);
   
   h_p3f1->GetXaxis()->SetTitle("P_{T} [TeV]");
   h_p3f1->GetYaxis()->SetTitle("Light fit scale factor");

   TLegend *leg = new TLegend(0.75,0.90,0.90,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   leg->AddEntry(h_p3f1,fit1tit.c_str(),"lep");
   leg->AddEntry(h_p3f2,fit2tit.c_str(),"lep");
   
   leg->Draw();
   
   std::string fsave = "pics/fit_FIT12_p3.eps";
   c1->Print(fsave.c_str());
   leg->Clear();
   c1->Clear();   
   
   gApplication->Terminate();
}
