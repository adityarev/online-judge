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
		int n;
		cin >> n;
		
		if ((n >> 1) & 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			
			int len = n / 2;
			int sum = 0;
			vector<int> ans;
			
			// Even
			for (int i = 0; i < len; i++) {
				int x = (i + 1) * 2;
				
				sum += x;
				ans.push_back(x);
			}
			
			int l = 0;
			int r = len - 1;
			
			// Odd
			for (int i = 0; i < (len >> 1); i++) {
				int val1 = ans[l] - 1;
				int val2 = ans[r] + 1;
				
				ans.push_back(val1);
				ans.push_back(val2);
				
				l++;
				r--;
			}
			
			// Ans
			for (int i = 0; i < n; i++)
				cout << ans[i] << (i == n - 1 ? "\n" : " ");
		}
	}
	
	return 0;
}

