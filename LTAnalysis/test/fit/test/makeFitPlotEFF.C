#include "ratioh.C"

double errfMC(double,double,double,double);

double errfDATA(double,double,double,double);

double errfDATA_UNCOR(double,double,double,double);

void makeFitPlotEFF(std::string type,bool usePRETAGb,bool usePRETAGc)
{
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);

   gROOT->ProcessLine(".x def.C");
   gROOT->ProcessLine(".x common.C");

   gROOT->ProcessLine(".L ratioh.C");
   
   TCanvas *c1 = new TCanvas("c1","c1",0,0,600,500);
   TPad *c1_1;
   c1->Range(0,0,1,1);
   c1_1 = new TPad("c1_1","main",0.01,0.30,0.99,0.99);
   c1_1->Draw();
   c1_1->cd();

   std::string ptb1Str, ptb2Str,
     p1Str, p2Str, p1errStr, p2errStr,
     nb1Str, nb2Str, nerrb1Str, nerrb2Str,
     nc1Str, nc2Str, nerrc1Str, nerrc2Str,
     nl1Str, nl2Str, nerrl1Str, nerrl2Str,
     nd1Str, nd2Str, nerrd1Str, nerrd2Str,
     fr1Str, fr2Str,
     frB1Str, frB2Str,
     frC1Str, frC2Str,
     frL1Str, frL2Str;
     
   std::ifstream fcom("input/makeFitPlotEFF.txt");
   fcom >> ptb1Str;
   fcom >> ptb2Str;
   fcom >> p1Str;
   fcom >> p2Str;
   fcom >> p1errStr;
   fcom >> p2errStr;
   fcom >> nb1Str;
   fcom >> nb2Str;
   fcom >> nerrb1Str;
   fcom >> nerrb2Str;
   fcom >> nc1Str;
   fcom >> nc2Str;
   fcom >> nerrc1Str;
   fcom >> nerrc2Str;
   fcom >> nl1Str;
   fcom >> nl2Str;
   fcom >> nerrl1Str;
   fcom >> nerrl2Str;
   fcom >> nd1Str;
   fcom >> nd2Str;
   fcom >> nerrd1Str;
   fcom >> nerrd2Str;
   fcom >> fr1Str;
   fcom >> fr2Str;
   fcom >> frB1Str;
   fcom >> frB2Str;
   fcom >> frC1Str;
   fcom >> frC2Str;
   fcom >> frL1Str;
   fcom >> frL2Str;
   fcom.close();
   
   gStyle->SetHistTopMargin(0);

   double ptb1[100];
   double ptb2[100];
   
   double p1[100];
   double p2[100];
   double p1err[100];
   double p2err[100];

   double nb1[100];
   double nb2[100];
   double nerrb1[100];
   double nerrb2[100];

   double nc1[100];
   double nc2[100];
   double nerrc1[100];
   double nerrc2[100];

   double nl1[100];
   double nl2[100];
   double nerrl1[100];
   double nerrl2[100];

   double nd1[100];
   double nd2[100];
   double nerrd1[100];
   double nerrd2[100];

   double fr1[100];
   double fr2[100];

   double frB1[100];
   double frB2[100];

   double frC1[100];
   double frC2[100];

   double frL1[100];
   double frL2[100];
   
   std::stringstream ptb1Stream(ptb1Str);
   std::stringstream ptb2Stream(ptb2Str);
   
   std::stringstream p1Stream(p1Str);
   std::stringstream p2Stream(p2Str);
   std::stringstream p1errStream(p1errStr);
   std::stringstream p2errStream(p2errStr);

   std::stringstream nb1Stream(nb1Str);
   std::stringstream nb2Stream(nb2Str);
   std::stringstream nerrb1Stream(nerrb1Str);
   std::stringstream nerrb2Stream(nerrb2Str);

   std::stringstream nc1Stream(nc1Str);
   std::stringstream nc2Stream(nc2Str);
   std::stringstream nerrc1Stream(nerrc1Str);
   std::stringstream nerrc2Stream(nerrc2Str);

   std::stringstream nl1Stream(nl1Str);
   std::stringstream nl2Stream(nl2Str);
   std::stringstream nerrl1Stream(nerrl1Str);
   std::stringstream nerrl2Stream(nerrl2Str);

   std::stringstream nd1Stream(nd1Str);
   std::stringstream nd2Stream(nd2Str);
   std::stringstream nerrd1Stream(nerrd1Str);
   std::stringstream nerrd2Stream(nerrd2Str);

   std::stringstream fr1Stream(fr1Str);
   std::stringstream fr2Stream(fr2Str);

   std::stringstream frB1Stream(frB1Str);
   std::stringstream frB2Stream(frB2Str);

   std::stringstream frC1Stream(frC1Str);
   std::stringstream frC2Stream(frC2Str);

   std::stringstream frL1Stream(frL1Str);
   std::stringstream frL2Stream(frL2Str);
   
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
   while( getline(nc1Stream, val, ',') )
     {	
	nc1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nc2Stream, val, ',') )
     {	
	nc2[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrc1Stream, val, ',') )
     {	
	nerrc1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrc2Stream, val, ',') )
     {	
	nerrc2[i] = atof(val.c_str());
	i++;
     }   

   // light
   i = 0;
   while( getline(nl1Stream, val, ',') )
     {	
	nl1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nl2Stream, val, ',') )
     {	
	nl2[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrl1Stream, val, ',') )
     {	
	nerrl1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrl2Stream, val, ',') )
     {	
	nerrl2[i] = atof(val.c_str());
	i++;
     }   

   // data
   i = 0;
   while( getline(nd1Stream, val, ',') )
     {	
	nd1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nd2Stream, val, ',') )
     {	
	nd2[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrd1Stream, val, ',') )
     {	
	nerrd1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(nerrd2Stream, val, ',') )
     {	
	nerrd2[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(fr1Stream, val, ',') )
     {	
	fr1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(fr2Stream, val, ',') )
     {	
	fr2[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(frB1Stream, val, ',') )
     {	
	frB1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(frB2Stream, val, ',') )
     {	
	frB2[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(frC1Stream, val, ',') )
     {	
	frC1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(frC2Stream, val, ',') )
     {	
	frC2[i] = atof(val.c_str());
	i++;
     }   

   i = 0;
   while( getline(frL1Stream, val, ',') )
     {	
	frL1[i] = atof(val.c_str());
	i++;
     }   
   i = 0;
   while( getline(frL2Stream, val, ',') )
     {	
	frL2[i] = atof(val.c_str());
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

   std::string fname = "results/fit_EFF_"+type+".root";
   TFile *f = new TFile(fname.c_str(),"RECREATE");
   
   TH1F *h_eff1DATA = new TH1F("h_eff1DATA","h_eff1DATA",ibn,xbins);
   TH1F *h_eff1MC = new TH1F("h_eff1MC","h_eff1MC",ibn,xbins);
   
   for(int j=0;j<ibn;j++)
     {
//	std::cout << "b:" << nb1[j] << " " << nb2[j] << std::endl;
//	std::cout << "c:" << nc1[j] << " " << nc2[j] << std::endl;

/*	double f1;
	
	if( usePRETAGb )
	  f1 = ((nb2[j]+nc2[j]+nl2[j]) == 0) ? 0. : (nb2[j]+nc1[j]+nl1[j])/(nb2[j]+nc2[j]+nl2[j]);
	else if( usePRETAGc )
	  f1 = ((nb2[j]+nc2[j]+nl2[j]) == 0) ? 0. : (nb1[j]+nc2[j]+nl1[j])/(nb2[j]+nc2[j]+nl2[j]);
	else
	  f1 = ((nb2[j]+nc2[j]+nl2[j]) == 0) ? 0. : (nb1[j]+nc1[j]+nl1[j])/(nb2[j]+nc2[j]+nl2[j]);
*/

////	double fr = ((1+fr2[j]+1) == 0) ? 0. : (1+fr1[j]+1)/(1+fr2[j]+1);
	double fr = 1;
	
	double f2 = (nd1[j] == 0) ? 0. : nd2[j]/nd1[j];
	
	double eff1DATA = (p1[j] == 0) ? 0 : p2[j]/p1[j];
//	double eff1errDATA = errfDATA(p2[j],p2err[j],p1[j],p1err[j]);
	double eff1errDATA = errfDATA_UNCOR(p2[j],p2err[j],p1[j],p1err[j]);

//	std::cout << p1[j]/(2+fr1[j]) << std::endl;
//	std::cout << p1[j]/3 << " " << p2[j]/3 << std::endl;
	
//	std::cout << eff1DATA << " +- " << eff1errDATA 
//	  << " " << p2[j] << " " << p2err[j] << " " << p1[j] << " " << p1err[j] << std::endl;
	
	double eff1MC = 0.;
	double eff1errMC = 0.;

	// case of non-scaled MC
///	double fdatab = nb2[j]/nb1[j];
///	double fdatac = nc2[j]/nc1[j];
	double fdatab = frB2[j]/frB1[j];
	double fdatac = frC2[j]/frC1[j];

	std::cout << fdatab << " " << f2 << " " << eff1DATA << std::endl;
	
	// if MC is scaled, otherwise comment it
///	fdatab = 1;
///	fdatac = 1;
	
//	if( usePRETAGb )
//	  fdatab = 1.;
	
//	if( usePRETAGc )
//	  fdatac = 1.;
	
	if( type == "beauty" )
	  {	     
	     eff1MC = (nb1[j] == 0) ? 0 : nb2[j]/nb1[j];
	     eff1errMC = errfMC(nb2[j],nerrb2[j],nb1[j],nerrb1[j]);
	     
	     eff1DATA = (nb1[j] == 0) ? 0 : eff1DATA*fdatab;
	     eff1errDATA = (nb1[j] == 0) ? 0 : eff1errDATA*fdatab;
	  }	
	if( type == "charm" )
	  {	     
	     eff1MC = (nc1[j] == 0) ? 0 : nc2[j]/nc1[j];
	     eff1errMC = errfMC(nc2[j],nerrc2[j],nc1[j],nerrc1[j]);

	     eff1DATA = (nc1[j] == 0) ? 0 : eff1DATA*fdatac;
	     eff1errDATA = (nc1[j] == 0) ? 0 : eff1errDATA*fdatac;
	  }	
	if( type == "light" )
	  {	     
	     eff1MC = (nl1[j] == 0) ? 0 : nl2[j]/nl1[j];
	     eff1errMC = errfMC(nl2[j],nerrl2[j],nl1[j],nerrl1[j]);

	     eff1DATA = (nl1[j] == 0) ? 0 : eff1DATA*nl2[j]/nl1[j];
	     eff1errDATA = (nl1[j] == 0) ? 0 : eff1errDATA*nl2[j]/nl1[j];
	  }	
	
//	eff1DATA *= f1*f2;
//	eff1errDATA *= f1*f2;

	eff1DATA *= f2 * fr;
	eff1errDATA *= f2 * fr;
	
	if( eff1DATA > 0 )
	  {	     
	     h_eff1DATA->SetBinContent(j+1,eff1DATA);
	     h_eff1DATA->SetBinError(j+1,sqrt(pow(eff1errDATA,2)+pow(eff1errMC,2)));
	  }	

	if( eff1MC > 0 )
	  {	     
	     h_eff1MC->SetBinContent(j+1,eff1MC);
	     h_eff1MC->SetBinError(j+1,eff1errMC);
	  }	
     }   

   if( type == "beauty" )
     {	
	h_eff1DATA->SetLineColor(46);
	h_eff1DATA->SetMarkerColor(46);
	h_eff1DATA->SetMarkerStyle(20);
	h_eff1MC->SetLineColor(46);
	h_eff1MC->SetMarkerColor(46);
	h_eff1MC->SetMarkerStyle(25);
     }
   if( type == "charm" )
     {
	h_eff1DATA->SetLineColor(38);
	h_eff1DATA->SetMarkerColor(38);
	h_eff1DATA->SetMarkerStyle(21);
	h_eff1MC->SetLineColor(38);
	h_eff1MC->SetMarkerColor(38);
	h_eff1MC->SetMarkerStyle(25);
     }
   if( type == "light" )
     {	
	h_eff1DATA->SetLineColor(30);
	h_eff1DATA->SetMarkerColor(30);
	h_eff1DATA->SetMarkerStyle(22);
	h_eff1MC->SetLineColor(30);
	h_eff1MC->SetMarkerColor(30);
	h_eff1MC->SetMarkerStyle(26);
     }   

   h_eff1DATA->Draw("e1");   
   h_eff1MC->Draw("e1 same");
   
//   ATLASLabel(0.20,0.85,"Internal",1);
   
   if( type == "beauty" )
     h_eff1DATA->GetYaxis()->SetRangeUser(0.,1.3);

   if( type == "charm" )
     h_eff1DATA->GetYaxis()->SetRangeUser(0.,1.3);
//   h_eff1DATA->GetYaxis()->SetRangeUser(0.,0.4);

   if( type == "light" )
     h_eff1DATA->GetYaxis()->SetRangeUser(0.,0.1);
   
   h_eff1DATA->GetXaxis()->SetTitle("P_{T} [TeV]");
   h_eff1DATA->GetYaxis()->SetTitle("Efficiency");

   TLegend *leg = new TLegend(0.75,0.90,0.90,0.75);
   leg->SetFillColor(253);
   leg->SetBorderSize(0);
   
   std::string label = "Data";
//   std::string label = "Data "+lumi;
   leg->AddEntry(h_eff1DATA,label.c_str(),"lep");
   leg->AddEntry(h_eff1MC,"MC","lep");
   
   leg->Draw();
   
   ratioh(c1,h_eff1DATA,h_eff1MC,type);
   
   std::string fsave = "pics/fit_EFF_"+type+".eps";
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

   double err = ve1*ve1/v2/v2 + v1*v1*ve2*ve2/v2/v2/v2/v2;
   
   err = sqrt(err);
   
   return err;
}

double errfDATA_UNCOR(double v1,double ve1,double v2,double ve2)
{
   if( v2 == 0 ) return -666;

   double err = ve1*ve1/v1/v1+ve2*ve2/v2/v2;
   
   err = sqrt(err)*v1/v2;
   
   return err;   
}
