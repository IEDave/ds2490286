/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 23, 2014, 3:24 AM
 * Savitch, 8th Edition - Chapter 4, Problem 2:
 * Modification of Program 1 - compare 2 cars by computing MPG
 * for both - display MPG for both, and determine the winner.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CNV_LTR = 2.64179e-1; // 1 liter = 0.264179 gallon. 

//Function prototypes
float compMpg(float,float);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float iCar1M, iCar1L, iCar2M, iCar2L;
    float dCar1M, dCar2M;
    //Get user input - car #1
    cout << "Car #1 - Enter miles driven: ";
    cin >> iCar1M;
    cout << "         Enter liters of fuel consumed: ";
    cin >> iCar1L;
    //Get user input - car #2
    cout << "Car #2 - Enter miles driven: ";
    cin >> iCar2M;
    cout << "         Enter liters of fuel consumed: ";
    cin >> iCar2L;
    //compute MPG, display output
    dCar1M = compMpg(iCar1M, iCar1L);
    dCar2M = compMpg(iCar2M, iCar2L);
    cout << "Car #1 - MPG: " << dCar1M << "   Car #2 - MPG: " << dCar2M << endl;
    //Determine the more fuel efficient car
    if (dCar1M > dCar2M)
        cout << "Car #1 is more fuel efficient than car #2." << endl;
    else if (dCar1M < dCar2M)
        cout << "Car #2 is more fuel efficient than car #1" << endl;
    else
        cout << "Both cars have equal fuel efficiency." << endl;
    //Exit, stage right
    return 0;
}

//Function compMpg - takes in distance traveled (in miles) and amount of
//fuel consumed (in liters) - returns MPG.
float compMpg(float iDist, float iUsed) {
    //Define local variable
    float mGal;
    //Calculate MPG, return result
    mGal = iUsed * CNV_LTR;
    return iDist / mGal;
}
