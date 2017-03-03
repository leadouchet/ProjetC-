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
    std::vector<char>* tab = new std::vector<char> (W_*H_);

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


void diffuse_box(int x, int y){
	std::vector<float> ABC =  grid_[x][y]-> get_box_concentrations();
	for (int i = -1, i <= 1, ++1){
		for (int j = -1, j <= 1, ++i){
			coord = toroidal(x+i,y+j);
			std::vector<float> NextBox = grid_[coord[0]][coord[1]]-> get_box_concentrations();
			for auto it = 0 ; it < 3 ;  ++it){
				ABC[it] += D_*NextBox[it];
			}
		}
	}
	grid[x][y] =  update_box (ABC);
}

/*
void diffuse_metabolites(){
	for (int y = 0, y < H_ , ++y){
		for (int x = 0, x < W_, ++x){
			for (int i = -1, i <= 1, ++1){
				for (int j = -1
	}

*/

//==============================
//      PRIVATE METHODS
//==============================

  char Environment::pick_char (std::vector<char>* tab)
{
    int r = rand() % (tab->size()-1);
    char rec = tab->at(r);
    int i = 0;
    for (auto it = tab->begin(); it != tab->end() ; ++it, ++i){
		if (i==r) {
			tab->erase(it);}
		}
    return rec;
}
 */
