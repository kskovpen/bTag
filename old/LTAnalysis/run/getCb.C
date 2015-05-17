#include "CMSLABEL.C"

void getCb()
{
   std::string flav = "cjet"; // bjet or cjet
   std::string year = "_2011"; // _2011 or nothing

   TLatex *t1 = CMSLABEL();

   std::string bTag = "TCH"; // CSV or TCH 
   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");

   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x fit/run/def.C");
   gROOT->ProcessLine(".x fit/run/common.C");

   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   
   std::string hdir = "histMJ2ALL_2011";
//   std::string hdir = "histMJ_ALL";

   const int nf = 11;
   TFile *fMC[nf];
   std::string fname[nf] = 
     {
	"/Pt-15to20/data.root",
	"/Pt-20to30/data.root",
	"/Pt-30to50/data.root",
	"/Pt-50to80/data.root",
	"/Pt-80to120/data.root",
	"/Pt-120to170/data.root",
	"/Pt-170to300/data.root",
	"/Pt-300to470/data.root",
	"/Pt-470to600/data.root",
	"/Pt-600to800/data.root",
	"/Pt-800to1000/data.root"
     };

   const int nbtag = 4;
   std::string btagname[nbtag] =
     {
	"nosel",
//	"combSvx0p244",
//	"combSvx0p679",
//	"combSvx0p898"
	"TCHP1p19",
	"TCHP1p93",
	"TCHP3p41"
     };   

   const int npt = 18;
   std::string ptname[npt] = 
     {
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
	"pt800t1000",
	"pt1000t1400"
     };   
   
   TH1D *h_bjets[npt][nbtag];

   for(int i=0;i<nf;i++)
     {
	std::string fn = hdir+fname[i];
	fMC[i] = TFile::Open(fn.c_str());

	for(int ipt=0;ipt<npt;ipt++)
	  {
	     for(int ibtag=0;ibtag<nbtag;ibtag++)
	       {
		  std::string hname = "h_j1_JP_"+flav+"_"+ptname[ipt]+"_nosel_"+btagname[ibtag];
		  TH1D *hf = (TH1D*)fMC[i]->Get(hname.c_str());
		  if( i == 0 )
		    {		       
		       hname += "_this";
		       h_bjets[ipt][ibtag] = (TH1D*)hf->Clone(hname.c_str());
		    }	
		  else
		    {
		       h_bjets[ipt][ibtag]->Add(hf,1.);
		    }
	       }
	  }	
     }   

   const int xb = 18;
   double xax[xb] = 
     {0.02,0.03,0.04,0.05,0.06,0.07,0.08,0.10,0.12,0.16,0.21,0.26,0.32,0.40,0.50,0.60,0.80,1.00};
   TH1D *h_cb[nbtag];
   for(int i=1;i<nbtag;i++)
     {	
	std::string hname = "h_cb_"+btagname[i-1];
	h_cb[i-1] = new TH1D(hname.c_str(),hname.c_str(),xb-1,xax);
	if( i == 1 ) 
	  {
	     h_cb[i-1]->SetMarkerStyle(20);
	     h_cb[i-1]->SetMarkerSize(0.8);
	     h_cb[i-1]->SetLineColor(kBlack);
	     h_cb[i-1]->SetMarkerColor(kBlack);
	  }	
	if( i == 2 )
	  {
	     h_cb[i-1]->SetMarkerStyle(21);
	     h_cb[i-1]->SetMarkerSize(0.8);
	     h_cb[i-1]->SetLineColor(kRed);
	     h_cb[i-1]->SetMarkerColor(kRed);
	  }	
	if( i == 3 ) 
	  {
	     h_cb[i-1]->SetMarkerStyle(22);
	     h_cb[i-1]->SetMarkerSize(0.8);
	     h_cb[i-1]->SetLineColor(kBlue);
	     h_cb[i-1]->SetMarkerColor(kBlue);
	  }	
     }   
   
   std::string fcb;

   for(int ibtag=1;ibtag<nbtag;ibtag++)
     {	
	if( flav == "bjet" ) 
	  {
	     fcb = "cb_"+btagname[ibtag]+"_bjet"+year+".txt";
	  }   
	else
	  {
	     fcb = "cb_"+btagname[ibtag]+"_cjet"+year+".txt";
	  }   
   
	std::ofstream f_cb(fcb.c_str());
	
	for(int ipt=0;ipt<npt;ipt++)
	  {
	     int nb = h_bjets[ipt][0]->GetXaxis()->GetNbins();
	     
	     double err0_nosel, errint_nosel;
	     double err0_btag, errint_btag;
	     
	     double v0_nosel = h_bjets[ipt][0]->IntegralAndError(1,nb+1,err0_nosel);
	     double vint_nosel = h_bjets[ipt][0]->IntegralAndError(0,nb+1,errint_nosel);
	     
	     double v0_btag = h_bjets[ipt][ibtag]->IntegralAndError(1,nb+1,err0_btag);
	     double vint_btag = h_bjets[ipt][ibtag]->IntegralAndError(0,nb+1,errint_btag);
	
	     double cb = v0_nosel/v0_btag*vint_btag/vint_nosel;
	     double cberr = errf(v0_btag,err0_btag,vint_btag,errint_btag);
	     
	     f_cb << ipt << " " << cb << " " << cberr*cb << std::endl;
	
	     h_cb[ibtag-1]->SetBinContent(ipt+1,cb);
	     h_cb[ibtag-1]->SetBinError(ipt+1,cberr*cb);
	  }

	f_cb.close();
   
	if( ibtag == 1 ) h_cb[ibtag-1]->Draw("e1p");
	else h_cb[ibtag-1]->Draw("e1p same");
	c1->SetLogx(1);
	h_cb[ibtag-1]->GetYaxis()->SetRangeUser(0.87,1.03);
	h_cb[ibtag-1]->GetXaxis()->SetTitle("P_{T} [TeV]");
	if( flav == "bjet" )
	  h_cb[ibtag-1]->GetYaxis()->SetTitle("C_{b}");
	else 
	  h_cb[ibtag-1]->GetYaxis()->SetTitle("C_{c}");
	
	h_cb[ibtag-1]->GetXaxis()->SetNdivisions(510);
	
	h_cb[ibtag-1]->SetNdivisions(510, "XYZ");
	h_cb[ibtag-1]->GetXaxis()->SetMoreLogLabels();
	h_cb[ibtag-1]->GetXaxis()->SetNoExponent();
     }

   TLegend *leg = new TLegend(0.60,0.40,0.88,0.20);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   if( bTag == "CSV" )
     {	
	leg->AddEntry(h_cb[0],"CSVL","lp");
	leg->AddEntry(h_cb[1],"CSVM","lp");
	leg->AddEntry(h_cb[2],"CSVT","lp");
     }
   else
     {
	leg->AddEntry(h_cb[0],"TCHPL","lp");
	leg->AddEntry(h_cb[1],"TCHPM","lp");
	leg->AddEntry(h_cb[2],"TCHPT","lp");
     }   
   leg->Draw();   

   t1->Draw();
   
   TLatex Tl;
   Tl.SetTextSize(0.08);
   Tl.DrawLatex(0.1,0.95,"QCD MC");
   std::string fsave = "cb.eps";
   c1->Print(fsave.c_str());
   c1->Clear();
   
   gApplication->Terminate();
}

double errf(double v1,double ve1,double v2,double ve2)
{
   if( v2 == 0 ) return -666;

   double err = pow(v2-v1,2)*ve1*ve1/pow(v2,4) +
     v1*v1*(ve2*ve2-ve1*ve1)/pow(v2,4);
   
   err = sqrt(err)*v2/v1;
   
   return err;
}
