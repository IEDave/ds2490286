/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 28, 2014, 2:34 AM
 * CSC17A Midterm #5 - Factorial fun!
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Structures

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    double fctrial=1;
    unsigned short lim;
    cout << "How big a factorial do you want to do?";
    cin >> lim;
    for (unsigned short i=1; i<=lim; i++) {
        fctrial *= i;
        cout << i << "! = " << fctrial << endl;
    }
    return 0;
}

