/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 6, 2014, 10:12 AM
 * Fun with Linear Algebra
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

//Function Prototypes
int **filAray(int,int);
void prntAry(int **,int,int,int);
void destroy(int **,int);
int **add(int **,int **,int,int);
int **sub(int **,int **,int,int);
int **mul(int **,int **,int,int);

//Execution begins here
int main(int argc, char** argv) {
    int row, col;
    srand(static_cast<unsigned int>(time(0)));
    //Prompt and input rows and columns
    cout << "How large of a 2-dimensional array?" << endl;
    cout << "Input rows and columns:" << endl;
    cin >>row>>col;
    //Fill array
    int **array= filAray(row,col);
    int **brray= filAray(row,col);
    //Add matrices
    int **crray=add(array,brray,row,col);
    //Sub matrices
    int **drray=sub(array,brray,row,col);
    //Multiply matrices
    int **erray=mul(array,brray,row,col);
    //Print matrices
    prntAry(array,row,col,4);
    prntAry(brray,row,col,4);
    prntAry(crray,row,col,4);
    prntAry(drray,row,col,4);
    prntAry(erray,row,col,6);
    //Clean up
    destroy(array,row);
    destroy(brray,row);
    destroy(crray,row);
    destroy(drray,row);
    destroy(erray,row);
    //Exit,stage right.
    return 0;
}
int **mul(int **a,int **b,int rows,int cols){
    int **c=filAray(rows,cols);
    //Null destination matrix
    for (int row = 0; row<rows; row++){
        for (int col=0; col<cols; col++) {
            c[row][col] = 0;
        }
    }
    //Multiply the 2 arrays
    for (int row = 0; row<rows; row++){
        for (int col=0; col<cols; col++) {
            c[row][col] += a[row][col]*b[col][row];
        }
    }
    return c;
}

int **sub(int **a,int **b,int rows,int cols){
    int **c=filAray(rows,cols);
    //Add the 2 arrays
    for (int row = 0; row<rows; row++){
        for (int col=0; col<cols; col++) {
            c[row][col] = a[row][col]-b[row][col];
        }
    }
    return c;
}

int **add(int **a,int **b,int rows,int cols){
    int **c=filAray(rows,cols);
    //Add the 2 arrays
    for (int row = 0; row<rows; row++){
        for (int col=0; col<cols; col++) {
            c[row][col] = a[row][col]+b[row][col];
        }
    }
    return c;
}

void destroy(int **a,int rows){
    for (int row=0; row<rows; row++) {
        delete [] a[row];
    }
    delete []a;
}

void prntAry(int **a,int rows,int cols,int wide) {
    cout << endl;
    for (int row = 0; row<rows; row++){
        for (int col=0; col<cols; col++) {
            cout << setw(wide);
            cout << a[row][col];
        }
        cout << endl;
    }
    cout << endl;
}

int **filAray(int rows, int cols) {
    //declare & create 2-d array
    int **a = new int*[rows];
    for (int row=0; row <rows;row++){
        a[row]=new int[cols];
    }
    //
    for (int row = 0; row<rows; row++){
        for (int col=0; col<cols; col++) {
            a[row][col] = rand()%90+10;
        }
    }
    
    return a;
}

