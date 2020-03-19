#include <algorithm>
#include <iostream>

using namespace std;

int
main() {
	int k, n;
	cin >> k >> n;
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		
		ans += x;
		ans = max(0, ans - k);
	}
	
	cout << ans << endl;
	
	return 0;
}

