#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Week 1 - Practice and exercise answers

int main()
{
	// Input and Output
	/*
	cout << "Calculate log(x) of x=";
	double x;
	cin >> x;
	double y = log(x);
	cout << y << endl;
	*/

	// Data type sizing
	cout << "\nNumber of bytes needed to store an int:" << endl;
	cout << sizeof(int) << endl;
	cout << "\nMax and min numbers which can be stored by the int data type:" << endl;
	cout << numeric_limits<int>::max() << endl;
	cout << numeric_limits<int>::min() << endl;

	// Increment operators
	cout << "\nIncrement operators:" << endl;
	cout << "\nPostfix, k++" << endl;
	cout << "\nLet k=5, and print j = k++, and then k" << endl;
	int k = 5;
	int j = k++;
	cout << j << endl; // 5
	cout << k << endl; // 6
	cout << "\nPrefix, ++k" << endl;
	cout << "\nLet k=5, and print j = ++k, and then k" << endl;
	int m = 5;
	int i = ++m;
	cout << i << endl; // 6
	cout << m << endl; // 6

	// Arithmetic with floats and ints
	cout << "\nInteger division is floor division:" << endl;
	int num1 = 5;
	int num2 = 4;
	cout << num1 / num2 << endl;
	cout << "\nUse doubles to get double from division:" << endl;
	double d1 = 5;
	double d2 = 4;
	cout << d1 / d2 << endl;

	// Casting
	cout << "\nCast integers to doubles, try 5/4 again after cast:" << endl;
	cout << double(num1) / double(num2) << endl;

	// Testing precisions with pi
	cout << "\nTesting precisions for different ways of getting pi:" << endl;
	cout << "With doubles:" << endl;
	cout << atan(1.) * 4. << endl;
	cout << atan2(0, -1.) << endl;
	cout << acos(-1.) << endl;
	cout << "With integers:" << endl;
	cout << atan(1) * 4 << endl;
	cout << atan2(0, -1) << endl;
	cout << acos(-1) << endl;
	cout << "Store in a double var first:" << endl;
	double pi = acos(-1.);
	cout << pi << endl; // ALL give 3.14159, may be better off using a literal instead

}