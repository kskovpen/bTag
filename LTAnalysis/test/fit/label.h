#ifndef LABEL_H
#define LABEL_H

std::string ptlabel(std::string l)
{   
   std::string ptl = "P_{T}";
   
   if( strcmp(l.c_str(),"nosel") == 0 ) ptl+=" 20-1400 GeV";
   else if( strcmp(l.c_str(),"pt20t30") == 0 ) ptl+=" 20-30 GeV";
   else if( strcmp(l.c_str(),"pt30t40") == 0 ) ptl+=" 30-40 GeV";
   else if( strcmp(l.c_str(),"pt40t50") == 0 ) ptl+=" 40-50 GeV";
   else if( strcmp(l.c_str(),"pt50t60") == 0 ) ptl+=" 50-60 GeV";
   else if( strcmp(l.c_str(),"pt60t70") == 0 ) ptl+=" 60-70 GeV";
   else if( strcmp(l.c_str(),"pt70t80") == 0 ) ptl+=" 70-80 GeV";
   else if( strcmp(l.c_str(),"pt80t100") == 0 ) ptl+=" 80-100 GeV";
   else if( strcmp(l.c_str(),"pt100t120") == 0 ) ptl+=" 100-120 GeV";
   else if( strcmp(l.c_str(),"pt120t160") == 0 ) ptl+=" 120-160 GeV";
   else if( strcmp(l.c_str(),"pt160t210") == 0 ) ptl+=" 160-210 GeV";
   else if( strcmp(l.c_str(),"pt210t260") == 0 ) ptl+=" 210-260 GeV";
   else if( strcmp(l.c_str(),"pt260t320") == 0 ) ptl+=" 260-320 GeV";
   else if( strcmp(l.c_str(),"pt320t400") == 0 ) ptl+=" 320-400 GeV";
   else if( strcmp(l.c_str(),"pt400t500") == 0 ) ptl+=" 400-500 GeV";
   else if( strcmp(l.c_str(),"pt500t600") == 0 ) ptl+=" 500-600 GeV";
   else if( strcmp(l.c_str(),"pt600t800") == 0 ) ptl+=" 600-800 GeV";
   else if( strcmp(l.c_str(),"pt800t1000") == 0 ) ptl+=" 800-1000 GeV";
   else if( strcmp(l.c_str(),"pt1000t1400") == 0 ) ptl+=" 1000-1400 GeV";
   
   else if( strcmp(l.c_str(),"pt500t670") == 0 ) ptl+=" 500-670 GeV";
   else if( strcmp(l.c_str(),"pt670t1000") == 0 ) ptl+=" 670-1000 GeV";
   
   else if( strcmp(l.c_str(),"pt30t50") == 0 ) ptl+=" 30-50 GeV";
   else if( strcmp(l.c_str(),"pt50t80") == 0 ) ptl+=" 50-80 GeV";
   else if( strcmp(l.c_str(),"pt80t120") == 0 ) ptl+=" 80-120 GeV";
   else if( strcmp(l.c_str(),"pt120t210") == 0 ) ptl+=" 120-210 GeV";
   else if( strcmp(l.c_str(),"pt210t320") == 0 ) ptl+=" 210-320 GeV";
   else if( strcmp(l.c_str(),"pt320t500") == 0 ) ptl+=" 320-500 GeV";
   else if( strcmp(l.c_str(),"pt500t800") == 0 ) ptl+=" 500-800 GeV";

   else if( strcmp(l.c_str(),"pt20t40") == 0 ) ptl+=" 20-40 GeV";
   else if( strcmp(l.c_str(),"pt40t60") == 0 ) ptl+=" 40-60 GeV";
   else if( strcmp(l.c_str(),"pt60t80") == 0 ) ptl+=" 60-80 GeV";
   else if( strcmp(l.c_str(),"pt80t120") == 0 ) ptl+=" 80-120 GeV";
   else if( strcmp(l.c_str(),"pt120t210") == 0 ) ptl+=" 120-210 GeV";
   else if( strcmp(l.c_str(),"pt210t500") == 0 ) ptl+=" 210-500 GeV";
   else if( strcmp(l.c_str(),"pt500t1000") == 0 ) ptl+=" 500-1000 GeV";
   else if( strcmp(l.c_str(),"pt1000t1400") == 0 ) ptl+=" 1000-1400 GeV";
   
   else
     {
	std::cout << "Pt bin is unknown to create a label" << std::endl;
	exit(1);
     }   
   
   return ptl;
}

#endif
