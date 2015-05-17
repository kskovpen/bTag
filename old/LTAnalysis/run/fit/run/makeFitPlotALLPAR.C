void makeFitPlotALLPAR(std::string ptb1Str,
		       std::string ptb2Str,
		       std::string p1Str,
		       std::string p2Str,
		       std::string p3Str,
		       std::string p1errStr,
		       std::string p2errStr,
		       std::string p3errStr)
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x common.C");
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   double ptb1[100];
   double ptb2[100];
   
   double p1[100];
   double p2[100];
   double p3[100];
   double p1err[100];
   double p2err[100];
   double p3err[100];
   
   std::stringstream ptb1Stream(ptb1Str);
   std::stringstream ptb2Stream(ptb2Str);
   
   std::stringstream p1Stream(p1Str);
   std::stringstream p2Stream(p2Str);
   std::stringstream p3Stream(p3Str);
   std::stringstream p1errStream(p1errStr);
   std::stringstream p2errStream(p2errStr);
   std::stringstream p3errStream(p3errStr);
   
   std::string val;
   
   int i = 0;
   while( getline(p1Stream, val, ',') )
     {	
	p1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p2Stream, val, ',') )
     {	
	p2[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p3Stream, val, ',') )
     {	
	p3[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(p1errStream, val, ',') )
     {	
	p1err[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p2errStream, val, ',') )
     {	
	p2err[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(p3errStream, val, ',') )
     {	
	p3err[i] = atof(val.c_str());
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
	xbins[j] = ptb1[j]/1000.;
     }   
   xbins[ibn] = ptb2[ibn-1]/1000.;
   
   TH1F *h_p1 = new TH1F("h_p1","h_p1",ibn,xbins);
   TH1F *h_p2 = new TH1F("h_p2","h_p2",ibn,xbins);
   TH1F *h_p3 = new TH1F("h_p3","h_p3",ibn,xbins);
   
   for(int j=0;j<ibn;j++)
     {
	if( ! (p1[j] == p2[j]) )
	  {	     
	     h_p1->SetBinContent(j+1,p1[j]);
	     h_p1->SetBinError(j+1,p1err[j]);
	     h_p2->SetBinContent(j+1,p2[j]);
	     h_p2->SetBinError(j+1,p2err[j]);
	     h_p3->SetBinContent(j+1,p3[j]);
	     h_p3->SetBinError(j+1,p3err[j]);
	  }	
     }   

   h_p1->SetLineColor(46);
   h_p2->SetLineColor(38);
   h_p3->SetLineColor(30);

   h_p1->SetMarkerColor(46);
   h_p2->SetMarkerColor(38);
   h_p3->SetMarkerColor(30);

   h_p1->SetMarkerStyle(20);
   h_p2->SetMarkerStyle(21);
   h_p3->SetMarkerStyle(22);
   
   h_p1->Draw("e1");
   h_p2->Draw("e1 same");
   h_p3->Draw("e1 same");
   
   h_p1->GetYaxis()->SetRangeUser(0.,3.);
   
   h_p1->GetXaxis()->SetTitle("P_{T} [TeV]");
   h_p1->GetYaxis()->SetTitle("Fit scale factor");

   TLegend *leg = new TLegend(0.75,0.90,0.90,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   leg->AddEntry(h_p1,"Beauty","lep");
   leg->AddEntry(h_p2,"Charm","lep");
   leg->AddEntry(h_p3,"Light","lep");
   
   leg->Draw();
   
   std::string fsave = "pics/fit_ALLPAR.eps";
   c1->Print(fsave.c_str());
   c1->Clear();
   
   gApplication->Terminate();
}
