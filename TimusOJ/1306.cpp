#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int
main() {
	int n;
	scanf("%d", &n);
	
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	
	if (n & 1 == 1) {
		printf("%d\n", arr[n >> 1]);
	} else {
		int mid = (n >> 1);
		int l_val = (arr[mid] >> 1);
		int l_rem = arr[mid] & 1;
		int 
	}
	
	return 0;
}

