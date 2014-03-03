/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 15, 2014, 6:43 PM
 * Final - Problem 6
 * Problem #6  (Spreadsheet Stuff)
 *         Create the following input tables.  Output
 * the sum of the rows, columns and grand total.  You
 * will need to create procedures that print the table,
 * then sum rows, columns and grand total, then pass
 * that information to the same print routine.  Note:
 * the 2 procedures printTable,SumTable and finally a
 * call to printTable again are all invoked from subroutine 
 * main.  I want to see each number formated to 6 spaces.  
 * Print the table out exactly as below.
 *
 *
 * Example Input Table
 *  100   101   102   103   104   105
 *  106   107   108   109   110   111
 *  112   113   114   115   116   117
 *  118   119   120   121   122   123
 *  124   125   126   127   128   131
 * Example Output Augmented Table with rows summed,
 * columns summed and the grand total printed.
 *  100   101   102   103   104   105   615
 *  106   107   108   109   110   111   651
 *  112   113   114   115   116   117   687
 *  118   119   120   121   122   123   723
 *  124   125   126   127   128   131   761
 *  560   565   570   575   580   587  3437
 *
 *
 * More credit will be given if you read the input and write 
 * the results to a file.  However, if you can't do this in 
 * a procedure then embed in the program.  But full credit 
 * will not be given for the problem if files
 * are not utilized. Name the files table.dat and augtable.dat
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Global Constants
const int MAX_COLS = 7;

//Structures

//Function prototypes
bool readTbl(unsigned short [][MAX_COLS],int,const char []);
void prntTbl(const unsigned short [][MAX_COLS],const int, const int);
void sumTbl(unsigned short [][MAX_COLS], int);
bool wrtTbl(const unsigned short [][MAX_COLS],const int,const char []);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    const int MAX_ROWS = 6;
    bool isValid;
    unsigned short matrix[MAX_ROWS][MAX_COLS]={0};
    isValid = readTbl(matrix,MAX_ROWS,"table.dat");
    if (isValid) {
        prntTbl(matrix,MAX_ROWS-1,MAX_COLS-1);
        cout << endl;
        sumTbl(matrix,MAX_ROWS);
        prntTbl(matrix,MAX_ROWS,MAX_COLS);
        wrtTbl(matrix,MAX_ROWS,"augtable.dat");
    } else
        cout << "Unable to open input file." << endl;
    //Exit, stage right
    return 0;
}

bool readTbl(unsigned short mat[][MAX_COLS],int rows,const char fname[]){
    //Define local variables
    ifstream file;
    bool isFile;
    int row,col;
    //Attempt file open
    file.open(fname);
    //If file was opened successfully, read contents into matrix else abort
    //with error message & attempted file close.
    if (file.fail()) {
        file.close();
        isFile = false;
    } else {
        isFile = true;
        for (row=0; row < rows-1; row++) {
            for (col = 0; col < MAX_COLS-1; col++) {
                file >> mat[row][col];
            }
        }
        file.close();
    }
}

void prntTbl(const unsigned short mat[][MAX_COLS],const int rows,
             const int cols) {
    //Define local variables
    int row,col;
    
    for (row=0; row < rows; row++) {
        for (col = 0; col < cols; col++) {
            cout << setw(6) << mat[row][col];
        }
        cout << endl;
    }
}

void sumTbl(unsigned short mat[][MAX_COLS], int rows) {
    //Define local variables
    unsigned short row,col,rowtot,coltot,tottot=0;
    
    for (row=0; row < rows-1; row++) {
        rowtot = 0;
        for (col = 0; col < MAX_COLS-1; col++) {
            rowtot += mat[row][col];
        }
        mat[row][MAX_COLS-1] = rowtot;
        tottot += rowtot;
    }
    for (col=0; col < MAX_COLS-1; col++) {
        coltot = 0;
        for (row = 0; row < rows-1; row++) {
            coltot += mat[row][col];
        }
        mat[rows-1][col] = coltot;
    }
    mat[rows-1][MAX_COLS-1] = tottot;
}

bool wrtTbl(const unsigned short mat[][MAX_COLS], const int rows,
            const char fname[]) {
    //Define local variables
    ofstream file;
    bool isFile;
    int row,col;
    //Attempt file open
    file.open(fname);
    //If file was opened successfully, read contents into matrix else abort
    //with error message & attempted file close.
    if (file.fail()) {
        file.close();
        isFile = false;
    } else {
        isFile = true;
        for (row=0; row < rows; row++) {
            for (col = 0; col < MAX_COLS; col++) {
                file << setw(6) << mat[row][col];
            }
            file << endl;
        }
        file.close();
    }
    return isFile;
}
