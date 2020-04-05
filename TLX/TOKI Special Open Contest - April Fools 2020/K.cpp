#include <iostream>
#include <vector>

int
main() {
	std::vector<std::string> ans = {"Rock", "Paper", "Scissor"};
	int p = 0;
	const int n = 1;
	
	while (true) {
		std::cout << ans[2] << std::endl;
		std::cout << std::flush;
		
		p++;
	}
	
	return 0;
}

