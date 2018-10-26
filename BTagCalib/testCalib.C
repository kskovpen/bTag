#include "testCalib.h"

#include "BTagCalibrationStandalone.h"

testCalib::testCalib()
{
   BTagCalibration calib = BTagCalibration("deepcsv", "subjet_DeepCSV_94XSF_V3_B_F.csv");
   
   BTagCalibrationReader reader(BTagEntry::OP_MEDIUM,"central",{"up", "down"});

   reader.load(calib,BTagEntry::FLAV_B,"comb");
   reader.load(calib,BTagEntry::FLAV_C,"comb");
   reader.load(calib,BTagEntry::FLAV_UDSG,"incl");
   
   getBtagSF("central",reader);
   getBtagSF("b_up",reader);
   getBtagSF("b_down",reader);
   getBtagSF("l_up",reader);
   getBtagSF("l_down",reader);
}

void testCalib::getBtagSF(std::string sysType, BTagCalibrationReader reader)
{
   std::string b_sysType = "central";
   std::string l_sysType = "central";
   
   if( sysType == "b_up" )
     {
	b_sysType = "up";
     } 
   else if( sysType == "b_down" )
     {
	b_sysType = "down";
     } 
   else if( sysType == "l_up" )
     {
	l_sysType = "up";
     } 
   else if( sysType == "l_down" )
     {
	l_sysType = "down";
     }	
   
   double jetpt = 500;
   double jeteta = 2.0;
   
   double SFb = reader.eval_auto_bounds(b_sysType,BTagEntry::FLAV_B,jeteta,jetpt);
   std::cout << SFb << std::endl;
}

int main()
{
   testCalib();
}
