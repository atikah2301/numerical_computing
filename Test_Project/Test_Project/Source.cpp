#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

int main(int argc, char *argv[])
{
	cout << "You have entered " << argc << " args:" << endl;

	for (int i = 0; i < argc; i++) {
		cout << argv[i] << endl;
	}

	return 0;
}