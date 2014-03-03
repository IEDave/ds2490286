/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr - modified by David W. Smith
 * Created on January 30, 2014, 10:31 AM
 * Modify Search With a Vector to search array contents
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void filAray(int [],int);
void nilAray(int [],int);
void srchAry(int [],int);
void prntAry(const int [],int,int);
void prntVec(const vector<int>&,int);
int  find(const int [],int,int,int);
void find(const int [],int,int,vector<int> &);
void find(const int [],int,int,int []);
void fndMult(int [], const int, const int [],int, int[],vector<int> &);

int main(int argc, char** argv) {
    //Declare and setup the problem
    const int SIZE=100,SRCHSZ=4;
    int array[SIZE];
    int brray[SIZE];
    int srch[SIZE];
    vector<int> posVec;
    int val1 = 20, val2 = 42;
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Initialize the arrays
    srchAry(srch,SIZE);
    filAray(array,SIZE);
    nilAray(brray,SIZE);
    //Display the array
    prntAry(array,SIZE,10);
    //Find values in the search array
    fndMult(srch,SRCHSZ,array,SIZE,brray,posVec);
    //Print array
    prntAry(brray,SIZE,10);
    //Print the vector
    prntVec(posVec,10);
    //Exit Stage RIGHT!!!
    return 0;
}

void fndMult (int srchAry[], int srchsz, const int array[],int n, int array2[],
              vector<int>&vec){
    //define local variable
    int pos;
    //Main processing loop for array values
    for (int cnt = 0; cnt < srchsz; cnt++) {
       pos = -1;
       do{
           pos=find(array,n,srchAry[cnt],pos+1);
           cout<<"Value found at "<<pos<<endl;
       }while(pos>0);
       find(array,n,srchAry[cnt],array2);
       find(array,n,srchAry[cnt],vec);
    }
    
    return;
}

void prntVec(const vector<int>&vec,int perLine){
    cout<<endl;
    cout<<"Found "<<vec.size()<<" values!"<<endl;
    cout<<"Position Vector where found = { ";
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<"}"<<endl;
    
    return;
}

void find(const int a[],int n,int val,int b[]){
    int cnt=0;
    //find first -1 in b array
    do {
        if (b[cnt] != -1)
            cnt++;
    }while(b[cnt]!=-1);
    //Now, populate b array
    for(int i=0;i<n;i++){
        if(a[i]==val)
            b[cnt++]=i;
    }
    
    return;
}

void find(const int a[],int n,int val,vector<int> &vec){
    for(int i=0;i<n;i++){
        if(a[i]==val)vec.push_back(i);
    }
    
    return;
}

int  find(const int a[],int n,int val,int pStrt){
    for(int i=pStrt;i<n;i++){
        if(a[i]==val)return i;
    }
    
    return -1;
}

//Fill the array with 2 digit numbers
void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
    }
    
    return;
}

//Initialize array with -1's
void nilAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=-1;
    }
    
    return;
}

//Init search array with numbers to find
void srchAry(int a[],int n){
    //First, init with -1s
    nilAray(a,n);
    //Then, populate with items to search
    a[0] = 20;
    a[1] = 81;
    a[2] = 42;
    a[3] = 69;
    
    return;
}

//Print the array with perLine elements on a line
void prntAry(const int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
    
    return;
}
