//Dr. Mark E. Lehr
//January 14th, 2014
//Menu to be used for the midterm
//homework and final, etc....

//Library includes Here!!!
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants Here!!!
const int SIZE=200; //used for problem #4 & #5

//Structures Here!!!
struct AryStat {
    int data[SIZE];
    int sizeUtl;
};

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
//Problem 1 functions
int *filAray(int);
void prntAry(const int*,int,int);
void swap(int &,int &);
void swap(int*,int,int);
void minPos(int*,int,int);
void mrkSort(int*,int);
void xcopy(const int*,int*,int);
//Problem 2 functions
void filAray(int *,int *,int);
void prntAry(int *,int *,int,int);
void prntAry(int *,int,int);
void minPos(int *, int *,int,int);
void mrkSort(int *,int *,int);
//Problem 3 functions
void filAray(int [],int);
void bblSort(int [],int);
void selSort(int [],int);
//Problem 4 functions
void filAray(AryStat &,int);
void prntAry(AryStat &,int);
void minPos(AryStat &,int);
void mrkSort(AryStat &);
void xcopy(AryStat &,AryStat &);
//Problem 5 functions
void filAray(AryStat &,AryStat &,int);
void prntAry(AryStat &,AryStat &,int);
void minPos(AryStat &,AryStat &,int);
void mrkSort(AryStat &, AryStat &);

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
}

void Menu(){
    cout<<"Menu for Assignment 5"<<endl;
    cout<<"====================="<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

int getN(){
        int inN;
        cin>>inN;
        return inN;
}

void problem1(){
/* 
 * Author: David W. Smith - based on in-class presentation by
 *         Dr. Mark E. Lehr
 * Created on February 3, 2014, 8:13 AM
 * Implementation of Mark Sort involving pointer notation
 */
    //Declare variables and initialize the
    //random number generator
    const int SIZE=200;
    //int array[SIZE], brray[SIZE];
    int *array, *brray;
    srand(static_cast<unsigned int>(time(0)));
    //Fill the arrays
    array = filAray(SIZE);
    brray = filAray(SIZE);
    xcopy(array,brray,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //Test out the min pos routine
    mrkSort(brray,SIZE);
    //Print the array
    prntAry(brray,SIZE,10);
    delete []array;
    delete []brray;
    //Exit Stage Right!!!
    return;
}

void xcopy(const int *a,int *b,int n){
    for(int i=0;i<n;i++){
        *(b+i) = *(a+i);
    }
}

void mrkSort(int *a,int n){
    for(int i=0;i<n-1;i++){
        minPos(a,n,i);
    }
}

void minPos(int *a,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(*(a+pos)>*(a+i))
            swap(*(a+pos),*(a+i));
        //if(a[pos]>a[i])swap(a,pos,i);
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void swap(int *a,int i,int j){
    int temp=*(a+i);
    *(a+i)=*(a+j);
    *(a+j)=temp;
}

void prntAry(const int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%10==(perLine-1))
            cout<<endl;
    }
    cout<<endl;
}

//2 Digit random numbers
int *filAray(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++)
        *(array+i)=rand()%90+10;
    return array;
}

void problem2(){
/* 
 * Author: David W. Smith - based on presentation by 
 *         Dr. Mark E. Lehr
 * Created on February 3, 2014, 8:13 AM
 * Purpose: Database sort implemented using pointer notation.
 */
    //Declare variables and initialize the
    //random number generator
    const int SIZE=200;
    int *array=new int[SIZE], *index=new int[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    //Fill the arrays
    filAray(array,index,SIZE);
    //Print the arrays
    prntAry(array,index,SIZE,10);
    //Test out the min pos routine
    mrkSort(array,index,SIZE);
    //Print the array
    prntAry(array,index,SIZE,10);
    prntAry(index,SIZE,10);
    prntAry(array,SIZE,10);
    //Exit Stage Right!!!
    return;
}

void mrkSort(int *a,int *indx,int n){
    for(int i=0;i<n-1;i++){
        minPos(a,indx,n,i);
    }
}

void minPos(int *a,int *indx,int n,int pos){
    for(int i=pos+1;i<n;i++){
        if (*(a+(*(indx+pos))) > *(a+(*(indx+i)))) {
                swap(*(indx+pos),*(indx+i));
        }
    }
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+i)<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void prntAry(int a[],int indx[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<*(a+(*(indx+i)))<<" ";
        if(i%10==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//2 Digit random numbers
void filAray(int *a,int *indx,int n){
    for(int i=0;i<n;i++){
        *(a+i)=rand()%90+10;
        *(indx+i)=i;
    }
}

void problem3(){
/*
 * Author: David W. Smith
 * Created on February 4, 2014, 10:06 AM
 * Comparison of Bubble vs Selection sort.
 */
    //define local constants & variables, seed random number generator
    const int MAX_SIZE = 100000, ARY_SIZE = MAX_SIZE+1, MIN_SIZE = 10000,
              INT_SIZE = 10000;
    int array[ARY_SIZE],brray[ARY_SIZE],strTime,endTime,size;
    srand(static_cast<unsigned int>(time(0)));
    for (size = MIN_SIZE; size <= MAX_SIZE; size += INT_SIZE) {
        //Populate array with random numbers
        filAray(array,size);
        //Create a working copy of initial array
        //Perform bubble sort, get time
        xcopy(array,brray,size);
        strTime = time(0);
        bblSort(brray,size);
        endTime = time(0);
        cout << "Time to perform Bubble sort " << size << " elements is "
             << endTime - strTime << " seconds." << endl;
        //Perform Selection sort, get time
        xcopy(array,brray,size);
        strTime = time(0);
        selSort(brray,size);
        endTime = time(0);
        cout << "Time to perform Selection sort " << size << " elements is "
             << endTime - strTime << " seconds." << endl;
    }
    //Exit, stage right.
    return;
}

void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%90+10;
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

void problem4(){
/* 
 * Author: David W. Smith
 * Created on February 11, 2014, 10:24 PM
 * Purpose: Convert Mark_Sort to use ADT
 */
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
    return;
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

void problem5(){
/* 
 * Author: David Smith
 * Created on February 11, 2014, 11:40 PM
 * Purpose: Convert Mark_Sort_Database to use an ADT
 */
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
    return;
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

void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}