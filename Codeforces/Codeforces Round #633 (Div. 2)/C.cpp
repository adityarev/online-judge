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
		
		vector<LL> arr(n);
		for (LL& x: arr)
			cin >> x;
		
		int ans = 0;
		LL prev = arr[0];
		
		for (int a = 1; a < n; a++) {
			int req_time = 0;
			
			LL plus;
			LL curr = arr[a];
			
			while (curr < prev) {
				req_time++;
				plus = (LL)pow(2LL, req_time - 1);
				curr += plus;
			}
			
			for (int i = req_time - 1; i >= 0; i--) {
				plus = (LL)pow(2LL, i);
				if ((curr - plus) >= prev)
					curr -= plus;
			}
			
			prev = curr;
			ans = max(ans, req_time);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
