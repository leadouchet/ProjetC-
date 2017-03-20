//==============================
//    INCLUDES
//==============================
#include "Environment.h"
#include <vector>
#include <iostream>
#include <stdlib.h> 
#include <stdio.h> 
using std::cout;
using std::endl;
using std::cin;
using namespace std;
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
    vector<char>* tab = new vector<char> (W_*H_);
    grid_ = vector<vector<Box*>>(H_,vector< Box* >(W_));
    for (int i = 0 ; i!=W_*H_/2 ; ++i ){
      (*tab)[i]='a';
    }
    for (int j = W_*H_/2  ; j!=W_*H_; ++j){
      (*tab)[j]='b';
    }
      
    vector<vector<Box*> >::iterator row;
    vector<Box*>::iterator col;
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
vector<int> Environment::toroidal(vector<int> coord)
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


void Environment::diffuse_box(int x, int y){
  vector<float> ABC =  grid_[y][x]-> get_box_metabolites();
	for (int i = -1; i <= 1; ++i){
	  for (int j = -1; j <= 1; ++i){
	    vector<int> xy = {x+i,y+i};
	    vector<int> coord = toroidal(xy);
	    vector<float> NextBox = grid_[coord[1]][coord[0]]-> get_box_metabolites();
	    for (auto it = 0 ; it < 3 ;  ++it){
	      ABC[it] += D_*NextBox[it];
			}
		}
	}
	grid_[y][x] ->  update_box (ABC);
}


void Environment::diffuse_metabolites(){
	for (int y = 0; y < H_ ; ++y){
		for (int x = 0; x < W_; ++x){
			diffuse_box(x,y);
	}
}
}



vector<vector<int>>* Environment::Cellular_killer()
{ vector<vector<int>>* result = new vector<vector<int>>;
  for (int y = 0; y < H_ ; ++y){
    for (int x = 0; x < W_; ++x){
      if (grid_[x][y] -> Cellular_death()){
	result -> push_back(vector<int> {x,y}); 
      } 
      
    }
  }
  return(result);
}

vector<int> Environment::Best_fit(vector<int> EmptyBox)
{
	float Bestfit = 0.0;
  vector<vector<int>>* C = new vector<vector<int>> {};
	for (int i = -1; i <= 1; ++i)
  {
	  for (int j = -1; j <= 1; ++j)
    {
      vector<int> coord = toroidal({EmptyBox[0]+i,EmptyBox[1]+j});
      if (grid_[coord[1]][coord[0]]-> empty_Box() != 0)
      {
        if (grid_[coord[1]][coord[0]]-> get_cell_fitness() == Bestfit)
        {
        C-> push_back(coord); // we put vector of coordinates with the same fitness into a vector        
		}
      if (grid_[coord[1]][coord[0]]-> get_cell_fitness() > Bestfit)
		{
        Bestfit = grid_[coord[1]][coord[0]]-> get_cell_fitness();
        delete C;
        C = new vector<vector<int>> {{coord[0],coord[1]}};
		}
	  }
	}
  }
vector<int> xy = pick_coord(C); //we choose randomly coordinate of the cell having the same best fitness
delete C;
return xy ;
}



 void Environment::Cycle()
 {
 //Cellular Death
   vector< vector<int> >* dead_ones = Cellular_killer();
 //Competition
   for (auto l = dead_ones.size() ; l > 0 ; l--){
     vector<int> coord_empty = pick_coord(dead_ones);
	 coord_best_fit = Best_fit(coord_empty);
     grid_[coord_empty[1]][coord_empty[0]]->newborn( grid_[coord_best_fit[1]][coord_best_fit[0]]->cell_ );
   }
  //Diffusion 	
    diffuse_metabolites(); 
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
    char res = tab->at(r);
    int i = 0;
    for (auto it = tab->begin(); it != tab->end() ; ++it, ++i){
		if (i==r) {
			tab->erase(it);
            break;}
		}
    return res;
}
 
 
  vector<int> Environment::pick_coord (vector< vector<int> >*  tab)
{
    int r;
    if (tab->size() > 1)
        r = rand() % (tab->size()-1);
    else
        r = 0;
    vector<int> res = tab->at(r);
    int i = 0;
    for (auto it = tab->begin(); it != tab->end() ; ++it, ++i){
		if (i==r) {
			tab->erase(it);
            break;}
		}
    return res;  
}
