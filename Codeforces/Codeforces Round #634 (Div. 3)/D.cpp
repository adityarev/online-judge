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
	scanf("%d%*c", &tc);
	
	while (tc--) {
		int n = 9;
		vector<vector<char>> matrix(n, vector<char>(n));
		
		for (vector<char>& arr: matrix) {
			for (char& x: arr)
				x = gc();
			gc();
		}
		
		int j;
		for (int i = 0; i < n; i++) {
			if (i % 3 == 0)
				j = i / 3;
			
			matrix[i][j] = ('1' + (int)((matrix[i][j] - '1' + 1) % n));
			j += 3;
		}
		
		// Ans
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				pc(matrix[i][j]);
			endline;
		}
	}
	
	return 0;
}

