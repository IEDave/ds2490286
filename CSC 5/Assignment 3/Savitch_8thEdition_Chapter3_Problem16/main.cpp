/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 19, 2014, 4:15 PM
 * Savitch, 8th Edition - Chapter 3, Problem 16
 * Determine the value at which the Celsius temperature
 * and the Fahrenheit temperature are the same. For this
 * problem I will use a looping construct that calculates
 * Fahrenheit temperatures based on a Celsius index variable
 * in the loop.
 */

// System Libraries
#include <iostream>
using namespace std;

//Global Constants
const int MAX_CELS = 100;
const int MIN_CELS = -100;

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    int dCels = MAX_CELS,dFahr;
    do {
        dCels--;
        dFahr = (9 * dCels)/5 + 32;
    } while (dCels != dFahr && dCels >= MIN_CELS);
    if (dCels < MIN_CELS)
        cout << "No temperature found where Celsius and Fahrenheit are" << endl
             << "equal between " << MAX_CELS << " and " << MIN_CELS
             << " degrees Celsius." << endl;
    else
        cout << "The temperature where Celsius = Fahrenheit is " << dCels
             << " degrees." << endl;
    //Exit, stage right.
    return 0;
}

