/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 25, 2014, 9:05 PM
 * Savitch, 8th Edition - Chapter 4, Problem 7:
 * Write a program to calculate the gravitational
 * attraction between 2 bodies. Define the universal
 * gravitational constant G as a global constant, and
 * use a function to return the force in dynes. Inputs
 * for mass shall be in grams, and distance shall be in
 * centimeters (CGS units);
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float UNIV_G = 6.673e-8; //Universal gravitational constant

//Function Prototypes
float cGrvFrc(float,float,float);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float iMass1 = 0, iMass2 = 0, iDist = 0, dForce;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter mass of body #1 in grams: ";
        cin >> iMass1;
        cout << "Enter mass of body #2 in grams: ";
        cin >> iMass2;
        cout << "Enter distance between bodies in centimeters: ";
        cin >> iDist;
        //Call function and display result.
        cout << "The force between the 2 masses at the specified distance "
             << "is " << cGrvFrc(iMass1,iMass2,iDist) << " dynes." << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    //Exit, stage right
    return 0;
}

//Calculate the gravitational attraction between 2 masses at a specified
//distance using Newton's gravitational law.
float cGrvFrc(float mMass1, float mMass2, float mDist) {
    return (UNIV_G * mMass1 * mMass2) / (mDist * mDist);
}

