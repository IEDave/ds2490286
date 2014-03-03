/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 3, 2014, 7:11 PM
 * Purpose: This is an implementation of the game "Hangman", where a user
 * attempts to guess the letters of a randomly selected word. If the user
 * makes 9 unsuccessful guesses, they lose the game - if less, they win.
 * Think "Wheel of Fortune" without Pat Sajak or Vanna White and you're on
 * the right track.
 * This game was (somewhat) derived from from a game presented in the book
 * "Basic Computer Games" by David H. Ahl. All rights reserved.
 */
//System Libraries
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

//Global Constants
const int WRD_COL = 32, DISP_COL = 15;

//Function Prototypes
void upCase(char &);
bool isFile(const char []);
int iniWord(char [][WRD_COL]);
int iniWord(char [][WRD_COL], const char[]);
void iniDisp(char [][DISP_COL]);
void doHang(char [][DISP_COL],char [][WRD_COL], int, int, int);
void dspHang(char [][DISP_COL],int);
void updtHng(char [][DISP_COL],unsigned short);
bool strFind(char [], char, unsigned short, char [][DISP_COL]);
void wrdSort(const char []);

//Execution begins here
int main(int argc, char** argv) {
    //Define local constants
    const int DISP_ROW = 15, WRD_ROW = 10;
    //Define local variables
    char wrdList[WRD_ROW][WRD_COL], sDisp[DISP_ROW][DISP_COL], iCont;
	int maxWord;
    //Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Initialize word list & display matrix
    if (isFile("words.dat")){
        wrdSort("words.dat");
        maxWord = iniWord(wrdList,"words.dat"); 
    } else
        maxWord = iniWord(wrdList);
    iniDisp(sDisp);
    //Main execution loop
    do {
        //call function doHang() - play 1 game of Hangman
        doHang(sDisp,wrdList,DISP_ROW,WRD_ROW,maxWord);
        //Confirm with user - are we done?
        cout << "Play again(Y/N)?";
        cin >> iCont;
        upCase(iCont);
    } while(iCont == 'Y');
    //Exit, stage right
    return 0;
}

void upCase(char &chkIt) {
    (chkIt >= 'a' && chkIt <= 'z')? chkIt=chkIt-'a'+'A':chkIt=chkIt;
}

bool isFile(const char fname[] = "words.dat") {
    ifstream file;
    file.open(fname);
    if (file.fail()) {
        file.close();
        return false;
    } else {
        file.close();
        return true;
    }     
}

int iniWord(char words[][WRD_COL],const char fname[] = "words.dat") {
    //Declare local variables
    ifstream istream;
    string word;
    int wrdCnt = 0, wrdLen, i;
    //Open file
    istream.open(fname);
    //Main execution loop
    while(istream >> word) {
	//Convert characters in word read from input stream to
	//uppercase, copy to word list
        for (i = 0; i <= word.length(); i++) {
            upCase(word[i]);
            words[wrdCnt][i] = word[i];
        }
	//Need to null terminate character array
        words[wrdCnt][i] = '\0';
	//Increment index pointer
        wrdCnt++;
    }
	//Close file
    istream.close();
 
    return wrdCnt;
}

int iniWord(char words[][WRD_COL]) {
    strcpy(words[0],"AARDVARK");
    strcpy(words[1],"ALIMENTARY");
    strcpy(words[2],"ADVICE");
    strcpy(words[3],"BELLICOSE");
    strcpy(words[4],"BUPKIS");
    strcpy(words[5],"BUM");
    strcpy(words[6],"CALENDAR");
    strcpy(words[7],"CADILLAC");
    strcpy(words[8],"DINKUM");
    strcpy(words[9],"DWEEZIL");
    
    return 10;
}

void iniDisp(char dMatrix[][DISP_COL]) {
    strcpy(dMatrix[0],"              ");
    strcpy(dMatrix[1]," +-------+    ");
    strcpy(dMatrix[2]," |       |    ");
    strcpy(dMatrix[3]," |            ");
    strcpy(dMatrix[4]," |            ");
    strcpy(dMatrix[5]," |            ");
    strcpy(dMatrix[6]," |            ");
    strcpy(dMatrix[7]," |            ");
    strcpy(dMatrix[8]," |            ");
    strcpy(dMatrix[9],"==============");
    strcpy(dMatrix[10],"              ");
    strcpy(dMatrix[11],"**************");
    strcpy(dMatrix[12],"              ");
    strcpy(dMatrix[13],"              ");
    strcpy(dMatrix[14],"              ");
    return;
}

