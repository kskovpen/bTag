#include "cfit.h"

int main()
{
   for(int i=0;i<10;i++)
//   while(1)
     {
	CFIT::cfit *cf = new CFIT::cfit();
	delete cf;
//	cf->SetData("h_j1_JP_ajet_pt320t400_nosel_nosel__DATA");
	
//	cf->AddTemplate("b-jets","h_j1_JP_bjet_pt320t400_nosel_nosel");
//	cf->AddTemplate("c-jets","h_j1_JP_cjet_pt320t400_nosel_nosel");
//	cf->AddTemplate("udsg-jets","h_j1_JP_ljet_pt320t400_nosel_nosel");
     }   
}
