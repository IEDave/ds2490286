/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 9, 2014, 2:43 PM
 * Gaddis, 7th Edition - Chapter 11, Problem 1: Write a program that uses a
 * structure named MovieData to store the following information about a movie:
 *     Title
 *     Director
 *     Year Released
 *     Running Time (in minutes)
 * The program should create two MovieData variables, store values in their
 * members, and pass each one, in turn, to a function that displays the
 * information that displays the information about the movie in a clearly
 * formatted manner.
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

//Global Constants

//Structures
struct MovieData {
    string title;
    string directr;
    short yrRlsd;
    short runTm;
};

//Function Prototypes
void prtMvie(MovieData);

//Execution begins here
int main(int argc, char** argv) {
    //Declare local variables
    MovieData movie1, movie2;
    //Populate structures
    movie1.title = "The Birds";
    movie1.directr = "Alfred Hitchcock";
    movie1.yrRlsd = 1963;
    movie1.runTm = 119;
    movie2.title = "Psycho";
    movie2.directr = "Alfred Hitchcock";
    movie2.yrRlsd = 1960;
    movie2.runTm = 108;
    //Display data using a function
    cout << "Movie #1:" << endl;
    cout << "=========" << endl;
    prtMvie(movie1);
    cout << endl << endl;
    cout << "Movie #2:" << endl;
    cout << "=========" << endl;
    prtMvie(movie2);
    //Exit, stage right!
    return 0;
}

void prtMvie(MovieData mov) {
    cout << "Movie - " << mov.title << endl;
    cout << "Directed by - " << mov.directr << endl;
    cout << "Year released - " << mov.yrRlsd << endl;
    cout << "Run Time - " << mov.runTm << " minutes" << endl;
}