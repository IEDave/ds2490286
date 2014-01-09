/*
 * David W. Smith - 1/8/14
 * Problem #5 - Program to get 2 integers from the user,
 * then print the sum and product of the 2 integers.
*/

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Declare local variables
    int usrInt1,usrInt2;
    //Get Input from user
    cout << "Enter 1st integer: ";
    cin >> usrInt1;
    cout << "Enter 2nd integer: ";
    cin >> usrInt2;
    //Output result - sum and product of user input.
    cout << "The sum of (" << usrInt1 << ") and (" << usrInt2 << ") is: "
         << usrInt1 + usrInt2 << endl;
    cout << "The product of (" << usrInt1 << ") and (" << usrInt2 << ") is: "
         << usrInt1 * usrInt2 << endl;
    //Exit, stage right.
    return 0;
}