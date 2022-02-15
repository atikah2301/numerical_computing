#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

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

	// Ex2 Q2 - Trying uninitialised variables
	/*double uninitialised; // warning
	double uninitialised_test = uninitialised * 2; // error
	cout << uninitialised_test << endl;*/

	// Ex2 Q8 - True and False
	// Let int m = 6; int n = 4;
	// bool a = false; // false
	// bool b = m == 3; // false since 3 != 6
	// bool c = n > m && m < 7; // false, since false && true == false
	// bool d = m != n; // true, since 6 != 4
	// bool e = m != 3; // true, since 6 != 3, and part b wasn't reassignment
	// bool f = !e || (3 < 2); // false, since !e is false, 3 < 2 is false
	// bool g = a || b; //  false or false is false
	// bool h = (a || b) && (c || d)); // false and anything is false

	// Ex2 Q9 - Standard Form using E or e
	double q9 = 2000;
	cout << q9 * q9 << endl; // returns an answer in standard form
	double std_form = 2E100; 
	cout << std_form << endl; // up to E5, you get 200..., but E6 onwards, you get 2e+06

	// Ex2 Q10 - Memory of an integer
	// Max is 2147483647, min is -2147483648
	// 2 = possibilites per bit
	// 8 = bits per byte
	// 4 = bytes per integer
	// so, 2 ** 4*8 = total number of possible values
	// incidentally, this is exactly 2 * 2147483648 = 4294967296, the range of integer values
	cout << "\nNumber of possiblilites for int data type, given as a long long:" << endl;
	long long longint = 2147483648 * 2;
	cout << longint << endl;
	cout << "Number of possibilities for long long data type:" << endl;
	cout << numeric_limits<long long>::max() << endl; // 9223372036854775807
	cout << numeric_limits<long long>::min() << endl; // -9223372036854775808
	cout << log2(9223372036854775808. * 2.) << endl; // 64
	// Since the number of possibilities for long long was 2 ** 64 = 2 ** 8*8
	// this means there were 8 bytes used to store an integer

	// Ex2 Q11 - Integer overflow
	/*int n = numeric_limits<int>::max();
	cout << n << endl;
	n = n + 1;
	cout << n << endl;*/
	// in the above code, the integer runs out of bits to store an integer bigger than its max
	// will have to use a long long
	// when at its max, an integer is a series of 2 ** 32 "1"s in binary

	// Ex2 Q12 - More on output
	int age = 21;
	cout << "\thello i am " << age << " years old!" << "\n";


}