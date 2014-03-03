/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 11, 2014, 7:43 AM
 * 2 dimensional array structures
 */
//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//Global Constants
const int SIZE=500,ROWS=500,COLS=500;

//Structures - static & dynamic arrays
struct AryStat {
    int data[ROWS][COLS];
    int rowsUtl;
    int colsUtl;
};
struct AryDyn {
    int **data;
    int rowsUtl;
    int colsUtl;
};

//Function Prototypes
void fillAry(AryStat &,int, int);
AryDyn *fillAry(int,int);
void prntAry(const AryStat &);
void prntAry(const AryDyn *);
void reclaim(AryDyn *);

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables & set random number generator
    AryStat aStat;
    int rowUtil = 10;
    int colUtil = 10;
    srand(static_cast<unsigned int>(time(0)));
    //fill array
    fillAry(aStat,row);
    AryDyn *aDyn=fillAry(rowUtil,colUtil);
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
    for(int row=0; row<a->rowsUtl; row++) {
       for(int col=0; col<a->colsUtl; col++) {
           cout << setw(4) << a->data[row][col];
       }
       cout << endl;
    }
}

void prntAry(const AryStat &a){
    //Print array
    cout << endl;
    for(int row=0; row<a.rowsUtl; row++) {
       for(int col=0; col<a.colsUtl; col++) {
           cout << setw(4) << a.data[row][col];
       }
       cout << endl;
    }
}

//Fill the dynamic array
AryDyn *fillAry(int rows, int cols){
    //Allocate memory for struct
    AryDyn *a=new AryDyn;
    //Validate size of array
    if(rows<=1||rows>ROWS)
        a->rowsUtl=2;
    else
        a->rowsUtl=rows;
    if(cols<=1||cols>COLS)
        a->colsUtl=2;
    else
        a->colsUtl=rows;
    //Allocate memory for array
    //a->size=us;
    //(*aDyn).size=us;
    a->data=new int[a->rowsUtl];
    //Fill the array
    for(int row=0; row<a->rowsUtl; row++) {
       for(int col=0; col<a->colsUtl; col++) {
        //(*a).data[i]=rand()%900+100;
        //*(a->data+i)=rand()%900+100;
        //*((*a).data+i)=rand()%900+100;
        a->data[row][col]=rand()%900+100; //3 digit number
    }
    return a;
}

void fillAry(AryStat &a,int rows,int cols){
    //Validate size of array
    if(rows<=1||rows>ROWS)
        a.rowsUtl=2;
    else
        a.rowsUtl=rows;
    if(cols<=1||cols>COLS)
        a.colsUtl=2;
    else
        a.colsUtl=rows;
    //Fill the array
    for(int row=0; row<a.rowsUtl; row++) {
       for(int col=0; col<a.colsUtl; col++) {
           a.data[row][col]=rand()%900+100; //3 digit number
       }
    }
}

