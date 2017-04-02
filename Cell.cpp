//======================================================================
//                            INCLUDES
//======================================================================
#include "Cell.h"

//======================================================================
//                  DEFINITION STATIC ATTRIBUTES
//======================================================================
  const float Cell::fitness_min_ = 0.001;
  const float Cell::Pdeath_ = 0.02; 
  const float Cell::Pmut_ = 0.001;
  const float Cell::dt_ = 0.1;
  int Cell::nb_cell = 0;
  
//======================================================================
//                          CONSTRUCTORS
//======================================================================
Cell::Cell()
/*Default constructor : Built a cell with all the metabolites equal to 
 * 0. We considere 3 metabolites : A - the glucose, B - the acetate, and
 * C - the ethanol. Each new cell is count in nb_cell attribute */
 
  { 
    fitness_ = 0;
    concentrations_ = {0.0,0.0,0.0};
    nb_cell++;
  }

Cell::Cell(std::vector<float> intra_metabolites)
/* Constructor from a vector : Create a new cell containing into its 
 * metabolisme, the concentration of metabolites given as argument by a 
 * vector containing (glucose, acetate, ethanol). Each new cell is 
 * counted in nb_cell attribute*/
 
  {
    fitness_ = 0;
    concentrations_= intra_metabolites;
    nb_cell++;
  }

//==============================
//    DESTRUCTOR
//==============================
Cell::~Cell()

/*Destructor : Each delete cell is updated into nb_cell attribute*/

  {
	nb_cell--;
  }
//==============================
//    PUBLIC METHODS
//==============================
void Cell::Cell_division()

/*Cell_division function simulate its division by dividing all its 
 * metabolites by 2.*/

  {
    concentrations_[0] /= 2;
    concentrations_[1] /= 2;
    concentrations_[2] /= 2;
  }
