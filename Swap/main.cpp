/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 22, 2014, 10:20 AM
 * Illustrate -> Pass by Reference, Random Numbers, Overloading functions
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global constants

//Function prototypes
void swap(int &, int &);
void swap(short &, short &);
int iDrvGen();
short sDrvGen();

//Execution begins here
int main(int argc, char** argv) {
    //Init random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Declare local variabless
    short sa,sb;
    int ia,ib;
    //Init variabless
    sa=sDrvGen(); sb=sDrvGen();
    ia=iDrvGen(); ib=sDrvGen();
    //Output before swap
    cout << "Short before swap: " << sa << ", " << sb << endl;
    cout << "Int before swap: " << ia << ", " << ib << endl;
    //Perform swap
    swap(sa,sb); swap(ia,ib);
    //Output after swap
    cout << "Short after swap: " << sa << ", " << sb << endl;
    cout << "Int after swap: " << ia << ", " << ib << endl;
    //Exit, stage right
    return 0;
}

//In-place (bitwise) swap
void swap(int &a, int &b) {
    a=a^b;
    b=a^b;
    a=a^b;
}

//External swap
void swap(short &a, short &b) {
    short temp;
    temp=a;
    a=b;
    b=temp;
}

//Generate a short between 1 and 1001
short sDrvGen() {
    short random=(rand()%1000)+1;
    return random;
}

//Generate an int between 1000 and 9999
int iDrvGen() {
    int random = (rand()%9000)+1000;
    return random;
}