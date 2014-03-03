/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 30, 2014, 6:28 PM
 * Midterm - Problem 3, Checking account balance
 */
//SYstem Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants
const float OVERDRF = 2.775e1;  //Overdraft fee = $27.75
const float CVT_CNT = 1.00e2;   //for converting those unsigned shorts to floats
const unsigned short MAX_ACCT = 65535; //Kind of pointless - c++ will truncate
const unsigned short MIN_ACCT = 0;
const unsigned short MAX_SHRT = 32767; //Any bigger and we can't tell if
                                       //the number is negative or positive
const unsigned short MIN_SHRT = 0;
const unsigned short MAX_CNT = 99; //99 cents is as big as you can go before
                                   //dollars start kicking in.
const unsigned short MIN_CNT = 0;


//Function Prototypes
bool isAcct(unsigned short);
bool isMoney(unsigned short, unsigned short);
void calcBal(unsigned short,unsigned short,unsigned short,unsigned short,
             unsigned short,unsigned short,unsigned short);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    unsigned short acctNum, balDol, balCnt, dbtDol, dbtCnt, cdtDol, cdtCnt;
    char decPt,iCont='Y';
    cout << "Checking account balance" << endl << endl;
    do {
        //Get user input
        cout << "Enter checking account number (0-65535):";
        cin >> acctNum;
        if (isAcct(acctNum)) {
            cout << "Enter current account balance (0.00 - 32767.99): $";
            cin >> balDol >> decPt >> balCnt;
            if (isMoney(balDol,balCnt)) {
                cout << "Enter total of checks written (0.00 - 32767.99): $";
                cin >> dbtDol >> decPt >> dbtCnt;
                if (isMoney(dbtDol,dbtCnt)) {
                    cout << "Enter total of deposits made (0.00 - 32767.99): $";
                    cin >> cdtDol >> decPt >> cdtCnt;
                    if (isMoney(cdtDol,cdtCnt)) {
                       //All input should be good - calculate total account
                       //balance & determine overdraft penalties (if any)
                        calcBal(acctNum,balDol,balCnt,dbtDol,dbtCnt,cdtDol,
                                cdtCnt);
                    } else
                        cout << "Invalid credit amount." << endl;
                } else
                    cout << "Invalid debit amount." << endl;
            } else
                cout << "Invalid account balance." << endl;
        } else
            cout << "Invalid account number." << endl;
        //Confirm with user - are we done?
        cout << "Do you wish to continue(Y/N)?";
        cin >> iCont;
        (iCont == 'y')?iCont = 'Y':iCont=iCont;
        cout << endl << endl;
    } while(iCont == 'Y');
    //Exit, stage right
    return 0;
}

bool isAcct(unsigned short acct) {
    //Kind of pointless - if the account number is too big, C++ will just
    //truncate it to fit. Really needs to be a string of characters...
    if (acct >= MIN_ACCT && acct <= MAX_ACCT)
        return true;
    else
        return false;
}

bool isMoney(unsigned short dollars,unsigned short cents) {
    if ((dollars >= MIN_SHRT) && (dollars <= MAX_SHRT) && 
            (cents >= MIN_CNT) && (cents <= MAX_CNT))
        return true;
    else
        return false;
}

void calcBal(unsigned short acct,unsigned short bdol,unsigned short bcnt,
             unsigned short ddol, unsigned short dcnt,
             unsigned short cdol ,unsigned short ccnt) {
    //define local variables
    float total, balance, checks, deposit;
    //Prepare to display dollars
    cout << setprecision(2) << fixed << showpoint;
    //Convert account balance to float
    balance = static_cast<float>(bdol) + (static_cast<float>(bcnt)/CVT_CNT);
    cout << "balance = " << balance << endl;
    //Convert checks to float
    checks = static_cast<float>(ddol) + (static_cast<float>(dcnt)/CVT_CNT);
    cout << "checks = " << checks << endl;
    //Convert deposits to float
    deposit = static_cast<float>(cdol) + (static_cast<float>(ccnt)/CVT_CNT);
    cout << "checks = " << deposit << endl;
    //Add 'em up - if negative, hit 'em with an overdraft charge.
    total = balance + deposit - checks;
    cout <<"The balance for account #"<<acct<< " is $" << total << "." << endl;
    if (total < 0.0) {
        cout << "You will be assessed an additional $" << OVERDRF
             << " for an overdraft penalty." << endl;
        cout << "This will give you a total account balance of $"
             << total - OVERDRF << "." << endl;         
    }
    return;
}