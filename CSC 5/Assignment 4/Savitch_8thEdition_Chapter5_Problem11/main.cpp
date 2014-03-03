/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 27, 2014, 8:31 PM
 * Savitch, 8th Edition - Chapter 5, Problem 11:
 * Take Problems 9 & 10 and combine them to allow bidirectional conversion
 * between Imperial & Metric units.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CVT_KG_LB = 2.2046e0;     //2.2046 pounds in 1 kilogram
const float CVT_KG_GM = 1.0e3;        //1000 grams per kilogram
const float CVT_LB_OZ = 1.6e1;        //16 ounces per pound
const float CVT_RND_MTR = 5.0e-4;     //.0005 factor to avoid truncating
const float CVT_RND_IMP = 5.0e-3;     //significant digits

//Function Prototypes
void mtrToIm();
void impToMt();
void getImp(int&,int&);
void cvtMtrc(int,int,int&,int&);
void outMtrc(int,int);
void getMtr(int&,int&);
void cvtImp(int,int,int&,int&);
void outImp(int,int);

//Execution begins here
int main(int argc, char** argv) {
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
    return 0;
}
void mtrToIm(){
     //Encapsulates the functionality of the kilogram to pound conversion code
     //Define local variables
     int dLb,dOz,iMetr,iCm;
     //Execute function calls
     getMtr(iMetr,iCm);
     cvtImp(iMetr,iCm,dLb,dOz);
     outImp(dLb,dOz);
     return;
}
void impToMt(){
    //Encapsulates the functionality of the Pound to kilogram conversion code
    //Define local variables
    int iLb,iOz,dMetr,dCm;
    //Execute function calls
    getImp(iLb,iOz);
    cvtMtrc(iLb,iOz,dMetr,dCm);
    outMtrc(dMetr,dCm);
    return;
}

void getImp(int& usrLb, int& usrOz) {
    cout << "Enter number of pounds: ";
    cin >> usrLb;
    cout << "Enter number of ounces: ";
    cin >> usrOz;
    cout << endl;
    return;
}

void cvtMtrc(int usrLb, int usrOz, int& usrKg, int& usrGm){
    //Define local variables
    float mLb, mKg, mGm;
    //convert the input (pounds and ounces) over to all pounds
    mLb = static_cast<float>(usrLb) + ((static_cast<float>(usrOz) / 
            CVT_LB_OZ));
    //convert the pounds to kilograms
    mKg = mLb / CVT_KG_LB;
    //Add in a rounding factor to avoid losing sig figs
    mKg += CVT_RND_MTR;
    //Shift the decimal point over 3 places to the right to convert to
    //grams
    mKg *= CVT_KG_GM;
    //and, divide by the conversion factor to get the kilograms
    usrKg = static_cast<int>(mKg) / static_cast<int>(CVT_KG_GM);
    //followed by a modulo divide to get the grams
    usrGm = static_cast<int>(mKg) % static_cast<int>(CVT_KG_GM);
    return;
}

void outMtrc(int usrKg, int usrGm){
    cout << "After conversion, there are " << usrKg << " kilograms and "
         << usrGm << " grams." << endl;
    return;
}

void getMtr(int& usrKg, int& usrGm) {
    cout << "Enter number of kilograms: ";
    cin >> usrKg;
    cout << "Enter number of grams: ";
    cin >> usrGm;
    cout << endl;
    return;
}

void cvtImp(int usrKg, int usrGm, int& usrLb, int& usrOz){
    //Define local variables
    float mLb, mOz, mKg;
    //convert the input (kilograms and grams) over to all kilos
    mKg = static_cast<float>(usrKg) + ((static_cast<float>(usrGm) / 
            CVT_KG_GM));
    //convert the kilograms to pounds
    mLb = mKg * CVT_KG_LB;
    //Add in a rounding factor to avoid losing sig figs
    mLb += CVT_RND_IMP;
    //Multiply by the conversion factor to get all ounces
    mLb *= CVT_LB_OZ;
    //and, divide by the conversion factor to get the pounds
    usrLb = static_cast<int>(mLb) / static_cast<int>(CVT_LB_OZ);
    //followed by a modulo divide to get the ounces
    usrOz = static_cast<int>(mLb) % static_cast<int>(CVT_LB_OZ);
    return;
}

void outImp(int usrLb, int usrOz){
    cout << "After conversion, there are " << usrLb << " pounds and "
         << usrOz << " ounces." << endl;
    return;
}

