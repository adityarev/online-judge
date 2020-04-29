#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)
#define endline pc('\n')

typedef long long LL;

using namespace std;

struct City {
	int id;
	int path_len;
	int child_count;
};

void
set_cities(
	vector<City>& cities,
	int& n,
	vector<vector<int>>& adj
) {
	int path_len = 0;
	vector<bool> visited(n + 1, false);
	
	function<int(int)>
	_travel = [&](int curr_city) -> int {
		visited[curr_city] = true;
		
		int child_count = 0;
		
		path_len++;
		for (int& city: adj[curr_city]) {
			if (!visited[city])
				child_count += _travel(city);
		}
		path_len--;
		
		int value = path_len - child_count;
		cities.push_back({curr_city, path_len, child_count});
		
		return child_count + 1;
	};
	
	int start_city = 1;
	int boom = _travel(start_city);
}

int
main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	
	vector<vector<int>> adj(n + 1, vector<int>());
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	vector<City> cities;
	set_cities(cities, n, adj);
	
	sort(cities.begin(), cities.end(), [](const City& c1, const City& c2) {
		int value1 = c1.path_len - c1.child_count;
		int value2 = c2.path_len - c2.child_count;
		
		return value1 == value2 ? c1.path_len > c2.path_len : value1 > value2;
	});
	
	LL ans = 0;
	int i = 0;
	
	for (City& city: cities) {
		if (i == k)
			break;
		
		ans += (LL)(city.path_len - city.child_count);
		i++;
	}
	
	cout << ans << endl;
	
	return 0;
}

