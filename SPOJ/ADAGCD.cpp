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

const int MAX_VAL = 1e7;
const int LIM = (int)ceil(sqrt(MAX_VAL));
const int MOD = 1e9 + 7;

std::vector<bool> is_prime(MAX_VAL + 1, true);
std::vector<int> prime_divisors;

void
set_is_prime() {
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= MAX_VAL; i++) {
		if (is_prime[i]) {
			for (int j = i + i; j <= MAX_VAL; j += i)
				is_prime[j] = false;
		}
	}
}

void
set_prime_divisors() {
	for (int i = 2; i <= LIM; i++)
		if (is_prime[i])
			prime_divisors.push_back(i);
}

void
precompute() {
	set_is_prime();
	set_prime_divisors();
}

void
calculate_num(
	int& num,
	int& group_id,
	std::vector<std::map<int,int>>& counter,
	std::set<int>& appeared
) {
	int x = num;
	
	if (!is_prime[x]) {
		for (int& prime: prime_divisors) {
			if (x == 1)
				break;
			
			int count = 0;
			
			while (x % prime == 0) {
				x /= prime;
				count++;
			}
			
			if (count > 0) {
				counter[group_id][prime] += count;
				appeared.insert(prime);
			}
		}
	}
	if (x != 1) {
		counter[group_id][x]++;
		appeared.insert(x);
	}
}

void
mark_appeared(
	std::set<int>& appeared,
	std::map<int,int>& appeared_count
) {
	for (auto it = appeared.begin(); it != appeared.end(); it++)
		appeared_count[*it]++;
}

void
process_group(
	int& n,
	std::vector<std::map<int,int>>& counter,
	std::map<int,int>& appeared_count
) {
	for (int i = 0; i < n; i++) {
		int m = fio.getnumb<int>();
		std::set<int> appeared;
		
		for (int j = 0; j < m; j++) {
			int num = fio.getnumb<int>();
			calculate_num(num, i, counter, appeared);
		}
		
		mark_appeared(appeared, appeared_count);
	}
}

template<typename T> T
modexp(T num, T power, T mod) {
	T res = 1;
	
	num %= mod;
	if (num == 0)
		return 0;
	
	while (power > 0) {
		if (power & 1)
			res = (res * num) % mod;
		power = power >> 1;
		num = (num * num) % mod;
	}
	
	return res;
}

LL
get_ans(
	int& n,
	std::vector<std::map<int,int>>& counter,
	std::map<int,int>& appeared_count
) {
	LL ans = 1LL;
	
	for (auto it0 = appeared_count.begin(); it0 != appeared_count.end(); it0++) {
		int key = it0->first;
		int val = it0->second;
		
		if (val == n) {
			int min_power = INT_MAX;
			
			for (int i = 0; i < n; i++)
				min_power = std::min(min_power, counter[i][key]);
			
			ans *= modexp<LL>((LL)key, (LL)min_power, (LL)MOD);
			ans %= MOD;
		}
	}
	
	return ans;
}

int
main() {
	precompute();
	
	int n = fio.getnumb<int>();
	std::vector<std::map<int,int>> counter(n, std::map<int,int>());
	std::map<int,int> appeared_count;
	process_group(n, counter, appeared_count);
	
	LL ans = get_ans(n, counter, appeared_count);
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

