/* 
 * File:   main.cpp
 * Author: David
 *
 * Created on January 30, 2014, 2:00 PM
 */
//#include <cstdlib>
#include <iostream>
//#include <vector>
using namespace std;

int main(int argc, char** argv) {
    int i,j;
    unsigned short dol,cnt;
    char decPt, words[50][32] = {"AARDVARK","ALIMENTARY"}, page[13][13];
    
    cout << "Enter a dollar amount: $";
    cin >> dol >> decPt >> cnt;
    cout << "$" << dol << "." << cnt << endl;
    
    for (i=32; i<=127; i++) {
        cout << i << " - " << static_cast<char>(i);
        cout << endl;
    }
    
    

    return 0;
}


