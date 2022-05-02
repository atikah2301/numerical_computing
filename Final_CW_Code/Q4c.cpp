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
valarray<long double> integrand(const valarray<long double>& X, const long double& b);
long double clenshaw(const long double& a, const long double& b, const int& n);
long double sum_for_clenshaw(const long double& theta, const int& n);

int main() {
    int a = 0; int b = 4; int n = 64;
    cout set << "exact value = " << I_exact << endl;
    long double I_clenshaw = clenshaw(a, b, n);
    cout set << "clenshaw = " << I_clenshaw << endl;
    cout set << "clenshaw error = " << I_exact - I_clenshaw << endl;
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
valarray<long double> integrand(const valarray<long double>& X, const long double& b) {
    // f(x) = sqrt((b-x)x)
    return pow(((long double)b - X)*X, 0.5L);
}

// Part (c) - Define Clenshaw-Curtis Quadrature Rule function
long double clenshaw(const long double& a, const long double& b, const int& n) {
    const long double q = (b - a) / 2.0L;
    const long double option_1 = q * 1.0L / (long double)(n * n);
    long double theta_i;
    long double r_i;
    long double option_2;

    valarray<long double> X(n); // x_i values: {0,0,..,0} for indices [0],[1],..[63]
    valarray<long double> F(n); // f(x_i) = f_i values
    valarray<long double> W(n); // weights

    for (int i = 0; i < n; i++) {
        theta_i = (long double)i * pi / (long double)(n - 1);
        X[i] = ((a + b) + ((a - b) * cos(theta_i))) * 0.5L;
        r_i = sum_for_clenshaw(theta_i, n);
        option_2 = q * 2.0L * (1.0L - r_i) / (long double)(n - 1);
        W[i] = (i == 0 || i == n-1) ? option_1 : option_2; // ternary operator to assign weights
    }
    F = integrand(X, b);

    return cdot(W, F);
}

// Part (c) - Define an auxiliary function for Clenshaw
long double sum_for_clenshaw(const long double& theta, const int& n) {
    const int length_of_sum = (n - 2) / 2; // = 31
    long double numerator;
    long double denominator;
    valarray<long double> summands(length_of_sum);

    for (int k = 1; k <= length_of_sum; k++) {
        numerator = (2.0L * cos(2.0L * (long double)k * theta));
        denominator = (4.0L * (long double)(k * k) - 1.0L);
//        cout set << "k = " << k << ", numerator = " << numerator << ", denominator = " << denominator << endl;
        summands[k-1] = numerator / denominator;
    }

//    cout << "summands = " ; print_valarray(summands);
//    cout << "number of summands = " << summands.size() << endl;

    return kahan_sum(summands);
}