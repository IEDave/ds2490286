/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 23, 2014, 3:51 AM
 * Savitch, 8th Edition - Chapter 4, Problem 4:
 * Write a program that accepts the following user input:
 * - Price of an item 1 year ago
 * - Price of the same item today
 * and estimate the rate of inflation by dividing the current
 * price by the year-ago price. The user should be allowed to input
 * data as often as they wish.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float CNV_PERC = 1.0e2; //Convert to percent = (fraction * 100) - 100. 

//Function prototypes
float compInf(float,float);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float iYrAgo, iToday;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter item price 1 year ago: ";
        cin >> iYrAgo;
        cout << "Enter item price today: ";
        cin >> iToday;
        //compute MPG, display output
        cout << setprecision(2) << fixed << showpoint;
        cout << "Estimated rate of inflation: " << compInf(iYrAgo, iToday) <<"%"
             << endl;
        cout << "(Negative rate of inflation indicates error or deflation.)"
             << endl;
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

//Function compInf - Estimates rate of inflation by comparing current
//item price to year ago item price
float compInf(float iLastYr, float iThisYr) {
    //Define local variable
    float mInfRt;
    //Calculate inflation rate, convert to percentage
    if (iLastYr != 0.0) {
        mInfRt = iThisYr / iLastYr;
        //convert to percentage & return
        return mInfRt * CNV_PERC - CNV_PERC;
    }
    else 
        return -1;
}

