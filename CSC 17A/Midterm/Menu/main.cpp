//Dr. Mark E. Lehr
//April 21st, 2014
//Menu to be used for the midterm
//homework and final, etc....

//Library includes Here!!!
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants Here!!!

//Structures here!!!
//Problem 1
struct Account {
    int acctNum;
    int prevBal;
    int totChek;
    int totDpst;
};
//Problem 2
struct Employee {
    string name;
    float hours;
    float payRate;
    float grosPay;
};
//Problem 3
struct statsResult {
    float avg;
    float median;
    int *mode;   //Array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
//
void problem1();
int getAcct(string &);
int getChks();
void calcBal(Account, const int);
//
void problem2();
float calcPay(float,float);
void prntChk(Employee);
void numWrds(int);
//
void problem3();
int *fillAry(int);
void prntAry(int *,int,int);
void sort(int *,int *,int);
int maxFreq(int *,int);
int nuMds(int *,int,int);
void filMdSt(int *, int *, int, int);
int *mode(int *,int);
float mean(int *,int);
float median(int *, int);
void printStat(int *,int);
void printStat(statsResult *,int);
statsResult *avgMedMode(int *,int);
void filMode(int *, int *, int, int);
void destroy(int *);
//
void problem4();
int encrypt(int);
int valOctl(string);
//
void problem5();
string decrypt(int);
void problem6();
void problem7();

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
        case 7:    problem7();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=7);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4a"<<endl;
    cout<<"Type 5 for problem 4b"<<endl;
    cout<<"Type 6 for problem 5"<<endl;
    cout<<"Type 7 for problem 6"<<endl;
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
 * Created on April 26, 2014, 4:28 AM
 * Midterm - Problem 1, Checking account balance
 */
    //Define local constants
    const int OVERDRF = 12;  //Overdraft fee = $12
    //Define local variables
    Account usrAcct;
    string acctNo;
    cout << "Checking account balance" << endl << endl;
    //Get user input
    cin.ignore(); //Necessary for menuized version
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
    return;
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

