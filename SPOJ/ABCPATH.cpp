#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define MAX 55
#define N_DIR 8

using namespace std;

int row;
int col;
char inp[MAX][MAX];
bool visited[MAX][MAX];

void
init_global() {
	memset(visited, false, sizeof(visited));
}

bool is_in_range(int &x, int &y) {
	return (0 <= x && x < row) && (0 <= y && y < col);
}

bool is_consecutive_letter(char &c, char &cc) {
	return (int)(cc - c) == 1;
}

int
get_path_len(char c, int x, int y, int len) {
	static int dx[N_DIR] = {-1, -1, -1, 0, 1, 1, 1, 0};
	static int dy[N_DIR] = {-1, 0, 1, 1, 1, 0, -1, -1};
	
	int max_len = len;
	for (int i = 0; i < N_DIR; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		
		if (is_in_range(xx, yy) && !visited[xx][yy]) {
			char cc = inp[xx][yy];
			
			if (is_consecutive_letter(c, cc)) {
				visited[xx][yy] = true;
				max_len = max(max_len, get_path_len(cc, xx, yy, len + 1));
				visited[xx][yy] = false;
			}
		}
	}
	
	return max_len;
}

void
show_map() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			putchar(inp[i][j]);
		}
		putchar('\n');
	}
}

int
get_ans(int x, int y) {
	visited[x][y] = true;
	
	char c = 'A';
	int len = 1;
	int ans = get_path_len(c, x, y, len);
	
	visited[x][y] = false;
	
	return ans;
}

int
main() {
	init_global();
	
	int row;
	int col;
	int countup = 0;
	
	while (scanf("%d %d%*c", &row, &col)) {
		if (row == 0 || col == 0)
			break;
		
		vector<pair<int,int> > start_points;
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				inp[i][j] = getchar();
				if (inp[i][j] == 'A') {
					pair<int,int> point = make_pair(i, j);
					start_points.push_back(point);
				}
			}
			getchar();
		}
		
		show_map();
		
		printf("%d\n", start_points.size());
		
		int ans = 0;
		for (pair<int,int> point : start_points) {
			int x = point.first;
			int y = point.second;
			
			
			printf("%d %d\n", x, y);
			
			ans = max(ans, get_ans(x, y));
		}
		
		printf("Case %d: %d\n", ++countup, ans);
	}
	
	return 0;
}

