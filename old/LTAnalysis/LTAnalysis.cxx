#include "Hist.h"
#include "HistTTbar.h"

char *fin;
char *foutname;
int isdata;
float noe;
float xsec;
float eff;
int nmax;
int doRW;
int doAnalysis;
bool year2011;
bool sp2011;
/*char *runmode;
char *tool;
int ptrw;
int hst;
int isdata;
char *dsid;
int doPS;
int doBEAM;
int doSPLOT;
int doLUMI;
float cutJVF;
int highPT;*/
/////TTree *tr;
TChain *tr;

LTANA::TreeClass *ntP;
LTANA::TreeClassTTbar *ntPT;

int main(int argc, char *argv[])
{
//   gSystem->Load("/usr/lib64/libdpm.so");
   gSystem->Load("/cvmfs/cms.cern.ch/slc6_amd64_gcc480/external/dpm/1.8.0.1-cms/lib/libdpm.so");
//   gSystem->Load("libdpm.so");
//   gSystem->Load("libFWCoreFWLite.so");
   
   if( argc < 12 )
     {
	std::cout << "Usage: ./sysAna [input file list] [output name] [isdata] [noe] [xsec] [eff] [nmax] [doRW] [doAnalysis] [year] [sp2011]" << std::endl;
	exit(1);
     }
   
   fin = argv[1];
   foutname = argv[2];
   isdata = atoi(argv[3]);
   noe = atof(argv[4]);
   xsec = atof(argv[5]);
   eff = atof(argv[6]);
   nmax = atoi(argv[7]);
   doRW = atoi(argv[8]);
   doAnalysis = atoi(argv[9]);
   char *year = argv[10];
   if( strcmp(year,"2011") == 0 ) year2011 = 1;
   else year2011 = 0;
   sp2011 = atoi(argv[11]);
/*   runmode = argv[3];
   tool = argv[4];
   ptrw = atoi(argv[5]);
   hst = atoi(argv[6]);
   isdata = atoi(argv[7]);
   dsid = argv[8];
   doPS = atoi(argv[9]);
   doLUMI = atoi(argv[10]);
   cutJVF = atof(argv[11]);
   highPT = atof(argv[12]);
   doBEAM = atoi(argv[13]);
   doSPLOT = atoi(argv[14]);
*/   
   std::cout << "Input file list: " << fin <<
     std::endl;

   std::string tpath = "btagana/ttree";
   std::string tpathTTbar = "btagana/ttree";
      
   LTANA::TreeClass FILEIN(0,const_cast<char*>(fin),tpath.c_str());
   LTANA::TreeClassTTbar FILEINTTBAR(0,const_cast<char*>(fin),tpathTTbar.c_str());
   ntP = &FILEIN;
   ntPT = &FILEINTTBAR;
   
//   tr = FILEIN.fChain;
////   TTree *tree = FILEIN.fChain;
   
   if( doAnalysis == 0 )
     {
	tr = FILEIN.fChain;
	ntP->registerInputBranches(tr);
     }   
   if( doAnalysis == 1 )
     {
	tr = FILEINTTBAR.fChain;
	ntPT->registerInputBranches(tr);
     }   
   
/*
   std::vector<JTRUN::Event>                *v_Event                = new std::vector<JTRUN::Event>();
   std::vector<JTRUN::Jet>                  *v_Jet                  = new std::vector<JTRUN::Jet>();
   
   f.SetBranchAddress("Event", &v_Event);
   f.SetBranchAddress("Jet", &v_Jet);
*/   
   LTANA::Hist hist;
   LTANA::HistTTbar histTTbar;

   if( doAnalysis == 0 ) hist.init();
   if( doAnalysis == 1 ) histTTbar.init();
   
   int nent = tr->GetEntries();
   std::cout << nent << std::endl;

   for(int i=0;i<nent;i++)
     {
	if( doAnalysis == 0 ) ntP->GetEntry(i);
	if( doAnalysis == 1 ) ntPT->GetEntry(i);

	if( i > nmax && nmax > 0 ) break;

	if( doAnalysis == 0 ) hist.fill();
	if( doAnalysis == 1 ) histTTbar.fill();
     }
   
   if( doAnalysis == 0 ) hist.close();
   if( doAnalysis == 1 ) histTTbar.close();
}
