/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 30, 2014, 5:32 PM
 * Midterm Problem #4 - Employee Gross Pay
 */

//System Variables
#include <iostream>
#include <iomanip>
using namespace std;

//Global constants
const float CVT_DBL = 2.0e0;  //Double time - 2x straight time.
const float CVT_TRP = 3.0e0;  //Triple time - 3x straight time.
const float HRS_DBL = 2.0e1;  //Double time starts at 20 hrs.
const float HRS_TRP = 4.0e1;  //Triple time starts at 40 hrs.

//Function Prototypes
float calcPay(float,float);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float usrHrs, usrRate;
    char iCont='Y';
    cout << setprecision(2) << fixed << showpoint;
    do {
        //Get user input
        cout << "Enter employee base pay rate: ";
        cin >> usrRate;
        cout << "Enter hours worked: ";
        cin >> usrHrs;
        //Error check & calculate pay
        if ((usrHrs > 0.0) && (usrRate > 0.0)) {
            cout << "Gross pay for this employee is $"
                 << calcPay(usrHrs,usrRate) << "." << endl;
        } else
            cout << "Error on input." << endl;
        //Confirm with user - are we done?
        cout << "Do you wish to continue(Y/N)?";
        cin >> iCont;
        (iCont == 'y')?iCont = 'Y':iCont=iCont;
        cout << endl << endl;
    } while(iCont == 'Y');
    //Exit, stage right!
    return 0;
}

float calcPay(float hours, float payRate) {
    //Define local variables
    float totPay = 0.0e0;
    //Calculate gross pay
    if (hours > HRS_TRP) {
         totPay += ((hours - HRS_TRP) * (CVT_TRP * payRate));
         hours -= (hours - HRS_TRP);
    }
    if (hours > HRS_DBL) {
         totPay += ((hours - HRS_DBL) * (CVT_DBL * payRate));
         hours -= (hours - HRS_DBL);
    }
    if (hours > 0.0) {
         totPay += hours * payRate;
    }  

    return totPay;
}


