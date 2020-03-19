#include <algorithm>
#include <iostream>
#include <vector>

void
set_arr(std::vector<int> &arr, int &n) {
	for (int i = 1; i <= n; i++)
		std::cin >> arr[i];
}

int
get_ans(std::vector<int> &arr, int &n) {
	int ans = 0;
	for (int i = 1; i <= (n + 1); i++)
		ans += std::max(arr[i], arr[i - 1]);
	return ans;
} 

int
main() {
	int n;
	std::cin >> n;
	
	std::vector<int> arr(n + 2, 0);
	set_arr(arr, n);
	
	std::sort(arr.begin() + 1, arr.end() - 1);
	
	int ans = get_ans(arr, n);
	std::cout << ans << std::endl;
	
	return 0;
}

