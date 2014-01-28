/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on January 13, 2014, 10:34 AM
 * Modified January 27th, 2014 by David W.Smith
 * Truth Table
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int NUM_ROWS = 4;

//Function Prototypes
void printrow(bool,bool);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    bool x=true,y=true;
    //Output the table heading
    cout<<"X Y !X !Y X&&Y X||Y X^Y X^Y^Y X^Y^X "
        <<"!(X&&Y) !X||!Y !(X||Y) !X&&!Y"<<endl;
    for (int i=1; i<=NUM_ROWS; i++) {
        switch(i){
            case 1:
                x=true,y=true;
                printrow(x,y);
                break;
            case 2:
                x=true,y=false;
                printrow(x,y);
                break;
            case 3:
                x=false,y=true;
                printrow(x,y);
                break;
            case 4:
                x=false,y=false;
                printrow(x,y);
                break;      
        }
    }
    //Exit, stage right
    return 0;
}
void printrow(bool x, bool y){
    cout<<(x?'T':'F')<<" ";
    cout<<(y?'T':'F')<<"  ";
    cout<<(!x?'T':'F')<<"  ";
    cout<<(!y?'T':'F')<<"   ";
    cout<<(x&&y?'T':'F')<<"    ";
    cout<<(x||y?'T':'F')<<"   ";
    cout<<(x^y?'T':'F')<<"    ";
    cout<<(x^y^y?'T':'F')<<"     ";
    cout<<(x^y^x?'T':'F')<<"      ";
    cout<<(!(x&&y)?'T':'F')<<"       ";
    cout<<(!x||!y?'T':'F')<<"      ";
    cout<<(!(x||y)?'T':'F')<<"       ";
    cout<<(!x&&!y?'T':'F')<<"  ";
    cout<<endl;
    return;
}


