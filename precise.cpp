#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    
    stringstream ss;
    double f = 3.14159;
    
    ss << setprecision(2) << f;
    double g;
    ss >> g;
    cout << g;
	
}