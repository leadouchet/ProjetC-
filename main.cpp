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
void Run_Programme(float time);
//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{	
Run_Programme (100);

}


//==================================================================================================
// RUN FUNCTIONS 
//==================================================================================================

void Run_Programme(float time)
{
    string result;
    vector<int> res;

    result += "T A Survival\n";
    for (float T = 0 ; T <= 1500 ; T += 1500){
        cout << T <<  endl;
        for (float A = 0.0 ; A <= 50 ; A += 50){
            cout << A << endl;
            result += to_string(T) + " " + to_string(A) + " ";
            Environment* E = new Environment(A);
            res = E->Run(time , T);
            delete E;
            if (res[0] == 0){
                result += "extinction \n";
            }
            else if (res[1] == 0){
                result += "exclusion \n";
            }
            else {
                result += "cohabitation \n";
            }
        }
    }
    
    ofstream data_csv;
    data_csv.open("data.csv");
    data_csv << result;
    data_csv.close();
    

}

