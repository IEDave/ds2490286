/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 26, 2014, 3:46 AM
 * Midterm CSC17A - Problem #4b. Decrypt 4-digit octal number
 * 
 */

//System Libraries
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
string decrypt(int);
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
    cout << "This program will accept numbers between 0000 and 7777 as a valid"
         << " input," << endl;
    cout << "but only numbers between 3333 and 7777 can be successfully"
         << " decrypted." << endl;
    cout << "Enter number to decrypt: ";
    getline(cin,usrInpt);
    if (valOctl(usrInpt) != -1) {
        cout << "Decrypted value is (" << decrypt(valOctl(usrInpt)) << ")."
             << endl;
    } 
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

