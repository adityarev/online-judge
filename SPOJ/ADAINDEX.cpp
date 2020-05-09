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
	template <typename T> T getnumb();
	template <typename T> void printnumb(T val, std::string suffix = "");
	std::string getstr(bool line_scan = false);
	void printstr(std::string &str);
} fio;


const int ALPH_SIZE = 26;

struct Node {
	int prefix_count;
	Node* children[ALPH_SIZE];
};

int
c_int(char c) {
	return (int)(c - 'a');
}

Node*
create_node() {
	Node* node = new Node;
	
	node->prefix_count = 0;
	memset(node->children, 0, sizeof(node->children));
	
	return node;
}

void
insert_node(Node* root, std::string& str) {
	Node* it = root;
	
	for (char& c: str) {
		int ind = c_int(c);
		
		if ((it->children)[ind] == NULL)
			(it->children)[ind] = create_node();
		
		((it->children)[ind]->prefix_count)++;
		it = (it->children)[ind];
	}
}

int
query(Node* root, std::string& str) {
	Node* it = root;
	
	for (char& c: str) {
		int ind = c_int(c);
		
		if ((it->children)[ind] == NULL)
			(it->children)[ind] = create_node();
		
		it = (it->children)[ind];
	}
	
	return it->prefix_count;
}

int
main() {
	int n = fio.getnumb<int>();
	int que = fio.getnumb<int>();
	Node* root = create_node();
	
	for (int i = 0; i < n; i++) {
		std::string str = fio.getstr();
		insert_node(root, str);
	}
	
	while (que--) {
		std::string str = fio.getstr();
		int ans = query(root, str);
		
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

