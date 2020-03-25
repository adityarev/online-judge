#pragma GCC optimize("O3")
#pragma GCC target("avx")

#include <iostream>
#include <vector>

int
get_ans(int &n, int &k) {
	if (n < k)
		return 0;
	
	int ans = 1;
	std::vector<bool> taken(n + 1, false);
	
	for (int i = k + k; i <= n; i += k) {
		if (!taken[i]) {
			ans++;
			for (int j = i + i; j <= n; j += i)
				taken[j] = true;
		}
	}
	
	return ans;
}

int
main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	
	int n, k;
	std::cin >> n >> k;
	
	int ans = get_ans(n, k);
	std::cout << ans << std::endl;
	
	return 0;
}

