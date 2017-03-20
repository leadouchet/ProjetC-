#ifndef GA_H
#define GA_H 

//==============================
//    INCLUDES
//==============================

#include "Cell.h"
#include "vector"
/**
 * @class Ga
 * @brief Creates a Ga Genotype, Cell
 */

class Ga : public Cell
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Ga();
  Ga(std::vector<float> intra_metabolites);
//==============================
//    DESTRUCTOR
//==============================
  virtual ~Ga();
//==============================
//    GETTERS
//==============================

//==============================
//    SETTERS
//==============================

//==============================
//    OPERATORS
//==============================

//==============================
//    PUBLIC METHODS
//==============================
  char WhatAmI() override;
  virtual std::vector<float> metabolism(std::vector<float> ext_metab) override;
  
protected:
//==============================
//    PROTECTED METHODS
//==============================
  void Update_Fit() override;
//==============================
//    ATTRIBUTES
//==============================
  static const float Raa_;
  static const float Rab_;
  static int nb_Ga;

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

//==============================
// INLINE FUNCTION DEFINITION
//==============================


#endif // GA_H

