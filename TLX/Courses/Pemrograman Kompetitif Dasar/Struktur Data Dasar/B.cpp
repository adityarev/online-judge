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


struct Value {
	int number;
	int freq;
};

const std::string ADD = "add";
const std::string DEL = "del";
const std::string REV = "rev";

int
main() {
	int que = fio.getnumb<int>();
	
	bool rev_mode = false;
	int counter = 0;
	
	std::list<Value> li;
	
	while (que--) {
		std::string cmd = fio.getstr();
		
		if (cmd == ADD) {
			int number = fio.getnumb<int>();
			int freq = fio.getnumb<int>();
			Value value = {number, freq};
			
			if (!rev_mode)
				li.push_back(value);
			else
				li.push_front(value);
			
			counter += freq;
			fio.printnumb<int>(counter, "\n");
		} else if (cmd == DEL) {
			int temp = fio.getnumb<int>();
			int first_num = (!rev_mode ? li.front().number : li.back().number);
			
			while (!li.empty() && temp > 0) {
				Value* value = (!rev_mode ? &li.front() : &li.back());
				int min_val = std::min(temp, value->freq);
				
				temp -= min_val;
				counter -= min_val;
				
				if (value->freq == min_val) {
					if (!rev_mode)
						li.pop_front();
					else
						li.pop_back();
				} else {
					value->freq -= min_val;
				}
			}
			
			fio.printnumb<int>(first_num, "\n");
		} else {
			rev_mode = !rev_mode;
		}
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

