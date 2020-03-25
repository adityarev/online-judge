#include <algorithm>
#include <iostream>

int
main() {
	int row, col;
	std::cin >> row >> col;
	
	int x, y;
	std::cin >> x >> y;
	
	int c1 = y + x;
	int c2 = y - x;
	int space = std::max(col - y, y - 1);
	
	int x1, y1;
	std::cin >> x1 >> y1;
	
	int sum = y1 + x1;
	
	if (
		(y1 + x1) >= c1 && (y1 - x1) <= c2
		&& x1 >= x && ((int)abs(sum - c1) % 2 == 0)
	) {
		std::cout << "YA" << std::endl;
	} else {
		std::cout << "TIDAK" << std::endl;
	}
 	
	return 0;
}

