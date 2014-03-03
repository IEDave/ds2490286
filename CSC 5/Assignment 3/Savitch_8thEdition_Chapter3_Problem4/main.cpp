/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 19, 2014, 1:21 PM
 * Savitch, 8th Edition - Chapter 3, Problem 4
 * Modification of Astrology program - add code to determine the
 * element associated with each sign, and which signs are most compatible
 * with that sign.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants
const unsigned int MON_JAN=0,MON_FEB=31,MON_MAR=59,MON_APR=90,     //Julian date
                   MON_MAY=120,MON_JUN=151,MON_JUL=181,MON_AUG=212,//conversion
                   MON_SEP=243,MON_OCT=273,MON_NOV=304,MON_DEC=334;//constants
const unsigned int DAY_JAN=31,DAY_FEB=28,DAY_MAR=31,DAY_APR=30,
                   DAY_MAY=31,DAY_JUN=30,DAY_JUL=31,DAY_AUG=31,
                   DAY_SEP=30,DAY_OCT=31,DAY_NOV=30,DAY_DEC=31;
const unsigned int JAN=1,FEB=2,MAR=3,APR=4,MAY=5,JUN=6,JUL=7,AUG=8,
                   SEP=9,OCT=10,NOV=11,DEC=12;
const unsigned int LEAP_DAY = 29;
const unsigned int BEG_YR=1,END_YR=365;
const unsigned int ARI_BEG=80,ARI_END=109,TAU_BEG=110,TAU_END=140, //Date ranges
                   GEM_BEG=141,GEM_END=172,CAN_BEG=173,CAN_END=203,//for signs
                   LEO_BEG=204,LEO_END=234,VIR_BEG=235,VIR_END=265, //of the
                   LIB_BEG=266,LIB_END=295,SCO_BEG=296,SCO_END=325,//Zodiac
                   SAG_BEG=326,SAG_END=355,CAP_BEG=356,CAP_END=19,
                   AQU_BEG=20,AQU_END=49,PIS_BEG=50,PIS_END=79;
const string ARI_HOR = "Good fortune awaits you today!", //Horoscopes
             TAU_HOR = "You will have a successful day!",
             GEM_HOR = "Do not despair - tomorrow will be a better day!",
             CAN_HOR = "Lucky you!",
             LEO_HOR = "Financial success will be yours!",
             VIR_HOR = "You will enjoy popularity today!",
             LIB_HOR = "A warm & sunny outlook is in store for you!",
             SCO_HOR = "You will fend off many challenges today!",
             SAG_HOR = "Woo Hoo! Lucky in love today!",
             CAP_HOR = "You will meet someone from your past today!",
             AQU_HOR = "Not enough cash? Not a problem - lucky day is today!",
             PIS_HOR = "WOW - are YOU in for a good day!";
const string ELE_FIR = "FIRE",                            //Elements associated
             ELE_RTH = "EARTH",                           //with each
             ELE_AIR = "AIR",                             //astrological sign
             ELE_WTR = "WATER";
const string COMP_FIR = "(Aries,Leo,Sagittarius)",        //Compatibilities
             COMP_RTH = "(Taurus,Virgo,Capricorn)",       //associated with each
             COMP_AIR = "(Gemini,Libra,Aquarius)",        //element
             COMP_WTR = "(Cancer,Scorpio,Pisces)";

//Function Prototypes

