/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 18, 2014, 10:19 PM
 * Savitch, 8th Edition - Chapter 2, Problem 19
 * Input scores & total possible scores for 3 exercises, 
 * then compute total percentage correct vs. total possible.
 * No looping constructs are to be used.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float CNV_FRAC_PCT = 1.0e2; //Conversion factor of 100
//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define Local Variables
    float iScore,iTotal,mCumSco=0,mCumTot=0,dTotPct;
    //Get input for Exercise #1
    cout << "Score for exercise 1: ";
    cin >> iScore;
    cout << "Total points possible for exercise 1: ";
    cin >> iTotal;
    cout << endl;
    //Calculate running total for exercise scores and total possible scores
    mCumSco += iScore;
    mCumTot += iTotal;
    //Get input for Exercise #2
    cout << "Score for exercise 2: ";
    cin >> iScore;
    cout << "Total points possible for exercise 2: ";
    cin >> iTotal;
    cout << endl;
    //Calculate running total for exercise scores and total possible scores
    mCumSco += iScore;
    mCumTot += iTotal;
    //Get input for Exercise #3
    cout << "Score for exercise 3: ";
    cin >> iScore;
    cout << "Total points possible for exercise 3: ";
    cin >> iTotal;
    cout << endl;
    //Calculate running total for exercise scores and total possible scores
    mCumSco += iScore;
    mCumTot += iTotal;
    //Calculate percentage
    dTotPct = mCumSco / mCumTot;
    dTotPct *= CNV_FRAC_PCT;
    //Output result
    cout << setprecision(2);
    cout << fixed;
    cout << showpoint;
    cout << "Total for this student is " << mCumSco << " out of "
         << mCumTot << ", or " << dTotPct << "%." << endl;
    //Exit, stage right
    return 0;
}

