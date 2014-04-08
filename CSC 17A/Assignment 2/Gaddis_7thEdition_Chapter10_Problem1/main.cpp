/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 7, 2014, 2:42 PM
 * Gaddis, 7th Edition - Chapter 10, Problem 1
 * Write a function that accepts a pointer to a C-String & returns an integer.
 * The integer returned should be the length of the string. Write a program to
 * demonstrate that the function works.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Global constants

//Function Prototypes
int cStrLen(const char *);

//Execution Begins Here
int main(int argc, char** argv) {
    //Define local constants
    const int SIZE=255;
    //Define local variable
    char uStr[SIZE];
    //Safeguard - initialize string with null terminators.
    for (int i=0; i<SIZE; i++)
        uStr[i] = '\0';
    //Get user input
    cout << "Enter a string: ";
    cin.getline(uStr,SIZE);
    //Call function & display result
    cout << "The length of the string you entered is (" << cStrLen(uStr)
         << ")." << endl;
    //Exit, stage right!
    return 0;
}

int cStrLen(const char *ptr) {
    //Define local variable
    int cnt = 0;
    while(*(ptr+cnt)!= '\0'){
        cnt++;
    }
    return cnt;
}

