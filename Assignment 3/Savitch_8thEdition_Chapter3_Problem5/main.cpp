/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 19, 2014, 1:58 PM
 * Savitch, 8th Edition - Chapter 3, Problem 5:
 * Compute the cost of a long-distance call.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const short CNV_DIG = 48;  //ASCII '0'
const short CNV_HRS = 100; //Shifting 2 places to the left
const float TOP_RT = 4.0e-1, MID_RT = 2.5e-1, MIN_RT = 1.5e-1;

//Function Prototypes

//Execution starts here
int main(int argc, char** argv) {
    //Define Local Variables
    char msdHour,lsdHour,colon,msdMin,lsdMin; //Start time of call
    char mscDOW,lscDOW; //Day of the Week
    unsigned int calLen, mCalHrs, mCalMin, mCalTim;
    float mBilRt, dCost;
    bool badNum = false;
    bool badDOW = false;
    //Get user input
    cout << "Enter start time of call in military format (04:14): ";
    cin >> msdHour >> lsdHour >> colon >> msdMin >> lsdMin;
    cout << "Enter day of the week the call was placed" << endl
         << "(Mo,Tu,We,Th,Fr,Sa,Su): ";
    cin >> mscDOW >> lscDOW;
    cout << "Enter the duration of the call in minutes: ";
    cin >> calLen;
    //Convert time input to integer, flag bad input
    mCalHrs = (static_cast<unsigned int>(msdHour) - CNV_DIG) * 10 +
              (static_cast<unsigned int>(lsdHour) - CNV_DIG);
    mCalMin = (static_cast<unsigned int>(msdMin) - CNV_DIG) * 10 +
              (static_cast<unsigned int>(lsdMin) - CNV_DIG);
    if (mCalHrs > 23 || mCalMin > 59)
        badNum = true;
    else
        mCalTim = mCalHrs * CNV_HRS + mCalMin;
    //Convert Day of Week into uppercase, flag bad input
    if (mscDOW == 'm' || mscDOW == 't' || mscDOW == 'w' || mscDOW == 'f' ||
        mscDOW == 's')
            mscDOW = mscDOW - 'a' + 'A';
    if (lscDOW == 'o' || lscDOW == 'u' || lscDOW == 'e' || lscDOW == 'h' ||
        lscDOW == 'r' || lscDOW == 'a')
            lscDOW = lscDOW - 'a' + 'A';
    if (!(mscDOW == 'M' || mscDOW == 'T' || mscDOW == 'W' || mscDOW == 'F' ||
        mscDOW == 'S'))
            badDOW = true;
    if (!(lscDOW == 'O' || lscDOW == 'U' || lscDOW == 'E' ||
        lscDOW == 'H' || lscDOW == 'R' || lscDOW == 'A'))
            badDOW = true;
    //Determine billing rate and total amount billed
    if (!badNum && !badDOW) {
        if ((mCalTim >= 800 && mCalTim <= 1800) && mscDOW != 'S')
            mBilRt = TOP_RT;
        else if (mscDOW == 'S')
            mBilRt = MIN_RT;
        else
            mBilRt = MID_RT;
        dCost = mBilRt * calLen;
        //Display cost of call
        cout << setprecision(2);
        cout << fixed;
        cout << showpoint;
        cout << "Cost of call: $" << dCost << endl;
    } else
        cout << "Invalid input." << endl;
    //Exit, stage right
    return 0;
}

