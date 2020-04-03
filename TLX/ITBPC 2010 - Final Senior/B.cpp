#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
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
		if (val == 0) {
			pc('0');
			printstr(suffix);
			return;
		}
		if (val < 0) {
			pc('-');
			val = -val;
		}
		
		std::function<void(T)> _print = [&](T x) -> void {
			if (x == 0)
				return;
			
			_print(x / 10);
			pc('0' + (x % 10));
		};
		
		_print(val);
		printstr(suffix);
	}
	
	void
	printstr(std::string &str) {
		for (char &c: str)
			pc(c);
	}
} fio;


void
set_min_max(
	std::map<int,std::pair<int,int>> &min_max,
	int &n
) {
	for (int i = 0; i < n; i++) {
		int x = fio.getnumb<int>();
		int y = fio.getnumb<int>();
		
		if (min_max.find(y) == min_max.end())
			min_max[y] = std::make_pair(INT_MAX, INT_MIN);
		
		min_max[y].first = std::min(min_max[y].first, x);
		min_max[y].second = std::max(min_max[y].second, x);
	}
}

int
get_ans(
	std::map<int,std::pair<int,int>> &min_max,
	int &h
) {
	std::map<int,int> counter;
	counter.clear();
	
	auto l_it = min_max.begin();
	auto r_it = min_max.begin();
	
	int ans = INT_MIN;
	
	do {
		int l_key = l_it->first;
		int r_key = r_it->first;
		std::pair<int,int> l_val = l_it->second;
		std::pair<int,int> r_val = r_it->second;
		
		int l_min_val = l_val.first;
		int l_max_val = l_val.second;
		int r_min_val = r_val.first;
		int r_max_val = r_val.second;
		
		if (r_key - l_key > h) {
			counter[l_min_val]--;
			counter[l_max_val]--;
			
			if (counter[l_min_val] <= 0)
				counter.erase(l_min_val);
			if (l_min_val != l_max_val && counter[l_max_val] <= 0)
				counter.erase(l_max_val);
			
			l_it++;
			continue;
		}
		
		counter[r_min_val]++;
		counter[r_max_val]++;
		
		int min_x = counter.begin()->first;
		int max_x = counter.rbegin()->first;
		int len = max_x - min_x;
		
		ans = std::max(ans, len);
		r_it++;
	} while (r_it != min_max.end());
	
	return ans;
}

void
run_case() {
	int n = fio.getnumb<int>();
	int h = fio.getnumb<int>();
	
	std::map<int,std::pair<int,int>> min_max;
	set_min_max(min_max, n);
	
	int ans = get_ans(min_max, h);
	fio.printnumb(ans, "\n");
}

int
main() {
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++)
		run_case();
	
	return 0;
}

