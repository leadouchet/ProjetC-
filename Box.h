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
std::vector<float> get_box_metabolites() const;
std::vector<float> get_cell_concentration() const;
char get_cell_type();
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
  bool Cellular_death();
  bool empty_Box();
  void newborn(Cell* mother);
  void update_box(const std::vector<float> C);


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
