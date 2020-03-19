#include <iostream>
#include <list>
#include <string>

void
set_words(
	int &n,
	int &width,
	std::list<std::string> &words
) {
	for (int i = 0; i < n; i++) {
		std::string word;
		std::cin >> word;
		
		while (word.length() > width) {
			std::string temp = word.substr(0, width);
			
			words.push_back(temp);
			word = word.substr(width, word.length());
		}
		words.push_back(word);
	}
}

void
write_one_line(
	int &width,
	std::list<std::string> &words
) {
	int space = width;
	
	while (!words.empty()) {
		std::string word = words.front();
		int len = word.length();
		
		if (len <= space) {
			space -= (len + 1);
			words.pop_front();
		} else {
			break;
		}
	}
}

int
get_ans(
	int &h,
	int &w,
	std::list<std::string> &words
) {
	int line_count = 0;
	
	while (!words.empty()) {
		write_one_line(w, words);
		line_count++;
	}
	
	int ans = (line_count / h) + (int)(line_count % h != 0);
	return ans;
}

int
main() {
	int h, w, n;
	std::cin >> h >> w >> n;
	
	std::list<std::string> words;
	set_words(n, w, words);
	
	int ans = get_ans(h, w, words);
	std::cout << ans << std::endl;
	
	return 0;
}

