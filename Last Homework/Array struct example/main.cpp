/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 10, 2014, 8:52 AM
 * Example of static & dynamic structures
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//Global Constants
const int SIZE=100;

//Structures - static & dynamic arrays
struct AryStat {
    int data[SIZE];
    int sizeUtl;
};
struct AryDyn {
    int *data;
    int size;
};

//Function Prototypes
void fillAry(AryStat &,int);
AryDyn *fillAry(int);
void prntAry(const AryStat &,int);
void prntAry(const AryDyn *,int);
void reclaim(AryDyn *);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables & set random number generator
    AryStat aStat;
    int sizUtil=100;
    srand(static_cast<unsigned int>(time(0)));
    //fill array
    fillAry(aStat,sizUtil);
    AryDyn *aDyn=fillAry(sizUtil);
    //print array
    prntAry(aStat,10);
    prntAry(aDyn,10);
    //Delete allocated memory
    reclaim(aDyn);
    //Exit, stage right.
    return 0;
}

//Reclaim memory
void reclaim(AryDyn *a) {
    //Array first...
    delete []a->data;
    //then struct...
    delete a;
}

void prntAry(const AryDyn *a,int perLine){
    //Print array
    cout << endl;
    for(int i=0; i<a->size; i++) {
        cout << setw(4) << a->data[i];
        if ((i%perLine)==(perLine-1)) {
            cout << endl;
        }
    }
    
}

void prntAry(const AryStat &a,int perLine){
    //Print array
    cout << endl;
    for(int i=0; i<a.sizeUtl; i++) {
        cout << setw(4) << a.data[i];
        if ((i%perLine)==(perLine-1)) {
            cout << endl;
        }
    }
}

//Fill the dynamic array
AryDyn *fillAry(int us){
    //Allocate memory
    AryDyn *a=new AryDyn;
    if(us<=1||us>SIZE)
        us=2;
    //Allocate memory for array
    a->size=us;
    //(*aDyn).size=us;
    a->data=new int[a->size];
    //Fill the array
    for(int i=0; i<a->size;i++) {
        //(*a).data[i]=rand()%900+100;
        //*(a->data+i)=rand()%900+100;
        //*((*a).data+i)=rand()%900+100;
        a->data[i]=rand()%900+100; //3 digit number
    }
    return a;
}

void fillAry(AryStat &a,int us){
    //Validate size of array
    if(us<=1||us>10000)a.sizeUtl=2;
    else a.sizeUtl=us;
    //Fill the array
    for(int i=0; i<a.sizeUtl;i++)
        a.data[i]=rand()%900+100; //3 digit number
}

