double errf(double v1,double ve1,double v2,double ve2);

void getCb()
{
   std::string flav = "bjet";
   
   gROOT->SetBatch();

   std::string hdir = "histMJALL_MERGED";
   
   const int nf = 11;
   TFile *fMC[nf];
   std::string fname[nf] = 
     {
	"/Pt-15to20_JPCalib/data.root",
	"/Pt-20to30_JPCalib/data.root",
	"/Pt-30to50_JPCalib/data.root",
	"/Pt-50to80_JPCalib/data.root",
	"/Pt-80to120_JPCalib/data.root",
	"/Pt-120to170_JPCalib/data.root",
	"/Pt-170to300_JPCalib/data.root",
	"/Pt-300to470_JPCalib/data.root",
	"/Pt-470to600_JPCalib/data.root",
	"/Pt-600to800_JPCalib/data.root",
	"/Pt-800to1000_JPCalib/data.root"
     };

   const int nbtag = 2;
   std::string btagname[nbtag] =
     {
	"nosel",
	"CSVT"
     };   

   const int npt = 8;
   std::string ptname[npt] = 
     {
	"pt20t30",
	"pt30t50",
	"pt50t70",
	"pt70t100",
	"pt100t140",
	"pt140t200",
	"pt200t300",
	"pt300t670"
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

   const int xb = 9;
   double xax[xb] = 
     {0.02,0.03,0.05,0.07,0.10,0.14,0.20,0.30,0.67};
   
   std::string fcb;

   for(int ibtag=1;ibtag<nbtag;ibtag++)
     {	
	if( flav == "bjet" ) 
	  {
	     fcb = "CbFactor/cb_"+btagname[ibtag]+"_bjet.txt";
	  }   
	else
	  {
	     fcb = "CbFactor/cb_"+btagname[ibtag]+"_cjet.txt";
	  }   
   
	std::ofstream f_cb(fcb.c_str());
	
	for(int ipt=0;ipt<npt;ipt++)
	  {
	     double err0_nosel, errint_nosel;
	     double err0_btag, errint_btag;
	     
	     int nb = h_bjets[ipt][0]->GetXaxis()->GetNbins();
	     
	     double v0_nosel = h_bjets[ipt][0]->IntegralAndError(1,nb+1,err0_nosel);
	     double vint_nosel = h_bjets[ipt][0]->IntegralAndError(0,nb+1,errint_nosel);
	     
	     double v0_btag = h_bjets[ipt][ibtag]->IntegralAndError(1,nb+1,err0_btag);
	     double vint_btag = h_bjets[ipt][ibtag]->IntegralAndError(0,nb+1,errint_btag);
	
	     double cb = v0_nosel/v0_btag*vint_btag/vint_nosel;
	     double cberr = errf(v0_btag,err0_btag,vint_btag,errint_btag);
	     
	     f_cb << ipt << " " << cb << " " << cberr*cb << std::endl;
	  }

	f_cb.close();
     }
   
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
