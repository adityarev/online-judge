// UNSOLVED

#include <cmath>
#include <iostream>

void
solve(std::string &s) {
	auto get_sum = [&](int start, int len) -> int {
		int sum = 0;
		int end = start + len;
		
		for (int i = start; i < end; i++)
			sum += (int)(s[i] - '0');
		return sum;
	};
	
	int left_sum = get_sum(0, 3);
	int right_sum = get_sum(3, 3);
	
//	std::cout << left_sum << " "
//			  << right_sum << std::endl;
	
	bool lucky = (abs(left_sum - right_sum) == 1);
	std::cout << (lucky ? "Yes" : "No") << std::endl;
}

int
main() {
	std::string s;
	std::cin >> s;
	
	solve(s);
	return 0;
}

