/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Purpose: Chapter 4 menu - mod of template provided by Dr. Mark E. Lehr
 * Created: January 26, 2014
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float CNV_LTR = 2.64179e-1;     // 1 liter = 0.264179 gallon.
const float CNV_PERC = 1.0e2;         //Convert to percent=(fraction*100)-100
const float UNIV_G = 6.673e-8;        //Universal gravitational constant
const float AGE_WST = 2.8e1;          // Cutoff age for waist adj. - 28
const float AGE_CHST = 3.0e1;         // Cutoff age for waist adj. - 30
const unsigned int INTV_WST = 2;      // Adjust every 2 years
const unsigned int INTV_CHS = 10;     // Adjust every 10 years
const float ADJ_CHST = 1.0e0/8.0e0;   // 1/8" for every 10 years over age 30
const float ADJ_WST = 1.0e0/1.0e1;    // 1/10" for every 2 years over age 28
const float CNV_WST = 5.7e0;          // Waist conversion factor
const float CNV_CHST = 2.88e2;        // Chest conversion factor
const float CNV_HAT = 2.9e0;          // Hat size = (weight/height)*2.9
const float FUT_AGE = 1.0e1;          // Future Age = current age + 10 years
const unsigned int DOLLAR = 100;      // Dollar = $1.00
const unsigned int QUARTER = 25;      // Quarter = $.25
const unsigned int DIME = 10;         // Dime = $.10
const unsigned int NICKEL = 5;        // Nickel = $.05
const float CNV_INT = 1.0e2;          // Move decimal 2 places to the right
const float TWINKIE = 3.5e0;          // Deep-Fried Twinkie(tm) = $3.50

//Function prototypes
void prob1(void);
void prob2(void);
float compMpg(float, float);
void prob4(void);
void prob5(void);
float compInf(float,float);
float cFutPri(float,float);
void prob7(void);
float cGrvFrc(float,float,float);
void prob9(void);
void prob10(void);
float cHat(float, float);
float cChest(float, float, float);
float cWaist(float, float);
void prob15(void);
float addCoin(float, float);
bool isLegit(float);

//Execution begins here
int main(int argc, char** argv) {
    //General Menu Format
    bool loop = true;
    do {
        //Display the selection
        cout << "Savitch - Chapter 4"<<endl;;
        cout << "Type 1 to solve problem 1" << endl;
        cout << "Type 2 to solve problem 2" << endl;
        cout << "Type 3 to solve problem 4" << endl;
        cout << "Type 4 to solve problem 5" << endl;
        cout << "Type 5 to solve problem 7" << endl;
        cout << "Type 6 to solve problem 9" << endl;
        cout << "Type 7 to solve problem 10" << endl;
        cout << "Type 8 to solve problem 15" << endl;
        cout << "Type anything else to quit with no solutions." << endl;
        //Read the choice
        char choice;
        cin >> choice;
        //Solve a problem that has been chosen.
        switch (choice) {
            case '1':
                prob1();
                break;
            case '2':
                prob2();
                break;
            case '3':
                prob4();
                break;
            case '4':
                prob5();
                break;
            case '5':
                prob7();
                break;
            case '6':
                prob9();
                break;
            case '7':
                prob10();
                break;
            case '8':
                prob15();
                break;
            default:
            {
                cout << "Exit?" << endl;
                loop = false;
                break;
            }
        };
    } while (loop); //Upper do-while
    return 0;
}

void prob1() {
    /* 
     * Author: David W. Smith
     * Created on January 23, 2014, 2:39 AM
     * Savitch, 8th Edition - Chapter 4, Problem 1:
     * Write a program that accepts the following user input:
     * - Liters consumed
     * - Miles driven
     * and computes the miles per gallon. A function should be used
     * to compute the MPG figure, and the user should be allowed
     * to input data as often as they wish.
     */

    //Execution begins here
    //Define local variables
    float iMiles;
    float iLiters;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter miles driven: ";
        cin >> iMiles;
        cout << "Enter liters of fuel consumed: ";
        cin >> iLiters;
        //compute MPG, display output
        cout << "Miles per gallon: " << compMpg(iMiles, iLiters) << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while (iCont == 'Y');
    //Exit, stage right
    return;
}

