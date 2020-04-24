#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int sum = 0, x, a, b;
	cin >> x;
	a = min(x, 1);
	b = max(x, 1);
	for (int i=a; i<=b; i++)
		sum += i;
	cout << sum << endl;
	return 0;
}
