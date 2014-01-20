/* 
 * File:   template.cpp
 * Author: David W. Smith
 * Created on January 19, 2014, 1:04 AM
 * Savitch, 8th Edition - Chapter 3, Problem 1
 * Computerized "Paper, Rock, Scissors"
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants
const char PAPER = 'P';
const char ROCK = 'R';
const char SCISSORS = 'S';

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define Local Variables
    char iUser1,iUser2;
    
    //User input - player #1
    cout << "Player 1: (P)aper,(R)ock,(S)cissors: ";
    cin >> iUser1;
    //User input - player #2
    cout << "Player 2: (P)aper,(R)ock,(S)cissors: ";
    cin >> iUser2;
    //convert lowercase to uppercase in user input
    if (iUser1 == 'p' || iUser1 == 'r' || iUser1 == 's')
        iUser1 = iUser1 - 'a' + 'A';
    if (iUser2 == 'p' || iUser2 == 'r' || iUser2 == 's')
        iUser2 = iUser2 - 'a' + 'A';
    //Compare User 1 to User2
    switch (iUser1) {
        case PAPER:
            switch (iUser2) {
                case PAPER:
                    cout << "Same - no winner";
                    break;
                case ROCK:
                    cout << "Paper covers Rock - Player 1 wins!";
                    break;
                case SCISSORS:
                    cout << "Scissors cuts Paper - Player 2 wins!";
                    break;
            }
            break;
        case ROCK:
            switch (iUser2) {
                case PAPER:
                    cout << "Paper covers Rock - Player 2 wins!";
                    break;
                case ROCK:
                    cout << "Same - no winner.";
                    break;
                case SCISSORS:
                    cout << "Rock breaks Scissors - Player 1 wins!";
                    break;
            }
            break;
        case SCISSORS:
            switch (iUser2) {
                case PAPER:
                    cout << "Scissors cuts Paper - Player 1 wins!";
                    break;
                case ROCK:
                    cout << "Rock breaks Scissors - Player 2 wins!";
                    break;
                case SCISSORS:
                    cout << "Same - no winner";
                    break;
            }
            break;
        default:
            if (iUser2 == PAPER || iUser2 == ROCK || iUser2 == SCISSORS)
                cout << "Player 1 - invalid input - Player 2 wins!";
            else
                cout << "Both players have invalid inputs - no winner.";
    }
    //Exit, stage right
    return 0;
}

