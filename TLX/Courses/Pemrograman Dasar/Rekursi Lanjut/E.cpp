#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int
get_lowest_power_num(int x, int base) {
	int curr = 1;
	while (x > curr)
		curr *= base;
	return curr;
}

void
set_grid(vector<vector<bool>>& grid, int& row, int& col) {
	int n = get_lowest_power_num(max(row, col), 2);
	
	grid = vector<vector<bool>>(n, vector<bool>(n, false));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int x;
			cin >> x;
			grid[i][j] = (x == 1);
		}
	}
}

enum { NONE = -1, ZERO, ONE };

int
get_group(
	vector<vector<bool>>& grid,
	int x,
	int y,
	int k
) {
	bool flag = grid[x][y];
	
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			if (grid[x + i][y + j] != flag)
				return NONE;
	
	return flag ? ONE : ZERO;
}

bool
is_power_number(int num, int power) {
	if (num == 0)
		return false;
	
	double x = log(num) / log(power);
	return ceil(x) == floor(x);
}

void
generate_ans(
	vector<string>& ans,
	vector<vector<bool>>& grid,
	int& row,
	int& col
) {
	int n = (int)grid.size();
	
	function<void(string,int,int,int)>
	_dfs = [&](string code, int x, int y, int k) -> void {
		int group = get_group(grid, x, y, k);
		
		if (group != NONE) {
			if (group == ONE) {
				code = '1' + code;
				ans.push_back(code);
			}
			return;
		}
		
		_dfs(code + "0", x, y, (k >> 1));
		_dfs(code + "1", x, y + (k >> 1), (k >> 1));
		_dfs(code + "2", x + (k >> 1), y, (k >> 1));
		_dfs(code + "3", x + (k >> 1), y + (k >> 1), (k >> 1));
	};
	
	_dfs("", 0, 0, n);
}

void
show_ans(vector<string>& ans) {
	cout << (int)ans.size() << endl;
	for (string& s: ans)
		cout << s << endl;
}

int
main() {
	int row, col;
	cin >> row >> col;
	
	vector<vector<bool>> grid;
	set_grid(grid, row, col);
	
	vector<string> ans;
	generate_ans(ans, grid, row, col);
	
	show_ans(ans);
	
	return 0;
}

