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
		LL n;
		cin >> n;
		
		LL ans = (n - 1) >> 1;
		cout << ans << endl;
	}
	
	return 0;
}

