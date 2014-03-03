/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 26, 2014, 4:02 PM
 * Savitch, 8th Edition - Chapter 5, Problem 1:
 * Ask the user to input a time in 24 hour format, then write 3
 * functions to (a)accept the user input, (b)convert the user input to 12 hour
 * format (using call-by-reference parameter sharing) and (c) output the
 * converted time
 * 
 */
//System Libraries
#include <iostream>
using namespace std;

//Global constants
const int CVT_24H = 12, MAX_24H=23, MAX_24M = 59, //conversion & error checking
          NOON = 12, MIDNITE = 0, SEP_DIG = 10;

//Function Prototypes
bool getInpt(int&,int&);
void cvtTime(int&,char&);
void outTime(int,int,char);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    int iHours,iMins;
    char dAmPm,iCont = 'Y';
    bool isValid = false;
    //Main processing loop
    do {
        isValid = getInpt(iHours,iMins);
        if (isValid) {
           cvtTime(iHours,dAmPm);
           outTime(iHours,iMins,dAmPm);
        } else
            cout << "Invalid time format." << endl;
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

bool getInpt(int& usrHrs, int& usrMin) {
    //Define local variable
    char colon; //dummy variable - grabs the colon from the user input.
    //First, get user input
    cout << "Enter the time in military format (hh:mm): ";
    cin >> usrHrs >> colon >> usrMin;
    //then, confirm valid input
    if ((usrHrs >= MIDNITE)&&(usrHrs<=MAX_24H)&&(usrMin >= MIDNITE)&&
            (usrMin <= MAX_24M)){
        return true;
    } else
        return false;
}

void cvtTime(int& usrHrs, char& dAmPm) {
    //No real error checking - just convert the time to 12-hour format 
    if (usrHrs == MIDNITE) {
        usrHrs = NOON;
        dAmPm = 'A';
    } else if (usrHrs > MIDNITE && usrHrs < NOON) {
        dAmPm = 'A';
    } else if (usrHrs == NOON){
        dAmPm = 'P';
    } else if (usrHrs > NOON) {
        usrHrs -= NOON;
        dAmPm = 'P';
    }
    return;
}

void outTime(int usrHrs, int usrMin, char dAmPm) {
    //define local variables
    int uMin,lMin;
    uMin = usrMin / SEP_DIG; lMin = usrMin % SEP_DIG;
    cout << "The converted time is: " << usrHrs << ":" << uMin << lMin
         << " " << dAmPm << endl;
    return;
}

