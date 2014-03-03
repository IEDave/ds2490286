/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 22, 2014, 11:23 AM
 * Illustrate -> Default parameters & Static Variables
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants
const unsigned short FULL_TIME=40;

//Function Prototypes
int payCheck(float, short=FULL_TIME);
short drvHrs();

//Execution begins here
main(int argc, char** argv) {
    //Init random number generator
    srand(static_cast<unsigned int>(time(0)));
    //init loop
    int loop = 100, pay;
    float pyRate=10.00;
    for (int emp=1; emp <= loop; emp++) {
        short hrsWrkd=drvHrs();
        if(hrsWrkd=FULL_TIME) pay=payCheck(pyRate);
        else pay=payCheck(pyRate,hrsWrkd);
        cout << "Emp " << emp << " hrs - " << hrsWrkd
             << " Paycheck: $" << pay << endl;
    }
    //Exit, stage right
    return 0;
}

short drvHrs() {
    //90% of the time - 40 hrs worked
    int pTim = rand()%100+1;
    if (pTim <= 90) return 40;
    //6% less than 40
    if (pTim <= 96) return rand()%40;
    //4% will have overtime
    return rand()%20+40;
}

int payCheck(float pyRate, short hrsWrkd) {
    if (hrsWrkd <= FULL_TIME) {
        return hrsWrkd*pyRate;
    } else {
        return FULL_TIME*pyRate+1.5*pyRate*(hrsWrkd-FULL_TIME);
    }
}