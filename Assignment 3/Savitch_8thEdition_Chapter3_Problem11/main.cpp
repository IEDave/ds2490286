/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 19, 2014, 4:45 PM
 * Savitch, 8th Edition - Chapter 3, Problem 11:
 * Use the series "1+x+x^2/2!+x^3/3!... to approximate e^x.
 * No looping constructs are to be used.
 */

//System Libraries
#include <iostream>
#include <cmath>
using namespace std;

//Global Constants
const unsigned int FAC_2 = 2*1;
const unsigned int FAC_3 = 3*2*1;
const unsigned int FAC_4 = 4*3*2*1;
const unsigned int FAC_5 = 5*4*3*2*1;


//Function Prototypes

//Execution starts here
int main(int argc, char** argv) {
    //Define local variables
    float iX, etox;
    //Get user input
    cout << "Enter a value for x: ";
    cin >> iX;
    //Do approximation (5 iterations)
    etox = 1;
    cout << "Approximation of e^" << iX << ": " << etox << endl;
    etox += iX;
    cout << "Approximation of e^" << iX << ": " << etox << endl;
    etox += (iX * iX / FAC_2);
    cout << "Approximation of e^" << iX << ": " << etox << endl;
    etox += (iX * iX * iX / FAC_3);
    cout << "Approximation of e^" << iX << ": " << etox << endl;
    etox += (iX * iX * iX * iX / FAC_4);
    cout << "Approximation of e^" << iX << ": " << etox << endl;   
    etox += (iX * iX * iX * iX * iX / FAC_5);
    cout << "Approximation of e^" << iX << ": " << etox << endl;
    cout << "System generated e^" << iX << ": " << exp(iX) << endl;
    //Exit, stage right!
    return 0;
}

