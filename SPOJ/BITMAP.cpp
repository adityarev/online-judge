#include <algorithm>
#include <cstdio>
#include <cstring>
#include <list>
#include <vector>

using namespace std;

#define gc(x) getchar(x)
#define pc(x) putchar(x)

int
getint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

void
printint(int val) {
	if (val == 0LL)
		return;
	printint(val / 10);
	pc('0' + (val % 10));
}

#define MAX 205

typedef pair<int,int> pii;
struct Node {
	pii point;
	int dist;
	
	Node(pii &point, int &dist) {
		this->point = point;
		this->dist = dist;
	}
};

void
run_input(
	vector<char> grid[],
	const int &row,
	const int &col
) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			grid[i].push_back(gc());
		gc();
	}
}

int
get_nearest(
	const vector<char> grid[],
	const int &row,
	const int &col,
	const int &x,
	const int &y
) {
	bool visited[row][col];
	memset(visited, false, sizeof(visited));
	
	pii f_point = make_pair(x, y);
	int f_dist = 0;
	
	list<struct Node> que;
	struct Node f_node = Node(f_point, f_dist);
	
	static auto is_in_range = [&](int &xx, int &yy) {
		return true
			&& (0 <= xx && xx <= row)
			&& (0 <= yy && yy <= col);
	};
	static const int d_sz = 4;
	static int dx[d_sz] = {-1, 0, 1, 0};
	static int dy[d_sz] = {0, 1, 0, -1};
	
	que.push_back(f_node);
	while (!que.empty()) {
		struct Node node = que.front();
		que.pop_front();
		
		int x = node.point.first;
		int y = node.point.second;
		
		char c = grid[x][y];
		int dist = node.dist;
		
		if (c == '1')
			return dist;
		
		for (int i = 0; i < d_sz; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			
			if (is_in_range(xx, yy) && !visited[xx][yy]) {
				pii n_point = make_pair(xx, yy);
				int n_dist = dist + 1;
				
				struct Node n_node = Node(n_point, n_dist);
				que.push_back(n_node);
			}
		}
	}
	
	return -1;
}

void
show_ans(const vector<char> grid[], const int &row, const int &col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int dist = get_nearest(grid, row, col, i, j);
			
			if (dist == 0)
				pc('0');
			else
				printint(dist);
			pc((j != col - 1) ? ' ' : '\n');
		}
	}
}

int
main() {
	int tc = getint();
	
	while (tc--) {
		int row = getint();
		int col = getint();
		vector<char> grid[MAX];
		
		run_input(grid, row, col);
		show_ans(grid, row, col);
	}
	
	return 0;
}
