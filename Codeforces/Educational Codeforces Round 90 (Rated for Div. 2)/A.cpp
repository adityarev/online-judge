#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iterator>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)
#define endline pc('\n')

using namespace std;

typedef long long LL;

struct Value {
	int val;
	int index;
};

bool
is_asc(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i - 1] > arr[i])
			return false;
	}
	return true;
}

bool
is_desc(vector<int>& arr) {
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i - 1] < arr[i])
			return false;
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
		
		vector<Value> values;
		vector<int> arr;
		
		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			values.push_back({val, i + 1});
			arr.push_back(val);
		}
		
		if (is_asc(arr) || is_desc(arr)) {
			cout << "NO" << endl;
			continue;
		}
		
		sort(values.begin(), values.end(), [](const Value& a, const Value& b) {
			return a.val > b.val; 
		});
		
		bool found = false;
		
		for (const Value& value: values) {
			if (value.index != 1 && value.index != n) {
				int mid = value.index;
				int l = 1;
				int r = n;
				while (l < mid && arr[l - 1] >= arr[mid - 1])
					l++;
				while (r > mid && arr[r - 1] >= arr[mid - 1])
					r--;
				if (l < mid && mid < r) {
					cout << "YES" << endl;
					cout << l << " " << mid << " " << r << endl;
					found = true;
					break;
				}
			}
		}
		
		if (!found)
			cout << "NO" << endl;
	}
	
	return 0;
}

