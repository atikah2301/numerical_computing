#include <iostream> // for cout
#include <iomanip> // for setprecision()
#include <valarray> // for valarrays, *, and .size()
#include <cmath> // for pow()
#include <stdexcept> // for invalid_argument()

#define set << setprecision(25)
using namespace std;

// Constants
const int n = pow(10, 6);
// Constants for Part (b) only
const long double pi = 3.1415926535897932385L;
const long double expected_1 = pi * pi / 6.0L;
// Constants for Part (c) only
const long double c = 0.1L;
const long double expected_2 = (long double)n * c * c;

// Function Declarations
void print_valarray(const valarray<long double>& A);
long double dot(const valarray<long double>& A, const valarray<long double>& B);
long double cdot(const valarray<long double>& A, const valarray<long double>& B);
long double kahan_sum(const valarray<long double>& v);

// Part (d) - Function Object

int main()
{
    // Part(a) - Test that dot() returns the inner product

    valarray<long double> A_test = {1, 2, 3};
    valarray<long double> B_test = {2, 3, 4};
    cout set << dot(A_test, B_test) << endl; // prints 20, as expected

    // Part (b) - Use dot() to approximate the sum of squared reciprocals

    // First set up the valarray A
    valarray<long double> A(0.0, n);
    for (int i = 1; i <= A.size(); i++) {
        A[i-1] = 1.0 / (long double)i;
    }
    // Test A and A*A have the expected values by printing them for n=10
    print_valarray(A);
    print_valarray(A*A);
    // Calculate 1/(i^2) using dot(), and get the error between our calculation and the expected value of (pi^2)/6
    long double A_squared = dot(A, A);
    long double diff = A_squared - expected_1;
    // Print the final results
    cout set << "A.A = " << A_squared << endl;
    cout set << "pi*pi/6 = " << expected_1 << endl;
    cout set << "difference = "<< diff << endl;

    // Part (c) - Use cdot() and dot(), compute then print values and errors

    valarray<long double> C(c, n);
    long double C_dot = dot(C, C);
    long double C_cdot = cdot(C, C);
    cout set << "exact value, n*c*c = " << expected_2 << endl;
    cout set << "dot(C, C) = " << C_dot << endl;
    cout set << "cdot(C, C) = " << C_cdot << endl;
    cout set << "dot error = " << abs(C_dot - expected_2) << endl;
    cout set << "cdot error = " << abs(C_cdot - expected_2) << endl;

}
// Function Definitions

void print_valarray(const valarray<long double>& A) {
    cout << "{ ";
    for (int i = 0; i < A.size(); i++) {
        cout set << A[i] << " ";
    }
    cout << " }" << endl;
}

// Part (a) - Define dot()
long double dot(const valarray<long double>& A, const valarray<long double>& B) {
    if (A.size() != B.size())
        throw invalid_argument( "Valarrays must be of equal length" );
    else
        return (A*B).sum();
}

// Part (c) - Define cdot()
long double cdot(const valarray<long double>& A, const valarray<long double>& B) {
    if (A.size() != B.size())
        throw invalid_argument( "Valarrays must be of equal length" );
    else
        return kahan_sum(A*B);
}

// Part (c) - Define compensated Kahan summation
long double kahan_sum(const valarray<long double>& v) {
    long double sum = 0.0;
    long double c = 0.0;
    long double y;
    long double t;
    for(int i = 0; i < v.size(); ++i) {
        y = v[i] - c;
        t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}