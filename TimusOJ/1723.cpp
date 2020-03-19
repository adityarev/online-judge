#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>

const int HASH_SIZE = 26;

int
hash_val(char &c) {
	return (int)(c - 'a');
}

void
build_hash(int hash[], std::string &s) {
	for (int i = 0; i < s.length(); i++)
		hash[hash_val(s[i])]++;
}

char
get_ans(int hash[]) {
	char ans = '\0';
	int max_val = INT_MIN;
	
	for (int i = 0; i < HASH_SIZE; i++) {
		char c = 'a' + i;
		int val = hash[i];
		
		if (val > max_val) {
			ans = c;
			max_val = val;
		}
	}
		
	return ans;
}

int
main() {
	std::string s;
	std::cin >> s;
	
	int hash[HASH_SIZE];
	memset(hash, 0, sizeof(hash));
	build_hash(hash, s);
	
	char ans = get_ans(hash);
	std::cout << ans << std::endl;
	
	return 0;
}

