#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

typedef long long LL;

using namespace std;

struct Building {
	LL height;
	LL cost;
};

class App {
private:
	int tc;
	int N;
	vector<struct Building> buildings;

protected:
	void init() {
		buildings.clear();
	}
	
	void runInput() {
		init();
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++) {
			buildings.push_back(*(new (struct Building)));
			scanf("%lld", &buildings[i].height);
		}
		
		for (int i = 0; i < N; i++) {
			scanf("%lld", &buildings[i].cost);
		}
	}
	
	LL getCost(LL mid) {
		LL cost = 0LL;
		for (int i = 0; i < N; i++) {
			cost += (LL)abs(buildings[i].height - mid) * buildings[i].cost;
		}
		
		return cost;
	}
	
	LL getMinimumCost() {
		int low = 0;
		int high = buildings.size() - 1;
		
		int lookup_point = 0;
		while (low != high) {
			int mid = (low + high) / 2;
			LL cost1 = getCost(low);
			LL cost2 = getCost(high);
			
			static int iter = 0;
			cout << "Iter " << iter++ << ": " << low << ", " << high << endl;
			system("pause");
			
			if (cost1 < cost2) {
				high = mid - ((low + high) % 2);
				lookup_point = high;
			} else {
				low = mid + ((low + high) % 2);
				lookup_point = low;
			}
		}
		
		return getCost(lookup_point);
	}
	
public:
	App() {	}
	
	void run() {
		scanf("%d", &tc);
		while (tc--) {
			runInput();
			
			LL ans = getMinimumCost();
			printf("%lld\n", ans);
		}
	}
};

int main()
{
	App app;
	app.run();
	
	return 0;
}
