#include <cstdio>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main()
{
	vector<pair<int,int> > ans;
	ans.clear();
	
	int counter = 0;
	int temp = INT_MAX;
	
	int x;
	while (scanf("%d", &x) != EOF) {
		if (x != temp || counter == 255) {
			ans.push_back(make_pair(counter, temp));
			
			temp = x;
			counter = 1;
		} else {
			counter++;
		}
	}
	ans.push_back(make_pair(counter, temp));
	
	printf("%d\n", (ans.size() - 1) * 2);
	for (int i = 1; i < ans.size(); i++) {
		printf("%d %d", ans[i].first, ans[i].second);
		printf("%c", i != ans.size() - 1 ? ' ' : '\n');
	}
	
	return 0;
}

