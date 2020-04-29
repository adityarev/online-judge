#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

typedef long long LL;

using namespace std;

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> arr(n);
		for (int& x: arr)
			cin >> x;
		
		sort(arr.begin(), arr.end());
		
		LL sum = 0;
		int counter = 0;
		int p = n - 1;
		
		while (p >= 0) {
			sum += (LL)arr[p];
			
			if (sum / (counter + 1) >= k)
				counter++;
			else
				break;
			
			p--;
		}
		
		cout << counter << endl;
	}
	
	return 0;
}

