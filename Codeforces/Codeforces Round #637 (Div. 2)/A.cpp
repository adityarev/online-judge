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

bool
possible(int n, int a, int b, int c, int d) {
	int l1 = (a - b) * n;
	int r1 = (a + b) * n;
	int l2 = c - d;
	int r2 = c + d;
	
	return (l1 <= r2 && l2 <= r1);
}

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;
		
		if (possible(n, a, b, c, d))
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}

