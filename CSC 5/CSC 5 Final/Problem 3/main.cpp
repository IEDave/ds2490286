/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 15, 2014, 1:34 PM
 * Final - Problem 3:
 * Create a function that fills one vector with even
 * random 2 digit numbers and another vector with
 * odd random numbers.  Prompt the user for the size
 * of these vectors.  Both will be the same size.
 * Output the results where you ask the user how
 * many columns to display.  These should be done
 * with 2 functions, fillVec and prntVec.
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
using namespace std;

//Global Constants

//Structures

//Function Prototypes
void fillVec(vector<unsigned short>&, vector<unsigned short>&, const int);
void prntVec(vector<unsigned short>&, vector<unsigned short>&, const int);

//Execution Begins here
int main(int argc, char** argv) {
    //Define local variables
    vector<unsigned short> eVec, oddVec;
    int iSize;
    
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Ask user for the size of the list
    cout << "Enter the number of elements to be put into the vectors:";
    cin >> iSize;
    //Fill vectors with requested # of elements
    fillVec(eVec,oddVec,iSize);
    //Ask user for # of columns to print
    cout << "Enter the number of columns to print:";
    cin >> iSize;
    //Print vectors with requested # of columns
    prntVec(eVec,oddVec,iSize);
    //Exit, stage right
    return 0;
}

void fillVec(vector<unsigned short> &a, vector<unsigned short> &b,
             const int elemnts) {
    //Define local variables
    unsigned short rndNum;
    
    //First, fill even numbered vector
    for (int i=0; i<elemnts; i++) {
        do {
            rndNum = rand()%90+10;
        } while (rndNum % 2);
        a.push_back(rndNum);
    }
    //Then, fill odd numbered vector
        for (int i=0; i<elemnts; i++) {
        do {
            rndNum = rand()%90+10;
        } while (!(rndNum % 2));
        b.push_back(rndNum);
    } 
}

void prntVec(vector<unsigned short>&a, vector<unsigned short>&b,
             const int cols) {
    //First, print even numbered vector contents, breaking every cols element
    for (int i=0; i<a.size(); i++) {
        cout << setw(3) << a[i];
        if (!((i+1) % (cols)))
            cout << endl;
    }
    cout << endl;
    //Then, print odd numbered vector contents, breaking every cols element
    for (int i=0; i < b.size(); i++) {
        cout << setw(3) << b[i];
            if (!((i+1) % (cols)))
                cout << endl;
    }
}