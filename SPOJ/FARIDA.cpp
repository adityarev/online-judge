#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX 10000

#define gc(x) getchar(x)
#define pc(x) putchar(x)

typedef long long LL;

using namespace std;

int scanint() {
	bool minus = false;
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc()) {
		if (c == '-') {
			while ((c = gc()) == '-');
			if (c > 47 && c < 58) {
				minus = true;
				break;
			}
		}
	}
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return minus ? -val : val;
}

int main()
{
	LL dp[MAX];
	memset(dp, 0LL, sizeof(dp));
	
	int tc = scanint();
	
	while (tc--) {
		static int cases = 0;
		
		int n = scanint();
		
		for (int i = 0; i < n; i++) {
			int val = scanint();
			
			if (i == 0)
				dp[i] = val;
			else if (i == 1)
				dp[i] = max((LL)val, dp[i - 1]);
			else
				dp[i] = max((LL)val, max(dp[i - 1], (dp[i - 2] + (LL)val)));
		}
		
		printf("Case %d: %lld\n", ++cases, dp[n - 1]);
		memset(dp, 0LL, sizeof(LL) * n);
	}
	
	return 0;
}

