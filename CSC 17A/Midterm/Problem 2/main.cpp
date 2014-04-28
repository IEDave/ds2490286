/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 26, 2014, 5:32 PM
 * CSC17A Midterm Problem #2 - Employee Gross Pay
 */

//System Variables
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global constants

//Structures
struct Employee {
    string name;
    float hours;
    float payRate;
    float grosPay;
};

//Function Prototypes
float calcPay(float,float);
void prntChk(Employee);
void numWrds(int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    Employee *empList;
    float usrHrs, usrRate;
    string empName;
    int numEmp,empCnt=0;
    char iCont='Y';
    //Ask user how many employees to process for & dynamically allocate
    //an array to store the data in.
    cout << "Employee check processing:" << endl;
    cout << "How many checks do you wish to process? " << endl;
    cin >> numEmp;
    cin.ignore();
    empList = new Employee[numEmp];
    do {
        //Get user input
        cout << "Check #" << empCnt + 1 << " - Enter employee name: ";
        getline(cin,empName);
        cout << "Enter employee base pay rate: ";
        cin >> usrRate;
        cout << "Enter hours worked: ";
        cin >> usrHrs;
        cin.ignore();
        //Error check & calculate pay
        if ((usrHrs > 0.0) && (usrRate > 0.0)) {
            empList[empCnt].name = empName;
            empList[empCnt].hours = usrHrs;
            empList[empCnt].payRate = usrRate;
            empList[empCnt].grosPay = calcPay(usrHrs,usrRate);
            prntChk(empList[empCnt]);
            empCnt++;
        } else
            cout << "Error on input. Discontinuing check processing." << endl;
    } while((usrHrs > 0.0) && (usrRate > 0.0) && (empCnt < numEmp));
    if (empCnt == numEmp) {
        cout << "All checks processed." << endl;
    }
    //Tidy up before exiting.
    delete [] empList;
    //Exit, stage right!
    return 0;
}

float calcPay(float hours, float payRate) {
    //Declare local constants
    const float CVT_DBL = 2.0e0;  //Double time - 2x straight time.
    const float CVT_TRP = 3.0e0;  //Triple time - 3x straight time.
    const float HRS_DBL = 2.0e1;  //Double time starts at 20 hrs.
    const float HRS_TRP = 4.0e1;  //Triple time starts at 40 hrs.
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

void prntChk(Employee emp) {
    //Define local variables
    int dollars, cents;
    char dol[10], cnt[10];
    string chkDols;
    time_t td = time(0);
    struct tm *now = localtime(&td);
    //Break out dollars and cents of gross pay
    dollars = static_cast<int>(emp.grosPay);
    cents = static_cast<int>((emp.grosPay-static_cast<float>(dollars))*100);
    // Line 1 - today's date
    cout << "                                                             "
         << (now->tm_mon + 1) << '/' << (now->tm_mday) << "/"
         << (now->tm_year + 1900) << endl; 
    //Line 3 - Employee name & numeric dollar amount
    cout << endl << "                    " << left << setw(33) << emp.name
         << right << setw(10) << "$" << dollars << "." << cents / 10
         << cents % 10 << endl;
    //Line 4 - Text payment amount
    numWrds(dollars);
    cout << " & " << cents/10 << cents % 10 << "/100" 
         << endl << endl << endl << endl;
}

void numWrds(int chkVal) {
    const char * const ones[20] = {"ZERO", "ONE", "TWO", "THREE","FOUR","FIVE",
    "SIX","SEVEN","EIGHT","NINE", "ELEVEN","TWELVE","THIRTEEN","FOURTEEN",
    "FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
    const char * const tens[10] = {"", "TEN", "TWENTY", "THIRTY","FORTY",
    "FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};

    if (chkVal >= 1000) {
        numWrds(chkVal / 1000);
        cout << " THOUSAND";
        if(chkVal % 1000) {
            if(chkVal % 1000 < 100) {
                cout << " AND";
            }
            cout << " " ;
            numWrds(chkVal % 1000);
        }
    }
    else if (chkVal >= 100) {
        numWrds(chkVal / 100);
        cout << " HUNDRED";
        if (chkVal % 100) {
            cout << " AND ";
            numWrds(chkVal % 100);
        }
    }
    else if (chkVal >= 20) {
        cout << tens[chkVal / 10];
        if(chkVal % 10) {
            cout << " ";
            numWrds(chkVal % 10);
        }
    }
    else
        cout << ones[chkVal];
    return;
}

