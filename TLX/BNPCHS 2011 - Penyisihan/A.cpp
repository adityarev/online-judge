#include <cstdio>

int
pow3(int n) {
	return n * n * n;
}

int
main() {
	int tc;
	scanf("%d", &tc);
	
	for (int i = 0; i < tc; i++) {
		int n;
		scanf("%d", &n);
		
		int ans = pow3(n) - pow3(n - 2);
		printf("%d\n", ans);
	}
	
	return 0;
}

