#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int,int> PII;

void
set_arr(vector<PII>& arr) {
	int i = 0;
	for (PII& x: arr) {
		int val;
		cin >> val;
		
		x.first = val;
		x.second = i++;
	}
}

int
main() {
	int n;
	cin >> n;
	
	vector<PII> arr(n);
	set_arr(arr);
	
	vector<PII> min_arr = arr;
	sort(min_arr.begin(), min_arr.end(), [](const PII& a, const PII& b) {
		return a.first < b.first;
	});
	
	vector<PII> max_arr = arr;
	sort(max_arr.begin(), max_arr.end(), [](const PII& a, const PII& b) {
		return a.first > b.first;
	});
	
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		PII min_val = min_arr[i];
		PII max_val = max_arr[i];
		
		ans[min_val.second] = max_val.first;
	}
	
	for (int i = 0; i < n; i++)
		cout << ans[i] << (i == n - 1 ? "\n" : " ");
	
	return 0;
}

