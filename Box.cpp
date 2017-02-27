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

//==============================
//    DESTRUCTOR
//==============================


//==============================
//    PUBLIC METHODS
//==============================
void Box::refresh_box(float A_init){
  CONCENTRATIONS_[0] = A_init;
  CONCENTRATIONS_[1] = 0;
  CONCENTRATIONS_[2] = 0;  
}

void Box::metab_trade(){
  CONCENTRATIONS_ = cell_ -> metabolism(CONCENTRATION_);
}
//==============================
//   PROTECTED METHODS
//==============================

