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
	  fitness_ = concentrations_[1];
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
	
  void Ga::metabolism(float& a_ext){
	  float flux_in = Raa_*a_ext;
	  float chgt = Rab_*concentrations_[0];
	  a_ext -= flux_in;
	  concentrations_[0] += flux_in - chgt;
	  concentrations_[1] += concentrations_[0] * Rab_ ;
  }
  

//==============================
//   PROTECTED METHODS
//==============================

