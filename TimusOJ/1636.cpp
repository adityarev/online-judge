#include <iostream>
#include <vector>

int
main() {
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(NULL);
	
	int qxx, zzz;
	std::cin >> qxx >> zzz;
	
	const int n = 10;
	const int penalty = 20;
	
	int time;
	
	for (int i = 0; i < n; i++) {
		int time;
		std::cin >> time;
		
		qxx += (time * penalty);
	}
	
	if (qxx <= zzz)
		std::cout << "No chance." << std::endl;
	else
		std::cout << "Dirty debug :(" << std::endl;
	
	return 0;
}

