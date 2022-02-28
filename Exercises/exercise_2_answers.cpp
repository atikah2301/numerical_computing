#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// Week 2 - Practice and exercise answers

int main()
{
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
	
	// Ex2 Q13 - Dividing floats and ints
	//double m = 5;
    //double n = 4;
    //cout << m/n << endl;
	
	int m = 5;
    int n = 4;
    cout << m/n << endl;

}