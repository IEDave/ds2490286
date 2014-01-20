/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 19, 2014, 7:44 PM
 * Savitch, 8th Edition - Chapter 3, Problem 17:
 * BMR revisited - ask the user if they are
 * (a) sedentary
 * (b) somewhat active (exercise occasionally)
 * (c) active (exercise 3-4 days a week)
 * (d) highly active (exercise every day.
 * Based on user input, adjust BMR accordingly & recalculate
 * the number of chocolate bars they should consume.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CHOC_BAR = 2.3e2;   // 1 chocolate bar = 230 calories
const float CNV_ROUND = 5.0e-1; // Round the number of chocolate bars
                                // appropriately
const float CNV_SED = 2.0e-1; //Sedentary = increase BMR by 20%
const float CNV_MOD = 3.0e-1; //Moderate = increase BMR by 30%
const float CNV_ACT = 4.0e-1; //Active = increase BMR by 40%
const float CNV_HI  = 5.0e-1; //Highly active = increase BMR by 50%
const unsigned int USR_SED = 1; //Corresponds to input values from user 
const unsigned int USR_MOD = 2;
const unsigned int USR_ACT = 3;
const unsigned int USR_HI = 4;
//Constants for Harris-Benedict equation for Female BMR
const float FM_CNST = 655,FM_WGHT = 4.3,FM_HGHT = 4.7,FM_AGE = 4.7;
const char FEMALE = 'F';
//Constants for Harris-Benedict equation for Male BMR
const float M_CNST = 66,M_WGHT = 6.3,M_HGHT = 12.9,M_AGE = 6.8;
const char MALE = 'M';

//Function Prototypes

int main(int argc, char** argv) {
    //Define local variables
    float iAge,iWeight,iHeight,mBMR,mChoclt;
    unsigned int iActiv, dChoclt;
    char iGender;
    //Get user input
    cout << "Is this calculation to be done for a (M)ale or a (F)emale? ";
    cin >> iGender;
    if (iGender == 'm')
        iGender = MALE;
    if (iGender == 'f')
        iGender = FEMALE;
    cout << "Is this person:" << endl
         << "(1) Sedentary;" << endl
         << "(2) Moderately active;" << endl
         << "(3) Active;" << endl
         << "(4) Highly Active;" << endl
         << "Enter a number (1-4): ";
    cin >> iActiv;
    cout << "Enter the person's age: ";
    cin >> iAge;
    cout << "Enter the person's weight(lbs): ";
    cin >> iWeight;
    cout << "Enter the person's height(in): ";
    cin >> iHeight;
    //Calculate BMR
    switch (iGender) {
        case MALE:
            mBMR = M_CNST + (M_WGHT * iWeight) + (M_HGHT * iHeight)
                   - (M_AGE * iAge);
            break;
        case FEMALE:
            mBMR = FM_CNST + (FM_WGHT * iWeight) + (FM_HGHT * iHeight)
                   - (FM_AGE * iAge);
            break;
        default:
            cout << "Unable to determine gender - no output generated." << endl;
            mBMR = 0;
    }
    //Adjust BMR for activity level
    switch (iActiv) {
        case USR_SED:
            mBMR += mBMR * CNV_SED;
            break;
        case USR_MOD:
            mBMR += mBMR * CNV_MOD;
            break;
        case USR_ACT:
            mBMR += mBMR * CNV_ACT;
            break;
        case USR_HI:
            mBMR += mBMR * CNV_HI;
            break;
        default:
            cout << "Invalid activity level - no output generated." << endl;
            iActiv = 0;
    }
    //Output result
    if (mBMR && iActiv) {
        mChoclt = mBMR + CNV_ROUND;
        dChoclt = mChoclt / CHOC_BAR;
        cout << "This person should consume " << mBMR << " calories, or "
             << dChoclt << " chocolate bars" << endl;
        cout << "per day to maintain their body weight." << endl;
    }
    //Exit, stage right.
    return 0;
}

