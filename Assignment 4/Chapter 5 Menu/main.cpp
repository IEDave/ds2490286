/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 27, 2014, 9:05 PM
 * Menu for Chapter 5 problems - mod of template provided by Dr. Mark E. Lehr
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

//Global Constants
const int CVT_24H = 12, MAX_24H=23, MAX_24M = 59, //conversion & error checking
          NOON = 12, MIDNITE = 0, SEP_DIG = 10,
          SEP_HRS = 60, CVT_1D = 1440;
const float CVT_FT_MTR = 3.048e-1;    //0.3048 meters in 1 foot
const float CVT_MTR_CM = 1.0e2;       //100 centimeters per meter
const float CVT_FT_IN = 1.2e1;        //12 inches per foot
const float CVT_RND_MTR = 5.0e-3;     //.005 factor to avoid truncating
                                      //significant digits
const float CVT_RND_IMP = 5.0e-2;     //.05 factor to avoid truncating
                                      //significant digits
const float CVT_KG_LB = 2.2046e0;     //2.2046 pounds in 1 kilogram
const float CVT_KG_GM = 1.0e3;        //1000 grams per kilogram
const float CVT_LB_OZ = 1.6e1;        //16 ounces per pound
const float CVT_RND_MT = 5.0e-4;      //.0005 factor to avoid truncating
                                      //significant digits
const float CVT_RND_IM = 5.0e-3;     //.005 factor to avoid truncating
                                      //significant digits

//Function prototypes
void prob1();
bool getInpt(int&,int&);
void cvtTime(int&,char&);
void outTime(int,int,char);
void prob2();
bool getInpt(int&,int&,string);
int cvtTime(int,int);
void outTime(int,int);
void prob6();
void getImp(int&,int&);
void cvtMtrc(int,int,int&,int&);
void outMtrc(int,int);
void prob7();
void getMtrc(int&,int&);
void cvtImp(int,int,int&,int&);
void outImp(int,int);
void prob8();
void ftToMtr();
void mtrToFt();
void prob9();
void getLb(int&,int&);
void cvtKg(int,int,int&,int&);
void outKg(int,int);
void prob10();
void getKg(int&,int&);
void cvtLb(int,int,int&,int&);
void outLb(int,int);
void prob11();
void mtrToIm();
void impToMt();

//Execution begins here
int main(int argc, char** argv) {
    //General Menu Format
    bool loop = true;
    do {
        //Display the selection
        cout << "Savitch - Chapter 5"<<endl;;
        cout << "Type 1 to solve problem 1" << endl;
        cout << "Type 2 to solve problem 2" << endl;
        cout << "Type 3 to solve problem 6" << endl;
        cout << "Type 4 to solve problem 7" << endl;
        cout << "Type 5 to solve problem 8" << endl;
        cout << "Type 6 to solve problem 9" << endl;
        cout << "Type 7 to solve problem 10" << endl;
        cout << "Type 8 to solve problem 11" << endl;
        cout << "Type anything else to quit with no solutions." << endl;
        //Read the choice
        char choice;
        cin >> choice;
        //Solve a problem that has been chosen.
        switch (choice) {
            case '1':
                prob1();
                break;
            case '2':
                prob2();
                break;
            case '3':
                prob6();
                break;
            case '4':
                prob7();
                break;
            case '5':
                prob8();
                break;
            case '6':
                prob9();
                break;
            case '7':
                prob10();
                break;
            case '8':
                prob11();
                break;
            default:
            {
                cout << "Exit?" << endl;
                loop = false;
                break;
            }
        };
    } while (loop); //Upper do-while
    return 0;
}

