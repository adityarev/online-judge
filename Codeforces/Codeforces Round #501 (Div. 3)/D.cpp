#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

typedef long long LL;

using namespace std;

int
main() {
	int n, k;
	LL s;
	cin >> n >> k >> s;
	
	if ((LL)((n - 1) * (LL)k) < s || k > s) {
		puts("NO");
		return 0;
	}
	
	int curr = 1;
	int max_move = n - 1;
	vector<int> ans;
	
	while ((s - max_move) >= k) {
		if (curr == 1)
			curr = n;
		else if (curr == n)
			curr = 1;
		
		ans.push_back(curr);
		s -= max_move;
		k--;
	}
	
	if (k > 0) {
		int first_step = (s - k + 1);
		
		if (curr == 1)
			curr += first_step;
		else if (curr == n)
			curr -= first_step;
		
		ans.push_back(curr);
		s -= first_step;
		k--;
		
		bool moving_right;
		
		while (k > 0) {
			if (curr == n)
				moving_right = false;
			else if (curr == 1)
				moving_right = true;
			
			if (moving_right)
				curr++;
			else
				curr--;
			
			ans.push_back(curr);
			k--;
		}
	}
	
	puts("YES");
	for (int i = 0, sz = (int)ans.size(); i < sz; i++)
		cout << ans[i] << (i == sz - 1 ? "\n" : " ");
	
	return 0;
}

