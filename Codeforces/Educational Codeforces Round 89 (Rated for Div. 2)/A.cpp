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
		int a, b;
		cin >> a >> b;
		
		int ans = 0;
		int diff = abs(a - b);
		
		if (diff > a) {
			ans = a;
		} else if (diff > b) {
			ans = b;
		} else {
			ans += diff;
			
			if (a > b) {
				a -= 2 * diff;
				b -= diff;
			} else {
				a -= diff;
				b -= 2 * diff;
			}
			
			ans += 2 * (min(a, b) / 3);
			a %= 3;
			b %= 3;
			
			if ((a >= 1 && b >= 2) or (a >= 1 && b >= 2))
				ans++;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

