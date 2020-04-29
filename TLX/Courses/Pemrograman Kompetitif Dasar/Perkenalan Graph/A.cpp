#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

struct Node {
	Point point;
	int dist;
};

enum { WALL = -1, ROOM = 0 };

bool
is_in_range(int val, int start, int end) {
	return (start <= val && val <= end);
}

void
set_maze(vector<vector<int>>& maze) {
	for (vector<int>& line: maze)
		for (int& x: line)
			cin >> x;
}

int
get_ans(vector<vector<int>>& maze, Point& start) {
	int row = (int)maze.size();
	int col = (int)maze[0].size();
	
	list<Node> bfs;
	vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	vector<vector<bool>> visited(row, vector<bool>(col, false));
	
	function<void(Node)>
	_push_node = [&](Node node) -> void {
		bfs.push_back(node);
		visited[node.point.x][node.point.y] = true;
	};
	
	_push_node({start, 1});
	
	while (!bfs.empty()) {
		Node node = bfs.front();
		bfs.pop_front();
		
		Point point = node.point;
		int dist = node.dist;
		
		for (vector<int>& move: moves) {
			int x = point.x + move[0];
			int y = point.y + move[1];
			
			if (!is_in_range(x, 0, row - 1) || !is_in_range(y, 0, col - 1))
				return dist;
			if (!visited[x][y] && maze[x][y] != WALL)
				_push_node({{x, y}, dist + 1});
		}
	}
	
	return -1;
}

int
main() {
	int row, col;
	cin >> row >> col;
	
	vector<vector<int>> maze(row, vector<int>(col));
	set_maze(maze);
	
	int x, y;
	cin >> x >> y;
	
	Point start = {x - 1, y - 1};
	int ans = get_ans(maze, start);
	
	cout << ans << endl;
	
	return 0;
}

