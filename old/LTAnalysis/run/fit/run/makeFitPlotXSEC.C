void makeFitPlotXSEC(
		     std::string ptb1Str,
		     std::string ptb2Str,
		     std::string nb1Str,
		     std::string nerrb1Str,
		     std::string nbj1Str,
		     std::string nerrbj1Str,
		     std::string ncj1Str,
		     std::string nerrcj1Str,
		     std::string nlj1Str,
		     std::string nerrlj1Str,
		     std::string p1Str,
		     std::string perr1Str,
		     std::string p2Str,
		     std::string perr2Str,
		     std::string p3Str,
		     std::string perr3Str
		     )
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   double il = lumi;
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   double ptb1[100];
   double ptb2[100];
   
   double nb1[100];
   double nerrb1[100];
   double nbj1[100];
   double nerrbj1[100];
   double ncj1[100];
   double nerrcj1[100];
   double nlj1[100];
   double nerrlj1[100];

   double p1[100];
   double perr1[100];
   double p2[100];
   double perr2[100];
   double p3[100];
   double perr3[100];
   
   std::stringstream ptb1Stream(ptb1Str);
   std::stringstream ptb2Stream(ptb2Str);
   
   std::stringstream nb1Stream(nb1Str);
   std::stringstream nerrb1Stream(nerrb1Str);
   std::stringstream nbj1Stream(nbj1Str);
   std::stringstream nerrbj1Stream(nerrbj1Str);
   std::stringstream ncj1Stream(ncj1Str);
   std::stringstream nerrcj1Stream(nerrcj1Str);
   std::stringstream nlj1Stream(nlj1Str);
   std::stringstream nerrlj1Stream(nerrlj1Str);

   std::stringstream p1Stream(p1Str);
   std::stringstream perr1Stream(perr1Str);
   std::stringstream p2Stream(p2Str);
   std::stringstream perr2Stream(perr2Str);
   std::stringstream p3Stream(p3Str);
   std::stringstream perr3Stream(perr3Str);
   
   std::string val;
   
   int i = 0;
   while( getline(nb1Stream, val, ',') )
     {	
	nb1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrb1Stream, val, ',') )
     {	
	nerrb1[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(nbj1Stream, val, ',') )
     {	
	nbj1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrbj1Stream, val, ',') )
     {	
	nerrbj1[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(ncj1Stream, val, ',') )
     {	
	ncj1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrcj1Stream, val, ',') )
     {	
	nerrcj1[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(nlj1Stream, val, ',') )
     {	
	nlj1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrlj1Stream, val, ',') )
     {	
	nerrlj1[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(p1Stream, val, ',') )
     {	
	p1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(perr1Stream, val, ',') )
     {	
	perr1[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(p2Stream, val, ',') )
     {	
	p2[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(perr2Stream, val, ',') )
     {	
	perr2[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(p3Stream, val, ',') )
     {	
	p3[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(perr3Stream, val, ',') )
     {	
	perr3[i] = atof(val.c_str());
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

   std::string fname = "results/fit_XSEC.root";
   TFile *f = new TFile(fname.c_str(),"RECREATE");
   
   TH1F *h_xsecDATA = new TH1F("h_xsecDATA","h_xsecDATA",ibn,xbins);
   TH1F *h_xsecDATAbj = new TH1F("h_xsecDATAbj","h_xsecDATAbj",ibn,xbins);
   TH1F *h_xsecDATAcj = new TH1F("h_xsecDATAcj","h_xsecDATAcj",ibn,xbins);
   TH1F *h_xsecDATAlj = new TH1F("h_xsecDATAlj","h_xsecDATAlj",ibn,xbins);

   TH1F *h_xsecDATAeffc = new TH1F("h_xsecDATAeffc","h_xsecDATAeffc",ibn,xbins);
   TH1F *h_xsecDATAbjeffc = new TH1F("h_xsecDATAbjeffc","h_xsecDATAbjeffc",ibn,xbins);
   TH1F *h_xsecDATAcjeffc = new TH1F("h_xsecDATAcjeffc","h_xsecDATAcjeffc",ibn,xbins);
   TH1F *h_xsecDATAljeffc = new TH1F("h_xsecDATAljeffc","h_xsecDATAljeffc",ibn,xbins);
   
   TFile feff("results/effSel.root");
   TH1F *heff_ajet = (TH1F*)feff.Get("heff_ajet");
   TH1F *heff_bjet = (TH1F*)feff.Get("heff_bjet");
   TH1F *heff_cjet = (TH1F*)feff.Get("heff_cjet");
   TH1F *heff_ljet = (TH1F*)feff.Get("heff_ljet");
   
   for(int j=0;j<ibn;j++)
     {
	// mb
	double xsecDATA = nb1[j]/il/pow(10.,12);
	double xsecerrDATA = nerrb1[j]/il/pow(10.,12);

	double xsecDATAbj = nb1[j]/il/pow(10.,12)*p1[j];
	double xsecerrDATAbj = sqrt(pow(nerrb1[j],2)+pow(perr1[j],2))/il/pow(10.,12);
	
	double xsecDATAcj = nb1[j]/il/pow(10.,12)*p2[j];
	double xsecerrDATAcj = sqrt(pow(nerrb1[j],2)+pow(perr2[j],2))/il/pow(10.,12);

	double xsecDATAlj = nb1[j]/il/pow(10.,12)*p3[j];
	double xsecerrDATAlj = sqrt(pow(nerrb1[j],2)+pow(perr3[j],2))/il/pow(10.,12);
	
	h_xsecDATA->SetBinContent(j+1,xsecDATA);
	h_xsecDATA->SetBinError(j+1,xsecerrDATA);

	h_xsecDATAbj->SetBinContent(j+1,xsecDATAbj);
	h_xsecDATAbj->SetBinError(j+1,xsecerrDATAbj);

	h_xsecDATAcj->SetBinContent(j+1,xsecDATAcj);
	h_xsecDATAcj->SetBinError(j+1,xsecerrDATAcj);

	h_xsecDATAlj->SetBinContent(j+1,xsecDATAlj);
	h_xsecDATAlj->SetBinError(j+1,xsecerrDATAlj);

	if( xsecDATA > 0. )
	  {	     
	     double xsecDATAeffc = xsecDATA / heff_ajet->GetBinContent(j+1);
	     double xsecerrDATAeffc = sqrt(pow(heff_ajet->GetBinError(j+1),2)+pow(xsecerrDATA,2));
	     
	     double xsecDATAbjeffc = xsecDATAbj / heff_bjet->GetBinContent(j+1);
	     double xsecerrDATAbjeffc = sqrt(pow(heff_bjet->GetBinError(j+1),2)+pow(xsecerrDATAbj,2));
	     
	     double xsecDATAcjeffc = xsecDATAcj / heff_cjet->GetBinContent(j+1);
	     double xsecerrDATAcjeffc = sqrt(pow(heff_cjet->GetBinError(j+1),2)+pow(xsecerrDATAcj,2));
	     
	     double xsecDATAljeffc = xsecDATAlj / heff_ljet->GetBinContent(j+1);
	     double xsecerrDATAljeffc = sqrt(pow(heff_ljet->GetBinError(j+1),2)+pow(xsecerrDATAlj,2));
	     
	     h_xsecDATAeffc->SetBinContent(j+1,xsecDATAeffc);
	     h_xsecDATAeffc->SetBinError(j+1,xsecerrDATAeffc);
	     
	     h_xsecDATAbjeffc->SetBinContent(j+1,xsecDATAbjeffc);
	     h_xsecDATAbjeffc->SetBinError(j+1,xsecerrDATAbjeffc);
	     
	     h_xsecDATAcjeffc->SetBinContent(j+1,xsecDATAcjeffc);
	     h_xsecDATAcjeffc->SetBinError(j+1,xsecerrDATAcjeffc);
	     
	     h_xsecDATAljeffc->SetBinContent(j+1,xsecDATAljeffc);
	     h_xsecDATAljeffc->SetBinError(j+1,xsecerrDATAljeffc);
	  }       
     }   

   h_xsecDATA->SetLineColor(1);
   h_xsecDATA->SetMarkerColor(1);
   h_xsecDATA->SetMarkerStyle(23);

   h_xsecDATAbj->SetLineColor(46);
   h_xsecDATAbj->SetMarkerColor(46);
   h_xsecDATAbj->SetMarkerStyle(20);

   h_xsecDATAcj->SetLineColor(38);
   h_xsecDATAcj->SetMarkerColor(38);
   h_xsecDATAcj->SetMarkerStyle(21);

   h_xsecDATAlj->SetLineColor(30);
   h_xsecDATAlj->SetMarkerColor(30);
   h_xsecDATAlj->SetMarkerStyle(22);

   h_xsecDATAeffc->SetLineColor(1);
   h_xsecDATAeffc->SetMarkerColor(1);
   h_xsecDATAeffc->SetMarkerStyle(23);

   h_xsecDATAbjeffc->SetLineColor(46);
   h_xsecDATAbjeffc->SetMarkerColor(46);
   h_xsecDATAbjeffc->SetMarkerStyle(20);

   h_xsecDATAcjeffc->SetLineColor(38);
   h_xsecDATAcjeffc->SetMarkerColor(38);
   h_xsecDATAcjeffc->SetMarkerStyle(21);

   h_xsecDATAljeffc->SetLineColor(30);
   h_xsecDATAljeffc->SetMarkerColor(30);
   h_xsecDATAljeffc->SetMarkerStyle(22);
   
//   h_xsecDATA->Draw("e1");
   h_xsecDATAbj->Draw("e1");
   h_xsecDATAcj->Draw("e1 same");
   h_xsecDATAlj->Draw("e1 same");
   
   h_xsecDATAbj->GetYaxis()->SetRangeUser(0.0001,100);

   h_xsecDATAbj->GetXaxis()->SetTitle("P_{T} [TeV]");
   h_xsecDATAbj->GetYaxis()->SetTitle("#sigma_{jj}^{vis} [mb]");

   TLegend *leg = new TLegend(0.75,0.90,0.90,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   std::string label = "#sigma(jj) "+lumi;
   leg->AddEntry(h_xsecDATA,label.c_str(),"lep");
   leg->AddEntry(h_xsecDATAbj,"#sigma(bj)","lep");
   leg->AddEntry(h_xsecDATAcj,"#sigma(cj)","lep");
   leg->AddEntry(h_xsecDATAlj,"#sigma(lj)","lep");
   
   leg->Draw();

   c1->SetLogy(1);
   
   std::string fsave = "pics/fit_XSEC.eps";
   c1->Print(fsave.c_str());
   c1->Clear();

//   h_xsecDATAeffc->Draw("e1");
   h_xsecDATAbjeffc->Draw("e1");
   h_xsecDATAcjeffc->Draw("e1 same");
   h_xsecDATAljeffc->Draw("e1 same");
   
   h_xsecDATAbjeffc->GetYaxis()->SetRangeUser(0.005,100.);

   h_xsecDATAbjeffc->GetXaxis()->SetTitle("P_{T} [TeV]");
   h_xsecDATAbjeffc->GetYaxis()->SetTitle("#sigma_{jj}^{vis} [mb]");
   
   leg->Draw();

   c1->SetLogy(1);
   
   std::string fsave = "pics/fit_XSEC_effc.eps";
   c1->Print(fsave.c_str());
   c1->Clear();
   
   f->Write();
   f->Close();
   
   gApplication->Terminate();
}
