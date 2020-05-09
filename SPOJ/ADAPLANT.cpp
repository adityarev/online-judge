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


const int INITIAL_NODE = 1;
const int SCALE = 4;
const int OUT_RANGE_VALUE = 0;

enum {
	MIN_MODE = 0,
	MAX_MODE
};

std::vector<int> out_range_values = {INT_MAX, INT_MIN};
std::vector<std::function<int(const int&, const int&)>>
fns = {
	[](const int& a, const int& b) -> int {
		return std::min(a, b);
	},
	[](const int& a, const int& b) -> int {
		return std::max(a, b);
	}
};

class SegmentTree {
private:
	int flag;
	std::vector<int> arr;
	std::vector<int> tree;
	void reset(int);

public:
	SegmentTree();
	SegmentTree(std::vector<int>&,int);
	void set_arr(std::vector<int>&,bool);
	std::vector<int> get_arr();
	std::vector<int> get_tree();
	void build();
	void update(int,int);
	int query(int,int);
};

void
set_arr(std::vector<int>& arr) {
	for (int& x: arr)
		x = fio.getnumb<int>();
}

int
main() {
	int tc = fio.getnumb<int>();
	
	while (tc--) {
		int n = fio.getnumb<int>();
		int k = fio.getnumb<int>();
		
		std::vector<int> arr(n);
		set_arr(arr);
		
		SegmentTree min_st(arr, MIN_MODE);
		SegmentTree max_st(arr, MAX_MODE);
		
		int l = 0;
		int r = std::min(n - 1, k + 1);
		int ans = INT_MIN;
		
		while (r < n) {
			int min_val = min_st.query(l, r);
			int max_val = max_st.query(l, r);
			int val = max_val - min_val;
			
			ans = std::max(ans, val);
			l++;
			r++;
		}
		
		fio.printnumb<int>(ans, "\n");
	}
	
	return 0;
}

void
SegmentTree::reset(int flag) {
	this->flag = flag;
	arr.clear();
	tree.clear();
}

SegmentTree::SegmentTree() {
	reset(MIN_MODE);
}

SegmentTree::SegmentTree(std::vector<int>& arr, int flag) {
	reset(flag);
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

std::vector<int>
SegmentTree::get_tree() {
	return this->tree;
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
		
		tree[node] = fns[flag](tree[2 * node], tree[2 * node + 1]);
	};
	
	int start = 0;
	int end = len - 1;
	
	tree = std::vector<int>(len * SCALE, 0);
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
		
		tree[node] = fns[flag](tree[2 * node], tree[2 * node + 1]);
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
			return out_range_values[flag];
		if (l <= start && end <= r)
			return tree[node];
		
		int mid = (start + end) / 2;
		int p1 = _query(2 * node, start, mid);
		int p2 = _query(2 * node + 1, mid + 1, end);
		
		return fns[flag](p1, p2);
	};
	
	int start = 0;
	int end = len - 1;
	
	return _query(INITIAL_NODE, start, end);
}

