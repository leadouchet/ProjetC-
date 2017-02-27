//==============================
//    INCLUDES
//==============================
#include "Box.h"
#include <cstdio>
#include <vector>
#include <stdlib.h>


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Box::Box(){
 CONCENTRATIONS_ = {0.0,0.0,0.0}; // Concentrations A, B, C
 cell_ = nullptr; 
}

Box::Box(char type, float A_init)
  {
    CONCENTRATIONS_ = {A_init,0.0,0.0};
    if (type == 'a'){
      cell_ = new Ga();
	}
	else{
      cell_ = new Gb();
	}
  }

//==============================
//    DESTRUCTOR
//==============================
Box::~Box(){
	delete cell_;
	cell_ = nullptr;	
	}

//==============================
//    PUBLIC METHODS
//==============================
bool Box::empty_Box(){
	if (cell_ == nullptr) return 0;
	else return 1;
}

bool Box::Cellular_death(){
	float decision = (double) rand() / (RAND_MAX);
	if(decision <= cell_->Pdeath()){
		std::vector<float> cell_metabolites;
		cell_metabolites = cell_-> intra_metabolites();
		CONCENTRATIONS_[0] += cell_metabolites[0];
		CONCENTRATIONS_[1] += cell_metabolites[1];
		CONCENTRATIONS_[2] += cell_metabolites[2];
		delete cell_;
		cell_ = nullptr;
		}
	return empty_Box();
	}


void Box::refresh_box(float A_init){
  CONCENTRATIONS_[0] = A_init;
  CONCENTRATIONS_[1] = 0;
  CONCENTRATIONS_[2] = 0;  
}

void Box::metab_trade(){
  CONCENTRATIONS_ = cell_ -> metabolism(CONCENTRATIONS_);
}


void Box::newborn(Cell* mother){
  float aleat = (double) rand() / (RAND_MAX);
  if (mother -> WhatAmI() == 'a'){
    if (aleat < (mother->Pmut())){
	cell_ = new Gb(mother->intra_metabolites());
      }
    else{
      	cell_ = new Ga(mother->intra_metabolites());
    }
      }
  else{
    if (aleat < (mother->Pmut())){
	cell_ = new Ga(mother->intra_metabolites());
      }
    else{
      	cell_ = new Gb(mother->intra_metabolites());
    }

  }
  }


//==============================
//   PROTECTED METHODS
//==============================

