#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Node {
	int key;
	struct Node *left;
	struct Node *right;
	int height;
} NODE_T;

int height(NODE_T *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

NODE_T *newNode (int key)
{
	NODE_T *node = new NODE_T;
	node->key    = key;
	node->left   = NULL;
	node->right  = NULL;
	node->height = 1;
	
	return node;
}

NODE_T *rightRotate(NODE_T *y)
{
	NODE_T *x  = y->left,
		   *T2 = x->right;
	
	x->right = y;
	y->left  = T2;
	
	y->height = 1 + max(height(y->left), height(y->right));
	x->height = 1 + max(height(x->left), height(x->right));
	
	return x;
}

NODE_T *leftRotate(NODE_T *y)
{
	NODE_T *x  = y->right,
		   *T2 = x->left;
	
	x->left  = y;
	y->right = T2;
	
	y->height = 1 + max(height(y->left), height(y->right));
	x->height = 1 + max(height(x->left), height(x->right));
}

int getBalance(NODE_T *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

NODE_T *insert(NODE_T *node, int key)
{
	if (node == NULL)
		return newNode(key);
	
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else
		return node;
	
	node->height = 1 + max( height(node->left),
							height(node->right) );
							
	int balance = getBalance(node);
	
	if (balance > 1 && key < node->left->key)
		return rightRotate(node);
	if (balance < -1 && key > node->right->key)
		return leftRotate(node);
	if (balance > 1 && key > node->left->key) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	
	return node;
}

NODE_T *deleteNode (NODE_T *node, int key)
{
	
	return node;
}

void printInOrder(NODE_T *node)
{
	if (node != NULL) {
		printInOrder(node->left);
		cout << node->key << endl;
		printInOrder(node->right);
	}
}

int main()
{
	NODE_T *root = NULL;
	
	srand(time(NULL));
	for (int i=0; i<10; i++)
		root = insert(root, rand()%101);
	
	printInOrder(root);
	
	return 0;
}
