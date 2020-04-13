#include <algorithm>
#include <iostream>
#include <vector>

int
main() {
	int x;
	std::cin >> x;
	
	const int N = 3;
	
	int sum = 0;
	std::vector<int> costs(N);
	
	for (int& cost: costs) {
		std::cin >> cost;
		sum += cost;
	}
	std::sort(costs.begin(), costs.end());
	
	int ans = (x / sum) * N;
	int temp = x - ((x / sum) * sum);
	
	for (int& cost: costs) {
		if (temp < cost)
			break;
		temp -= cost;
		ans++;
	}
	
	std::cout << ans << std::endl;
	
	return 0;
}

