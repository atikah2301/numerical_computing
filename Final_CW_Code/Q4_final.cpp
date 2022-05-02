#include <iostream> // for cout
#include <iomanip> // for setprecision()
#include <valarray> // for valarrays, .size(), *
#include <stdexcept> // for invalid_argument()
#include <random> // for random_device, mt19937 gen(), uniform_real_distribution

#define set << setprecision(20) // using shorthand for convenience
using namespace std;

// Global Constants

const long double pi = 3.1415926535897932385L; // as defined in Q2
const long double I_exact = pi * 2.0L; // exact value of the integral

// Function Declarations

// Used in all parts of question
void print_valarray(const valarray<long double>& A);
long double cdot(const valarray<long double>& A, const valarray<long double>& B);
long double kahan_sum(const valarray<long double>& v);
valarray<long double> integrand(const valarray<long double>& X, const long double& b);
// Used in individual parts of question
long double trapezium(const long double& a, const long double& b, const int& n);
long double simpson(const long double& a, const long double& b, const int& n);
long double clenshaw(const long double& a, const long double& b, const int& n);
long double sum_for_clenshaw(const long double& theta, const int& n);
long double mv_monte(const long double& a, const long double& b, const int& sample_size);
valarray<long double> uniform_randoms(const long double& a, const long double& b, const int& sample_size);

int main() {
    long double a = 0; long double b = 4; int n = 64; int sample_size = 1000;
    cout set << "exact value = " << I_exact << endl;
    // Part (a)
    long double I_trapezium = trapezium(a, b, n);
    cout set << "trapezium = " << I_trapezium << endl;
    cout set << "trapezium error = " << I_exact - I_trapezium << endl;
    // Part (b)
    long double I_simpson = simpson(a, b, n);
    cout set << "simpson = " << I_simpson << endl;
    cout set << "simpson error = " << I_exact - I_simpson << endl;
    // Part (c)
    long double I_clenshaw = clenshaw(a, b, n);
    cout set << "clenshaw = " << I_clenshaw << endl;
    cout set << "clenshaw error = " << I_exact - I_clenshaw << endl;
    // Part (d)
    long double I_mv_monte = mv_monte(a, b, sample_size);
    cout set << "MV monte carlo = " << I_mv_monte << endl;
    cout set << "MV monte carlo error = " << I_exact - I_trapezium << endl;

    // Testing integrand() works
    valarray<long double> X = {0, 1, 2, 3, 4, 5, 6};
    print_valarray(integrand(X, b));
    // prints { 0 1.7320508075688772936 2 1.7320508075688772936 0 nan nan  }
    // integrand() for values of x > b are negative and therefore do not integrate,
    // hence "not a number", as expected

    // Testing whether r_i values for clensahw are calculated correctly
    cout set << sum_for_clenshaw(pi / 2.0L, n) << endl; // prints -0.57104815272235883133
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

// Part (a) - Define Trapezium Rule function
long double trapezium(const long double& a, const long double& b, const int& n) {
    const long double h = (long double)(b - a)/ (long double)n;
    valarray<long double> X(n); // x_i values: {0,0,..,0} for indices [0],[1],..[63]
    valarray<long double> F(n); // f(x_i) = f_i values
    valarray<long double> W(n); // weights

    for (int i = 0; i < X.size(); i++) {
        X[i] = (long double)a + h*(long double)i; // use step size h to calculate each x value
        W[i] = (i == 0 || i == n - 1) ? h / 2.0L : h; // ternary operator to assign weights
    }
    F = integrand(X, b);

    // Test the output
//    cout << "N = " << F.size() << endl;
//    cout << "X = " << endl; print_valarray(X[slice(0,5,1)]);
//    cout << "W = " << endl; print_valarray(W);
//    cout << "F = " << endl; print_valarray(F[slice(0,5,1)]);

    return cdot(W, F);
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

// Part (d) - Define mean value Monte Carlo function
long double mv_monte(const long double& a, const long double& b, const int& sample_size) {
    const long double weight = (b - a) / (long double)sample_size;
    valarray<long double> X = uniform_randoms(a, b, sample_size);
    valarray<long double> F = integrand(X, b);

    return weight * kahan_sum(F);
}

// Part (d) - Define uniform random values, an auxiliary function for mv_monte()
valarray<long double> uniform_randoms(const long double& a, const long double& b, const int& sample_size) {
    valarray<long double> rand_nums(sample_size);
    // Seed with a real random value
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<long double> unif(a, b);
    // Choose a random value uniformly between a and b
    for (int i = 0; i < sample_size; i++){
        long double rand_num = unif(gen);
        rand_nums[i] = rand_num;
    }
    return rand_nums;
}