#include <iostream>
#include <map>
#include <vector>

void
run_input(std::vector<std::string> &arr) {
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		
		arr.push_back(s);
	}
}

std::map<std::string,int>
get_hash(std::vector<std::string> &arr) {
	std::map<std::string,int> hash;
	hash.clear();
	
	for (std::string s: arr)
		hash[s]++;
	
	return hash;
}

void
show_ans(std::map<std::string,int> &hash) {
	for (auto it = hash.begin(); it != hash.end(); it++) {
		std::string key = it->first;
		int value = it->second;
		
		if (value > 1)
			std::cout << key << std::endl;
	}
}

int
main() {
	std::vector<std::string> arr;
	run_input(arr);

	std::map<std::string,int> hash = get_hash(arr);
	show_ans(hash);
	
	return 0;
}

