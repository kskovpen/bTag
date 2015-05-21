void combSF()
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   gROOT->ProcessLine(".L ratioh.C");
   gROOT->ProcessLine(".L makeErrorBand.C");
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   gStyle->SetHistTopMargin(0);

   std::string path = "results/fit_EFF_beauty_";
   const int nf = 3;
   std::string fin[nf] = 
     {"NONE",
      "JESup",
      "JESdown"};

   double sf[nf][100];
   double sferr[nf][100];
   double sys[nf][100];

   TFile *f[nf];
   TH1F *hComb;
   TH1F *hCombUp;
   TH1F *hCombDown;
   int nb;
   
   for(int i=0;i<nf;i++)
     {	
	std::string fname = path+fin[i]+".root";
	
	f[i] = new TFile(fname.c_str());
	TH1F *h1c = (TH1F*)f[i]->Get("h1c");
	if( i == 0 ) {hComb = (TH1F*)h1c->Clone("hComb");}
	nb = h1c->GetXaxis()->GetNbins();
	for(int ib=1;ib<=nb;ib++)
	  {
	     sf[i][ib] = h1c->GetBinContent(ib);
	     sferr[i][ib] = h1c->GetBinError(ib);
	  }	
     }
   
   hComb->Clear();
   hComb->GetYaxis()->SetTitle("Scale factor");
   
   hCombUp = (TH1F*)hComb->Clone("hCombUp");
   hCombDown = (TH1F*)hComb->Clone("hCombDown");
      
   for(int ib=1;ib<=nb;ib++)
     {
	hComb->SetBinContent(ib,sf[0][ib]);
	hComb->SetBinError(ib,sferr[0][ib]);
     }
   
   int i0 = 0;
   for(int j=1;j<nf;j++)
     {
	if( j%2 == 0 ) continue;
	for(int ib=1;ib<=nb;ib++)
	  {
	     sys[i0][ib] = sf[j][ib]-sf[j+1][ib];
	  }
	i0++;
     }
   
   std::cout << "Include " << i0 << " systematic variations" << std::endl;
   
   double sysComb[100];
   for(int i=0;i<100;i++)
     sysComb[i] = 0.;
   
   for(int ib=1;ib<=nb;ib++)
     {	
	for(int i=0;i<i0;i++)
	  {
	     sysComb[ib] += pow(sys[i][ib],2);
	  }   
	sysComb[ib] = sqrt(sysComb[ib]+pow(sferr[0][ib],2));
	hCombUp->SetBinContent(ib,sf[0][ib]+sysComb[ib]);
	hCombDown->SetBinContent(ib,sf[0][ib]-sysComb[ib]);
     }   

   hComb->GetYaxis()->SetRangeUser(0.6,1.6);
   hComb->Draw("e1");

   TGraphAsymmErrors *grComb = makeErrorBand(hComb,
					     hCombUp,
					     hCombDown);

   grComb->SetFillColor(kGreen-8);
   
   grComb->Draw("2SAME");
   hComb->Draw("e1 same");
   
   TLine *lone = new TLine(0.02,1.,1.0,1.);
   lone->SetLineStyle(2);
   lone->SetLineWidth(2);
   
   lone->Draw("same");
   
   std::string fsave = "pics/fit_EFF_COMB.eps";
   c1->Print(fsave.c_str());
   
   for(int i=0;i<nf;i++)
     f[i]->Close();
   
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

   double err = ve1*ve1/v2/v2 + v1*v1*ve2*ve2/v2/v2/v2/v2;
   
   err = sqrt(err);
   
   return err;
}
