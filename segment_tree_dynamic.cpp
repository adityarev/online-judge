#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

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
	void set_combine_val(std::function<T(const T&, const T&)>* combine_val);
	void set_out_range_value(T* out_range_value);
	std::vector<T> get_arr();
	std::vector<T> get_tree();
	void build();
	void update(int idx, T val);
	T query(int l, int r);

private:
	void reset();
	std::function<T(const T&, const T&)>* combine_val;
};


int
main() {
	// Your code goes here
		
	return 0;
}

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
SegmentTree<T>::set_combine_val(std::function<T(const T&, const T&)>* combine_val) {
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

