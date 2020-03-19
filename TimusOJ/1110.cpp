/*
 * Modular Exponentiation Problem
 * x -> base number
 * n -> power
 * m -> modulo
 */

#include <iostream>
#include <vector>

int
modexp(int x, int n, int m) {
	int res = 1;
	
	x = x % m;
	while (n > 0) {
		if (n & 1)
			res = (res * x) % m;
		n = n >> 1;
		x = (x * x) % m;
	}
	
	return res;
}

std::vector<int>
get_ans(int n, int m, int y) {
	std::vector<int> ans;
	
	for (int i = 0; i < m; i++) {
		int res = modexp(i, n, m);
		if (res == y)
			ans.push_back(i);
	}
	
	return ans;
}

void
show_ans(std::vector<int> &ans) {
	if (ans.size() == 0) {
		std::cout << -1 << std::endl;
		return;
	}
	
	bool first = true;
	for (int num: ans) {
		if (first)
			first = false;
		else
			std::cout << " ";
		std::cout << num;
	}
	std::cout << std::endl;
}

int
main() {
	int n, m, y;
	std::cin >> n >> m >> y;
	
	std::vector<int> ans = get_ans(n, m , y);
	show_ans(ans);
	
	return 0;
}

