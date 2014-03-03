/* 
 * File:   main.cpp
 * Author: David W. Smith
 * Created on January 18, 2014, 12:20 PM
 * Savitch, 8th Edition - Chapter 2, Problem 15:
 * Calculate the speed of sound at 1 degree Celsius
 * intervals, for 5 iterations, using a user-supplied
 * start temperature. Use no looping constructs while
 * doing this. Formula to be used is v = 331.3 + 0.61 * Tc
 */

//System Variables
#include <iostream>
using namespace std;

//Global Constants
const float SPD_SND = 3.313e2;//Speed of sound in dry air at STP(Standard
                              //Temperature and Pressure - 0 degrees
                              //Celsius, 14.7 p.s.i.)
const float SAV_CST = 6.1e-1; //Constant supplied by Savitch - believe it to be
                              //derived from Taylor expansion of differential
                              //equation of sound.

//Function Prototypes

//Execution begins here
int main(int argc, char** argv) {
    //Define local variables
    float iTemp, dTemp, dSpdSnd;
    //Get user input
    cout << "Input temperature in degrees Celsius: ";
    cin >> iTemp;
    dTemp = iTemp;
    //Calculate speed of sound for 1st iteration
    dSpdSnd = SPD_SND + SAV_CST * dTemp;
    //Display 1st speed of sound approximation
    cout << "At (" << dTemp << ") degrees Celsius the speed of sound is "
         << dSpdSnd << " m/s." << endl;
    //Calculate speed of sound for 2nd iteration
    dTemp++;
    dSpdSnd = SPD_SND + SAV_CST * dTemp;
    //Display 2nd speed of sound approximation
    cout << "At (" << dTemp << ") degrees Celsius the speed of sound is "
         << dSpdSnd << " m/s." << endl;
    //Calculate speed of sound for 3rd iteration
    dTemp++;
    dSpdSnd = SPD_SND + SAV_CST * dTemp;
    //Display 3rd speed of sound approximation
    cout << "At (" << dTemp << ") degrees Celsius the speed of sound is "
         << dSpdSnd << " m/s." << endl;
    //Calculate speed of sound for 4th iteration
    dTemp++;
    dSpdSnd = SPD_SND + SAV_CST * dTemp;
    //Display 4th speed of sound approximation
    cout << "At (" << dTemp << ") degrees Celsius the speed of sound is "
         << dSpdSnd << " m/s." << endl;
    //Calculate speed of sound for 5th iteration
    dTemp++;
    dSpdSnd = SPD_SND + SAV_CST * dTemp;
    //Display 5th speed of sound approximation
    cout << "At (" << dTemp << ") degrees Celsius the speed of sound is "
         << dSpdSnd << " m/s." << endl;
    //Exit, stage right.
    return 0;
}

