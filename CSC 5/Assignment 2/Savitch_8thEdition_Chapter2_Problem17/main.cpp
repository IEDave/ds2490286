/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 18, 2014, 7:50 PM
 * Savitch, 8th Edition - Chapter 2, Problem 17:
 * Calculate volume of well casing to determine whether a separate
 * holding tank is necessary. Volume of well casing is v = r*r*h
 * where v = volume, r is radius of well casing & h is depth of well from
 * top of local water table to bottom of well.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float PI = 3.1415;          //The world-famous pi...
const float CNV_IN_FT = 1.2e1;    //12 inches = 1 foot
const float CNV_VOL_GAL = 7.48e0; //1 cubic foot of water = 7.48 gallons
const float TYP_FAM = 2.5e2;      //Typical family of 4 uses 250 gallons
                                  //per day

//Function Prototypes

//Execution starts here
int main(int argc, char** argv) {
    //Define local variables
    float iRadius,iDepth,mRadius,mVolume,dVolume;
    //Get user input
    cout << "Enter radius of well in inches: ";
    cin >> iRadius;
    cout << "Next, enter depth of well from top of"
         << " water table to bottom of well." << endl
         << "Enter depth of well in feet: ";
    cin >> iDepth;
    //Calculate volume of water in well casing & amount of
    //water stored in gallons
    mRadius = iRadius / CNV_IN_FT;
    mVolume = PI * mRadius * mRadius * iDepth;
    dVolume = mVolume * CNV_VOL_GAL;
    //Display final output
    cout << "For a family of 4, it is estimated that they will use "
         << TYP_FAM << " gallons" << endl;
    cout << "of water per day. This "
         << "well, with a radius of (" << iRadius << ") "
         << "inches and a usable" << endl; 
    cout << "depth of (" << iDepth << ") feet, has a usable volume of "
         << mVolume << " cubic feet containing" << endl;
    cout << dVolume << " gallons of water. This is ";
    if (dVolume < TYP_FAM)
        cout << "insufficient";
    else
        cout << "sufficient";
    cout << " for a typical 4 person family." << endl;
    //Exit, stage right.
    return 0;
}

