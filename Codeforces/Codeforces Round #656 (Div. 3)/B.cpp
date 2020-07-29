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

using namespace std;

typedef long long LL;

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n;
		cin >> n;
		
		vector<bool> taken(n + 1, false);
		vector<int> arr;
		
		for (int i = 0; i < 2 * n; i++) {
			int x;
			cin >> x;
			
			if (!taken[x]) {
				arr.push_back(x);
				taken[x] = true;
			}
		}
		
		for (int i = 0; i < n; i++)
			cout << arr[i] << (i == n - 1 ? "\n" : " ");
	}
	
	return 0;
}

