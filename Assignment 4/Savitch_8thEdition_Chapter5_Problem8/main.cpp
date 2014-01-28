/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 27, 2014, 6:42 PM
 * Savitch, 8th Edition - Chapter 5, Problem 8:
 * Combine Problems 6 & 7 into one easy-to-use program.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CVT_FT_MTR = 3.048e-1;    //0.3048 meters in 1 foot
const float CVT_MTR_CM = 1.0e2;       //100 centimeters per meter
const float SHFT_DEC = 1.0e2;         //shifting decimal point
const float CVT_FT_IN = 1.2e1;        //12 inches per foot
const float CVT_RND_MTR = 5.0e-3;     //.005 factor to avoid truncating
const float CVT_RND_IMP = 5.0e-2;     //significant digits

//Function Prototypes
void getImp(int&,int&);
void cvtMtrc(int,int,int&,int&);
void outMtrc(int,int);
void getMtrc(int&,int&);
void cvtImp(int,int,int&,int&);
void outImp(int,int);
void ftToMtr();
void mtrToFt();

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    char iCont = 'Y',usrSel;
    //Main processing loop
    do {
        //Have user select which conversion to use
        cout << "Which conversion would you like to do:" << endl
             << "   (1) Feet to Meters" << endl
             << "   (2) Meters to Feet" << endl
             << "Enter choice: ";
        cin >> usrSel;
        //Perform selected conversion, or give an error message for
        //an invalid selection.
        if (usrSel == '1')
            ftToMtr();
        else if (usrSel == '2')
            mtrToFt();
        else
            cout << "Invalid selection - no conversion will be done." << endl;
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

void ftToMtr() {
    //Encapsulates the functionality of the feet to meter conversion code
    //Define local variables
    int iFeet,iInches,dMetr,dCm;
    //Execute function calls
    getImp(iFeet,iInches);
    cvtMtrc(iFeet,iInches,dMetr,dCm);
    outMtrc(dMetr,dCm);
    return;
}
void mtrToFt(){
     //Encapsulates the functionality of the meter to feet conversion code
     //Define local variables
     int dFeet,dInches,iMetr,iCm;
     //Execute function calls
     getMtrc(iMetr,iCm);
     cvtImp(iMetr,iCm,dFeet,dInches);
     outImp(dFeet,dInches);
     return;
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