void prob1() {
 /*
 * Author: David W. Smith
 * Created on January 26, 2014, 4:02 PM
 * Savitch, 8th Edition - Chapter 5, Problem 1:
 * Ask the user to input a time in 24 hour format, then write 3
 * functions to (a)accept the user input, (b)convert the user input to 12 hour
 * format (using call-by-reference parameter sharing) and (c) output the
 * converted time
 * 
 */
    //Define local variables
    int iHours,iMins;
    char dAmPm,iCont = 'Y';
    bool isValid = false;
    //Main processing loop
    do {
        isValid = getInpt(iHours,iMins);
        if (isValid) {
           cvtTime(iHours,dAmPm);
           outTime(iHours,iMins,dAmPm);
        } else
            cout << "Invalid time format." << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    //Exit, stage right
    return;
}
bool getInpt(int& usrHrs, int& usrMin) {
    //Define local variable
    char colon; //dummy variable - grabs the colon from the user input.
    //First, get user input
    cout << "Enter the time in military format (hh:mm): ";
    cin >> usrHrs >> colon >> usrMin;
    //then, confirm valid input
    if ((usrHrs >= MIDNITE)&&(usrHrs<=MAX_24H)&&(usrMin >= MIDNITE)&&
            (usrMin <= MAX_24M)){
        return true;
    } else
        return false;
}

void cvtTime(int& usrHrs, char& dAmPm) {
    //No real error checking - just convert the time to 12-hour format 
    if (usrHrs == MIDNITE) {
        usrHrs = NOON;
        dAmPm = 'A';
    } else if (usrHrs > MIDNITE && usrHrs < NOON) {
        dAmPm = 'A';
    } else if (usrHrs == NOON){
        dAmPm = 'P';
    } else if (usrHrs > NOON) {
        usrHrs -= NOON;
        dAmPm = 'P';
    }
    return;
}

void outTime(int usrHrs, int usrMin, char dAmPm) {
    //define local variables
    int uMin,lMin;
    uMin = usrMin / SEP_DIG; lMin = usrMin % SEP_DIG;
    cout << "The converted time is: " << usrHrs << ":" << uMin << lMin
         << " " << dAmPm << endl;
    return;
}

void prob2() {
/* 
 * Author: David W. Smith
 * Created on January 26, 2014, 5:07 PM
 * Savitch, 8th Edition - Chapter 5, Problem 2:
 * Modification of problem 1 - get user input consisting of start and wait
 * times in military format. Write functions to accept user input, error check,
 * and determine what the end time after  the wait period should be.
 */
    //Define local variables
    int iHours,iMins,sTime,wTime;
    char dAmPm,iCont = 'Y';
    bool isValid = false;
    //Main processing loop
    do {
        isValid = getInpt(iHours,iMins,
                "Enter start time in military format(hh:mm): ");
        if (isValid) {
           sTime=cvtTime(iHours,iMins);
           isValid = false;
           isValid=getInpt(iHours,iMins,
                   "Enter wait time in military format(hh:mm): ");
           if (isValid) {
               wTime = cvtTime(iHours,iMins);
               outTime(sTime,wTime);
           } else
               cout << "Invalid wait time format." << endl;
        } else
            cout << "Invalid start time format." << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    //Exit, stage right
    return;
}

bool getInpt(int& usrHrs, int& usrMin, string uPrompt) {
    //Define local variable
    char colon; //dummy variable - grabs the colon from the user input.
    //First, get user input
    cout << uPrompt;
    cin >> usrHrs >> colon >> usrMin;
    //then, confirm valid input
    if ((usrHrs >= MIDNITE)&&(usrHrs<=MAX_24H)&&(usrMin >= MIDNITE)&&
            (usrMin <= MAX_24M)){
        return true;
    } else
        return false;
}

int cvtTime(int usrHrs, int usrMin) {
    //No real error checking - just convert the time to minutes after midnight
    //(0 = midnight, 1439 = 23:59)
    return (usrHrs * 60) + usrMin;
}

void outTime(int bTime,int pTime) {
    //Add start + wait time - if total is greater than 24 hours, subtract
    //24 hours to get valid time.
    //Define local variable
    int eTime = (bTime + pTime > (CVT_1D-1))? bTime+pTime-CVT_1D:bTime+pTime;
    int dHrs,dMin,msdHrs,lsdHrs,msdMin,lsdMin;
    //break all the digits out individually so they all appear on the output
    dHrs = eTime / SEP_HRS; dMin = eTime % SEP_HRS;
    msdHrs = dHrs / SEP_DIG; lsdHrs = dHrs % SEP_DIG; msdMin = dMin / SEP_DIG;
    lsdMin = dMin % SEP_DIG;
    cout << "End time is: " << msdHrs << lsdHrs << ":" << msdMin << lsdMin
         << endl;
    return;
}

void prob6() {
/* 
 * Author: David W. Smith
 * Created on January 26, 2014, 11:05 PM
 * Savitch, 8th Edition - Chapter 5, Problem 6:
 * Get user input of a length in feet and inches - output the equivalent
 * in meters & centimeters. Use at least three function to accomplish this:
 * one for input, one for conversion & one for output.
 */
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

void prob7(){
/* 
 * Author: David W. Smith
 * Created on January 27, 2014, 12:33 AM
 * Savitch, 8th Edition - Chapter 5, Problem 7:
 * Rework Problem 6 so that it accepts meters and centimeters for input, and
 * converts to feet and inches.
 */
    
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
    
    //Exit, stage right
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

void prob8() {
/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 27, 2014, 6:42 PM
 * Savitch, 8th Edition - Chapter 5, Problem 8:
 * Combine Problems 6 & 7 into one easy-to-use program.
 */
    
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
    return;
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

void prob9(){
/* 
 * Author: David Smith
 * Created on January 27, 2014, 7:11 PM
 * Savitch, 8th Edition - Chapter 5, Problem 9:
 * Much like problem 6, except we get user input in pounds and ounces
 * and convert to kilograms & grams
 * 
 */
    //Define local variables
    int iLb,iOz,dKg,dGm;
    char iCont = 'Y';
    //Main processing loop
    do {
        getLb(iLb,iOz);
        cvtKg(iLb,iOz,dKg,dGm);
        outKg(dKg,dGm);
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    
    //Exit, stage right 
    return;
}

void getLb(int& usrLb, int& usrOz) {
    cout << "Enter number of pounds: ";
    cin >> usrLb;
    cout << "Enter number of ounces: ";
    cin >> usrOz;
    cout << endl;
    return;
}

void cvtKg(int usrLb, int usrOz, int& usrKg, int& usrGm){
    //Define local variables
    float mLb, mKg, mGm;
    //convert the input (pounds and ounces) over to all pounds
    mLb = static_cast<float>(usrLb) + ((static_cast<float>(usrOz) / 
            CVT_LB_OZ));
    //convert the pounds to kilograms
    mKg = mLb / CVT_KG_LB;
    //Add in a rounding factor to avoid losing sig figs
    mKg += CVT_RND_MT;
    //Shift the decimal point over 3 places to the right to convert to
    //grams
    mKg *= CVT_KG_GM;
    //and, divide by the conversion factor to get the kilograms
    usrKg = static_cast<int>(mKg) / static_cast<int>(CVT_KG_GM);
    //followed by a modulo divide to get the grams
    usrGm = static_cast<int>(mKg) % static_cast<int>(CVT_KG_GM);
    return;
}

void outKg(int usrKg, int usrGm){
    cout << "After conversion, there are " << usrKg << " kilograms and "
         << usrGm << " grams." << endl;
    return;
}

void prob10(){
/* 
 * Author: David Smith
 * Created on January 27, 2014, 8:06 PM
 * Savitch, 8th Edition - Chapter 5, Problem 10:
 * Again, like problem 7 - modify problem 9 to accept kilograms & grams
 * from the user, and convert to pounds and ounces. 
 */
    //Define local variables
    int dLb,dOz,iKg,iGm;
    char iCont = 'Y';
    //Main processing loop
    do {
        getKg(iKg,iGm);
        cvtLb(iKg,iGm,dLb,dOz);
        outLb(dLb,dOz);
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    
    //Exit, stage right
    return;
}

void getKg(int& usrKg, int& usrGm) {
    cout << "Enter number of kilograms: ";
    cin >> usrKg;
    cout << "Enter number of grams: ";
    cin >> usrGm;
    cout << endl;
    return;
}

void cvtLb(int usrKg, int usrGm, int& usrLb, int& usrOz){
    //Define local variables
    float mLb, mOz, mKg;
    //convert the input (kilograms and grams) over to all kilos
    mKg = static_cast<float>(usrKg) + ((static_cast<float>(usrGm) / 
            CVT_KG_GM));
    //convert the kilograms to pounds
    mLb = mKg * CVT_KG_LB;
    //Add in a rounding factor to avoid losing sig figs
    mLb += CVT_RND_IM;
    //Multiply by the conversion factor to get all ounces
    mLb *= CVT_LB_OZ;
    //and, divide by the conversion factor to get the pounds
    usrLb = static_cast<int>(mLb) / static_cast<int>(CVT_LB_OZ);
    //followed by a modulo divide to get the ounces
    usrOz = static_cast<int>(mLb) % static_cast<int>(CVT_LB_OZ);
    return;
}

void outLb(int usrLb, int usrOz){
    cout << "After conversion, there are " << usrLb << " pounds and "
         << usrOz << " ounces." << endl;
    return;
}

void prob11(){
/* 
 * Author: David W. Smith
 * Created on January 27, 2014, 8:31 PM
 * Savitch, 8th Edition - Chapter 5, Problem 11:
 * Take Problems 9 & 10 and combine them to allow bidirectional conversion
 * between Imperial & Metric units.
 */
    //Define local variables
    char iCont = 'Y',usrSel;
    //Main processing loop
    do {
        //Have user select which conversion to do
        cout << "Which conversion would you like to do:" << endl
             << "   (1) Pounds to Kilograms" << endl
             << "   (2) Kilograms to Pounds" << endl
             << "Enter choice: ";
        cin >> usrSel;
        //Perform selected conversion, or give an error message for
        //an invalid selection.
        if (usrSel == '1')
            impToMt();
        else if (usrSel == '2')
            mtrToIm();
        else
            cout << "Invalid selection - no conversion will be done." << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    
    //Exit, stage right 
    return;
}

void mtrToIm(){
     //Encapsulates the functionality of the kilogram to pound conversion code
     //Define local variables
     int dLb,dOz,iKg,iGm;
     //Execute function calls
     getKg(iKg,iGm);
     cvtLb(iKg,iGm,dLb,dOz);
     outLb(dLb,dOz);
     return;
}
void impToMt(){
    //Encapsulates the functionality of the Pound to kilogram conversion code
    //Define local variables
    int iLb,iOz,dKg,dGm;
    //Execute function calls
    getLb(iLb,iOz);
    cvtKg(iLb,iOz,dKg,dGm);
    outKg(dKg,dGm);
    return;
}
