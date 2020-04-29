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
	int n, k;
	cin >> n >> k;
	
	vector<pair<int,int>> arr(k);
	for (pair<int,int>& x: arr)
		cin >> x.first >> x.second;
	
	vector<int> parent(n + 1, 0);
	vector<int> start(n + 1, 0);
	vector<int> index(n + 1, 0);
	vector<int> sum(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		parent[i] = parent[i - 1];
		start[i] = start[i - 1];
		index[i] = index[i - 1];
		sum[i] = sum[i - 1];
		
		int curr_index = 0;
		
		for (pair<int,int>& x: arr) {
			curr_index++;
			
			int weight = x.first;
			int value = x.second;
			int curr_sum = value + sum[i - weight];
			
			if (curr_sum > sum[i]) {
				parent[i] = start[i];
				start[i] = i;
				index[i] = curr_index;
				sum[i] = curr_sum;
			}
		}
	}
	
	function<void(int)>
	_print_ans = [&](int p) -> void {
		if (index[p] == 0)
			return;
		
		_print_ans(parent[p]);
		cout << index[p] << endl;
	};
	
	_print_ans(start[n]);
	
	return 0;
}

