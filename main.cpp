//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>

#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include "Box.h"
#include "Environment.h"
#include <vector>
#include <list>
#include <iostream>
#include <stdlib.h>  

using std::cout;
using std::endl;
using std::cin;
using namespace std;
//==============================
//    FUNCTION DECLARATION
//==============================

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{	/*srand (time(NULL));
	Ga* A1 = new Ga();
	std::vector<float> c = {1,2,3};
	Gb* B1 = new Gb(c);
	cout << A1-> WhatAmI()<< endl;
	cout << B1-> WhatAmI() << endl;
	cout << B1-> intra_metabolites()[0] << endl;
	cout << B1-> intra_metabolites()[1] << endl;
	cout << B1-> intra_metabolites()[2] << endl;
    B1-> Cell_division();
	cout << B1-> intra_metabolites()[0] << endl;
	cout << B1-> intra_metabolites()[1] << endl;
	cout << B1-> intra_metabolites()[2] << endl;
	delete A1;
	delete B1;
	Box* b1 = new Box('a',5);
	delete b1;
	cout << ((double) rand() / (RAND_MAX))  << endl;	
	cout << ((double) rand() / (RAND_MAX))  << endl;
	cout << ((double) rand() / (RAND_MAX))  << endl;
	Box b2 = Box();
	Cell* mother = new Ga(c);
	cout << mother->WhatAmI() << endl;
	mother-> Cell_division();
	b2.newborn(mother);
	std::vector<float> e = b2.get_cell_concentration();
	cout << e[0] << endl;
	cout << e[1] << endl;
	cout << e[2] << endl;
	cout << b2.get_cell_type() << endl;
	
    delete mother;
    srand (time(NULL));*/
    
    Environment envir = Environment();
    cout << "environment initialized" << endl;
    std::vector<std::vector<Box*> >::iterator row;
    std::vector<Box*>::iterator col;
    for (row = envir.grid_.begin(); row != envir.grid_.end(); row++) {
      for (col = row->begin(); col != row->end(); col++) {
        cout <<(*col)->get_cell_type() << "  ";
	  }
        cout<< endl;
    }
    for (int i = 0; i<10 ; ++i){
      vector<vector<int>>* dead_list = envir.Cellular_killer();
      int r = 0 ;
      for (row = envir.grid_.begin(); row != envir.grid_.end(); row++) {
      	int c = 0;
	for (col = row->begin(); col != row->end(); col++) {
	  cout <<(*col)-> get_cell_type() << " ";
	 if ((*col)-> get_cell_type() == 'X'){
	  	vector<int> coord = {c, r};
	  	cout << "(" << envir.Best_fit(coord)[0] << "," << envir.Best_fit(coord)[1]<<')' <<"  ";
	  }
	  else { 
	  	cout << (*col)-> get_cell_fitness() << "  ";
	  }
	  c++;
	}
	r++;
	cout<< endl;} cout<< endl;
}
}
