/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 18, 2014, 4:22 PM
 * Savitch, 8th Edition - Chapter 2, Problem 16:
 * Take program supplied in problem, and convert it to a more readable form.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float PI = 3.1415e0;           //The world-famous pi...
const float ARC_RAT = 4.0e0 / 3.0e0; //Archimedes Ratio - 2/3 the volume of a
                                     //circumscribed cylinder

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float iRadius, dVolume;
    //Get user input - radius of the sphere
    cout << "Enter the radius of the sphere: ";
    cin >> iRadius;
    //Calculate volume of the sphere
    dVolume = ARC_RAT * PI * iRadius * iRadius * iRadius;
    //Display sphere volume
    cout << "The volume of a sphere with radius (" << iRadius
         << ") is " << dVolume << " units." << endl;
    //Exit, stage right
    return 0;
}

