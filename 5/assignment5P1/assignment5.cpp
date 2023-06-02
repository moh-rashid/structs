//     Mohammed Alrashid
//     CS 2130 – Online
//     Assignment #5 Part 1
//     Dr. Huson
//     Due: 10/21/20
//     Filename: assignment5.cpp
//     Version: 1.0
// ---------------------------------------------------------------
// this program asks user to input 3X3 matrix and calculates
// different Boolean matrix functions.
// ---------------------------------------------------------------

// Compiler directives
#include<iostream>
using namespace std;

// ---------------------------------------------------------------
// This function takes set of pairs as input from user and stores it
// in matrix parameter
// Version 1.0
// ---------------------------------------------------------------
void matrixInput(int X[][3]){
    int a,b; // order pair variables
    while(true){
        // Error checking
        while((!(cin >> a >> b)) || ((a == 0 && b != 0) || (b == 0 && a != 0)) || (a < 0  || a > 3) || (b < 0  || b > 3)){
            cout << "ERROR: you have entered an invalid value! Please enter a value from set F = {1,2,3}" << endl;
            cin.clear();
            cin.ignore(123, '\n');
        }
        // terminate if "0 0"
        if(a == 0 && b == 0){
            cout << endl;
            break;
        }
        X[a-1][b-1] = 1; // set as 1
    }
}

// ---------------------------------------------------------------
// This Function take a matrix as parameter and print it to
// a console window.
// Version 1.0
// ---------------------------------------------------------------
void matrixPrint(int X[][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << X[i][j] <<' ';
        }
        cout << endl;
    }
    cout << endl;
}

// ---------------------------------------------------------------
// This function perfroms A meet B and stores result in matrix C
//
// Version 1.0
// ---------------------------------------------------------------
void matrixMeet(int A[][3], int B[][3], int C[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j] = A[i][j] && B[i][j];
        }
    }
}

// ---------------------------------------------------------------
// This function perfroms A join B and stores result in matrix C
//
// Version 1.0
// ---------------------------------------------------------------
void matrixJoin(int A[][3], int B[][3], int C[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j] = A[i][j] || B[i][j];
        }
    }
}

// ---------------------------------------------------------------
// This function perfroms A product B and stores result in matrix C
//
// Version 1.0
// ---------------------------------------------------------------
void matrixProduct(int A[][3], int B[][3], int C[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            int sum=0;
            for(int k=0;k<3;k++){
                sum += A[i][k]*B[k][j];
            }
            C[i][j]=(sum>0);
        }
    }
}

// ---------------------------------------------------------------
// This function perfroms complement of B and stores result in matrix C
//
// Version 1.0
// ---------------------------------------------------------------
void matrixComplement(int A[][3], int B[][3], int C[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[i][j] = !A[i][j];
        }
    }
}

// ---------------------------------------------------------------
// This function perfroms transpose of B and stores result in matrix C
//
// Version 1.0
// ---------------------------------------------------------------
void matrixTranspose(int A[][3], int B[][3], int C[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            C[j][i] = A[i][j];
        }
    }
}

void transitiveClosure(int X[][3], int C[][3]){
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            C[i][j] = X[i][j];
        }
    }
    for (int k = 0; k < 3; k++){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (C[i][k] + C[k][j] < C[i][j])
                    C[i][j] = C[i][k] + C[k][j];
            }
        }
    }
}

// ---------------------------------------------------------------
// MAIN function
//
// Version 1.0
// ---------------------------------------------------------------
int main(){
    // Define matrix arrays
    int A[3][3] = {{0,},}, B[3][3] = {{0,},}, C[3][3] = {{0,},};
    
    
    // Get matrix A input from user
    cout << "Please input the ordered pairs for matrix A: " << endl;
    matrixInput(A);
    // Get matrix B input from user
    cout << "Please input the ordered pairs for matrix B: " << endl;
    matrixInput(B);
    
    
    // Matrix Print
    cout << "A =" << endl;
    matrixPrint(A);
    cout << "B =" << endl;
    matrixPrint(B);
    
    
    // Meet Test
    matrixMeet(A, B, C);
    cout<<"A meet B =" << endl;
    matrixPrint(C); //prints C
    
    
    //Join tests
    matrixJoin(A, B, C);
    cout<<"A join B =" << endl;
    matrixPrint(C);
    
    
    //Product test
    matrixProduct(A, B, C);
    cout<<"A product B =" << endl;;
    matrixPrint(C);
    
    
    //Complement test
    matrixComplement(A, B, C);
    cout<<"Complement of A =" << endl;
    matrixPrint(C);
    
    
    //Transpose test
    matrixTranspose(A, B, C);
    cout<<"Transpose of A =" << endl;
    matrixPrint(C);
    
    // Transitive Closure
    transitiveClosure(A, C);
    cout<<"Transitive Closure of A =" << endl;
    matrixPrint(C);
    
    cout << endl;
    
    return 0;
}
