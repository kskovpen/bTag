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

#include "TreeClass.h"
#include "TreeClassTTbar.h"

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

// JES
#include "../CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "../CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"

extern char *fin;
extern char *foutname;
extern int isdata;
extern float noe;
extern float xsec;
extern float eff;
extern int nmax;
extern int doRW;
extern int doAnalysis;
extern bool year2011;
extern bool sp2011;

extern TChain *tr;

extern LTANA::TreeClass *ntP;
extern LTANA::TreeClassTTbar *ntPT;

#endif
