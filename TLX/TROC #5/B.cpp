#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int
main() {
	int a, b, c, m;
	cin >> a >> b >> m;
	
	int counter = 0;
	vector<bool> seen(m, false);
	map<pair<int,int>,bool> taken;
	
	function<void(int)>
	_mark_seen = [&](int x) -> void {
		if (!seen[x]) {
			seen[x] = true;
			counter++;
		}
	};
	
	_mark_seen(a);
	_mark_seen(b);
	
	do {
		pair<int,int> p = std::make_pair(a, b);
		
		if (taken[p])
			break;
		else
			taken[p] = true;
		
		int c = (a + b) % m;
		_mark_seen(c);
		
		a = b;
		b = c;
	} while (true);
	
	cout << counter << endl;
	
	return 0;
}

