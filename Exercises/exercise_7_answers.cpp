#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Week 7 - Practice and exercise answers

// Function declarations


int main()
{
    // Q1 - Vector elements
    
    // vector<double> v(5, 1); // [1,1,1,1,1]
    
    // vector<double> v{1,2,3,4}; // [1,2,3,4]
    
    // vector<double> v(4); // same as above
    // for (int i=0; i<=3; i++)
    //     v[i] = i+1;
    
    vector<double> v; // same as above
    for (int i=1; i<=4; i++)
        v.push_back(i);
    
    v.resize(8);
    v.pop_back();
    v.clear();
    
    for (int i=0; i<v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    
    
}

// Function definitions


