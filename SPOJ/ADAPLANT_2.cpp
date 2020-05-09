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

const int INITIAL_NODE = 1;
const int SCALE = 4;

template<typename T>
class SegmentTree {
private:
	T* out_range_value;
	std::vector<T>* arr;
	std::vector<T> tree;

public:
	SegmentTree();
	SegmentTree(std::vector<T>* arr, std::function<T(const T&,const T&)>* combine_val, T* out_range_value);
	void set_arr(std::vector<T>* arr, bool auto_build = true);
	void set_combine_val(std::function<T(const T&,const T&)>* combine_val);
	void set_out_range_value(T* out_range_value);
	std::vector<T> get_arr();
	std::vector<T> get_tree();
	void build();
	void update(int idx, T val);
	T query(int l, int r);

private:
	void reset();
	std::function<T(const T&,const T&)>* combine_val;
};

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
		
		SegmentTree<int> min_st(&arr, &fns[MIN_MODE], &out_range_values[MIN_MODE]);
		SegmentTree<int> max_st(&arr, &fns[MAX_MODE], &out_range_values[MAX_MODE]);
		
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

/* FastIO Implementation */
template <typename T> T
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

template <typename T> void
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

/* SegmentTree Implementation */
template<typename T>
void
SegmentTree<T>::reset() {
	out_range_value = NULL;
	arr = NULL;
	tree.clear();
	
	combine_val = NULL;
}

template<typename T>
SegmentTree<T>::SegmentTree() {
	reset();
}

template<typename T>
SegmentTree<T>::SegmentTree(
	std::vector<T>* arr,
	std::function<T(const T&,const T&)>* combine_val,
	T* out_range_value
) {
	reset();
	set_combine_val(combine_val);
	set_out_range_value(out_range_value);
	set_arr(arr, true);
}

template<typename T>
void
SegmentTree<T>::set_arr(std::vector<T>* arr, bool auto_build) {
	this->arr = arr;
	if (auto_build)
		build();
}

template<typename T>
void
SegmentTree<T>::set_combine_val(std::function<T(const T&,const T&)>* combine_val) {
	this->combine_val = combine_val;
}

template<typename T>
void
SegmentTree<T>::set_out_range_value(T* out_range_value) {
	this->out_range_value = out_range_value;
}

template<typename T>
std::vector<T>
SegmentTree<T>::get_arr() {
	return *(this->arr);
}

template<typename T>
std::vector<T>
SegmentTree<T>::get_tree() {
	return this->tree;
}

template<typename T>
void
SegmentTree<T>::build() {
	assert(arr != NULL);
	assert(combine_val != NULL);
	
	int len = (int)arr->size();
	
	std::function<void(int,int,int)>
	_build = [&](int node, int start, int end) -> void {
		if (start == end) {
			tree[node] = (*arr)[start];
			
			return;
		}
		
		int mid = (start + end) / 2;
		
		_build(2 * node, start, mid);
		_build(2 * node + 1, mid + 1, end);
		
		tree[node] = (*combine_val)(tree[2 * node], tree[2 * node + 1]);
	};
	
	int start = 0;
	int end = len - 1;
	
	tree = std::vector<T>(len * SCALE, 0);
	_build(INITIAL_NODE, start, end);
}

template<typename T>
void
SegmentTree<T>::update(int idx, T val) {
	assert(arr != NULL);
	assert(combine_val != NULL);
	
	int len = (int)arr->size();
	
	std::function<void(int,int,int)>
	_update = [&](int node, int start, int end) -> void {
		if (start == end) {
			(*arr)[idx] = val;
			tree[node] = val;
			
			return;
		}
		
		int mid = (start + end) / 2;
		
		if (start <= idx && idx <= mid)
			_update(2 * node, start, mid);
		else
			_update(2 * node + 1, mid + 1, end);
		
		tree[node] = (*combine_val)(tree[2 * node], tree[2 * node + 1]);
	};
	
	int start = 0;
	int end = len - 1;
	
	_update(INITIAL_NODE, start, end);
}

template<typename T>
T
SegmentTree<T>::query(int l, int r) {
	assert(arr != NULL);
	assert(out_range_value != NULL);
	assert(combine_val != NULL);
	
	int len = (int)arr->size();
	
	std::function<int(int,int,int)>
	_query = [&](int node, int start, int end) -> int {
		if (r < start || end < l)
			return *out_range_value;
		if (l <= start && end <= r)
			return tree[node];
		
		int mid = (start + end) / 2;
		T p1 = _query(2 * node, start, mid);
		T p2 = _query(2 * node + 1, mid + 1, end);
		
		return (*combine_val)(p1, p2);
	};
	
	int start = 0;
	int end = len - 1;
	
	return _query(INITIAL_NODE, start, end);
}

