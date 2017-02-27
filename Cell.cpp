//==============================
//    INCLUDES
//==============================
#include "Cell.h"
#include <vector>
//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
const float Cell::fitness_min_ = 0.001;
const float Cell::Pdeath_ = 0.02; 
const float Cell::Pmut_ = 0;
//==============================
//    CONSTRUCTORS
//==============================
Cell::Cell()
{ fitness_ = 0;
  concentrations_ = {0.0,0.0,0.0};
}

Cell::Cell(std::vector<float> intra_metabolites){
  fitness_ = 0;
  concentrations_= intra_metabolites;
}

//==============================
//    DESTRUCTOR
//==============================
Cell::~Cell(){}
//==============================
//    PUBLIC METHODS
//==============================


//==============================
//    GETTERS
//==============================
std::vector<float> Cell::intra_metabolites()
{  
  return(concentrations_);
}
