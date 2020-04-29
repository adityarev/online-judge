#include <iostream>
#include <vector>

using namespace std;

int
main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> arr(k + 2, 0);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		
		arr[l]++;
		arr[r + 1]--;
	}
	
	vector<int> ans;
	int curr = 0;
	
	for (int i = 1; i <= k; i++) {
		curr += arr[i];
		if (curr == 0)
			ans.push_back(i);
	}
	
	int sz = (int)ans.size();
	
	cout << sz << endl;
	for (int i = 0; i < sz; i++)
		cout << ans[i] << (i == sz - 1 ? "\n" : " ");
	
	return 0;
}

