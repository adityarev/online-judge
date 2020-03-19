#include <algorithm>
#include <iostream>
#include <vector>

typedef long long LL;

LL
get_ans(
	std::vector<LL> &arr,
	LL &budget,
	LL &sum
) {
	if (sum <= budget)
		return -1LL;
	
	int emp_left = (int)arr.size();
	LL budget_left = budget;
	
	for (LL &x: arr) {
		LL mean = budget_left / emp_left;
		
		if (x > mean)
			break;
		
		budget_left -= x;
		emp_left--;
	}
	
	return budget_left / emp_left;
}

void
run_case() {
	int n;
	LL budget;
	std::cin >> n >> budget;
	
	LL sum = 0;
	
	std::vector<LL> arr(n);
	for (LL &x: arr) {
		std::cin >> x;
		sum += x;
	}
	std::sort(arr.begin(), arr.end());
	
	LL ans = get_ans(arr, budget, sum);
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

