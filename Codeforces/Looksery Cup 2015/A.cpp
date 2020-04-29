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
	int row, col;
	cin >> row >> col;
	
	vector<string> grid(row);
	for (string& s: grid)
		cin >> s;
	
	int ans = 0;
	
	for (int i = 0; i < row - 1; i++) {
		for (int j = 0; j < col - 1; j++) {
			string str = "";
			
			for (int k = 0; k < 2; k++)
				for (int l = 0; l < 2; l++)
					str += grid[i + k][j + l];
			
			sort(str.begin(), str.end());
			
			if (str == "acef")
				ans++;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

