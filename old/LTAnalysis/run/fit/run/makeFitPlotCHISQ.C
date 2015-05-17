void makeFitPlotCHISQ(std::string ptb1Str,
		      std::string ptb2Str,
		      std::string chisq1Str,
		      std::string ndof1Str,
		      std::string name,
		      std::string tit)
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   TPad *c1_1;
   c1->Range(0,0,1,1);
   c1_1 = new TPad("c1_1","main",0.01,0.50,0.99,0.99);
//   c1_1 = new TPad("c1_1","main",0.01,0.30,0.99,0.99);
   c1_1->Draw();
   c1_1->cd();

   gStyle->SetHistTopMargin(0);

   double ptb1[100];
   double ptb2[100];
   
   double chisq1[100];
   int ndof1[100];
   
   double prob1[100];

   std::stringstream ptb1Stream(ptb1Str);
   std::stringstream ptb2Stream(ptb2Str);
   
   std::stringstream chisq1Stream(chisq1Str);
   std::stringstream ndof1Stream(ndof1Str);
   
   std::string val;
   
   int i = 0;
   while( getline(chisq1Stream, val, ',') )
     {	
	chisq1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(ndof1Stream, val, ',') )
     {	
	ndof1[i] = atoi(val.c_str());
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

   std::string fsave = "results/fit_CHISQ_"+tit+".root";
   TFile *f = new TFile(fsave.c_str(),"RECREATE");
   
   TH1F *h_chisq1 = new TH1F("h_chisq1","h_chisq1",ibn,xbins);
   TH1F *h_ndof1 = new TH1F("h_ndof1","h_ndof1",ibn,xbins);

   for(int j=0;j<ibn;j++)
     {
	double chisq1v = (ndof1[j] == 0) ? 0 : chisq1[j]/float(ndof1[j]);
	prob1[j] = TMath::Prob(chisq1[j],ndof1[j]);

	if( chisq1v > 0 )
	  {	     
	     h_chisq1->SetBinContent(j+1,chisq1v);
	     h_chisq1->SetBinError(j+1,pow(10.,-10.));

	     h_ndof1->SetBinContent(j+1,float(ndof1[j]));
	     h_ndof1->SetBinError(j+1,pow(10.,-10.));
	  }	
     }   
   
   h_chisq1->SetLineColor(46);
   h_chisq1->SetMarkerColor(46);
   h_chisq1->SetMarkerStyle(20);

   h_chisq1->Draw("p");

   h_chisq1->GetYaxis()->SetRangeUser(0.001,1.);
   
   c1_1->SetLogy(1);
   
   h_chisq1->GetXaxis()->SetTitle("P_{T} [GeV]");
   h_chisq1->GetYaxis()->SetTitle("#Chi^{2}/N_{dof}");

   TLegend *leg = new TLegend(0.75,0.90,0.90,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   std::string label = "Data "+lumi;
   leg->AddEntry(h_chisq1,label.c_str(),"lep");

   leg->Draw();

   // plot prob
   
   TH1F* hp = (TH1F*)h_chisq1->Clone("hp");
   hp->Reset();

   c1->cd();
//   TPad *c1_2 = new TPad("c1_2", "ratio",0.01,0.01,0.99,0.37);
   TPad *c1_2 = new TPad("c1_2", "ratio",0.01,0.01,0.99,0.47);
   c1_2->Draw();
   c1_2->cd();  
//   c1_2->SetBottomMargin(0.37);
   c1_2->SetBottomMargin(0.27);
//   c1_2->SetGrid(0,1);

   hp->SetMarkerStyle(20);
   hp->SetMarkerSize(0.8);
//   hp->GetYaxis()->SetNdivisions(5);
   hp->GetYaxis()->SetTitle("P(#Chi^{2}/N_{dof})");
   
//   hp->GetYaxis()->SetTitleSize((hp->GetYaxis()->GetTitleSize())*2);
   hp->GetYaxis()->SetTitleOffset(hp->GetYaxis()->GetTitleOffset()/2);
//   hp->GetXaxis()->SetTitleSize((hp->GetXaxis()->GetTitleSize())*2);
   hp->GetXaxis()->SetTitleOffset(hp->GetXaxis()->GetTitleOffset()+0.2);

//   hp->GetYaxis()->SetLabelSize((hp->GetYaxis()->GetLabelSize())*2);
//   hp->GetXaxis()->SetLabelSize((hp->GetXaxis()->GetLabelSize())*2);

   hp->GetXaxis()->SetTitle(hp->GetXaxis()->GetTitle());

   hp->GetYaxis()->SetRangeUser(0.001,1.1);

   c1_2->SetLogy(1);
   
   hp->SetLineColor(kBlack);
   hp->SetMarkerColor(kBlack);

   for(int ib=1;ib<hp->GetXaxis()->GetNbins()+1;ib++)
     {
	if( prob1[ib-1] > 0 )
	  {	     
	     hp->SetBinContent(ib,prob1[ib-1]);
	     hp->SetBinError(ib,pow(10.,-20.));
	  }	
	else
	  {
	     hp->SetBinContent(ib,pow(10.,-20.));
	     hp->SetBinError(ib,pow(10.,-20.));	     
	  }	
     }   
   
   hp->Draw("hist");
   
   c1->Update();

   std::string fsave = "pics/fit_CHISQ_"+tit+".eps";
   c1->Print(fsave.c_str());
   c1->Clear();

   f->Write();
   f->Close();
   
   gApplication->Terminate();
}
