/*
 * David W. Smith - 1/10/14
 * SavitchChap1Prob6 - Example 'Display 8' from textbook,
 * being used to generate a list of compilation errors.
*/
// Error messages
//====================================================================
//g++    -c -g -MMD -MP -MF "build/Debug/Cygwin_4.x-Windows/main.o.d" -o
//build/Debug/Cygwin_4.x-Windows/main.o main.cpp
//main.cpp:8:21: fatal error:  iostream: No such file or directory
// #include < iostream>
//                     ^
//compilation terminated.
//---------------------------------------------------------------------
//g++    -c -g -MMD -MP -MF "build/Debug/Cygwin_4.x-Windows/main.o.d" -o
//build/Debug/Cygwin_4.x-Windows/main.o main.cpp
//main.cpp:18:10: error: #include expects "FILENAME" or <FILENAME>
// #include iostream>
//          ^
//main.cpp: In function ‘int main(int, char**)’:
//main.cpp:30:5: error: ‘cout’ was not declared in this scope
//     cout << "Press return after entering a number.\n";
//     ^
//main.cpp:32:5: error: ‘cin’ was not declared in this scope
//     cin >> number_of_pods;
//     ^
//nbproject/Makefile-Debug.mk:66: recipe for target 
//'build/Debug/Cygwin_4.x-Windows/main.o' failed
//-----------------------------------------------------------------------
//omitting 'int' from main() - compiled successfully.
//-----------------------------------------------------------------------
//g++     -o dist/Debug/Cygwin_4.x-Windows/problem_6 build/Debug/
//Cygwin_4.x-Windows/main.o 
///usr/lib/gcc/x86_64-pc-cygwin/4.8.2/../../../../lib/libcygwin.a(libcmain.o):
//In function `main':
///usr/src/debug/cygwin-1.7.27-2/winsup/cygwin/lib/libcmain.c:39: undefined
//reference to `WinMain'
///usr/src/debug/cygwin-1.7.27-2/winsup/cygwin/lib/libcmain.c:39:(.text.
//startup+0x7e): relocation truncated to fit: R_X86_64_PC32 against undefined
//symbol `WinMain'
//collect2: error: ld returned 1 exit status
//nbproject/Makefile-Debug.mk:62: recipe for target
//'dist/Debug/Cygwin_4.x-Windows/problem_6.exe' failed
//------------------------------------------------------------------------
//g++    -c -g -MMD -MP -MF "build/Debug/Cygwin_4.x-Windows/main.o.d"
//-o build/Debug/Cygwin_4.x-Windows/main.o main.cpp
//main.cpp:57:10: error: expected initializer before ‘int’
// int main int argc, char** argv){
//          ^
//nbproject/Makefile-Debug.mk:66: recipe for target 'build/Debug/
//Cygwin_4.x-Windows/main.o' failed
//-------------------------------------------------------------------------
//g++    -c -g -MMD -MP -MF "build/Debug/Cygwin_4.x-Windows/main.o.d" -o
//build/Debug/Cygwin_4.x-Windows/main.o main.cpp
//main.cpp:64:10: error: expected initializer before ‘int’
// int main int argc, char** argv{
//          ^
//nbproject/Makefile-Debug.mk:66: recipe for target 'build/Debug/
//Cygwin_4.x-Windows/main.o' failed
//-------------------------------------------------------------------------
//g++    -c -g -MMD -MP -MF "build/Debug/Cygwin_4.x-Windows/main.o.d" -o
//build/Debug/Cygwin_4.x-Windows/main.o main.cpp
//main.cpp: In function ‘int main(int, char**)’:
//main.cpp:77:5: error: ‘couf’ was not declared in this scope
//     couf << "Press return after entering a number.\n";
//     ^
//nbproject/Makefile-Debug.mk:66: recipe for target 'build/Debug/
//Cygwin_4.x-Windows/main.o' failed
//-------------------------------------------------------------------------
//g++    -c -g -MMD -MP -MF "build/Debug/Cygwin_4.x-Windows/main.o.d" -o
//build/Debug/Cygwin_4.x-Windows/main.o main.cpp
//main.cpp: In function ‘int main(int, char**)’:
//main.cpp:77:5: error: ‘couf’ was not declared in this scope
//     couf << "Press return after entering a number.\n";
//     ^
//nbproject/Makefile-Debug.mk:66: recipe for target 'build/Debug/
//Cygwin_4.x-Windows/main.o' failed
//-------------------------------------------------------------------------
//g++    -c -g -MMD -MP -MF "build/Debug/Cygwin_4.x-Windows/main.o.d" -o 
//build/Debug/Cygwin_4.x-Windows/main.o main.cpp
//main.cpp: In function ‘int main(int, char**)’:
//main.cpp:111:13: error: expected ‘}’ at end of input
//     return 0;
//             ^
//nbproject/Makefile-Debug.mk:66: recipe for target 'build/Debug/
//Cygwin_4.x-Windows/main.o' failed
//====================================================================

//System Libraries
#include <iostream>
using namespace std;

//Global Constants

//Function Prototypes

//Execution Begins Here
int main (int argc, char** argv){
    //Declare local variables
    int number_of_pods, peas_per_pod, total_peas;
    //Get Input from user
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
    //Exit, stage right.
    return 0;
}