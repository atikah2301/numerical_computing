# Numerical Computing with C++

Assessment:

- Fortnightly exercises, upload code on QMPlus as a quiz, 2 weeks to complete each one
- 4 in total worth 5% each
- Made available each Friday
- Due: ???

Module Structure:

- Coursework which is code + a report
- Due: ???

Links:

- en.cppreference.com
- cplusplus.com
- Stack Overflow

C& C++ Info:

- The module will use C++20 
- Compiled language as opposed to interpreted 
- C allows abstraction compared to Python
- C is independent of the type of computer processor being used, so it can be used on different systems, unlike Assembly
- UNIX was originally written in C
- Bjarne Stroustrup developed C++ to add more features including OOP capabilities for C

## Week 1 - Intro, Data Types, Operators

### Hello World Program

- Pre-processor Directives - use `#` at the top of a cpp file, e.g. `#include`.

- Comments - use either `//` for single line, or `/*hi*/` for multi-line.
- `using namespace std` means we can exclude using `std::` before all `std` features
- `std` is the standard library
- `#include <iostream>` is an imported library, allowing us to use inputs and outputs to console
- `<<` is the output operator,; `>>` is the input operator
- To take user input from the console, declare a variable to store the input e.g. `double x`, then ask for input and store it in the variable`std::cin >> x;`. 

### Maths and Operators

- Use `#include <cmath>`

- Arithmetic operators, `+ - / *` are **binary** operators since they use **two** inputs to give an output

- Operator precedence is just applying BIDMAS rules

- Increment and decrement operators `++ --` are **unary** operators since they use **one** input to give an output

    - Prefix operators (`++k`) and postfix operators (`k++`) are the same when used standalone 
    - But when used in conjunction with the assignment operators (`=`) they have a different effect
    - Specifically, `j = k++` will do `j = k` THEN do `k = k+1` (assign first, increment after)
    - But `j = ++k` with do `k = k+1` THEN do `j = k` (increment first, assign after)

- Other unary operators are `+=, -=, *=, /=` 

- Conditional operators: `&&` is 'and', `||` is 'or'

    - `&&` takes greater precedence than `||`
    - Note: `&` and `|` are used for unrelated purposes in C/C++

- An binary operation must always involve data of the same type, and the output will always be of that type:

    - Consider the division of two integers giving a decimal number. If the data types of the divisor and dividend are both `int` then this will be floor division.
    - Could be useful for finding division and remainder!
    - To get "regular" division, use `double` or `float` 

    

### Data Types

- `float` has 8 digits of precision, `double` has 16 digits of precision, 
- Floats and doubles shouldn't generally be used together,
- We can differentiate between integers and natural number (including 0) by called them signed and unsigned integer
- 8 bits make 1 bytes. Bools, chars, integers take up 1 byte.
- Check limits using `sizeof(int)` or `numeric_limits<int>::max()` or `min()`
- Literals are raw data - `2`,`4.67`,`cat` are integer, double, and string literals.
- `long long` is a data type for integers outside of the -2,147,483,648 to 2,147,483,647 range

### Best Practices

- Declare and initialise variables at the same time
    1. Ensures you don't assign a value later that doesn't match its type from declaration.
    2. Ensures you don't leave unused variables, which would take up memory needlessly.

### IDE Notes

- `exit with code 0` means everything ran as expected.

    

## Week 2 - Casting, Conditionals, Loops

### File Management

- Only one file per cpp project can use the`main()` function
- You can exclude a file from a project without deleting it entirely by using `remove` in the Solution Explorer

### Casting

Converting one data type to another is called casting. We can cast integers to doubles **explicitly**. Starting with `int a = 7;`:

- `double b = (double)a;`  - C-style casting
- `double b = double(a);` - function-style casting
- `double b = static_cast<double>(a);` - C++- style casting

Integers can be cast to doubles **implicitly** without warning because they are a subset of doubles, so no data is lost as a result. Casting is usually is done explicitly so that data is less likely to be lost unintentionally.

- `int k = 2; double j = k;` - casts automatically, no issues
- `double j = 2.43; int = j;` - casts but with warning!

### Input and Output

C++ Style:

- Can use `cin >> var1;` to assign user input via console to the variable `var1`
- Can use `cout << var1 << endl;` to print values as output to console

C Style:

- Use function `printf` and `scanf`
- Note: Non examinable!

Checking if input is valid:

- Use `cin.good()` to check the value taken as input is of the correct data type for the variable it has been stored in. E.g. `if (!cin.good()) {cout << "Input was invalid" << endl;}`

### 'If' Statements

Same as in C#. Example:

```c++
int userInput2;
    cout << "Is even? "; 
    cin >> userInput2;
    if (userInput2 % 2 == 0)
        cout << "Yes, number is even" << endl;
    else
        cout << "No, number is odd" << endl;
```

