/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 19, 2014, 6:32 PM
 * Savitch, 8th Edition - Chapter 3, Problem 14:
 * Write a program to find all the prime numbers between 3 and 100
 */
//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Starts Here
int main(int argc, char** argv) {
    //Define local variables
    int outInx,inrInx,mRem;
    bool isPrime = true;
    //The outer loop supplies numbers to test - the inner loop
    //does the actual checking to see if the number is in fact a prime 
    cout << "The list of numbers from 3 to 100 is:" << endl;
    for (outInx=3; outInx <=100; outInx++) {
        isPrime = true;
        for (inrInx=2; inrInx < outInx ; inrInx++) {
            mRem = outInx % inrInx;
            if (mRem == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime)
            cout << outInx << " ";
    }   
    //Exit, stage right.
    return 0;
}

