/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 23, 2014, 2:39 AM
 * Savitch, 8th Edition - Chapter 4, Problem 1:
 * Write a program that accepts the following user input:
 * - Liters consumed
 * - Miles driven
 * and computes the miles per gallon. A function should be used to
 * compute the MPG figure, and the user should be allowed to input
 * data as often as they wish.
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
    float iMiles;
    float iLiters;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter miles driven: ";
        cin >> iMiles;
        cout << "Enter liters of fuel consumed: ";
        cin >> iLiters;
        //compute MPG, display output
        cout << "Miles per gallon: " << compMpg(iMiles, iLiters) << endl;
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

//Function compMpg - takes in distance traveled (in miles) and amount of
//fuel consumed (in liters) - returns MPG.
float compMpg(float iDist, float iUsed) {
    //Define local variable
    float mGal;
    //Calculate MPG, return result
    mGal = iUsed * CNV_LTR;
    return iDist / mGal;
}
