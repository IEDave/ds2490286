/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 9, 2014, 3:53 PM
 * Gaddis, 7th Edition - Chapter 11, Problem 4: Write a program that uses a
 * structure to store the following weather data for a particular month:
 *     Total Rainfall
 *     High Temperature
 *     Low Temperature
 *     Average Temperature
 * The program should have an array of 12 structures to hold weather data for an
 * entire year. When the program runs, it should ask the user to enter data for
 * each month (the average temperature should be calculated). Once the data are
 * entered for all the months, the program should calculate and display the
 * average monthly rainfall, the total rainfall for the year, the highest and
 * lowest temperatures for the year (and the months they occurred in), and the
 * average of all the monthly average temperatures.
 * Input validation: Only accept temperatures within the range between -100 and
 * +140 degrees Fahrenheit.
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Structures
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
    for (int i=0; i<NUM_MOS; i++) {
        getMo(wthrYr+i,i+1);
        cout << endl;
    }
    //Calculate total annual rainfall, total average monthly rainfall, 
    //highest max temperature and lowest min temperature
    //and display of same.
    maxTmp.temp = -100.0;
    maxTmp.month= -1;
    minTmp.temp = 140.0;
    minTmp.month = -1;
    for(int i = 0; i < NUM_MOS; i++) {
        totRain += wthrYr[i].totRain;
        totAvg += wthrYr[i].avgTemp;
        if (wthrYr[i].hiTemp > maxTmp.temp) {
            maxTmp.temp = wthrYr[i].hiTemp;
            maxTmp.month = i;
        }
        if (wthrYr[i].loTemp < minTmp.temp) {
            minTmp.temp = wthrYr[i].loTemp;
            minTmp.month = i;
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
