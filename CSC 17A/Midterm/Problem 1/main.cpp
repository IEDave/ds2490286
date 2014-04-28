/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 26, 2014, 4:28 AM
 * Midterm - Problem 1, Checking account balance
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

//Global Constants

//Structures
struct Account {
    int acctNum;
    int prevBal;
    int totChek;
    int totDpst;
};

//Function Prototypes
int getAcct(string &);
int getChks();
void calcBal(Account, const int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants
    const int OVERDRF = 12;  //Overdraft fee = $12
    //Define local variables
    Account usrAcct;
    string acctNo;
    cout << "Checking account balance" << endl << endl;
    //Get user input
    cout << "Enter checking account number (00000-99999):";
    usrAcct.acctNum = getAcct(acctNo);
    if (usrAcct.acctNum != -1) {
        cout << "Enter beginning balance (to the nearest whole dollar): $";
        cin >> usrAcct.prevBal;
        cout << "Enter checks written against this account:" << endl;
        usrAcct.totChek = getChks();
        cout << "Enter checks deposited to this account:" << endl;
        usrAcct.totDpst = getChks();
        //Calculate bank balance, display results
        cout << endl << endl << "For account #" << acctNo << ":" << endl;
        calcBal(usrAcct, OVERDRF);
    } else
       cout << "Invalid account number." << endl;
    //Exit, stage right
    return 0;
}

int getAcct(string &acctNo) {
    //Reads in exactly 6 characters - 5 digits & a newline. If any of this
    //is violated, returns a -1 indicating erroneous input.
    //Define local constant
    const int ACCTLEN = 5;
    //Define local variables
    bool isValid = true;
    getline(cin,acctNo);
    //Check to see if it has 5 characters
    if (acctNo.length() != ACCTLEN)
        isValid = false;
    //Check to see if it's a number
    for (int i=0; i < ACCTLEN; i++) {
        if (!isdigit(acctNo[i]))
            isValid = false;
    }
    //If it's O.K. - convert to integer & return else return -1
    if (isValid)
        return atoi(acctNo.c_str());
    else
        return -1;
}

int getChks() {
    //Define local variables
    int usrInp,chkNum=0,totChks=0;
    do {
        cout << " Enter dollar amount for check #" << ++chkNum << " (0 to exit)"
             << ":$";
        cin >> usrInp;
        if (usrInp > 0)
            totChks += usrInp;
        else
            break;
    } while(true);
    return totChks;
}

void calcBal(Account acctBal, const int penalty) {
    //Define local variables
    int newBal = acctBal.prevBal + acctBal.totDpst - acctBal.totChek;
    cout << "Beginning monthly balance: $" << acctBal.prevBal << endl;
    cout << "Total checks deposited: $" << acctBal.totDpst << endl;
    cout << "Total checks written against account: $"<< acctBal.totChek << endl;
    cout << "Current account balance: $" << newBal << endl;
    if (newBal <= 0) {
        cout << "with $" << penalty << " penalty, current account balance: $"
             << newBal - penalty << "." << endl;
    } 
    return;
}