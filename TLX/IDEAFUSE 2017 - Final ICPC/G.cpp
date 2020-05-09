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


const int N_APLH = 26;

int
c_int(char c) {
	return (int)(c - 'A');
}

char
i_char(int i) {
	return (char)('A' + i);
}

void
set_adj(std::vector<std::vector<char>>& adj) {
	std::vector<std::vector<bool>> taken(N_APLH, std::vector<bool>(N_APLH, false));
	
	for (int i = 0; i < N_APLH; i++) {
		std::string s = fio.getstr();
		
		for (char& c: s) {
			int curr = c_int(c);
			
			if (!taken[i][curr]) {
				adj[i].push_back(c);
				taken[i][curr] = true;
			}
		}
	}
}

struct Node {
	char prev;
	char curr;
	int dist;
};

void
set_dist(
	std::vector<std::vector<int>>& dist,
	std::vector<std::vector<char>>& adj
) {
	std::list<Node> bfs;
	
	std::function<void(Node&)>
	_mark_node = [&](Node& node) -> void {
		int prev = c_int(node.prev);
		int curr = c_int(node.curr);
		
		if (node.dist < dist[prev][curr]) {
			dist[prev][curr] = node.dist;
			bfs.push_back(node);
		}
	};
	
	for (int i = 0; i < N_APLH; i++) {
		Node node = {i_char(i), i_char(i), 0};
		_mark_node(node);
	}
	
	while (!bfs.empty()) {
		Node node = bfs.front();
		bfs.pop_front();
		
		for (char& c: adj[c_int(node.curr)]) {
			Node next = {node.prev, c, node.dist + 1};
			_mark_node(next);
		}
	}
}

int
get_ans(
	std::string& src,
	std::string& dest,
	std::vector<std::vector<int>>& dist
) {
	int ans = 0;
	int len = (int)src.length();
	
	for (int i = 0; i < len; i++) {
		int prev = c_int(src[i]);
		int curr = c_int(dest[i]);
		
		if (dist[prev][curr] == INT_MAX)
			return -1;
		ans += dist[prev][curr];
	}
	
	return ans;
}

int
main() {
	std::string src;
	std::cin >> src;
	
	std::string dest;
	std::cin >> dest;
	
	std::vector<std::vector<char>> adj(N_APLH, std::vector<char>());
	set_adj(adj);
	
	std::vector<std::vector<int>> dist(N_APLH, std::vector<int>(N_APLH, INT_MAX));
	set_dist(dist, adj);
	
	int ans = get_ans(src, dest, dist);
	
	if (ans == -1)
		puts("IMPOSSIBLE");
	else
		fio.printnumb<int>(ans, "\n");
	
	return 0;
}

