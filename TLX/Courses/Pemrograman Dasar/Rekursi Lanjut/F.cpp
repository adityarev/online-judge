#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Painter {
	int x;
	int y;
	int k;
};

void
set_codes(vector<string>& codes) {
	for (string& code: codes)
		cin >> code;
}

void
paint_grid(
	vector<vector<bool>>& grid,
	Painter& painter
) {
	for (int i = 0; i < painter.k; i++) {
		for (int j = 0; j < painter.k; j++) {
			int x = painter.x + i;
			int y = painter.y + j;
			grid[x][y] = true;
		}
	}
}

Painter
code_to_painter(string& code, int& n) {
	int x = 0;
	int y = 0;
	int k = n;
	
	for (int i = 1; i < (int)code.length(); i++) {
		int pos = (int)(code[i] - '0');
		
		if (pos > 1)
			x += (k >> 1);
		if (pos % 2 == 1)
			y += (k >> 1);
		k = (k >> 1);
	}
	
	return {x, y, k};
}

int
get_lowest_power_num(int x, int base) {
	int curr = 1;
	while (x > curr)
		curr *= base;
	return curr;
}

void
set_grid(
	vector<vector<bool>>& grid,
	vector<string>& codes
) {
	int row = (int)grid.size();
	int col = (int)grid[0].size();
	int n = get_lowest_power_num(max(row, col), 2);
	
	for (string& code: codes) {
		Painter painter = code_to_painter(code, n);
		paint_grid(grid, painter);
	}
}

void
show_grid(vector<vector<bool>>& grid) {
	for (vector<bool>& arr: grid) {
		bool first = true;
		for (bool flag: arr) {
			if (first)
				first = false;
			else
				cout << " ";
			cout << (flag ? "1" : "0");
		}
		cout << endl;
	}
}

int
main() {
	int n;
	cin >> n;
	
	vector<string> codes(n);
	set_codes(codes);
	
	int row, col;
	cin >> row >> col;
	
	vector<vector<bool>> grid(row, vector<bool>(col, false));
	set_grid(grid, codes);
	
	show_grid(grid);
	
	return 0;
}

