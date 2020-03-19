#include <iostream>

using namespace std;

int
main() {
	int a0, b0;
	cin >> a0 >> b0;
	
	int a1, b1;
	cin >> a1 >> b1;
	
	int a2, b2;
	cin >> a2 >> b2;
	
	int a = a0 - a2;
	int b = b0 - b1;
	
	cout << a << " " << b << endl;
	
	return 0;
}

