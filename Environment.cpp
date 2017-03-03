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
/**
  char randel (std::vector<char>& tab)
{
    int r = rand() % (tab.size() - 1) 
    char rec = tab[r];
    tab.splice (r, 1);
    return rec;
}
 */
