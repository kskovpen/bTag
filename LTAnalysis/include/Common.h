#ifndef LTANACOMMON_H
#define LTANACOMMON_H

#include "TSystem.h"
#include "TFile.h"
#include "TChain.h"
#include "Riostream.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH3F.h"
#include "TRandom3.h"
#include "TLorentzVector.h"

#include "Tree.h"
#include "Syst.h"
#include "Reweight.h"

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

extern char *fin;
extern char *foutname;
extern int isdata;
extern float noe;
extern float xsec;
extern float eff;
extern int nmax;
extern int doRW;
extern char* tool;

extern TChain *tr;

extern LTANA::Tree *ntP;

#endif
