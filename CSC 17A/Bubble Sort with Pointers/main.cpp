/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 19, 2014, 1:50 PM
 * Homework #1 - Bubble Sort with Pointers, and Binary Search too!
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Structures

//Function Prototypes
int *fillAry(int);
void prtAry(int *,int,int);
void bblSort(int *,int);
int binSrch(int *,int,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables & constants
    int NUM = 100, NUM_COLS = 10, FIND_IT = 50;
    int *array;
    //Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Create array with random elements
    array = fillAry(NUM);
    //Print array
    prtAry(array,NUM,NUM_COLS);
    //Sort using Bubble Sort
    bblSort(array,NUM);
    //Print sorted array
    prtAry(array,NUM,NUM_COLS);
    //Search for element in sorted array
    binSrch(array,NUM,FIND_IT);
    //Release array memory back to system
    delete []array;
    //Exit, stage right.
    return 0;
}
int binSrch(int *a,int n,int findIt) {
    //Define local variables
    int min=0, max=n;
    do {
        
    } while (min < max);
}

void bblSort(int *array,int size) {
    //Define local variables
    bool swap;
    int temp;
    //Perform bubble sort
    do {
        swap = false; //If there were no swaps, you're done.
        //Repeatedly pass through array, swapping elements over & over
        //until all elements are swapped into ascending order.
        for (int count = 0; count < (size-1); count++) {
            if (*(array + count) > *(array + count + 1)) {
                temp = *(array + count);
                *(array + count) = *(array + count + 1);
                *(array + count + 1) = temp;
                swap = true;
            }
        }
    } while(swap);
    return;
}

int *fillAry(int elemnts){
    //Create array & assign address to variable
    int *aray=new int[elemnts];
    //Fill array with random 2-digit numbers
    for(int i = 0; i < elemnts; i++) {
        *(aray+i) = rand() % 90 + 10;
    }
    //pass pointer back to calling program
    return aray;
}

void prtAry(int *a,int elemnts,int brkOn){
    cout << endl;
    for(int i = 0; i < elemnts; i++){
        cout << setw(3) << *(a + i);
        if((i % 10) == (brkOn - 1))
            cout << endl;
    }
    cout << endl;
}