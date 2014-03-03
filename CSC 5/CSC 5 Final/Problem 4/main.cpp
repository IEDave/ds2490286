/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 15, 2014, 2:50 PM
 * Final - Problem 4:
 * Create a function/method/procedure that
 * returns a random number from the following set,
 * {9,51,79,182,251}.  Loop 10000 times with this 
 * procedure and print the frequency of each of 
 * the 5 numbers obtained.  Hint: Use an array for 
 * the sequence and frequency.  
 *
 *
 * The following is a brief hint on items that might 
 * be helpful in obtaining the results.  This is not 
 * direct code but more pseudo code related.  Don't 
 * try and run the following directly and more code 
 * will be needed.
 *
 *
 * Setup
 *         const int n=5,ntimes=10000;
 *         int freq[n]={0};
 *         short int rndseq[]={9,51,79,182,251};
 *
 *
 * Call to the routine to return a random sequence
 *        retrand(rndseq,freq,n,ntimes);
 *
 *
 * Results
 *         cout<<rndseq[i]<<" occured "<<
 *                 freq[i]<<" times"<<endl;
 *
 *
 * Sample Output
 *         9 occured 2055 times
 *         51 occured 1986 times
 *         79 occured 1962 times
 *         182 occured 2079 times
 *         251 occured 1919 times
 *
 *
 * Note:  Your results are not expected to be exactly
 * the same!  After all these are pseudo-random 
 * number sequences with different seeds.  
 */

//System Variables
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Structures

//Function Prototypes
void retrand(short int [], int [],const int,const int);
short int fndRnd(short int [], const int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    const int n = 5, ntimes = 10000;
    int freq[n] = {0};
    short int rndseq[] = {9, 51, 79, 182, 251};
    
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Call routine to generate random sequence
    retrand(rndseq,freq,n,ntimes);
    //Print results
    for (int i=0; i<n; i++) {
         cout << rndseq[i] << " occurred " <<
         freq[i] << " times." << endl;
    }
    //Exit, stage right
    return 0;
}

void retrand(short int values[], int freqs[],const int n,const int nTimes){
    for (int i = 0; i < nTimes; i++) {
        freqs[fndRnd(values,n)]++;
    }
}

short int fndRnd(short int values[], const int n) {
    //define local variables
    bool isFnd = false;
    short int value, i;
    //Crank out random numbers until one is found in the list.
    do {
        value = rand() % 255;
        for (i = 0; i < n; i++) {
            if (value == values[i]) {
                isFnd = true;
                break;
            }
        }
    } while(!isFnd);
    return i;
}