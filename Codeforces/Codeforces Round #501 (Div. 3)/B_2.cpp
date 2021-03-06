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
	std::string s = fio.getstr();
	std::string t = fio.getstr();
	
	std::string temp_s = s;
	std::string temp_t = t;
	
	std::sort(temp_s.begin(), temp_s.end());
	std::sort(temp_t.begin(), temp_t.end());
	
	if (temp_s != temp_t) {
		puts("-1");
		return 0;
	}
	
	std::vector<int> ans;
	
	for (int i = 0; i < n; i++) {
		std::string find_t = "";
		find_t += t[i];
		
		int ind = i + s.substr(i, n - i).find(find_t);
		
		while (ind > i) {
			ans.push_back(ind);
			std::swap(s[ind], s[ind - 1]);
			ind--;
		}
	}
	
	int sz = (int)ans.size();
	
	fio.printnumb<int>(sz, "\n");
	for (int i = 0; i < sz; i++)
		fio.printnumb<int>(ans[i], (i == sz - 1 ? "\n" : " "));
	
	return 0;
}

