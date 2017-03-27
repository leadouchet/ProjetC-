//======================================================================
//                           INCLUDES
//======================================================================
#include "Ga.h"

//======================================================================
//                  DEFINITION STATIC ATTRIBUTES
//======================================================================
  const float Ga::Raa_= 0.1;
  const float Ga::Rab_ = 0.1;
  int Ga::nb_Ga = 0;
  
//======================================================================
//                         CONSTRUCTORS
//======================================================================
Ga::Ga()

/*Construct a Ga cell using the cell default constructor and update
 the Gb counter. */

  {
    nb_Ga++;
  }
  
Ga::Ga(vector<float> intra_metabolites) : Cell (intra_metabolites)

/* Construct a Ga cell using the cell vector constructor and update 
 * the Ga counter.*/

  {
    nb_Ga++;
	  Update_Fit();
  }

//======================================================================
//                           DESTRUCTOR
//======================================================================
Ga::~Ga()

/*Delete the Ga cell using the cell destructor and update the Gb 
 * counter*/

  {
    nb_Ga--;
  }

//======================================================================
//                         PUBLIC METHODS
//======================================================================


vector<float> Ga::metabolism(vector<float> ext_metab)

/*Change the level of metabolites into the cell depending on the 
 * concentration available its box (given as argument). Return a vector 
 * containing the new concentration of metabolites available in the box 
 * after the reaction of the cell (update its fitness) occure. */
 
  {
    float flux_in = Raa_ * ext_metab[0] * dt_;
	  float chgt = Rab_ * concentrations_[0] * dt_;
	  std::vector<float> residues = {ext_metab[0] - flux_in, ext_metab[1], ext_metab[2]};
	  concentrations_[0] += flux_in - chgt;
	  concentrations_[1] += chgt ;
	  Update_Fit();
	  return residues;
  }

//======================================================================
//                         PROTECTED METHODS
//======================================================================

void Ga::Update_Fit()

/*Compute the fitness of the cell from its metabolites 
 concentrations. The fitness is depending of the glucose level.*/ 

  {
	  if (concentrations_[1] >= fitness_min_)
      {
        fitness_ = concentrations_[1];
      }
	  else fitness_ = 0;
  }
