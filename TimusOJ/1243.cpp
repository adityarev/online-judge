#include <iostream>
#include <string>

int
get_ans(std::string num) {
	const int divider = 7;
	
	int ans = 0;
	int i = 0;
	
	while (i < num.length()) {
		ans *= 10;
		ans += (int)(num[i] - '0');
		ans %= divider;
		
		i++;
	}
	
	return ans;
}

int
main() {
	std::string num;
	std::cin >> num;
	
	int ans = get_ans(num);
	std::cout << ans << std::endl;
	
	return 0;
}

