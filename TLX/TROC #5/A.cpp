#include <iostream>
#include <string>

using namespace std;

int
main() {
	string x, y;
	cin >> x >> y;
	
	if (x.find(y) == -1) {
		cout << "YA" << endl;
		cout << x << endl;
	} else {
		cout << "TIDAK" << endl;
	}
	
	return 0;
}

