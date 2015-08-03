#include "../include/Hist.h"
#include "../include/Trigger.h"

char *fin;
char *foutname;
int isdata;
float noe;
float xsec;
float eff;
int nmax;
int doRW;
TChain *tr;
char *tool;

LTANA::Tree *ntP;

int main(int argc, char *argv[])
{
   if( argc < 10 )
     {
	std::cout << "Usage: ./sysAna [input file list] [output name] [isdata] [noe] [xsec] [eff] [nmax] [doRW] [tool]" << std::endl;
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
   tool = argv[9];

   std::cout << "Input file list: " << fin <<
     std::endl;

   std::string tpath = "btagana/ttree";
      
   LTANA::Tree FILEIN(0,const_cast<char*>(fin),tpath.c_str());
   ntP = &FILEIN;
   
   tr = FILEIN.fChain;
   ntP->registerInputBranches(tr);

   if( strcmp(tool,"Hist") == 0 )
     {	
	LTANA::Hist hist;
	
	hist.init();
	
	int nent = tr->GetEntries();
	std::cout << nent << std::endl;
	
	for(int i=0;i<nent;i++)
	  {
	     ntP->GetEntry(i);
	     
	     if( i > nmax && nmax > 0 ) break;
	     
	     hist.fill();
	  }
   
	hist.close();
     }
   else if( strcmp(tool,"Trigger") == 0 )
     {
	LTANA::Trigger trig;
	
	trig.init();
	
	int nent = tr->GetEntries();
	std::cout << nent << std::endl;
	
	for(int i=0;i<nent;i++)
	  {
	     ntP->GetEntry(i);
	     
	     if( i > nmax && nmax > 0 ) break;
	     
	     trig.fill();
	  }
   
	trig.close();
     }  
   else
     {
	std::cout << "Tool " << tool << " does not exist" << std::endl;
	exit(1);
     }   
}
