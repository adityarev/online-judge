#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	
	if ((abs(a) >= b && b >= -abs(a)) && (abs(a - b) % 2 == 0)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
	return 0;
}
