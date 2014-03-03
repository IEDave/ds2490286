/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  To Illustrate the code for
 * developing a menu
 * Created on October 13, 2011, 6:44 PM
 * Modified by David W. Smith on February 15, 2014, 10:09 PM
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <vector>
using namespace std;

//Global Constants
const unsigned short MAX_KOLS=16; //Problem 5
const int MAX_COLS = 7;           //Problem 6

//Function prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
//Problem 1 function prototypes
unsigned short revShrt(unsigned short, const int, bool &);
//Problem 3 function prototypes
void fillVec(vector<unsigned short>&, vector<unsigned short>&, const int);
void prntVec(vector<unsigned short>&, vector<unsigned short>&, const int);
//Problem 4 function prototypes
void retrand(short int [], int [],const int,const int);
short int fndRnd(short int [], const int);
//Problem 5 function prototypes
void selsort(char [][MAX_KOLS],unsigned short);
void prntMat(const char [][MAX_KOLS],const unsigned short);
//Problem 6 function prototypes
bool readTbl(unsigned short [][MAX_COLS],int,const char []);
void prntTbl(const unsigned short [][MAX_COLS],const int, const int);
void sumTbl(unsigned short [][MAX_COLS], int);
bool wrtTbl(const unsigned short [][MAX_COLS],const int,const char []);

//Execution begins here
int main(int argc, char** argv) {
    int choice;
    //General Menu Format
    cout << "Welcome to Dave's Takehome Final:" << endl;
    cout << "Submitted as part of a grade for CSC 5" << endl;
    cout << "Winter intersession 2013-2014." << endl;
    cout << "David W. Smith - 2/15/14." << endl;
    cout << "=======================================" << endl;
    do{
        //Display the selection
        cout<<"Type 1 to solve problem 1"<<endl;
        cout<<"Type 2 to solve problem 2"<<endl;
        cout<<"Type 3 to solve problem 3"<<endl;
        cout<<"Type 4 to solve problem 4"<<endl;
        cout<<"Type 5 to solve problem 5"<<endl;
        cout<<"Type 6 to solve problem 6"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
                case 1:{
                    cout<<endl;
                    cout<<"Solution to Problem 1:"<<endl;
                    problem1();
                    break;
                }
                case 2:{
                    cout<<"Solution to Problem 2:"<<endl;
                    cout<<endl;
                    problem2();
                    break;
                }
                case 3:{
                    cout<<endl;
                    cout<<"Solution to Problem 3:"<<endl;
                    problem3();
                    break;
                }
                case 4:{
                    cout<<endl;
                    cout<<"Solution to Problem 4:"<<endl;
                    problem4();
                    break;
                }
                case 5:{
                    cout<<endl;
                    cout<<"Solution to Problem 5:"<<endl;
                    problem5();
                    break;
                }
                case 6:{
                    cout<<endl;
                    cout<<"Solution to Problem 6:"<<endl;
                    problem6();
                    break;
                }
                default:{
                        cout<<"Exit?"<<endl;
                        break;
                }
        };
    }while(choice >= 1 && choice <= 6);//Upper do-while
    //Exit, stage right.
    return 0;
}

void problem1() {
/* 
 * Author: David W. Smith
 * Created on February 15, 2014, 1:44 AM
 * Final - Problem 1:
 * Write a function that takes an unsigned
 * short integer and returns an unsigned short
 * number in reverse.  For instance 106 
 * reversed would be 601.  Another would be 
 * 30000 gives 3.  Check to make sure the 
 * conversion falls within the range for an 
 * unsigned short. If it doesn't then output
 * no conversion possible.
 */
    //Declare local variables
    string iLine;
    int num=0,factor,iLen;
    unsigned short result;
    bool isNum;
    //Ask user for input
    cout << "Enter a number between 0 and 65535: " << endl;
    cin >> iLine;
    iLen = iLine.size();
    //Check to see if it's a valid input before passing to conversion function.
    if (iLen <= 5) {
        for (int i=0; i <= iLen-1; i++){
            if (iLine[i] >= '0' && iLine[i] <= '9') {
                switch (iLen-i){
                    case 1:
                        factor = 1;
                        break;
                    case 2:
                        factor = 10;
                        break;
                    case 3:
                        factor = 100;
                        break;
                    case 4:
                        factor = 1000;
                        break;
                    case 5:
                        factor = 10000;
                        break;
                }
                num += (iLine[i]-'0')*factor;
                isNum = true;
            }
            else {
                isNum = false;
                break;
            }
        }
        //If it makes the cut - pass it to conversion function. If it didn't,
        //flag it as invalid & end program.
        if (isNum && (num>= 0 && num <= 65535)) {
            result = revShrt(static_cast<unsigned short> (num),iLen,isNum);
            if (isNum)
                cout << "Reversed " << num << " is " << result << "." << endl;
            else
                cout << "Conversion not possible.";
        } else {
            cout << "Conversion not possible." << endl;
        }
    } else {
        cout << "Conversion not possible." << endl;
    }
    //Exit,stage right
    return;
}

