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


void
set_arr(std::vector<int>& arr) {
	for (int& x: arr)
		x = fio.getnumb<int>();
	
	std::sort(arr.begin(), arr.end());
}

int
get_ans(
	std::vector<int>& ducks,
	std::vector<int>& shoes
) {
	int n = (int)ducks.size();
	int m = (int)shoes.size();
	int i = 0;
	int j = 0;
	int ans = 0;
	
	std::function<bool(int,int,int)>
	_is_in_range = [&](int val, int l, int r) -> bool {
		return (l <= val && val <= r);
	};
	
	while (i < n && j < m) {
		if (_is_in_range(shoes[j] - ducks[i], 0, 1)) {
			ans++;
			i++;
			j++;
			continue;
		}
		
		if (ducks[i] < shoes[j])
			i++;
		else
			j++;
	}
	
	return ans;
}

int
main() {
	int n = fio.getnumb<int>();
	int m = fio.getnumb<int>();
	
	std::vector<int> ducks(n);
	set_arr(ducks);
	
	std::vector<int> shoes(m);
	set_arr(shoes);
	
	int ans = get_ans(ducks, shoes);
	fio.printnumb<int>(ans, "\n");
	
	return 0;
}

