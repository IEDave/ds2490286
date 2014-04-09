/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 7, 2014, 3:22 PM
 * Gaddis, 7th Edition - Chapter 10, Problem 3
 * Write a function that accepts a pointer to a C-String & returns an integer.
 * The integer returned should be the word count of the string. Write a program
 * to demonstrate that the function works.
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//Global constants

//Function Prototypes
int cStrWc(const char *);

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
    cout << "The number of words in your string is (" << cStrWc(uStr) << ")."
         << endl;
    //Exit, stage right!
    return 0;
}

int cStrWc(const char *ptr) {
    //Define local variables
    int cnt = 0, wc = 0;
    bool isWs = false, isAsc = false;
    //Strip out leading spaces
    while (*(ptr+cnt)!= '\0' && (*(ptr+cnt)== ' ' || *(ptr+cnt)== '\t')){
        cnt++;
    }
    //At a non-whitespace char...scan for non-whitespace/whitespace transition
    //and increment word count when found.
    while (*(ptr+cnt)!= '\0'){
        isAsc = (*(ptr+cnt)!= ' ' && *(ptr+cnt)!= '\t');
        isWs = (*(ptr+cnt+1)== ' ' || *(ptr+cnt+1)== '\t' ||
                *(ptr+cnt+1) == '\0');
        if (isAsc && isWs) {
            wc++;
        }
        cnt++;
    }
    return wc;
}
