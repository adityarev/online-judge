#include <iostream>

int
main() {
	int n;
	std::cin >> n;
	
	int res = (n + 1) >> 1;
	bool grimy = (res & 1) == 1;
	
	std::cout << (grimy ? "grimy" : "black") << std::endl;
	
	return 0;
}

