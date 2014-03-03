//David W. Smith
//January 14th, 2014
//Menu to be used for the midterm
//homework and final, etc....

//Library includes Here!!!
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants Here!!!
//Problem 2
const int MIN_NUM = 1;
const int MAX_NUM = 5;
const int MIN_VAL = 3;
const int MAX_VAL = 27;
//Problem 3
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
//Problem 4
const float CVT_DBL = 2.0e0;  //Double time - 2x straight time.
const float CVT_TRP = 3.0e0;  //Triple time - 3x straight time.
const float HRS_DBL = 2.0e1;  //Double time starts at 20 hrs.
const float HRS_TRP = 4.0e1;  //Triple time starts at 40 hrs.
//Problem 5
const float CUTOFF1 = 1.1e1;   //11 hours
const float CUTOFF2 = 2.2e1;   //22 hours
const float CUTOFF3 = 3.3e1;   //33 hours
const float BASERTA = 2.995e1; //$29.95 - plan a base rate
const float BASERTB = 3.495e1; //$34.95 - plan b base rate
const float BASERTC = 3.975e1; //$39.75 - plan c base rate
const float CUTOF1A = 2.75e0;  //$2.75 - level 1 overage plan a
const float CUTOF1B = 1.50e0;  //$1.50 - level 1 overage plan b
const float CUTOF1C = 0.0e0;   //$0.00 - level 1 overage plan c
const float CUTOF2A = 5.0e0;   //$5.00 - level 2 overage plan a
const float CUTOF2B = 2.5e0;   //$2.50 - level 2 overage plan b (hourly)
const float CUTOF2C = 0.0e0;   //$0.00 - level 2 overage plan c

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
//Problem 2
void prtHist(unsigned int);
bool isValid(unsigned int);
//Problem 3
bool isAcct(unsigned short);
bool isMoney(unsigned short, unsigned short);
void calcBal(unsigned short,unsigned short,unsigned short,unsigned short,
             unsigned short,unsigned short,unsigned short);
//Problem 4
float calcPay(float,float);
//Problem 5
float clcBill(float, char);
bool isPlan(char &);
//Problem 6
bool isFunny(unsigned int);

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 6"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
/* 
 * Author: David W. Smith
 * Created on January 29, 2014, 2:15 AM
 * Midterm Problem #1 - ask user for number of lines to output,
 * then print a column of numbers, with each # indented row #
 * of spaces (e.g. col = row). 
 */
    // Define local variables
    int usrCnt;
    //Get user input
    cout << "Enter the number of lines to output: ";
    cin >> usrCnt;
    //Minimal error checking - then, print them numbers!
    if (usrCnt > 0) {
        for (int col = 1; col <= usrCnt; col++){
            for (int row = 1; row < col; row++)
                cout << " ";
            cout << col << endl;
        }
    } else
        cout << "Numbers less than 1 are not accepted. Sorry." << endl;
    //Exit, stage right.
    return;
}

