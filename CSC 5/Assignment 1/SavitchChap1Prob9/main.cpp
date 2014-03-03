/* 
 * David W. Smith - 1/9/14
 * SavitchChap1Prob9 - From the text: "Write a program that allows the user
 * to enter a time in seconds and then outputs how far an object would drop if
 * it is in free fall for that length of time. Assume that the object starts
 * at rest, there is no friction or resistance from air, and there is a
 * constant acceleration of 32 feet per second due to gravity. Use the
 * equation:  distance = acceleration * time^2 / 2. You should first compute
 * the product then divide by 2 (the reason for this will be discussed later
 * in the book)."
 */

// System functions
#include <iostream>
using namespace std;

// Constants
const float ACCEL = 3.2e1; //Average gravitational acceleration
                           //in Earth's gravity field - 32 ft/sec^2.

// Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    float usrTime, dFall;
    // Get user input for time
    cout << "Input time in seconds: ";
    cin >> usrTime;
    // Calculate distance dropped
    dFall = ACCEL*usrTime*usrTime;
    dFall = dFall/2.0;
    // Output result
    cout << "With a time of (" << usrTime <<
         ") seconds, an object accelerating at" << endl << ACCEL <<
         " feet per second would fall a distance of (" << dFall <<
         ") feet." << endl;
    // Exit, stage right
    return 0;
}

