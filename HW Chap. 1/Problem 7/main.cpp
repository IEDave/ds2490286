/*
 * David W. Smith - 1/8/14
 * Problem #7 - Display fun message with "*" borders, followed by 2 blank lines
 * and the text string "Computer Science is Cool Stuff!"
*/

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Output result
    cout << "*******************************" << endl
         << endl
         << "    CCC       SSSS        !!" << endl
         << "   C   C     S    S       !!" << endl
         << "  C         S             !!" << endl
         << " C           S            !!" << endl
         << " C            SSSS        !!" << endl
         << " C                S       !!" << endl
         << "  C                S      !!" << endl
         << "   C   C     S    S" << endl
         << "    CCC       SSSS        00" << endl
         << endl
         << "********************************" << endl
         << endl
         << endl
         << "Computer Science is Cool Stuff!\n";
    //Exit, stage right.
    return 0;
}

