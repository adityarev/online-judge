#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

int
main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
	int n;
	std::cin >> n;
	
	std::vector<int> arr(n + 1, 0);
	
	for (int i = 1; i <= n; i++) {
		int x;
		std::cin >> x;
		arr[i] = arr[i - 1] + x;
	}
	
	int que;
	std::cin >> que;
	
	while (que--) {
		int x;
		std::cin >> x;
		
		auto it = std::lower_bound(arr.begin(), arr.end(), x);
		int ans = std::distance(arr.begin(), it);
		
		std::cout << ans << std::endl;
	}
	
	return 0;
}
