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
  float a_;
  float b_;
  float c_;



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
