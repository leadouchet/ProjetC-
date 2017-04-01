//==============================
//    INCLUDES
//==============================
#include "Gb.h"

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
  void Gb::metabolism(std::vector<float>* ext_metab)
  {
    float flux_in = Rbb_*ext_metab->at(1)*dt_;
    float chgt = Rbc_*concentrations_[1]*dt_;
      ext_metab->at(1) -= flux_in;
    concentrations_[1] += flux_in - chgt;
    concentrations_[2] += chgt;
    Update_Fit(); //update the fitness of the box
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


