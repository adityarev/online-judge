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


void
set_cost(std::map<char,int>& cost) {
	static std::string str = "IVXLCDM";
	for (char& c: str)
		cost[c] = fio.getnumb<int>();
}

struct Next {
	int value;
	int cost;
};

Next
get_next(
	std::map<char,int>& cost,
	int& x
) {
	if (x >= 1000)
    	return {1000, cost['M']};
    if (x >= 900)
    	return {900, cost['C'] + cost['M']};
    if (x >= 500)
    	return {500, cost['D']};
    if (x >= 400)
    	return {400, cost['C'] + cost['D']};
    if (x >= 100)
    	return {100, cost['C']};
    if (x >= 90)
    	return {90, cost['X'] + cost['C']};
    if (x >= 50)
    	return {50, cost['L']};
    if (x >= 40)
    	return {40, cost['X'] + cost['L']};
    if (x >= 10)
    	return {10, cost['X']};
    if (x >= 9)
    	return {9, cost['I'] + cost['X']};
    if (x >= 5)
    	return {5, cost['V']};
    if (x >= 4)
    	return {4, cost['I'] + cost['V']};
    if (x >= 1)
    	return {1, cost['I']};
    
	return {0, 0};
}

int
get_ans(
	std::map<char,int>& cost,
	int& n
) {
	int temp = n;
	int ans = 0;
	
	while (temp > 0) {
		Next next = get_next(cost, temp);
		
		temp -= next.value;
		ans += next.cost;
	}
	
	return ans;
}

void
run_case() {
	int n = fio.getnumb<int>();
	
	static std::map<char,int> cost;
	set_cost(cost);
	
	int ans = get_ans(cost, n);
	fio.printnumb<int>(ans, "\n");
}

int
main() {
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++)
		run_case();
	
	return 0;
}

