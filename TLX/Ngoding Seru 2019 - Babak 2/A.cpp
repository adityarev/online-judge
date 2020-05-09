#include <algorithm>
#include <cassert>
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
	template <typename T> T getnumb();
	template <typename T> void printnumb(T val, std::string suffix = "");
	std::string getstr(bool line_scan = false);
	void printstr(std::string &str);
} fio;

const LL MOD = 1e9 + 7;

void
set_count(std::vector<int>& count, int& k) {
	for (int i = 0; i < k; i++) {
		int x = fio.getnumb<int>();
		count[x]++;
	}
}

LL
get_ans(std::vector<int>& count, int& k) {
	int lim = (int)count.size();
	int temp = k - count[0];
	LL ans = 1LL;
	
	for (int i = 1; i < lim; i++) {
		int x = count[i];
		
		if (x != 0)
			temp -= x;
		else
			ans = (ans * temp) % MOD;
	}
	
	return ans;
}

int
main() {
	int n = fio.getnumb<int>();
	int k = fio.getnumb<int>();
	
	std::vector<int> count(n + 1, 0);
	set_count(count, k);
	
	LL ans = get_ans(count, k);
	fio.printnumb<LL>(ans, "\n");
	
	return 0;
}

/* FastIO Implementation */
template <typename T>
T
FastIO::getnumb() {
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

template <typename T>
void
FastIO::printnumb(T val, std::string suffix) {
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

std::string
FastIO::getstr(bool line_scan) {
	std::function<bool(char&)> is_separator = [&](char &c) -> bool {
		return c == '\n' || (c == ' ' && !line_scan) || c == EOF;
	};
	
	char c;
	std::string str = "";
	
	while ((c = gc()) && is_separator(c));
	do
		str += c;
	while ((c = gc()) && !is_separator(c));
	
	return str;
}

void
FastIO::printstr(std::string &str) {
	for (char &c: str)
		pc(c);
}

