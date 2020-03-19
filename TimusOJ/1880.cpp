#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>

#define N_BLOCK 3

using namespace std;

int
main() {
	map<int,int> count[N_BLOCK];
	
	for (int i = 0; i < N_BLOCK; i++) {
		int n;
		cin >> n;
		
		while (n--) {
			int x;
			cin >> x;
			
			count[i][x]++;
		}
	}
	
	map<int,bool> taken;
	int ans = 0;
	
	for (int i = 0; i < N_BLOCK; i++) {
		for (auto it = count[i].begin(); it != count[i].end(); it++) {
			int key = it->first;
			int val = it->second;
			
			if (!taken[key]) {
				if (
					count[0].find(key) != count[0].end()
					&& count[1].find(key) != count[1].end()
					&& count[2].find(key) != count[2].end()
				) {
					int min_val = INT_MAX;
					
					for (int j = 0; j < N_BLOCK; j++)
						min_val = min(min_val, count[i][key]);
					
					ans += min_val;
				}
				
				taken[key] = true;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

