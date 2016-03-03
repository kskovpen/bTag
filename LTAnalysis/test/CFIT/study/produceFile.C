void produceFile()
{
   gROOT->SetBatch();

   int nTemplate = 3;
   
   TFile *fout = new TFile("test.root","RECREATE");
   
   TFile fin("../../histCFIT/data.root");

   std::string tagName = "CSVT";
   std::string jetName = "h_jSub_JP";
   std::string ptName = "pt430t570_nosel";
   std::string bjetName = jetName+"_bjet_"+ptName+"_nosel";
   std::string bjetNameTag = jetName+"_bjet_"+ptName+"_"+tagName;
   std::string bjetNameUnTag = jetName+"_bjet_"+ptName+"_UNTAG"+tagName;
   std::string cjetName = jetName+"_cjet_"+ptName+"_nosel";
   std::string cjetNameTag = jetName+"_cjet_"+ptName+"_"+tagName;
   std::string cjetNameUnTag = jetName+"_cjet_"+ptName+"_UNTAG"+tagName;
   std::string ljetName = jetName+"_cjet_"+ptName+"_nosel";
   std::string ljetNameTag = jetName+"_cjet_"+ptName+"_"+tagName;
   std::string ljetNameUnTag = jetName+"_cjet_"+ptName+"_UNTAG"+tagName;
   
   // get
   
   TH1D *h_get_mc1 = (TH1D*)fin.Get(bjetName.c_str());
   TH1D *h_get_mc1_tag = (TH1D*)fin.Get(bjetNameTag.c_str());
   TH1D *h_get_mc1_untag = (TH1D*)fin.Get(bjetNameUnTag.c_str());

   TH1D *h_get_mc2 = (TH1D*)fin.Get(cjetName.c_str());
   TH1D *h_get_mc2_tag = (TH1D*)fin.Get(cjetNameTag.c_str());
   TH1D *h_get_mc2_untag = (TH1D*)fin.Get(cjetNameUnTag.c_str());

   TH1D *h_get_mc3 = (TH1D*)fin.Get(ljetName.c_str());
   TH1D *h_get_mc3_tag = (TH1D*)fin.Get(ljetNameTag.c_str());
   TH1D *h_get_mc3_untag = (TH1D*)fin.Get(ljetNameUnTag.c_str());
   
   // clone

   fout->cd();
   
   TH1D *h_mc1 = (TH1D*)h_get_mc1->Clone("h_mc1"); h_mc1->SetName("h_mc1"); h_mc1->SetTitle("h_mc1");
   TH1D *h_mc1_tag = (TH1D*)h_get_mc1_tag->Clone("h_mc1_tag"); h_mc1_tag->SetName("h_mc1_tag"); h_mc1_tag->SetTitle("h_mc1_tag");
   TH1D *h_mc1_untag = (TH1D*)h_get_mc1_untag->Clone("h_mc1_untag"); h_mc1_untag->SetName("h_mc1_untag"); h_mc1_untag->SetTitle("h_mc1_untag");

   TH1D *h_mc2 = (TH1D*)h_get_mc2->Clone("h_mc2"); h_mc2->SetName("h_mc2"); h_mc2->SetTitle("h_mc2");
   TH1D *h_mc2_tag = (TH1D*)h_get_mc2_tag->Clone("h_mc2_tag"); h_mc2_tag->SetName("h_mc2_tag"); h_mc2_tag->SetTitle("h_mc2_tag");
   TH1D *h_mc2_untag = (TH1D*)h_get_mc2_untag->Clone("h_mc2_untag"); h_mc2_untag->SetName("h_mc2_untag"); h_mc2_untag->SetTitle("h_mc2_untag");

   TH1D *h_mc3 = (TH1D*)h_get_mc3->Clone("h_mc3"); h_mc3->SetName("h_mc3"); h_mc3->SetTitle("h_mc3");
   TH1D *h_mc3_tag = (TH1D*)h_get_mc3_tag->Clone("h_mc3_tag"); h_mc3_tag->SetName("h_mc3_tag"); h_mc3_tag->SetTitle("h_mc3_tag");
   TH1D *h_mc3_untag = (TH1D*)h_get_mc3_untag->Clone("h_mc3_untag"); h_mc3_untag->SetName("h_mc3_untag"); h_mc3_untag->SetTitle("h_mc3_untag");
   
   // cook up data
   TH1D *h_data_art = (TH1D*)h_mc1->Clone("h_data_art"); h_data_art->SetName("h_data_art"); h_data_art->SetTitle("h_data_art");
   TH1D *h_data_art_tag = (TH1D*)h_mc1_tag->Clone("h_data_art_tag"); h_data_art_tag->SetName("h_data_art_tag"); h_data_art_tag->SetTitle("h_data_art_tag");
   TH1D *h_data_art_untag = (TH1D*)h_mc1_untag->Clone("h_data_art_untag"); h_data_art_untag->SetName("h_data_art_untag"); h_data_art_untag->SetTitle("h_data_art_untag");
   if( nTemplate >= 2 ) 
     {
	h_data_art->Add(h_mc2,1.);
	h_data_art_tag->Add(h_mc2_tag,1.);
	h_data_art_untag->Add(h_mc2_untag,1.);
     }   
   if( nTemplate >= 3 ) 
     {
	h_data_art->Add(h_mc3,1.);
	h_data_art_tag->Add(h_mc3_tag,1.);
	h_data_art_untag->Add(h_mc3_untag,1.);
     }   
   
   // generate uncertainties in data
   int nBins = h_data_art->GetXaxis()->GetNbins();
   for(int i=0;i<=nBins+1;i++)
     {
	int v = h_data_art->GetBinContent(i);
	double err = sqrt(v);
//	h_data_art->SetBinContent(i,v);
	h_data_art->SetBinError(i,err);

	int v_tag = h_data_art_tag->GetBinContent(i);
	double err_tag = sqrt(v_tag);
//	h_data_art_tag->SetBinContent(i,v_tag);
	h_data_art_tag->SetBinError(i,err_tag);

	int v_untag = h_data_art_untag->GetBinContent(i);
	double err_untag = sqrt(v_untag);
//	h_data_art_untag->SetBinContent(i,v_untag);
	h_data_art_untag->SetBinError(i,err_untag);
     }     
   
   fout->Write();
   fout->Close();
   
   gApplication->Terminate();
}
