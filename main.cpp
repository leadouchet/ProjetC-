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

//==============================
//    FUNCTION DECLARATION
//==============================

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{	srand (time(NULL));
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
    mother-> Cell_division();
	b2.newborn(mother);
    std::vector<float> e = b2.get_cell_concentration();
    cout << e[0] << endl;
    cout << e[1] << endl;
    cout << e[2] << endl;
	delete mother;
    srand (time(NULL));
    
    Environment envir = Environment();
    std::vector<char>* tab = new std::vector<char> {'a','b','c','d','e'};
    char lettre = envir.pick_char(tab);
    cout << lettre << endl;
    cout << tab->at(0) << tab->at(1) << tab->at(2) << tab->at(3) << endl;
    delete tab;

}
