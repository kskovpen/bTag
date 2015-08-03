void produceFile()
{
   gROOT->SetBatch();
   
   TFile *fout = new TFile("test.root","RECREATE");
   
   TFile fin("../../histCFIT/data.root");
   
   // get
   
   TH1D *h_get_data = (TH1D*)fin.Get("h_j1_JP_ajet_pt400t500_nosel_nosel__DATA");
   TH1D *h_get_data_tag = (TH1D*)fin.Get("h_j1_JP_ajet_pt400t500_nosel_CSVL__DATA");
   TH1D *h_get_data_untag = (TH1D*)fin.Get("h_j1_JP_ajet_pt400t500_nosel_UNTAGCSVL__DATA");

   TH1D *h_get_mc1 = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_nosel");
   TH1D *h_get_mc1_sys1_down = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_nosel_gsplit_down");
   TH1D *h_get_mc1_sys1_up = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_nosel_gsplit_up");
   TH1D *h_get_mc1_sys2_down = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_nosel_ntrkgen_down");
   TH1D *h_get_mc1_sys2_up = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_nosel_ntrkgen_up");
   TH1D *h_get_mc1_tag = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_CSVL");
   TH1D *h_get_mc1_tag_sys1_down = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_CSVL_gsplit_down");
   TH1D *h_get_mc1_tag_sys1_up = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_CSVL_gsplit_up");
   TH1D *h_get_mc1_tag_sys2_down = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_CSVL_ntrkgen_down");
   TH1D *h_get_mc1_tag_sys2_up = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_CSVL_ntrkgen_up");
   TH1D *h_get_mc1_untag = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_UNTAGCSVL");
   TH1D *h_get_mc1_untag_sys1_down = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_UNTAGCSVL_gsplit_down");
   TH1D *h_get_mc1_untag_sys1_up = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_UNTAGCSVL_gsplit_up");
   TH1D *h_get_mc1_untag_sys2_down = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_UNTAGCSVL_ntrkgen_down");
   TH1D *h_get_mc1_untag_sys2_up = (TH1D*)fin.Get("h_j1_JP_bjet_pt400t500_nosel_UNTAGCSVL_ntrkgen_up");

   TH1D *h_get_mc2 = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_nosel");
   TH1D *h_get_mc2_sys1_down = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_nosel_gsplit_down");
   TH1D *h_get_mc2_sys1_up = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_nosel_gsplit_up");
   TH1D *h_get_mc2_sys2_down = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_nosel_ntrkgen_down");
   TH1D *h_get_mc2_sys2_up = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_nosel_ntrkgen_up");
   TH1D *h_get_mc2_tag = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_CSVL");
   TH1D *h_get_mc2_tag_sys1_down = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_CSVL_gsplit_down");
   TH1D *h_get_mc2_tag_sys1_up = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_CSVL_gsplit_up");
   TH1D *h_get_mc2_tag_sys2_down = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_CSVL_ntrkgen_down");
   TH1D *h_get_mc2_tag_sys2_up = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_CSVL_ntrkgen_up");
   TH1D *h_get_mc2_untag = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_UNTAGCSVL");
   TH1D *h_get_mc2_untag_sys1_down = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_UNTAGCSVL_gsplit_down");
   TH1D *h_get_mc2_untag_sys1_up = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_UNTAGCSVL_gsplit_up");
   TH1D *h_get_mc2_untag_sys2_down = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_UNTAGCSVL_ntrkgen_down");
   TH1D *h_get_mc2_untag_sys2_up = (TH1D*)fin.Get("h_j1_JP_cjet_pt400t500_nosel_UNTAGCSVL_ntrkgen_up");

   TH1D *h_get_mc3 = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_nosel");
   TH1D *h_get_mc3_sys1_down = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_nosel_gsplit_down");
   TH1D *h_get_mc3_sys1_up = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_nosel_gsplit_up");
   TH1D *h_get_mc3_sys2_down = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_nosel_ntrkgen_down");
   TH1D *h_get_mc3_sys2_up = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_nosel_ntrkgen_up");
   TH1D *h_get_mc3_tag = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_CSVL");
   TH1D *h_get_mc3_tag_sys1_down = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_CSVL_gsplit_down");
   TH1D *h_get_mc3_tag_sys1_up = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_CSVL_gsplit_up");
   TH1D *h_get_mc3_tag_sys2_down = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_CSVL_ntrkgen_down");
   TH1D *h_get_mc3_tag_sys2_up = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_CSVL_ntrkgen_up");
   TH1D *h_get_mc3_untag = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_UNTAGCSVL");
   TH1D *h_get_mc3_untag_sys1_down = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_UNTAGCSVL_gsplit_down");
   TH1D *h_get_mc3_untag_sys1_up = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_UNTAGCSVL_gsplit_up");
   TH1D *h_get_mc3_untag_sys2_down = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_UNTAGCSVL_ntrkgen_down");
   TH1D *h_get_mc3_untag_sys2_up = (TH1D*)fin.Get("h_j1_JP_ljet_pt400t500_nosel_UNTAGCSVL_ntrkgen_up");
   
   // clone

   fout->cd();
   
   TH1D *h_data = (TH1D*)h_get_data->Clone("h_data"); h_data->SetName("h_data"); h_data->SetTitle("h_data");
   TH1D *h_data_tag = (TH1D*)h_get_data_tag->Clone("h_data_tag"); h_data_tag->SetName("h_data_tag"); h_data_tag->SetTitle("h_data_tag");
   TH1D *h_data_untag = (TH1D*)h_get_data_untag->Clone("h_data_untag"); h_data_untag->SetName("h_data_untag"); h_data_untag->SetTitle("h_data_untag");

   TH1D *h_mc1 = (TH1D*)h_get_mc1->Clone("h_mc1"); h_mc1->SetName("h_mc1"); h_mc1->SetTitle("h_mc1");
   TH1D *h_mc1_sys1_down = (TH1D*)h_get_mc1_sys1_down->Clone("h_mc1_sys1_down"); h_mc1_sys1_down->SetName("h_mc1_sys1_down"); h_mc1_sys1_down->SetTitle("h_mc1_sys1_down");
   TH1D *h_mc1_sys1_up = (TH1D*)h_get_mc1_sys1_up->Clone("h_mc1_sys1_up"); h_mc1_sys1_up->SetName("h_mc1_sys1_up"); h_mc1_sys1_up->SetTitle("h_mc1_sys1_up");
   TH1D *h_mc1_sys2_down = (TH1D*)h_get_mc1_sys2_down->Clone("h_mc1_sys2_down"); h_mc1_sys2_down->SetName("h_mc1_sys2_down"); h_mc1_sys2_down->SetTitle("h_mc1_sys2_down");
   TH1D *h_mc1_sys2_up = (TH1D*)h_get_mc1_sys2_up->Clone("h_mc1_sys2_up"); h_mc1_sys2_up->SetName("h_mc1_sys2_up"); h_mc1_sys2_up->SetTitle("h_mc1_sys2_up");
   TH1D *h_mc1_tag = (TH1D*)h_get_mc1_tag->Clone("h_mc1_tag"); h_mc1_tag->SetName("h_mc1_tag"); h_mc1_tag->SetTitle("h_mc1_tag");
   TH1D *h_mc1_tag_sys1_down = (TH1D*)h_get_mc1_tag_sys1_down->Clone("h_mc1_tag_sys1_down"); h_mc1_tag_sys1_down->SetName("h_mc1_tag_sys1_down"); h_mc1_tag_sys1_down->SetTitle("h_mc1_tag_sys1_down");
   TH1D *h_mc1_tag_sys1_up = (TH1D*)h_get_mc1_tag_sys1_up->Clone("h_mc1_tag_sys1_up"); h_mc1_tag_sys1_up->SetName("h_mc1_tag_sys1_up"); h_mc1_tag_sys1_up->SetTitle("h_mc1_tag_sys1_up");
   TH1D *h_mc1_tag_sys2_down = (TH1D*)h_get_mc1_tag_sys2_down->Clone("h_mc1_tag_sys2_down"); h_mc1_tag_sys2_down->SetName("h_mc1_tag_sys2_down"); h_mc1_tag_sys2_down->SetTitle("h_mc1_tag_sys2_down");
   TH1D *h_mc1_tag_sys2_up = (TH1D*)h_get_mc1_tag_sys2_up->Clone("h_mc1_tag_sys2_up"); h_mc1_tag_sys2_up->SetName("h_mc1_tag_sys2_up"); h_mc1_tag_sys2_up->SetTitle("h_mc1_tag_sys2_up");
   TH1D *h_mc1_untag = (TH1D*)h_get_mc1_untag->Clone("h_mc1_untag"); h_mc1_untag->SetName("h_mc1_untag"); h_mc1_untag->SetTitle("h_mc1_untag");
   TH1D *h_mc1_untag_sys1_down = (TH1D*)h_get_mc1_untag_sys1_down->Clone("h_mc1_untag_sys1_down"); h_mc1_untag_sys1_down->SetName("h_mc1_untag_sys1_down"); h_mc1_untag_sys1_down->SetTitle("h_mc1_untag_sys1_down");
   TH1D *h_mc1_untag_sys1_up = (TH1D*)h_get_mc1_untag_sys1_up->Clone("h_mc1_untag_sys1_up"); h_mc1_untag_sys1_up->SetName("h_mc1_untag_sys1_up"); h_mc1_untag_sys1_up->SetTitle("h_mc1_untag_sys1_up");
   TH1D *h_mc1_untag_sys2_down = (TH1D*)h_get_mc1_untag_sys2_down->Clone("h_mc1_untag_sys2_down"); h_mc1_untag_sys2_down->SetName("h_mc1_untag_sys2_down"); h_mc1_untag_sys2_down->SetTitle("h_mc1_untag_sys2_down");
   TH1D *h_mc1_untag_sys2_up = (TH1D*)h_get_mc1_untag_sys2_up->Clone("h_mc1_untag_sys2_up"); h_mc1_untag_sys2_up->SetName("h_mc1_untag_sys2_up"); h_mc1_untag_sys2_up->SetTitle("h_mc1_untag_sys2_up");

   TH1D *h_mc2 = (TH1D*)h_get_mc2->Clone("h_mc2"); h_mc2->SetName("h_mc2"); h_mc2->SetTitle("h_mc2");
   TH1D *h_mc2_sys1_down = (TH1D*)h_get_mc2_sys1_down->Clone("h_mc2_sys1_down"); h_mc2_sys1_down->SetName("h_mc2_sys1_down"); h_mc2_sys1_down->SetTitle("h_mc2_sys1_down");
   TH1D *h_mc2_sys1_up = (TH1D*)h_get_mc2_sys1_up->Clone("h_mc2_sys1_up"); h_mc2_sys1_up->SetName("h_mc2_sys1_up"); h_mc2_sys1_up->SetTitle("h_mc2_sys1_up");
   TH1D *h_mc2_sys2_down = (TH1D*)h_get_mc2_sys2_down->Clone("h_mc2_sys2_down"); h_mc2_sys2_down->SetName("h_mc2_sys2_down"); h_mc2_sys2_down->SetTitle("h_mc2_sys2_down");
   TH1D *h_mc2_sys2_up = (TH1D*)h_get_mc2_sys2_up->Clone("h_mc2_sys2_up"); h_mc2_sys2_up->SetName("h_mc2_sys2_up"); h_mc2_sys2_up->SetTitle("h_mc2_sys2_up");
   TH1D *h_mc2_tag = (TH1D*)h_get_mc2_tag->Clone("h_mc2_tag"); h_mc2_tag->SetName("h_mc2_tag"); h_mc2_tag->SetTitle("h_mc2_tag");
   TH1D *h_mc2_tag_sys1_down = (TH1D*)h_get_mc2_tag_sys1_down->Clone("h_mc2_tag_sys1_down"); h_mc2_tag_sys1_down->SetName("h_mc2_tag_sys1_down"); h_mc2_tag_sys1_down->SetTitle("h_mc2_tag_sys1_down");
   TH1D *h_mc2_tag_sys1_up = (TH1D*)h_get_mc2_tag_sys1_up->Clone("h_mc2_tag_sys1_up"); h_mc2_tag_sys1_up->SetName("h_mc2_tag_sys1_up"); h_mc2_tag_sys1_up->SetTitle("h_mc2_tag_sys1_up");
   TH1D *h_mc2_tag_sys2_down = (TH1D*)h_get_mc2_tag_sys2_down->Clone("h_mc2_tag_sys2_down"); h_mc2_tag_sys2_down->SetName("h_mc2_tag_sys2_down"); h_mc2_tag_sys2_down->SetTitle("h_mc2_tag_sys2_down");
   TH1D *h_mc2_tag_sys2_up = (TH1D*)h_get_mc2_tag_sys2_up->Clone("h_mc2_tag_sys2_up"); h_mc2_tag_sys2_up->SetName("h_mc2_tag_sys2_up"); h_mc2_tag_sys2_up->SetTitle("h_mc2_tag_sys2_up");
   TH1D *h_mc2_untag = (TH1D*)h_get_mc2_untag->Clone("h_mc2_untag"); h_mc2_untag->SetName("h_mc2_untag"); h_mc2_untag->SetTitle("h_mc2_untag");
   TH1D *h_mc2_untag_sys1_down = (TH1D*)h_get_mc2_untag_sys1_down->Clone("h_mc2_untag_sys1_down"); h_mc2_untag_sys1_down->SetName("h_mc2_untag_sys1_down"); h_mc2_untag_sys1_down->SetTitle("h_mc2_untag_sys1_down");
   TH1D *h_mc2_untag_sys1_up = (TH1D*)h_get_mc2_untag_sys1_up->Clone("h_mc2_untag_sys1_up"); h_mc2_untag_sys1_up->SetName("h_mc2_untag_sys1_up"); h_mc2_untag_sys1_up->SetTitle("h_mc2_untag_sys1_up");
   TH1D *h_mc2_untag_sys2_down = (TH1D*)h_get_mc2_untag_sys2_down->Clone("h_mc2_untag_sys2_down"); h_mc2_untag_sys2_down->SetName("h_mc2_untag_sys2_down"); h_mc2_untag_sys2_down->SetTitle("h_mc2_untag_sys2_down");
   TH1D *h_mc2_untag_sys2_up = (TH1D*)h_get_mc2_untag_sys2_up->Clone("h_mc2_untag_sys2_up"); h_mc2_untag_sys2_up->SetName("h_mc2_untag_sys2_up"); h_mc2_untag_sys2_up->SetTitle("h_mc2_untag_sys2_up");

   TH1D *h_mc3 = (TH1D*)h_get_mc3->Clone("h_mc3"); h_mc3->SetName("h_mc3"); h_mc3->SetTitle("h_mc3");
   TH1D *h_mc3_sys1_down = (TH1D*)h_get_mc3_sys1_down->Clone("h_mc3_sys1_down"); h_mc3_sys1_down->SetName("h_mc3_sys1_down"); h_mc3_sys1_down->SetTitle("h_mc3_sys1_down");
   TH1D *h_mc3_sys1_up = (TH1D*)h_get_mc3_sys1_up->Clone("h_mc3_sys1_up"); h_mc3_sys1_up->SetName("h_mc3_sys1_up"); h_mc3_sys1_up->SetTitle("h_mc3_sys1_up");
   TH1D *h_mc3_sys2_down = (TH1D*)h_get_mc3_sys2_down->Clone("h_mc3_sys2_down"); h_mc3_sys2_down->SetName("h_mc3_sys2_down"); h_mc3_sys2_down->SetTitle("h_mc3_sys2_down");
   TH1D *h_mc3_sys2_up = (TH1D*)h_get_mc3_sys2_up->Clone("h_mc3_sys2_up"); h_mc3_sys2_up->SetName("h_mc3_sys2_up"); h_mc3_sys2_up->SetTitle("h_mc3_sys2_up");
   TH1D *h_mc3_tag = (TH1D*)h_get_mc3_tag->Clone("h_mc3_tag"); h_mc3_tag->SetName("h_mc3_tag"); h_mc3_tag->SetTitle("h_mc3_tag");
   TH1D *h_mc3_tag_sys1_down = (TH1D*)h_get_mc3_tag_sys1_down->Clone("h_mc3_tag_sys1_down"); h_mc3_tag_sys1_down->SetName("h_mc3_tag_sys1_down"); h_mc3_tag_sys1_down->SetTitle("h_mc3_tag_sys1_down");
   TH1D *h_mc3_tag_sys1_up = (TH1D*)h_get_mc3_tag_sys1_up->Clone("h_mc3_tag_sys1_up"); h_mc3_tag_sys1_up->SetName("h_mc3_tag_sys1_up"); h_mc3_tag_sys1_up->SetTitle("h_mc3_tag_sys1_up");
   TH1D *h_mc3_tag_sys2_down = (TH1D*)h_get_mc3_tag_sys2_down->Clone("h_mc3_tag_sys2_down"); h_mc3_tag_sys2_down->SetName("h_mc3_tag_sys2_down"); h_mc3_tag_sys2_down->SetTitle("h_mc3_tag_sys2_down");
   TH1D *h_mc3_tag_sys2_up = (TH1D*)h_get_mc3_tag_sys2_up->Clone("h_mc3_tag_sys2_up"); h_mc3_tag_sys2_up->SetName("h_mc3_tag_sys2_up"); h_mc3_tag_sys2_up->SetTitle("h_mc3_tag_sys2_up");
   TH1D *h_mc3_untag = (TH1D*)h_get_mc3_untag->Clone("h_mc3_untag"); h_mc3_untag->SetName("h_mc3_untag"); h_mc3_untag->SetTitle("h_mc3_untag");
   TH1D *h_mc3_untag_sys1_down = (TH1D*)h_get_mc3_untag_sys1_down->Clone("h_mc3_untag_sys1_down"); h_mc3_untag_sys1_down->SetName("h_mc3_untag_sys1_down"); h_mc3_untag_sys1_down->SetTitle("h_mc3_untag_sys1_down");
   TH1D *h_mc3_untag_sys1_up = (TH1D*)h_get_mc3_untag_sys1_up->Clone("h_mc3_untag_sys1_up"); h_mc3_untag_sys1_up->SetName("h_mc3_untag_sys1_up"); h_mc3_untag_sys1_up->SetTitle("h_mc3_untag_sys1_up");
   TH1D *h_mc3_untag_sys2_down = (TH1D*)h_get_mc3_untag_sys2_down->Clone("h_mc3_untag_sys2_down"); h_mc3_untag_sys2_down->SetName("h_mc3_untag_sys2_down"); h_mc3_untag_sys2_down->SetTitle("h_mc3_untag_sys2_down");
   TH1D *h_mc3_untag_sys2_up = (TH1D*)h_get_mc3_untag_sys2_up->Clone("h_mc3_untag_sys2_up"); h_mc3_untag_sys2_up->SetName("h_mc3_untag_sys2_up"); h_mc3_untag_sys2_up->SetTitle("h_mc3_untag_sys2_up");
   
   fout->Write();
   fout->Close();
   
   gApplication->Terminate();
}
