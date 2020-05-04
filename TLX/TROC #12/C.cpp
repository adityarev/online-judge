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

bool
possible(int n, int m, int k) {
	int mul = n * m;
	int sq_root = (int)ceil(sqrt(mul));
	int max_val = max(n, m);
	
	return k >= sq_root && (k >= ((n / 2) + (m / 2)) && (k > (max_val / 2)));
}

enum {
	RIGHT = 0,
	DOWN,
	LEFT,
	UP,
};

const int N_DIR = 4;
vector<vector<int>> moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool
is_in_range(int val, int start, int end) {
	return (start <= val && val <= end);
}

void
print_grid(int n, int m, int k) {
	vector<vector<bool>> grid(n, vector<bool>(m, false));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	
	int i = 0;
	int j = 0;
	int take_count = 0;
	
	for (int j = 0; j < m && take_count < k; j += 2) {
		if (!grid[0][j]) {
			grid[0][j] = true;
			take_count++;
		}
	}
	for (int i = n - 1; i >= 0 && take_count < k; i -= 2) {
		if (!grid[i][m - 1]) {
			grid[i][m - 1] = true;
			take_count++;
		}
	}
	
	for (int i = 0; i < n && take_count < k; i++) {
		for (int j = 0; j < m && take_count < k; j++) {
			if (!grid[i][j]) {
				grid[i][j] = true;
				take_count++;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j])
				cout << "X";
			else
				cout << ".";
		}
		cout << endl;
	}
}

int
main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	int max_val = max(n, m);
	
	if (!possible(n, m, k)) {
		cout << "TIDAK" << endl;
	} else {
		cout << "YA" << endl;
		print_grid(n, m, k);
	}
	
	return 0;
}

