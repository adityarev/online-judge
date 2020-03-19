#include <algorithm>
#include <iostream>
#include <vector>

int
get_ans(std::vector<int> &arr) {
	static const int LIM = 5;
	int ans = 0;
	
	std::sort(arr.begin(), arr.end(), std::greater<int>());
	for (int i = 0; i < LIM; i++)
		ans += arr[i];
	
	return ans;
}

void
run_case() {
	int n;
	std::cin >> n;
	
	std::vector<int> arr(n);
	for (int &x: arr)
		std::cin >> x;
	
	int ans = get_ans(arr);
	std::cout << ans << std::endl;
}

int
main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int tc;
	std::cin >> tc;
	
	for (int i = 0; i < tc; i++)
		run_case();
	
	return 0;
}

