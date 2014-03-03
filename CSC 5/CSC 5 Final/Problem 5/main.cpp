/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 15, 2014, 4:09 PM
 * Final - Problem 5:
 * Problem #5  (All Kinds of Sorting)
 * Sort a 10x15 array of characters.  Largest located
 * at index [0][0-14] and smallest at index [9][0-14].  
 * Create a procedure that passes the array to a print routine, 
 * then a procedure that sorts the array and returns the sorted array 
 * to the original procedure, and finish by using the same print routine.  
 * Fill the array with
 *
 *
 * Lcekoeddhoffbmc
 * Lkcmggjcdhhglif
 * Cgldjhcekjigcdd
 * Cgldjhcekjigcdn
 * Bffmdbkcenlafjk
 * Fggdijijegfblln
 * Jjlncnimjldfedj
 * Amliglfohajcdmm
 * Balgfcaelhfkgeb
 * Kmlhmhcddfoeild
 *
 *
 * Note:  This is a character array but the sorting is 
 * done as if there are 10 strings with each string having 15 characters.  
 * The output would be
 *
 *
 * Lkcmggjcdhhglif
 * Lcekoeddhoffbmc
 * Kmlhmhcddfoeild
 * Jjlncnimjldfedj
 * Fggdijijegfblln
 * Cgldjhcekjigcdn
 * Cgldjhcekjigcdd
 * Bffmdbkcenlafjk
 * Balgfcaelhfkgeb
 * Amliglfohajcdmm
 *
 * Full credit will be given if a file is used to read in the array.
 * Name the file input.dat
 * 
 */

//System Variables
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//Global Constants
const unsigned short MAX_COLS=16;

//Structures

//Function Prototypes
void selsort(char [][MAX_COLS],unsigned short);
void prntMat(const char [][MAX_COLS],const unsigned short);

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants
    const unsigned short MAX_ROWS=10;
    //Define local variables
    ifstream file;
    unsigned short row,col;
    char matrix[MAX_ROWS+1][MAX_COLS];
    //Open file for reading
    cout << "Opening file..." << endl;
    file.open("input.dat");
    //If file was opened successfully, read contents into matrix else abort
    //with error message & attempted file close.
    if (file.fail()) {
        cout << "Error opening input file." << endl;
        file.close();
    } else {
        cout << "Reading file..." << endl;
        for (row=0; row < MAX_ROWS; row++) {
             file >> matrix[row];
        }
        cout << "Printing matrix..." << endl;
        prntMat(matrix,MAX_ROWS);
        //Call function to sort matrix
        cout << endl;
        cout << "Sorting matrix..." << endl;
        selsort(matrix, MAX_ROWS);
        //Print matrix
        cout << endl;
        cout << "Printing sorted matrix..." << endl;
        prntMat(matrix,MAX_ROWS);
    }
    //Exit, stage right.
    return 0;
}

void prntMat(const char matrix[][MAX_COLS], const unsigned short rows) {
    for (int row=0; row < rows; row++) {
        for (int col = 0; col < MAX_COLS; col++) {
            cout << matrix[row][col];
        }
        cout << endl;
    }
}


void selsort(char matrix[][MAX_COLS], unsigned short rows) {
    //Define local variables
    char line[MAX_COLS];
    int strtEle,minIdx;
    //Perform selection sort
    for (strtEle = 0; strtEle < rows-1; strtEle++) {
        minIdx = strtEle;
        strcpy(line,matrix[strtEle]);
        for (int idx=strtEle+1;idx < rows;idx++) {
            if (strcmp(line,matrix[idx]) < 0) {
                strcpy(line,matrix[idx]);
                minIdx = idx;
            }
        }
        strcpy(matrix[minIdx],matrix[strtEle]);
        strcpy(matrix[strtEle],line);
    }
}

