#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Week 5, Exercise 10

// Function declarations
void output_vector(const string& file, const vector<double>& v);


int main()
{
	// Q1 - Output vector to a text file
	
    string output_path = "C:\Users\atika\Documents\GitHub\numerical_computing\Text Files\exercise_10_output.txt";
	vector<double> my_vec = {2.5, 6.88, 12, 3.4};
	output_vector(output_path, my_vec);
	if (!output.is_open()) {
		cout << "Error: Couldn't create the file" << endl;
	}
}

// Function definitions

void output_vector(const string& file, const vector<double>& v) {
    ofstream output(file);
    for (double num : v) {
        output << num;
    }
}
