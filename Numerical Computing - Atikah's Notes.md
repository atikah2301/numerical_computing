# Numerical Computing

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

### 'If' Statements

Same as in C#

Example:

```c++
int age = 6;
int category = 0;
if (answer >= 4)
	category = 3;     
if else (answer <= 2)
    category = 1;
else
    category = 2;
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







