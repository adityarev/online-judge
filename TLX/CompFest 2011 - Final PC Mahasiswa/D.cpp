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
run_case() {
	char c = '\0';
	int ans = 0;
	std::string s = fio.getstr();
	
	for (int i = 0; i < ((int)s.length() - 3); i++) {
		if (s[i] == 'l' && s[i + 1] == 'h' && s[i + 2] == 'o') {
			int counter = 0;
			int p = i + 2;
			
			while (p < ((int)s.length() - 1) && s[p] == 'o') {
				counter++;
				p++;
			}
			
			if (s[p] == '?')
				ans = std::max(ans, counter);
			i = p - 1;
		}
	}
	
	fio.printnumb<int>(ans, "\n");
}

int
main() {
	int n = fio.getnumb<int>();
	
	for (int i = 0; i < n; i++)
		run_case();
	
	return 0;
}

