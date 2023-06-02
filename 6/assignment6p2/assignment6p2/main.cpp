//     Mohammed Alrashid
//     CS 2130 – Online
//     Assignment #6 part 2
//     Dr. Huson
//     Due: 11/08/2020
//     Filename: assignment6p2.cpp
//     Version: 1.0
// ---------------------------------------------------------------
// This program calculates Permutations, Combinations and Binomial
// installing coaxial cable
// ---------------------------------------------------------------

// Compiler directives
#include <iostream>
#include<math.h>
using namespace std;

// ---------------------------------------------------------------
// This function returns factorial of number
//
// Version 1.0
// ---------------------------------------------------------------
long long fact(long long n) {
    return (n == 1 || n == 0) ? 1 : fact(n - 1) * n ;
}

// ---------------------------------------------------------------
// This function returns the number of ways X objects can be drawn from N objects in a
// particular order.
// Version 1.0
// ---------------------------------------------------------------
long long permutation(long long N, long long X){
   
    return (fact(N)/fact(N-X));
}

// ---------------------------------------------------------------
// This function returns the number of ways X objects can be drawn from N objects
// ignoring the order in which the objects are drawn.
// Version 1.0
// ---------------------------------------------------------------
long long combination(long long N, long long X){
    return (fact(N)/(fact(N-X)*fact(X)));
}

// ---------------------------------------------------------------
// This function returns the binomial distribution probability of
// having X successes in N independent trials,
// where P is the probability of a success in each trial.
// Version 1.0
// ---------------------------------------------------------------
double binomial(long long N, double P, long long X){
    double result = combination(N,X) * pow(P,X) * pow(1 - P,N-X);
    
    return result;
}

// ---------------------------------------------------------------
// Main function
// Version 1.0
// ---------------------------------------------------------------
int main(){
    cout << "For Debug: Check for correctness of functions: " << endl;
    cout << "permutations:   P(10,4) = " << permutation(10,4) << endl;
    cout << "combinations:   C(10,4) = " << combination(10,4) << endl;
    cout << "binomial:  b(2, 12, 0.06) = " << binomial(2,12,0.06) << endl;
    
    cout << endl; // spacer
    cout << "Question 1:" << endl;
    cout << "a- Ways of presenting different prizes to 4 of 20 employees: "
    << permutation(20,4) << endl;
    cout << "b- Ways of presenting the same gifts to 4 of 20 employees: "
    << combination(20,4) << endl;
    
    cout << endl; // spacer
    cout << "Question 2: " << endl;
    cout << "Probability of at most one faulty bomb in sample size 10: "
    << binomial(10,0.06,0) + binomial(10,0.06,1) << endl;
    
    cout << endl;
    cout << "Question 3: " << endl;
    cout<<"Probability of at most two faulty hand grenades in 15: "
    << binomial(15,0.075,0) + binomial(15,0.075,1) + binomial(15,0.075,2) << endl;
    
    cout << endl;
    return 0;
}
