#include <algorithm>
#include <iostream>

int
main() {
	int x, y, c;
	std::cin >> x >> y >> c;
	
	int sum = x + y;
	
	if (sum < c) {
		std::cout << "Impossible" << std::endl;
	} else {
		int a = std::min(x, c);
		int b = std::max(0, c - a);
		
		std::cout << a << " " << b << std::endl;
	}
	
	return 0;
}

