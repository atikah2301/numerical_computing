#include <iostream> // for cout
#include <iomanip> // for setprecision()
#include <fstream>
#include <string>
#include <valarray> // for valarrays
#include <cmath> // for exp(), pow() - overloading to work for long doubles
#include <stdexcept>
#include <bits/stdc++.h>
#include <limits>

#define set << setprecision(10)
using namespace std;

// Function Declarations

void print_valarray(const valarray<long double>& A);
string tabulated_format(const long double& x, const int& decimals, const int& width);
string centre_align(const string& str, const int& width);
long double kahan_sum(const valarray<long double>& v);
long double mean(const valarray<long double>& v);
long double known_function(const long double& x);
valarray<long double> known_function(const valarray<long double>& X);
valarray<long double> known_function_2nd_derivatives(const valarray<long double>& X);
valarray<long double> finite_differences(const valarray<long double>& X);

int main()
{
    int N = 64; // x values numbered using i = 0, 1, .., N => valarrays should have N + 1 elements
    valarray<long double> X(N + 1); // x_i
    valarray<long double> F(N + 1); // f(x_i)
    valarray<long double> analytical_2nd_derivatives(N + 1); // f''(x_i)
    valarray<long double> numerical_2nd_derivatives(N + 1); // f''_i
    valarray<long double> errors(N + 1); // e_i

    // Calculate the values and store them
    for (int i = 0; i <= N; i++) {
        X[i] = (long double)((2 * i) - N) / (long double)N;
    }
    F = known_function(X);
    analytical_2nd_derivatives = known_function_2nd_derivatives(X);
    numerical_2nd_derivatives = finite_differences(X);
    errors = analytical_2nd_derivatives - numerical_2nd_derivatives;

    // print calculations
    cout << "X = " << endl; print_valarray(X); // x values should be equidistant and in the interval [-1, 1]
    cout << "F(X) = " << endl; print_valarray(F);
    cout << "F''(X) Numerical = " << endl; print_valarray(numerical_2nd_derivatives); // should be similar to analytical values
    cout << "F''(X) Analytical = " << endl; print_valarray(analytical_2nd_derivatives); // approx = 0, .., 14, .., -32, .., 14, .., 0
    cout << "Error = " << endl; print_valarray(errors);
    cout << "Average Error = " << mean(errors) << endl;

    // tabulate
    int width = 15;
    int decimals = 10;

    // set up the headings
    cout
        << centre_align("i", 5) << " | "
        << centre_align("x", 10) << " | " << centre_align("f(x)", width) << " | "
        << centre_align("f''(x) exact", width) << " | " << centre_align("f''(x) approx", width) << " | "
        << centre_align("error", width) << endl
        << string(width * 6, '-') << endl; // create the headings' underline

    // assign values from each valarray to their own columns
    for (int i = 0; i <= N; i++) {
        cout
            << tabulated_format(i, 0, 5) << " | "
            << tabulated_format(X[i], 5, 10) << " | "
            << tabulated_format(F[i], decimals, width) << " | "
            << tabulated_format(analytical_2nd_derivatives[i], decimals, width) << " | "
            << tabulated_format(numerical_2nd_derivatives[i], decimals, width) << " | "
            << tabulated_format(errors[i], decimals, width) << endl;
    }

}

// Function Definitions

void print_valarray(const valarray<long double>& A) {
    cout << "{ ";
    for (int i = 0; i < A.size(); i++){
        cout set << A[i] << ", ";
    }
    cout << " }" << endl;
}

string tabulated_format(const long double& x, const int& decimals, const int& width) {
    stringstream ss;
    ss << fixed << internal; // set the alignment of each number
    ss.precision(decimals); // set the number of decimal points on display for each number
    ss.fill(' '); // use space within single quotes to denote char instead of string
    ss.width(width); // set the width of the column for the table
    ss << x;

    return ss.str();
}

string centre_align(const string& str, const int& width) {
    stringstream ss;
    stringstream spaces;

    const int str_pad = width - str.size(); // set the size of the padding based on the desired width and string length
    for (int i = 0; i < str_pad / 2; ++i) {
        spaces << " "; // create padding
    }

    ss << spaces.str() << str << spaces.str(); // combine the spacing and output string
    if (str_pad % 2 != 0 && str_pad > 0) { // even out the padding
        ss << " ";
    }

    return ss.str();
}

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

long double mean(const valarray<long double>& A) {
    return kahan_sum(A) / (long double)A.size();
}

long double known_function(const long double& x) {
    long double x_sqr = pow(x, 2.0L);
    return exp(-16.0L * x_sqr);
}

valarray<long double> known_function(const valarray<long double>& X) {
    valarray<long double> X_sqr = pow(X, 2.0L);
    return exp(-16.0L * X_sqr);
}

valarray<long double> known_function_2nd_derivatives(const valarray<long double>& X) {
    valarray<long double> X_sqr = pow(X, 2.0L);
    return (1024.0L * X_sqr - 32.0L) * exp(-16.0L * X_sqr);
}

valarray<long double> finite_differences(const valarray<long double>& X) {
    int N = X.size() - 1; // = 63
    long double delta = 2.0L / (long double)N; // = 0.031746...
    long double delta_sqr = delta * delta; // = 0.00010078...
    valarray<long double> results(N + 1);
    // when i = 0, and when i = N
    results[0] = (known_function(X[2]) - 2.0L * known_function(X[1]) + known_function(X[0])) / delta_sqr;
    results[N] = (known_function(X[N]) - 2.0L * known_function(X[N-1]) + known_function(X[N-2])) / delta_sqr;
    // when i = 1, 2, .., N - 1
    for (int i = 1; i < N; i++) {
        results[i] = (known_function(X[i + 1]) - 2.0L * known_function(X[i]) + known_function(X[i - 1])) / delta_sqr;
    }
    return results;
}

