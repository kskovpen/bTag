/*void makeFitPlotCOMPEFF(std::string ptb1Str,
			std::string ptb2Str,
			std::string nb1Str,
			std::string nb2Str,
			std::string nerrb1Str,
			std::string nerrb2Str,
			std::string nb1StrC,
			std::string nb2StrC,
			std::string nerrb1StrC,
			std::string nerrb2StrC,
			std::string nb1StrL,
			std::string nb2StrL,
			std::string nerrb1StrL,
			std::string nerrb2StrL
			)*/
void makeFitPlotCOMPEFF()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   gROOT->ProcessLine(".L ratioh.C");
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   double ptb1[100];
   double ptb2[100];
   
   double nb1[100];
   double nb2[100];
   double nerrb1[100];
   double nerrb2[100];
   double nb1C[100];
   double nb2C[100];
   double nerrb1C[100];
   double nerrb2C[100];
   double nb1L[100];
   double nb2L[100];
   double nerrb1L[100];
   double nerrb2L[100];
   
   std::string ptb1Str, ptb2Str,
     nb1Str, nb2Str, nerrb1Str, nerrb2Str,
     nb1StrC, nb2StrC, nerrb1StrC, nerrb2StrC,
     nb1StrL, nb2StrL, nerrb1StrL, nerrb2StrL;
     
   std::ifstream fcom("input/makeFitPlotCOMPEFF.txt");
   fcom >> ptb1Str;
   fcom >> ptb2Str;
   fcom >> nb1Str;
   fcom >> nb2Str;
   fcom >> nerrb1Str;
   fcom >> nerrb2Str;
   fcom >> nb1StrC;
   fcom >> nb2StrC;
   fcom >> nerrb1StrC;
   fcom >> nerrb2StrC;
   fcom >> nb1StrL;
   fcom >> nb2StrL;
   fcom >> nerrb1StrL;
   fcom >> nerrb2StrL;
   fcom.close();

   std::stringstream ptb1Stream(ptb1Str);
   std::stringstream ptb2Stream(ptb2Str);
   
   std::stringstream nb1Stream(nb1Str);
   std::stringstream nb2Stream(nb2Str);
   std::stringstream nerrb1Stream(nerrb1Str);
   std::stringstream nerrb2Stream(nerrb2Str);

   std::stringstream nb1StreamC(nb1StrC);
   std::stringstream nb2StreamC(nb2StrC);
   std::stringstream nerrb1StreamC(nerrb1StrC);
   std::stringstream nerrb2StreamC(nerrb2StrC);

   std::stringstream nb1StreamL(nb1StrL);
   std::stringstream nb2StreamL(nb2StrL);
   std::stringstream nerrb1StreamL(nerrb1StrL);
   std::stringstream nerrb2StreamL(nerrb2StrL);
   
   std::string val;
   
   int i = 0;
   // beauty
   i = 0;
   while( getline(nb1Stream, val, ',') )
     {	
	nb1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nb2Stream, val, ',') )
     {	
	nb2[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(nerrb1Stream, val, ',') )
     {	
	nerrb1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrb2Stream, val, ',') )
     {	
	nerrb2[i] = atof(val.c_str());
	i++;
     }   

   // charm
   i = 0;
   while( getline(nb1StreamC, val, ',') )
     {	
	nb1C[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nb2StreamC, val, ',') )
     {	
	nb2C[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(nerrb1StreamC, val, ',') )
     {	
	nerrb1C[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrb2StreamC, val, ',') )
     {	
	nerrb2C[i] = atof(val.c_str());
	i++;
     }   

   // light
   i = 0;
   while( getline(nb1StreamL, val, ',') )
     {	
	nb1L[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nb2StreamL, val, ',') )
     {	
	nb2L[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(nerrb1StreamL, val, ',') )
     {	
	nerrb1L[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrb2StreamL, val, ',') )
     {	
	nerrb2L[i] = atof(val.c_str());
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

   TFile *f = new TFile("results/fit_COMPEFF.root","RECREATE");
   
   TH1F *h_eff1MC_b = new TH1F("h_eff1MC_b","h_eff1MC_b",ibn,xbins);
   TH1F *h_eff1MC_c = new TH1F("h_eff1MC_c","h_eff1MC_c",ibn,xbins);
   TH1F *h_eff1MC_l = new TH1F("h_eff1MC_l","h_eff1MC_l",ibn,xbins);
   
   for(int j=0;j<ibn;j++)
     {
	double eff1MC_b = (nb1[j] == 0) ? 0 : nb2[j]/nb1[j];
	double eff1errMC_b = errfMC(nb2[j],nerrb2[j],nb1[j],nerrb1[j]);

	double eff1MC_c = (nb1C[j] == 0) ? 0 : nb2C[j]/nb1C[j];
	double eff1errMC_c = errfMC(nb2C[j],nerrb2C[j],nb1C[j],nerrb1C[j]);

	double eff1MC_l = (nb1L[j] == 0) ? 0 : nb2L[j]/nb1L[j];
	double eff1errMC_l = errfMC(nb2L[j],nerrb2L[j],nb1L[j],nerrb1L[j]);
	
	if( eff1MC_b > 0 )
	  {	     
	     h_eff1MC_b->SetBinContent(j+1,eff1MC_b);
	     h_eff1MC_b->SetBinError(j+1,eff1errMC_b);
	  }	

	if( eff1MC_c > 0 )
	  {	     
	     h_eff1MC_c->SetBinContent(j+1,eff1MC_c);
	     h_eff1MC_c->SetBinError(j+1,eff1errMC_c);
	  }	

	if( eff1MC_l > 0 )
	  {	     
	     h_eff1MC_l->SetBinContent(j+1,eff1MC_l);
	     h_eff1MC_l->SetBinError(j+1,eff1errMC_l);
	  }	
     }   

   h_eff1MC_b->SetLineColor(46);
   h_eff1MC_b->SetMarkerColor(46);
   h_eff1MC_b->SetMarkerStyle(24);

   h_eff1MC_c->SetLineColor(38);
   h_eff1MC_c->SetMarkerColor(38);
   h_eff1MC_c->SetMarkerStyle(25);

   h_eff1MC_l->SetLineColor(30);
   h_eff1MC_l->SetMarkerColor(30);
   h_eff1MC_l->SetMarkerStyle(26);

   h_eff1MC_b->Draw("e1");
   h_eff1MC_c->Draw("e1 same");
   h_eff1MC_l->Draw("e1 same");
   
   h_eff1MC_b->GetYaxis()->SetRangeUser(0.,1.2);
   h_eff1MC_c->GetYaxis()->SetRangeUser(0.,1.2);
   h_eff1MC_l->GetYaxis()->SetRangeUser(0.,1.2);
   
   h_eff1MC_b->GetXaxis()->SetTitle("P_{T} [TeV]");
   h_eff1MC_b->GetYaxis()->SetTitle("Efficiency");

   TLegend *leg = new TLegend(0.75,0.90,0.90,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   leg->AddEntry(h_eff1MC_b,"Beauty","lep");
   leg->AddEntry(h_eff1MC_c,"Charm","lep");
   leg->AddEntry(h_eff1MC_l,"Light","lep");
   
   leg->Draw();
   
   std::string fsave = "pics/fit_COMPEFF.eps";
   c1->Print(fsave.c_str());
   c1->Clear();

   f->Write();
   f->Close();
   
   gApplication->Terminate();
}

double errfMC(double v1,double ve1,double v2,double ve2)
{
   if( v2 == 0 ) return -666;

   double err = pow(v2-v1,2)*ve1*ve1/pow(v2,4) +
     v1*v1*(ve2*ve2-ve1*ve1)/pow(v2,4);
   
   err = sqrt(err);
   
   return err;
}

double errfDATA(double v1,double ve1,double v2,double ve2)
{
   if( v2 == 0 ) return -666;

   double err = ve1*ve1/v2/v2 + v1*v1*ve2*ve2/v2/v2;
   
   err = sqrt(err);
   
   return err;
}
