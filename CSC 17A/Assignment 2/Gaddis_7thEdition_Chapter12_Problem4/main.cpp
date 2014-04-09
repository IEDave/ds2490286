/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 8, 2014, 3:45 PM
 * Gaddis, 7th Edition - Chapter 12, Problem 4
 * File Tail program: Ask user for a filename, then display the last 10 lines
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
    int ln = 0;
    //Get user input
    cout << "Enter file name: ";
    cin >> uFileNm;
    //Open file stream for reading
    file.open(uFileNm,ios::in);
    //Need to make 2 passes through the file. On pass I, count the number of
    //lines until you hit EOF. On pass II, read up to (n-10) lines, then
    //display the last 10 lines. If file has less than 10 lines in it, display
    //file content then tell user how many lines file has.
    if (!file.fail()) {
        //Pass I - get the number of lines in the file.
        while (!file.eof()){
            getline(file,fileBuf);
            ln++;
        }
        //Pass II - we'll do this as a two-piece-ee. Piece 1 will be for files
        //longer than or equal to 10 lines; piece 2 will be for files less than
        //10 lines.
        //First, close & re-open file stream to reset internal pointers to SOF.
        file.close();
        file.open(uFileNm,ios::in);
        if (ln >= NUM_LNS) {
            //Piece 1 - Since you already know how long the file is, read the
            //file again, printing only the last 10 lines.
            for (int i=1; i<=ln; i++) {
                getline(file,fileBuf);
                if (i >= (ln-NUM_LNS) && i <= ln) {
                    cout << fileBuf << endl;
                }
            }
        } else {
            //Piece II - the file is less than 10 lines long. Display the
            //whole file and let user know how many lines the file has.
            while (!file.eof()) {
                getline(file,fileBuf);
                cout << fileBuf << endl;
            }
            cout << "EOF - file only contains " << ln << " lines." << endl;
        }
    } else {
        cout << "File '" << uFileNm << "' does not exist." << endl;
    }
    //Close file stream
    file.close();
    //Exit, stage right.
    return 0;
}
