#ifndef GA_H
#define GA_H 

//==============================
//    INCLUDES
//==============================

#include "Cell.h"
#include <cstdio>
#include <vector>
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
  void metabolism(std::vector<float>* ext_metab) override;
  inline int Get_nb() const override;
  
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
inline int Ga::Get_nb() const
{
  return nb_Ga;
}

#endif // GA_H

