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


const int MAX = 1e3;

void
init_primes(std::vector<int>& primes) {
	std::vector<bool> is_prime(MAX + 1, true);
	
	for (int i = 2; i <= MAX; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (int j = i + i; j <= MAX; j += i)
				is_prime[j] = false;
		}
	}
}

void
set_dp(
	std::vector<int>& dp,
	std::vector<int>& primes
) {
	std::function<int(int&)>
	count_prime_factor = [&](int n) -> int {
		int counter = 0;
		
		for (int& prime: primes) {
			if (prime > n)
				break;
			while (n % prime == 0) {
				counter++;
				n /= prime;
			}
		}
		
		return counter;
	};
	
	for (int i = 1; i <= MAX; i++) {
		int n_factor = count_prime_factor(i);
		dp[i] = dp[i - 1] + (int)(n_factor == 2);
	}
}

int
main() {
	std::vector<int> primes;
	init_primes(primes);
	
	std::vector<int> dp(MAX + 1, 0);
	set_dp(dp, primes);
	
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++) {
		int l = fio.getnumb<int>();
		int r = fio.getnumb<int>();
		
		int ans = dp[r] - dp[l - 1];
		fio.printnumb<int>(ans, "\n");
	}
	
	return 0;
}

