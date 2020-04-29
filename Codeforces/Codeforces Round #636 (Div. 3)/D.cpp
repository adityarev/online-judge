#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)
#define endline pc('\n')

typedef long long LL;

using namespace std;

int
main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> arr(n);
		for (int& x: arr)
			cin >> x;
		
		map<int,int> zero_change;
		vector<int> prefix(2 * k + 2, 0);
		
		for (int i = 0, len = (n >> 1); i < len; i++) {
			int min_val = min(arr[i], arr[n - 1 - i]);
			int max_val = max(arr[i], arr[n - 1 - i]);
			int sum = min_val + max_val;
			
			zero_change[sum]++;
			
			int l = min_val + 1;
			int r = max_val + k;
			
			prefix[l]++;
			prefix[r + 1]--; 
		}
		
		int ans = INT_MAX;
		int curr = 0;
		
		for (int i = 2, lim = 2 * k; i <= lim; i++) {
			curr += prefix[i];
			
			int zero = zero_change[i];
			int one = curr - zero;
			int two = (n / 2) - (one + zero);
			int count = one + (2 * two);
			
			ans = min(ans, count);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

