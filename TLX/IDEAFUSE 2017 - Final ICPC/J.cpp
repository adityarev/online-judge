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
const int MAX_LEN = 1e5 + 5;
const int OUT_RANGE_VAL = 0;
const int SCALE = 3;

int tree[SCALE * MAX_LEN];
int N;
int max_index = -1;

int combine_val(int,int);
void update(int,int);
int query(int,int);

void
reset() {
	for (int i = 0; i <= max_index; i++)
		tree[i] = 0;
	max_index = -1;
}

LL
get_ans() {
	LL ans = 0LL;
	
	for (int i = 0; i < N; i++) {
		int x = fio.getnumb<int>();
		update(x - 1, 1);
		
		int dist = query(x, N - 1);
		ans += (LL)dist;
	}
	
	return ans;
}

void
run_case(int case_num) {
	N = fio.getnumb<int>();
	reset();
	
	static std::string CASE = "Case #";
	LL ans = get_ans();
	
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

int
combine_val(int l_val, int r_val) {
	return (l_val + r_val);
}

void
update(int idx, int val) {
	std::function<void(int,int,int)>
	_update = [&](int node, int start, int end) -> void {
		max_index = std::max(max_index, node);
		
		if (start == end) {
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
	int end = N - 1;
	
	_update(INITIAL_NODE, start, end);
}

int
query(int l, int r) {
	std::function<int(int,int,int)>
	_query = [&](int node, int start, int end) -> int {
		max_index = std::max(max_index, node);
		
		if (r < start || end < l)
			return OUT_RANGE_VAL;
		if (l <= start && end <= r)
			return tree[node];
		
		int mid = (start + end) / 2;
		int p1 = _query(2 * node, start, mid);
		int p2 = _query(2 * node + 1, mid + 1, end);
		
		return combine_val(p1, p2);
	};
	
	int start = 0;
	int end = N - 1;
	
	return _query(INITIAL_NODE, start, end);
}

