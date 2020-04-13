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
set_arr_counter(
	std::vector<int>& arr,
	std::vector<int>& counter
) {
	for (int& x: arr) {
		x = fio.getnumb<int>();
		counter[x]++;
	}
}

bool
arrange_ans(
	std::vector<int>& ans,
	std::vector<int>& arr,
	std::vector<int>& counter
) {
	int n = (int)arr.size();
	int k = (int)counter.size();
	
	for (int i = 0; i < n; i++) {
		int val = (counter[arr[i]] - 1) * k + (arr[i] == 0 ? k : arr[i]);
		
		if (val > n)
			return false;
		
		ans[i] = val;
		counter[arr[i]]--;
	}
	
	return true;
}

void
show_arr(std::vector<int>& arr) {
	int len = (int)arr.size();
	
	for (int i = 0; i < len; i++)
		fio.printnumb<int>(arr[i], (i == len - 1 ? "\n" : " "));
}

int
main() {
	int n = fio.getnumb<int>();
	int k = fio.getnumb<int>();
	
	std::vector<int> arr(n);
	std::vector<int> counter(k, 0);
	set_arr_counter(arr, counter);
	
	std::vector<int> ans(n);
	bool valid = arrange_ans(ans, arr, counter);
	
	if (valid)
		show_arr(ans);
	else
		puts("-1");
	
	return 0;
}

