#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include "prokudin.hpp"
#include "TROOT.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TCanvas.h"
#include "TAxis.h"
#include <TROOT.h>
#include <TStyle.h>
#define alpha 1.0/137.0
#define Mp 0.938272
#define beam_energy 5.479 // GeV
#define pi 3.141592
#define hcut_c 0.197323
using namespace std;
int main() {
  sidis::ProkudinSfSet sf;
  ifstream inputfile,input1;
  inputfile.open("data_Pi.txt");
  input1.open("momentum.txt");
  double pi_m_data[25],pi_p_data[25], pi_data[50],error_piM[25],error_piP[25],error_data[50];
  double momentum[25];
  for(int i=0;i<50;i++)
    {
      inputfile>>pi_data[i]>>error_data[i];
    }
  
for(int ii=0;ii<25;ii++)
    {
     pi_p_data[ii]= pi_data[ii];
     error_piP[ii]= error_data[ii];
     input1>>momentum[ii];
     //  cout<<""<<pi_p_data[ii]<<"   "<<momentum[ii]<<"     "<<error_piP[ii]<<endl;
    }

for(int iii=25;iii<50;iii++)
    {
     pi_m_data[iii-25]= pi_data[iii];
     error_piM[iii-25]= error_data[iii];
    
    }
  

  ofstream outputfile;
  outputfile.open("kinevariable.txt");
  double xb = 0.5;
  double Q_sq = 10; // light green 3.08
  double z = 0.3;
  double phi_h=pi;
  const int num=20;
  //  double nu=Q_sq/(xb*2.0*Mp);
  double nu=3.794;
  double y=nu/beam_energy;//Q_sq/2.0/Mp/beam_energy;
  double epsilon=(1-y)/(1 -y + pow(y,2.0)/2.0);
  
  double pt_sq_val_temp=0.1;

  double sigma_plot[num], sigma_plot_pim[num];
  double pt_sq_plot[num];
  int i=0;
 double ph_t_sq = pow(pt_sq_val_temp,2.0);
cout<<xb<<"\t"<<Q_sq<<"  "<<z<<"  "<<ph_t_sq<<"  "<<sf.F_UUT(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq)<<"  "<<sf.F_UU_cos_phih(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq)<<"   "<<sf.F_UU_cos_2phih(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq)<<std::endl;
/*
  do
   {

  double ph_t_sq = pow(pt_sq_val_temp,1.0);

 //////////Pi Plus case////////////////
  double FUU=sf.F_UUT(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq);
  double FUU_cos=  sf.F_UU_cos_phih(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq);
  double FUU_cos2= sf.F_UU_cos_2phih(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq);

  //////////Pi minus case
  double FUU_pim=sf.F_UUT(sidis::Hadron::PI_M, xb, z, Q_sq, ph_t_sq);
  double FUU_cos_pim=  sf.F_UU_cos_phih(sidis::Hadron::PI_M, xb, z, Q_sq, ph_t_sq);
  double FUU_cos2_pim= sf.F_UU_cos_2phih(sidis::Hadron::PI_M, xb, z, Q_sq, ph_t_sq);

 



  double dsigma_Tbo_LO;
  double first_Tbo_LO, second_Tbo_LO;
  double dsigma_ini, dsigma, const_term,dsigma1, dsigma2,dsigma3;
  double dsigma1_pim, dsigma2_pim,dsigma3_pim;
  double conversion_Factor=(1-y)/(2*pi*Mp*y);// convert dxdy to domega_dEprime
  double consider_psi=2*pi;

  const_term=pow(alpha,2.0)/(2.0*Q_sq*xb*y);
  dsigma1=(1 + pow((1-y),2.0))*FUU;
  dsigma2=2*(2-y)*sqrt(1-y)*FUU_cos*cos(phi_h);
  dsigma3=2*(1-y)*FUU_cos2*cos(2*phi_h);
  dsigma_ini=(const_term*(dsigma1+dsigma2+dsigma3));// GeV^-4

  dsigma1_pim=(1 + pow((1-y),2.0))*FUU_pim;
  dsigma2_pim=2*(2-y)*sqrt(1-y)*FUU_cos_pim*cos(phi_h);
  dsigma3_pim=2*(1-y)*FUU_cos2_pim*cos(2*phi_h);
 double dsigma_pim_ini=const_term*( dsigma1_pim + dsigma2_pim  + dsigma3_pim); 

  dsigma=dsigma_ini*pow(hcut_c,2.0)*1e7*conversion_Factor*consider_psi;// GeV-2 nb
  // dE' domega dpt_sq dz dphi 
  // 10^7 is conversion of barn to micro barn


  double dsigma_pim=dsigma_pim_ini* pow(hcut_c,2.0)*1e7*conversion_Factor*consider_psi;// GeV-2 nb

  sigma_plot[i]=dsigma;
  sigma_plot_pim[i]=dsigma_pim;
  pt_sq_plot[i]=pt_sq_val_temp;

  
  cout<<" Check out this  "<<pt_sq_val_temp<<"         "<<dsigma<<endl;
  outputfile<< pt_sq_val_temp<<"\t"<< dsigma<<endl;
  //  pt_sq_val_temp=pt_sq_val_temp+0.01;
  // i++;
  //  }while(pt_sq_val_temp<0.2);



gStyle->SetTitleYOffset(0.7); // higher the value goes away from axis
gStyle->SetTitleXOffset(0.7);
gStyle->SetTitleYSize(0.045);
gStyle->SetTitleXSize(0.055);
gStyle->SetLabelFont(62,"X");
gStyle->SetLabelFont(62,"Y");
gStyle->SetTitleFont(62,"X");
gStyle->SetTitleFont(62,"Y");
gStyle->SetLabelSize(0.045,"X");
gStyle->SetLabelSize(0.054,"Y");


 TCanvas *c1= new TCanvas();
 c1->SetLogy();
 c1->SetGridx();
c1->SetGridy();

 TGraphErrors*gr_dataP= new TGraphErrors(25,momentum,pi_p_data,NULL ,error_piP);
 TGraphErrors *gr_dataM= new TGraphErrors(25,momentum,pi_m_data,NULL,error_piM);
 
// gr_dataP->Draw("AP");
 

 TGraph *gr= new TGraph(num,pt_sq_plot,sigma_plot);
 gr->SetMarkerStyle(8);
 gr->SetMarkerColor(2);
 gr->GetXaxis()->SetTitle("P_{t}^{2} (GeV/c)^{2}");
 gr->GetYaxis()->SetTitle("#frac{d#sigma}{d#Omega_{e} dE_{e} dz dP_{t}^{2} d#Phi}[nb GeV^{-2} sr^{-1}]");
 gr->SetTitle("H(e,e'#pi^{+})X");
 gr->Draw("AP");
 gr_dataP->Draw("sameP");
 gr_dataP->SetMarkerColor(1);
 gr_dataP->SetMarkerStyle(8);
 gr->GetXaxis()->SetNdivisions(510);
 gr->GetYaxis()->SetRangeUser(0.1,5.0);
 
 c1->Print("test.pdf(");


 


 TGraph *gr_pim= new TGraph(num,pt_sq_plot,sigma_plot_pim);
 gr_pim->SetMarkerStyle(8);
 gr_pim->SetMarkerColor(2);
 gr_pim->GetXaxis()->SetTitle("P_{t}^{2} (GeV/c)^{2}");
 gr_pim->GetYaxis()->SetTitle("#frac{d#sigma}{d#Omega_{e} dE_{e} dz dP_{t}^{2} d#Phi}[nb GeV^{-2} sr^{-1}]");
 gr_pim->SetTitle("H(e,e'#pi^{-})X");
 gr_pim->Draw("AP");
gr_dataM->Draw("sameP");
 gr_dataM->SetMarkerColor(1);
 gr_dataM->SetMarkerStyle(8);
 gr_pim->GetYaxis()->SetRangeUser(0.1,5.0);
 gr_pim->GetXaxis()->SetNdivisions(510);
 c1->Print("test.pdf)");
 */
/*
//////////// Hat expressions ////////////
  double zeta=1;
  double xi=1; 
  double Q_sq_h,y_h,epsilon_h,z_h,xb_h, ph_t_sq_h;
  xb_h=zeta*xb*y/(zeta*xi+y-1);
  y_h=(zeta*xi+y-1)/(zeta*xi);
  Q_sq_h=(xi/zeta)*Q_sq;
  z_h=(zeta*y*z)/(xi*zeta+y-1);
  double gamma=(2*xb*Mp)/sqrt(Q_sq);
  epsilon_h=(1-y_h)/(1 -y_h + pow(y_h,2.0)/2.0);  

 double F11_h=sf.F_UUT(sidis::Hadron::PI_P, xb_h, z_h, Q_sq_h, ph_t_sq);

 first_Tbo_LO=xb_h/xb;
  second_Tbo_LO=(2*pi)*(alpha*y_h)/(xb_h*y_h*Q_sq_h*2*(1-epsilon_h));
 
  dsigma_Tbo_LO=first_Tbo_LO*second_Tbo_LO*F11_h;// GeV^2
 ////////////For PhT has/////////////
  //double ph_t_sq_h;
  double term1,term2,term3,term4,term5,term6;
  term1=4*(pow(gamma,2.0)+1)*pow((xi*zeta-1),2.0)+ y*y*(pow(gamma,2.0)*xi*zeta+1)+2*y*(xi*zeta-1);
*/
 /*
  // cout<<F11<<"   "<<F12<<"   "<<F13<<endl;
  
  //	double ph_t=;
  //double ph_t_sq = pow(ph_t,2.0);;
  std::cout << "SF FUU @ x=" << xb
	    << ", Q_sq=" << Q_sq
	    << ", z=" << z
	    << ", ph_t_sq=" << ph_t_sq
	    << ": " << sf.F_UUT(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq)
	    << std::endl;
  //	outputfile<<xb<<"\t"<<Q_sq<<"\t"<<z<<"\t"<<ph_t_sq<<"\t"<<sf.F_UUT<<std::endl;
	outputfile<<xb<<"\t"<<Q_sq<<"  "<<z<<"  "<<ph_t_sq<<"  "<<sf.F_UUT(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq)<<"  "<<sf.F_UU_cos_phih(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq)<<"   "<<sf.F_UU_cos_2phih(sidis::Hadron::PI_P, xb, z, Q_sq, ph_t_sq)<<std::endl;
  */
	return 0;
}

