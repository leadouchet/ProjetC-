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
	  fitness_ = b_;
	  }
//==============================
//    DESTRUCTOR
//==============================
  Ga::~Ga(){}

//==============================
//    PUBLIC METHODS
//==============================
  void Ga::metabolism(float& a_ext){
	  float flux_in = Raa_*a_ext;
	  float chgt = Rab_*a_;
	  a_ext -= flux_in;
	  a_ = flux_in - chgt;
	  b_ = a_ * Rab_ ;
  }

//==============================
//   PROTECTED METHODS
//==============================

