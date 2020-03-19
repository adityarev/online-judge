#include <iostream>

using namespace std;

int
main() {
	int f_lock;
	int s_lock;
	
	cin >> f_lock >> s_lock;
	
	if ((f_lock & 1) == 0 || (s_lock & 1) == 1)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	
	return 0;
}

