#ifndef LTANAHELPER_H
#define LTANAHELPER_H

namespace LTANA
{
   
   class Helper
     {

      public:
	Helper();
	virtual ~Helper();
	
	float DeltaR(float eta1,float phi1,float eta2,float phi2);
     };
}

#endif
