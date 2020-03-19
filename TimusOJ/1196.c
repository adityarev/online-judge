#include <stdbool.h>
#include <stdio.h>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

const MAX_LEN = 15005;

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
set_arr(int arr[], int *n) {
	int i = 0;
	for (i = 0; i < *n; i++)
		arr[i] = getint();
}

bool
found(int arr[], int *len, int *val) {
	int l = 0;
	int r = *len - 1;
	
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (arr[mid] < *val)
			l = mid + 1;
		else if (arr[mid] > *val)
			r = mid - 1;
		else
			return true;
	}
	
	return false;
}

void
show_ans(int ans) {
	if (ans == 0) {
		puts("0");
	} else {
		printint(ans); pc('\n');
	}
}

int
main() {
	int arr[MAX_LEN];
	int n = getint();
	
	set_arr(arr, &n);
	
	int ans = 0;
	int m = getint();
	
	int i = 0;
	for (i = 0; i < m; i++) {
		int val = getint();
		
		if (found(arr, &n, &val))
			ans++;
	}
	
	show_ans(ans);
	
	return 0;
}

