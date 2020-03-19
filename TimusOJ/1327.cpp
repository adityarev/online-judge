#include <iostream>

int
odd_count_till(int n) {
	return (n + 1) >> 1;
}

int
main() {
	int a, b;
	std::cin >> a >> b;
	
	int ans = odd_count_till(b) - odd_count_till(a - 1);
	std::cout << ans << std::endl;
	
	return 0;
}

