//==============================
//    INCLUDES
//==============================
#include "Environment.h"
#include <vector>
//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
  Environment::Environment(){
    W_ = 32;
    H_ = 32;
    A_init_ = 0;
    
  }
  
  
//==============================
//    DESTRUCTOR
//==============================

//==============================
//    PUBLIC METHODS
//==============================


//==============================
//    PROTECTED METHODS
//==============================
std::vector<int> Environment::toroidal(std::vector<int> coord)
{
  int i = coord[0];
  int j = coord[1];
  if (i<0){
    if (j<0){
      return {H_-1,W_-1};
    }
    if (j>(W_-1)){
      return {H_-1,0};
    }
    return {H_-1,j};
  }
  if (i>(H_-1)){
    if (j<0){
      return {0,W_-1};
    }
    if (j>(W_-1)){
      return {0,0};
    }
    return {0,j}; 
  }
  if (j>(W_-1)){
    return {i,0};
  }
  if (j<0){
    return {i,W_-1};
    }
  return {i,j};
}


//==============================
//      PRIVATE METHODS
//==============================
/**
  char randel (std::vector<char>& tab)
{
    int r = rand() % (tab.size() - 1) 
    char rec = tab[r];
    tab.splice (r, 1);
    return rec;
}
 */
