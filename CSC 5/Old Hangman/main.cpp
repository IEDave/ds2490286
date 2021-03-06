/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on February 3, 2014, 7:11 PM
 * Purpose: This is an implementation of the game "Hangman", where a user
 * attempts to guess the letters of a randomly selected word. If the user
 * makes 10 unsuccessful guesses, they lose the game - if less, they win.
 * Think "Wheel of Fortune" without Pat Sajak or Vanna White and you're on
 * the right track.
 * This game was (somewhat) derived from from a game presented in the book
 * "Basic Computer Games" by David H. Ahl.
 */
//System Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>
using namespace std;

//Global Constants
const int WRD_COL = 32, DISP_COL = 15, DISP_ROW = 15, WRD_ROW = 10,
          MAX_WORD = 10;

//Function Prototypes
void upCase(char &);
void iniWord(char [][WRD_COL]);
void iniDisp(char [][DISP_COL]);
void doHang(char [][DISP_COL],char [][WRD_COL]);
void dspHang(char [][DISP_COL]);
void updtHng(char [][DISP_COL]);
bool strFind(char [], char, unsigned short, char [][DISP_COL]);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    char wrdList[WRD_ROW][WRD_COL], sDisp[DISP_ROW][DISP_COL], iCont;
    //Seed random number generator
    srand(static_cast<unsigned int>(time(0)));
    //Initialize word list & display matrix
    iniWord(wrdList);
    iniDisp(sDisp);
    //Main execution loop
    do {
        //call function doHang(wrdList,sDisp) - play 1 game of Hangman
        doHang(sDisp,wrdList);
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

void iniWord(char words[][WRD_COL]) {
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
    
    return;
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

void doHang(char dMatrix[][DISP_COL],char words[][WRD_COL]) {
    //define local variables
    char word[WRD_COL],letr;
    unsigned short badLetr = 0, wrdLen,wrdLoc;
    bool isWord;
    //randomly pick a word, get its length & location in array
    //wrdLoc = rand()%MAX_WORD;
    wrdLoc = 0;
    strcpy(word,words[wrdLoc]);
    wrdLen = strlen(word);
    //loop
    do {
        //ask user for a letter (cvt. to uppercase)
        cout << "Letter? ";
        cin >> letr;
        upCase(letr);
        if (letr >= 'A' && letr <= 'Z') {
            if (strFind(word, letr, wrdLen, dMatrix)) {
                dspHang(dMatrix);
                cout << "Found " << letr << "." << endl;
            } else {
                badLetr++;
                updtHng(dMatrix);
                dspHang(dMatrix);
                cout << "Didn't find " << letr << "." << endl;
            }
        } else {
              badLetr++;
              updtHng(dMatrix);
              dspHang(dMatrix);
              cout << "Didn't find " << letr << "." << endl;
        }
        isWord = (!strncmp(word,dMatrix[11],wrdLen));
    } while ((badLetr < MAX_WORD-1) && (!isWord));
    if (isWord) {
        cout << "YOU WIN!";
    } else if (badLetr >= MAX_WORD-1) {
        cout << "YOU LOSE!";
    }
    cout << endl;
    return;
}

void dspHang(char dMatrix[][DISP_COL]) {
    for (int row = 0; row <= DISP_ROW-1; row++) {
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
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

