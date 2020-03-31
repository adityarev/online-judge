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

#define gc(x) getchar(x)
#define pc(x) putchar(x)
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
set_arr(std::vector<int> &arr) {
	for (int &x: arr)
		x = fio.getnumb<int>();
}

std::string
get_ans(std::vector<int> &arr) {
	std::string ans = "";
	std::vector<int> updowns = {8, 1, 0};
	
	// Left append
	for (int &val: updowns) {
		int n = (arr[val] >> 1);
		
		for (int i = 0; i < n; i++)
			ans += ('0' + val);
	}
	
	// Middle append
	for (int &val: updowns) {
		if (arr[val] & 1) {
			ans += ('0' + val);
			break;
		}
	}
	
	// Right append
	std::reverse(updowns.begin(), updowns.end());
	for (int &val: updowns) {
		int n = (arr[val] >> 1);
		
		for (int i = 0; i < n; i++)
			ans += ('0' + val);
	}
	
	int n = std::min(arr[9], arr[6]);
	
	// Partials (9 and 6) append
	for (int i = 0; i < n; i++)
		ans = '9' + ans + '6';
	
	if (ans == "")
		return "-1";
	if ((int)ans.length() % 2 == 0 && ans[0] == '0')
		return "-1";
	
	// Remove leading zeroes
	int l = 0;
	int r = (int)ans.length() - 1;
	
	while (l < r && ans[l] == '0') {
		int len = (r - l - 1);
		
		ans = ans.substr(l + 1, len);
		l++;
		r--;
	}
	
	return ans == "0" ? "-1" : ans;
}

int
main() {
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++) {
		const int N_DIGIT = 10;
		
		std::vector<int> arr(N_DIGIT);
		set_arr(arr);
		
		std::string ans = get_ans(arr);
		fio.printstr(ans); endline;
	}
	
	return 0;
}

