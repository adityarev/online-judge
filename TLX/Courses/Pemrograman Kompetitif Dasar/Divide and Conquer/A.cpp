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


const int MAX_N = 265 * 1e3;
const LL INVALID = -1LL;

enum {
	LOWER_BOUND = 0,
	NORMAL_BOUND,
	UPPER_BOUND,
};

int n;
LL m;
LL eggs[MAX_N];

void
set_eggs() {
	for (int i = 0; i < n; i++)
		eggs[i] = fio.getnumb<LL>();
}

LL
count_m(LL &x) {
	LL counter = 0;
	for (int i = 0; i < n; i++)
		counter += x / eggs[i];
	return counter;
}

LL
find_x(LL l, LL r, int flag) {
	LL x = INVALID;
	
	while (l <= r) {
		LL mid = l + ((r - l) >> 1);
		LL x_m = count_m(mid);
		
		if (x_m < m)
			l = mid + 1LL;
		else if (x_m > m)
			r = mid - 1LL;
		else {
			x = mid;
			
			if (flag == LOWER_BOUND)
				r = mid - 1LL;
			else if (flag == UPPER_BOUND)
				l = mid + 1LL;
			else
				break;
		}
	}
		
	return x;
}

LL
get_ans() {
	LL x = find_x(1LL, LLONG_MAX, NORMAL_BOUND);
	
	if (x == INVALID)
		return 0LL;
	
	LL min_x = find_x(1LL, x - 1LL, LOWER_BOUND);
	LL max_x = find_x(x + 1LL, LLONG_MAX, UPPER_BOUND);
	
	if (min_x == INVALID)
		min_x = x;
	if (max_x == INVALID)
		max_x = x;
	
	LL ans = max_x - min_x + 1LL;
	return ans;
}

int
main() {
	n = fio.getnumb<int>();
	m = fio.getnumb<LL>();
	set_eggs();
	
	LL ans = get_ans();
	fio.printnumb<LL>(ans, "\n");
	
	return 0;
}

