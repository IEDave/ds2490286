/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 7, 2014, 4:58 PM
 * Gaddis, 7th Edition - Chapter 12, Problem 1
 * File Head program: Ask user for a filename, then display the first 10 lines
 * of the file. If the file has less than 10 lines, inform user that the
 * entire file is displayed.
 */

//System Libraries
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants
    const int NUM_LNS = 10,NUM_CHAR = 256;
    //Define local variables
    ifstream file;
    char uFileNm[NUM_CHAR];
    string fileBuf;
    int ln;
    //Get user input
    cout << "Enter file name: ";
    cin >> uFileNm;
    //Open file stream for reading
    file.open(uFileNm,ios::in);
    //Main program loop - read 10 lines. If file has fewer than 10 lines,
    //break out of loop & inform user that file has only n lines in it.
    if (!file.fail()) {
        for (ln=1; ln<=NUM_LNS; ln++) {
            getline(file,fileBuf);
            cout << fileBuf << endl;
            if (file.eof()){
                break;
            }
        }
        if (ln<10)
            cout << "EOF - file only contains " << ln << " lines." << endl;
    } else {
        cout << "File '" << uFileNm << "' does not exist." << endl;
    }
    //Close file stream
    file.close();
    //Exit, stage right.
    return 0;
}