### Loops

- Loops can be ended early using `break;`
- An iteration can be ended early using `continue;`
- Note: when loops are nested, `break` will only break the current loop

### For Loops

Used to iterate commands when you know how many iterations are needed and when to stop, e.g.`for (int i = 1; i <= 5; i++)`

- First argument declares and initialises the iterator variable
- The second argument is a condition that is checked against before each iteration is allowed to begin. Once it evaluates to `true`, iteration stops.
- The third argument changes some parameter before the next iteration begins, but after the check is still `false`

### While Loops

Used to iterate commands when you **don't** know how many iterations are needed by still know when to stop, e.g. `while (i <= 5)`

- The only argument is a condition for when the iterations should cease.

### Scope

- Local variables are any variables declared within from functions, loops etc, and are not accessible outside of that block.
- Variables declared in some scope can be accessed by any sub-blocks of code.

 

## Week 3

### Functions

- Modular programming (using functions) is a form of abstracting code
- Start by specifying return type, name, parameter type and parameter name, then scope. E.g.

```c++
double power(const double x, int power n) {
	double result = 1.0;
	for (int i = 1; i <= n; i++) {
		result *= x;
	}
	return result;
}
```

- We can declare and define functions in separate places. Declarations are the same as defining but excludes the scope and main body of the function, e.g. `double power(const double x, int power n);`
    -  Declaration and definition need only match for:
        - Return type
        - Name
        - Number of parameters
        - Types of parameters
    - They need not match for:
        - Order of parameters
        - Names of parameters
- Function A can use function B in its main body as long as function B came before A in its declaration. So, the advantage of writing out our declarations first at the top of every file of code is that the definitions which follow can freely call other functions, regardless of order.
- A function with no return type is specified as `void`. A function with no arguments can have its round brackets left blank, or with the keyword `void` on the inside.
- Note - functions cannot be defined within other functions like `int main {}`

### Constants

For a variable storing an unchanging value, use the `const` modifier in from of a variables declaration e.g.

```c++
const double pi = 3.14159265358979; // using a const
pi *= 2.0; // results in an error since a const can't be altered
```

Use `const` as consistently and often as possible is "const-correctness", which helps reduce bugs in code.

### Global Variables

If we want a variable to be accessible by any function, loop etc. regardless of scope, we can make it a global variable. These are usually `const` so that they can be used for parallel processing i.e. they aren't changed by function A before function B wants to use it.

### Overloaded Functions

If two functions have the **same name** but **different parameter types**, then we have an overloaded function. This can easily go wrong if the two functions are not conceptually the same in their usage. Example:

```c++
double square(double x) { return x*x; }
double square(int x) { return x*x; } // Correctly overloaded, since parameter type differs 
int square(int x) { return x*x; } // Correctly overloaded, since return type can only differ when parameter type differs
int square(double x) { return x*x; } // Incorrectly overloaded, since return type cannot differ unlesss parameter type differs
```

### Recursive Functions

Example

```c++
int factorial(const int n) {
	if (n <= 1) return 1;
	else return n*factorial(n-1);
}
```

### Naming Conventions

**Reserved words** are keywords in C++ that can't be used as function names, variable names etc. because they already have a predefined meaning in the language, e.g. we can't name a function `double` since this is a known data type.

### Importing

To import code from file A to file B, put `#include "file_A.cpp"` at the top of file B. This will effectively copy all code from file A and paste it onto that line in file B.

This only works when file A and B are in the same directory

### Headers 

Header files, with extension .h, are files in which all declarations for functions go, and the header is imported into all relevant .cpp files. Non examinable.

## Week 4 - Vectors, Valarrays, References

### Vectors

The C++ standard library, i.e. `using namespace std` or `std::`,  contains code for data structures, functions, algorithms, and more.

Vectors are one such data structure, implementing using OOP and templates - features in C++ but not C. In C, we would use C-style arrays, but vectors are less error-prone. We can gain access to vectors using `#include <vector>` at the top of our code.

#### Accessing elements of a vector

We can access elements of a vector using the index of the element in square brackets following the named instance of a vector, e.g. `v[0]`. 

The last element of a vector is accessed as `v.back()`.

#### Initialising a vector

- `vector<double> v` gives ` []`
- `vector<double> v(3, 1.0)` gives `[1.0, 1.0, 1.0]`
- `vector<double> v(3)` gives `[0.0, 0.0, 0.0]` 
- `vector<int> v{1, 2, 3}` or `vector<double> v={1, 2, 3}`gives `[1, 2, 3]`

#### Vector operations

