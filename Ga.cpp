//==============================
//    INCLUDES
//==============================
#include "Ga.h"
#include <cstdio>
#include <vector>

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
  const float Ga::Raa_= 0.1;
  const float Ga::Rab_ = 0.1;
//==============================
//    CONSTRUCTORS
//==============================
  Ga::Ga(){}
  
  Ga::Ga(std::vector<float> intra_metabolites) : Cell (intra_metabolites){
	  if (concentrations_[1] >= fitness_min_){
	  fitness_ = concentrations_[1];
	  }
	  else fitness_ = 0;
	  }
//==============================
//    DESTRUCTOR
//==============================
  Ga::~Ga(){}

//==============================
//    PUBLIC METHODS
//==============================
char Ga::WhatAmI() {
	return 'a';
	}

  std::vector<float> Ga::metabolism(std::vector<float> ext_metab){
	  float flux_in = Raa_*ext_metab[0];
	  float chgt = Rab_*concentrations_[0];
	  std::vector<float> residues = {ext_metab[0] - flux_in, ext_metab[1], ext_metab[2]};
	  concentrations_[0] += flux_in - chgt;
	  concentrations_[1] += concentrations_[0] * Rab_ ;
	  return residues;
  }

//==============================
//   PROTECTED METHODS
//==============================

