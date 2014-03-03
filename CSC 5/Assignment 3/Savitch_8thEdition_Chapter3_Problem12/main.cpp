/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 19, 2014, 5:40 PM
 * Savitch, 8th Edition - Chapter 3, Problem 12:
 * Approximate the value of pi using the series
 * 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9...). We will do
 * this for 5 iterations, and no looping constructs
 * are to be used.
 */

//System Libraries
#include <iostream>
using namespace std;

// Global Constants
const float APPROX_PI = 4.0e0;

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float mSerFac, dApprox;
    //Calculate successive approximations of pi, displaying as we do so.
    mSerFac = 1.0;
    dApprox = APPROX_PI * mSerFac;
    cout << "Initial approximation = " << dApprox << endl;
    mSerFac -= (1.0/3.0);
    dApprox = APPROX_PI * mSerFac;
    cout << "Next approximation = " << dApprox << endl;
    mSerFac += (1.0/5.0);
    dApprox = APPROX_PI * mSerFac;
    cout << "Next approximation = " << dApprox << endl;
    mSerFac -= (1.0/7.0);
    dApprox = APPROX_PI * mSerFac;
    cout << "Next approximation = " << dApprox << endl;
    mSerFac += (1.0/9.0);
    dApprox = APPROX_PI * mSerFac;
    cout << "Next approximation = " << dApprox << endl;
    //Exit, stage right.
    return 0;
}

