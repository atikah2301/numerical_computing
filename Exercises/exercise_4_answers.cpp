#include <iostream>
#include <cmath>
#include <algorithm> // To use min and max functions

using namespace std;

// Week 2, Exercise 4
// * = Answers to submit

int main()
{
    // Q3* - Sum of reciprocal squares
    
    // Using a for loop, we keep adding values to the variable "sum"
    // The loop terminates after the input value of "n" is reached
    // We then comparet the value of "sum" to "limit"
    // Used double for all variables involved in arithmetic
    
    double sum = 0;
    int n; cout << "Number of steps = "; cin >> n;
    for (int i=1; i<=n; i++) {
        sum += 1.0/(i*i);
        //cout << sum << ", ";
    }
    cout << "\nSum of the first " << n << " 1/n^2 is " << sum << endl;
    double pi = 3.14159265358979;
    double limit = pi*pi/6.0;
    cout << "The limit as # of steps goes to infinity is " << limit << endl;
    

    // When n = 1000, the sum is 1.64393, while the limit is 1.64493
    // This close approximation supports the validity of Euler's formula
    
    
    // Q4* - Fibonacci numbers and successive quotients, iteratively
    
    // Initialise variables with the first three fibonacci numbers
    // Use a while loop to keep checking that the results are less than 1000
    // Iteratively add successive values and reassing them to existing variables
    
    int f0 = 0; int f1 = 1; int f2 = f1 + f0;
    cout << f0 << ", " << f1 << ", ";
    while (f2 < 1000) {
        cout << f2 << ", ";
        f0 = f1;
        f1 = f2;
        f2 = f1 + f0;
    }
    
    
    // Use a long double since numbers could get quite long,
    // and will be used in arithmetic.
    // I tried different numbers of iterations for the loop,
    // and found that even just 20 was enough, but the code goes up to 100,
    // just to be sure.
    
    long double f0 = 0.0; long double f1 = 1.0; long double f2 = f1 + f0;
    for (int i = 1; i <= 100; i++) {
        cout << i << ": " << f2 << " / " << f1 << " = " << f2/f1 << endl;
        f0 = f1;
        f1 = f2;
        f2 = f1 + f0;
    }
    long double fibonacciLimit = (sqrt(5.0)+1.0)/2.0;
    cout << "From the 15th succesive quotient onwards, we get 1.61803" << endl;
    cout << "The limit to infinity is " << fibonacciLimit << endl;
    
    // The expected and approximated limits are equal when truncated to 5 d.p.,
    // which verifies the expression for the golden ratio
    
    
    
    // Q5* - Collatz conjecture
    
    // Check that the value of "a" is a positive integer before running the loop
    // Used int data type to truncate any decimal values given as input
    // Made sure to cast "a" to an int before using modulus operator
    // Again used a while loop so that the loop could terminate when a reaches 1
    
    int a; cin >> a; 
    if (a < 1.0) cout << "a must be a positive integer\n";
    else {
        while (a != 1.0) {
            if (int(a) % 2 == 0)
                a /= 2.0;
            else
                a = 3.0*a + 1.0;
            cout << int(a) << " ";
        }
    }
	
	
	// Q6 - Finding greatest common divisor
    
    int a; cout << "a = "; cin >> a;
    int b; cout << "b = "; cin >> b;
    
    // Euclid's algorithm
    
    // while (b != 0) {
    //     int temp = b;
    //     b = a % b;
    //     a = temp;
    // }
    // cout << "gcd is "<< a;
    
    // Naive method - assume a >= b
    
    if (a % b == 0) {
        cout << a << " is a multiple of " << b;
        cout << ", so gcd is " << b;
    }
    else {
        int gcd = 1;
        for (int i = 1; i < b/2; i++)  {
            if (a % i == 0 && b % i ==0)
                gcd = i;
        }
        cout << "gcd is " << gcd;
    }
	
	
}
