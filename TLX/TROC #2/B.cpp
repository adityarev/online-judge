#include <iostream>

int
main() {
	int n;
	std::cin >> n;
	
	int k = n - 1;
	std::cout << k << std::endl;
	
	for (int i = 0; i < k - 1; i++)
		std::cout << 1 << " ";
	std::cout << 2 << std::endl;
	
	return 0;
}

