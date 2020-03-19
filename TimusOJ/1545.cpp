#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void
run_input(std::vector<std::string> &words) {
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		std::string word;
		std::cin >> word;
		
		words.push_back(word);
	}
}

std::vector<std::string>
get_ans(std::vector<std::string> &words, std::string &prefix) {
	std::vector<std::string> ans;
	
	for (std::string word: words) {
		if (word.find(prefix) == 0)
			ans.push_back(word);
	}
	std::sort(ans.begin(), ans.end());
	
	return ans;
}

int
main() {
	std::vector<std::string> words;
	run_input(words);
	
	std::string prefix;
	std::cin >> prefix;
	
	std::vector<std::string> ans = get_ans(words, prefix);
	for (std::string word: ans)
		std::cout << word << std::endl;
	
	return 0;
}

