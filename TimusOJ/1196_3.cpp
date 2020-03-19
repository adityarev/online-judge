#include <cstdio>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)

int
getint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

void
printint(int val) {
	if (val == 0LL)
		return;
	printint(val / 10);
	pc('0' + (val % 10));
}

void
set_arr(std::vector<int> &arr) {
	int n = getint();
	
	for (int i = 0; i < n; i++) {
		int x = getint();
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
	std::vector<int> arr;
	set_arr(arr);
	
	int ans = 0;
	int n = getint();
	
	for (int i = 0; i < n; i++) {
		int val = getint();
		
		if (found(arr, val))
			ans++;
	}
	
	show_ans(ans);
	
	return 0;
}

