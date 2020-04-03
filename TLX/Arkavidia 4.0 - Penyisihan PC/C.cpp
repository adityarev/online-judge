#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)
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

const int INITIAL_NODE = 1;
const int MAX_LEN = 200000;

class SegmentTree {
private:
	std::vector<int> arr;
	int tree[2 * MAX_LEN];
	void reset();
	int combine_val(int,int);

public:
	SegmentTree();
	SegmentTree(std::vector<int>&);
	void set_arr(std::vector<int>&,bool);
	std::vector<int> get_arr();
	void build();
	void update(int,int);
	int query(int,int);
};

void
set_arr(std::vector<int>& arr) {
	for (int &x: arr)
		x = fio.getnumb<int>();
}

std::vector<int> arr;
SegmentTree st;

void
run_case() {
	int n = fio.getnumb<int>();
	
	arr = std::vector<int>(n);
//	set_arr(arr);
	
	st.set_arr(arr, true);
	int que = fio.getnumb<int>();
	
	while (que--) {
		int l = fio.getnumb<int>() - 1;
		int r = fio.getnumb<int>() - 1;
		
		int ans = st.query(l, r);
		fio.printnumb<int>(ans, "\n");
	}
}

int
main() {
	int tc = fio.getnumb<int>();
	
	for (int i = 0; i < tc; i++)
		run_case();
	
	return 0;
}

void
SegmentTree::reset() {
	arr.clear();
}

int
SegmentTree::combine_val(int l_val, int r_val) {
	return (l_val & r_val);
}

SegmentTree::SegmentTree() {
	reset();
}

SegmentTree::SegmentTree(std::vector<int>& arr) {
	reset();
	set_arr(arr, true);
}

void
SegmentTree::set_arr(std::vector<int>& arr, bool auto_build = true) {
	this->arr = arr;
	if (auto_build)
		build();
}

std::vector<int>
SegmentTree::get_arr() {
	return this->arr;
}

void
SegmentTree::build() {
	int len = (int)arr.size();
	
	std::function<void(int,int,int)>
	_build = [&](int node, int start, int end) -> void {
		if (start == end) {
			tree[node] = arr[start];
			
			return;
		}
		
		int mid = (start + end) / 2;
		
		_build(2 * node, start, mid);
		_build(2 * node + 1, mid + 1, end);
		
		tree[node] = combine_val(tree[2 * node], tree[2 * node + 1]);
	};
	
	int start = 0;
	int end = len - 1;
	
	_build(INITIAL_NODE, start, end);
}

void
SegmentTree::update(int idx, int val) {
	int len = (int)arr.size();
	
	std::function<void(int,int,int)>
	_update = [&](int node, int start, int end) -> void {
		if (start == end) {
			arr[idx] = val;
			tree[node] = val;
			
			return;
		}
		
		int mid = (start + end) / 2;
		
		if (start <= idx && idx <= mid)
			_update(2 * node, start, mid);
		else
			_update(2 * node + 1, mid + 1, end);
		
		tree[node] = combine_val(tree[2 * node], tree[2 * node + 1]);
	};
	
	int start = 0;
	int end = len - 1;
	
	_update(INITIAL_NODE, start, end);
}

int
SegmentTree::query(int l, int r) {
	int len = (int)arr.size();
	
	std::function<int(int,int,int)>
	_query = [&](int node, int start, int end) -> int {
		if (r < start || end < l)
			return INT_MAX;
		if (l <= start && end <= r)
			return tree[node];
		
		int mid = (start + end) / 2;
		int p1 = _query(2 * node, start, mid);
		int p2 = _query(2 * node + 1, mid + 1, end);
		
		return combine_val(p1, p2);
	};
	
	int start = 0;
	int end = len - 1;
	
	return _query(INITIAL_NODE, start, end);
}

