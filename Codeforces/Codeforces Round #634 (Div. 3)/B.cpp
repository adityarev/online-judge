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


string
repeated_str(int len, int n_dist) {
	int i;
	string s = "";
	
	for (i = 0; i < n_dist - 1; i++)
		s += ('a' + (i % 26));
	
	int temp = i;
	while (i < len) {
		s += ('a' + (temp % 26));
		i++;
	}
	
	return s;
}

int
main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n, len, n_dist;
		cin >> n >> len >> n_dist;
		
		string ans = "";
		string s = repeated_str(len, n_dist);
		
		for (int i = 0; i < n; i++)
			ans += s[i % len];
		
		cout << ans << endl;
	}
	
	return 0;
}

