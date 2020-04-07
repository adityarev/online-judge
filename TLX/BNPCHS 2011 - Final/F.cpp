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


const int MAX = 1e6;
const int INVALID = -1;

void
init_gcd(std::vector<int>& gcd) {
	for (int i = 2; i <= MAX; i++) {
		if (gcd[i] == INVALID) {
			for (int j = i + i; j <= MAX; j += i)
				gcd[j] = i;
		}
	}
}

void
build_dp(
	std::vector<int>& gcd,
	std::vector<int>& dp
) {
	int curr_max = INT_MIN;
	
	for (int i = 1; i <= MAX; i++) {
		if (gcd[i] != INVALID) {
			curr_max = std::max(curr_max, gcd[i]);
			if (gcd[i] == curr_max)
				dp[i]++;
		}
		dp[i] += dp[i - 1];
	}
}

int
main() {
	std::vector<int> gcd(MAX + 1, INVALID);
	init_gcd(gcd);
	
	std::vector<int> dp(MAX + 1, 0);
	build_dp(gcd, dp);
	
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++) {
		int l = fio.getnumb<int>();
		int r = fio.getnumb<int>();
		
		int ans = dp[r] - dp[l - 1];
		fio.printnumb<int>(ans, "\n");
	}
	
	return 0;
}

