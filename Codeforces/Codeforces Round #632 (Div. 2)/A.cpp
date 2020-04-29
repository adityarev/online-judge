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
#include <set>
#include <string>
#include <vector>

using namespace std;

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int row, col;
		cin >> row >> col;
		
		vector<vector<char>> ans(row, vector<char>(col));
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if ((i + j) % 2 == 0)
					ans[i][j] = 'B';
				else
					ans[i][j] = 'W';
			}
		}
		if ((row * col) % 2 == 0) {
			if (ans[row - 1][col - 1] == 'W') {
				ans[row - 1][col - 1] = 'B';
			} else {
				if (ans[0][col - 1] == 'W')
					ans[0][col - 1] = 'B';
			}
		}
		
		for (vector<char>& arr: ans) {
			for (char& c: arr)
				putchar(c);
			putchar('\n');
		}
	}
	
	return 0;
}

