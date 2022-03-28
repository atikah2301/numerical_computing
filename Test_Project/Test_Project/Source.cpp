#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void output_vector(const string& file, const vector<double>& v) {
	ofstream output(file);
	for (double num : v) {
		output << num; output << " ";
	}
}

int main(int argc, char *argv[])
{
	/*cout << "You have entered " << argc << " args:" << endl;

	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
	}*/

	string output_path = "C:/Users/atika/Documents/GitHub/numerical_computing/Text Files/exercise_10_output.txt";
	ofstream output(output_path); // Create the file if it doesn't already exist
	vector<double> my_vec = { 2.5, 6.88, 12, 3.4 };
	output_vector(output_path, my_vec);
	if (!output.is_open()) {
		cout << "Error: Couldn't create the file" << endl;
	}

	return 0;
}