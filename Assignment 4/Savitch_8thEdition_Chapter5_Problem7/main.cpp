/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 27, 2014, 12:33 AM
 * Savitch, 8th Edition - Chapter 5, Problem 6:
 * Rework Problem 6 so that it accepts meters and centimeters for input, and
 * converts to feet and inches.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CVT_FT_MTR = 3.048e-1;    //0.3048 meters in 1 foot
const float CVT_MTR_CM = 1.0e2;       //100 centimeters per meter
const float SHFT_DEC = 1.0e2;         //shifting decimal point
const float CVT_FT_IN = 1.2e1;        //12 inches per foot
const float CVT_RND_IMP = 5.0e-2;         //.005 factor to avoid truncating
                                      //significant digits

//Function Prototypes
void getMtrc(int&,int&);
void cvtImp(int,int,int&,int&);
void outImp(int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    int dFeet,dInches,iMetr,iCm;
    char iCont = 'Y';
    //Main processing loop
    do {
        getMtrc(iMetr,iCm);
        cvtImp(iMetr,iCm,dFeet,dInches);
        outImp(dFeet,dInches);
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    return 0;
}

void getMtrc(int& usrMtr, int& usrCm) {
    cout << "Enter number of meters: ";
    cin >> usrMtr;
    cout << "Enter number of centimeters: ";
    cin >> usrCm;
    cout << endl;
    return;
}

void cvtImp(int usrMtr, int usrCm, int& usrFt, int& usrIn){
    //Define local variables
    float mFt, mMtr, mIn;
    //convert the input (meters & centimeters) over to all meters
    mMtr = static_cast<float>(usrMtr) + ((static_cast<float>(usrCm) / 
          CVT_MTR_CM));
    //convert the meters to feet
    mFt = mMtr / CVT_FT_MTR;
    //Add in a rounding factor to avoid losing sig figs
    mFt += CVT_RND_IMP;
    //everything to the left of the decimal point is feet
    usrFt = static_cast<int>(mFt);
    //subtract out the feet to get the fractional part
    mIn = mFt - usrFt;
    //multiply by conversion factor to get the inches
    usrIn = mIn * CVT_FT_IN;
    return;
}

void outImp(int usrFt, int usrIn){
    cout << "After conversion, there are " << usrFt << " feet and "
         << usrIn << " inches." << endl;
    return;
}


