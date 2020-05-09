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
#include <string>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)
#define endline pc('\n')

typedef long long LL;

using namespace std;

const int MAX = 1e9;

LL
f(LL n) {
	return (n * (3LL * n + 1LL)) >> 1;
}

LL
nearest_f(LL x) {
	LL l = 0;
	LL r = (LL)MAX;
	
	LL mid;
	LL ans;
	
	while (l <= r) {
		mid = l + ((r - l + 1LL) >> 1);
		ans = f(mid);
		
		if (ans < x)
			l = mid + 1;
		else if (ans > x)
			r = mid - 1;
		else
			return ans;
	}
	
	while (ans > x) {
		mid--;
		ans = f(mid);
	}
	
	return ans;
}

int
get_ans(LL& n) {
	LL temp = n;
	LL f_val;
	int counter = 0;
	
	while ((f_val = nearest_f(temp)) > 0) {
		counter++;
		temp -= f_val;
	}
	
	return counter;
}

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		LL n;
		cin >> n;
		
		int ans = get_ans(n);
		cout << ans << endl;
	}
	
	return 0;
}

