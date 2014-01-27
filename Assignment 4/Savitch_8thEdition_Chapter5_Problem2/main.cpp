/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 26, 2014, 5:07 PM
 * Savitch, 8th Edition - Chapter 5, Problem 2:
 * Modification of problem 1 - get user input consisting of start and wait
 * times in military format. Write functions to accept user input, error check,
 * and determine what the end time after  the wait period should be.
 */

//System Libraries
#include <iostream>
#include <cstring>
using namespace std;

//Global constants
const int MAX_24H=23, MAX_24M = 59, MIDNITE = 0,   //conversion & error checking
          SEP_DIG = 10, SEP_HRS = 60, CVT_24H = 1440;

//Function Prototypes
bool getInpt(int&,int&,string);
int cvtTime(int,int);
void outTime(int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    int iHours,iMins,sTime,wTime;
    char dAmPm,iCont = 'Y';
    bool isValid = false;
    //Main processing loop
    do {
        isValid = getInpt(iHours,iMins,
                "Enter start time in military format(hh:mm): ");
        if (isValid) {
           sTime=cvtTime(iHours,iMins);
           isValid = false;
           isValid=getInpt(iHours,iMins,
                   "Enter wait time in military format(hh:mm): ");
           if (isValid) {
               wTime = cvtTime(iHours,iMins);
               outTime(sTime,wTime);
           } else
               cout << "Invalid wait time format." << endl;
        } else
            cout << "Invalid start time format." << endl;
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

bool getInpt(int& usrHrs, int& usrMin, string uPrompt) {
    //Define local variable
    char colon; //dummy variable - grabs the colon from the user input.
    //First, get user input
    cout << uPrompt;
    cin >> usrHrs >> colon >> usrMin;
    //then, confirm valid input
    if ((usrHrs >= MIDNITE)&&(usrHrs<=MAX_24H)&&(usrMin >= MIDNITE)&&
            (usrMin <= MAX_24M)){
        return true;
    } else
        return false;
}

int cvtTime(int usrHrs, int usrMin) {
    //No real error checking - just convert the time to minutes after midnight
    //(0 = midnight, 1439 = 23:59)
    return (usrHrs * 60) + usrMin;
}

void outTime(int bTime,int pTime) {
    //Add start + wait time - if total is greater than 24 hours, subtract
    //24 hours to get valid time.
    //Define local variable
    int eTime = (bTime + pTime > (CVT_24H-1))? bTime+pTime-CVT_24H:bTime+pTime;
    int dHrs,dMin,msdHrs,lsdHrs,msdMin,lsdMin;
    //break all the digits out individually so they all appear on the output
    dHrs = eTime / SEP_HRS; dMin = eTime % SEP_HRS;
    msdHrs = dHrs / SEP_DIG; lsdHrs = dHrs % SEP_DIG; msdMin = dMin / SEP_DIG;
    lsdMin = dMin % SEP_DIG;
    cout << "End time is: " << msdHrs << lsdHrs << ":" << msdMin << lsdMin
         << endl;
    return;
}

