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
set_arr(std::vector<int>& arr) {
	for (int &x: arr)
		x = fio.getnumb<int>();
}

int
get_ans(
	std::vector<int>& arr1,
	std::vector<int>& arr2
) {
	int ans = INT_MAX;
	
	for (int &x1: arr1)
		for (int &x2: arr2)
			ans = std::min(ans, (int)abs(x1 - x2));
	
	return ans;
}

int
main() {
	int tc = fio.getnumb<int>();
	
	for (int c = 0; c < tc; c++) {
		int n1 = fio.getnumb<int>();
		int n2 = fio.getnumb<int>();
		
		std::vector<int> arr1(n1);
		set_arr(arr1);
		
		std::vector<int> arr2(n2);
		set_arr(arr2);
		
		int ans = get_ans(arr1, arr2);
		printf("Kasus #%d: %d\n", c + 1, ans);
	}
	
	return 0;
}

