#include <algorithm>
#include <cassert>
#include <climits>
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

vector<vector<bool>>
get_grid_taken(vector<vector<int>>& grid) {
	int i = 0;
	vector<vector<bool>> taken;
	
	for (vector<int>& line: grid) {
		taken.push_back(vector<bool>());
		for (int& x: line)
			taken[i].push_back(x == -1);
		i++;
	}
	
	return taken;
}

vector<vector<int>>
get_broken_grid(
	vector<vector<int>>& grid,
	int& i,
	int& j
) {
	int row = (int)grid.size();
	int col = (int)grid[0].size();
	
	vector<vector<int>> broken_grid = grid;
	vector<vector<bool>> taken(row, vector<bool>(col, false));
	
	int num = grid[i][j];
	vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	
	function<void(int,int)>
	_break_grid = [&](int x, int y) -> void {
		taken[x][y] = true;
		broken_grid[x][y] = -1;
		
		for (vector<int>& move: moves) {
			int xx = x + move[0];
			int yy = y + move[1];
			
			if (
				is_in_range(xx, 0, row - 1)
				&& is_in_range(yy, 0, col - 1)
				&& !taken[xx][yy]
				&& grid[xx][yy] == num
			) {
				_break_grid(xx, yy);
			}
		}
	};
	
	function<void(int,int)>
	_normalize_column = [&](int x, int y) -> void {
		int p = x;
		
		while (p >= 0 && broken_grid[p][y] == -1)
			p--;
		
		if (p != -1) {
			while (p + 1 < row && broken_grid[p + 1][y] == -1) {
				swap(broken_grid[p][y], broken_grid[p + 1][y]);
				p++;
			}
		}
	};
	
	function<void()>
	_normalize_grid = [&]() -> void {
		for (int k = row - 1; k >= 0; k--) {
			for (int l = 0; l < col; l++) {
				if (broken_grid[k][l] == -1)
					_normalize_column(k, l);
			}
		}
	};
	
	_break_grid(i, j);
	_normalize_grid();
	
	return broken_grid;
}

int
main() {
	int row, col;
	cin >> row >> col;
	
	vector<vector<int>> grid(row, vector<int>(col));
	set_grid(grid);
	
	int max_point = INT_MIN;
	vector<vector<bool>> taken(row, vector<bool>(col, false));
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!taken[i][j]) {
				int point1 = get_point(grid, taken, i, j);
				int point2 = 0;
				
				vector<vector<int>> broken_grid = get_broken_grid(grid, i, j);
				vector<vector<bool>> broken_taken = get_grid_taken(broken_grid);
				
				for (int k = 0; k < row; k++) {
					for (int l = 0; l < col; l++) {
						if (!broken_taken[k][l]) {
							int point = get_point(broken_grid, broken_taken, k, l);
							point2 = max(point2, point);
						}
					}
				}
				
				int point = point1 + point2;
				max_point = max(max_point, point);
			}
		}
	}
	
	assert(max_point != INT_MIN);
	cout << max_point << endl;
	
	return 0;
}

