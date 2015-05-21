TLatex* CMSLABEL()
{
   TLatex *text1 = new TLatex(3.14,23.08044,"CMS Preliminary at #sqrt{s} = 8 TeV, 20 fb^{-1}");
   
   text1->SetNDC();
   text1->SetTextAlign(13);
   text1->SetX(0.238);
   text1->SetY(0.928);
   text1->SetTextFont(42);
   text1->SetTextSizePixels(24);
   
   return text1;
}
