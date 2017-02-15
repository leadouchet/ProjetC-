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
  a_ = 0;
  b_ = 0;
  c_ = 0;
}

Cell::Cell(std::vector<float> intra_metabolites){
  fitness_ = 0;
  a_ = intra_metabolites[0];
  b_ = intra_metabolites[1];
  c_ = intra_metabolites[2];
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
{  std::vector<float> vec{a_ , b_ , c_};
return(vec);
}
