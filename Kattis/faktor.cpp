#include <cmath>
#include <iostream>

int
main() {
	int a, b;
	std::cin >> a >> b;
	
	int ans = a * b - (a - 1);
	std::cout << ans << std::endl;
	
	return 0;
}

