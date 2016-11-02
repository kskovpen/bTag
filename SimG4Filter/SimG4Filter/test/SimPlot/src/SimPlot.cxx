#include "../include/Hist.h"

char *fin;
char *foutname;
TChain *tr;
int runOnReco;

SIMPLOT::Tree *ntP;

int main(int argc, char *argv[])
{
   if( argc < 4 )
     {
	std::cout << "Usage: ./simPlot [input file list] [output name] [runOnReco]" << std::endl;
	exit(1);
     }
   
   fin = argv[1];
   foutname = argv[2];
   runOnReco = atoi(argv[3]);

   std::cout << "Input file list: " << fin <<
     std::endl;
   std::cout << "RunOnReco=" << runOnReco << std::endl;

   std::string tpath = "SimTree/tree";

   SIMPLOT::Tree FILEIN(0,const_cast<char*>(fin),tpath.c_str());
   ntP = &FILEIN;

   tr = FILEIN.fChain;
   ntP->registerInputBranches(tr);
   
   SIMPLOT::Hist hist;
   
   hist.init();
   
   int nent = tr->GetEntries();
   std::cout << nent << std::endl;
   
   for(int i=0;i<nent;i++)
     {
	ntP->GetEntry(i);
	
	hist.fill();
     }
   
   hist.close();
}
