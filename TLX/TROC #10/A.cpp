#include <functional>
#include <iostream>
#include <string>

const int ASCII_DISTANCE = (int)('a' - 'A');

std::string
get_ans(std::string &s, std::string &t) {
	std::function<char(char&)> lower_case = [&](char &c) -> char {
		return ('A' <= c && c <= 'Z') ? (c + ASCII_DISTANCE) : c;
	};
	
	int len = s.length();
	
	for (int i = 0; i < len; i++)
		if (lower_case(s[i]) != lower_case(t[i]))
			return "x_x";
	
	return "20/20";
}

int
main() {
	std::string s;
	std::cin >> s;
	
	std::string t;
	std::cin >> t;
	
	std::string ans = get_ans(s, t);
	std::cout << ans << std::endl;
	
	return 0;
}

