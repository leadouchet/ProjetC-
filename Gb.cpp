//======================================================================
//                            INCLUDES
//======================================================================
#include "Gb.h"

//======================================================================
//                  DEFINITION STATIC ATTRIBUTES
//======================================================================
  const float Gb::Rbb_ = 0.1;
  const float Gb::Rbc_ = 0.1;
  int Gb::nb_Gb = 0;
  
//======================================================================
//                         CONSTRUCTORS
//======================================================================
Gb::Gb()

/*Construct a Gb cell using the cell default constructor and update
 the Gb counter. */
 
  {
	  nb_Gb++;
  }
  
Gb::Gb(vector<float> intra_metabolites) : Cell(intra_metabolites) 

/* Construct a Gb cell using the cell vector constructor and update 
 * the Gb counter.*/

  {
	  Update_Fit(); 
	  nb_Gb++;
  }

//======================================================================
//    DESTRUCTOR
//======================================================================
  Gb::~Gb()

/*Delete the Gb cell using the cell destructor and update the Gb 
 * counter*/
 
  {
	  nb_Gb--;
  }

//======================================================================
//    PUBLIC METHODS
//======================================================================

  void Gb::metabolism(vector<float>* ext_metab)

/*Change the level of metabolites into the cell depending on the 
 * concentration available its box (given as argument). Return a vector 
 * containing the new concentration of metabolites available in the box 
 * after the reaction of the cell (update its fitness) occure. */

  {
    float flux_in = Rbb_ * ext_metab->at(1) * dt_;
    float chgt = Rbc_ * concentrations_[1] * dt_;
    ext_metab->at(1) -= flux_in;
    concentrations_[1] += flux_in - chgt;
    concentrations_[2] += chgt;
    Update_Fit(); //update the fitness of the box
  }
  
//======================================================================
//                        PROTECTED METHODS
//======================================================================

void Gb::Update_Fit()

/*Compute the fitness of the cell from its metabolites 
 concentrations. The fitness is depending of the acetate level.*/ 
 
  {
    if (concentrations_[2] >= fitness_min_)
    {
      fitness_ = concentrations_[2];
    }
    else fitness_ = 0; 
  }