void problem2(){
/* 
 * Author: David Smith
 * Created on January 30, 2014, 6:12 AM
 * Midterm problem #2 - Histograms
 */
    //Define local variables
    unsigned int usrNum1, usrNum2, usrNum3, usrNum4, usrNum5, iNum, valCnt;
    char iCont = 'Y';
    bool isVal;

    //Main execution loop
    do {
        //Get the number of numbers we are expected to input
        cout << "How many values (1 - 5) would you like on your histogram: ";
        cin >> iNum;
        usrNum1 = 0;
        usrNum2 = 0;
        usrNum3 = 0;
        usrNum4 = 0;
        usrNum5 = 0;
        if ((iNum >= MIN_NUM)&&(iNum <= MAX_NUM)) {
            cout << "O.K. Now, you will be asked to enter " <<iNum<< " values,"
                 << " one at a time." << endl
                 << "Each value should be between 3 and 27 - "
                 << "if any are not," <<endl<< "none will be displayed."<<endl;
            valCnt = MIN_NUM;
            isVal = true;
            do {
                switch (valCnt){
                    case 1:
                        cout << "Enter value #1: ";
                        cin >> usrNum1;
                        isVal = isValid(usrNum1);
                        break;
                    case 2:
                        cout << "Enter value #2: ";
                        cin >> usrNum2;
                        isVal = isValid(usrNum2);
                        break;
                    case 3:
                        cout << "Enter value #3: ";
                        cin >> usrNum3;
                        isVal = isValid(usrNum3);
                        break;
                    case 4:
                        cout << "Enter value #4: ";
                        cin >> usrNum4;
                        isVal = isValid(usrNum4);
                        break;
                    case 5:
                        cout << "Enter value #5: ";
                        cin >> usrNum5;
                        isVal = isValid(usrNum5);
                        break;
                }
                valCnt++;
            } while((valCnt <= iNum) && isVal);
            //If all numbers are valid, print histogram
            if (isVal) {
                prtHist(usrNum1);
                prtHist(usrNum2);
                prtHist(usrNum3);
                prtHist(usrNum4);
                prtHist(usrNum5);
                cout << endl;
            } else
                cout << "Sorry - an invalid number was entered." << endl;
        } else
            cout << "Sorry - that is not a number between 1 and 5." << endl;
        //Confirm with user - are we done?
        cout << "Do you wish to continue(Y/N)?";
        cin >> iCont;
        (iCont == 'y')?iCont = 'Y':iCont=iCont;
        cout << endl << endl;
    } while(iCont == 'Y');
    //Exit, stage right
    return;
}

bool isValid(unsigned int iNum) {
    if ((iNum >= MIN_VAL)&&(iNum <= MAX_VAL))
        return true;
    else
        return false;
}

void prtHist(unsigned int num){
    if (num) {
       cout << setw(3)<< num << setw(1) << " ";
       for (int i = 1; i<=num; i++)
           cout << "*";
       cout << endl;
    }
}

