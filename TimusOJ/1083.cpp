#include <cstdio>

int
count_marks() {
	int count = 0;
	while (getchar() == '!')
		count++;
	return count;
}

int
main() {
	int n;
	scanf("%d%*c", &n);
	
	int ans = 1;
	int temp = n;
	int k = count_marks();
	
	while (temp > 0) {
		ans *= temp;
		temp -= k;
	}
	
	printf("%d\n", ans);
	
	return 0;
}

