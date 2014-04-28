/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 26, 2014, 3:46 AM
 * Midterm CSC17A - Problem #4a. Encrypt 4-digit octal number
 * 
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
int encrypt(int);
int valOctl(string);

//Execution begins here
int main(int argc, char** argv) {
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
    getline(cin,usrInpt);
    if (valOctl(usrInpt) != -1) {
       cout << "Encrypted value is (" << encrypt(valOctl(usrInpt)) << ")."
             << endl;
    } else
       cout << "Invalid input." << endl;
    //Exit, stage right!
    return 0;
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
    