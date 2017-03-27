#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H 

//======================================================================
//                         INCLUDES
//======================================================================
//#include <vector>
#include <stdlib.h>
#include "Box.h"
#include <iostream>
#include <fstream>
#include <stdio.h> 


using std::cout;
using std::endl;
using std::cin;
//using std::vector;
using std::ofstream;


/**
 * @class Environment
 * @brief Creates an Environment
 */


class Environment
{
public:
//======================================================================
//                          CONSTRUCTORS
//======================================================================
  Environment();
  Environment(float A_init);

//======================================================================
//                           DESTRUCTOR
//======================================================================
  ~Environment();
  
//======================================================================
//                          PUBLIC METHODS
//======================================================================
  char                  pick_char (vector<char>* tab);
  vector<int>           pick_coord (vector< vector<int> >*  tab);
  vector<int>           Run(float time, float T);




protected:
//======================================================================
//                       PROTECTED METHODS
//======================================================================
  vector<int>           toroidal(vector<int> coord);
  void                  diffuse_metabolites();
  void                  diffuse_box(int x, int y);
  void                  Cycle(); 
  vector<vector<int>>*  Cellular_killer();
  vector<int>           Best_fit(vector<int> EmptyBox);
  void                  refresh_Environment();
 
 
//======================================================================
//                          ATTRIBUTES
//======================================================================
  int                   W_;                                             //Width
  int                   H_;                                             //Height
  vector<vector<Box*>>  grid_;
  float                 D_;                                             //Diffusion constant
  float                 A_init_;
  static const float    dt_;
};


#endif // ENVIRONMENT_H
