#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int getRoot(int a, int b, int c) {
	int D = b * b - (4 * a *c);
	int root = (-b + (int)pow(D, 0.5)) / (2 * a);
	
	return root;
}

int main()
{
	int tc;
	cin >> tc;
	
	for (int i = 0; i < tc; i++) {
		int x;
		cin >> x;
		
		int a = 1;
		int b = 1;
		int c = -2 * x;
		
		int root = getRoot(a, b, c);
		cout << "Case #" << (i + 1) << ": ";
		
		if ((root * (root + 1) / 2) == x) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	
	return 0;
}
