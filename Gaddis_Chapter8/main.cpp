/* 
 * File:   main.cpp
 * Author: David W. Smith
 *
 * Created on January 23, 2014, 11:16 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>
using namespace std;

//Global Constants

//Function Prototypes
bool isPrime(unsigned int);
int outPrime(unsigned int);
int random(unsigned int, unsigned int);

//Execution begins here
int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    int strt=100,stp=200,cnt;
    int rnd = random(strt,stp);
    cout << "The random numbers up to " << rnd << " are:" << endl;
    cnt = outPrime(rnd);
    cout << "The number of primes is: " << cnt << endl;
    return 0;
}

bool isPrime(unsigned int n){
    int loop=sqrt(n);
    for (int i=2; i<=loop; i++){
        if (n % i==0) return false;
    }
    return true;
}

int outPrime(unsigned int n) {
    //Count the number of primes
    int cnt=0;
    for (int i=2; i<= n; i++){
        if(isPrime(i)) {
            cout << setw(5) << i;
            if(cnt++%10==9)
                cout << endl;
        }
    }
    cout << endl;
    return cnt;
}

int random(unsigned int strt, unsigned int stp) {
    return rand()%(stp-strt+1)+strt;
}

