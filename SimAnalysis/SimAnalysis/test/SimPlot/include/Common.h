#ifndef SIMPLOTCOMMON_H
#define SIMPLOTCOMMON_H

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

#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

extern char *fin;
extern char *foutname;

extern TChain *tr;

extern SIMPLOT::Tree *ntP;

extern int nSel;

#endif
