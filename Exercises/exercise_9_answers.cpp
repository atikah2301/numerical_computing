#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Week 5, Exercise 9

// Function declarations


int main(int argc, char *argv[])
{
    // Q1 - string concatention
    const string h = "Hello"; const string w = "World";
    const string s = h + " " + w + "!";
    cout << s << endl;
    
    // Q2 - vectors of strings
    const vector<string> v = {"Hello","Atikah"};
    for (string str : v) {
        cout << str << " ";
    }
    cout << endl;
    
    // Q3 - strings as input
    string user_input; cout << "What is your name? "; cin >> user_input;
    cout << "Hi " << user_input << endl;
    
    // Q4 - casting int to string
    const string test_1 = to_string(21);
    cout << "You are " << test_1 << " years old." << endl;
    
    // Q5 - command line input
    const double my_double = atof(argv[1]);
    const int my_int = atoi(argv[2]);
    cout << "argc = " << argc << endl;
    cout << "argv[0] = " << argv[0] << endl;
    cout << "my double argv[1] = " << my_double << endl;
    cout << "my int argv[2] = " << my_int << endl;
}

// Function definitions

