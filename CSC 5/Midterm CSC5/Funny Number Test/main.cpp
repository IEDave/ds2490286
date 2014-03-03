/* 
 * File:   main.cpp
 * Author: David Smith
 * Created on January 28, 2014, 7:51 PM
 * Midterm problem #6 - Funny Numbers
 */

//System Libraries
#include <iostream>
using namespace std;

//Global constants

//Function prototypes
bool isFunny(unsigned int,unsigned int&,unsigned int&,unsigned int&);

//Execution begins here
int main(int argc, char** argv) {
    unsigned int count = 0, funny = 0,
	bucket2 = 0, bucket3 = 0, bucket5 = 0;
    while (count < 1501) {
        funny++;
        if (isFunny(funny,bucket2,bucket3,bucket5)) {
            count++;
            if ((count % 100)==0)
                cout << count << " funny numbers counted..." << endl;
        }
    }
    cout << "The 1501'st funny number is: " << funny << "." << endl;
    //Exit, stage right!
    return 0;
}

bool isFunny(unsigned int check, unsigned int &bucket2,
             unsigned int &bucket3, unsigned int &bucket5) {
    unsigned int buck2 = 0, buck3 = 0, buck5 = 0;
    //Strip out all the factors of 2
    if (bucket2 && !(check % 2))
	check /= bucket2;
    while(!(check % 2)) {
        check /= 2;
        buck2 *= 2;
    }
    if (buck2 > bucket2)
        bucket2 = buck2;
    //Strip out all the factors of 3
    if (bucket3 && !(check % 3))
	check /= bucket3;
    while(!(check % 3)) {
        check /= 3;
	buck3 *= 3;
	}
    if (buck3 > bucket3)
	bucket3 = buck3;
    //Strip out all the factors of 5
    if (bucket3 && !(check % 3))
	check /= bucket3;
    while(!(check % 5)) {
        check /= 5;
	buck5 *= 5;
    }
    if (buck5 > bucket5)
        bucket5 = buck5;
    //Check to see what's left. If it's a 1,
    //we've got us a funny number. If not,
    //there are other factors and, hence,
    //it's not a funny number
    if (check == 1)
        return true;
    else
        return false;
}

