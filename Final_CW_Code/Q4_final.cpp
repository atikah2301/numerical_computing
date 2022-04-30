#include <iostream> // for cout
#include <iomanip> // for setprecision()
#include <fstream>
#include <string>
#include <valarray> // for valarrays, .size(), *
#include <cmath> // for cos()
#include <stdexcept> // for invalid_argument()
#include <bits/stdc++.h>
#include <limits>

#define set << setprecision(20)
using namespace std;

// Constants
const int a = 0;
const int b = 4;
const int n = 64;
const long double h = (long double)(b-a)/ (long double)n;
const long double q = (long double)(b-a)/ 2.0L;
const int sample_size = 10000;
const long double pi = 3.1415926535897932385L;
const long double I_exact = pi * 2.0;

// Function Declarations
void print_valarray(const valarray<long double>& A);
long double cdot(const valarray<long double>& A, const valarray<long double>& B);
long double kahan_sum(const valarray<long double>& v);
long double integrand(const long double x);
valarray<long double> integrand(const valarray<long double>& X);
long double trapezium(const int a, const int b, const int n, long double f(const long double));
long double simpson(const int a, const int b, const int n, long double f(const long double));
long double clenshaw(const int a, const int b, const int n, long double f(const long double));
long double clenshaw_w_sum(const long double theta);
// mv_monte

int main()
{
    // Testing

    long double I_trapezium = trapezium(a, b, n, integrand);
    long double I_simpson = simpson(a, b, n, integrand);
    long double I_clenshaw = clenshaw(a, b, n, integrand);
    // long double I_mv_monte = mv_monte();

    cout set << "exact value = " << I_exact << endl;

    cout set << "trapezium = " << I_trapezium << endl;
    cout set << "trapezium error = " << I_exact - I_trapezium << endl;

    cout set << "simpson = " << I_simpson << endl;
    cout set << "simpson error = " << I_exact - I_simpson << endl;

//    cout set << "clenshaw = " << I_clenshaw << endl;
//    cout set << "clenshaw error = " << I_exact - I_clenshaw << endl;

//    cout set << "MV monte carlo = " << I_mv_monte << endl;
//    cout set << "MV monte carlo error = " << I_exact - I_trapezium << endl;

    // Testing f(x) vs f(X) - both work as expected
    // at X = {0, 1, .., 6} we get F = { 0 1.7320508075688772936 2 1.7320508075688772936 0 nan nan  }
    for (int i = 0; i < 7; i++) {
        cout << "x = " << i << ", f(x) = " << integrand(i) << endl;
    }
    valarray<long double> X = {0, 1, 2, 3, 4, 5, 6};
}

// Function Definitions

void print_valarray(const valarray<long double>& A) {
    cout << "{ ";
    for (int i = 0; i < A.size(); i++) {
        cout set << A[i] << " ";
    }
    cout << " }" << endl;
}

// From Q2x, use for Part (a)'s and Part(c)'s calculation of cdot(W, F)
long double cdot(const valarray<long double>& A, const valarray<long double>& B) {
    if (A.size() != B.size())
        throw invalid_argument( "Valarrays must be of equal length" );
    else
        return kahan_sum(A*B);
}

// From Q2c, use to define cdot()
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

// Calculate individual values of f(x), the integrand
long double integrand(const long double x) {
    // f(x) = sqrt((b-x)x)
    return pow(((long double)b - x)*x, 0.5L);
}

// Calculate F values en masse from a valarray, X
valarray<long double> integrand(const valarray<long double>& X) {
    // f(x) = sqrt((b-x)x)
    return pow(((long double)b - X)*X, 0.5L);
}

// Part (a) - Define trapezium rule function
long double trapezium(const int a, const int b, const int n, long double f(const long double)) {
    valarray<long double> X(n); // x_i values: {0,0,..,0} for indices [0],[1],..[63]
    valarray<long double> F(n); // f(x_i) = f_i values
    valarray<long double> W(n); // weights

    for (int i = 0; i < X.size(); i++) {
        X[i] = (long double)a + h*(long double)i; // use step size h to calculate each x value
        W[i] = (i == 0 || i == n-1) ? h/2.0L : h; // ternary operator to assign weights
    }
    F = integrand(X);

    // Test the output
    cout << "N = " << F.size() << endl;
    cout << "X = " << endl; print_valarray(X[slice(0,5,1)]);
    cout << "W = " << endl; print_valarray(W);
    cout << "F = " << endl; print_valarray(F[slice(0,5,1)]);

    return cdot(W, F);
}

// Part (b) - Define simpson's rule function
long double simpson(const int a, const int b, const int n, long double f(const long double)) {
    valarray<long double> X(n); // x_i values: {0,0,..,0} for indices [0],[1],..[63]
    valarray<long double> F(n); // f(x_i) = f_i values
    valarray<long double> W(n); // weights

    for (int i = 0; i < X.size(); i++) {
        X[i] = (long double)a + h*(long double)i; // use step size h to calculate each x value

        if (i == 0 || i == n-1) W[i] = (h * 17.0L) / 48.0L;
        else if (i == 1 || i == n-2) W[i] = (h * 59.0L) / 48.0L;
        else if (i == 2 || i == n-3) W[i] = (h * 43.0L) / 48.0L;
        else if (i == 3 || i == n-4) W[i] = (h * 49.0L) / 48.0L;
        else W[i] = h;
    }
    F = integrand(X);

    // Test the output
//    cout << "N = " << F.size() << endl;
//    cout << "X = " << endl; print_valarray(X[slice(0,5,1)]);
//    cout << "W = " << endl; print_valarray(W);
//    cout << "F = " << endl; print_valarray(F[slice(0,5,1)]);

    return cdot(W, F);
}

// Part (c) - Define clenshaw-curtis quadrature rule function
long double clenshaw(const int a, const int b, const int n, long double f(const long double)) {
    return 0.0;
}
