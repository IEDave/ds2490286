/*
 * David W. Smith - 1/8/14
 * SavitchChap1Prob #8 - Ask user for the number of nickels, dimes & quarters
 * then display the monetary value of the coins in cents.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float NICKEL=5.0e-2;  // Nickel = $0.05
const float DIME=1.0e-1;    // Dime = $0.10
const float QUARTER=2.5e-1; // Quarter = $0.25

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Declare local variables
    int usrNckl, usrDime, usrQtr, cnv2Bux, dspDolr, dspCent,
        lsdCent, msdCent;
    float totAmt;
    //Get User Input
    cout << "How many nickels do you have? ";
    cin >> usrNckl;
    cout << "How many dimes do you have? ";
    cin >> usrDime;
    cout << "How many quarters do you have? ";
    cin >> usrQtr;
    //Calculate total monetary value - need to cast user input
    // to floating point value to get proper dollars & cents.
    totAmt = static_cast<float>(usrNckl)*NICKEL +
             static_cast<float>(usrDime)*DIME +
             static_cast<float>(usrQtr)*QUARTER;
    // To get dollars & cents to display correctly without using formatting
    // tools, we're going to get a bit cute.
    // First, we'll add 0.005 to the total amount to ensure that
    // proper rounding takes place, then multiply by 100 to move the
    // decimal point 2 places to the right, storing result in an
    // intermediate integer variable to truncate extraneous digits.
    cnv2Bux = (totAmt + .005) * 100;
    // Now, to display the dollars & cents we'll first do an integer divide
    // by 100 on the intermediate variable to get the dollars, and a modulo
    // divide by 100 to get the cents.
    dspDolr = cnv2Bux / 100;
    dspCent = (cnv2Bux % 100);
    // The cents provide a special challenge because values less than 10
    // don't display a leading zero, and we need to always display 2 digits.
    // To accomplish this we do an integer divide by 10 to display the leading
    // digit of the cents, and a modulo divide by 10 to display the trailing
    // digit of the cents. Thus, no matter how many cents we have, we're
    // covered.
    msdCent = dspCent / 10;
    lsdCent = dspCent % 10;
    //And, finally, output result. 
    cout << "With (" << usrNckl << ") nickels, ("
         << usrDime << ") dimes, and ("
         << usrQtr << ") quarters, you have a total of $"
         << dspDolr << "." << msdCent << lsdCent << endl;
    //All done - exit, stage right.
    return 0;
}
