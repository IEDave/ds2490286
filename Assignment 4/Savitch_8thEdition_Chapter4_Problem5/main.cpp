/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 23, 2014, 4:17 AM
 * Savitch, 8th Edition - Chapter 4, Problem 5:
 * Modify program to estimate prices one and two
 * years from now, based on current estimated
 * inflation rate. Write function to accomplish this.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float CNV_PERC = 1.0e2; //Convert to percent = (fraction * 100) - 100. 

//Function prototypes
float compInf(float,float);
float cFutPri(float,float);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float iYrAgo, iToday, mRate, dFut1Yr, dFut2Yr;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter item price 1 year ago: ";
        cin >> iYrAgo;
        cout << "Enter item price today: ";
        cin >> iToday;
        //compute MPG, display output
        mRate = compInf(iYrAgo, iToday);
        cout << setprecision(2) << fixed << showpoint;
        cout << "Estimated rate of inflation: " << mRate <<"%"
             << endl;
        cout << "(Negative rate of inflation indicates error or deflation.)"
             << endl;
        dFut1Yr = cFutPri(mRate,iToday);
        dFut2Yr = cFutPri(mRate,dFut1Yr);
        cout << "Estimated price for next year: $" << dFut1Yr << endl;
        cout << "Estimated price 2 years from now: $" << dFut2Yr << endl;
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

//Function cFutPri - Estimates future price based on current price &
//inflation rate.
float cFutPri(float iRate, float iPrice) {
    return iPrice * (iRate / CNV_PERC) + iPrice;
}
