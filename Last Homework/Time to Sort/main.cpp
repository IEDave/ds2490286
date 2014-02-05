/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 4, 2014, 10:06 AM
 * Comparison of Bubble vs Selection sort.
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void filAray(int [],int);
void xcopy(const int [],int [],int);
void bblSort(int [],int);
void selSort(int [],int);

//Execution begins here
int main(int argc, char** argv) {
    //define local constants & variables, seed random number generator
    const int SIZE=120000;
    int array[SIZE],brray[SIZE],strTime,endTime;
    srand(static_cast<unsigned int>(time(0)));
    //Populate array with random numbers
    filAray(array,SIZE);
    //Create a working copy of initial array
    //Perform bubble sort, get time
    xcopy(array,brray,SIZE);
    strTime = time(0);
    bblSort(brray,SIZE);
    endTime = time(0);
    cout << "Time to perform Bubble sort " << SIZE << " elements is "
         << endTime - strTime << " seconds." << endl;
    //Perform Selection sort, get time
    xcopy(array,brray,SIZE);
    strTime = time(0);
    selSort(brray,SIZE);
    endTime = time(0);
    cout << "Time to perform Selection sort " << SIZE << " elements is "
         << endTime - strTime << " seconds." << endl;
    //Exit, stage right.
    return 0;
}

void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
}

void xcopy(const int a[],int b[],int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}

void bblSort(int array[],int size) {
    bool swap;
    int temp;
    
    do {
        swap = false;
        for (int count = 0; count < (size-1); count++) {
            if (array[count] > array[count + 1]) {
                temp = array[count];
                array[count] = array[count+1];
                array[count+1] = temp;
                swap = true;
            }
        }
    } while(swap);
    return;
}

void selSort(int array[],int size) {
    int strtScn, minIdx, minVal;
    
    for (strtScn = 0; strtScn < (size-1); strtScn++) {
        minIdx = strtScn;
        minVal = array[strtScn];
        for (int idx=strtScn+1;idx < size;idx++) {
            if (array[idx] < minVal) {
                minVal = array[idx];
                minIdx = idx;
            }
        }
        array[minIdx] = array[strtScn];
        array[strtScn] = minVal;
    }
    
    return;
}

