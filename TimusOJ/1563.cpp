#include <cstdio>
#include <iostream>
#include <map>

void
build_hash_count(std::map<std::string,int> &hash_count) {
	int n;
	std::cin >> n; getchar(); 
	
	for (int i = 0; i < n; i++) {
		std::string s;
		std::getline(std::cin, s);
		
		hash_count[s]++;
	}
}

int
get_ans(std::map<std::string,int> &hash_count) {
	int ans = 0;
	
	for (auto it = hash_count.begin(); it != hash_count.end(); it++) {
		int count = it->second;
		ans += (count - 1);
	}
	
	return ans;
}

int
main() {
	std::map<std::string,int> store_count;
	build_hash_count(store_count);
	
	int ans = get_ans(store_count);
	std::cout << ans << std::endl;
	
	return 0;
}

