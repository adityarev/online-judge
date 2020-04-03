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


bool
is_unlucky_number (int n) {
	int prev = 0;
	int curr;
	
	while (n != 0) {
		curr = n % 10;
		
		if (curr == 4)
			return true;
		if (curr == 1 && prev == 3)
			return true;
		
		prev = curr;
		n /= 10;
	}
	
	return false;
}

void
init_dp(std::vector<int> &dp) {
	int len = (int)dp.size();
	int next = 1;
	
	for (int i = 1; i < len; i++) {
		if (is_unlucky_number(i)) {
			dp[i] = -1;
			continue;
		}
		dp[i] = next++;
	}
}

void
run_case(std::vector<int> &dp) {
	int n = fio.getnumb<int>();
	
	for (int i = 0; i < n; i++) {
		int x = fio.getnumb<int>();
		fio.printnumb<int>(dp[x], (i == (n - 1) ? "\n" : " "));
	}
}

int
main() {
	const int MAX_N = 1e6;
	
	std::vector<int> dp(MAX_N + 1, 0);
	init_dp(dp);
	
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++)
		run_case(dp);
	
	return 0;
}

