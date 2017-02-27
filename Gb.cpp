//==============================
//    INCLUDES
//==============================
#include "Gb.h"
#include <cstdio>
#include <vector>

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
  const float Gb::Rbb_ = 0.1;
  const float Gb::Rbc_ = 0.1;
//==============================
//    CONSTRUCTORS
//==============================
  Gb::Gb(){}
  Gb::Gb(std::vector<float> intra_metabolites) : Cell(intra_metabolites) 
  {
	if (concentrations_[1] >= fitness_min_){
    fitness_ = concentrations_[3];
    }
	else fitness_ = 0; 
  }
  
//==============================
//    DESTRUCTOR
//==============================
  Gb::~Gb(){}

//==============================
//    PUBLIC METHODS
//==============================
char Gb::WhatAmI() {
	return 'b';
	}
  std::vector<float> Gb::metabolism(std::vector<float> ext_metab)
  {
    float flux_in = Rbb_*ext_metab[1];
    float chgt = Rbc_*concentrations_[1];
    std::vector<float> residues = {ext_metab[0], ext_metab[1] - flux_in, ext_metab[2]};
    concentrations_[1] += flux_in - chgt;
    concentrations_[2] += chgt;
    return residues;
  }
  
//==============================
//   PROTECTED METHODS
//==============================
