//     Mohammed Alrashid
//     CS 2130 – Online
//     Assignment #1
//     Dr. Huson
//     Due: 09/02/2020
//     Filename: cs2130A1.cpp
//     Version: 1.0
//     Student discussions:
// ---------------------------------------------------------------
// This program generates 1 Million dice rolls and calculates percentage of snake eye, double, seven rolls.
// ---------------------------------------------------------------

// Do the results agree with your intuition about the probabilities of certain values appearing on two fair dice?
// Yes, for each roll on first die, there is 6 possible outcomes for die 2. that makes the total possible outcomes 36 combinations.

// for snake eyes, there is only 1 for 36 possible outcomes. which makes it 1/36 = 2%
// for sevens and doubles, there are 6 out of 36 possible combinations. which makes it 6/36 = 1/6 = 16%

// ---------------------------------------------------------------


// Compiler directives
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // variables
    int rolls = 1000000;
    int snakeEyes = 0;
    int doubles = 0;
    int sevens = 0;
    int dice1, dice2;
    srand( static_cast<unsigned int>(time(nullptr))); // initialize random seed
    
    for(int i=0; i<rolls; i++){
        // generate 2 dice rolls
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        
        if(dice1 == dice2){
            if (dice1==1)
                snakeEyes++; // snake eyes condition
            else
                doubles++; // doubles condition
        }
        if(dice1+dice2 == 7)
            sevens++; // sevens condition
    }
    
    // Output
    cout << "CS 2130 Fall 2020 - Mohammed Alrashid" << endl;
    cout << "Snake Eyes occurred: " << static_cast<double>(snakeEyes)/rolls*100 << "% Percent of the time." << endl;
    cout << "Doubles occurred: " << static_cast<double>(doubles)/rolls*100<< "% Percent of the time." << endl;
    cout << "Sevens occurred: " << static_cast<double>(sevens)/rolls*100 << "% Percent of the time." << endl;
    
    return 0;
}
