/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 30, 2014, 3:07 PM
 * Midterm problem 5 - ISP billing
 */

//System Variables
#include <iostream>
#include <iomanip>
using namespace std;

//Global constants
const float CUTOFF1 = 1.1e1;   //11 hours
const float CUTOFF2 = 2.2e1;   //22 hours
const float CUTOFF3 = 3.3e1;   //33 hours
const float BASERTA = 2.995e1; //$29.95 - plan a base rate
const float BASERTB = 3.495e1; //$34.95 - plan b base rate
const float BASERTC = 3.975e1; //$39.75 - plan c base rate
const float CUTOF1A = 2.75e0;  //$2.75 - level 1 overage plan a
const float CUTOF1B = 1.50e0;  //$1.50 - level 1 overage plan b
const float CUTOF1C = 0.0e0;   //$0.00 - level 1 overage plan c
const float CUTOF2A = 5.0e0;   //$5.00 - level 2 overage plan a
const float CUTOF2B = 2.5e0;   //$2.50 - level 2 overage plan b (hourly)
const float CUTOF2C = 0.0e0;   //$0.00 - level 2 overage plan c

//Function Prototypes
float clcBill(float, char);
bool isPlan(char &);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float usrHrs;
    char iPlan, iCont='Y';
    cout << setprecision(2) << fixed << showpoint;
    do {
        //Explain plans, then get user selection
        cout << "Welcome to CSC ISP billing!" << endl;
        cout << "We have 3 billing plans:" << endl;
        cout << "Plan 'A' - $"<<BASERTA<<"/month for the first 11 hours access."
                <<endl;
        cout << "           The next 11 hours of usage costs $" << CUTOF1A
             << ", with"<<endl;
        cout << "           additional hours costing only $" << CUTOF2A
             << ". "<< endl;
        cout << "Plan 'B' - $"<<BASERTB<<"/month for the first 22 hours access."
             << endl;
        cout << "           The next 11 hours of access costs just $" << CUTOF1B
             << ", with"<<endl;
        cout << "           additional hours costing only $" << CUTOF2B
             << " per hour! "<< endl;
        cout << "Plan 'C' - $"<<BASERTC<<"/month, with unlimited usage - our "
             << "most popular plan!" << endl;

        cout << "Enter plan: ";
        cin >> iPlan;
        cout << "Enter hours: ";
        cin >> usrHrs;
        //Error check
        if (isPlan(iPlan) && (usrHrs > 0.0)) {
            cout << "Your bill for this month is $"
                 << clcBill(usrHrs,iPlan) << "." << endl;
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

bool isPlan(char &plan){
    //Coerce to uppercase
    if ((plan >='a') && (plan <= 'c')) {
        plan = plan - 'a' + 'A';
    }
    //Is it between 'A' & 'C'?
    if ((plan >='A') && (plan <= 'C'))
        return true;
    else 
        return false;
}
  

float clcBill(float hours, char tier) {
    //Define local variables
    float totBill = 0.0e0;
    //Calculate bill
    switch(tier) {
        case 'A':
            if (hours > CUTOFF2) {
                totBill += CUTOF2A;
            }
            if (hours > CUTOFF1) {
                totBill += CUTOF1A;
            }
            if (hours > 0) {
                totBill += BASERTA;
            }      
            break;
        case 'B':
            if (hours > CUTOFF3) {
                totBill += ((hours - CUTOFF3) * CUTOF2B);
            }
            if (hours > CUTOFF2) {
                totBill += CUTOF1B;
            }
            if (hours > 0) {
                totBill += BASERTB;
            }  
            break;
        case 'C':
            totBill = BASERTC;
            break;
    }
    return totBill;
}

