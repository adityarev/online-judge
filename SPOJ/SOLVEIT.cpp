#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

typedef struct Node {
	int key;
	int l, mid, r;
	struct Node *left, *right;
} NODE_T;

int pow2[32];
void initPow2() {
	int val = 1;
	
	for (int i=0; i<32; i++) {
		pow2[i] = val;
		val <<= 1;
	}
}

int getMid(int l, int r) {
	int i = 0,
		diff = r-l;
	
	for (int i=0; i<32; i++) {
		if (pow2[i] >= diff)
			return (l+pow2[i-1]);
	}
}

int getKey(NODE_T *node) {
	if (node == NULL) {
		return 0;
	} else {
		return node->key;
	}
}

NODE_T *newNode(int l, int r) {
	NODE_T *node = new NODE_T;
	node->key = INT_MIN;
	node->l = l;
	node->r = r;
	node->mid = getMid(l, r);
	node->left = NULL;
	node->right = NULL;
	
	return node;
}

class SegmentTree {
private :
	int N;
	vector<int> arr;
	NODE_T *root;
	
	NODE_T *construct(NODE_T *root, int l, int r) {
		if (l >= r)
			return NULL;
		
		NODE_T *node = newNode(l, r);
		
		if (r-l == 1) {
			node->key = arr[l];
		} else {
			node->left = construct(node->left, l, node->mid);
			node->right = construct(node->right, node->mid, r);
			
			node->key = max(getKey(node->left), getKey(node->right));
		}
		
		return node;
	}
	
	void runUpdate(NODE_T *node, int ind, int key) {
		if (node == NULL)
			return;
		
		if (node->l == ind && (node->r - node->l == 1)) {
			node->key = key;
		} else {
			if (ind < node->mid)
				runUpdate(node->left, ind, key);
			else
				runUpdate(node->right, ind, key);
			
			node->key = max(getKey(node->left), getKey(node->right));
		}
		return;
	}
	
	int runSearch (NODE_T *node, int l, int r) {
		if (node == NULL)
			return INT_MIN;
		
		if (node->l == l && node->r == r) {
			return node->key;
		} else {
			if (r <= node->mid) {
				return runSearch (node->left, l, r);
			} else if (l >= node->mid) {
				return runSearch (node->right, l, r);
			} else {
				return max(runSearch (node->left, l, node->mid),
						   runSearch (node->right, node->mid, r));
			}
		}
	}
	
public :
	SegmentTree() {}
	
	SegmentTree(vector<int> arr, int N) {
		this->arr = arr;
		this->N = N;
		this->root = construct(this->root, 0, N);
	}
	
	int searchMax(int l, int r) {
		runSearch(root, l, r);
	}
	
	void update(int ind, int key) {
		runUpdate(root, ind, key);
	}
};

void inOrder(NODE_T *node)
{
	if (node != NULL) {
		inOrder(node->left);
		cout << node->key << " ";
		inOrder(node->right);
	}
}

int scanint() {
	int c = getchar(), x = 0;
	for (;c<48||c>57; c=getchar());
	for (;c>47&&c<58; c=getchar())
		x = (x<<1)+(x<<3)+c-48;
	return x;
}

int main()
{
	initPow2();
	
	int N = scanint(),
		que = scanint();
	
	vector<int> arr;
	for (int i=0; i<n; i++)
		arr.push_back(0);
	
	SegmentTree *mySegTree = new SegmentTree(arr, N);
	while (que--) {
		
	}
	
	return 0;
}
