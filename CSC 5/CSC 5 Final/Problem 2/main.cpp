/* 
 * File:   main.cpp
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

//System Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global constants

//Structures

//Function definitions

//Execution begins here
int main(int argc, char** argv) {
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
    return 0;
}

