#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

bool
is_in_range(int val, int l, int r) {
	return (l <= val && val <= r);
}

void
set_grid(vector<vector<int>>& grid) {
	for (vector<int>& line: grid)
		for (int& x: line)
			cin >> x;
}

int
get_point(
	vector<vector<int>>& grid,
	vector<vector<bool>>& taken,
	int i,
	int j
) {
	int row = (int)grid.size();
	int col = (int)grid[0].size();
	
	vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	int counter = 0;
	int num = grid[i][j];
	
	function<void(int,int)>
	_dfs = [&](int x, int y) -> void {
		taken[x][y] = true;
		counter++;
		
		for (vector<int>& move: moves) {
			int xx = x + move[0];
			int yy = y + move[1];
			
			if (
				is_in_range(xx, 0, row - 1)
				&& is_in_range(yy, 0, col - 1)
				&& !taken[xx][yy]
				&& grid[xx][yy] == num
			) {
				_dfs(xx, yy);
			}
		}
	};
	_dfs(i, j);
	
	return counter * (counter - 1);
}

int
main() {
	int row, col;
	cin >> row >> col;
	
	vector<vector<int>> grid(row, vector<int>(col));
	set_grid(grid);
	
	int ans = 0;
	vector<vector<bool>> taken(row, vector<bool>(col, false));
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!taken[i][j]) {
				int point = get_point(grid, taken, i, j);
				ans = max(ans, point);
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}

