/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 25, 2014, 10:02 PM
 * Savitch, 8th Edition - Chapter 4, Problem 9
 * Using supplied formulae, accept input from user re: person's age,
 * weight & height, then determine the person's hat size, jacket (e.g chest)
 * size, and waist size. Chest and waist measurements are to be altered
 * based on person's age.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float AGE_WST = 2.8e1;          // Cutoff age for waist adj. - 28
const float AGE_CHST = 3.0e1;         // Cutoff age for waist adj. - 30
const unsigned int INTV_WST = 2;      // Adjust every 2 years
const unsigned int INTV_CHS = 10;     // Adjust every 10 years
const float ADJ_CHST = 1.0e0/8.0e0;   // 1/8" for every 10 years over age 30
const float ADJ_WST = 1.0e0/1.0e1;    // 1/10" for every 2 years over age 28
const float CNV_WST = 5.7e0;          // Waist conversion factor
const float CNV_CHST = 2.88e2;        // Chest conversion factor
const float CNV_HAT = 2.9e0;          // Hat size = (weight/height)*2.9

//Function Prototypes
float cHat(float, float);
float cChest(float, float, float);
float cWaist(float, float);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float iHeight, iWeight, iAge;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter person's weight in pounds: ";
        cin >> iWeight;
        cout << "Enter person's height in inches: ";
        cin >> iHeight;
        cout << "Enter person's age in years: ";
        cin >> iAge;
        cout << endl;
        //Calculate & display hat, chest & waist sizes for person
        cout << "The person's hat size is: " << cHat(iHeight,iWeight) << endl;
        cout << "The person's jacket(chest) size is: " 
             << cChest(iHeight,iWeight,iAge) << endl;
        cout << "The person's waist size is: " << cWaist(iWeight,iAge) << endl;
        cout << endl;
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

//Calculate person's hat size
float cHat(float mHeight, float mWeight) {
    return mWeight / mHeight * CNV_HAT;
}

//Calculate person's chest size
float cChest(float mHeight, float mWeight, float mAge){
    //Define local variables
    float mChest = mHeight * mWeight / CNV_CHST;
    //Adjust for age
    if (mAge > AGE_CHST) {
        mChest += static_cast<unsigned int>(mAge-AGE_CHST)/INTV_CHS*ADJ_CHST;
    }
    return mChest;
}

//Calculate person's waist size
float cWaist(float mWeight, float mAge){
    //Define local variables
    float mWaist = mWeight / CNV_WST;
    //Adjust for age
    if (mAge > AGE_WST) {
        mWaist += static_cast<unsigned int>(mAge-AGE_WST)/INTV_WST*ADJ_WST;
    }
    return mWaist;
}