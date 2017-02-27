//==============================
//    INCLUDES
//==============================
#include "Box.h"
#include <cstdio>

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
bool Box::empty_Box(){
	if (cell_ == nullptr) return 0;
	else return 1;
}

//==============================
//   PROTECTED METHODS
//==============================

