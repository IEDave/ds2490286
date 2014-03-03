/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 29, 2014, 2:15 AM
 * Midterm Problem #1 - ask user for number of lines to output,
 * then print a column of numbers, with each # indented row #
 * of spaces (e.g. col = row). 
 */
//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    int usrCnt;
    cout << "Enter the number of lines to output: ";
    cin >> usrCnt;
    if (usrCnt > 0) {
        for (int col = 1; col <= usrCnt; col++){
            for (int row = 1; row < col; row++)
                cout << " ";
            cout << col << endl;
        }
    } else
        cout << "Numbers less than 1 are not accepted. Sorry." << endl;
    //Exit, stage right.
    return 0;
}

