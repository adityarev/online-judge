#include <cstdio>

int
get_ans(int &n, int &k) {
	int l = 1;
	int r = n;
	int ind = k;
	int ans = k;
	
	while (l < r) {
		int mid = (l + r) / 2;
		
		if (ind % 2 == 1) {
			r = mid;
			ind = (ind + 1) / 2;
			ans = (l - 1) + ind;
		} else {
			l = mid + 1;
			ind = ind / 2;
			ans = mid + ind;
		}
	}
	
	return ans;
}

int
main() {
	int tc;
	scanf("%d", &tc);
	
	while (tc--) {
		int n, k;
		scanf("%d%d", &n, &k);
		
		int ans = get_ans(n, k);
		printf("%d\n", ans);
	}
	
	return 0;
}

