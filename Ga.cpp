//==============================
//    INCLUDES
//==============================
#include "Ga.h"

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
  const float Ga::Raa_= 0.1;
  const float Ga::Rab_ = 0.1;
  int Ga::nb_Ga = 0;
//==============================
//    CONSTRUCTORS
//==============================
  Ga::Ga(){
	  nb_Ga += 1;
	  }
  
  Ga::Ga(std::vector<float> intra_metabolites) : Cell (intra_metabolites){
	  nb_Ga += 1;
	  Update_Fit();
	  }
//==============================
//    DESTRUCTOR
//==============================
  Ga::~Ga(){
	  nb_Ga -= 1;
	  }

//==============================
//    PUBLIC METHODS
//==============================
char Ga::WhatAmI() {
	return 'a';
	}

void Ga::metabolism(std::vector<float>* ext_metab){
	  float flux_in = Raa_*ext_metab->at(0)*dt_;
	  float chgt = Rab_*concentrations_[0]*dt_;
    ext_metab->at(0) -= flux_in;
	  concentrations_[0] += flux_in - chgt;
	  concentrations_[1] += chgt ;
	  Update_Fit();

  }

//==============================
//   PROTECTED METHODS
//==============================

void Ga::Update_Fit(){
	  if (concentrations_[1] >= fitness_min_){
	  fitness_ = concentrations_[1];
	  }
	  else fitness_ = 0;
	  }
