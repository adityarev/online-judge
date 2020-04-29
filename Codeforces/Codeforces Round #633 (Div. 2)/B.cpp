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
		int n;
		cin >> n;
		
		vector<int> arr(n);
		for (int& x: arr)
			cin >> x;
		
		sort(arr.begin(), arr.end());
		
		int l = 0;
		int r = n - 1;
		list<int> ans;
		
		while (l < r) {
			ans.push_front(arr[r]);
			ans.push_front(arr[l]);
			l++;
			r--;
		}
		if (l == r)
			ans.push_front(arr[l]);
		
		bool first = true;
		for (int& x: ans) {
			if (first)
				first = false;
			else
				cout << " ";
			cout << x;
		}
		cout << endl;
	}
	
	return 0;
}

