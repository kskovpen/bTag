#ifndef FITADJUST_H
#define FITADJUST_H

#include "TMath.h"

void adjust(TH1D *h)
{   
   Int_t x_nbins = h->GetXaxis()->GetNbins();
   for(int ib=0;ib<=x_nbins+1;ib++)
     {
	double v = h->GetBinContent(ib);
	if( v == 0 ) 
	  {
	     h->SetBinContent(ib,1.);
	     h->SetBinError(ib,1.);
	  }	
     }   
}

double* mergeBins(TH1D *h,int ibmin,int ibmax,double xnew[])
{
   bool removeBin = 1;
   
   Int_t x_nbins = h->GetXaxis()->GetNbins();
   
   if( ibmax < x_nbins || ibmin > 1 )
     {	
	double sumMax = 0.;
	double sumErrMax = 0.;

	double sumMin = 0.;
	double sumErrMin = 0.;

	int idx=0;
	for(int ib=1;ib<=ibmax;ib++)
	  {
	     if( ibmin >= ib && ib != 1 ) continue;
	     xnew[idx] = h->GetXaxis()->GetBinLowEdge(ib);
	     idx++;
	  }

	for(int ib=1;ib<=ibmin;ib++)
	  {
	     double v = h->GetBinContent(ib);
	     double err = h->GetBinError(ib);
	     sumMin += v;
	     sumErrMin += err*err;
	     
	     if( removeBin )
	       {		  
		  h->SetBinContent(ib,0.);
		  h->SetBinError(ib,0.);
	       }	    
	  }
	
	for(int ib=ibmax;ib<=x_nbins+1;ib++)
	  {
	     double v = h->GetBinContent(ib);
	     double err = h->GetBinError(ib);
	     sumMax += v;
	     sumErrMax += err*err;
	     
	     if( removeBin )
	       {		  
		  h->SetBinContent(ib,0.);
		  h->SetBinError(ib,0.);
	       }	    
	  }
	
	xnew[idx] = h->GetXaxis()->GetBinUpEdge(x_nbins);
	
	sumErrMin = sqrt(sumErrMin);
	sumErrMax = sqrt(sumErrMax);

	h->SetBinContent(1,sumMin);
	h->SetBinError(1,sumErrMin);
	
	h->SetBinContent(ibmax,sumMax);
	h->SetBinError(ibmax,sumErrMax);
     }
   
   return xnew;
}

