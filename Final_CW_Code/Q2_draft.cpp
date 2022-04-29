#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <valarray>
#include <cmath> // for pow()
#include <stdexcept> // for invalid_argument()
#include <bits/stdc++.h>
#include <limits>

#define set << setprecision(16)
using namespace std;

const long double pi = 3.1415926535897932385;
const long double expected = pi * pi / 6.0;

// Function Declarations
long double dot(const valarray<long double>& A, const valarray<long double>& B);
void print_valarray(const valarray<long double>& A);

int main()
{
    // Test dot()
    valarray<long double> A = {1, 2, 3};
    valarray<long double> B = {2, 3};
    cout << dot(A, B) << endl; // prints 20

    // Part (b)
//    int n = pow(10, 6);
//    cout << n << endl;
//    valarray<long double> A(0.0, n);
//    for (int i = 1; i <= A.size(); i++) {
//        A[i-1] = 1.0 / (long double)i;
//    }
//    long double A_squared = dot(A, A);
//    long double diff = A_squared - expected;
//    //print_valarray(A);
//    cout set << "A.A = " << A_squared << endl;
//    cout set << "pi*pi/6 = " << expected << endl;
//    cout set << diff << endl;
}

// Function Definitions

// Part (a)
long double dot(const valarray<long double>& A, const valarray<long double>& B) {
//    if (A.size() != B.size())
//        throw invalid_argument( "Valarrays must be of equal length" );
//    else {
//        long double product = 0.0;
//        for (int i = 0; i < A.size(); i++) {
//            product += A[i] * B[i];
//        }
//        long double product = (A*B).sum();
//        return product;
//    }
    return (A*B).sum();
}

void print_valarray(const valarray<long double>& A) {
    cout << "{ ";
    for (int i = 0; i < A.size(); i++) {
        cout set << A[i] << " ";
    }
    cout << " }" << endl;
}