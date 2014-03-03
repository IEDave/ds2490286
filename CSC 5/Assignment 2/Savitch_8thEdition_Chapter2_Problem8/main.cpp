/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 18, 2014, 10:53 AM
 * Savitch, 8th Ed. - Chapter 2, Problem 8
 * Accept user input for annual rate of inflation and item price - calculate
 * estimated price for item over the next 5 years, without using looping
 * constructs.
 * 
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float CNV_PCT_FRA = 1.0e2; // Convert percentage to fraction (/ 100)

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare local variables
    float iPrice, iRate, mRate, dPrice; //Initial item price, 
                                        //rate of inflation, fractional
                                        //percentage and display price
                                        //(adjusted for inflation)
    //Get user inputs
    cout << "Enter current price for item: $";
    cin >> iPrice;
    cout << "Enter rate of inflation in percent: %";
    cin >> iRate;
    // Set up cout object for monetary display of floats
    cout << setprecision(2);
    cout << fixed;
    cout << showpoint;
    //Display initial conditions
    cout << "For year 0 (now) the item price is $" << iPrice
         << " with an inflation rate of " << iRate << "%." << endl;
    //Convert percentage to fraction & init working variable for price
    mRate = iRate / CNV_PCT_FRA;
    dPrice = iPrice;
    // Calculate new item price for 1st year
    dPrice += dPrice * mRate;
    // Display new item price for 1st year
    cout << "For year 1 the item price will be $" << dPrice << endl;
    // Calculate new item price for 2nd year
    dPrice += dPrice * mRate;
    // Display new item price for 2nd year
    cout << "For year 2 the item price will be $" << dPrice << endl;
    // Calculate new item price for 3rd year
    dPrice += dPrice * mRate;
    // Display new item price for 3rd year
    cout << "For year 3 the item price will be $" << dPrice << endl;
    // Calculate new item price for 4th year
    dPrice += dPrice * mRate;
    // Display new item price for 4th year
    cout << "For year 4 the item price will be $" << dPrice << endl;
    // Calculate new item price for 5th year
    dPrice += dPrice * mRate;
    // Display new item price for 5th (and final) year
    cout << "For year 5 the item price will be $" << dPrice << endl;
    //Exit, stage right
    return 0;
}

