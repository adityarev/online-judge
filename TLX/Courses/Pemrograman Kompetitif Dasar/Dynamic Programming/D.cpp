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

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)
#define endline pc('\n')

typedef long long LL;

using namespace std;

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		string s;
		cin >> s;
		
		int len = (int)s.length();
		vector<vector<int>> dp(len, vector<int>(len, 0));
		
		for (int i = 0; i < len; i++)
			dp[i][i] = 1;
		
		for (int sz = 2; sz <= len; sz++) {
			for (int i = 0; i < (len - sz + 1); i++) {
				int l = i;
				int r = i + sz - 1;
				int j = r;
				
				if (s[l] == s[r] && sz == 2)
					dp[i][j] = 2;
				else if (s[l] == s[r])
					dp[i][j] = dp[i + 1][j - 1] + 2;
				else
					dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
		
		int ans = dp[0][len - 1];
		cout << ans << endl;
	}
	
	return 0;
}

