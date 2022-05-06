#include <iostream> // for cout
#include <iomanip> // for fixed, setprecision()
using namespace std;

// differential equation
long double dydx(long double x, long double y)
{
    return (x + y - 2.0L);
}

// Finds value of y for a given x
// using step size h
// and initial value y0 at x0.
long double rungeKutta(long double x0, long double y0, long double x, long double h)
{
    // Count number of iterations
    // using step size or
    // step height h
    int n = (int)((x - x0) / h);

    long double k1, k2;

    // Iterate for number of iterations
    long double y = y0;
    for (int i = 1; i <= n; i++) {
        // Apply Runge Kutta Formulas
        // to find next value of y
        k1 = h * dydx(x0, y);
        k2 = h * dydx(x0 + 0.5 * h, y + 0.5 * k1);

        // Update next value of y
        //y = y + (1.0 / 6.0) * (k1 + 2 * k2);
        y = y + k2;

        // Update next value of x
        x0 = x0 + h;
    }

    return y;
}

// Driver Code
int main()
{
    long double x0 = 0, y = 1, x = 2, h = 0.2;

    long double r = rungeKutta(x0, y, x, h);
    cout << fixed << setprecision(6) << "y(x) = " << r << endl;
    cout << setprecision(6) << "y(x) = " << r;
    return 0;
}
 