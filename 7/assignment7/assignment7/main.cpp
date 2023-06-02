//     Mohammed Alrashid
//     CS 2130 – Online
//     Assignment #7
//     Dr. Huson
//     Due: 12/02/2020
//     Filename: assignment7.cpp
//     Version: 1.0
// ---------------------------------------------------------------
// This program A Simple Finite State Machine
// ---------------------------------------------------------------
// Compiler directives
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// ---------------------------------------------------------------
// This Function determine the next state transition.
// Version 1.0
// ---------------------------------------------------------------
int nextState(int state, char symbol[30]) {
    char stri;
    int stateMove[4][3] = { {0, 0, 1},{0, 0, 2},{2, 3, 2},{2, 3, 2} }; // move array

    for (size_t i = 0; i < strlen(symbol); i++) {
        if (symbol[i] == 'a' || symbol[i] == 'b' || symbol[i] == 'c') {
            continue;
        }
        else
            return -1;
    }
    // set the state of each char
    for (size_t i = 0; i < strlen(symbol); i++) {
        stri = symbol[i] - 97;
        state = stateMove[state][stri];
    }
    return state;
}
// ---------------------------------------------------------------
// This Function that output true if input is acceptance state
// Version 1.0
// ---------------------------------------------------------------
bool accept(int state) {
    if (state == 3)
        return true;
    else
        return false;
}
// ---------------------------------------------------------------
// This Function that check string if valid
// Version 1.0
// ---------------------------------------------------------------
bool validString(string word) {
    int state = 0; 

    if (state == 3)
        return true;
     else
         return false;
}

// ---------------------------------------------------------------
// Main Function
// Version 1.0
// ---------------------------------------------------------------
int main() {
    int state = 0;
    char myInput[30];
    
    cout << "Enter string: ";
    cin.getline(myInput, 30);
    
    cout << "End State = " << nextState(state, myInput) << endl;
    cout << "Accepted: " << accept(nextState(state, myInput)) << endl;
    cout << "Valid String: " << validString(myInput) << endl;
    
    return 0;
}


