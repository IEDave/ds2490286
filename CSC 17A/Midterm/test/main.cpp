/* 
 * File:   main.cpp
 * Author: David
 *
 * Created on May 2, 2014, 2:25 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

void numWrds(int);

int main(int argc, char** argv) {
    for (int i = 0; i < 100000; i++) {
        numWrds(i);
        cout << endl;
        if (i%10==9) {
            cout << "Press <Enter> to continue...";
            cin.get();
        }
    }
    return 0;
}

void numWrds(int chkVal) {
    const char * const ones[20] = {"ZERO", "ONE", "TWO", "THREE","FOUR","FIVE",
    "SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN",
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