#include <algorithm>
#include <iostream>

int
main() {
	int n, m;
	std::cin >> n >> m;
	
	int a, b;
	std::cin >> a >> b;
	
	int ans = std::max(((n / a) * (m / b)), ((n / b) * (m / a)));
	std::cout << ans << std::endl;
	
	return 0;
}

