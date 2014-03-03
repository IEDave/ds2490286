/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 26, 2014, 12:05 PM
 * Gaddis, 7th Edition: Chapter 3, Problem 
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants & variables
    const int ST_TAX = 4.0e-2;  //State sales tax = 4%
    const int CTY_TAX = 2.0e-2; //County sales tax = 2%
    const int TTL_TAX = 1.06e0; //Total sales tax = 6%
    string iMth;
    int iYr,iSlsTtl;
    //Get user input
    cout << "Enter month (January - December): ";
    cin >> iMth;
    cout << "Enter year (yyyy): ";
    cin >> iYr;
    cout << "Enter total $ collected at this register: $";
    cin >> iSlsTtl;
    //
    

    //Exit, stage right.
    return 0;
}

