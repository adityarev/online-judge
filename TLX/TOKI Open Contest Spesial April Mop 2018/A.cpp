#include <iostream>

int
main() {
	int n;
	scanf("%d", &n);
	
	int left;
	int right;

	if (n % 2 == 1) {
		if (n == 1)
			left = 0;
		else if (n % 3 == 0)
			left = n / 3;
		else if (n % 5 == 0)
			left = n / 5;
		else if (n % 7 == 0)
			left = n / 7;
		else
			left = 1;
		right = n - left;
	} else {
		left = right = (n >> 1);
	}
	
	printf("%d %d\n", left, right);
	
	return 0;
}
