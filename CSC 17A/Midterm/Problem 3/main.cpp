/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on April 28th, 2014, 05:49 AM
 * Determine mode, median & mean of a set of numbers.
 * Based on example provided by Dr. Mark E. Lehr.
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Structures
struct statsResult {
    float avg;
    float median;
    int *mode;   //Array containing the modes
    int nModes;  //number of modes in the array
    int maxFreq; //max frequency of modes
};

//Function Prototypes
int *fillAry(int);
void prntAry(int *,int,int);
void sort(int *,int *,int);
int maxFreq(int *,int);
int nuMds(int *,int,int);
void filMdSt(int *, int *, int, int);
int *mode(int *,int);
float mean(int *,int);
float median(int *, int);
void printStat(int *,int);
void printStat(statsResult *,int);
statsResult *avgMedMode(int *,int);
void filMode(int *, int *, int, int);
void destroy(int *);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    //const int SIZE=100;
    int mFreq,nElem,size;
    statsResult *results;
    //Ask user for size of array
    cout << "How many elements in the array: ";
    cin >> size;
    //Create & populate an array
    int *array = fillAry(size);
    for (int i = 0; i < size; i++) {
        cout << "Value for array element #" << i << ":";
        cin >> array[i];
    }
    int *brray = fillAry(size);
    //Print array contents
    prntAry(array,size,10);
    //Sort array
    sort(array,brray,size);
    //Print sorted array
    prntAry(brray,size,10);
    cout << endl;
    //Generate mode set
    //int *srray = mode(brray,SIZE);
    results = avgMedMode(brray,size);
    //Print mode set
    //printStat(srray,10);
    printStat(results,10);
    //Delete dynamic arrays (prevents memory leaks))
    destroy(array);
    destroy(brray);
    //destroy(srray);
    destroy(results->mode);
    delete [] results;
    //Exit, stage right
    return 0;
}

float mean(int *a, int n) {
    //Define local variables
    float totSet = 0;
    for (int i=0; i<n; i++)
        totSet += static_cast<float>(*(a+i));
    return totSet/static_cast<float>(n);  
}

float median(int *a,int n) {
    if (n%2 == 1) {
       return static_cast<float>(*(a+((n/2)+1)));
    } else {
       return static_cast<float>((*(a+(n/2))+*(a+((n/2)+1))))/2.0;
    }
}

void printStat(statsResult *a,int perLine) {
    //Define local variables
    //Print contents of structure
    cout << "Average of set: " << a->avg << endl;
    cout << "Median of set: " << a->median << endl;
    cout << "Number of elements in mode set = " << a->nModes << endl;
    cout << "Max frequency = " << a->maxFreq << endl;
    if (a->nModes > 0) {
         //...print the actual mode set.
         cout << "Mode set = {";
         for (int i=0; i < (a->nModes-1); i++) {
             cout << a->mode[i] << ", ";
             if (i%perLine == (perLine-1))
                 cout << endl;
         }
         cout << a->mode[(a->nModes-1)] << "}." << endl;
    }
}

void printStat(int *a,int perLine) {
     //Define local variables
     int n = *(a)+2; //+2 to skip over the first 2 array elements
     //Print # of elements & max frequency first, then...
     cout << "Number of elements in mode set = " << *(a) << endl;
     cout << "Max frequency = " << *(a+1) << endl;
     if (*(a) > 0) {
         //...print the actual mode set.
         cout << "Mode set = {";
         for (int i=2; i<(n-1); i++) {
             cout << *(a+i) << ", ";
             if (i%perLine == (perLine-1))
                 cout << endl;
         }
         cout << *(a+(n-1)) << "}." << endl;
     }
}
 
 statsResult *avgMedMode(int *a, int n) {
     statsResult *s = new statsResult;
     s->avg = mean(a,n);
     s->median = median(a,n);
     s->maxFreq = maxFreq(a,n);
     s->nModes = nuMds(a,n,s->maxFreq);
     s->mode = fillAry(s->nModes);
     filMode(a,s->mode,n,s->maxFreq);
     return s;
 }
 
void filMode(int *a, int *mset, int n, int maxFreq) {
    //This function populates the mode array.
    //Declare local variable
    int kount=1, mdIndex=0;
    //loop and compare
    for (int i=1; i<n; i++) {
        if (*(a+(i-1)) == *(a+i)) {
            kount++;
            if (kount == maxFreq) {
                *(mset+mdIndex) = *(a+(i-1));
                mdIndex++;
            }
        } else
            kount = 1;
    }
}

int *mode(int *a, int n){
    //This is really just an amalgam of other function calls to conform to
    //assignment specifications.
    int mFreq = maxFreq(a,n);
    int nElem = nuMds(a,n,mFreq);
    int *s = fillAry(nElem+2);
    filMdSt(a, s, n, mFreq);
    return s;
}

void filMdSt(int *a, int *mset, int n, int maxFreq) {
    //This function (filMdSt = Fill Mode Set) populates the mode array.
    //Declare local variable
    int kount=1, mdIndex=2;
    //loop and compare
    for (int i=1; i<n; i++) {
        if (*(a+(i-1)) == *(a+i)) {
            kount++;
            if (kount == maxFreq) {
                *(mset+mdIndex) = *(a+(i-1));
                mdIndex++;
            }
        } else
            kount = 1;
    }
    *(mset+1) = maxFreq;
    *(mset) = mdIndex-2;
}

int nuMds(int *a, int n, int maxFreq) {
    //This function counts the number of elements that will be in the mode set.
    //Declare local variables
    int kount=1, numElem=0;
    //loop and compare
    for (int i=1; i<n; i++) {
        if (*(a+(i-1)) == *(a+i)) {
            kount++;
            if (kount == maxFreq)
                numElem++;
        } else
            kount = 1;
    }
    return numElem;
}

void destroy(int *a) {
    delete []a;
}

//Req. sorted array for input
int maxFreq(int *a,int n) {
    //Declare local variable
    int kount=1,max=1;
    //loop and compare
    for (int i=1; i<n; i++) {
        if (*(a+(i-1)) == *(a+i)) {
            kount++;
            if (kount > max)
                max = kount;
        } else
            kount = 1;
    }
    return max;
}

void sort(int *a,int *b,int n) {
    for (int i=0; i<n; i++) {
        *(b+i)=*(a+i);
    }
    //Sort the copied array
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (*(b+i)>*(b+j)) {
                int temp = *(b+i);
                *(b+i) = *(b+j);
                *(b+j) = temp;
            }
        }
    }
}

void prntAry(int *a,int n,int perLine) {
    cout << endl;
    for (int i=0; i<n; i++) {
        cout << *(a+i) << " ";
        if (i%perLine == (perLine-1))
            cout << endl;
    }
    cout << endl;
}

//Repetitive count with 1-digit elements
int *fillAry(int n) {
    int *a = new int[n];
    for (int i=0; i<n; i++) {
        *(a+i)=i%10;
    }
    return a;
}
