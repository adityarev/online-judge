#include <algorithm>
#include <iostream>
#include <vector>

const int HASH_SIZE = 101;
const int MIN_VAL = 600;
const int DIVIDER = 4;

int
hash_val(int &val) {
	return val - MIN_VAL;
}

void
build_hash(std::vector<int> &hash, int &n) {
	for (int i = 0; i < n; i++) {
		int val;
		std::cin >> val;
		
		hash[hash_val(val)]++;
	}
}

int
get_ans(std::vector<int> &hash) {
	int ans = 0;
	
	for (int val: hash)
		ans += val / DIVIDER;
	
	return ans;
}

int
main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);
	
	int n;
	std::cin >> n;
	
	std::vector<int> hash(HASH_SIZE, 0);
	build_hash(hash, n);
	
	int ans = get_ans(hash);
	std::cout << ans << std::endl;
	
	return 0;
}

