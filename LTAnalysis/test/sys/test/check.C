void check()
{
   gROOT->SetBatch(1);
   
   std::string dir1 = "histNOM";
   std::string dir2 = "histRW";
   
   const int npt = 15;
   std::string pt[npt] = {"pt20t30","pt30t40","pt40t50","pt50t60","pt60t70","pt70t80",
      "pt80t100","pt100t120","pt120t160","pt160t210","pt210t260","pt260t320","pt320t400",
      "pt400t500","pt500t670"};
   
   std::string fname1 = dir1+"/MC/data.root";
   TFile *f1 = TFile::Open(fname1.c_str());
   std::string fname2 = dir2+"/MC/data.root";
   TFile *f2 = TFile::Open(fname2.c_str());
   
   for(int i=0;i<npt;i++)
     {
	std::string hname = "h_j1_JP_ajet_"+pt[i]+"_nosel_nosel";
	TH1D *h1 = (TH1D*)f1->Get(hname.c_str());
	TH1D *h2 = (TH1D*)f2->Get(hname.c_str());
	
	int nev1 = h1->GetEntries();
	int nev2 = h2->GetEntries();
	
	float int1 = h1->Integral(0,h1->GetXaxis()->GetNbins()+1);
	float int2 = h2->Integral(0,h2->GetXaxis()->GetNbins()+1);
	
	float diff = (int1 > 0) ? fabs(int1-int2)/int1 : 0.;
	
	if( nev1 != nev2 )
	  std::cout << "NEV problem in " << pt[i] << " " << nev1 << " " << nev2 << std::endl;
//	if( diff > 0.001 )
//	  std::cout << "INT problem in " << pt[i] << " " << int1 << " " << int2 << std::endl;
     }
   
   gApplication->Terminate();
}
