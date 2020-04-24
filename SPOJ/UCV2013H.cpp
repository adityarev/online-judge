#include <cstdio>
#include <map>
#include <queue>
#include <list>
#include <cstring>

using namespace std;

int rows, cols;
bool field[255][255];
map<int,int> slickCount;

int slickSize (int x, int y) {
	int ans = 1;
	field[x][y] = false;
	
	list<pair<int,int> > bfs;
	if (field[x][y-1]) {
		field[x][y-1] = false;
		bfs.push_back(make_pair(x,y-1));
	}
	if (field[x-1][y]) {
		field[x-1][y] = false;
		bfs.push_back(make_pair(x-1,y));
	}
	if (field[x][y+1]) {
		field[x][y+1] = false;
		bfs.push_back(make_pair(x,y+1));
	}
	if (field[x+1][y]) {
		field[x+1][y] = false;
		bfs.push_back(make_pair(x+1,y));
	}
	
	while (!bfs.empty()) {
		pair<int,int> curr = bfs.front();
		bfs.pop_front();
		
		x = curr.first;
		y = curr.second;
		ans++;
		
		if (field[x][y-1]) {
			field[x][y-1] = false;
			bfs.push_back(make_pair(x,y-1));
		}
		if (field[x-1][y]) {
			field[x-1][y] = false;
			bfs.push_back(make_pair(x-1,y));
		}
		if (field[x][y+1]) {
			field[x][y+1] = false;
			bfs.push_back(make_pair(x,y+1));
		}
		if (field[x+1][y]) {
			field[x+1][y] = false;
			bfs.push_back(make_pair(x+1,y));
		}
	}
	
	return ans;
}

int main()
{
	while (scanf("%d%*c%d%*c", &rows, &cols))
	{
		slickCount.clear();
		if (!rows && !cols)
			break;
		
		char x;
		for (int i=1; i<=rows; i++) {
			for (int j=1; j<=cols; j++) {
				x = getchar(); getchar();
				field[i][j] = (x=='1' ? true : false);
			}
		}
		
		int count = 0;
		for (int i=1; i<=rows; i++) {
			for (int j=1; j<=cols; j++) {
				if (field[i][j]) {
					count++;
					slickCount[slickSize(i,j)]++;
				}
			}
		}
		
		printf("%d\n", count);
		for (map<int,int>::iterator it = slickCount.begin(); it != slickCount.end(); it++) {
			printf("%d %d\n", it->first, it->second);
		}
	}
	
	return 0;
}
