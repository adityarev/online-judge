#include <iostream>

int
main() {
	int n, k;
	std::cin >> n >> k;
	
	int diff_count = 0;
	
	for (int i = 0; i < n; i++) {
		int b, g;
		std::cin >> b >> g;
		
		diff_count += (b - (g + 2));
	}
	
	int ans = diff_count + (k - 2);
	
	if (ans < 0)
		std::cout << "Big Bang!" << std::endl;
	else
		std::cout << ans << std::endl;
	
	return 0;
}

