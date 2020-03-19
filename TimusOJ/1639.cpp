#include <iostream>

int
main() {
	int a, b;
	std::cin >> a >> b;
	
	if ((a & 1) == 1 && (b & 1) == 1)
		std::cout << "[second]=:]" << std::endl;
	else
		std::cout << "[:=[first]" << std::endl;
	
	return 0;
}

