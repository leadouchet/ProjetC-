//==============================
//    INCLUDES
//==============================
#include "Box.h"
#include <vector>
#include <stdlib.h>
#include "Box.h"
#include <iostream>
#include <fstream>
#include <stdio.h>


using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ofstream;


//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Box::Box(){
    CONCENTRATIONS_ = new vector<float>;
    *CONCENTRATIONS_={0.0,0.0,0.0};
    Next_CONCENTRATIONS_ = new vector<float>;
    *Next_CONCENTRATIONS_={0.0,0.0,0.0};
 cell_ = nullptr; 
}

Box::Box(char type, float A_init)
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

//==============================
//    DESTRUCTOR
//==============================
Box::~Box(){
	delete cell_;
    delete CONCENTRATIONS_;
    delete Next_CONCENTRATIONS_;
    Next_CONCENTRATIONS_ = nullptr;
    CONCENTRATIONS_ = nullptr;
	cell_ = nullptr;
    
	}

//==============================
//    PUBLIC METHODS
//==============================
//Getter 

vector<float>* Box::get_box_metabolites(){
	return CONCENTRATIONS_;
	}
vector<float>* Box::get_box_next_metabolites(){
    return Next_CONCENTRATIONS_;
}


bool Box::empty_Box(){
	if (cell_ == nullptr) return true;
	else return false;
}

bool Box::Cellular_death(){
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


void Box::refresh_box(float A_init){
  CONCENTRATIONS_ -> at(0) = A_init;
  CONCENTRATIONS_-> at(1) = 0;
  CONCENTRATIONS_-> at(2) = 0;
}

void Box::metab_trade(){
    
   cell_ -> metabolism(CONCENTRATIONS_);

}


void Box::newborn(Cell* mother){
  mother->Cell_division();
  float aleat = (double) rand() / (RAND_MAX);
  if (mother -> WhatAmI() == 'a'){
    if (aleat < (mother->Pmut())){
	cell_ = new Gb(mother->intra_metabolites());
      }
    else{
      	cell_ = new Ga(mother->intra_metabolites());
    }
      }
  else{
    if (aleat < (mother->Pmut())){
	cell_ = new Ga(mother->intra_metabolites());
      }
    else{
      	cell_ = new Gb(mother->intra_metabolites());
    }

  }
  }

vector<float> Box::get_cell_concentration()
{
    return(cell_ -> intra_metabolites());    
}

char Box::get_cell_type()
{ if (cell_==nullptr){return('X');}
  return(cell_-> WhatAmI()); 
}




float Box::get_cell_fitness(){
    return cell_-> fitness();

}

void Box::update_diffusion(){
    *CONCENTRATIONS_=*Next_CONCENTRATIONS_;
}

//==============================
//   PROTECTED METHODS
//==============================