void prob2() {
    /* 
     * Author: David W. Smith
     * Created on January 23, 2014, 3:24 AM
     * Savitch, 8th Edition - Chapter 4, Problem 2:
     * Modification of Program 1 - compare 2 cars by computing MPG
     * for both - display MPG for both, and determine the winner.
     */
    
    //Execution begins here
    //Define local variables
    float iCar1M, iCar1L, iCar2M, iCar2L;
    float dCar1M, dCar2M;
    //Get user input - car #1
    cout << "Car #1 - Enter miles driven: ";
    cin >> iCar1M;
    cout << "         Enter liters of fuel consumed: ";
    cin >> iCar1L;
    //Get user input - car #2
    cout << "Car #2 - Enter miles driven: ";
    cin >> iCar2M;
    cout << "         Enter liters of fuel consumed: ";
    cin >> iCar2L;
    //compute MPG, display output
    dCar1M = compMpg(iCar1M, iCar1L);
    dCar2M = compMpg(iCar2M, iCar2L);
    cout << "Car #1 - MPG: " << dCar1M << "   Car #2 - MPG: " << dCar2M << endl;
    //Determine the more fuel efficient car
    if (dCar1M > dCar2M)
        cout << "Car #1 is more fuel efficient than car #2." << endl;
    else if (dCar1M < dCar2M)
        cout << "Car #2 is more fuel efficient than car #1" << endl;
    else
        cout << "Both cars have equal fuel efficiency." << endl;
    //Exit, stage right
    return;
}

//Function compMpg - takes in distance traveled (in miles) and amount of
//fuel consumed (in liters) - returns MPG.
float compMpg(float iDist, float iUsed) {
    //Define local variable
    float mGal;
    //Calculate MPG, return result
    mGal = iUsed * CNV_LTR;
    return iDist / mGal;
}

void prob4(void) {
    /* 
     * Author: David W. Smith
     * Created on January 23, 2014, 3:51 AM
     * Savitch, 8th Edition - Chapter 4, Problem 4:
     * Write a program that accepts the following user input:
     * - Price of an item 1 year ago
     * - Price of the same item today
     * and estimate the rate of inflation by dividing the current
     * price by the year-ago price. The user should be allowed to input
     * data as often as they wish.
     */
    
    //Define local variables
    float iYrAgo, iToday;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter item price 1 year ago: ";
        cin >> iYrAgo;
        cout << "Enter item price today: ";
        cin >> iToday;
        //compute MPG, display output
        cout << setprecision(2) << fixed << showpoint;
        cout << "Estimated rate of inflation: " << compInf(iYrAgo, iToday) << "%"
                << endl;
        cout << "(Negative rate of inflation indicates error or deflation.)"
                << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while (iCont == 'Y');
    //Exit, stage right
    return;
}
void prob5(void){
/* 
 * Author: David W. Smith
 * Created on January 23, 2014, 4:17 AM
 * Savitch, 8th Edition - Chapter 4, Problem 5:
 * Modify program to estimate prices one and two
 * years from now, based on current estimated
 * inflation rate. Write function to accomplish this.
 */
    //Define local variables
    float iYrAgo, iToday, mRate, dFut1Yr, dFut2Yr;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter item price 1 year ago: ";
        cin >> iYrAgo;
        cout << "Enter item price today: ";
        cin >> iToday;
        //compute MPG, display output
        mRate = compInf(iYrAgo, iToday);
        cout << setprecision(2) << fixed << showpoint;
        cout << "Estimated rate of inflation: " << mRate <<"%"
             << endl;
        cout << "(Negative rate of inflation indicates error or deflation.)"
             << endl;
        dFut1Yr = cFutPri(mRate,iToday);
        dFut2Yr = cFutPri(mRate,dFut1Yr);
        cout << "Estimated price for next year: $" << dFut1Yr << endl;
        cout << "Estimated price 2 years from now: $" << dFut2Yr << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    //Exit, stage right
    return;
}

//Function compInf - Estimates rate of inflation by comparing current
//item price to year ago item price
float compInf(float iLastYr, float iThisYr) {
    //Define local variable
    float mInfRt;
    //Calculate inflation rate, convert to percentage
    if (iLastYr != 0.0) {
        mInfRt = iThisYr / iLastYr;
        //convert to percentage & return
        return mInfRt * CNV_PERC - CNV_PERC;
    }
    else 
        return -1;
}

//Function cFutPri - Estimates future price based on current price &
//inflation rate.
float cFutPri(float iRate, float iPrice) {
    return iPrice * (iRate / CNV_PERC) + iPrice;
}

void prob7(void) {
/* 
 * Author: David W. Smith
 * Created on January 25, 2014, 9:05 PM
 * Savitch, 8th Edition - Chapter 4, Problem 7:
 * Write a program to calculate the gravitational
 * attraction between 2 bodies. Define the universal
 * gravitational constant G as a global constant, and
 * use a function to return the force in dynes. Inputs
 * for mass shall be in grams, and distance shall be in
 * centimeters (CGS units);
 */

    //Define local variables
    float iMass1 = 0, iMass2 = 0, iDist = 0, dForce;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter mass of body #1 in grams: ";
        cin >> iMass1;
        cout << "Enter mass of body #2 in grams: ";
        cin >> iMass2;
        cout << "Enter distance between bodies in centimeters: ";
        cin >> iDist;
        //Call function and display result.
        cout << "The force between the 2 masses at the specified distance "
             << "is " << cGrvFrc(iMass1,iMass2,iDist) << " dynes." << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    //Exit, stage right
    return;
}

