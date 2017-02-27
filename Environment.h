#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H 

//==============================
//    INCLUDES
//==============================
#include <vector>
#include <array>
#include <stdlib.h>
#include "Box.h"

/**
 * @class Environment
 * @brief Creates an Environment
 */

class Environment
{
public:
//==============================
//    CONSTRUCTORS
//==============================
  Environment();

//==============================
//    DESTRUCTOR
//==============================

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

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
  int W_; //width
  int H_; //Height
  std::vector< std::vector<Box> > grid_;
  float D_; // diffusion constant
  int T_;
  float A_init_;


private :
//==============================
//      PRIVATE METHODS
//==============================
  char randel (std::vector<char>& tab);

  
  
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



#endif // ENVIRONMENT_H
