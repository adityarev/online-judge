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
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)
#define endline pc('\n')

typedef long long LL;

using namespace std;

struct FastIO {
	template <typename T> T
	getnumb() {
		T c = gc();
		
		function<bool()> is_negative = [&]() -> bool {
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
	
	string
	getstr(bool line_scan = false) {
		function<bool(char&)> is_separator = [&](char &c) -> bool {
			return c == '\n' || (c == ' ' && !line_scan) || c == EOF;
		};
		
		char c;
		string str = "";
		
		while ((c = gc()) && is_separator(c));
		do {
			str += c;
		} while ((c = gc()) && !is_separator(c));
		
		return str;
	}
	
	template <typename T> void
	printnumb(T val, string suffix = "") {
		function<void(T)> _print = [&](T x) -> void {
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
	printstr(string &str) {
		for (char &c: str)
			pc(c);
	}
} fio;

struct Node {
	int id;
	int dist;
};

struct NodeCompare {
	bool operator()(const Node& a, const Node& b) {
		return a.dist > b.dist;
	}
};

void
set_adjs(vector<Node> adjs[], int& e) {
	for (int i = 0; i < e; i++) {
		int a = fio.getnumb<int>() - 1;
		int b = fio.getnumb<int>() - 1;
		int dist = fio.getnumb<int>();
		
		adjs[a].push_back({b, dist});
		adjs[b].push_back({a, dist});
	}
}

int
get_ans(
	vector<Node> adjs[],
	int& v,
	int& start,
	int& dest
) {
	vector<int> min_dist(v, INT_MAX);
	priority_queue<Node, vector<Node>, NodeCompare> travel;
	
	travel.push({start, 0});
	while (!travel.empty()) {
		Node node = travel.top();
		travel.pop();
		
		min_dist[node.id] = node.dist;
		
		if (node.id == dest)
			return min_dist[node.id];
		
		for (Node& adj: adjs[node.id]) {
			int dist = min_dist[node.id] + adj.dist;
			
			if (dist < min_dist[adj.id])
				travel.push({adj.id, dist});
		}
	}
	
	return -1;
}

int
main() {
	int v = fio.getnumb<int>();
	int e = fio.getnumb<int>();
	int start = fio.getnumb<int>() - 1;
	int dest = fio.getnumb<int>() - 1;
	
	vector<Node> adjs[v];
	set_adjs(adjs, e);
	
	int ans = get_ans(adjs, v, start, dest);
	fio.printnumb<int>(ans, "\n");
	
	return 0;
}

