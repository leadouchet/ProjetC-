#ifndef BOX_H
#define BOX_H

//==============================
//    INCLUDES
//==============================
#include <vector>
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"

/**
 * @class Box
 * @brief Creates a Box associated to environment
 */

class Box
{
public:
//==============================
//    CONSTRUCTORS
//==============================
Box();
Box(char type, float A_init);
	

//==============================
//    DESTRUCTOR
//==============================
~Box();

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
  void refresh_box(float A_init); 
  void metab_trade();
  void Cellular_death();
  bool empty_Box();

protected:
//==============================
//    PROTECTED METHODS
//==============================

//==============================
//    ATTRIBUTES
//==============================
  std::vector<float> CONCENTRATIONS_;
  Cell* cell_;
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

#endif // BOX_H
