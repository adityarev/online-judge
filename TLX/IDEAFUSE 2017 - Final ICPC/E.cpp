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


struct Time {
	int start;
	int end;
};

void
set_times(std::vector<Time>& times) {
	for (Time& t: times) {
		t.start = fio.getnumb<int>();
		t.end = fio.getnumb<int>();
	}
	std::sort(times.begin(), times.end(), [](const Time& a, const Time& b) {
		return (a.start == b.start ? a.end < b.end : a.start < b.start);
	});
}

struct PQCompare {
	bool operator()(const Time& a, const Time& b) {
		return (a.end == b.end ? a.start > b.start : a.end > b.end);
	};
};

int
get_ans(std::vector<Time>& times) {
	int ans = -1;
	int max_val = 0;
	std::priority_queue<Time, std::vector<Time>, PQCompare> included;
	
	for (Time& t: times) {
		while (!included.empty()) {
			Time temp = included.top();
			if (temp.end < t.start)
				included.pop();
			else
				break;
		}
		included.push(t);
		
		int count = (int)included.size();
		
		if (count > max_val) {
			ans = t.start;
			max_val = count;
		}
	}
	
	return ans;
}

void
run_case(int case_num) {
	int n = fio.getnumb<int>();
	
	std::vector<Time> times(n);
	set_times(times);
	
	static std::string CASE = "Case #";
	int ans = get_ans(times);
	
	fio.printstr(CASE);
	fio.printnumb<int>(case_num, ": ");
	fio.printnumb<LL>(ans, "\n");
}

int
main() {
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++)
		run_case(i + 1);
	
	return 0;
}

