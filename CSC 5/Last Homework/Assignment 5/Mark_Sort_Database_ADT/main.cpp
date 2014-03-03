/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on February 11, 2014, 11:40 PM
 * Purpose: Convert Mark_Sort_Database to use an ADT
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
void filAray(AryStat &,AryStat &,int);
void prntAry(AryStat &,int);
void prntAry(AryStat &,AryStat &,int);
void swap(int &,int &);
void minPos(AryStat &,AryStat &,int);
void mrkSort(AryStat &, AryStat &);

//Executions Begin Here!
int main(int argc, char** argv) {
    //Declare variables and initialize the
    //random number generator
    AryStat array,irray;
    int sizUsed = 100;
    srand(static_cast<unsigned int>(time(0)));
    //Fill the arrays
    filAray(array,irray,sizUsed);
    //Print the array
    prntAry(array,irray,10);
    //Test out the min pos routine
    mrkSort(array,irray);
    //Print the array
    prntAry(array,irray,10);
    prntAry(irray,10);
    prntAry(array,10);
    //Exit Stage Right!!!
    return 0;
}

void mrkSort(AryStat &a, AryStat &i){
   for(int idx = 0; idx < a.sizeUtl-1; idx++){
        minPos(a,i,idx);
    }
}

void minPos(AryStat &a,AryStat &i,int pos){
    for(int idx = pos+1; idx < a.sizeUtl; idx++){
        if(a.data[i.data[pos]]>a.data[i.data[idx]])
            swap(i.data[pos],i.data[idx]);
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

void prntAry(AryStat &a,AryStat &i,int perLine){
    cout<<endl;
    for(int idx=0;idx<a.sizeUtl;idx++){
        cout<<a.data[i.data[idx]]<<" ";
        if(idx%10==(perLine-1))
            cout<<endl;
    }
    cout<<endl;
}

//2 Digit random numbers
void filAray(AryStat &a, AryStat &i,int n){
    //Validate array size
    if(n <= 1 || n > 10000) {
        a.sizeUtl=2;
        i.sizeUtl=2;
    }
    else {
        a.sizeUtl=n;
        i.sizeUtl=n;
    }
    //Fill array
    for(int idx=0;idx<a.sizeUtl;idx++){
        a.data[idx]=rand()%90+10;
        i.data[idx]=idx;
    }
}

