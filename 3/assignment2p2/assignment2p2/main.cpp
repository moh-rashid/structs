//     John Doe
//     CS 2130 – 7:30 am
//     Assignment #3 Part 2
//     Dr. Huson
//     Due: sep/23/1010
//     Filename: assignment3p2.cpp
//     Version: 1.0
// ---------------------------------------------------------------
// This program generates the sum-of-products expansion
// from a truth table representing a Boolean function in three variables
// ---------------------------------------------------------------

// Compiler directives
#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    
    int X[8],Y[8],Z[8],F[8],i;
    int count=0;
    cout<<"Enter eigt groups of four boolean values (0 or 1):" << endl;
    
    for(i=0; i < 8; i++){
        cin >> X[i] >> Y[i] >> Z[i] >> F[i]; // fill table with user input
        if(F[i] == 1)
            count++; // track the number of 1's
    }
    
    // print truth table
    cout<<endl; // spacer
    cout << setw(3) << "x" << setw(3) << "y" << setw(3) << "z" << setw(10) << "F(x,y,z)" << endl;
    for(i=0;i<8;i++){
        cout << setw(3) << X[i] << setw(3) << Y[i] << setw(3) << Z[i] << setw(10) << F[i] << endl;
    }
    
    // print output
    cout << endl << "F(x,y,z) = ";
    for(i=0; i < 8; i++){
        if(F[i] == 1){
            if(X[i] == 0)
                cout<<"x'"; // X complement
            if(X[i] == 1)
                cout<<"x"; // print x
            
            if(Y[i] == 0)
                cout<<"y'"; // Y complement
            if(Y[i] == 1)
                cout<<"y"; // print y
            
            if(Z[i] == 0)
                cout<<"z'"; // Z complement
            if(Z[i] == 1)
                cout<<"z"; // print z
            
            if(count-1 > 0){ // print +
                cout<<" + ";
                count--;
            }
        }
    }
    cout << endl;
    
    return 0;
}
