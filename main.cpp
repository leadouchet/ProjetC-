//==============================
//    INCLUDES
//==============================

#include <cstdio>
#include <cstdlib>

#include "Cell.h"
#include "Ga.h"
#include "Gb.h"
#include "Box.h"
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
	cout << B1 -> WhatAmI() << endl;
	cout << B1-> intra_metabolites()[0] << endl;
	cout << B1-> intra_metabolites()[1] << endl;
	cout << B1-> intra_metabolites()[2] << endl;
	std::vector<float> res = B1-> Cell_division();
	cout << B1-> intra_metabolites()[0] << endl;
	cout << B1-> intra_metabolites()[1] << endl;
	cout << B1-> intra_metabolites()[2] << endl;
	
	cout << res[0] << endl;
	cout << res[1] << endl;
	cout << res[2] << endl;
	delete A1;
	delete B1;
	Box* b1 = new Box('a',5);
	delete b1;
	cout << ((double) rand() / (RAND_MAX))  << endl;	
	cout << ((double) rand() / (RAND_MAX))  << endl;
	cout << ((double) rand() / (RAND_MAX))  << endl;
	Box b2 = Box();
	Cell* mother = new Ga(c);
	b2.newborn(mother);
	
}
