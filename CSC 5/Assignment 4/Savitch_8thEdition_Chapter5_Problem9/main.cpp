/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 27, 2014, 7:11 PM
 * Savitch, 8th Edition - Chapter 5, Problem 9:
 * Much like problem 6, except we get user input in pounds and ounces
 * and convert to kilograms & grams
 * 
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CVT_KG_LB = 2.2046e0;     //2.2046 pounds in 1 kilogram
const float CVT_KG_GM = 1.0e3;        //1000 grams per kilogram
const float CVT_LB_OZ = 1.6e1;        //16 ounces per pound
const float CVT_RND_MTR = 5.0e-4;     //.0005 factor to avoid truncating
                                      //significant digits

//Function Prototypes
void getImp(int&,int&);
void cvtMtrc(int,int,int&,int&);
void outMtrc(int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    int iLb,iOz,dKg,dGm;
    char iCont = 'Y';
    //Main processing loop
    do {
        getImp(iLb,iOz);
        cvtMtrc(iLb,iOz,dKg,dGm);
        outMtrc(dKg,dGm);
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