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
#include <set>
#include <string>
#include <vector>

using namespace std;

bool
is_possible(
	vector<int>& arr1,
	vector<int>& arr2,
	int minus_counter,
	int plus_counter
) {
	if (arr1[0] != arr2[0])
		return false;
	
	for (int i = (int)arr1.size() - 1; i > 0; i--) {
		if (arr1[i] < 0)
			minus_counter--;
		if (arr1[i] > 0)
			plus_counter--;
		
		if (arr1[i] == arr2[i])
			continue;
		else if (arr2[i] > arr1[i]) {
			if (plus_counter <= 0)
				return false;
		} else {
			if (minus_counter <= 0)
				return false;
		}
	}
	
	return true;
}

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n;
		cin >> n;
		
		int minus_counter = 0;
		int plus_counter = 0;
		vector<int> arr1(n);
		
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			
			arr1[i] = x;
			
			if (x < 0)
				minus_counter++;
			if (x > 0)
				plus_counter++;
		}
		
		vector<int> arr2(n);
		for (int i = 0; i < n; i++)
			cin >> arr2[i];
		
		bool possible = is_possible(arr1, arr2, minus_counter, plus_counter);
		
		if (possible)
			puts("YES");
		else
			puts("NO");
	}
	
	return 0;
}

