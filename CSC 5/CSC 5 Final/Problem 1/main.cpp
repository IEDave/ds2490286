/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 15, 2014, 1:44 AM
 * Final - Problem 1:
 * Write a function that takes an unsigned
 * short integer and returns an unsigned short
 * number in reverse.  For instance 106 
 * reversed would be 601.  Another would be 
 * 30000 gives 3.  Check to make sure the 
 * conversion falls within the range for an 
 * unsigned short. If it doesn't then output
 * no conversion possible.
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Structures

//Function Prototypes
unsigned short revShrt(unsigned short, const int, bool &);

//Execution begins here
int main(int argc, char** argv) {
    //Declare local variables
    string iLine;
    int num=0,factor,iLen;
    unsigned short result;
    bool isNum;
    //Ask user for input
    cout << "Enter a number between 0 and 65535: ";
    getline(cin,iLine);
    iLen = iLine.size();
    //Check to see if it's a valid input before passing to conversion function.
    if (iLen <= 5) {
        for (int i=0; i <= iLen-1; i++){
            if (iLine[i] >= '0' && iLine[i] <= '9') {
                switch (iLen-i){
                    case 1:
                        factor = 1;
                        break;
                    case 2:
                        factor = 10;
                        break;
                    case 3:
                        factor = 100;
                        break;
                    case 4:
                        factor = 1000;
                        break;
                    case 5:
                        factor = 10000;
                        break;
                }
                num += (iLine[i]-'0')*factor;
                isNum = true;
            }
            else {
                isNum = false;
                break;
            }
        }
        //If it makes the cut - pass it to conversion function. If it didn't,
        //flag it as invalid & end program.
        if (isNum && (num>= 0 && num <= 65535)) {
            result = revShrt(static_cast<unsigned short> (num),iLen,isNum);
            if (isNum)
                cout << "Reversed " << num << " is " << result << "." << endl;
            else
                cout << "Conversion not possible.";
        } else {
            cout << "Conversion not possible." << endl;
        }
    } else {
        cout << "Conversion not possible." << endl;
    }
    //Exit,stage right
    return 0;
}

unsigned short revShrt(unsigned short num, const int len, bool &isNum) {
    //Define local variables
    int digit;
    int result = 0,factor;
    //pop off least significant digits & multiply them by factors in
    //reverse order to convert them to a reverse-order number. Has to
    //be done as an int because of the possibility of an overflow of a
    //unsigned short.
    for (int i = len; i >= 1; i--){
        digit = num % 10;
        num /= 10;
        switch(i){
            case 1:
                factor = 1;
                break;
            case 2:
                factor = 10;
                break;
            case 3:
                factor = 100;
                break;
            case 4:
                factor = 1000;
                break;
            case 5:
                factor = 10000;
                break;
        }
        result += digit*factor;
    }
    //If the result is valid, return it - otherwise set the boolean flag to
    //indicate unsuccessful conversion and return 0;
    if (result >= 0 && result <=65535)
        return static_cast<unsigned short> (result);
    else {
        isNum = false;
        return 0;
    }
}
