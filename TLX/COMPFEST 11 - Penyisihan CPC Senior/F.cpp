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
			return c == '\n' || (c == ' ' && !line_scan);
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

int
get_ans(std::string &str, int &q) {
	std::function<std::string(std::string&, char&, std::string&)>
	get_changes = [&](
		std::string &ori,
		char &poc,
		std::string &changer
	) -> std::string {
		std::string modified = "";
		
		for (char &c: ori) {
			if (c == poc)
				modified += changer;
			else
				modified += c;
		}
		
		return modified;
	};
	
	std::string ans = str;
	
	for (int i = 0; i < q; i++) {
		char poc = fio.getstr()[0];
		std::string changer = fio.getstr();
		
		ans = get_changes(ans, poc, changer);
	}
	
	return (int)ans.length();
}

int
main() {
	int n = fio.getnumb<int>();
	int q = fio.getnumb<int>();
	std::string str = fio.getstr();
	
	int ans = get_ans(str, q);
	fio.printnumb<int>(ans); endline;
	
	return 0;
}

