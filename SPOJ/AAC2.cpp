#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

using namespace std;

int scanint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

int find_parent(vector<int> &parent, int &child) {
	if (parent[child] == child)
		return parent[child];
	return find_parent(parent, parent[child]);
}

bool valid(int n, vector<pair<int,int> > &equals, vector<pair<int,int> > &not_equals) {
	vector<int> parent(n + 1);
	
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	
	sort(equals.begin(), equals.end());
	for (pair<int,int> edge : equals) {
		int ancestor = edge.first;
		int curr = edge.second;
		
		parent[curr] = find_parent(parent, ancestor);
	}
	
	for (pair<int,int> edge : not_equals) {
		int a = edge.first;
		int b = edge.second;
		
		if (parent[a] == parent[b])
			return false;
	}
	
	return true;
}

int main()
{
	int tc;
	tc = scanint();
	
	while (tc--) {
		int n, k;
		n = scanint(); k = scanint();
		
		vector<pair<int,int> > equals;
		vector<pair<int,int> > not_equals;
		
		for (int i = 0; i < k; i++) {
			int a = scanint();
			char sign = gc();
			int b = scanint();
			
			int min_val = min(a, b);
			int max_val = max(a, b);
			pair<int,int> edge = make_pair(min_val, max_val);
			
			if (sign == '=')
				equals.push_back(edge);
			else
				not_equals.push_back(edge);
		}
		
		puts(valid(n, equals, not_equals) ? "YES" : "NO");
	}
	
	return 0;
}

