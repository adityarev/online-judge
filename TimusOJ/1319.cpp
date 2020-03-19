#include <algorithm>
#include <iostream>
#include <vector>

bool
is_in_range(int val, int &n) {
	return (0 <= val && val < n);
}

void
build_ans(std::vector<std::vector<int> > &ans, int &n) {
	int num = 0;
	int num_limit = n * n;
	int step = 0;
	
	do {
		int x = std::max(0, (step + 1) - n);
		int y = std::min(n - 1, step);
		
		while (is_in_range(x, n) && is_in_range(y, n)) {
			ans[x][y] = ++num;
			x++;
			y--;
		}
		
		step++;
	} while (num != num_limit);
}

void
show_ans(std::vector<std::vector<int> > &ans) {
	for (std::vector<int> row: ans) {
		bool first = true;
		
		std::reverse(row.begin(), row.end());
		for (int num: row) {
			if (first)
				first = false;
			else
				std::cout << " ";
			std::cout << num;
		}
		std::cout << std::endl;
	}
}

int
main() {
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int> > ans(n, std::vector<int>(n));
	build_ans(ans, n);
	
	show_ans(ans);
	
	return 0;
}

