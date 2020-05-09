#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iterator>
#include <iostream>
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


void
set_maps(
	std::unordered_map<int,int>& x_counter,
	std::unordered_map<int,int>& y_counter,
	std::unordered_map<int,std::unordered_map<int,int>>& xy_counter,
	int& n
) {
	for (int i = 0; i < n; i++) {
		int x = fio.getnumb<int>();
		int y = fio.getnumb<int>();
		
		x_counter[x]++;
		y_counter[y]++;
		xy_counter[x][y]++;
	}
}

int
get_ans(
	std::unordered_map<int,int>& x_counter,
	std::unordered_map<int,int>& y_counter,
	std::unordered_map<int,std::unordered_map<int,int>>& xy_counter
) {
	int ans = 0;
	
	for (auto it0 = xy_counter.begin(); it0 != xy_counter.end(); it0++) {
		int x = it0->first;
		auto temp = &(it0->second);
		
		for (auto it1 = temp->begin(); it1 != temp->end(); it1++) {
			int y = it1->first;
			int val = it1->second;
			int count = x_counter[x] + y_counter[y] - (val << 1);
			
			ans = std::max(ans, count);
		}
	}
	
	return ans;
}

void
run_case(int case_num) {
	int n = fio.getnumb<int>();
	
	std::unordered_map<int,int> x_counter;
	std::unordered_map<int,int> y_counter;
	std::unordered_map<int,std::unordered_map<int,int>> xy_counter;
	set_maps(x_counter, y_counter, xy_counter, n);
	
	static std::string CASE = "Case #";
	int ans = get_ans(x_counter, y_counter, xy_counter);
	
	fio.printstr(CASE);
	fio.printnumb<int>(case_num, ": ");
	fio.printnumb<int>(ans, "\n");
}

int
main() {
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++)
		run_case(i + 1);
	
	return 0;
}

