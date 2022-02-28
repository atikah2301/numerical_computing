#include <iostream>
#include <cmath>

using namespace std;

// Week 6 - Practice and exercise answers

// Global constants
const double e = 2.7182818284590; 
const double pi = 3.141592653589793;

// Function declarations
double cube(const double n); // (1) double double
int cube(const int n); // (2) int int - no errors overloading with (1)
//double cube(const int n); // (3) double int - no errors overloading with (1)
//int cube(const double n); // (4) int double - error: ambiguating new declaration
double pow_int(const double x, const int k);
double pow_int_rec(const double x, const int k);
double norm_pdf(const double x, const double mu, const double sigma);
double error_f(const double w, const int n); 
    // note: erff was a reserved word, so i used the name error_f instead
double norm_cdf(const double x, const int n);
double approx_cdf(double x, int N);


int main()
{
    // Q1 - Overloaded function
    
    // cout << cube(2) << endl;
    // cout << cube(2.3) << endl;
    
    // Q4 & Q5 - Iterative and Recursive power function
    
    // cout << pow_int(3.0, 3) << endl;
    // cout << pow_int_rec(3.0, 3) << endl;
    
    // Q6* - Normal pdf 

    cout << norm_pdf(1,0,1) << endl;
    // expected: 0.242 to 3 d.p. ; actual: 0.241971 to 6 d.p.
    cout << norm_pdf(2,1,2) << endl;
    // expected: 0.176 to 3 d.p. ; actual: 0.176033 to 6 d.p.

    
    // Q7* - Normal cdf using error function
    
    int n = 100;
    cout << norm_cdf(1.64, n) << endl;
    // expected: 0.950 to 3 d.p. ; actual: 0.949497 to 6 d.p.
    cout << norm_cdf(1.96, n) << endl;
    // expected: 0.975 to 3 d.p. ; actual: 0.975002 to 6 d.p.
    cout << 1. - norm_cdf(-1.96, n) << endl;
    // got the same answer as above, 0.975002, just as expected,
    // based on phi(x) = 1 - phi(-x)
    
	
	// Q8 - Normal cdf as an interal of normal pdf, via trapezium rule
    
    int N = 100;
    cout << approx_cdf(1.64, N) << endl;
    // expected: 0.950 to 3 d.p. ; actual: 0.950322 to 6 d.p.
    cout << approx_cdf(1.96, N) << endl;
    // expected: 0.975 to 3 d.p. ; actual: 0.975989 to 6 d.p.
}

// Q1 function definitions
double cube(const double n) {
    return n*n*n;
}

int cube(const int n) {
    return n*n*n;
}

// double cube(const int n) {
//     return n*n*n;
// }

// int cube(const double n) {
//     return n*n*n;
// }

// Q4 function definition
double pow_int(const double x, const int k) {
    double result = 1.0;
    for (int i=0; i<k; i++) {
        result *= x;
    }
    return result;
    
}

// Q5 function definition
double pow_int_rec(const double x, const int k) {
    if(k == 1){
        return x;
    }
    // By using the properties: 1. x^(2m)==(x^m)^2 and 2. x^(2m+1)==x*(x^m)^2,
    // the recursive implementation can halve the number of steps required,
    // compared to the iterative implementation
    else if(k > 1 && k % 2 == 0){
        const double w = pow_int_rec(x, k/2);
        return w*w;
    }
    else{
        const double w = pow_int_rec(x, k/2);
        return x*w*w;
    }
}

// Q6* function definition
double norm_pdf(const double x, const double mu, const double sigma) {
    double result_1 = sigma*sqrt(2.*pi);
    double result_2 = -((x-mu)*(x-mu))/(2.*sigma*sigma);
    return (1./result_1)*pow(e, result_2);
}

// Q7* function definitions
double error_f(const double w, const int n) {
    double result_1 = 2./sqrt(pi);
    double factorial = 1.;
    double w_pow = w;
    double sum = 0.;
    for (int k=0; k<=n; k++) {
        if (k > 0) {
            // make the algorithm more efficient
            // by reusing terms from previous the iterations
            factorial *= double(k);
            w_pow *= w*w;
        }
        double result_2 = pow(-1., k)*w_pow;
        double result_3 = factorial*(2.*double(k)+1.);
        sum += result_2/result_3;
    }
    return result_1*sum;
} 

double norm_cdf(const double x, const int n) {
    double err = error_f(x/sqrt(2), n);
    return (1.+err)/2.;
}

// Q8 - function definition
double approx_cdf(const double x, const int N) {
    if (N < 1) {
        cout << "error: N must be a positive integer";
        return 0;
    }
    double mu = 0.; double sigma = 1.;
    double result_1 = x/double(N);
    double result_2 = (norm_pdf(x,mu,sigma)+0.5)/2.;
    
    double sum = 0.;
    for (int k=1; k<=N-1; k++) {
        sum += norm_pdf(k*result_1, mu, sigma);
    }
    
    double integral = result_1*(result_2+sum);
    if (x > 0) return 0.5 + integral;
    else if (x < 0) return 0.5 - integral;
    else return 0.5;
}