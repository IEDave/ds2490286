/*
 * David W. Smith - 1/9/14
 * SavitchChap1Prob2 - Example 'Display 8' from textbook,
 * modified to be a bit more "user friendly". Again, resolving conflict
 *  between the book & established shop standards in the class.
*/

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv){
    //Declare local variables
    int number_of_pods, peas_per_pod, total_peas;
    //Get Input from user
    cout << "Hello!" << endl;
    cout << "Press return after entering a number.\n";
    cout << "Enter the number of pods:\n";
    cin >> number_of_pods;
    cout << "Enter the number of peas in a pod:\n";
    cin >> peas_per_pod;
    //Calculate total number of peas based on user input.
    total_peas = number_of_pods * peas_per_pod;
    //Output result
    cout << "If you have ";
    cout << number_of_pods;
    cout << " pea pods\n";
    cout << "and ";
    cout << peas_per_pod;
    cout << " peas in each pod, then\n";
    cout << "you have ";
    cout << total_peas;
    cout << " peas in all the pods.\n";
    cout << "Good-bye!\n";
    //Exit, stage right.
    return 0;
}

