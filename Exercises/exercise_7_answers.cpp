#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Week 7 - Practice and exercise answers

// Function declarations
vector<int> fibonacci(int n);
vector<int> primes(int n);

void print_vector(const vector<int> v);


int main()
{
    // Q1 - Vector elements
    
    vector<double> v(3, 1); // {1.0, 1.0, 1.0}
    vector<double> v{1,2,3,4}; // {1.0, 2.0, 3.0, 4.0}
    vector<double> v(4); // starts as {0.0, 0.0, 0.0, 0.0}
    for (int i=1; i<=4; i++)
        v[i-1] = i; // becomes {1.0, 2.0, 3.0, 4.0,}
    
    vector<double> v; // starts as {}
    for (int i=1; i<=4; i++)
        v.push_back(i); // becomes {1.0, 2.0, 3.0, 4.0,}
    
    v.resize(8);
    v.pop_back();
    v.clear();
    
    for (int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    
    
    // Q2 - Fibonacci with vectors
    
    cout << "n = "; int n; cin >> n;
    vector<int> fib_nums = fibonacci(n);
    print_vector(fib_nums);
    
    
    // Q3 - Primes with vectors
    
    cout << "n = "; int n; cin >> n;
    vector<int> prime_nums = primes(n);
    print_vector(prime_nums);
    
    
    // Q4 - Subscript out of range
    
    vector<int> v(4, 3);
    //v[6] = 5; 
    
    // In debug mode, "subscript out of range" error shown
    // In release mode, an exception is thrown warning us of an "access violation"
    
    //v[4] *= 2;
    //cout << v[4] << endl; // Got the output as 33734096..
    //cout << v[-1] << endl;

    vector<int> w;
    // w.pop_back();
    
    // In release mode, nothing appears to happen
    // In debug mode, "pop back on empty vector" error shown
    
}

// Function definitions

// for Q2
vector<int> fibonacci(int n) {
    vector<int> fib_nums{};
    if (n >= 1) {
        fib_nums.push_back(0);
    }
    if (n >= 2) {
        fib_nums.push_back(1);
    }
    if (n >= 3) {
        for (int i = 2; i < n; i++) {
            fib_nums.push_back(fib_nums[i-2] + fib_nums[i-1]);    
        }
    }
    return fib_nums;
}

void print_vector(const vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}

// for Q3

vector<int> primes(int n) {
    vector<int> all_primes;
    int next_prime = 2;
    bool is_prime = true;

    if (n >= 1) {
        while (all_primes.size() < n) {
            for (int prime : all_primes) {
                if (next_prime % prime == 0) {
                    is_prime = false;
                    break;    
                }
            }
            if (is_prime == true) {
                all_primes.push_back(next_prime);    
            }
            next_prime++;
            is_prime = true;
        }
    }
    return all_primes;
}

