#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int
main() {
	const int LEN = 3;
	int arr[LEN];
	for (int i = 0; i < LEN; i++)
		cin >> arr[i];
	
	int ans = INT_MAX;
	
	ans = min(ans, arr[0] + arr[1] + arr[2]);
	ans = min(ans, arr[0] + arr[1] - arr[2]);
	ans = min(ans, arr[0] + arr[1] * arr[2]);
	ans = min(ans, arr[0] - arr[1] + arr[2]);
	ans = min(ans, arr[0] - arr[1] - arr[2]);
	ans = min(ans, arr[0] - arr[1] * arr[2]);
	ans = min(ans, arr[0] * arr[1] + arr[2]);
	ans = min(ans, arr[0] * arr[1] - arr[2]);
	ans = min(ans, arr[0] * arr[1] * arr[2]);
	
	cout << ans << endl;
	
	return 0;
}

