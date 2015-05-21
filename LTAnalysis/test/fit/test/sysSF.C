void sysSF()
{
   gROOT->SetBatch(1);

   std::string ver = "TCHP";
   std::string tag = "TIGHT";
   const int nrun = 4;
   int run[nrun] = {8,9,15,18};
   int runCentral = 7;
   
   bool sum2 = 1;
   
   std::string sfCentral = "results/SF_"+tag+"_2011FINAL"+ver+"_"+std::string(Form("%d",runCentral))+"_beauty";
   std::string sfCentralROOT = sfCentral+".root";
   std::string sfCentralTEX = sfCentral+".tex";
   TFile *f_Central = TFile::Open(sfCentralROOT.c_str());
   TH1F *hSF_Central = (TH1F*)f_Central->Get("hSF");
   TPolyLine *hSFSYS_Central = (TPolyLine*)f_Central->Get("hSFSYS");

   std::string sfCentral_mod = "results/SF_"+tag+"_2011FINAL"+ver+"_beauty";
   std::string sfCentral_modROOT = sfCentral_mod+".root";
   std::string sfCentral_modTEX = sfCentral_mod+".tex";
   TFile *f_mod = new TFile(sfCentral_modROOT.c_str(),"RECREATE");
   TH1F *hSF = (TH1F*)hSF_Central->Clone("hSF");
   
   std::string com = "cp "+sfCentralTEX+" "+sfCentral_modTEX;
   system(com.c_str());
   
   int nbins = hSF_Central->GetXaxis()->GetNbins();

   int np = hSFSYS_Central->GetN();
   double x_mod[1000];
   double y_mod[1000];
   
   double *x = &(hSFSYS_Central->GetX());
   double *y = &(hSFSYS_Central->GetY());
   for(int i=0;i<np;i++)
     {
	x_mod[i] = x[i];
     }       
   
   double diffMax[1000];
   for(int ib=1;ib<=nbins;ib++)
     diffMax[ib-1] = 0.;

   double unc[1000];
   
   for(int i=0;i<nrun;i++)
     {	
	std::string sf = "results/SF_"+tag+"_2011FINAL"+ver+"_"+std::string(Form("%d",run[i]))+"_beauty.root";
	TFile *f = TFile::Open(sf.c_str());
	TH1F *hSF = (TH1F*)f->Get("hSF");
	for(int ib=1;ib<=nbins;ib++)
	  {
	     double v0 = hSF_Central->GetBinContent(ib);
	     double v = hSF->GetBinContent(ib);
	     double diff = fabs(v-v0);
	     if( diff > diffMax[ib-1] ) diffMax[ib-1] = diff;
	  }	
     }   

   double uncUp[1000];
   double uncDown[1000];
   
   for(int i=1;i<=nbins;i++)
     {
	double v0 = hSF_Central->GetBinContent(i);
	unc[i-1] = (v0 > 0.) ? fabs(diffMax[i-1]): 0.;
	
	y_mod[i-1] = y[i-1]+diffMax[i-1];       
	if( sum2 )
	  {
	     double dif = y[i-1]-v0;
	     double sum = sqrt(pow(dif,2)+pow(diffMax[i-1],2));
	     y_mod[i-1] = v0+sum;
	  }	

	uncUp[i-1] = y_mod[i-1]-v0;
     }   
   for(int i=1;i<=nbins;i++)
     {
	double v0 = hSF_Central->GetBinContent(nbins-i+1);
	
	y_mod[i-1+nbins] = y[i-1+nbins]-diffMax[nbins-i];
	if( sum2 )
	  {
	     double dif = v0-y[i-1+nbins];
	     double sum = sqrt(pow(dif,2)+pow(diffMax[nbins-i],2));
	     y_mod[i-1+nbins] = v0-sum;
	  }	
	
	uncDown[nbins-i] =v0-y_mod[i-1+nbins];
     }   
   y_mod[np-1] = y_mod[0];

   for(int i=0;i<nbins;i++)
     {	
	std::string com = "sed 's%XXX"+std::string(Form("%d",i))+"XXX%"+std::string(Form("%.3f",unc[i]))+"%g' "+sfCentral_modTEX+" > "+sfCentral_modTEX+".temp";
	system(com.c_str());
	std::string com = "cp "+sfCentral_modTEX+".temp "+sfCentral_modTEX;
	system(com.c_str());

	std::string com = "sed 's%YYY"+std::string(Form("%d",i))+"YYY%"+std::string(Form("%.3f",uncUp[i]))+"%g' "+sfCentral_modTEX+" > "+sfCentral_modTEX+".temp";
	system(com.c_str());
	std::string com = "cp "+sfCentral_modTEX+".temp "+sfCentral_modTEX;
	system(com.c_str());

	std::string com = "sed 's%ZZZ"+std::string(Form("%d",i))+"ZZZ%"+std::string(Form("%.3f",uncDown[i]))+"%g' "+sfCentral_modTEX+" > "+sfCentral_modTEX+".temp";
	system(com.c_str());
	std::string com = "cp "+sfCentral_modTEX+".temp "+sfCentral_modTEX;
	system(com.c_str());
     }   
   
   f_mod->cd();
   TPolyLine *hSFSYS = new TPolyLine(np,x_mod,y_mod);
   hSFSYS->SetFillColor(kYellow);
   
//   for(int i=0;i<np;i++)
//     {
//	std::cout << i << " " << x_mod[i] << " " << y_mod[i] << std::endl;
//     }       

   hSFSYS->Write("hSFSYS");
   hSF_Central->Write("hSF");
   
   f_mod->Close();
   
   gApplication->Terminate();
}
