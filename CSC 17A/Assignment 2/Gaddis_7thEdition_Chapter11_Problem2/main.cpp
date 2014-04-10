/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on April 9, 2014, 3:13 PM
 * Gaddis, 7th Edition - Chapter 11, Problem 2: Modify the Movie Data program
 * written for Programming Challenge 1 to include two difficult two additional
 * members that hold the movie's production costs & first-year revenues. Modify
 * the function that displays the movie data to display the title, director,
 * release year, running time, and first year's profit or loss.
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Global Constants

//Structures
struct MovieData {
    string title;
    string directr;
    short yrRlsd;
    short runTm;
    int prdCost;
    int yr1Rev;
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
    movie1.prdCost = 3300000;
    movie1.yr1Rev = 11403529;
    //
    movie2.title = "Psycho";
    movie2.directr = "Alfred Hitchcock";
    movie2.yrRlsd = 1960;
    movie2.runTm = 108;
    movie2.prdCost = 806948;
    movie2.yr1Rev = 15000000;
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
    cout << "First year profit - $" << mov.yr1Rev - mov.prdCost << endl; 
}