//     Mohammed Alrashid
//     CS 2130 – Online
//     Assignment #4 Part 2
//     Dr. Huson
//     Due: 10/07/2020
//     Filename: functions.cpp
//     Version: 1.0
// ---------------------------------------------------------------
// This program determine whether a function is a valid function, one-to-one,
// onto, and/or a bijection
// ---------------------------------------------------------------

// Compiler directives
#include <iostream>

using namespace std;


// ---------------------------------------------------------------
// This Function check if function is Valid.
// "Valid function: no x value has two y values and all x and y values are in
// the Domain and Range"
// Version 1.1
// ---------------------------------------------------------------
bool isValid(int function[][2], int size) {
    
    bool tempSet[6] = {false}; // temp bool array to track duplication
    
    for (int i = 0; i < size; i++) {
        
        // Range and domain check
        if (function[i][0] < 1 || function[i][0] > 5) // check if set X is in range
            return false;
        
        if (function[i][1] < 1 || function[i][1] > 5) // check if set Y is in range
            return false;
        
        
        // return false if an x value has two y values
        if (tempSet[function[i][0]]) //
            return false;
        
        // if x value hasn't been used, set its place in bool array to true.
        else
            tempSet[function[i][0]] = true;
    }
    
    return true; // return true if function is valid
}

// ---------------------------------------------------------------
// This Function check if function is one-to-one.
// "One-to-one: No y value has more than one x that maps to it"
// (e.g., f(3) = 2 and f(4) = 2 is NOT one-to-one)
// Version 1.0
// ---------------------------------------------------------------
bool isOneToOne(int function[][2], int size) {
    
    
    bool tempSet[6] = {false}; // temp bool array to track duplication
    
    // loop through the bool array, and set all used y values to true.
    for (int i = 0; i < size; i++) {
        
        // return false if any y value has more than one x that maps to it.
        if (tempSet[function[i][1]])
            return false;
        
        // if y value hasn't been used, set its place in bool array to true.
        else
            tempSet[function[i][1]] = true;
    }
    
    return true; // return true if on-to-one
}


// ---------------------------------------------------------------
// This Function checks if function is Onto.
// "for every y in the Range, there is at least one x such that f(x) = y"
// Version 1.0
// ---------------------------------------------------------------
bool isOnto(int function[][2], int size) {
    
    bool tempSet[6] = {false}; // temp bool array to track duplication
    
    for (int i = 0; i < size; i++) {
        tempSet[function[i][1]] = true; // set all values used in y to true inside bool array.
    }
    
    // check if all the y values were used or not
    for (int i = 1; i < 6; i++) {
        
        if (!tempSet[i]) // return false if any y value doesn't have at least one x
            return false;
    }
    
    return true; // return true if Onto
}

// ---------------------------------------------------------------
// Main function
//
// Version 1.0
// ---------------------------------------------------------------

int main() {
    
    // Ask user for the number of ordered pairs.
    int size = 0;
    cout << "How many ordered pairs? " << endl;
    // error handling
    while(!(cin >> size)){
        cout << "ERROR: a number must be entered: " << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    
    // function array declaration
    int function[size][2];
    

    // Ask users for inputs and add values to arrays
    cout << "Please enter one pair per line, "
            "and seprate values by space: " << endl;
    
    for (int i = 0; i < size; i++) {
        // Error handling
        while(!(cin >> function[i][0] >> function[i][1])){
            cout << "ERROR: a number must be entered: " << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }
    }
    
    // print function
    cout << "\n\nFunction described by: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "f(" << function[i][0] << ") = " << function[i][1] << endl;
    }
    
    cout << endl;
    
    // check if function is valid
    if (isValid(function, size)) {
        
        cout << "This function is a valid function." << endl;
        
        // if valid, continue checking other cases...
        
        
        // check if function is one to one
        if (isOneToOne(function, size))
            cout << "This function is a one-to-one function." << endl;
        else
            cout << "This function is not a one-to-one function." << endl;
        
        
        // check if fucntion is onto
        if (isOnto(function, size))
            cout << "This function is onto." << endl;
        else
            cout << "This function is not onto." << endl;
        
        
        // checck if function is bijection
        if (isOneToOne(function, size) && isOnto(function, size))
            cout << "This function is a bijection." << endl;
        else
            cout << "This function is not a bijection." << endl;
    }
    
    // if function not valid
    else {
        cout << "This function is not a valid function." << endl;
    }
    cout << endl; // spacer
    
    return 0;
}