unsigned short revShrt(unsigned short num, const int len, bool &isNum) {
    //Define local variables
    int digit;
    int result = 0,factor;
    //pop off least significant digits & multiply them by factors in
    //reverse order to convert them to a reverse-order number. Has to
    //be done as an int because of the possibility of an overflow of a
    //unsigned short.
    for (int i = len; i >= 1; i--){
        digit = num % 10;
        num /= 10;
        switch(i){
            case 1:
                factor = 1;
                break;
            case 2:
                factor = 10;
                break;
            case 3:
                factor = 100;
                break;
            case 4:
                factor = 1000;
                break;
            case 5:
                factor = 10000;
                break;
        }
        result += digit*factor;
    }
    //If the result is valid, return it - otherwise set the boolean flag to
    //indicate unsuccessful conversion and return 0;
    if (result >= 0 && result <=65535) {
        isNum = true;
        return static_cast<unsigned short> (result);
    } else {
        isNum = false;
        return 0;
    }
}

void problem2() {
/* 
 * Author: David W. Smith
 * Created on February 15, 2014, 5:04 AM
 * Final - Problem 2:
 * Write a program that plays the game "Guess the
 * Number" as follows.  Your program chooses the
 * number to be guessed by selecting an integer
 * at random in the range 1 to 950.  The program
 * displays
 *
 *
 * 
 * I have a number between 1 and 950
 * Can you guess my number?  You will be
 * given a maximum of 10 guesses.
 * Please type your first guess.
 *
 *
 * The player then types a guess.  The
 * program responds with one of the following.
 *
 *
 * 1. Congratulations, You guessed the number!
 *    Would you like to play again(y or n)?
 * 2. Too low.  Try again.
 * 3. Too High. Try again.
 * 4. Too many tries.
 */
    //Define local constants
    const short MAX_GUES = 10;
    //Define local variables
    unsigned short guessIt, iGuess, numGues;
    bool isNum,iPlay;
    char iCont;
    //Seed random number generator.
    srand(static_cast<unsigned int>(time(0)));
    //Start guessing game
    do {
        //Generate random number between 1 to 950
        guessIt = rand()%950+1;
        //Init variables for game play
        numGues = 0;
        isNum = false;
        iPlay = false;
        //Display opening message
        cout << "I have a number between 1 and 950." << endl;
        cout << "Can you guess my number?  You will be" << endl;
        cout << "given a maximum of 10 guesses." << endl;
        cout << "Please type your first guess: " << endl;
        //Begin main execution loop
        do {
            cin >> iGuess;
            numGues++;
            if (numGues > MAX_GUES) {
               cout << "Too many tries." << endl;
            } else if (iGuess < guessIt) {
                cout << "Too low. Try again." << endl;
            } else if (iGuess > guessIt) {
                cout << "Too high. Try again." << endl;
            } else if (iGuess == guessIt) {
                cout << "Congratulations, You guessed the number!" << endl;
                isNum = true;        
            }
        } while ((!isNum) && (numGues <= MAX_GUES));
        //At this point, we only give a successful guesser the option to play
        //again.
        if (numGues <= MAX_GUES) {
            cout << "Would you like to play again(y or n)?";
            cin >> iCont;
            if (iCont == 'y' || iCont == 'Y')
                iPlay = true;
        } else {
            iPlay = false;
        }
    } while(iPlay);
    //Exit, stage right.
    return;
}

void problem3() {
/* 
 * Author: David W. Smith
 * Created on February 15, 2014, 1:34 PM
 * Final - Problem 3:
 * Create a function that fills one vector with even
 * random 2 digit numbers and another vector with
 * odd random numbers.  Prompt the user for the size
 * of these vectors.  Both will be the same size.
 * Output the results where you ask the user how
 * many columns to display.  These should be done
 * with 2 functions, fillVec and prntVec.
 */
    //Define local variables
    vector<unsigned short> eVec, oddVec;
    int iSize;
    
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Ask user for the size of the list
    cout << "Enter the number of elements to be put into the vectors:";
    cin >> iSize;
    //Fill vectors with requested # of elements
    fillVec(eVec,oddVec,iSize);
    //Ask user for # of columns to print
    cout << "Enter the number of columns to print:";
    cin >> iSize;
    //Print vectors with requested # of columns
    prntVec(eVec,oddVec,iSize);
    //Exit, stage right
    return;
}