//Execution starts here
int main(int argc, char** argv) {
    //Define Local Variables
    unsigned int iMonth,iDay,julDate;
    //Get user input
    cout << "Enter the month of your birth: ";
    cin >> iMonth;
    cout << "Enter the day of your birth: ";
    cin >> iDay;
    //Calculate Julian Date
    //A julian date of 0 means that something was wrong in the
    //users input - valid julian dates are from 1 to 365
    switch (iMonth) {
        case JAN:
            if (iDay >= 1 && iDay <= DAY_JAN)
                julDate = MON_JAN + iDay;
            else
                julDate = 0;
            break;
        case FEB:
            // Leap year check
            if (iDay == LEAP_DAY)
                iDay--;
            if (iDay >= 1 && iDay <= DAY_FEB)
                julDate = MON_FEB + iDay;
            else
                julDate = 0;
            break;
        case MAR:
            if (iDay >= 1 && iDay <= DAY_MAR)
                julDate = MON_MAR + iDay;
            else
                julDate = 0;
            break;
        case APR:
            if (iDay >= 1 && iDay <= DAY_APR)
                julDate = MON_APR + iDay;
            else
                julDate = 0;
            break;
        case MAY:
            if (iDay >= 1 && iDay <= DAY_MAY)
                julDate = MON_MAY + iDay;
            else
                julDate = 0;
            break;
        case JUN:
            if (iDay >= 1 && iDay <= DAY_JUN)
                julDate = MON_JUN + iDay;
            else
                julDate = 0;
            break;
        case JUL:
            if (iDay >= 1 && iDay <= DAY_JUL)
                julDate = MON_JUL + iDay;
            else
                julDate = 0;
            break;
        case AUG:
            if (iDay >= 1 && iDay <= DAY_AUG)
                julDate = MON_AUG + iDay;
            else
                julDate = 0;
            break;
        case SEP:
            if (iDay >= 1 && iDay <= DAY_SEP)
                julDate = MON_SEP + iDay;
            else
                julDate = 0;
            break;
        case OCT:
            if (iDay >= 1 && iDay <= DAY_OCT)
                julDate = MON_OCT + iDay;
            else
                julDate = 0;
            break;
        case NOV:
            if (iDay >= 1 && iDay <= DAY_NOV)
                julDate = MON_NOV + iDay;
            else
                julDate = 0;
            break;
        case DEC:
            if (iDay >= 1 && iDay <= DAY_DEC)
                julDate = MON_DEC + iDay;
            else
                julDate = 0;
            break;
        default:
            julDate = 0;
    }
    //Now, using the julian date, determine the astrological sign - 
    //includes cusp processing & date checking as well!
    if (julDate) {
        if (julDate >= ARI_BEG && julDate <= ARI_END){
            cout << "Aries:" << endl << ARI_HOR << endl;
            if (julDate >= ARI_BEG && julDate <= ARI_BEG+2)
                cout << "Cusp with Pisces:" << endl << PIS_HOR << endl;
            else if (julDate >= ARI_END-2 && julDate <= ARI_END)
                cout << "Cusp with Taurus:" << endl << TAU_HOR << endl;
            cout << "Your element is: " << ELE_FIR << endl
                 << "Compatible with: " << COMP_FIR << endl;
        }
        else if (julDate >= TAU_BEG && julDate <= TAU_END) {
            cout << "Taurus:" << endl << TAU_HOR << endl;
            if (julDate >= TAU_BEG && julDate <= TAU_BEG+2)
                cout << "Cusp with Aries:" << endl << PIS_HOR << endl;
            else if (julDate >= TAU_END-2 && julDate <= TAU_END)
                cout << "Cusp with Gemini:" << endl << GEM_HOR << endl;
            cout << "Your element is: " << ELE_RTH << endl
                 << "Compatible with: " << COMP_RTH << endl;
        }
        else if (julDate >= GEM_BEG && julDate <= GEM_END) {
            cout << "Gemini:" << endl << GEM_HOR << endl;
            if (julDate >= GEM_BEG && julDate <= GEM_BEG+2)
                cout << "Cusp with Taurus:" << endl << TAU_HOR << endl;
            else if (julDate >= GEM_END-2 && julDate <= GEM_END)
                cout << "Cusp with Cancer:" << endl << CAN_HOR << endl;
            cout << "Your element is: " << ELE_AIR << endl
                 << "Compatible with: " << COMP_AIR << endl;
        }
        else if (julDate >= CAN_BEG && julDate <= CAN_END) {
            cout << "Cancer:" << endl << CAN_HOR << endl;
            if (julDate >= CAN_BEG && julDate <= CAN_BEG+2)
                cout << "Cusp with Gemini:" << endl << GEM_HOR << endl;
            else if (julDate >= CAN_END-2 && julDate <= CAN_END)
                cout << "Cusp with Leo:" << endl << LEO_HOR << endl;
            cout << "Your element is: " << ELE_WTR << endl
                 << "Compatible with: " << COMP_WTR << endl;
        }
        else if (julDate >= LEO_BEG && julDate <= LEO_END) {
            cout << "Leo:" << endl << LEO_HOR << endl;
            if (julDate >= LEO_BEG && julDate <= LEO_BEG+2)
                cout << "Cusp with Cancer:" << endl << CAN_HOR << endl;
            else if (julDate >= LEO_END-2 && julDate <= LEO_END)
                cout << "Cusp with Virgo:" << endl << VIR_HOR << endl;
            cout << "Your element is: " << ELE_FIR << endl
                 << "Compatible with: " << COMP_FIR << endl;
        }
        else if (julDate >= VIR_BEG && julDate <= VIR_END) {
            cout << "Virgo:" << endl << VIR_HOR << endl;
            if (julDate >= VIR_BEG && julDate <= VIR_BEG+2)
                cout << "Cusp with Leo:" << endl << LEO_HOR << endl;
            else if (julDate >= VIR_END-2 && julDate <= VIR_END)
                cout << "Cusp with Libra:" << endl << LIB_HOR << endl;
            cout << "Your element is: " << ELE_RTH << endl
                 << "Compatible with: " << COMP_RTH << endl;
        }
        else if (julDate >= LIB_BEG && julDate <= LIB_END) {
            cout << "Libra:" << endl << LIB_HOR << endl;
            if (julDate >= LIB_BEG && julDate <= LIB_BEG+2)
                cout << "Cusp with Virgo:" << endl << VIR_HOR << endl;
            else if (julDate >= LIB_END-2 && julDate <= LIB_END)
                cout << "Cusp with Scorpio:" << endl << SCO_HOR << endl;
            cout << "Your element is: " << ELE_AIR << endl
                 << "Compatible with: " << COMP_AIR << endl;
        }
        else if (julDate >= SCO_BEG && julDate <= SCO_END) {
            cout << "Scorpio:" << endl << SCO_HOR << endl;
            if (julDate >= SCO_BEG && julDate <= SCO_BEG+2)
                cout << "Cusp with Libra:" << endl << LIB_HOR << endl;
            else if (julDate >= SCO_END-2 && julDate <= SCO_END)
                cout << "Cusp with Sagittarius:" << endl << SAG_HOR << endl;
            cout << "Your element is: " << ELE_WTR << endl
                 << "Compatible with: " << COMP_WTR << endl;
        }
        else if (julDate >= SAG_BEG && julDate <= SAG_END) {
            cout << "Sagittarius:" << endl << SAG_HOR << endl;
            if (julDate >= SAG_BEG && julDate <= SAG_BEG+2)
                cout << "Cusp with Scorpio:" << endl << SCO_HOR << endl;
            else if (julDate >= SAG_END-2 && julDate <= SAG_END)
                cout << "Cusp with Capricorn:" << endl << CAP_HOR << endl;
            cout << "Your element is: " << ELE_FIR << endl
                 << "Compatible with: " << COMP_FIR << endl;
        }
        //Capricorn spans year end, so the date check is a little different
        else if ((julDate >= CAP_BEG && julDate <= END_YR)||
                 (julDate >= BEG_YR && julDate <= CAP_END )) {
                     cout << "Capricorn:" << endl << CAP_HOR << endl;
                     if (julDate >= CAP_BEG && julDate <= CAP_BEG+2)
                         cout << "Cusp with Sagittarius:" << endl
                              << SAG_HOR << endl;
                     else if (julDate >= CAP_END-2 && julDate <= CAP_END)
                         cout << "Cusp with Aquarius:" << endl
                              << AQU_HOR << endl;
                     cout << "Your element is: " << ELE_RTH << endl
                          << "Compatible with: " << COMP_RTH << endl;
        }
        else if (julDate >= AQU_BEG && julDate <= AQU_END) {
            cout << "Aquarius:" << endl << AQU_HOR;
            if (julDate >= AQU_BEG && julDate <= AQU_BEG+2)
                cout << "Cusp with Capricorn:" << endl << CAP_HOR << endl;
            else if (julDate >= AQU_END-2 && julDate <= AQU_END)
                cout << "Cusp with Pisces:" << endl << PIS_HOR << endl;
            cout << "Your element is: " << ELE_AIR << endl
                 << "Compatible with: " << COMP_AIR << endl;
        }
        else if (julDate >= PIS_BEG && julDate <= PIS_END) {
            cout << "Pisces:" << endl << PIS_HOR << endl;
            if (julDate >= PIS_BEG && julDate <= PIS_BEG+2)
                cout << "Cusp with Aquarius:" << endl << AQU_HOR << endl;
            else if (julDate >= PIS_END-2 && julDate <= PIS_END)
                cout << "Cusp with Aries:" << endl << ARI_HOR << endl;
            cout << "Your element is: " << ELE_WTR << endl
                 << "Compatible with: " << COMP_WTR << endl;
        }
        else
            cout << "Huh?" << endl; //Should never occur - did during testing.
    } else
        cout << "Invalid Date.";
    //Exit, stage right
    return 0;
}

