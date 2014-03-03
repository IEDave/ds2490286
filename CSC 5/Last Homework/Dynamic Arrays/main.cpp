/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on August 20, 2013, 2:45 PM
 * Array & Pointer
 */
//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
int *filAray(int);
void prntAry(int *, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Decl var
    int size;
    //Seed random number generator
    srand(static_cast<int>(time(0)));
    //Ask user for size of array
    cout << "How big?";
    cin >> size;
    //Dynamically allocate array
    int *array = filAray(size);
    //Display array contents
    prntAry(array,size,10);
    //Free up memory before exit
    delete []array;
    //Exit, stage right.
    return 0;
}

void prntAry(int *a, int n, int perLine) {
    //Print array contents, 10 numbers per line
    cout <<endl;
    for (int i=0; i<n-1; i++) {
        cout << *(a+i) << " ";
        if ((i%perLine) == (perLine-1))
                cout << endl;
    }
}
    
int *filAray(int n) {
    //Create a new array & fill it with random 2-digit numbers
    int *array=new int[n];
    for (int i=0; i<n ; i++) {
        *(array+i)=rand()%90+10;
    }
    return array;
}