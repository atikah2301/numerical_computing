#include <iostream> // for cout, cin
#include <iomanip> // for setprecision()
#include <cmath> // for pow(), exp(), abs() - overloaded functions for long doubles
#define set << setprecision(18) // using shorthand for convenience
using namespace std;

int main()
{
    // Part (a) - Implement the self-consistent iteration
    
    // Threshold of convergence
    const long double epsilon = pow(10,-15);
    // Initial value and 1st iteration
    long double x_0 = 1.;
    long double x_1 = exp(-x_0); 
    // 2nd to 62nd iterations occur in loop
    for (int i = 2; i < 70; i++) {
        // Check for sufficient convergence
        long double diff = abs(x_1 - x_0);
		if (diff < epsilon)
			break;
        // Update values if convergence has not yet occurred
        x_0 = x_1;
        x_1 = exp(-x_0);
        // Print output at each iteration
        cout << i << ": ";
        cout set << diff << ", "<< endl;
        cout set << x_1 << endl;
    }
    
    // Part (c) - Check if the result converged as expected based on error
    
    long double error = abs(x_1 - exp(-x_1));
    cout set << error << endl; // prints 5.5250942709861306e-16
    bool has_converged = (error < epsilon);
    cout << has_converged; // prints 1, i.e. true
}