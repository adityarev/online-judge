#include <iostream>

typedef long long LL;

int
main() {
	LL row, col;
	std::cin >> row >> col;
	
	if (col >= row)
		std::cout << ((row - 1LL) * 2LL) << std::endl;
	else
		std::cout << ((col * 2LL) - 1LL) << std::endl;
	
	return 0;
}

