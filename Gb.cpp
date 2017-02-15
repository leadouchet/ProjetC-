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
    fitness_ = c_; 
  }
  
//==============================
//    DESTRUCTOR
//==============================


//==============================
//    PUBLIC METHODS
//==============================

//==============================
//   PROTECTED METHODS
//==============================
