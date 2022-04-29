#include <iostream>
#include <string>
#include <bits/stdc++.h> // for exp()
#include <limits> // for sizeof(), min(), and max()

using namespace std;

// e = 2.718281828459045 2353602874...
// in C++, exp(1) is only accurate to 16 digits


int main()
{
    // long double e = exp(1);
    double e = 2.7182818284590452353602874;
    cout << setprecision(20) << e << endl;
    cout << "# of bytes for int: " << sizeof(int) << endl;
    cout << "# of bytes for float: " << sizeof(float) << endl;
    cout << "# of bytes for double: " << sizeof(double) << endl;
    cout << "# of bytes for long double: " << sizeof(long double) << endl;

    cout << "min for int: " << numeric_limits<int>::min() << endl;
    cout << "max for int: " << numeric_limits<int>::max() << endl;
    cout << "min for float: " << numeric_limits<float>::min() << endl;
    cout << "max for float: " << numeric_limits<float>::max() << endl;
    cout << "min for double: " << numeric_limits<double>::min() << endl;
    cout << "max for double: " << numeric_limits<double>::max() << endl;
    cout << "min for long double: " << numeric_limits<long double>::min() << endl;
    cout << "max for long double: " << numeric_limits<long double>::max() << endl;
}

/*
Output:

# of bytes for int: 4
# of bytes for float: 4
# of bytes for double: 8
# of bytes for long double: 16

min for int: -2147483648
max for int: 2147483647

min for float: 1.175494350822287508e-38
max for float: 3.4028234663852885981e+38

min for double: 2.2250738585072013831e-308
max for double: 1.7976931348623157081e+308

min for long double: 3.3621031431120935063e-4932
max for long double: 1.189731495357231765e+4932
*/