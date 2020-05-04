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


enum {
	BATU = 0,
	GUNTING,
	KERTAS
};

void
set_counter(
	std::vector<int>& counter,
	std::string& str
) {
	for (char& c: str) {
		if (c == 'B')
			counter[BATU]++;
		else if (c == 'G')
			counter[GUNTING]++;
		else if (c == 'K')
			counter[KERTAS]++;
	}
}

int
get_ans(
	std::vector<int>& counter1,
	std::vector<int>& counter2
) {
	int ans = 0;
	
	ans += std::min(counter1[BATU], counter2[GUNTING]);
	ans += std::min(counter1[GUNTING], counter2[KERTAS]);
	ans += std::min(counter1[KERTAS], counter2[BATU]);
	
	return ans;
}

int
main() {
	int n = fio.getnumb<int>();
	std::string str1 = fio.getstr();
	std::string str2 = fio.getstr();
	
	const int sz = 3;
	std::vector<int> counter1(sz, 0);
	std::vector<int> counter2(sz, 0);
	
	set_counter(counter1, str1);
	set_counter(counter2, str2);
	
	int ans = get_ans(counter1, counter2);
	fio.printnumb<int>(ans, "\n");
	
	return 0;
}
