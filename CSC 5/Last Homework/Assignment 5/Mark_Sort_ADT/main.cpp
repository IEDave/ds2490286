/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 11, 2014, 10:24 PM
 * Purpose: Convert Mark_Sort to use ADT
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants
const int SIZE=200;

//Structures - static array
struct AryStat {
    int data[SIZE];
    int sizeUtl;
};

//Function Prototypes
void filAray(AryStat &,int);
void prntAry(AryStat &,int);
void swap(int &,int &);
void minPos(AryStat &,int);
void mrkSort(AryStat &);
void xcopy(AryStat &,AryStat &);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Declare variables and initialize the
    //random number generator
    AryStat array,brray;
    int sizUsed = 100;
    srand(static_cast<unsigned int>(time(0)));
    //Fill the arrays
    filAray(array,sizUsed);
    xcopy(array,brray);
    //Print the array
    prntAry(array,10);
    //Test out the min pos routine
    mrkSort(brray);
    //Print the array
    prntAry(brray,10);
    //Exit Stage Right!!!
    return 0;
}

void xcopy(AryStat &a,AryStat &b){
    for(int i = 0; i < a.sizeUtl; i++){
        b.data[i] = a.data[i];
    }
    b.sizeUtl = a.sizeUtl;
}

void mrkSort(AryStat &a){
   for(int i = 0; i < a.sizeUtl-1; i++){
        minPos(a,i);
    }
}

void minPos(AryStat &a,int pos){
    for(int i = pos+1; i < a.sizeUtl; i++){
        if(a.data[pos]>a.data[i])
            swap(a.data[pos],a.data[i]);
        //if(a[pos]>a[i])swap(a,pos,i);
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void prntAry(AryStat &a,int perLine){
    cout<<endl;
    for(int i=0;i<a.sizeUtl;i++){
        cout<<a.data[i]<<" ";
        if(i%10==(perLine-1))
            cout<<endl;
    }
    cout<<endl;
}

//2 Digit random numbers
void filAray(AryStat &a, int n){
    //Validate array size
    if(n <= 1 || n > 10000)
        a.sizeUtl=2;
    else
        a.sizeUtl=n;
    //Fill array
    for(int i=0;i<a.sizeUtl;i++){
        a.data[i]=rand()%90+10;
    }
}

