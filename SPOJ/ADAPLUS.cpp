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


const int MAX_N = 2000;
const int N_DIR = 4;

int dp[MAX_N][MAX_N][N_DIR];
char grid[MAX_N][MAX_N + 1];

enum {
	TOP = 0,
	RIGHT,
	BOTTOM,
	LEFT
};

void
set_dp(int& n) {
	// Top and Left
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c = grid[i][j] = gc();
			
			// Top DP
			if (i == 0)
				dp[i][j][TOP] = (int)(c == '#');
			else {
				if (c == '#')
					dp[i][j][TOP] = dp[i - 1][j][TOP] + 1;
				else
					dp[i][j][TOP] = 0;
			}
			
			// Left DP
			if (j == 0)
				dp[i][j][LEFT] = (int)(c == '#');
			else {
				if (c == '#')
					dp[i][j][LEFT] = dp[i][j - 1][LEFT] + 1;
				else
					dp[i][j][LEFT] = 0;
			}
		}
		gc();
	}
	
	// Bottom and Right
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			char c = grid[i][j];
			
			// Bottom DP
			if (i == n - 1)
				dp[i][j][BOTTOM] = (int)(c == '#');
			else {
				if (c == '#')
					dp[i][j][BOTTOM] = dp[i + 1][j][BOTTOM] + 1;
				else
					dp[i][j][BOTTOM] = 0;
			}
			
			// Right DP
			if (j == n - 1)
				dp[i][j][RIGHT] = (int)(c == '#');
			else {
				if (c == '#')
					dp[i][j][RIGHT] = dp[i][j + 1][RIGHT] + 1;
				else
					dp[i][j][RIGHT] = 0;
			}
		}
	}
}

int
get_ans(int& n) {
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = std::max(
				ans,
				std::min(
					std::min(dp[i][j][TOP], dp[i][j][LEFT]),
					std::min(dp[i][j][BOTTOM], dp[i][j][RIGHT])
				)
			);
		}
	}
	
	return ans;
}

int
main() {
	int tc = fio.getnumb<int>();
	
	while (tc--) {
		int n = fio.getnumb<int>();
		set_dp(n);
		
		int ans = get_ans(n);
		fio.printnumb<int>(ans, "\n");
	}
	
	return 0;
}

