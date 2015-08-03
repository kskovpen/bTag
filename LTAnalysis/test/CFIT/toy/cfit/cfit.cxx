#include "cfit.h"

ClassImp(CFIT::cfit)

CFIT::cfit::cfit()
{
   dfile = TFile::Open("../../histCFIT/data.root","READ");
   TH1D *hdNOM = (TH1D*)dfile->Get("h_j1_JP_ajet_pt500t670_nosel_UNTAGCSVL__DATA");
   std::string hdcopyNOM = "NOMcopy";
   h_data = (TH1D*)(hdNOM->Clone(hdcopyNOM.c_str()));
//   h_data = std::unique_ptr<TH1D>( (static_cast<TH1D*>(hdNOM->Clone(hdcopyNOM.c_str()))) );
   delete hdNOM;
}

CFIT::cfit::~cfit()
{
   delete h_data;
//   h_data.reset();
   dfile->Close();
   delete dfile;
}
