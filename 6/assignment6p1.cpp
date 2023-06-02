//     Mohammed Alrashid
//     CS 2130 – Online
//     Assignment #6 Part 1
//     Dr. Huson
//     Due: 11/08/2020
//     Filename: assignment6p1.cpp
//     Version: 1.0
// ---------------------------------------------------------------
// This program determine if a value is prime number
// and calculates the greatest common divisor  of 2 values.
// ---------------------------------------------------------------
// Compiler directives
#include<iostream>
using namespace std;

// ---------------------------------------------------------------
// This Function determine if a value is prime number and return boolean
// Version 1.0
// ---------------------------------------------------------------
bool isPrime(int n){
    for(int i = 2; i < n; i++){
        if(n % i == 0)
            return false; // return false if not prime
    }
    return true; // return true if prime
}

// ---------------------------------------------------------------
// This Function calculates the greatest common divisor  of 2 values.
// Version 1.0
// ---------------------------------------------------------------
int gcd(int n1, int n2){
    int gcd = 0;
    for(int i = 1; i <= n1 && i <= n2; i++){  //loops from first to last to find greatest divisor
        if(n1 % i == 0 && n2 % i == 0) //it gives the last divisor which divides both values
            gcd = i;
    }
    return gcd;
}

// ---------------------------------------------------------------
// This Function check input value for errors and limit
// Version 1.0
// ---------------------------------------------------------------
int intCheck(){
    int num = 0;
    while((!(cin >> num)) || num <= 0 || num > 100000){
        cout << "ERROR! Please enter a value from 1 to 100000: " << endl;
        cin.clear();
        cin.ignore(123, '\n');
    }
    return num;
}

// ---------------------------------------------------------------
// Main function
// Version 1.0
// ---------------------------------------------------------------
int main(){
    // variables
    int n1,n2,r;
    string result;
    
    // take input from user
    cout << "enter first integer: ";
    n1 = intCheck(); // check for error
    cout << "enter second integer: ";
    n2 = intCheck(); // check for error
    
    cout << endl; // spacer
    
    // Print result for first number
    result = (isPrime(n1)) ? " is a prime number." : " is not a prime number.";
    cout << n1 << result << endl;
    // Print result for second number
    result = (isPrime(n2)) ? " is a prime number." : " is not a prime number.";
    cout << n2 << result << endl;
    
    // print result for GCD
    r = gcd(n1,n2);
    cout << "The gcd(" << n1 << ", " << n2 << ") is " << r << endl;
    
    cout << endl; // spacer
    
    return 0;
}
