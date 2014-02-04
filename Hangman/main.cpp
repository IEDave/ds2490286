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
 * "Basic Computer Games" by David H. Ahl. When presuming that I simply
 * cribbed someone else's code, note 3 things:
 * 1) The game of "hangman" has been around for quite a bit longer than
 *    computer systems;
 * 2) The source code presented was in DEC BASIC-PLUS, not C++;
 * 3) The source was written well before object oriented programming or
 *    structured programming methodologies existed - in short, "...you ain't
 *    never seen so many GOTOs in your life, mister!". Hence, the original code
 *    is largely unusable, except as pseudocode - and not terribly useful as
 *    that.
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
void iniWord(char [][WRD_COL], bool[]);
void iniDisp(char [][DISP_COL]);
void doHang(char [][WRD_COL],char [][DISP_COL]);
void dump(char [][DISP_COL]);

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    char wrdList[WRD_ROW][WRD_COL], sDisp[DISP_ROW][DISP_COL], iCont;
    bool usedWrd[WRD_ROW];
    //Seed random number generator
    
    //Initialize word list & display matrix
    iniWord(wrdList,usedWrd);
    iniDisp(sDisp);
    //Main execution loop
    do {
        //call function doHang(wrdList,sDisp) - play 1 game of Hangman
        dump(sDisp);
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

void iniWord(char words[][WRD_COL], bool avail[]) {
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
    
    for (int i=1; i<=MAX_WORD; i++)
        avail[i] = true;
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

void doHang(char dMatrix[][WRD_COL],char words[][DISP_COL]) {
    //define local variables
    char word[WRD_COL];
    //randomly pick a word
    //loop
    //   ask user for a letter (cvt. to uppercase)
    //   look for letters in word
    //   if found
    //      update partial word
    //   else
    //      update hangman
    //   display results
    //   if word completed
    //      "YOU WIN!"
    //      exit loop
    //   else if hangman complete
    //      "YOU LOSE!"
    //      exit loop
    //repeat     
    return;
}

void dump(char dMatrix[][DISP_COL]) {
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

