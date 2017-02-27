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
{
	Ga* A1 = new Ga();
	Gb* B1 = new Gb();
	cout << A1-> WhatAmI()<< endl;
	cout << B1 -> WhatAmI() << endl;
	delete A1;
	delete B1;
	Box* b1 = new Box('a',5);
	delete b1;
	}
