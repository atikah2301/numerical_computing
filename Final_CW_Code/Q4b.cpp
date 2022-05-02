#include <iostream> // for cout
#include <iomanip> // for setprecision()
#include <valarray> // for valarrays, .size(), *
#include <stdexcept> // for invalid_argument()

#define set << setprecision(20)
using namespace std;

// Global Constants

const long double pi = 3.1415926535897932385L;
const long double I_exact = pi * 2.0L;

// Function Declarations

void print_valarray(const valarray<long double>& A);
long double cdot(const valarray<long double>& A, const valarray<long double>& B);
long double kahan_sum(const valarray<long double>& v);
valarray<long double> integrand(const valarray<long double>& X);
long double simpson(const long double& a, const long double& b, const int& n);

int main() {
    int a = 0; int b = 4; int n = 64;
    cout set << "exact value = " << I_exact << endl;
    long double I_simpson = simpson(a, b, n);
    cout set << "simpson = " << I_simpson << endl;
    cout set << "simpson error = " << I_exact - I_simpson << endl;
}

// Function Definitions

void print_valarray(const valarray<long double>& A) {
    cout << "{ ";
    for (int i = 0; i < A.size(); i++){
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

// Calculate F values en masse from a valarray, X
valarray<long double> integrand(const valarray<long double>& X, const long double b) {
    // f(x) = sqrt((b-x)x)
    return pow(((long double)b - X)*X, 0.5L);
}

// Part (b) - Define Simpson's Rule function
long double simpson(const long double& a, const long double& b, const int& n) {
    const long double h = (b - a)/ (long double)n;
    valarray<long double> X(n); // x_i values: {0,0,..,0} for indices [0],[1],..[63]
    valarray<long double> F(n); // f(x_i) = f_i values
    valarray<long double> W(n); // weights

    for (int i = 0; i < X.size(); i++) {
        X[i] = a + h * (long double)i; // use step size h to calculate each x value

        if (i == 0 || i == n - 1) W[i] = (h * 17.0L) / 48.0L;
        else if (i == 1 || i == n - 2) W[i] = (h * 59.0L) / 48.0L;
        else if (i == 2 || i == n - 3) W[i] = (h * 43.0L) / 48.0L;
        else if (i == 3 || i == n - 4) W[i] = (h * 49.0L) / 48.0L;
        else W[i] = h;
    }
    F = integrand(X, b);

    // Test the output
//    cout << "N = " << F.size() << endl;
//    cout << "X = " << endl; print_valarray(X[slice(0,5,1)]);
//    cout << "W = " << endl; print_valarray(W);
//    cout << "F = " << endl; print_valarray(F[slice(0,5,1)]);

    return cdot(W, F);
}