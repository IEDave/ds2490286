/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 7, 2014, 3:08 PM
 * Gaddis, 7th Edition - Chapter 10, Problem 
 * Write a function that accepts a pointer to a C-String & prints the string
 * in reverse. Write a program to demonstrate that the function works.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Global constants

//Function Prototypes
void cStrRev(const char *);

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
    cout << "Your string in reverse is: ";
    cStrRev(uStr);
    cout << endl;
    //Exit, stage right!
    return 0;
}

void cStrRev(const char *ptr) {
    //Define local variable
    int cnt = 0;
    //Get count
    while(*(ptr+cnt)!= '\0'){
        cnt++;
    }
    //Display string in reverse
    for (int i=cnt; i>=0; i--)
        cout << *(ptr+i);
}