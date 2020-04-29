#include <iostream>
#include <vector>

using namespace std;

void
set_stones(vector<int>& stones) {
	for (int& stone: stones)
		cin >> stone;
}

int
get_ans(vector<int>& stones) {
	int ans = 0;
	int n;
	vector<int> line;
	
	for (int& stone: stones) {
		while ((n = (int)line.size()) > 0 && line.back() <= stone) {
			if (n == 1)
				ans += stone;
			else
				ans += min(line[n - 2], stone);
			line.pop_back();
		}
		line.push_back(stone);
	}
	
	while ((int)line.size() > 1) {
		line.pop_back();
		ans += line.back();
	}
	
	return ans;
}

int
main() {
	int n;
	cin >> n;
	
	vector<int> stones(n);
	set_stones(stones);
	
	int ans = get_ans(stones);
	cout << ans << endl;
	
	return 0;
}