- *Append* - add a new element to a vector using `v.push_back(a)` where `a` is the new element
- *Clear* - reset the size of a vector to 0 and delete all elements using `v.clear()`
- *Remove from end* - reduce size by 1 and delete last element using `v.pop_back()`
- *Resize* - use `v.resize(n)` where `n` is an integer for the new size 

### Templates

A template is used to help specify a function that could have return types or parameter types that work with different data types. It's the safer way of creating an overloaded function intentionally. 

A vector is an example of a data structure that would work with any type of numeric data type. To specify which data type we're working with from the template, use angle brackets: `vector<double>`.

### Objects

In C++, objects can be instances of either a `class` or a `struct`. To access functions and properties of an object, use the dot operator. E.g.

```c++
vector<double> v(5, 1.0); // v is an in instance a vector
cout << v.size(); // access the size property or function of v 
```

### Valarrays

The C++ `std` library provides a highly efficient data structure (or more accurately, a template) for vectors which can be imported using `#include <valarray>`. 

These can be initialised in many ways:

- `valarray<int> v;` for `{}`
- `valarray<int> v(n);` for vector `{0,0,0..,0}` of size `n` 
- `valarray<int> v(x, n);` for `{x, x, x,..,x}` of size `n`
- `valarray<double> v(n, x);` for `{x, x, x,..,x}` of size `n`, where `x` is a `double` and `n` is an `int`
- `valarray<double> v(a, n);` for `{a[0], a[1], .., a[n-1]}` for the first `n` values of an array `a`

Note: a "normal" array would be of the form `double a[] = {1.0, 1.1, ..}`

Many functions take valarrays as arguments and apply the function to it element-wise, e.g. sin() and cos(). Valarrays also have special methods such as `shift()` and `cshift()` to shift elements normally and circularly. 

### Other

- Debug mode vs Release mode on VS
- Subscript out of range errors

### Passing by Value

- Passing an argument to a function by value means creating a copy of the value passed in, so that the original value (of the literal or variable passed) is unaffected. 
- Instead the copy of the value is manipulated within the function using a local variable
- Example:

```C++
int increment(int k) {return k++;} // passing by value
```

```c++
int main() {
    int m = 2;
    int n = increment(m); // value of m is still 2, but n is 3
}
```

### Passing by Reference

What is passing by reference?

- Passing an argument to a function by reference means using the original value of the variable passed in for any operations carried out within the function. 

When should I pass by reference?

- Passing by reference allows us to not copy large bodies of data unnecessarily, to save on memory and be more efficient.
- This can also be used to directly manipulate data in variables that existed outside of the function.

How do I pass by reference?

- Using `&` after declaring the data type of some variable allows us to reference the location of the data, not just the value of the data itself. 
    - `cout << k` would print the value of the variable `k`, which could be `2`
    - `cout << &k` would print the location of the date stored in variable `k`, which could be `0x7fffca7f5cc4`, which an address on the CPU given in hexidecimal.
- Example for directly manipulating data:

```C++
int increment(int& k) {return k++;} // passing by reference using an "&" symbol	
```

- Example for referring to data from outside the function, without manipulating it:
    - Pass in the vector by reference, to avoid creating a copy of it
    - However, we don't intend to alter vector at all in this function
    - So we pass it in as a const reference. so that if we do accidentally change the vector through out function code, an error will occur to warn us.
    - Note: By convention, any `const` reference arguments and non-changing arguments go first in the list of a functions arguments

```c++
vector<int> w = {1, 2, 3}
int get_sum(const vector<int>& v) {
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    return sum;
}
```

```c++
int main() {
    int m = 2;
    int n = increment(m); // m is now 3 since we passed it by reference to the function
    // n is also 3 since it stores the function's return value 
    // m and n may have the same value but are stored at different addresses
}
```

### Alternative to Passing by Reference

- If variable `m` is passed to a function by value, it won't be manipulated. However, we can still achieve the effect of having `m` changed by the time the code finishes running, using reassignment, e.g. `m = increment(m);`. 

### Reference Variables

- A reference variable allows you to create a new variable that refers to the same memory address as another variable, so that when the data at the address changes, both the original variable and reference variable are updated simultaneously. 
- In other words, reference variables create a shallow copy of the original variable.
- Example:

```c++
int main() {
    int m = 2;
    int k = m;
    int& n = m; // create a shallow copy of m using reference variable n
    m++; // m and n are now both 3, whereas k is still 2
}
```

### Pointers

- We can store the memory address of a variable's data as its own data type, called a pointer, which is declared using `*`
- For any pointer, you still need to specify what type of data is at the memory address being stored by the pointer, e.g. `int*` or `bool*`
- To get the address of a variable to store in the pointer, use `&var`

```c++
int main() {
    int m = 2;
    int* ptr = &m; // get the memory address of m, store it in a pointer,
}
```

- 