void adjustSys(TH1D *hnom,TH1D *hsys_low,TH1D *hsys_up,double* binF,bool dofac)
{
   bool doMorphing = 1;
   
   if( dofac )
     {	
	for(int i=0;i<100;i++)
	  {
	     binF[i] = 1.;
	  }
     }   
   
   Int_t x_nbins = hnom->GetXaxis()->GetNbins();

   double val_max = -666.;
   double sigma_av = 0.;
   double sum = 0.;
   
   for(int i=1;i<=x_nbins;i++)
     {
	double v_nom = hnom->GetBinContent(i);
	double v_sys_low = hsys_low->GetBinContent(i);
	double v_sys_up = hsys_up->GetBinContent(i);

	double sysUp = (v_nom > 0.) ? (v_sys_up-v_nom)/v_nom : 0.;
	double sysDown = (v_nom > 0.) ? (v_nom-v_sys_low)/v_nom : 0.;
	
	double sign = (sysUp > 0) ? 1. : -1.;
	double sigma = (fabs(sysUp) > fabs(sysDown)) ? fabs(sysUp) : fabs(sysDown);
	sum += v_nom;
	sigma_av += sigma*sigma*v_nom;
	sigma *= sign*v_nom;
	
	hsys_up->SetBinContent(i,v_nom+sigma);
	hsys_low->SetBinContent(i,v_nom-sigma);

	if( v_nom > val_max ) val_max = v_nom;

	if( dofac )
	  {	     
	     if( sysUp*sysDown < 0 )
	       {
		  binF[i] = 0.;
	       }	
	  }	
     }
   
   sigma_av = sqrt(sigma_av/sum);

   binF[x_nbins] = 0.;
   
   for(int i1=1;i1<=x_nbins;i1++)
     {
	double v_nom_i1 = hnom->GetBinContent(i1);
	double v_sys_low_i1 = hsys_low->GetBinContent(i1);
	double v_sys_up_i1 = hsys_up->GetBinContent(i1);

	double sysUp_i1 = v_sys_up_i1-v_nom_i1;
	double sysDown_i1 = v_nom_i1-v_sys_low_i1;

	double sysUp_rel_i1 = (v_nom_i1 > 0.) ? sysUp_i1/v_nom_i1 : 0.;
	double sysDown_rel_i1 = (v_nom_i1 > 0.) ? sysDown_i1/v_nom_i1 : 0.;
	
	double signUp_i1 = (sysUp_i1 > 0) ? 1. : -1.;
	double signDown_i1 = (sysDown_i1 > 0) ? 1. : -1.;

	if( dofac )
	  {	     
	     double val_rel = (val_max > 0.) ? v_nom_i1/val_max : 666.;
	     if( val_rel < 0.75 ) binF[i1] = 0.;
	  }	

/*	if( i1 < x_nbins ) 
	  {
	     double v1 = hnom->GetBinContent(i1+1);
	     double val_max_ii1 = std::max(v1,v_nom_i1);
	     double diff = (val_max_ii1 > 0) ? fabs(v1-v_nom_i1)/val_max_ii1 : 0.;
	     if( diff > 0.7 )
	       {
//		  std::cout << i1 << " " << x_nbins << std::endl;
		  for(int i11=i1;i11<=x_nbins;i11++)
		    {		       
		       binF[i11] = 0.;
		       binF[i11+1] = 0.;
		    }		  
	       }	     
	  }*/

	double thres = 0.1*sigma_av;

	if( dofac )
	  {	     
	     bool wasAdjusted = 0;
	     if( fabs(sysUp_rel_i1) < thres ) 
	       {
		  sysUp_i1 = v_nom_i1*signUp_i1*thres;
		  wasAdjusted = 1;
		  if( doMorphing ) binF[i1] = 0.;
	       }
	     if( fabs(sysDown_rel_i1) < thres ) 
	       {
		  sysDown_i1 = v_nom_i1*signDown_i1*thres;
		  wasAdjusted = 1;
		  if( doMorphing ) binF[i1] = 0.;
	       }	
	  }	
	
	if( doMorphing )
	  {	     
	     hsys_up->SetBinContent(i1,v_nom_i1+sysUp_i1);
	     hsys_low->SetBinContent(i1,v_nom_i1-sysDown_i1);
	  }	

	if( i1 < x_nbins )
	  {
	     int i1n = i1+1;

	     double v_nom_i1n = hnom->GetBinContent(i1n);
	     double v_sys_low_i1n = hsys_low->GetBinContent(i1n);
	     double v_sys_up_i1n = hsys_up->GetBinContent(i1n);
	     
	     double sysUp_i1n = v_sys_up_i1n-v_nom_i1n;
	     double sysDown_i1n = v_nom_i1n-v_sys_low_i1n;

/*	     if( sysUp_i1*sysUp_i1n < 0 )
	       {		  		  
		  int ib_begin = i1;
		  int ib_end = (i1+1 <= x_nbins) ? i1+1 : x_nbins;*/
/*		  double sigma_max = -666.;
	
		  for(int i2=ib_begin;i2<=ib_end;i2++)
		    {
		       double v_nom = hnom->GetBinContent(i2);
		       double v_sys_up = (v_nom > 0.) ? fabs(hsys_up->GetBinContent(i2)-v_nom)/v_nom : 0.;
		       if( v_sys_up > sigma_max ) 
			 {
			    sigma_max = v_sys_up;
			 }	     
		    }*/
	
//		  for(int i2=ib_begin;i2<=ib_end;i2++)
//		    {
/*		       double v_nom_i2 = hnom->GetBinContent(i2);
		       double v_sys_low_i2 = hsys_low->GetBinContent(i2);
		       double v_sys_up_i2 = hsys_up->GetBinContent(i2);
		       
		       double sysUp_i2 = v_sys_up_i2-v_nom_i2;
		       double sysDown_i2 = v_nom_i2-v_sys_low_i2;*/
		       
//		       binF[i2] = 0.;
		       
/*		       double nom_up_i2_new = (sysUp_i2 > 0) ? v_nom_i2+v_nom_i2*sigma_max : v_nom_i2-v_nom_i2*sigma_max;		       
		       double nom_low_i2_new = (sysUp_i2 > 0) ? v_nom_i2-v_nom_i2*sigma_max : v_nom_i2+v_nom_i2*sigma_max;
		       
		       hsys_up->SetBinContent(i2,nom_up_i2_new);		       
		       hsys_low->SetBinContent(i2,nom_low_i2_new);*/
//		    }
//	       }
	  }
     }   
}

#endif
