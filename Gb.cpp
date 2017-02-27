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
    fitness_ = concentrations_[2]; 
  }
  
//==============================
//    DESTRUCTOR
//==============================
  Gb::~Gb(){}

//==============================
//    PUBLIC METHODS
//==============================
  void Gb::metabolism(float& b_ext)
  {
    float flux_in = Rbb_*b_ext;
    float chgt = Rbc_*concentrations_[1];
    b_ext -= flux_in;
    concentrations_[1] += flux_in - chgt;
    concentrations_[2] += chgt;
  }
  
//==============================
//   PROTECTED METHODS
//==============================
