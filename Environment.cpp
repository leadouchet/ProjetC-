//==============================
//    INCLUDES
//==============================
#include "Environment.h"
#include <vector>
#include <iostream>
#include <stdlib.h>  
using std::cout;
using std::endl;
using std::cin;
//using namespace std;
//==============================
//    DEFINITION STATIC ATTRIBUTES
//==============================

//==============================
//    CONSTRUCTORS
//==============================
  Environment::Environment(){
    W_ = 4;
    H_ = 4;
    A_init_ = 0;
    std::vector<char>* tab = new std::vector<char> (W_*H_);
    grid_ = std::vector<std::vector<Box*>>(H_,std::vector< Box* >(W_));
    for (int i = 0 ; i!=W_*H_/2 ; ++i ){
      (*tab)[i]='a';
    }
    for (int j = W_*H_/2  ; j!=W_*H_; ++j){
      (*tab)[j]='b';
    }
      
    std::vector<std::vector<Box*> >::iterator row;
    std::vector<Box*>::iterator col;
    for (row = grid_.begin(); row != grid_.end(); row++) {
      for (col = row->begin(); col != row->end(); col++) {
        char type = pick_char(tab);
	  (*col) = new Box(type,A_init_);
	  }
    }
    delete tab;
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

  char Environment::pick_char (std::vector<char>* tab)
{
    int r;
    if (tab->size() > 1)
        r = rand() % (tab->size()-1);
    else
        r = 0;
    char rec = tab->at(r);
    int i = 0;
    for (auto it = tab->begin(); it != tab->end() ; ++it, ++i){
		if (i==r) {
			tab->erase(it);
            break;}
		}
    return rec;
}
 
