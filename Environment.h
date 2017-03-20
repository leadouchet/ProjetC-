#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H 

//==============================
//    INCLUDES
//==============================
#include <vector>
#include <array>
#include <stdlib.h>
#include "Box.h"
#include <fstream>
#include <iostream>
using namespace std;

/**
 * @class Environment
 * @brief Creates an Environment
 */

class Environment
{
public:
    vector< vector<Box* > > grid_;//(32,std::vector< Box* >(32));
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
  char pick_char (vector<char>* tab);
  vector<int> pick_coord (vector< vector<int> >*  tab);

  vector<vector<int>>* Cellular_killer();
  void Cycle();
  vector<int> Best_fit(vector<int> EmptyBox);
  void Run(float t);

protected:
//==============================
//    PROTECTED METHODS
//==============================
  vector<int> toroidal(vector<int> coord);
  void diffuse_metabolites();
  void diffuse_box(int x, int y);
 
//==============================
//    ATTRIBUTES
//==============================
  int W_; //width
  int H_; //Height
  //  std::vector< std::vector<Box*> > grid_;
  float D_; // diffusion constant
  float T_;
  float A_init_;
  static const float dt_;
  FILE* data;
  
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