void doHang(char dMatrix[][DISP_COL],char words[][WRD_COL],
            int rows, int cols, int totWrds=10) {
    //Define local constant
    const int HANGMAN = 9;
    //define local variables
    char word[WRD_COL],letr;
    unsigned short badLetr = 0,wrdLen,wrdLoc;
    bool isWord=false;
    //randomly pick a word, get its length & location in array
    wrdLoc = rand()%totWrds;
    strcpy(word,words[wrdLoc]);
    wrdLen = strlen(word);
    //Initialize display matrix, print cheery welcome message & display
    //empty gallows
    iniDisp(dMatrix);
    cout << "Welcome to HANGMAN" << totWrds << endl;
    dspHang(dMatrix,rows);
    //loop
    while((badLetr < HANGMAN) && (!isWord)) {
        //ask user for a letter (cvt. to uppercase)
        cout << "Letter? ";
        cin >> letr;
        upCase(letr);
        if (letr >= 'A' && letr <= 'Z') {
            if (strFind(word, letr, wrdLen, dMatrix)) {
                dspHang(dMatrix,rows);
                cout << "Found " << letr << "." << endl;
            } else {
                badLetr++;
                updtHng(dMatrix,badLetr);
                dspHang(dMatrix,rows);
                cout << "Didn't find " << letr << ". "
                     << "That was error #" << setw(2) << badLetr << "."
                     << endl;
            }
        } else {
              badLetr++;
              updtHng(dMatrix,badLetr);
              dspHang(dMatrix,rows);
              cout << "Didn't find " << letr << ". "
                   << "That was error #" << setw(2) << badLetr << "."
                   << endl;
        }
        isWord = (!strncmp(word,dMatrix[11],wrdLen));
    }
    if (isWord)
        cout << "YOU WIN!";
    else if (badLetr >= HANGMAN)
        cout << "YOU LOSE! Word was (" << word << ")." << endl;
    cout << endl;
    return;
}

void dspHang(char dMatrix[][DISP_COL], int rows) {
    for (int row = 0; row <= rows-1; row++) {
        for (int col = 0; col <= DISP_COL-1; col++) {
            if (dMatrix[row][col] != '\0') 
                cout << dMatrix[row][col];
            else {
                cout << endl;
                col = DISP_COL;
            }      
        }
    }
}

void updtHng(char dMatrix[][DISP_COL],unsigned short errCnt) {
    switch(errCnt) {
        case 1:
            dMatrix[3][9] = 'O';
            break;
        case 2:
            dMatrix[4][9] = '|';
            break;
        case 3:
            dMatrix[4][8] = '\\';
            break;
        case 4:
            dMatrix[4][10] = '/';
            break;
        case 5:
            dMatrix[5][9] = '|';
            break;
        case 6:
            dMatrix[6][8] = '/';
            break;
        case 7:
            dMatrix[6][10] = '\\';
            break;
        case 8:
            dMatrix[7][7] = '-';
            break;
        case 9:
            dMatrix[7][11] = '-';
            break;      
    }
    return;
}

bool strFind(char wrd[], char ltr, unsigned short len,
             char display[][DISP_COL]) {
    bool isFnd = false;
    for (int i = 0; (i < len)&&(wrd[i]!= '\0') ; i++) {
        if (wrd[i] == ltr) {
            isFnd = true;
            display[11][i] = ltr;
        }
    }
    return isFnd;
}

void wrdSort(const char fname[] = "words.dat") {
    //Declare local variables
    ifstream istream;
    ofstream ostream;
    vector<string> words;
    string word;
    int strtScn, minIdx;
    //Open file
    istream.open(fname);
    //Load words into vector, converting characters to uppercase as we go
    while(istream >> word) {
        for (int i = 0; i <= word.length(); i++)
            upCase(word[i]);
        words.push_back(word);
    }
    //Close file
    istream.close();
    //Sort the vector
    for (strtScn = 0; strtScn < words.size()-1; strtScn++) {
        minIdx = strtScn;
        word = words[strtScn];
        for (int idx=strtScn+1;idx < words.size();idx++) {
            if (words[idx] < word) {
                word = words[idx];
                minIdx = idx;
            }
        }
        words[minIdx] = words[strtScn];
        words[strtScn] = word;
    }
    //Write sorted output back onto file
    ostream.open(fname);
    if (!ostream.fail()) {
        for (int idx = 0; idx < words.size(); idx++){
            ostream << words[idx] << endl;
        }
    } else
        cout << "Error writing sorted file." << endl;
    //Close file
    ostream.close();
    return;
}