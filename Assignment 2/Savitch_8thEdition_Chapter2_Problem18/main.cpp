/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 18, 2014, 8:59 PM
 * Savitch, 8th Edition - Chapter 2, Problem 17:
 * 
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float CHOC_BAR = 2.3e2;   // 1 chocolate bar = 230 calories
const float CNV_ROUND = 5.0e-1; // Round the number of chocolate bars
                                // appropriately
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
    unsigned int dChoclt;
    char iGender;
    //Get user input
    cout << "Is this calculation to be done for a (M)ale or a (F)emale? ";
    cin >> iGender;
    if (iGender == 'm')
        iGender = MALE;
    if (iGender == 'f')
        iGender = FEMALE;
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
            cout << "Unable to determine gender - no output generated.";
            mBMR = 0;
    }
    //Output result
    if (mBMR) {
        mChoclt = mBMR + CNV_ROUND;
        dChoclt = mChoclt / CHOC_BAR;
        cout << "This person should consume " << mBMR << " calories, or "
             << dChoclt << " chocolate bars" << endl;
        cout << "per day to maintain their body weight." << endl;
    }
    //Exit, stage right.
    return 0;
}

