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
#include <stack>
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

const std::string ADD = "add";
const std::string DEL = "del";
const std::string ADX = "adx";
const std::string DEX = "dex";

struct Value {
	int number;
	int freq;
	int left_index;
};

void
add(
	std::stack<Value>& st,
	int& counter,
	std::vector<int>& carries
) {
	int number = fio.getnumb<int>();
	int freq = fio.getnumb<int>();
	int left_index = (int)carries.size() - 1;
	
	st.push({number, freq, left_index});
	counter += freq;
	
	fio.printnumb<int>(counter, "\n");
}

void
del(
	std::stack<Value>& st,
	int& counter,
	std::vector<int>& carries
) {
	int freq = fio.getnumb<int>();
	int number = st.top().number + (carries.back() - carries[st.top().left_index]);
	
	while (!st.empty() && freq > 0) {
		Value val = st.top();
		st.pop();
		
		int min_freq = std::min(freq, val.freq);
		
		counter -= min_freq;
		freq -= min_freq;
		
		if (val.freq > min_freq) {
			val.freq -= min_freq;
			st.push(val);
		}
	}
	
	fio.printnumb<int>(number, "\n");
}

void
adx(std::vector<int>& carries) {
	int x = fio.getnumb<int>();
	carries.push_back(carries.back() + x);
}

void
dex(std::vector<int>& carries) {
	int x = fio.getnumb<int>();
	carries.push_back(carries.back() - x);
}

int
main() {
	std::stack<Value> st;
	
	int counter = 0;
	std::vector<int> carries(1, 0);
	
	int que = fio.getnumb<int>();
	
	while (que--) {
		std::string cmd = fio.getstr();
		
		if (cmd == ADD)
			add(st, counter, carries);
		else if (cmd == DEL)
			del(st, counter, carries);
		else if (cmd == ADX)
			adx(carries);
		else if (cmd == DEX)
			dex(carries);
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

