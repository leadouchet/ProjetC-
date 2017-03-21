#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H 

//==============================
//    INCLUDES
//==============================
#include <vector>
#include <stdlib.h>
#include "Box.h"
#include <iostream>
#include <fstream>
#include <stdio.h> 


using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::ofstream;


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
  Environment(float A_init);

//==============================
//    DESTRUCTOR
//==============================
  ~Environment();
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
  vector<int> Run(float time, float T);
  //go in protected
  void Cycle(); 
  vector<vector<int>>* Cellular_killer();

  vector<int> Best_fit(vector<int> EmptyBox);
  void refresh_Environment();



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
//  float T_;
  float A_init_;
  static const float dt_;
 // ofstream data_csv;
   
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
