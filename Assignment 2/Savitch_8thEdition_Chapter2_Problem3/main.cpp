/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 16, 2014, 11:35 AM
 * Savitch, 8th Edition - Chapter 2, Problem 3:
 * Get user's previous annual salary as input - calculate the retroactive
 * pay increase (6 months @ 7.6%), the new annual & monthly salary and
 * display result.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global constants
const float PAY_INCR = 7.6e-2; //Retroactive pay increase = 7.6%

//Function prototypes

int main(int argc, char** argv) {
    //Local variables
    float iOldSal,dNewSal,dNewMon,dRetro;
    // Get previous salary
    cout << "What was your previous annual salary?" << endl;
    cin >> iOldSal;
    //Calculate new annual salary
    
    //Calculate retroactive pay
    //Calculate new monthly salary
    
    //Exit, stage right.
    return 0;
}

