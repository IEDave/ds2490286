/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 27, 2014, 8:06 PM
 * Savitch, 8th Edition - Chapter 5, Problem 10:
 * Again, like problem 7 - modify problem 9 to accept kilograms & grams
 * from the user, and convert to pounds and ounces. 
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CVT_KG_LB = 2.2046e0;     //2.2046 pounds in 1 kilogram
const float CVT_KG_GM = 1.0e3;        //1000 grams per kilogram
const float CVT_LB_OZ = 1.6e1;        //16 ounces per pound
const float CVT_RND_IMP = 5.0e-3;     //.005 factor to avoid truncating
                                      //significant digits

//Function Prototypes
void getMtr(int&,int&);
void cvtImp(int,int,int&,int&);
void outImp(int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    int dLb,dOz,iKg,iGm;
    char iCont = 'Y';
    //Main processing loop
    do {
        getMtr(iKg,iGm);
        cvtImp(iKg,iGm,dLb,dOz);
        outImp(dLb,dOz);
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

