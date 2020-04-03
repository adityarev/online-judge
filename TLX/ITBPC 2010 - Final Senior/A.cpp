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


const int MAX_LEN = 1e6 + 2;
int count[MAX_LEN];

void
set_count(int& r, int& c, int& max_h) {
	int lim = r * c;
	
	for (int i = 0; i < lim; i++) {
		int x = fio.getnumb<int>();
		
		count[x]++;
		max_h = std::max(max_h, x);
	}
}

double
get_ans(int v, int &max_h) {
	double ans = 0.0;
	int temp = 0;
	int h = 0;
	
	for (int i = 1; i <= max_h + 1; i++) {
		temp += count[i - 1];
		if (temp > v)
			break;
		v -= temp;
		h = i;
	}
	
	return ((double)h + ((double)v / (double)temp));
}

int
main() {
	int r = fio.getnumb<int>();
	int c = fio.getnumb<int>();
	int v = fio.getnumb<int>();
	int max_h = INT_MIN;
	
	set_count(r, c, max_h);
	
	double ans = get_ans(v, max_h);
	printf("%.3lf\n", ans);
	
	return 0;
}

