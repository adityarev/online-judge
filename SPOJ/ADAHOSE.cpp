#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

#define oo INT_MAX
#define N_DIR 4

typedef pair<int,int> NODE;

#define _n_cost(x) (x).first
#define _n_index(x) (x).second

const int dx[N_DIR] = {0, 1, 0, -1};
const int dy[N_DIR] = {1, 0, -1, 0};

const int N = 1002;
int dist[N * N];
int inp[N][N];

struct NodeCompare {
    bool operator()(const NODE &a, const NODE &b) {
    	return _n_cost(a) > _n_cost(b);
	};
};
priority_queue<NODE, vector<NODE>, NodeCompare> pq;

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

int scanint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

void
run_input(int &n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			inp[i][j] = scanint();
}

void
init_dist(int &n) {
	int s = n * n;
	for (int i = 0; i < s; i++)
		dist[i] = oo;
}

void
construct_dist(int &n) {
	int s = n * n;
	dist[s] = 0;
	
	NODE first_node = make_pair(0, s);
	pq.push(first_node);
	
	while (!pq.empty()) {
		NODE node = pq.top();
		pq.pop();
		
		if (dist[_n_index(node)] < _n_cost(node))
			continue;
		
		if (_n_index(node) == s) {
			for (int i = 0; i < n; i++) {
				int cost = _n_cost(node) + inp[i][0];
				int next = i * n;
				
				if (dist[next] > cost) {
					NODE new_node = make_pair(cost, next);
					
					dist[next] = cost;
					pq.push(new_node);
				}
			}
			
			continue;
		}
		
		int x = _n_index(node) / n;
		int y = _n_index(node) % n;
		
		for (int i = 0; i < N_DIR; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if (xx < 0 || xx >= n || yy < 0 || yy >= n)
				continue;
			
			int ii = xx * n + yy;
			int cost = inp[x][y] + inp[xx][yy] + _n_cost(node);
			
			if (dist[ii] > cost) {
				NODE new_node = make_pair(cost, ii);
					
				dist[ii] = cost;
				pq.push(new_node);
			}
		}
	}
}

int
main() {
	int n;
	n = scanint();
	
	run_input(n);
	init_dist(n);
	construct_dist(n);
	
	int res = oo;
	for (int i = 0; i < n; i++) {
		int cost = dist[i * n + n - 1] + inp[i][n - 1];
		res = min(res, cost);
	}
	
	printf("%d\n", res);
	
	return 0;
}

