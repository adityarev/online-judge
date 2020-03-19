#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const int MIN = 1;
const int MAX = 8;

bool
is_in_range(int val) {
	return (MIN <= val && val <= MAX);
}

int get_ans(string &pos) {
	int x = (int)(pos[0] - 'a') + 1;
	int y = (int)(pos[1] - '0');
	
	vector<int> vs = {-2, -1, 1, 2};
	int count = 0;
	
	for (int v: vs) {
		int h_val = 2 - ((abs(v) + 1) % 2);
		vector<int> hs = {h_val, -h_val};
		
		for (int h: hs) {
			if (is_in_range(x + v) && is_in_range(y + h))
				count++;
		}
	}
	
	return count;
}

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		string pos;
		cin >> pos;
		
		int ans = get_ans(pos);
		cout << ans << endl;
	}
	
	return 0;
}

