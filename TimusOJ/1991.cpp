#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

std::pair<int,int>
get_ans(std::vector<int> &bombs, int &k) {
	int unused_bomb_count = 0;
	int droid_count = 0;
	
	for (int bomb: bombs) {
		int unused_bomb = std::max(0, bomb - k);
		int droid = std::max(0, k - bomb);
		
		unused_bomb_count += unused_bomb;
		droid_count += droid;
	}
	
	return std::make_pair(unused_bomb_count, droid_count);
}

int
main() {
	int n, k;
	std::cin >> n >> k;
	
	std::vector<int> bombs(n);
	for (int i = 0; i < n; i++)
		std::cin >> bombs[i];
	
	std::pair<int,int> ans = get_ans(bombs, k);
	std::cout << ans.first << " " << ans.second << std::endl;
		
	return 0;
}

