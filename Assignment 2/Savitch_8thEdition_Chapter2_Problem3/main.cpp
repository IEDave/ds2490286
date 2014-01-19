/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 16, 2014, 11:35 AM
 * Savitch, 8th Edition - Chapter 2, Problem 3:
 * Get user's previous annual salary as input - calculate the retroactive
 * pay increase (6 months @ 7.6%), the new annual & monthly salary and
 * display result.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global constants
const float PAY_INCR = 7.6e-2; //Retroactive pay increase = 7.6%
const float CNV_SIX_M = 2.0e0; //Retroactive pay period = 6 months
                               //or 1/2 calendar year
const float CNV_ONE_M = 1.2e1; //New monthly salary = 1/12 new annual
                               //salary

//Function prototypes

int main(int argc, char** argv) {
    //Local variables
    float iOldSal,dNewSal,dNewMon,dRetro;
    //Get previous salary
    cout << "What was your previous annual salary?" << endl;
    cin >> iOldSal;
    //Calculate new annual salary
    dNewSal = iOldSal;
    dNewSal += iOldSal * PAY_INCR;
    //Calculate retroactive pay
    dRetro = dNewSal / CNV_SIX_M;
    //Calculate new monthly salary
    dNewMon = dNewSal / CNV_ONE_M;
    //Display calculated salaries
    cout << setprecision(2);
    cout << fixed;
    cout << showpoint;
    cout << "Your new annual salary is $" << dNewSal << endl;
    cout << "Your new monthly salary is $" << dNewMon << endl;
    cout << "You will also be receiving $" << dRetro;
    cout << " in retroactive pay." << endl << "Congratulations!" << endl;
    //Exit, stage right.
    return 0;
}

