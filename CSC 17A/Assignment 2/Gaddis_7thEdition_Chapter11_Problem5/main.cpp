/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 9, 2014, 5:22 PM
 * Gaddis, 7th Edition - Chapter 11, Problem : Modify the program written for
 * Programming Challenge 4 so it defines an enumerated data type with
 * enumerators for the months (January, February, etc.) The program should use
 * the enumerated types to step through the array.
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Structures & Enumerated data type
struct WthrMo {
    float totRain;
    float hiTemp;
    float loTemp;
    float avgTemp;
};

struct ExtTmp {
    float temp;
    int month;
};

enum Month { JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
             SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

//Function Prototypes
void getMo(WthrMo *, int);

//Execution begins here
int main(int argc, char** argv) {
    //Declare local constants
    const int NUM_MOS = 12;
    //Declare local variables
    WthrMo wthrYr[12];
    ExtTmp maxTmp, minTmp;
    float totRain = 0, totAvg = 0;
    //Loop to get weather data from user
    for (Month i=JANUARY; i<=DECEMBER; i = static_cast<Month>(i+1)) {
        getMo(wthrYr+static_cast<int>(i),static_cast<int>(i)+1);
        cout << endl;
    }
    //Calculate total annual rainfall, total average monthly rainfall, 
    //highest max temperature and lowest min temperature
    //and display of same.
    maxTmp.temp = -100.0;
    maxTmp.month= -1;
    minTmp.temp = 140.0;
    minTmp.month = -1;
    for(Month i = JANUARY; i <= DECEMBER; i = static_cast<Month>(i+1)) {
        totRain += wthrYr[static_cast<int>(i)].totRain;
        totAvg += wthrYr[static_cast<int>(i)].avgTemp;
        if (wthrYr[static_cast<int>(i)].hiTemp > maxTmp.temp) {
            maxTmp.temp = wthrYr[static_cast<int>(i)].hiTemp;
            maxTmp.month = static_cast<int>(i);
        }
        if (wthrYr[static_cast<int>(i)].loTemp < minTmp.temp) {
            minTmp.temp = wthrYr[static_cast<int>(i)].loTemp;
            minTmp.month = static_cast<int>(i);
        }
    }
    cout <<"Total annual rainfall: " << totRain << " inches" << endl;
    cout <<"Average monthly rainfall: " << totRain/NUM_MOS << " inches" << endl;
    cout <<"Max temp occurred in month " << maxTmp.month+1 << " and was "
         << maxTmp.temp << " degrees" << endl;
    cout <<"Min temp occurred in month " << minTmp.month+1 << " and was "
         << minTmp.temp << " degrees" << endl;
    cout << "Average of average monthly rainfalls was: " << totAvg/NUM_MOS;
    //Exit, stage right!
    return 0;
}

void getMo(WthrMo *month, int numMo) {
    do {
        cout << "Enter total rainfall for month " << numMo << " : ";
        cin >> month->totRain;
    } while(month->totRain < 0.0);
    do {
        cout << "Enter high temperature for month " << numMo << " : ";
        cin >> month->hiTemp;
    } while(month->hiTemp < -100.0 || month->hiTemp > 140.0);
    do {
        cout << "Enter low temperature for month " << numMo << " : ";
        cin >> month->loTemp;
    } while(month->loTemp < -100.0 || month->loTemp > 140.0);
    month->avgTemp = (month->hiTemp + month->loTemp) / 2.0;
}