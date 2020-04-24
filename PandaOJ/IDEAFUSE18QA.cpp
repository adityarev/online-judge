#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int sum = 0;
	int min_val = INT_MAX;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		sum += x;
		min_val = min(min_val, x);
	}
	
	cout << (sum - min_val) << endl;
	
	return 0;
}
