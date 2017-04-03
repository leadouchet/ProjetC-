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
using std::string;
using std::to_string;

//==============================
//    FUNCTION DECLARATION
//==============================
string eco_link(vector<int> res);
void Run_Programme(float time, float Pmut, float D);
void Run_Programme_opti(float time, float Pmut, float D);

//==============================
//    MAIN
//==============================

int main(int argc, char const *argv[])
{	

Run_Programme(10000.0, 0.0, 0.1);

}


//==================================================================================================
// RUN FUNCTIONS 
//==================================================================================================



string eco_link(vector<int> res)
{
    if (res[1]==0){
        return("exclusion \n");
    }
    else if (res[0]/res[1] > 300){
        return("exclusion \n");
    }
    
    else if (res[0] == 0){
        return("extinction \n");
    }
    else if (res[1]/res[0] > 300){
        return("extinction \n");
    }
    return("cohabitation \n");
}




void Run_Programme(float time, float Pmut, float D)
{
    string result;
    vector<int> res;

    result += "T A nb_B Survival\n";
    for (float T = 0 ; T <= 1500 ; T += 500)
    {
        cout << "T : " << T <<  endl;
        for (float A = 0 ; A <= 50 ; A += 10)
        {
            cout << "  A : " << A << endl;
            result += to_string(T) + " " + to_string(A) + " ";
            Environment* E = new Environment(A);
            res = E->Run(time , T);
            delete E;
            cout << to_string(res[1]) << "  " << eco_link(res) <<endl;
            result += to_string(res[1]) + " " + eco_link(res);
        }
    }
    
    ofstream data_csv;
    data_csv.open("dataTest.csv");
    data_csv << result;
    data_csv.close();
    

}

void Run_Programme_opti(float time, float Pmut, float D)
{
    string result;
    vector<int> up;
    vector<int> down;
    vector<int> middle;
    string ecological_link_up;
    string ecological_link_down;
    string ecological_link_middle;


    result += "T A Survival\n";
    for (int A = 0 ; A <= 50 ; A += 10)
    {
        cout << "A : " << A <<  endl;
        float T_up = 1500.0;
        float T_down = 0.0;
        
        Environment* E_up = new Environment(A);
        up = E_up->Run(time, T_up);
        ecological_link_up = eco_link(up);
        result += to_string(T_up) + " " + to_string(A) + " " + ecological_link_up;
        delete E_up;
        
        
        Environment* E_down = new Environment(A);
        down = E_down->Run(time, T_down);
        ecological_link_down = eco_link(down);
        result += to_string(T_down) + " " + to_string(A) + " " + ecological_link_down;
        delete E_down;

        
        //if(ecological_link_down != ecological_link_up)
        
            for (int i = 0 ; i<2 ; i++)
            {
                Environment* E_middle = new Environment(A);
                float T_middle = (T_down+T_up)/2;
                middle = E_middle->Run(time, T_middle);
                ecological_link_middle = eco_link(middle);
                result += to_string(T_middle) + " " + to_string(A) + " " + ecological_link_middle;
            
                if (ecological_link_middle == ecological_link_down)
                {
                    T_down = T_middle;
                    down = middle;
                }
                else if (ecological_link_middle == ecological_link_up )
                {
                    T_up = T_middle;
                    up = middle;
                }
                else {break;}
                delete E_middle;
            }

    }
    
    ofstream data_csv;
    data_csv.open("data.csv");
    data_csv << result;
    data_csv.close();
    
}
