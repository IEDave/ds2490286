/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 18, 2014, 11:40 AM
 * Savitch, 8th Edition - Chapter 2, Problem 10:
 * Have the user input 10 whole numbers in any order - the program
 * is to sum all the positive numbers (> 0), all the negative numbers (<= 0)
 * and all the numbers entered, then display the results. No separating
 * of negative and positive numbers is allowed, and no looping constructs
 * are to be used.
 */

//System Libraries
#include <iostream>
using namespace std;

//Global constants

//Function Prototypes

//Begin execution here
int main(int argc, char** argv) {
    //Define local variables
    int iNum1,iNum2,iNum3,iNum4,iNum5,
        iNum6,iNum7,iNum8,iNum9,iNum10,
        dSumPos = 0,dSumNeg = 0,dSumAll = 0;
    //Get user input
    cout << "Enter 10 whole numbers in any order:" << endl;
    cin >> iNum1 >> iNum2 >> iNum3 >> iNum4 >> iNum5 >>
        iNum6 >> iNum7 >> iNum8 >> iNum9 >> iNum10;
    //Determine whether 1st number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum1;
    if (iNum1 > 0)
        dSumPos += iNum1;
    else
        dSumNeg += iNum1;
    //Determine whether 2nd number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum2;
    if (iNum2 > 0)
        dSumPos += iNum2;
    else
        dSumNeg += iNum2;
    //Determine whether 3rd number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum3;
    if (iNum3 > 0)
        dSumPos += iNum3;
    else
        dSumNeg += iNum3;
    //Determine whether 4th number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum4;
    if (iNum4 > 0)
        dSumPos += iNum4;
    else
        dSumNeg += iNum4;
    //Determine whether 5th number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum5;
    if (iNum1 > 0)
        dSumPos += iNum5;
    else
        dSumNeg += iNum5;
    //Determine whether 6th number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum6;
    if (iNum6 > 0)
        dSumPos += iNum6;
    else
        dSumNeg += iNum6;
    //Determine whether 7th number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum7;
    if (iNum7 > 0)
        dSumPos += iNum7;
    else
        dSumNeg += iNum7;
    //Determine whether 8th number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum8;
    if (iNum8 > 0)
        dSumPos += iNum8;
    else
        dSumNeg += iNum8;
    //Determine whether 9th number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum9;
    if (iNum9 > 0)
        dSumPos += iNum9;
    else
        dSumNeg += iNum9;
    //Determine whether 10th (and final) number is positive or negative,
    //and increment counter variables appropriately
    dSumAll += iNum10;
    if (iNum10 > 0)
        dSumPos += iNum10;
    else
        dSumNeg += iNum10;
    //Display results
    cout << "Sum of all positive numbers: " << dSumPos << endl;
    cout << "Sum of all negative numbers: " << dSumNeg << endl;
    cout << "Sum of all numbers input: " << dSumAll << endl;
    //Exit, stage right
    return 0;
}

