#include <iostream>
#include <fstream>
#include <cmath>
#include "prokudin.hpp"
using namespace std;


#define alpha 1.0/137.0
#define Mp 0.938272
//#define beam_energy 5.8913 // GeV
#define beam_energy 5.498 // GeV
void cross_SIDIS()
{
  sidis::ProkudinSfSet sf;

  double x = 0.420;
  double Q_sq = 1.82; // light green 3.08
  double z = 0.224;
  //	double ph_t=;
  double ph_t_sq = 0.023;


  //double F11=sf.F_UUT(sidis::Hadron::PI_P, x, z, Q_sq, ph_t_sq);
  cout<<sf.F_UUT(sidis::Hadron::PI_P, x, z, Q_sq, ph_t_sq)<<endl;
  
  double F12=  sf.F_UU_cos_phih(sidis::Hadron::PI_P, x, z, Q_sq, ph_t_sq);
  double F13= sf.F_UU_cos_2phih(sidis::Hadron::PI_P, x, z, Q_sq, ph_t_sq);
  cout<<F11<<"   "<<F12<<"   "<<F13<<endl;
 
  //<<std::endl;
  // double dsigma, const_term,dsigma1, dsigma2,dsigma3;
  // //double phi_h=3.10;
  // double phi_h=-150;
  // double phi_h_rad=phi_h*TMath::DegToRad();
  // double hcut_c=0.197326;
  // double conversion_ub=1e4*pow(hcut_c,2.0); //
  // =5;
  // double Q2=1.47;// GeV^2
  // double xb=0.163;
 
  // double ph=0.437;
  // double zh=0.476;
  
  double FUU,xb,Q2,zh,ph_t_sq,FUU_cos,FUU_cos2;
  ifstream inputfile;
  inputfile.open("kinevariable.txt");
  inputfile>>xb>>Q2>>zh>>ph_t_sq>>FUU>>FUU_cos>>FUU_cos2;
  double y=Q2/2.0/Mp/beam_energy;

  //////////// Hat expressions ////////////
  double zeta,xi; 
  double Q2_h,y_h,epsilon_h,z_h;
  xb_h=zeta*xb*y/(zeta*xi+y-1);
  y_h=(zeta*xi+y-1)/(zeta*xi);
  Q2_h=(xi/zeta)*Q2;

  double epsilon=(1-y)/(1 -y + pow(y,2.0)/2.0);
  double epsilon_h=(1-y_h)/(1 -y_h + pow(y_h,2.0)/2.0);    

 



  const_term=pow(alpha,2.0)/(2.0*Q2*xb*y);
 dsigma1=(1 + pow((1-y),2.0))*FUU;
 dsigma2=2*(2-y)*sqrt(1-y)*FUU_cos*TMath::Cos(phi_h);
 dsigma3=2*(1-y)*FUU_cos2*TMath::Cos(2*phi_h);
 dsigma=(const_term*(dsigma1+dsigma2+dsigma3))*conversion_ub;

 double dsigma_Tbo_LO;
 double first_Tbo_LO, second_Tbo_LO;
 second_Tbo_LO=(2*TMath::Pi())*(alpha*y_h)/(xb_h*y_h*Q2_h*2*(1-epsilon_h));
 first_Tbo_LO=xb_h/xb;


  cout<<"CHECK THIS OUT  "<<xb<<"   "<<FUU<<"  SIGMA "<<dsigma<<"   cos "<<FUU_cos<<" cos 2  "<<FUU_cos2<<endl;
 */
}

pi_m_data={};
pi_p_data={};

