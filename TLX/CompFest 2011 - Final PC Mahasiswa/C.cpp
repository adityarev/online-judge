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


void
set_lookup(
	std::vector<std::vector<int> > &lookup,
	int &r,
	int &c
) {
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			lookup[i][j] = fio.getnumb<int>();
}

void
set_dp(
	std::vector<std::vector<int> > &lookup,
	std::vector<std::vector<int> > &p_dp,
	std::vector<std::vector<int> > &n_dp,
	int &r,
	int &c
) {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			p_dp[i][j] = lookup[i][j] + p_dp[i - 1][j + 1];
			n_dp[i][j] = lookup[i][j] + n_dp[i - 1][j - 1];
		}
	}
}

int
get_ans(
	std::vector<std::vector<int> > &lookup,
	std::vector<std::vector<int> > &p_dp,
	std::vector<std::vector<int> > &n_dp,
	int &r,
	int &c
) {
	int ans = 0;
	
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			int l_dist = j - 1;
			int r_dist = c - j;
			int d_dist = r - i;
			
			int p_i = std::min(r, (i + l_dist));
			int n_i = std::min(r, (i + r_dist));
			int p_j = std::max(1, (j - d_dist));
			int n_j = std::min(c, (j + d_dist));
			
			int score = p_dp[p_i][p_j] + n_dp[n_i][n_j] - (2 * lookup[i][j]);
			ans = std::max(ans, score);
		}
	}
	
	return ans;
}

void
run_case() {
	int r = fio.getnumb<int>();
	int c = fio.getnumb<int>();
	
	std::vector<std::vector<int> > lookup(r + 1, std::vector<int>(c + 2, 0));
	set_lookup(lookup, r, c);
	
	// Postive and Negative diagonal DP array
	std::vector<std::vector<int> > p_dp(r + 1, std::vector<int>(c + 2, 0));
	std::vector<std::vector<int> > n_dp(r + 1, std::vector<int>(c + 2, 0));
	set_dp(lookup, p_dp, n_dp, r, c);
	
	int ans = get_ans(lookup, p_dp, n_dp, r, c);
	fio.printnumb<int>(ans, "\n");
}

int
main() {
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++)
		run_case();
	
	return 0;
}

