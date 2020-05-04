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


struct Item {
	int index;
	int value;
};

void
set_arrays(
	std::vector<Item>& items,
	std::vector<int>& max_arr
) {
	int i = 0;
	
	for (Item& item: items) {
		item.index = i;
		item.value = fio.getnumb<int>();
		max_arr[i] = item.value;
		i++;
	}
}

int
main() {
	int n = fio.getnumb<int>();
	
	std::vector<Item> items(n);
	std::vector<int> max_arr(n);
	
	set_arrays(items, max_arr);
	std::sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
		return a.value < b.value;
	});
	std::sort(max_arr.begin(), max_arr.end(), [](const int& a, const int& b) {
		return a > b;
	});
	
	std::vector<int> ans(n);
	
	for (int i = 0; i < n; i++)
		ans[items[i].index] = max_arr[i];
	
	for (int i = 0; i < n; i++)
		fio.printnumb(ans[i], (i == n - 1 ? "\n" : " "));
	
	return 0;
}

