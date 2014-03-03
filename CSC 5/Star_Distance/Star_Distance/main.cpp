/*
 * David W. Smith - 1/7/14
 * Calculate the distance to a star
 * In miles and kilometers.
*/

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const float VC=3.0e8;
const float CNV_SEC_YR=60*60*24*365;
const float CNV_M_KM=1e-3;
const float CNV_FT_M=3.048e-1;
const float CNV_MI_FT=5.280e3;

//Function Prototypes

//Execution Begins Here
int main() {
    //Declare local variables
    float dLtYr,dMiles,dKm;
    cout << "Enter distance to star in light years:";
    cin >> dLtYr;
    //Calculate distance in KM
    dKm = dLtYr*VC*CNV_SEC_YR*CNV_M_KM;
    //Calculate distance in Miles
    dMiles = dKm/CNV_M_KM/CNV_FT_M/CNV_MI_FT;
    //Output result
    cout << "Distance in Kilometers: " << dKm << endl;
    cout << "Distance in Miles: " << dMiles << endl;
    //Exit, stage right.
    return 0;
}

