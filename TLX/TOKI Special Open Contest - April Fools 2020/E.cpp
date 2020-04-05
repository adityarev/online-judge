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


template <typename T> void
print_arr(std::vector<T>& arr) {
	bool first = true;
	for (T &val: arr) {
		if (first)
			first = false;
		else
			std::cout << " ";
		std::cout << val;
	}
	std::cout << std::endl;
}

void
do_observation(
	std::map<std::string,std::map<int,int>>& counter,
	int& obs
) {
	for (int i = 0; i < obs; i++) {
		int n_people = fio.getnumb<int>();
		std::vector<std::string> names;
		
		for (int j = 0; j < n_people; j++) {
			std::string name = fio.getstr();
			names.push_back(name);
		}
		
		std::vector<int> floors;
		
		for (int j = 0; j < n_people; j++) {
			int num = fio.getnumb<int>();
			floors.push_back(num);
		}
		
		for (std::string& name: names) {
			for (int& num: floors)
				counter[name][num]++;
		}
	}
}

void
init_que(
	std::list<std::string>& que,
	std::map<std::string,std::map<int,int>>& counter
) {
	for (auto it = counter.begin(); it != counter.end(); it++) {
		std::string name = it->first;
		que.push_back(name);
	}
}

void
build_ans(
	std::map<std::string,std::map<int,int>>& counter,
	std::vector<std::string>& names,
	std::vector<int>& floors
) {
	std::list<std::string> que;
	init_que(que, counter);
	
	std::map<int,bool> taken_floor;
	taken_floor.clear();
	
	while (!que.empty()) {
		std::string name = que.front();
		que.pop_front();
		
		std::map<int,int>* curr = &counter[name];
		
		int max_count = INT_MIN;
		std::vector<int> floors_on_count;
		
		for (auto it = curr->begin(); it != curr->end(); it++) {
			int key = it->first;
			int val = it->second;
			
			if (val > max_count && !taken_floor[key]) {
				max_count = val;
				floors_on_count.clear();
				floors_on_count = {key};
				continue;
			}
			if (val == max_count && !taken_floor[key]) {
				floors_on_count.push_back(key);
			}
		}
		
		if ((int)floors_on_count.size() == 1) {
			int num = floors_on_count[0];
			
			names.push_back(name);
			floors.push_back(num);
			taken_floor[num] = true;
		} else {
			que.push_back(name);
		}
	}
}

void
show_ans(
	std::vector<std::string>& names,
	std::vector<int>& floors
) {
	print_arr(names);
	print_arr(floors);
}

int
main() {
	int n = fio.getnumb<int>();
	int obs = fio.getnumb<int>();
	
	std::map<std::string,std::map<int,int>> counter;
	do_observation(counter, obs);
	
	std::vector<std::string> names;
	std::vector<int> floors;
	
	build_ans(counter, names, floors);
	show_ans(names, floors);
	
	return 0;
}

