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

struct Data {
	struct {
		int x;
		int y;
	} point;
	int val;
};

void
select_data (
	Data& data,
	Data& min_data,
	Data& max_data
) {
	if (data.val <= min_data.val) {
		if (data.val < min_data.val)
			min_data = data;
		else {
			if (data.point.x < min_data.point.x)
				min_data.point.x = data.point.x;
			if (data.point.y < min_data.point.y)
				min_data.point.y = data.point.y;
		}
	}
	if (data.val >= max_data.val) {
		if (data.val > max_data.val)
			max_data = data;
		else {
			if (data.point.x > max_data.point.x)
				max_data.point.x = data.point.x;
			if (data.point.y > max_data.point.y)
				max_data.point.y = data.point.y;
		}
	}
}

int
get_dist(Data& min_data, Data& max_data) {
	return abs(min_data.point.x - max_data.point.x)
		   + abs(min_data.point.y - max_data.point.y);
}

int
main() {
	std::string case_str = "Kasus #";
	
	int tc = fio.getnumb<int>();
	int case_num = 0;
	
	while (tc--) {
		int n = fio.getnumb<int>();
		
		Data minus_min_data = {{INT_MAX, INT_MAX}, INT_MAX};
		Data minus_max_data = {{INT_MIN, INT_MIN}, INT_MIN};
		Data plus_min_data = {{INT_MAX, INT_MAX}, INT_MAX};
		Data plus_max_data = {{INT_MIN, INT_MIN}, INT_MIN};
		
		for (int i = 0; i < n; i++) {
			int x = fio.getnumb<int>();
			int y = fio.getnumb<int>();
			
			Data minus_data = {{x, y}, (x - y)};
			Data plus_data = {{x, y}, (x + y)};
			
			select_data(plus_data, plus_min_data, plus_max_data);
			select_data(minus_data, minus_min_data, minus_max_data);
		}
		
		int ans = std::max(
			get_dist(minus_min_data, minus_max_data),
			get_dist(plus_min_data, plus_max_data)
		);
		
		fio.printstr(case_str);
		fio.printnumb<int>(++case_num, ": ");
		fio.printnumb<int>(ans, "\n");
	}
	
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

