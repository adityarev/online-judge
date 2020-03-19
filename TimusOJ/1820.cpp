#include <iostream>

using namespace std;

int
main() {
	int n, k;
	cin >> n >> k;
	
	if (n < k) {
		cout << 2 << endl;
	} else {
		int count = n * 2;
		int ans = (count / k) + ((count % k) != 0 ? 1 : 0);
		
		cout << ans << endl;
	}
	
	return 0;
}

