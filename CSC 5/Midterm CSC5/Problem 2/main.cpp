/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 30, 2014, 6:12 AM
 * Midterm problem #2 - Histograms
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global constants
const int MIN_NUM = 1;
const int MAX_NUM = 5;
const int MIN_VAL = 3;
const int MAX_VAL = 27;

//Function Prototypes
void prtHist(unsigned int);
bool isValid(unsigned int);

//Execution begins here
int main(int argc, char** argv) {
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
    return 0;
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
