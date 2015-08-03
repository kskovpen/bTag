void adjustData()
{
   gROOT->SetBatch(1);
   
   TFile *f = TFile::Open("../../histCFIT/DATA/data.root","UPDATE");
   f->cd();
   
   std::string h_dataSys = "h_j1_*_*_*_nosel_*_*;1";
   gDirectory->Delete(h_dataSys.c_str());

   TIter next(f->GetListOfKeys());
   TKey *key;
   while( (key = (TKey*)next()) )
     {
	TClass *cl = gROOT->GetClass(key->GetClassName());
	if( !cl->InheritsFrom("TH1") ) continue;
	TH1 *h = (TH1*)key->ReadObj();
	std::string hname = h->GetName();
	std::size_t found = hname.find("__DATA");
	if( found!=std::string::npos ) continue;
	std::string hnameDATA = hname+"__DATA";
	TH1 *hDATA = (TH1*)h->Clone(hnameDATA.c_str());
	hname += ";1";
	gDirectory->Delete(hname.c_str());
	hDATA->Write();
     }
   
   f->Close();
   
   gApplication->Terminate();
}
