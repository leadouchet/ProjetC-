//======================================================================
//                           INCLUDES
//======================================================================
#include "Ga.h"

//======================================================================
//                  DEFINITION STATIC ATTRIBUTES
//======================================================================
  const float Ga::Raa_= 0.1;
  const float Ga::Rab_ = 0.1;
  int Ga::nb_Ga = 0;
  
//======================================================================
//                         CONSTRUCTORS
//======================================================================
Ga::Ga()
  {
    nb_Ga++;
  }
  
Ga::Ga(vector<float> intra_metabolites) : Cell (intra_metabolites)
  {
    nb_Ga++;
	  Update_Fit();
  }

//======================================================================
//                           DESTRUCTOR
//======================================================================
Ga::~Ga()
  {
    nb_Ga--;
  }

//======================================================================
//                         PUBLIC METHODS
//======================================================================
char Ga::WhatAmI()
  {
    return 'a';
	}

vector<float> Ga::metabolism(vector<float> ext_metab)
  {
    float flux_in = Raa_ * ext_metab[0] * dt_;
	  float chgt = Rab_ * concentrations_[0] * dt_;
	  std::vector<float> residues = {ext_metab[0] - flux_in, ext_metab[1], ext_metab[2]};
	  concentrations_[0] += flux_in - chgt;
	  concentrations_[1] += chgt ;
	  Update_Fit();
	  return residues;
  }

//======================================================================
//                         PROTECTED METHODS
//======================================================================

void Ga::Update_Fit()
  {
	  if (concentrations_[1] >= fitness_min_)
      {
        fitness_ = concentrations_[1];
      }
	  else fitness_ = 0;
  }