//Calculate the gravitational attraction between 2 masses at a specified
//distance using Newton's gravitational law.
float cGrvFrc(float mMass1, float mMass2, float mDist) {
    return (UNIV_G * mMass1 * mMass2) / (mDist * mDist);
}

void prob9(void){
/* 
 * Author: David Smith
 * Created on January 25, 2014, 10:02 PM
 * Savitch, 8th Edition - Chapter 4, Problem 9
 * Using supplied formulae, accept input from user re: person's age,
 * weight & height, then determine the person's hat size, jacket (e.g chest)
 * size, and waist size. Chest and waist measurements are to be altered
 * based on person's age.
 */
 
    //Define local variables
    float iHeight, iWeight, iAge;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter person's weight in pounds: ";
        cin >> iWeight;
        cout << "Enter person's height in inches: ";
        cin >> iHeight;
        cout << "Enter person's age in years: ";
        cin >> iAge;
        cout << endl;
        //Calculate & display hat, chest & waist sizes for person
        cout << "The person's hat size is: " << cHat(iHeight,iWeight) << endl;
        cout << "The person's jacket(chest) size is: " 
             << cChest(iHeight,iWeight,iAge) << endl;
        cout << "The person's waist size is: " << cWaist(iWeight,iAge) << endl;
        cout << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    //Exit, stage right
    return ;
}
void prob10(void){
/* 
 * Author: David W. Smith
 * Created on January 26, 2014, 12:17 AM
 * Savitch, 8th Edition - Chapter 4, Problem 10
 * Modify program for problem #9 to display waist & jacket sizes in 10
 * years.
 */
    //Define local variables
    float iHeight, iWeight, iAge;
    char iCont = 'Y';
    //Main processing loop
    do {
        //Get user input
        cout << "Enter person's weight in pounds: ";
        cin >> iWeight;
        cout << "Enter person's height in inches: ";
        cin >> iHeight;
        cout << "Enter person's age in years: ";
        cin >> iAge;
        cout << endl;
        //Calculate & display hat, chest & waist sizes for person
        cout << "The person's hat size is: " << cHat(iHeight,iWeight) << endl;
        cout << "The person's jacket(chest) size is: " 
             << cChest(iHeight,iWeight,iAge) << endl;
        cout << "The person's waist size is: " << cWaist(iWeight,iAge) << endl;
        cout << endl;
        iAge += FUT_AGE;
        cout << "In " << FUT_AGE << " years..." << endl;
        cout << "The person's jacket(chest) size will be: " 
             << cChest(iHeight,iWeight,iAge) << endl;
        cout << "The person's waist size will be: " << cWaist(iWeight,iAge)
             << endl;
        cout << endl;
        //Check with user - are we done?
        cout << "Would you like to continue (Y/N)? ";
        cin >> iCont;
        //Make sure confirmation is in uppercase
        if (iCont == 'y')
            iCont = 'Y';
    } while(iCont == 'Y');
    //Exit, stage right
    return ;
}

//Calculate person's hat size
float cHat(float mHeight, float mWeight) {
    return mWeight / mHeight * CNV_HAT;
}

//Calculate person's chest size
float cChest(float mHeight, float mWeight, float mAge){
    //Define local variables
    float mChest = mHeight * mWeight / CNV_CHST;
    //Adjust for age
    if (mAge > AGE_CHST) {
        mChest += static_cast<unsigned int>(mAge-AGE_CHST)/INTV_CHS*ADJ_CHST;
    }
    return mChest;
}

//Calculate person's waist size
float cWaist(float mWeight, float mAge){
    //Define local variables
    float mWaist = mWeight / CNV_WST;
    //Adjust for age
    if (mAge > AGE_WST) {
        mWaist += static_cast<unsigned int>(mAge-AGE_WST)/INTV_WST*ADJ_WST;
    }
    return mWaist;
}

void prob15(void){
/* 
 * Author: David W. Smith
 * Created on January 26, 2014, 12:49 AM
 * Savitch, 8th edition - Chapter 4, Problem 15:
 * Write a program to simulate a vending machine. The item to be sold
 * costs $3.50, and the machine can only accept denominations of 
 * a nickel,dime,quarter, or dollar. When the user has inserted enough coins,
 * the machine will dispense the item, along with any change owed.
 */
    
    //Define local variables
    float amtTend, iCoin;
    char iCont = 'Y';
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
    return;
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
