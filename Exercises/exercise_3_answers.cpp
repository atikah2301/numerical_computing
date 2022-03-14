#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Week 2, Exercise 3

int main()
{
    // Q1 - Three types of type casting
    // int m1 = 5;
    // int n1 = 4;
    // cout << (double)m/(double)n << endl; // C-style casting
    // cout << double(m)/double(n) << endl; // Function style casting
    // cout << static_cast<double>(m)/static_cast<double>(n) << endl; // C++-style casting

    // Q2 - Problems with casting
    // double x = 3.42567890123;
    // int k = x; // truncation, k = 3
    // float y = x; // loss of precision, y = 3.425678
    // cout << k << endl;
    // cout << y << endl;
    
    // Q3 - Modular arithmetic
    // int a = 7; int n = 4; int q = a/n; int r = a%n;
    // cout << "for " << a << " divided by " << n << ":" << endl;
    // cout << r << " is the remainer, " << q << " is the quotient," << endl;

    // Q4 - Squaring user input
    // double userInput1;
    // cout << "Input: ";
    // cin >> userInput1;
    // cout << "Square: "<< userInput1*userInput1 << endl;
    
    
    // Q5 - Checking input parity using conditional statments
    // int userInput2;
    // cout << "Is even? "; 
    // cin >> userInput2;
    // if (userInput2 % 2 == 0)
    //     cout << "Yes, number is even" << endl;
    // else
    //     cout << "No, number is odd" << endl;
    
    // Q6 - Check a series of conditionals using user input
    // int userInput3; 
    // cout << "Check size of number: "; cin >> userInput3;
    // if (userInput3<0) cout << "Negative" << endl;
    // else if (userInput3<10) cout << "1 digit" << endl;
    // else if (userInput3<100) cout << "2 digits" << endl;
    // else if (userInput3<1000) cout << "3 digits" << endl;
    // else cout << "4 or more digits" << endl; 
    
    // Q7 - Loan repayment calculator
        // User input
    // double borrow; int days;
    // cout << "**LOAN REPAYMENT CALCULATOR**"  << endl;
    // cout << "Amount to borrow: "; cin >> borrow;
    // cout << "Days until repayment: "; cin >> days;
    //     // Calculate repayment
    // double rate = 0.01;
    // double repayment = borrow*(1+rate*double(days)) + 20.0;
    // cout << "You will repay: " << repayment << endl;
    //     // Calculate APR
    // double years = double(days)/365.0;
    // double apr = (pow(repayment/borrow, 1.0/years)-1.0)*100.0;
    // cout << "APR: " << apr << endl;
    
    // Q8 - Check validity of user input
    // int age; cout << "Enter your age: "; cin >> age;
    // if (!cin.good()) cout << "Invalid data type was given." << endl;
    // else if (age < 0) cout << "Age cannot be negative." << endl;
    // else cout << "You are " << age << " years old!" << endl;
    
}
