#include <iostream> // for cout
#include <iomanip> // for setprecision()
#include <valarray> // for valarrays, .size(), *
#include <stdexcept> // for invalid_argument()
#include <random> // for random_device, mt19937 gen(), uniform_real_distribution

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
long double mv_monte(const long double a, const long double b, const int sample_size);
valarray<long double> uniform_randoms(const long double a, const long double b, int n);

int main() {
    int a = 0; int b = 4; int sample_size = 1000;
    cout set << "exact value = " << I_exact << endl;
    long double I_mv_monte = mv_monte(a, b, sample_size);
    cout set << "mv_monte = " << I_mv_monte << endl;
    cout set << "mv_monte error = " << I_exact - I_mv_monte << endl;
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

// Part (d) - Define mean value Monte Carlo function
long double mv_monte(const long double a, const long double b, const int sample_size) {
    const long double weight = (long double)(b - a) / (long double)sample_size;
    valarray<long double> X = uniform_randoms(a, b, sample_size);
    valarray<long double> F = integrand(X, b);

    return weight * kahan_sum(F);
}

// Part (d) - Define uniform random values, an auxiliary function for mv_monte()
valarray<long double> uniform_randoms(const long double a, const long double b, int n) {
    valarray<long double> rand_nums(n);
    // Seed with a real random value, if available
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<long double> unif(a, b);
    // Choose a random value uniformly between a and b
    for (int i = 0; i < n; i++){
        long double rand_num = unif(gen);
        rand_nums[i] = rand_num;
    }
    return rand_nums;
}