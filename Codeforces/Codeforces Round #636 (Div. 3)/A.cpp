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
		
		int divisor = 1;
		
		for (int i = 1; ; i++) {
			divisor += (1 << i);
			if (n % divisor == 0) {
				cout << (n / divisor) << endl;
				break;
			}
		}
	}
	
	return 0;
}

