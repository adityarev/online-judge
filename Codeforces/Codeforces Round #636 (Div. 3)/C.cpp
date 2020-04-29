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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n;
		cin >> n;
		
		vector<int> arr(n);
		for (int& x: arr)
			cin >> x;
			
		LL ans = 0;
		
		for (int i = 0; i < n; i++) {
			int selected = arr[i];
			
			if (arr[i] < 0) {
				while (i + 1 < n && arr[i + 1] < 0) {
					selected = max(selected, arr[i + 1]);
					i++;
				}
			} else {
				while (i + 1 < n && arr[i + 1] > 0) {
					selected = max(selected, arr[i + 1]);
					i++;
				}
			}
			
			ans += (LL)selected;
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