void problem2(){
/* 
 * Author: David W. Smith
 * Created on April 26, 2014, 5:32 PM
 * CSC17A Midterm Problem #2 - Employee Gross Pay
 */
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
    return;
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

void problem3(){
/* 
 * Author: David Smith
 * Created on April 28th, 2014, 05:49 AM
 * Determine mode, median & mean of a set of numbers.
 * Based on example provided by Dr. Mark E. Lehr.
 */
    //Define local variables
    //const int SIZE=100;
    int mFreq,nElem,size;
    statsResult *results;
    //Ask user for size of array
    cout << "How many elements in the array: ";
    cin >> size;
    //Create & populate an array
    int *array = fillAry(size);
    for (int i = 0; i < size; i++) {
        cout << "Value for array element #" << i << ":";
        cin >> array[i];
    }
    int *brray = fillAry(size);
    //Print array contents
    prntAry(array,size,10);
    //Sort array
    sort(array,brray,size);
    //Print sorted array
    prntAry(brray,size,10);
    cout << endl;
    //Generate mode set
    //int *srray = mode(brray,SIZE);
    results = avgMedMode(brray,size);
    //Print mode set
    //printStat(srray,10);
    printStat(results,10);
    //Delete dynamic arrays (prevents memory leaks))
    destroy(array);
    destroy(brray);
    //destroy(srray);
    destroy(results->mode);
    delete [] results;
    //Exit, stage right
    return;
}

float mean(int *a, int n) {
    //Define local variables
    float totSet = 0;
    for (int i=0; i<n; i++)
        totSet += static_cast<float>(*(a+i));
    return totSet/static_cast<float>(n);  
}

float median(int *a,int n) {
    if (n%2 == 1) {
       return static_cast<float>(*(a+((n/2)+1)));
    } else {
       return static_cast<float>((*(a+(n/2))+*(a+((n/2)+1))))/2.0;
    }
}

void printStat(statsResult *a,int perLine) {
    //Define local variables
    //Print contents of structure
    cout << "Average of set: " << a->avg << endl;
    cout << "Median of set: " << a->median << endl;
    cout << "Number of elements in mode set = " << a->nModes << endl;
    cout << "Max frequency = " << a->maxFreq << endl;
    if (a->nModes > 0) {
         //...print the actual mode set.
         cout << "Mode set = {";
         for (int i=0; i < (a->nModes-1); i++) {
             cout << a->mode[i] << ", ";
             if (i%perLine == (perLine-1))
                 cout << endl;
         }
         cout << a->mode[(a->nModes-1)] << "}." << endl;
    }
}

void printStat(int *a,int perLine) {
     //Define local variables
     int n = *(a)+2; //+2 to skip over the first 2 array elements
     //Print # of elements & max frequency first, then...
     cout << "Number of elements in mode set = " << *(a) << endl;
     cout << "Max frequency = " << *(a+1) << endl;
     if (*(a) > 0) {
         //...print the actual mode set.
         cout << "Mode set = {";
         for (int i=2; i<(n-1); i++) {
             cout << *(a+i) << ", ";
             if (i%perLine == (perLine-1))
                 cout << endl;
         }
         cout << *(a+(n-1)) << "}." << endl;
     }
}
 
 statsResult *avgMedMode(int *a, int n) {
     statsResult *s = new statsResult;
     s->avg = mean(a,n);
     s->median = median(a,n);
     s->maxFreq = maxFreq(a,n);
     s->nModes = nuMds(a,n,s->maxFreq);
     s->mode = fillAry(s->nModes);
     filMode(a,s->mode,n,s->maxFreq);
     return s;
 }
 
void filMode(int *a, int *mset, int n, int maxFreq) {
    //This function populates the mode array.
    //Declare local variable
    int kount=1, mdIndex=0;
    //loop and compare
    for (int i=1; i<n; i++) {
        if (*(a+(i-1)) == *(a+i)) {
            kount++;
            if (kount == maxFreq) {
                *(mset+mdIndex) = *(a+(i-1));
                mdIndex++;
            }
        } else
            kount = 1;
    }
}

int *mode(int *a, int n){
    //This is really just an amalgam of other function calls to conform to
    //assignment specifications.
    int mFreq = maxFreq(a,n);
    int nElem = nuMds(a,n,mFreq);
    int *s = fillAry(nElem+2);
    filMdSt(a, s, n, mFreq);
    return s;
}

void filMdSt(int *a, int *mset, int n, int maxFreq) {
    //This function (filMdSt = Fill Mode Set) populates the mode array.
    //Declare local variable
    int kount=1, mdIndex=2;
    //loop and compare
    for (int i=1; i<n; i++) {
        if (*(a+(i-1)) == *(a+i)) {
            kount++;
            if (kount == maxFreq) {
                *(mset+mdIndex) = *(a+(i-1));
                mdIndex++;
            }
        } else
            kount = 1;
    }
    *(mset+1) = maxFreq;
    *(mset) = mdIndex-2;
}

int nuMds(int *a, int n, int maxFreq) {
    //This function counts the number of elements that will be in the mode set.
    //Declare local variables
    int kount=1, numElem=0;
    //loop and compare
    for (int i=1; i<n; i++) {
        if (*(a+(i-1)) == *(a+i)) {
            kount++;
            if (kount == maxFreq)
                numElem++;
        } else
            kount = 1;
    }
    return numElem;
}

void destroy(int *a) {
    delete []a;
}

//Req. sorted array for input
int maxFreq(int *a,int n) {
    //Declare local variable
    int kount=1,max=1;
    //loop and compare
    for (int i=1; i<n; i++) {
        if (*(a+(i-1)) == *(a+i)) {
            kount++;
            if (kount > max)
                max = kount;
        } else
            kount = 1;
    }
    return max;
}

void sort(int *a,int *b,int n) {
    for (int i=0; i<n; i++) {
        *(b+i)=*(a+i);
    }
    //Sort the copied array
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (*(b+i)>*(b+j)) {
                int temp = *(b+i);
                *(b+i) = *(b+j);
                *(b+j) = temp;
            }
        }
    }
}

void prntAry(int *a,int n,int perLine) {
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << *(a+i) << " ";
        if (i%perLine == (perLine-1))
            cout << endl;
    }
    cout << endl;
}

//Repetitive count with 1-digit elements
int *fillAry(int n) {
    int *a = new int[n];
    for (int i=0; i<n; i++) {
        *(a+i)=i%10;
    }
    return a;
}

void problem4(){
/* 
 * Author: David W. Smith
 * Created on April 26, 2014, 3:46 AM
 * Midterm CSC17A - Problem #4a. Encrypt 4-digit octal number
 */
    //Note: due to the encryption method used, only values between 0000-4444
    //inclusive can be successfully encrypted and decrypted.
    //Define local variables
    string usrInpt;
    //Since input can have leading zeroes, reading number in directly as an int
    //won't work. Need to read it in as a string of some sort, then check digits
    //and convert to int.
    cout << "Only numbers between 0000-4444 can successfully be encrypted"
         << " and decrypted," << endl;
    cout << "however this program will encrypt numbers between 0000-7777."
         << endl;
    cout << "Enter number to encrypt: ";
    cin.ignore();
    getline(cin,usrInpt);
    if (valOctl(usrInpt) != -1) {
       cout << "Encrypted value is (" << encrypt(valOctl(usrInpt)) << ")."
             << endl;
    } else
       cout << "Invalid input." << endl;
    //Exit, stage right!
    return;
}

