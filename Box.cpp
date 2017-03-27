//======================================================================
//                           INCLUDES
//======================================================================
#include "Box.h"


//======================================================================
//                        CONSTRUCTORS
//======================================================================
Box::Box()
/* Construct an empty box. */
  {
    CONCENTRATIONS_ = {0.0,0.0,0.0};                                    // Concentrations A, B, C
    cell_ = nullptr; 
  }


Box::Box(char type, float A_init)
/* Construct a box with Ga or Gb Cell and A_init given. */
  {
    CONCENTRATIONS_ = {A_init,0.0,0.0};
    if (type == 'a')
      {
        cell_ = new Ga();
      }
    else cell_ = new Gb();
  }

//======================================================================
//                          DESTRUCTOR
//======================================================================
Box::~Box()
/* Destruct a box. */
  {
    delete cell_;
    cell_ = nullptr;	
	}

//======================================================================
//                          GETTERS
//======================================================================
vector<float> Box::get_box_metabolites()
/* Give the concentrations of metabolites within the Box. */
  {
	  return CONCENTRATIONS_;
	}


vector<float> Box::get_cell_concentration()
/* Give the concentrations of metabolites within the Cell. */
  {
    return(cell_->intra_metabolites());    
  }


char Box::get_cell_type()
/* Give the type of the Cell in the Box. */
  { 
    if (cell_ == nullptr)
      {
        return('X');
      }
    return(cell_->WhatAmI()); 
}


float Box::get_cell_fitness()
/* Give the fitness of the Cell within the Box. */
  {
    return cell_->fitness();
  }
  
//======================================================================
//                        PUBLIC METHODS
//======================================================================
void Box::refresh_box(float A_init)
/* Clean the box and set A to the initial concentration. */
  {
    CONCENTRATIONS_[0] = A_init;
    CONCENTRATIONS_[1] = 0;
    CONCENTRATIONS_[2] = 0;  
  }


void Box::metab_trade()
/* The Cell metabolize and exchange metabolites with the Box. */
  {
    CONCENTRATIONS_ = cell_->metabolism(CONCENTRATIONS_);
  }


bool Box::Cellular_death()
/* The Cell die following a mutation probability. */
  {
    float decision = (double) rand() / (RAND_MAX);
    if(decision <= cell_->Pdeath())
      {
        vector<float> cell_metabolites;
        cell_metabolites = cell_->intra_metabolites();
        CONCENTRATIONS_[0] += cell_metabolites[0];
        CONCENTRATIONS_[1] += cell_metabolites[1];
        CONCENTRATIONS_[2] += cell_metabolites[2];
        delete cell_;
        cell_ = nullptr;
        return true;
      }
    return false;
	}


bool Box::empty_Box()
/* Say if the Box is empty. */ 
  {
    if (cell_ == nullptr) return true;
    else return false;
  }


void Box::newborn(Cell* mother)
/* A close Cell (mother) divide itself and fill the empty Box. 
 * Its metabolites are divided by 2. */
  {
    mother->Cell_division();
    float aleat = (double) rand() / (RAND_MAX);
    if (mother->WhatAmI() == 'a')
      {
        if (aleat < (mother->Pmut()))
          {
            cell_ = new Gb(mother->intra_metabolites());
          }
        else
          {
            cell_ = new Ga(mother->intra_metabolites());
          }
      }
    else
      {
        if (aleat < (mother->Pmut()))
          {
            cell_ = new Ga(mother->intra_metabolites());
          }
        else
          {
            cell_ = new Gb(mother->intra_metabolites());
          }
      }
  }


void Box::update_box(const vector<float> ABC)
/* Set new values for the metabolites concentrations of the Box. */
  {
    for (auto it = 0 ; it < 3; ++it)
      {
        CONCENTRATIONS_[it] = ABC[it];
      }
  }