void problem3(){
/* 
 * Author: David W. Smith
 * Created on January 30, 2014, 6:28 PM
 * Midterm - Problem 3, Checking account balance
 */
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
    return;
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
    //Convert checks to float
    checks = static_cast<float>(ddol) + (static_cast<float>(dcnt)/CVT_CNT);
    //Convert deposits to float
    deposit = static_cast<float>(cdol) + (static_cast<float>(ccnt)/CVT_CNT);
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

void problem4(){
/* 
 * Author: David W. Smith
 * Created on January 30, 2014, 5:32 PM
 * Midterm Problem #4 - Employee Gross Pay
 */
    //Define local variables
    float usrHrs, usrRate;
    char iCont='Y';
    cout << setprecision(2) << fixed << showpoint;
    do {
        //Get user input
        cout << "Enter employee base pay rate: ";
        cin >> usrRate;
        cout << "Enter hours worked: ";
        cin >> usrHrs;
        //Error check & calculate pay
        if ((usrHrs > 0.0) && (usrRate > 0.0)) {
            cout << "Gross pay for this employee is $"
                 << calcPay(usrHrs,usrRate) << "." << endl;
        } else
            cout << "Error on input." << endl;
        //Confirm with user - are we done?
        cout << "Do you wish to continue(Y/N)?";
        cin >> iCont;
        (iCont == 'y')?iCont = 'Y':iCont=iCont;
        cout << endl << endl;
    } while(iCont == 'Y');
    //Exit, stage right!
    return;
}

float calcPay(float hours, float payRate) {
    //Define local variables
    float totPay = 0.0e0;
    //Calculate gross pay
    if (hours > HRS_TRP) {
         totPay += ((hours - HRS_TRP) * (CVT_TRP * payRate));
         hours -= (hours - HRS_TRP);
    }
    if (hours > HRS_DBL) {
         totPay += ((hours - HRS_DBL) * (CVT_DBL * payRate));
         hours -= (hours - HRS_DBL);
    }
    if (hours > 0.0) {
         totPay += hours * payRate;
    }  

    return totPay;
}

void problem5(){
/* 
 * Author: David Smith
 * Created on January 30, 2014, 3:07 PM
 * Midterm problem 5 - ISP billing
 */
    //Define local variables
    float usrHrs;
    char iPlan, iCont='Y';
    //Set up for monetary printing
    cout << setprecision(2) << fixed << showpoint;
    do {
        //Explain plans, then get user selection
        cout << "Welcome to CSC ISP billing!" << endl;
        cout << "We have 3 billing plans:" << endl;
        cout << "Plan 'A' - $"<<BASERTA<<"/month for the first 11 hours access."
                <<endl;
        cout << "           The next 11 hours of usage costs $" << CUTOF1A
             << ", with"<<endl;
        cout << "           additional hours costing only $" << CUTOF2A
             << ". "<< endl;
        cout << "Plan 'B' - $"<<BASERTB<<"/month for the first 22 hours access."
             << endl;
        cout << "           The next 11 hours of access costs just $" << CUTOF1B
             << ", with"<<endl;
        cout << "           additional hours costing only $" << CUTOF2B
             << " per hour! "<< endl;
        cout << "Plan 'C' - $"<<BASERTC<<"/month, with unlimited usage - our "
             << "most popular plan!" << endl;

        cout << "Enter plan: ";
        cin >> iPlan;
        cout << "Enter hours: ";
        cin >> usrHrs;
        //Error check & compute bill
        if (isPlan(iPlan) && (usrHrs > 0.0)) {
            cout << "Your bill for this month is $"
                 << clcBill(usrHrs,iPlan) << "." << endl;
        } else
            cout << "Error on input." << endl;
        //Confirm with user - are we done?
        cout << "Do you wish to continue(Y/N)?";
        cin >> iCont;
        (iCont == 'y')?iCont = 'Y':iCont=iCont;
        cout << endl << endl;
    } while(iCont == 'Y');
    //Exit, stage right!
    return;
}

bool isPlan(char &plan){
    //Coerce to uppercase
    if ((plan >='a') && (plan <= 'c')) {
        plan = plan - 'a' + 'A';
    }
    //Is it between 'A' & 'C'?
    if ((plan >='A') && (plan <= 'C'))
        return true;
    else 
        return false;
}
  
float clcBill(float hours, char tier) {
    //Define local variables
    float totBill = 0.0e0;
    //Calculate bill
    switch(tier) {
        case 'A':
            if (hours > CUTOFF2) {
                totBill += CUTOF2A;
            }
            if (hours > CUTOFF1) {
                totBill += CUTOF1A;
            }
            if (hours > 0) {
                totBill += BASERTA;
            }      
            break;
        case 'B':
            if (hours > CUTOFF3) {
                totBill += ((hours - CUTOFF3) * CUTOF2B);
            }
            if (hours > CUTOFF2) {
                totBill += CUTOF1B;
            }
            if (hours > 0) {
                totBill += BASERTB;
            }  
            break;
        case 'C':
            totBill = BASERTC;
            break;
    }
    return totBill;
}

void problem6(){
/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 28, 2014, 7:51 PM
 * Midterm problem #6 - Funny Numbers
 */
    //Define local variables
    unsigned int count = 0, funny = 0;
    while (count < 1501) {
        funny++;
        if (isFunny(funny)) {
            count++;
        }
    }
    cout << "The 1501'st funny number is: " << funny << "." << endl;
    //Exit, stage right!
    return;
}

bool isFunny(unsigned int check) {
    //Strip out all the factors of 2
    while(!(check % 2))
        check /= 2;
    //Strip out all the factors of 3
    while(!(check % 3))
        check /= 3;
    //Strip out all the factors of 5
    while(!(check % 5))
        check /= 5;
    //Check to see what's left. If it's a 1,
    //we've got us a funny number. If not,
    //there are other factors and, hence,
    //it's not a funny number
    if (check == 1)
        return true;
    else
        return false;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}