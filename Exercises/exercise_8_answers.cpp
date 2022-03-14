#include <iostream>
//#include <cmath>
#include <vector>

using namespace std;

// Week 8 - Practice and exercise answers

// Function declarations
void swap_by_val(int a, int b);
void swap_by_ref(int& a, int& b);

double dot_product(const vector<double>& u, const vector<double>& v);

void print_vector(const vector<double>& v);
void print_vector(const vector<int>& v);

double mean(const vector<double>& v);
double var(const vector<double>& v);
double min(const vector<double>& v);
double max(const vector<double>& v);

int random_lc(const int x);
vector<int> random_ints(const int n, const int x);
vector<double> random_decimals(const vector<int>& random_ints, int m);

int main()
{
    // Q1 - passing by ref vs passing by value
    
    int a = 3; int b = 4;
    swap_by_ref(a, b); // works
    swap_by_val(a, b); // doesn't work
    cout << "a = " << a << ", b = " << b << endl;
    
    
    // Q2 - calculate dot product of two vectors
    
    vector<double> v_1 = {2., 1., 0.};
    vector<double> v_2 = {-1., 2., 0.};
    cout << dot_product(v_1, v_2) << endl; // gives 0, as expected
    
    
    // Q4 - write functions for mean and variance using const ref arguments
    
    vector<double> v_3 = {1, 2, 3, 4, 5};
    cout << "mean = " << mean(v_3) << ", variance = " << var(v_3) << endl;
    cout << "min = " << min(v_3) << ", max = " << max(v_3) << endl;
    
    
    // Q5 - Pseudo random number generation using Linear Congruence Method
    
    
    // part 1
    int seed = 10; int n = 20; int m = 134456;
    cout << "random numbers: "<< endl;
    vector<int> random_nums = random_ints(n, seed);
    print_vector(random_nums); cout << endl;
    cout << "correct size? " << (random_nums.size() == n) << endl;
    
    // part 2
    vector<double> random_dec = random_decimals(random_nums, m);
    cout << "random decimals: "<< endl;
    print_vector(random_dec); cout << endl;
    cout << "mean's error = " << abs(mean(random_dec) - 0.5) << endl;
    cout << "variance's error = " << abs(var(random_dec) - (1./12.)) << endl;
    cout << "min's error = " << min(random_dec) << endl;
    cout << "max's error = " << 1. - max(random_dec) << endl;
    
}

// Function definitions


// for Q1
void swap_by_val(int a, int b) {
    const int temp = a;
    a = b;
    b = temp;
} 
// doesn't work as intended,
// since values are only swapped within the function's scope

void swap_by_ref(int& a, int& b) {
    const int temp = a;
    a = b;
    b = temp;
}
// works as intended,
// since we swap the original variables existing outside of the function's scope


// for Q2
double dot_product(const vector<double>& u, const vector<double>& v) {
    double sum_of_products = 0.0;
    for (int i = 0; i < u.size(); i++) {
        sum_of_products += u[i] * v[i];
    }
    return sum_of_products;
}


// for Q3 
void print_vector(const vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

void print_vector(const vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}


// for Q4
double mean(const vector<double>& v) { 
    // note that we copy the vector using &, but without changing it, via const
    double n = double(v.size());
    double sum = 0.;
    for (double x : v) {
        sum += x;
    }
    return sum / n;
    
}

double var(const vector<double>& v) {
    // note that we copy the vector using &, but without changing it, via const
    double n = double(v.size());
    double sum = 0.;
    double mu = mean(v);
    for (double x : v) {
        sum += (x-mu)*(x-mu);
    }
    return sum / (n-1);
}

double min(const vector<double>& v) {
    double minimum = v[0];
    for (double value : v) {
        if (value < minimum)
            minimum = value;
    }
    return minimum;
}

double max(const vector<double>& v) {
    double maximum = v[0];
    for (double value : v) {
        if (value > maximum)
            maximum = value;
    }
    return maximum;
}


// for Q5 
int random_lc(const int x) {
    int a = 8121; int m = 134456; int c = 28411;
    return (a*x + c) % m;     
}

vector<int> random_ints(const int n, const int x) {
    vector<int> random_vals = {random_lc(x)};
    for (int i = 0; i < n-1; i++) {
        random_vals.push_back(random_lc(random_vals[i]));
    }
    return random_vals;
}

vector<double> random_decimals(const vector<int>& random_ints, int m) {
    vector<double> decimals;
    for (int x : random_ints) {
        decimals.push_back(double(x)/(m-1));
    }
    return decimals;
}
