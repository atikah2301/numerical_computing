#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <valarray>
#include <cmath>
#include <bits/stdc++.h>
#include <limits>

#define set << setprecision(18)

using namespace std;

const long double e = 2.718281828459045;
const long double epsilon = pow(10,-15);

// e = 2.718281828459045 2353602874...
// in C++, numbers are only guaranteed to be accurate to 16 digits

int main()
{
    long double x_0 = 1.; // 0th iteration
    long double x_1 = exp(-x_0); // 1st iteration
    for (int i = 2; i < 70; i++) { // 2nd to 62nd iterations will occur
        // Check for sufficient convergence
        long double diff = abs(x_1 - x_0);
//        if (diff < epsilon)
//            break;
        // Update values if convergence has not yet occurred
        x_0 = x_1;
        x_1 = exp(-x_0);
        // Print output at each iteration
        cout << i << ": ";
        cout set << diff << ", "<< endl;
        cout set << x_1 << endl;
    }
    // Check if the result converged as expected
    long double error = abs(x_1 - exp(-x_1));
    cout set << error << endl;
    bool has_converged = (error < epsilon);
    cout << has_converged;
}