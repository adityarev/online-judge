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
    
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n;
		cin >> n;
		
		map<int,int> counter;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			counter[x]++;
		}
		
		int ans = INT_MIN;
		int team1 = (int)counter.size() - 1;
		
		for (auto it = counter.begin(); it != counter.end(); it++) {
			int key = it->first;
			int val = it->second;
			
			int prob = max(min(team1, val), min(team1 + 1, val - 1));
			ans = max(ans, prob);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

