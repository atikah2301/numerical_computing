#include <iostream>
#include <cmath>

using namespace std;

// Week 3, Exercise 5

// Function declarations
double triangle_area(const double a, const double b, const double c);
double hypoteneuse(const double x, const double y);
bool is_even(const int m);
int get_odd_int();
double get_pi();

int main()
{
    // Q1 - Understanding const errors
    
    // const double pi = 3.14159;
    // pi *= 2.0; // "error: assignment of read-only variable ‘pi’"
    // const double myConst; // "error: uninitialised const ‘myConst’"

    
    // Q2 - Triangle area function

    // a. type out the code from lectures
    // b. test the code on different inputs
    // c. add an error message
    // d. separate declaration and definition
    
    // int a; cin >> a; int b; cin >> b; int c; cin >> c;
    // cout << triangle_area(a,b,c) << endl;
    
    
    // Q3 - Hypoteneuse function

    // int x1; cin >> x1; int y1; cin >> y1;
    // cout << hypoteneuse(x1, y1) << endl;
    
    
    // Q5 - Functions calling functions (checking parity)
    // get_odd_int();
    
    
    // Q6 - Pi function
    // cout << get_pi();
    
    
}

// Q2 function definition

double triangle_area(const double a, const double b, const double c) {
        const double s = (a+b+c)/2.0;
        const double area_sqr = s*(s-a)*(s-b)*(s-c);
        if (area_sqr < 0) {
            cout << "error: invalid input" << endl;
            return -1;
        }
        const double area = sqrt(area_sqr);
        return area;
    }
    
// Q3 function definition

double hypoteneuse(const double x, const double y) {
        return sqrt(x*x + y*y);
    }
    
// Q5 function definitions
bool is_even(const int m) {
    return m % 2 == 0;
}

int get_odd_int() {
    while(true) {
        int user_int; cin >> user_int;
        if (!is_even(user_int)) return user_int;
        else cout << "Please enter an odd integer." << endl;
    }
}

// Q6 function definition
double get_pi() {
    return 4.0*atan(1.0); // atan() from <cmath>
}