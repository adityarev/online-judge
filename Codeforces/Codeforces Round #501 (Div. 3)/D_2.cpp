#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)
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

int
main() {
	int n = fio.getnumb<int>();
	int k = fio.getnumb<int>();
	LL s = fio.getnumb<LL>();
	
	if ((LL)((n - 1) * (LL)k) < s || k > s) {
		puts("NO");
		return 0;
	}
	
	int curr = 1;
	int max_move = n - 1;
	std::vector<int> ans;
	
	while ((s - max_move) >= k) {
		if (curr == 1)
			curr = n;
		else if (curr == n)
			curr = 1;
		
		ans.push_back(curr);
		s -= max_move;
		k--;
	}
	
	if (k > 0) {
		int first_step = (s - k + 1);
		
		if (curr == 1)
			curr += first_step;
		else if (curr == n)
			curr -= first_step;
		
		ans.push_back(curr);
		s -= first_step;
		k--;
		
		bool moving_right;
		
		while (k > 0) {
			if (curr == n)
				moving_right = false;
			else if (curr == 1)
				moving_right = true;
			
			if (moving_right)
				curr++;
			else
				curr--;
			
			ans.push_back(curr);
			k--;
		}
	}
	
	puts("YES");
	for (int i = 0, sz = (int)ans.size(); i < sz; i++)
		fio.printnumb<int>(ans[i], (i == sz - 1 ? "\n" : " "));
	
	return 0;
}

