/*
 * David W. Smith - 1/8/14
 * Problem #10 - Ask user for 1 character input, then display the
 * input character in the shape of the letter "C".
 */

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Define local variables
    char usrChar;
    //Get user input
    cout << "What character should I display? ";
    cin >> usrChar;
    //Output result
    cout << endl << "    " << usrChar << usrChar << usrChar << endl
         << "   " << usrChar << "   "<< usrChar << endl
         << "  " << usrChar << endl
         << " " << usrChar << endl
         << " " << usrChar << endl
         << " " << usrChar << endl
         << "  " << usrChar << endl
         << "   " << usrChar << "   "<< usrChar << endl
         << "    " << usrChar << usrChar << usrChar << endl << endl;
    //Exit, stage right.
    return 0;
}