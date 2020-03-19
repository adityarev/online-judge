#include <iostream>
#include <string>
#include <vector>

int
main() {
	int n;
	std::cin >> n;
	
	if (n <= 4) {
		const std::vector<std::string> overtuned = {"16", "06", "68", "88"};
		bool first = true;
		
		for (int i = 0; i < n; i++) {
			if (first)
				first = false;
			else
				std::cout << " ";
			std::cout << overtuned[i];
		}
		std::cout << std::endl;
	} else {
		std::cout << "Glupenky Pierre" << std::endl;
	}
	
	return 0;
}

