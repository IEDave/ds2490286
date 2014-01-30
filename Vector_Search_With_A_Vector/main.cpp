/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr - modified by David W. Smith
 * Created on January 30, 2014, 10:59 AM
 * Modify Search With a Vector to search vector contents
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
void srchAry(vector<int>&);
void prntAry(const int [],int,int);
void prntVec(const vector<int>&,int);
int  find(const int [],int,int,int);
void find(const int [],int,int,vector<int> &);
void find(const int [],int,int,int []);
void fndMult(const vector<int> &, const int [],int, int[],vector<int> &);

int main(int argc, char** argv) {
    //Declare and setup the problem
    const int SIZE=100;
    int array[SIZE];
    int brray[SIZE];
    vector<int> srch;
    vector<int> posVec;
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Initialize the arrays
    srchAry(srch);
    filAray(array,SIZE);
    nilAray(brray,SIZE);
    //Display the array
    prntAry(array,SIZE,10);
    //Find the values in the search vector
    fndMult(srch,array,SIZE,brray,posVec);
    //Print array
    prntAry(brray,SIZE,10);
    //Print the vector
    prntVec(posVec,10);
    //Exit Stage RIGHT!!!
    return 0;
}

void fndMult (const vector<int>&srchAry, const int array[],int n, int array2[],
              vector<int>&vec){
    //define local variable
    int pos;
    //Main processing loop for array values
    for (int cnt = 0; cnt < srchAry.size(); cnt++) {
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
void srchAry(vector<int> &a){
    //Populate with items to search
    a.push_back(20);
    a.push_back(81);
    a.push_back(42);
    a.push_back(69);
    
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
