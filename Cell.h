#ifndef CELL_H
#define CELL_H 

//==============================
//    INCLUDES
//==============================
#include <vector>

/**
 * @class Cell
 * @brief Creates a Cell
 */

class Cell
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Cell();
  Cell(std::vector<float>);
//==============================
//    DESTRUCTOR
//==============================
 virtual ~Cell();
//==============================
//    GETTERS
//==============================
 std::vector<float> intra_metabolites(); 
//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
virtual char WhatAmI() = 0;
virtual std::vector<float> metabolism(std::vector<float>) = 0;
std::vector<float> Cell_division();


protected:
//==============================
//    PROTECTED METHODS
//==============================
  
//==============================
//    ATTRIBUTES
//==============================
  static const float fitness_min_;
  static const float Pdeath_;
  static const float Pmut_;
  int fitness_;
  std::vector<float> concentrations_;



};

//==============================
//    GETTER DEFINITION
//==============================

//==============================
//    SETTER DEFINITION
//==============================

//==============================
//    OPERATOR DEFINITION
//==============================



#endif // CELL_H
