#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iterator>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
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
		int n, x, que;
		cin >> n >> x >> que;
		
		int l = x;
		int r = x;
		
		while (que--) {
			int a, b;
			cin >> a >> b;
			
			if (a <= r && r <= b)
				r = b;
			if (a <= l && l <= b)
				l = a;
		}
		
		int ans = (r - l) + 1;
		cout << ans << endl;
	}
	
	return 0;
}

