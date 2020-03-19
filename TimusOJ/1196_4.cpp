#include <cstdio>
#include <iostream>
#include <vector>

#define pc(x) putchar(x)

void
printint(int val) {
	if (val == 0LL)
		return;
	printint(val / 10);
	pc('0' + (val % 10));
}

void
set_arr(std::vector<int> &arr) {
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		arr.push_back(x);
	}
}

bool
found(std::vector<int> &arr, int &val) {
	int l = 0;
	int r = arr.size() - 1;
	
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (arr[mid] < val)
			l = mid + 1;
		else if (arr[mid] > val)
			r = mid - 1;
		else
			return true;
	}
	
	return false;
}

void
show_ans(int &ans) {
	if (ans == 0) {
		puts("0");
	} else {
		printint(ans); pc('\n');
	}
}

int
main() {
	std::ios_base::sync_with_stdio(false); 
    std::cin.tie(NULL);
	
	std::vector<int> arr;
	set_arr(arr);
	
	int n;
	std::cin >> n;
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val;
		std::cin >> val;
		
		if (found(arr, val))
			ans++;
	}
	
	show_ans(ans);
	
	return 0;
}

