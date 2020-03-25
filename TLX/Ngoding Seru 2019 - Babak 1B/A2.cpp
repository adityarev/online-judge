#include <algorithm>
#include <climits>
#include <cstdio>
#include <functional>
#include <iostream>

#define gc(x) getchar_unlocked(x)

typedef long long LL;
const int MAX_SCORE_VALUE = 1000000000LL;

LL
get_personal_passing_score() {
	int n;
	std::cin >> n;
	
	LL max_score = LLONG_MIN;
	LL second_max_score = LLONG_MIN;
	LL last_score;
	
	std::function<int()> scan_score = [&]() -> int {
		char c;
		LL score = 0LL;
		
		std::function<bool(char)> is_numb = [&](char c) -> bool {
			return '0' <= c && c <= '9';
		};
		
		std::function<void()> ignore_numb = [&]() -> void {
			while ((c = gc()) && is_numb(c));
		};
		
		while (c = gc()) {
			if (c == '-') {
				ignore_numb();
				return -1LL;
			}
			if (is_numb(c))
				break;
		}
		
		do {
			score *= 10LL;
			score += (int)(c - '0');
			
			if (score > MAX_SCORE_VALUE) {
				ignore_numb();
				return -1LL;
			}
		} while ((c = gc()) && is_numb(c));
		
		return score;
	};
	
	for (int i = 0; i < n; i++) {
		last_score = scan_score();
		if (last_score >= max_score) {
			second_max_score = max_score;
			max_score = last_score;
		}
	}
	
	return (max_score != second_max_score && last_score == max_score) ? last_score : -1;
}

int
get_ans(int &n) {
	int ans = INT_MAX;
	
	for (int i = 0; i < n; i++) {
		int personal_passing_score = get_personal_passing_score();
		ans = std::min(ans, personal_passing_score);
	}
	
	return ans;
}

int
main() {
	int n;
	std::cin >> n;
	
	int ans = get_ans(n);
	std::cout << ans << std::endl;
	
	return 0;
}

