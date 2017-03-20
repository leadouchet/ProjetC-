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
  int Gb::nb_Gb = 0;
//==============================
//    CONSTRUCTORS
//==============================
  Gb::Gb(){
	  nb_Gb += 1;
	  }
  Gb::Gb(std::vector<float> intra_metabolites) : Cell(intra_metabolites) 
  {
	Update_Fit(); 
	nb_Gb += 1;
  }
  
//==============================
//    DESTRUCTOR
//==============================
  Gb::~Gb(){
	  nb_Gb -= 1;
	  }

//==============================
//    PUBLIC METHODS
//==============================

  char Gb::WhatAmI() {
	  return 'b';
	  }
  std::vector<float> Gb::metabolism(std::vector<float> ext_metab)
  {
    float flux_in = Rbb_*ext_metab[1]*dt_;
    float chgt = Rbc_*concentrations_[1]*dt_;
    std::vector<float> residues = {ext_metab[0], ext_metab[1] - flux_in, ext_metab[2]};
    concentrations_[1] += flux_in - chgt;
    concentrations_[2] += chgt;
    Update_Fit(); //update the fitness of the box
    return residues; // return the concentration of metabolites left in the surrounding box
  }
  
//==============================
//   PROTECTED METHODS
//==============================

void Gb::Update_Fit(){
	if (concentrations_[2] >= fitness_min_){
    fitness_ = concentrations_[2];
    }
	else fitness_ = 0; 
	}


