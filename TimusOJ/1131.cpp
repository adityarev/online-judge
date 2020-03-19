#include <algorithm>
#include <iostream>

int
get_ans(int &n, int &k) {
	int ans = 0;
	int installed = 1;
	int not_installed = n - 1;
	
	while (not_installed > 0 && installed < k) {
		int curr = std::min(installed, not_installed);
		
		ans++;
		installed += curr;
		not_installed -= curr;
	}
	
	ans += (not_installed / k);
	not_installed %= k;
	
	if (not_installed > 0)
		ans++;
	
	return ans;
}

int
main() {
	int n, k;
	std::cin >> n >> k;
	
	int ans = get_ans(n, k);
	std::cout << ans << std::endl;
	
	return 0;
}

