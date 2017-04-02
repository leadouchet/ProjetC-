#ifndef BOX_H
#define BOX_H

//======================================================================
//                           INCLUDES
//======================================================================
#include <vector>
#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include <cstdio>
#include <stdlib.h>


/**
 * @class Box
 * @brief Creates a Box associated to environment
 */

class Box
{
public:
//======================================================================
//                           CONSTRUCTORS
//======================================================================
  Box();
  Box(char type, float A_init);
	
//======================================================================
//                           DESTRUCTOR
//======================================================================
  ~Box();

//======================================================================
//                            GETTERS
//======================================================================
  vector<float>*          get_box_metabolites() ;
  vector<float>           get_cell_concentration();
  vector<float>*          get_box_next_metabolites();
  char                    get_cell_type();
  float                   get_cell_fitness();




//======================================================================
//                       PUBLIC ATTRIBUTES
//======================================================================
  Cell*                   cell_;                                        //essayer de le passer en protected



//======================================================================
//                         PUBLIC METHODS
//======================================================================
  void                    refresh_box(float A_init); 
  void                    metab_trade();
  bool                    Cellular_death();
  bool                    empty_Box();
  void                    newborn(Cell* mother);
  void                    update_diffusion();

protected:

//======================================================================
//                           ATTRIBUTES
//======================================================================
  std::vector<float>* 	  CONCENTRATIONS_;
  std::vector<float>* 	  Next_CONCENTRATIONS_;

};




#endif // BOX_H
