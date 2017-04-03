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
    CONCENTRATIONS_ = new vector<float>;
    *CONCENTRATIONS_={0.0,0.0,0.0};
    Next_CONCENTRATIONS_ = new vector<float>;
    *Next_CONCENTRATIONS_={0.0,0.0,0.0};
    cell_ = nullptr; 
  }


Box::Box(char type, float A_init)

/* Construct a box with Ga or Gb Cell and A_init given. */

  {
   CONCENTRATIONS_ = new vector<float>;
    *CONCENTRATIONS_ = {A_init,0.0,0.0};
    if (type == 'a'){
      cell_ = new Ga();
	}
	else{
      cell_ = new Gb();
	}
   Next_CONCENTRATIONS_ = new vector<float>;
   *Next_CONCENTRATIONS_={0.0,0.0,0.0};
  }

//======================================================================
//                          DESTRUCTOR
//======================================================================
Box::~Box(){
	delete cell_;
    delete CONCENTRATIONS_;
    delete Next_CONCENTRATIONS_;
    Next_CONCENTRATIONS_ = nullptr;
    CONCENTRATIONS_ = nullptr;
	cell_ = nullptr;
    
	}

//======================================================================
//                          GETTERS
//======================================================================
vector<float>* Box::get_box_metabolites()

/* Give the concentrations of metabolites within the Box. */

  {
	  return CONCENTRATIONS_;
	}

vector<float>* Box::get_box_next_metabolites(){
    return Next_CONCENTRATIONS_;
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

Cell* Box::cell()

/* Give the pointer to the cell in the box. */

  {
    return cell_;
  }

//======================================================================
//                        PUBLIC METHODS
//======================================================================

void Box::refresh_box(float A_init){
  CONCENTRATIONS_ -> at(0) = A_init;
  CONCENTRATIONS_-> at(1) = 0;
  CONCENTRATIONS_-> at(2) = 0;
}

void Box::metab_trade(){
  cell_ -> metabolism(CONCENTRATIONS_);
}

bool Box::Cellular_death()

/* The Cell die following a mutation probability. */

{
float decision = (double) rand() / (RAND_MAX);
	if(decision <= cell_->Pdeath()){
		std::vector<float> cell_metabolites;
		cell_metabolites = cell_-> intra_metabolites();
		CONCENTRATIONS_-> at(0) += cell_metabolites[0];
		CONCENTRATIONS_-> at(1) += cell_metabolites[1];
		CONCENTRATIONS_-> at(2) += cell_metabolites[2];
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


void Box::newborn(Cell* sister)

/*Given a cell, reproduce the same cell into the box*/

{
	char phenotype = sister->WhatAmI();
	vector <float> sister_concentration = sister->intra_metabolites();
	if (phenotype == 'a')
	{
		cell_ = new Ga(sister_concentration);
	}
	else
	{
		cell_ = new Gb(sister_concentration);		
	}
}
/*void Box::newborn(Cell* mother)

* A close Cell (mother) divide itself and fill the empty Box. 
 * Its metabolites are divided by 2. 
 
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
  */

void Box::mutation()

/* Decide if the cell should mutate or not and then divid its metabolites */

{
    float aleat = (double) rand() / (RAND_MAX);
    vector <float> mother = cell_->intra_metabolites();
    char phenotype = cell_->WhatAmI();
    if (aleat < (cell_->Pmut()))
    {
		if ( phenotype == 'a' )
		{
			delete cell_;
            cell_ = new Gb(mother);
        }
        else 
          {
			  delete cell_;
			  cell_ = new Ga(mother);
          }
      }
      cell_->Cell_division();
  }



void Box::update_diffusion(){
    *CONCENTRATIONS_=*Next_CONCENTRATIONS_;
}




