#include <algorithm>
#include <climits>
#include <iostream>

int
get_ans(int a1, int add, int a2, int sub) {
	int prev_add = INT_MAX;
	int prev_sub = INT_MAX;
	
	int curr_add = a1;
	int curr_sub = a2;
	
	while (curr_add <= curr_sub) {
		prev_add = curr_add;
		prev_sub = curr_sub;
		
		curr_add += add;
		curr_sub -= sub;
	}
	
	return std::min(curr_add, prev_sub);
}

int
main() {
	int a1, add, a2, sub;
	std::cin >> a1 >> add >> a2 >> sub;
	
	int ans = get_ans(a1, add, a2, sub);
	std::cout << ans << std::endl;
	
	return 0;
}

