#include <climits>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

const std::string EMPEROR = "Emperor Penguin";
const std::string LITTLE = "Little Penguin";
const std::string MACARONI = "Macaroni Penguin";

void
run_input(std::vector<std::string> &names) {
	int n;
	std::cin >> n; getchar();
	
	for (int i = 0; i < n; i++) {
		std::string name;
		std::getline(std::cin, name);
		
		names.push_back(name);
	}
}

void
build_hash(
	std::map<std::string,int> &hash,
	std::vector<std::string> &names
) {
	hash.clear();
	for (std::string name: names) {
		hash[name]++;
	}
}

std::string
get_ans(std::vector<std::string> &names) {
	std::map<std::string,int> hash;
	build_hash(hash, names);
	
	int max_val = INT_MIN;
	std::string ans = "None";
	
	if (hash[EMPEROR] > max_val) {
		max_val = hash[EMPEROR];
		ans = EMPEROR;
	}
	if (hash[LITTLE] > max_val) {
		max_val = hash[LITTLE];
		ans = LITTLE;
	}
	if (hash[MACARONI] > max_val) {
		max_val = hash[MACARONI];
		ans = MACARONI;
	}
	
	return ans;
}

int
main() {
	std::vector<std::string> names;
	run_input(names);
	
	std::string ans = get_ans(names);
	std::cout << ans << std::endl;
	
	return 0;
}

