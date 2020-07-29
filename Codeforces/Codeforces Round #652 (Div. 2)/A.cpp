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
		
		if (n % 4 == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}

