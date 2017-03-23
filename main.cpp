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
#include <fstream> 

using std::cout;
using std::endl;
using std::cin;
using std::ofstream;
using std::vector;

//==============================
//    FUNCTION DECLARATION
//==============================
void Run_Programme(float time, float Pmut, float D);
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
    
/*    Environment envir;
    cout << "environment initialized" << endl;
    vector<std::vector<Box*> >::iterator row;
    vector<Box*>::iterator col;
    for (row = envir.grid_.begin(); row != envir.grid_.end(); row++) {
      for (col = row->begin(); col != row->end(); col++) {
        cout <<(*col)->get_cell_type() << "  ";
	  }
        cout<< endl;
    }cout<< endl;
 for (int i = 0; i<10 ; ++i){
        envir.Cycle();
        for (row = envir.grid_.begin(); row != envir.grid_.end(); row++) {
            for (col = row->begin(); col != row->end(); col++) {
                cout <<(*col)->get_cell_type() <<" "<< (*col)->get_cell_fitness() <<"   ";
	}
	cout<< endl;} cout<< endl;
}*/


Run_Programme (100, 0.0, 0.1);

}


//==================================================================================================
// RUN FUNCTIONS 
//==================================================================================================

void Run_Programme(float time, float Pmut, float D)
{
	ofstream data_csv;
	data_csv.open("data.csv");
	if (data_csv.is_open())
	{
    data_csv << "T" << " A" << " Survival" << endl;
		for (int T = 1 ; T <= 1500 ; T += 100){ 
      cout << T <<  endl;
			for (int A = 0 ; A <= 50 ; A += 5){
				data_csv << T << " " << A << " ";
				Environment* E = new Environment(A);
				vector<int> res = E-> Run(time , T);
				delete E;
				if (res[0] == 0){
					data_csv << "extinction" << endl;
				}
				else if (res[1] == 0){
					data_csv << "exclusion" << endl;
				}
				else {
					data_csv << "cohabitation" << endl;
        }
			}
		}
		data_csv.close();
	}
	else {
		cout << "File could not be open !" << endl;
	}

}