int valOctl(string usrInpt) {
    //Accepts a string of exactly 4 characters & checks to see if they are valid
    //octal digits - if they are, return int equivalent of input string, else
    //return -1 indicating an error.
    //
    //Define local constant
    const int INPTLEN = 4;
    //Define local variables
    bool isValid = true;
    //Check to see if it has 4 characters
    if (usrInpt.length() != INPTLEN)
        isValid = false;
    //Check to see if it's an octal number
    for (int i=0; i < INPTLEN; i++) {
        if (!isdigit(usrInpt[i])||(((usrInpt[i]-'0')-7)>0))
            isValid = false;
    }
    //If it's O.K. - convert to integer & return else return -1
    if (isValid)
        return atoi(usrInpt.c_str());
    else
        return -1;
}

int encrypt(int normal) {
    //Define local constant
    const int INPTLEN = 4;
    //define local variables
    int tweaked = 0,digits[4],swap;
    //First, break the digits out individually
    for (int i=0; i<INPTLEN; i++){
        digits[i] = normal % 10;
        normal /= 10;
    }
    //Next, encode the digits individually
    for (int i=0; i<INPTLEN; i++){
        digits[i] = (digits[i] + 3) % 8;
    }
    //Then, swap the digits
    swap = digits[0];
    digits[0] = digits[1];
    digits[1] = swap;
    swap = digits[2];
    digits[2] = digits[3];
    digits[3] = swap;
    //Finally, put digits back together in reverse order
    for (int i=INPTLEN-1; i>=0; i--){
        tweaked = (tweaked * 10) + digits[i];
    }
    return tweaked;
}

void problem5(){
/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 26, 2014, 3:46 AM
 * Midterm CSC17A - Problem #4b. Decrypt 4-digit octal number
 */
    //Note: due to the encryption method used, only values between 0000-4444
    //inclusive can be successfully encrypted and decrypted.
    //Define local variables
    string usrInpt;
    //Since input can have leading zeroes, reading number in directly as an int
    //won't work. Need to read it in as a string of some sort, then check digits
    //and convert to int.
    cout << "This program will accept numbers between 0000 and 7777 as a valid"
         << " input," << endl;
    cout << "but only numbers between 3333 and 7777 can be successfully"
         << " decrypted." << endl;
    cout << "Enter number to decrypt: ";
    cin.ignore();
    getline(cin,usrInpt);
    if (valOctl(usrInpt) != -1) {
        cout << "Decrypted value is (" << decrypt(valOctl(usrInpt)) << ")."
             << endl;
    } 
    //Exit, stage right!
    return;
}

string decrypt(int tweaked) {
    //Define local constant
    const int INPTLEN = 4;
    //define local variables
    string normal = "";
    int digits[4],swap;
    bool isValid=true;
    //First, break the digits out individually
    for (int i=0; i<INPTLEN; i++){
        digits[i] = tweaked % 10;
        tweaked /= 10;
    }
    cout << endl;
    //Next, swap the digits
    swap = digits[0];
    digits[0] = digits[1];
    digits[1] = swap;
    swap = digits[2];
    digits[2] = digits[3];
    digits[3] = swap;
    //Next, decode the digits individually, error checking as we go
    for (int i=0; i<INPTLEN; i++){
        digits[i] = (digits[i] - 3);
        if (digits[i] < 0)
            isValid = false;
    }
    //Finally, put digits back together in reverse order (if you can...)
    if (isValid) {
        for (int i=INPTLEN-1; i>=0; i--){
            normal += digits[i]+'0';
        }
    } else
        normal = "Invalid result";
    return normal;
}

void problem6(){
    cout << "Fun with factorials!" << endl;
    cout << "--------------------" << endl;
    cout << "Byte = 5! = 120" << endl;
    cout << "Unsigned short = 8! = 40320" << endl;
    cout << "Short = 7! 5040" << endl;
    cout << "Unsigned int = 13! = 1932053504" << endl;
    cout << "Int = 13! = 1932053504" << endl;
    cout << "Unsigned long = 22! = 17196083355034583040" << endl;
    cout << "Long = 20! = 2432902008176640000" << endl;
    cout << "Float = 34! = 2.95233e+38" << endl;
    cout << "Double = 170! = 7.25742e+306" << endl;
    cout << "----------------------------" << endl;
}

void problem7(){
    cout << "Manual Mantissas - Floating point fun!" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Part (a):" << endl;
    cout << "2.125 = 10.001(binary) = 2.1(octal) = 2.2(hex)" << endl;
    cout << "0.06640625 = 0.00110011(binary) = 0.146(octal) = 0.11(hex)"<< endl;
    cout << "-2.125 = 88000080(hex)" << endl;
    cout << "0.06640625 = 0800007B(hex)" << endl;
    cout << "Part (b):" << endl;
    cout << "46666601 = 1.82e-38" << endl;
    cout << "46666602 = 3.64e-38" << endl;
    cout << "B9999AFE = -2.41e-38" << endl;
    cout << "---------------------" << endl;
}

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

