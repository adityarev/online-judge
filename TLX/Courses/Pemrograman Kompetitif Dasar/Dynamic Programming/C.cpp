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
	int n;
	cin >> n;
	
	vector<int> dp(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		int curr = 0;
		vector<int> dividers = {2, 3, 4};
		
		for (int& divider: dividers) {
			int res = i / divider;
			curr += max(res, dp[res]);
		}
		
		dp[i] = max(i, curr);
	}
	
	int ans = dp[n];
	cout << ans << endl;
	
	return 0;
}

