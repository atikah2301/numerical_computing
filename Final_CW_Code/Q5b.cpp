#include <iostream>
#include <cmath>
using namespace std;

double norm_pdf(const double x){
    const double pi = 3.14159265358979;
    return 1./sqrt(2.*pi) *exp(-x*x/2.0);
}

struct Norm_pdf_standard{
    double operator()(const double x){
        const double pi = 3.14159265358979;
        return 1./sqrt(2.*pi) *exp(-x*x/2.0);
    }
};

double trap_function(const double a, const double b, const int n, double f(const double)){
    const double h = (b-a)/double(n);
    double S = (f(a)+f(b))*0.5;
    for (int k=1; k<n; k++) S+=f(a+k*h);
    return S*h;
}

template <typename F>
double trap_template(const double a, const double b, const int n, F f){
    const double h = (b-a)/double(n);
    double S = (f(a)+f(b))*0.5;
    for (int k=1; k<n; k++) S+=f(a+k*h);
    return S*h;
}

int main() {
    Norm_pdf_standard Gaussian;-
    cout << norm_pdf(1.) << endl;
    cout << 0.5+trap_function(0.,1.96,20,norm_pdf) << endl;
    cout << Gaussian(1.) << endl;
    cout << 0.5+trap_template(0.,1.96,20,norm_pdf) << endl;
    cout << 0.5+trap_template(0.,1.96,20,Gaussian) << endl;
    return 0;
}