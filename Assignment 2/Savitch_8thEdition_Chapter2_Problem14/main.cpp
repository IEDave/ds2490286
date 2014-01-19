/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 18, 2014, 10:57 PM
 * Savitch, 8th Edition - Chapter 2, Problem 14
 * This program play a game of "Mad Lib" with the user.
 * It takes in various inputs, and substitutes them into a letter
 * explaining what happened to the user's homework. The story is
 * then printed out on the user's screen. No looping constructs are to be used.
 */

//System Libraries
#include <iostream>
#include <string>
using namespace std;

//Global Constants
const unsigned int MAX_NUM = 120;
const unsigned int MIN_NUM = 100;
//Function Prototypes

//Execution starts here
int main(int argc, char** argv) {
    //Define Local Variables
    string iProfNm,iMyName,iFood,iAdject,iColor,iAnimal;
    unsigned int iNumber;
    //Get user inputs
    cout << "Enter the first or last name of your instructor: ";
    cin >> iProfNm;
    cout << "Enter your name: ";
    cin >> iMyName;
    cout << "Enter a food: ";
    cin >> iFood;
    cout << "Enter a number between 100 and 120: ";
    cin >> iNumber;
    cout << "Enter an adjective: ";
    cin >> iAdject;
    cout << "Enter a color: ";
    cin >> iColor;
    cout << "Enter an animal: ";
    cin >> iAnimal;
    //Generate output
    if ( iNumber >= MIN_NUM && iNumber <= MAX_NUM ) {
        cout << endl << endl << "Dear Instructor " << iProfNm << "," << endl;
        cout << endl << "I am sorry that I am unable to turn in my homework "
             << "at this time. First," << endl;
        cout << "I ate a rotten " << iFood << ", which made me turn " << iColor
             << " and extremely ill. I" << endl;
        cout << "came down with a fever of " << iNumber << ". Next, my "
             << iAdject << " pet" << endl;
        cout << iAnimal << " must have smelled the remains of the " << iFood
             << " on my homework," << endl;
        cout << "because he ate it. I am currently rewriting my homework"
             << " and hope you" << endl;
        cout << "will accept it late." << endl << endl << endl;
        cout << "Sincerely," << endl;
        cout << iMyName << endl;
    } else {
        cout << "Number " << iNumber << " is out of range. No output." << endl;
    }
    //Exit, stage right
    return 0;
}


