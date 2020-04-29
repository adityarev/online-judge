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
	int tc;
	cin >> tc;
	
	while (tc--) {
		int a, b;
		cin >> a >> b;
		
		int cost1, cost2;
		cin >> cost1 >> cost2;
		
		LL sum1 = (LL)abs(a - b) * cost1 + (LL)min(a, b) * cost2;
		LL sum2 = (LL)(a + b) * cost1;
		LL ans = min(sum1, sum2);
		
		cout << ans << endl;
	}
	
	return 0;
}

