#ifndef BOX_H
#define BOX_H

//==============================
//    INCLUDES
//==============================
#include <vector>
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
using namespace std;

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
vector<float> get_box_metabolites() ;
vector<float> get_cell_concentration();
char get_cell_type();
float get_cell_fitness();
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
