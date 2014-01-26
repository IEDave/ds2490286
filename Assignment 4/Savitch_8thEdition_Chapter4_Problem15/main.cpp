/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 26, 2014, 12:49 AM
 * Savitch, 8th edition - Chapter 4, Problem 15:
 * Write a program to simulate a vending machine. The item to be sold
 * costs $3.50, and the machine can only accept denominations of 
 * a nickel,dime,quarter, or dollar. When the user has inserted enough coins,
 * the machine will dispense the item, along with any change owed.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const unsigned int DOLLAR = 100;    // Dollar = $1.00
const unsigned int QUARTER = 25;    // Quarter = $.25
const unsigned int DIME = 10;       // Dime = $.10
const unsigned int NICKEL = 5;      // Nickel = $.05
const float CNV_INT = 1.0e2;        // Move decimal 2 places to the right
const float TWINKIE = 3.5e0; // Deep-Fried Twinkie(tm) = $3.50

//Function Prototypes
float addCoin(float, float);
bool isLegit(float);
//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float amtTend, iCoin;
    char iCont = 'Y';
    //Display cheery welcome
    cout << setprecision(2) << fixed << showpoint;
    //Main processing loop
    do {
        //Interior loop handles the actual simulation - we start with a
        //cheery message
        cout << "Welcome to Dave's Deep-fried Twinkies(tm)!" << endl;
        cout << "Each twinkie is " << TWINKIE << " and I can accept" << endl;
        cout << "nickels, dimes, quarters & dollars." << endl;
        cout << endl;
        amtTend = 0; //No money tendered at this point
        //Simulation loop - keep asking for coins until we can vend.
        do {
            //Get user input
            cout << "You have given me $" << amtTend << " so far." << endl;
            cout << "Enter the monetary value of the coin: ";
            cin >> iCoin;
            if (isLegit(iCoin))
               amtTend = addCoin(iCoin,amtTend);
            else
                cout << "I'm sorry - $" << iCoin << " cannot be accepted."
                     << endl;
        } while(amtTend < TWINKIE);
        //At this point the amount tendered should be enough to dispense.
        //Print message & dispense change
        cout << "O.K.! Dispensing deep-fried twinkie(tm)!" << endl;
        if (amtTend > TWINKIE)
            cout << "You get $" << amtTend - TWINKIE << " back in change."
                 << endl;
        cout << "Enjoy your deep-fried twinkie(tm)!" << endl << endl;
        //Check with user - are we done?
        cout << "Would you like to buy another twinkie(tm)(Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    //Exit, stage right
    return 0;
}

//Is the coin legitimate tender?
bool isLegit(float iMoney) {
    //Define local variable
    unsigned int valCoin = static_cast<unsigned int>(iMoney * CNV_INT);
    switch (valCoin) {
        case NICKEL:
            return true;
        case DIME:
            return true;
        case QUARTER:
            return true;
        case DOLLAR:
            return true;
        default:
            return false;
    }               
}

//Valid tender - add to total amount tendered.
float addCoin(float iMoney,float iTotAmt){
    return iTotAmt + iMoney;
}


