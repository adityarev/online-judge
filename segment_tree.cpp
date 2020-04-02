#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

const int INITIAL_NODE = 1;

class SegmentTree {
private:
	std::vector<int> arr;
	std::vector<int> tree;
	void reset();
	int combine_val(int,int);

public:
	SegmentTree();
	SegmentTree(std::vector<int>&);
	void set_arr(std::vector<int>&,bool);
	std::vector<int> get_arr();
	std::vector<int> get_tree();
	void build();
	void update(int,int);
	int query(int,int);
};


int
main() {
	// Your code goes here
		
	return 0;
}

void
SegmentTree::reset() {
	arr.clear();
	tree.clear();
}

int
SegmentTree::combine_val(int l_val, int r_val) {
	return (l_val + r_val);
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
		
		tree[node] = combine_val(tree[2 * node], tree[2 * node + 1]);
	};
	
	int start = 0;
	int end = len - 1;
	
	tree = std::vector<int>(len * 2, 0);
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
			return 0;
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

