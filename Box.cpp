//==============================
//    INCLUDES
//==============================
#include "Box.h"
#include <cstdio>
#include <vector>

//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
Box::Box(){
 CONCENTRATIONS_ = {0.0,0.0,0.0}; // Concentrations A, B, C
 cell_ = nullptr; 
}

  Box::Box(char type, float A_init)
  {
    CONCENTRATIONS_ = {A_init,0.0,0.0};
    if (type == 'a'){
      cell_ = new Ga();
	}
	else{
      cell_ = new Gb();
	}
  }

//==============================
//    DESTRUCTOR
//==============================
Box::~Box(){
	delete cell_;
	cell_ = nullptr;	
	}

//==============================
//    PUBLIC METHODS
//==============================


//==============================
//   PROTECTED METHODS
//==============================

