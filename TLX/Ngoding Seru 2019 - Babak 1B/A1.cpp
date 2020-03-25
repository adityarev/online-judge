#include <algorithm>
#include <climits>
#include <functional>
#include <iostream>

const int MAX_SCORE_VALUE = 100;

int
get_personal_passing_score() {
	int n;
	std::cin >> n;
	
	int max_score = INT_MIN;
	int second_max_score = INT_MIN;
	int last_score;
	
	std::function<int(int&)> normalized_score = [&](int &score) -> int {
		return score <= MAX_SCORE_VALUE ? score : -1;
	};
	
	for (int i = 0; i < n; i++) {
		int score;
		std::cin >> score;
		
		last_score = normalized_score(score);
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

