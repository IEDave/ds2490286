/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 16, 2014, 10:38 AM
 * Savitch, 8th Ed. - Chapter 2 problem 1: 
 * Get the weight of a box of breakfast cereal in ounces and determine the
 * weight of the box in fraction of a metric ton. Also, determine how many
 * boxes it would take to yield 1 metric to on cereal. Per class specification
 * eliminate any repetition (e.g. no looping constructs).
 */
//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CNV_MT_OZ = 35273.92; // 1 Metric Ton = 35273.92 ounces.

//Function Prototypes
int main(int argc, char** argv) {
    //Define Local Variables
    float iCerWt, dCerMTn;
    unsigned int dCerPkg;
    // Get user input - weight of a cereal package in ounces
    cout << "What is the weight of a cereal package in ounces? ";
    cin >> iCerWt;
    // Calculate weight of a cereal package in metric tons
    dCerMTn = iCerWt / CNV_MT_OZ;
    dCerPkg = CNV_MT_OZ / iCerWt;
    // Output calculated weight
    cout << "The weight of the cereal package is ("
         << dCerMTn << ") metric tons." << endl;
    cout << "The number of packages to make 1 metric ton = ("
         << dCerPkg << ")." << endl;
    //Exit, stage right
    return 0;
}

