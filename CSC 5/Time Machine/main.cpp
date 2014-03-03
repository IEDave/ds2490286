/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 23, 2014, 8:45 AM
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Global constants
const unsigned char CNV_MIN_HRS = 60;
const unsigned char CNV_24HR = 12;

//Function Prototypes
void read(unsigned short &,unsigned short &,char &);
unsigned short minutes(unsigned short,unsigned short,char);
unsigned short diff(unsigned short,unsigned short);

int main(int argc, char** argv) {
    unsigned short shr,ehr,smin,emin,scmin,ecmin;
    char sampm,eampm;
    //Read in start & end times
    read(shr,smin,sampm);
    read(ehr,emin,eampm);
    //Convert to minutes
    scmin=minutes(shr,smin,sampm);
    ecmin=minutes(ehr,emin,eampm);
    cout << "Time to jump ahead: " << diff(scmin,ecmin) << endl;
    //Exit, stage right
    return 0;
}

unsigned short minutes(unsigned short hr, 
        unsigned short min, char ampm) {
    hr += (ampm=='p' && hr!=CNV_24HR)?CNV_24HR:0;
    hr -= (ampm=='a' && hr==CNV_24HR)?CNV_24HR:0;
    return hr*CNV_MIN_HRS+min;
}

void read(unsigned short &hr, unsigned short &min,
        char &ampm) {
   char dum;
   cout << "Input a time" << endl;
   cout << "Format xx:xx am/pm" << endl;
   cin >>setw(2)>>hr>>dum>>min>>setw(2)>>ampm>>dum;
   cout << "You input the following: " << hr <<" "<<min<<" "<<ampm<<endl;
  
}

unsigned short diff(unsigned short strt, 
                unsigned short stp) {
    short min=stp-strt;
    return (min>0)?min:min+2*CNV_24HR*CNV_MIN_HRS;
}