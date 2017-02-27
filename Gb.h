#ifndef GB_H
#define GB_H 

//==============================
//    INCLUDES
//==============================

#include "Cell.h"
#include <vector>

/**
 * @class Gb
 * @brief Creates a Gb genotype, Cell
 */

class Gb : public Cell
{
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
  virtual void metabolism(float&) override;


protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
  static const float Rbb_;
  static const float Rbc_;

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

#endif // GB_H
