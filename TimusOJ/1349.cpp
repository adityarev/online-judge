#include <iostream>

int
main() {
	int n;
	std::cin >> n;
	
	if (n == 1)
		std::cout << "1 2 3" << std::endl;
	else if (n == 2)
		std::cout << "3 4 5" << std::endl;
	else
		std::cout << "-1" << std::endl;
	
	return 0;
}

