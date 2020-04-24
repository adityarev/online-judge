#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int tc;
	double x, a, y, b;
	
	cin >> tc;
	while (tc--)
	{
		cin >> x >> a >> y >> b;
		if (a * log10(x) == b * log10(y)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	return 0;
}
