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


struct Node {
	int carry;
	std::vector<bool> binaries;
};

enum { ZERO = 0, ONE = 1 };

std::vector<bool>
get_binaries(int& n) {
	Node start = {1, {true}};
	
	if (n == 1)
		return start.binaries;
	
	std::list<Node> bfs;
	std::vector<bool> visited(n, false);
	
	bfs.push_back(start);
	visited[start.carry] = true;
	
	while (!bfs.empty()) {
		Node node = bfs.front();
		bfs.pop_front();
		
		int carry0 = (node.carry * 10) % n;
		std::vector<bool> binaries0 = node.binaries;
		
		binaries0.push_back(ZERO);
		if (carry0 == 0)
			return binaries0;
		else if (!visited[carry0]) {
			bfs.push_back({carry0, binaries0});
			visited[carry0] = true;
		}
		
		int carry1 = (node.carry * 10 + 1) % n;
		std::vector<bool> binaries1 = node.binaries;
		
		binaries1.push_back(ONE);
		if (carry1 == 0)
			return binaries1;
		else if (!visited[carry1]) {
			bfs.push_back({carry1, binaries1});
			visited[carry1] = true;
		}
	}
	
	return {};
}

std::string
to_binary_string(std::vector<bool>& binaries) {
	std::string str = "";
	for (bool flag: binaries)
		str += (flag == ZERO ? '0' : '1');
	return str;
}

int
main() {
	int tc = fio.getnumb<int>();
	
	while (tc--) {
		int n = fio.getnumb<int>();
		std::vector<bool> binaries = get_binaries(n);
		std::string ans = to_binary_string(binaries);
		
		fio.printstr(ans); endline;
	}
	
	return 0;
}

