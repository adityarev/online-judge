#include <iostream>
#include <string>
#include <vector>

const int ASCII_SIZE = 256;
int hash[ASCII_SIZE];

std::vector<std::string> button_chars = {
	".,!", "abc", "def", "ghi", "jkl",
	"mno", "pqr", "stu", "vwx", "yz",
	" "
};

void
precompute() {
	for (std::string chs: button_chars) {
		for (int i = 0; i < chs.length(); i++) {
			int cost = i + 1;
			hash[(int)chs[i]] = cost;
		}
	}
}

int
get_cost(std::string &str) {
	int cost = 0;
	for (char c: str) {
		cost += hash[(int)c];
	}
	return cost;
}

int
main() {
	precompute();
	
	std::string str;
	std::getline(std::cin, str);
	
	int ans = get_cost(str);
	std::cout << ans << std::endl;
	
	return 0;
}

