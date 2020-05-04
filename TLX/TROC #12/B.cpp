#include <algorithm>
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

int
main() {
	int n;
	cin >> n;
	
	vector<int> arr(n + 1);
	for (int &x: arr)
		cin >> x;
	
	LL carry = 0;
	LL capacity = (LL)pow(2LL, n);
	LL ans = 0;
	
	for (int i = 0; i <= n; i++) {
		LL curr = arr[n - i] * (1LL << (n - i));
		carry += curr;
		ans += (carry / capacity);
		carry -= (carry / capacity) * capacity;
	}
	
	if (carry != 0)
		cout << -1 << endl;
	else
		cout << ans << endl;
	
	return 0;
}

