#include "../include/Origin.h"

char *fin;
char *foutname;
TChain *tr;
int nSel;

SIMPLOT::Tree *ntP;

int main(int argc, char *argv[])
{
   if( argc < 3 )
     {
	std::cout << "Usage: ./simPlot [input file list] [output name]" << std::endl;
	exit(1);
     }
   
   fin = argv[1];
   foutname = argv[2];

   std::cout << "Input file list: " << fin <<
     std::endl;

   std::string tpath = "SimTree/tree";

   SIMPLOT::Tree FILEIN(0,const_cast<char*>(fin),tpath.c_str());
   ntP = &FILEIN;

   tr = FILEIN.fChain;
   ntP->registerInputBranches(tr);
   
   SIMPLOT::Origin orig;
   
   orig.init();
   
   int nent = tr->GetEntries();
   std::cout << nent << std::endl;
   
   for(int i=0;i<nent;i++)
     {
	ntP->GetEntry(i);
	
	orig.fill();
     }
   
   std::cout << nSel << std::endl;
   
   orig.close();
}
