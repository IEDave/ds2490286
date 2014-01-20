/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 19, 2014, 7:11 PM
 * Savitch, 8th Edition - Chapter 3, Problem 15
 * Using Archimedes' principle of buoyancy, determine of a sphere of a given
 * radius & weight will sink or float in water.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float PI = 3.1415;      //That ever-lovin' pi again... 
const float SPC_WGT = 6.24e1; //Specific weight of water - 62.4 lbs/ft^3
const float SPH_RAT = 4.0e0 / 3.0e0; // Used for calculating the volume
                                     // of a sphere

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float mForceB, mVolSph, iWeight, iRadius;
    //Get user input
    cout << "Enter the weight of the sphere in pounds: ";
    cin >> iWeight;
    cout << "Enter the radius of the sphere in feet: ";
    cin >> iRadius;
    //Calculate volume of the sphere
    mVolSph = SPH_RAT*PI*iRadius*iRadius*iRadius;
    //Calculate buoyant force of the sphere
    mForceB = mVolSph * SPC_WGT;
    //Display numbers & tell user whether the sphere will sink or float.
    cout << "Buoyant force = " << mForceB << " lbs." << endl;
    cout << "Weight of sphere entered by user = " << iWeight << " lbs." << endl;
    if (iWeight <= mForceB)
        cout << "The sphere will float." << endl;
    else
        cout << "The sphere will sink." << endl;
    //Exit, stage right
    return 0;
}

