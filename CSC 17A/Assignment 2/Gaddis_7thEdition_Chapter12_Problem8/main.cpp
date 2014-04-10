/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 8, 2014, 4:48 PM
 * Gaddis, 7th Edition - Chapter 12, Problem 8
 * Array/File Functions: Write 2 functions; one to write the contents of an
 * array of integers out to a binary file, and one to read the contents of a
 * binary file into an array of integers. Both functions should accept 3
 * arguments: the file name, a pointer to an integer array, and the size of the
 * array. Write a calling program that generates the initial array, prints the
 * contents of the array, calls the functions to write the array out to a file
 * and read the array back in, and finishes by printing the contents of the
 * integer array read back in.
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
using namespace std;

//Global Constants

//Function Prototypes
void mkArray(int *,int);
void ptArray(int *,int,int);
void arrayToFile(const char *,int *,int);
void fileToArray(const char *,int *,int);
bool cmpAray(int *,int *,int);

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants
    const int SIZE = 100;
    //Define local variables
    int array[SIZE], brray[SIZE];
    //Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Populate integer array with random 2-digit numbers
    mkArray(array,SIZE);
    //Print array contents
    cout << "Initial array:" << endl;
    ptArray(array,SIZE,10);
    //Write array out to file
    arrayToFile("test.bin",array,SIZE);
    //Read array from file
    fileToArray("test.bin",brray,SIZE);
    //Compare array contents to see if they are the same
    if (cmpAray(array,brray,SIZE)) {
        cout << "Array contents differ." << endl;
    } else {
        cout << "Array contents are equal." << endl;
    }
    //Print array contents
    ptArray(brray,SIZE,10);
    //Exit, stage right!
    return 0;
}

//Compare 2 arrays - return false if equal, true if not.
bool cmpAray(int *nums1,int *nums2, int sz) {
    //Define local variable
    bool isDiff = false;
    //Loop through both arrays; if a[i] <> b[i] at any point, set flag to
    //indicate a problem.
    for (int i=0; i<sz; i++) {
        if (nums1[i] != nums2[i])
            isDiff = true;
    }
    return isDiff;  
}

//Fill array with random 2-digit integers
void mkArray(int *nums,int sz) {
    for(int i=0; i<sz; i++)
        nums[i] = rand()%90+10;
}

//Print contents of array, breaking at brkOn intervals.
void ptArray(int *nums,int sz,int brkOn) {
    for(int i=0; i<sz; i++){
        cout << nums[i] << " ";
        if(i%brkOn == (brkOn-1))
            cout << endl;
    }
    cout << endl;
    return;
}

//Write array contents to file
void arrayToFile(const char *fname,int *nums,int sz) {
    //Define local variables
    fstream file;
    file.open(fname,ios::out|ios::binary);
    if (!file.fail()) {
        file.write(reinterpret_cast<char *>(nums),sz*sizeof(int));
    } else {
        cout << "Unable to open file." << endl;
    }
    file.close();
}

//Read array contents to file
void fileToArray(const char *fname,int *nums,int sz) {
    //Define local variables
    fstream file;
    file.open(fname,ios::in|ios::binary);
    if (!file.fail()) {
        file.read(reinterpret_cast<char *>(nums),sz*sizeof(int));
    } else {
        cout << "Unable to open file." << endl;
    }
    file.close();
}