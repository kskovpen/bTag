std::string toolDATA = "plot_PROC_PS_LATEST";
std::string fpathDATA = "/gcf/atlas/data/JTNtuple_hist/run_"+toolDATA+"/";

float LUMI0 = 20190.1;

void calcLUMIPRESCALE()
{   
   gROOT->SetBatch();
   gROOT->SetStyle("Plain");
   
   gStyle->SetOptStat(0);
   
   gROOT->ProcessLine(".x common.C");
   gROOT->ProcessLine(".x def.C");

   float jPt;
   int jPtBin;
   float PRESCALE;
   
   TChain tch("treePRESCALE");
   tch.SetBranchAddress("jPt",&jPt);
   tch.SetBranchAddress("jPtBin",&jPtBin);
   tch.SetBranchAddress("PRESCALE",&PRESCALE);
   
   for(int i=0;i<v_data.size();i++)
     {	
	std::string fname_DATA = fpathDATA+v_data.at(i);
	
	tch.Add(fname_DATA.c_str());
     }

   int ib = 20;

   std:vector<float> PSsum;   
   PSsum.reserve(ib);
   for(int i=0;i<ib;i++)
     {
	PSsum.push_back(0.);
     }   

   std:vector<float> Nsum;
   Nsum.reserve(ib);
   for(int i=0;i<ib;i++)
     {
	Nsum.push_back(0.);
     }   
   
   int nev = tch.GetEntries();
   for(int i=0;i<nev;i++)
     {
	tch.GetEntry(i);
	PSsum[jPtBin] += PRESCALE;
	Nsum[jPtBin] ++;
     }   

   std::ofstream fout("LUMIPRESCALE.txt");
   
   for(int i=0;i<PSsum.size();i++)
     {
	float SF = (PSsum[i] > 0.) ? Nsum[i]/PSsum[i] : 0.;
	float LUMI = LUMI0*SF;
	std::cout << "BIN=" << i <<
	  "     LUMI=" << LUMI <<
	  "/pb     SF=" << SF <<
	  std::endl;
	fout << i << " " << SF << std::endl;
     }   
   
   fout.close();

   gApplication->Terminate();
}