void fillVec(vector<unsigned short> &a, vector<unsigned short> &b,
             const int elemnts) {
    //Define local variables
    unsigned short rndNum;
    
    //First, fill even numbered vector
    for (int i=0; i<elemnts; i++) {
        do {
            rndNum = rand()%90+10;
        } while (rndNum % 2);
        a.push_back(rndNum);
    }
    //Then, fill odd numbered vector
        for (int i=0; i<elemnts; i++) {
        do {
            rndNum = rand()%90+10;
        } while (!(rndNum % 2));
        b.push_back(rndNum);
    } 
}

void prntVec(vector<unsigned short>&a, vector<unsigned short>&b,
             const int cols) {
    //First, print even numbered vector contents, breaking every cols element
    for (int i=0; i<a.size(); i++) {
        cout << setw(3) << a[i];
        if (!((i+1) % (cols)))
            cout << endl;
    }
    cout << endl;
    //Then, print odd numbered vector contents, breaking every cols element
    for (int i=0; i < b.size(); i++) {
        cout << setw(3) << b[i];
            if (!((i+1) % (cols)))
                cout << endl;
    }
}

void problem4() {
/* 
 * Author: David W. Smith
 * Created on February 15, 2014, 2:50 PM
 * Final - Problem 4:
 * Create a function/method/procedure that
 * returns a random number from the following set,
 * {9,51,79,182,251}.  Loop 10000 times with this 
 * procedure and print the frequency of each of 
 * the 5 numbers obtained.  Hint: Use an array for 
 * the sequence and frequency.  
 *
 *
 * The following is a brief hint on items that might 
 * be helpful in obtaining the results.  This is not 
 * direct code but more pseudo code related.  Don't 
 * try and run the following directly and more code 
 * will be needed.
 *
 *
 * Setup
 *         const int n=5,ntimes=10000;
 *         int freq[n]={0};
 *         short int rndseq[]={9,51,79,182,251};
 *
 *
 * Call to the routine to return a random sequence
 *        retrand(rndseq,freq,n,ntimes);
 *
 *
 * Results
 *         cout<<rndseq[i]<<" occured "<<
 *                 freq[i]<<" times"<<endl;
 *
 *
 * Sample Output
 *         9 occured 2055 times
 *         51 occured 1986 times
 *         79 occured 1962 times
 *         182 occured 2079 times
 *         251 occured 1919 times
 *
 *
 * Note:  Your results are not expected to be exactly
 * the same!  After all these are pseudo-random 
 * number sequences with different seeds.  
 */

    //Define local variables
    const int n = 5, ntimes = 10000;
    int freq[n] = {0};
    short int rndseq[] = {9, 51, 79, 182, 251};
    
    //Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Call routine to generate random sequence
    retrand(rndseq,freq,n,ntimes);
    //Print results
    for (int i=0; i<n; i++) {
         cout << rndseq[i] << " occurred " <<
         freq[i] << " times." << endl;
    }
    //Exit, stage right
    return;
}

void retrand(short int values[], int freqs[],const int n,const int nTimes){
    for (int i = 0; i < nTimes; i++) {
        freqs[fndRnd(values,n)]++;
    }
}

short int fndRnd(short int values[], const int n) {
    //define local variables
    bool isFnd = false;
    short int value, i;
    //Crank out random numbers until one is found in the list.
    do {
        value = rand() % 255;
        for (i = 0; i < n; i++) {
            if (value == values[i]) {
                isFnd = true;
                break;
            }
        }
    } while(!isFnd);
    return i;
}

void problem5() {
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
    //Define local constants
    const unsigned short MAX_ROWS=10;
    //Define local variables
    ifstream file;
    unsigned short row,col;
    char matrix[MAX_ROWS+1][MAX_KOLS];
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
    return;
}

void prntMat(const char matrix[][MAX_KOLS], const unsigned short rows) {
    for (int row=0; row < rows; row++) {
        for (int col = 0; col < MAX_KOLS; col++) {
            cout << matrix[row][col];
        }
        cout << endl;
    }
}


void selsort(char matrix[][MAX_KOLS], unsigned short rows) {
    //Define local variables
    char line[MAX_KOLS];
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

void problem6() {
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
    return;
}

bool readTbl(unsigned short mat[][MAX_COLS],int rows,const char fname[]){
    //Define local variables
    ifstream file;
    bool isFile;
    int row,col;
    //Attempt file open
    cout << "Attempting file open..." << endl;
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
    return isFile;
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

