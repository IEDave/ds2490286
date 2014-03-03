/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 26, 2014, 11:05 PM
 * Savitch, 8th Edition - Chapter 5, Problem 6:
 * Get user input of a length in feet and inches - output the equivalent
 * in meters & centimeters. Use at least three function to accomplish this:
 * one for input, one for conversion & one for output.
 */
//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CVT_FT_MTR = 3.048e-1;    //0.3048 meters in 1 foot
const float CVT_MTR_CM = 1.0e2;       //100 centimeters per meter
const float CVT_FT_IN = 1.2e1;        //12 inches per foot
const float CVT_RND_MTR = 5.0e-3;     //.005 factor to avoid truncating
                                      //significant digits

//Function Prototypes
void getImp(int&,int&);
void cvtMtrc(int,int,int&,int&);
void outMtrc(int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    int iFeet,iInches,dMetr,dCm;
    char iCont = 'Y';
    //Main processing loop
    do {
        getImp(iFeet,iInches);
        cvtMtrc(iFeet,iInches,dMetr,dCm);
        outMtrc(dMetr,dCm);
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    
    //Exit,stage right
    return 0;
}

void getImp(int& usrFt, int& usrIn) {
    cout << "Enter number of feet: ";
    cin >> usrFt;
    cout << "Enter number of inches: ";
    cin >> usrIn;
    cout << endl;
    return;
}

void cvtMtrc(int usrFt, int usrIn, int& usrMtr, int& usrCm){
    //Define local variables
    float mFt, mMtr, mCm;
    //convert the input (feet & inches) over to all feet
    mFt = static_cast<float>(usrFt) + ((static_cast<float>(usrIn) / 
            CVT_FT_IN));
    //convert the feet to meters
    mMtr = mFt * CVT_FT_MTR;
    //Add in a rounding factor to avoid losing sig figs
    mMtr += CVT_RND_MTR;
    //Shift the decimal point over 2 places to the right to convert to
    //centimeters
    mMtr *= CVT_MTR_CM;
    //and, divide by the conversion factor to get the meters
    usrMtr = static_cast<int>(mMtr) / static_cast<int>(CVT_MTR_CM);
    //followed by a modulo divide to get the centimeters
    usrCm = static_cast<int>(mMtr) % static_cast<int>(CVT_MTR_CM);
    return;
}

void outMtrc(int usrMtr, int usrCm){
    cout << "After conversion, there are " << usrMtr << " meters and "
         << usrCm << " centimeters." << endl;
    return;
}

