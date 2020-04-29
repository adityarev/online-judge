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

bool
possible(int x, int n, int m) {
	while ((n > 0 && x > 20) && (m * 10 >= x)) {
		int n_hp = (x / 2) + 10;
		int m_hp = x - 10;
		
		if (n_hp <= m_hp) {
			x = n_hp;
			n--;
		} else {
			x = m_hp;
			m--;
		}
	}
	while (n > 0 && x > 20) {
		int n_hp = (x / 2) + 10;
		x = n_hp;
		n--;
	}
	while (m > 0) {
		int m_hp = x - 10;
		x = m_hp;
		m--;
	}
	
	return (x <= 0);
}

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int x, n, m;
		cin >> x >> n >> m;
		
		if (possible(x, n, m))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}

