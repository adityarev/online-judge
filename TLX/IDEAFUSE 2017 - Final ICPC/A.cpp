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
run_case(int case_num) {
	int n = fio.getnumb<int>();
	int k = fio.getnumb<int>();
	
	LL curr = 0;
	LL ans = 0;
	std::vector<LL> prefix(n, 0);
	
	for (int i = 0; i < n; i++) {
		LL x = fio.getnumb<LL>();
		
		curr += prefix[i];
		if (x > curr) {
			LL diff = x - curr;
			
			ans += diff;
			curr += diff;
			
			int last_ind = i + k;
			
			if (last_ind < n)
				prefix[last_ind] -= diff;
		}
	}
	
	static std::string CASE = "Case #";
	
	fio.printstr(CASE);
	fio.printnumb<int>(case_num, ": ");
	fio.printnumb<LL>(ans, "\n");
}

int
main() {
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++)
		run_case(i + 1);
	
	return 0;
}

