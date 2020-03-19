#include <functional>
#include <iostream>
#include <string>

std::string
get_an(int start, int end) {
	std::function<std::string(int)> build_an = [&](int curr) -> std::string {
		if (curr > end)
			return "";
		
		std::string prefix = (curr & 1 ? "+" : "-");
		std::string s = prefix + "sin(" + std::to_string(curr) + build_an(curr + 1) + ")";
		
		return s;
	};
	
	std::string an = build_an(start);
	return an.substr(1, an.length());
}

std::string
get_sn(int start, int end) {
	std::function<std::string(int)> build_sn = [&](int curr) -> std::string {
		if (curr > end)
			return "";
		
		std::string prefix = build_sn(curr + 1);
		std::string an = get_an(start, (end - curr + 1));
		std::string s = "(" + prefix + ")" + an + "+" + std::to_string(curr);
		
		return s;
	};
	
	int remove_pos = end - start;
	std::string sn = build_sn(start);
	
	sn.erase(remove_pos, 2);
	return sn.substr(0, sn.length());
}

int
main() {
	int n;
	std::cin >> n;
	
	std::string s = get_sn(1, n);
	std::cout << s << std::endl;
	
	return 0;
}

