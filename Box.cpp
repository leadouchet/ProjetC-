//==============================
//    INCLUDES
//==============================
#include "Box.h"
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include <cstdio>
#include <vector>
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

void Box::Cellular_death(){
	std::vector<float> cell_metabolites;
	cell_metabolites = cell_-> intra_metabolites();
	CONCENTRATIONS_[0] += cell_metabolites[0];
	CONCENTRATIONS_[1] += cell_metabolites[1];
	CONCENTRATIONS_[2] += cell_metabolites[2];
	delete cell_;
	cell_ = nullptr;
	}

//==============================
//   PROTECTED METHODS
//==============================

