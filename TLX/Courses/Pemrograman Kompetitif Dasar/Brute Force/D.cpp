#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)
#define endline pc('\n')

typedef long long LL;

struct FastIO {
	template <typename T> T
	getnumb() {
		T c = gc();
		
		std::function<bool()> is_negative = [&]() -> bool {
			for (; c < '0' || c > '9'; c = gc()) {
				if (c == '-') {
					c = gc();
					if (c >= '0' && c <= '9')
						return true;
				}
			}
			return false;
		};
		
		bool negative = is_negative();
		T val = 0;
		
		for (; c >= '0' && c <= '9'; c = gc())
			val = (val << 1) + (val << 3) + c - (T)'0';
		
		return negative ? -val : val;
	}
	
	std::string
	getstr(bool line_scan = false) {
		std::function<bool(char&)> is_separator = [&](char &c) -> bool {
			return c == '\n' || (c == ' ' && !line_scan) || c == EOF;
		};
		
		char c;
		std::string str = "";
		
		while ((c = gc()) && is_separator(c));
		do {
			str += c;
		} while ((c = gc()) && !is_separator(c));
		
		return str;
	}
	
	template <typename T> void
	printnumb(T val, std::string suffix = "") {
		std::function<void(T)> _print = [&](T x) -> void {
			if (x == 0)
				return;
			
			_print(x / 10);
			pc('0' + (x % 10));
		};
		
		if (val != 0) {
			if (val < 0) {
				pc('-');
				val = -val;
			}
			_print(val);
		} else {
			pc('0');
		}
		printstr(suffix);
	}
	
	void
	printstr(std::string &str) {
		for (char &c: str)
			pc(c);
	}
} fio;


const char BIASA = 'B';
const char PUKAU = 'P';
const char LELAH = 'L';
const char YAKIN = 'Y';

struct Dance {
	int point;
	char type;
};

struct Judge {
	int id;
	int min_score;
};

void
ignore_line() {
	while (gc() != '\n');
}

void
set_dances(std::vector<Dance>& dances) {
	for (Dance& dance: dances) {
		dance.point = fio.getnumb<int>();
		dance.type = fio.getstr()[0];
	}
}

void
set_min_scores(std::vector<int>& min_scores) {
	for (int& min_score: min_scores)
		min_score = fio.getnumb<int>();
}

void
set_judges(
	std::vector<Judge>& judges,
	std::vector<int>& min_scores
) {
	int i = 0;
	
	for (Judge& judge: judges) {
		judge.id = i;
		judge.min_score = min_scores[i];
		i++;
	}
	judges.push_back({i, INT_MAX});
	
	std::sort(judges.begin(), judges.end(), [](const Judge& a, const Judge& b) {
		return a.min_score < b.min_score;
	});
}

void
set_temp(
	std::vector<int>& temp,
	std::vector<Judge>& judges
) {
	for (Judge& judge: judges)
		temp.push_back(judge.min_score);
}

void
set_answers(
	std::vector<int>& answers,
	std::vector<Dance>& dances,
	std::vector<int>& min_scores,
	int& r,
	int& y
) {
	int n = (int)dances.size();
	int j = (int)min_scores.size();
	
	std::vector<Judge> judges(j);
	set_judges(judges, min_scores);
	
	std::vector<int> temp;
	set_temp(temp, judges);
	
	std::vector<int> prefix(j + 1, 0);
	
	std::function<void(int)>
	_judge_score = [&](int score) -> void {
		auto lower = std::lower_bound(temp.begin(), temp.end(), score);
		int dist = std::distance(temp.begin(), lower);
		
		if (*lower < score)
			dist++;
		
		prefix[0]++;
		prefix[dist]--;
	};
	
	std::vector<bool> taken(n, false);
	
	std::function<void(int,int,int,char,bool)>
	_dfs = [&](int ind, int len, int score, char prev_type, bool add_y) -> void {
		Dance dance = dances[ind];
		int curr_score = dance.point;
		
		if (prev_type == PUKAU)
			curr_score <<= 1;
		else if (prev_type == LELAH)
			curr_score >>= 1;
		if (add_y)
			curr_score += y;
		
		int full_score = score + curr_score;
		
		if (len == r - 1) {
			_judge_score(full_score);
			return;
		}
		
		for (int i = 0; i < n; i++) {
			if (!taken[i]) {
				taken[i] = true;
				_dfs(i, len + 1, full_score, dance.type, add_y || (dance.type == YAKIN));
				taken[i] = false;
			}
		}
	};
	
	std::function<void()>
	_brute_force = [&]() -> void {
		for (int i = 0; i < n; i++) {
			if (!taken[i]) {
				taken[i] = true;
				_dfs(i, 0, 0, '-', false);
				taken[i] = false;
			}
		}
	};
	
	std::function<void()>
	_do_scanline = [&]() -> void {
		int curr = 0;
		
		for (int i = 0; i < j; i++) {
			Judge judge = judges[i];
			
			curr += prefix[i];
			answers[judge.id] = curr;
		}
	};
	
	_brute_force();
	_do_scanline();
}

int
main() {
	ignore_line();
	
	int n = fio.getnumb<int>();
	int r = fio.getnumb<int>();
	int y = fio.getnumb<int>();
	int j = fio.getnumb<int>();
	
	std::vector<Dance> dances(n);
	set_dances(dances);
	
	std::vector<int> min_scores(j);
	set_min_scores(min_scores);
	
	std::vector<int> answers(j, 0);
	set_answers(answers, dances, min_scores, r, y);
	
	for (int& answer: answers)
		fio.printnumb<int>(answer, "\n");
	
	return 0;
}

