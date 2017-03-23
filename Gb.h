#ifndef GB_H
#define GB_H 

//==============================
//    INCLUDES
//==============================

#include "Cell.h"
#include <vector>
#include <cstdio>


/**
 * @class Gb
 * @brief Creates a Gb genotype, Cell
 */

class Gb : public Cell
{
	friend int Get_nb_Gb();
public:
//==============================
//    CONSTRUCTORS
//==============================
  Gb();
  Gb(std::vector<float>);

//==============================
//    DESTRUCTOR
//==============================
  virtual ~Gb();

//==============================
//    GETTERS
//==============================
inline int Get_nb() const override;
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
  static const float Rbb_;
  static const float Rbc_;
  static int nb_Gb; 

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

inline int Gb::Get_nb() const
{
	
  return nb_Gb;
}


#endif // GB_H
