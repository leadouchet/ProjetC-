//==============================
//    INCLUDES
//==============================
#include "Cell.h"

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================
const float Cell::fitness_min_ = 0.001;
const float Cell::Pdeath_ = 0.02; 
const float Cell::Pmut_ = 0.001;
const float Cell::dt_ = 0.1;
int Cell::nb_cell = 0;
//==============================
//    CONSTRUCTORS
//==============================
Cell::Cell()
{ fitness_ = 0;
  concentrations_ = {0.0,0.0,0.0};
  nb_cell += 1;
}

Cell::Cell(std::vector<float> intra_metabolites){
  fitness_ = 0;
  concentrations_= intra_metabolites;
  nb_cell += 1;
}

//==============================
//    DESTRUCTOR
//==============================
Cell::~Cell(){
	nb_cell-= 1;
	}
//==============================
//    PUBLIC METHODS
//==============================
void Cell::Cell_division(){
	concentrations_[0] /= 2;
	concentrations_[1] /= 2;
	concentrations_[2] /= 2;
}
//==============================
//    GETTERS
//==============================
std::vector<float> Cell::intra_metabolites()
{  
  return(concentrations_);
}
