//     Mohammed Alrashid
//     CS 2130 – Online
//     Assignment #4
//     Dr. Huson
//     Due: 10/7/2020
//     Filename: bitstrings.cpp
//     Version: 1.0
//     Student discussions:  -
// ---------------------------------------------------------------
// This program allows to represent bit sets using bitwise and logical operations
// ---------------------------------------------------------------

// Compiler directives

#include <iostream>

using namespace std;

// constents
const int bitCount = 10; // range of integers (0 to 9)

//function declarations
int inputReq(int count);
void setPrint(int setA);
int setComp(int setA);
int setUnion(int setA, int setB);
int setInter(int setA, int setB);
int setDiff(int setA, int setB);
int setSym(int setA, int setB);


int main(int argc, const char * argv[]) {
 
    int count = 0; // numner of elements in set from user
    
    // Fill Set A from input
    cout << "Please enter the number of elements in set A: " << endl;
    cin >> count;
    int setA = inputReq(count); // add input to set A
    
    // Fill Set B from input
    cout << "Please enter the number of elements in set B: " << endl;
    cin >> count;
    int setB = inputReq(count); // add input to set B
    cout << endl;
    
    // Print Sets
    cout << "Input Sets:" << endl;
    setPrint(setA);
    setPrint(setB);
    cout << endl;
    
    // print Complement of setA
    int compSet = setComp(setA);
    cout << "Complement of A: ";
    setPrint(compSet);
    
    // print Union of setA and setB
    int unionSet = setUnion(setA, setB);
    cout << "Union of A and B: ";
    setPrint(unionSet);
    
    // print Intersection of setA and setB
    int interSet = setInter(setA, setB);
    cout << "Intersection of A and B: ";
    setPrint(interSet);
    
    // print Difference of setA and setB
    int diffSet = setDiff(setA, setB);
    cout << "Difference of A: ";
    setPrint(diffSet);
    
    // print Symmetric Difference of setA and setB
    int symSet = setSym(setA, setB);
    cout << "Symmetric of A: ";
    setPrint(symSet);
    
    
    return 0;
}

// ---------------------------------------------------------------
// This function gets user input and return the set
//
//
// Version 1.0
// ---------------------------------------------------------------

int inputReq(int count){
    int set = 0; // holds the value to be returened
    int input = 0; // holds the value user entered
    
    for(int i = 0; i < count; i++){
        cout << "Please Enter element " << i+1 << ": ";
        while (!(cin >> input) || (input < 0 || input >= bitCount)){
            cout << "Value entered is not allowed, please try again." << endl;
            cout << "Please Enter element " << i+1 << ": ";
            cin.clear();
            cin.ignore(132, '\n');
        }
        set = set | (1 << input);
    }
    return set;
}

// ---------------------------------------------------------------
// This function prints passed set as a parameter
//
//
// Version 1.0
// ---------------------------------------------------------------

void setPrint(int set){
    cout << "{ ";
    
    for(int i=0; i < bitCount; i++){
        if ( set & ( 1 << i))
            cout << i << " ";
    }
    cout << "}" << endl;
}
// ---------------------------------------------------------------
// This function returns the Complement of a set passed as parameter.
//
//
// Version 1.0
// ---------------------------------------------------------------

int setComp(int set){

    return ~set;
}

// ---------------------------------------------------------------
// This function returns the union of the passed
// sets as parameters.
//
// Version 1.0
// ---------------------------------------------------------------
int setUnion(int setA, int setB){
    
    return setA | setB;
}

// ---------------------------------------------------------------
// This function returns the intersection of the passed
// sets as parameters.
//
// Version 1.0
// ---------------------------------------------------------------

int setInter(int setA, int setB){

    return setA & setB;
}

// ---------------------------------------------------------------
// This function returns the Difference of the passed
// sets as parameters.
//
// Version 1.0
// ---------------------------------------------------------------

int setDiff(int setA, int setB){

    return setA & ~setB;
}

// ---------------------------------------------------------------
// This function returns the Symmetric Difference of the passed
// sets as parameters.
//
// Version 1.0
// ---------------------------------------------------------------

int setSym(int setA, int setB){
    
    return setA ^ setB; // XOR
}
