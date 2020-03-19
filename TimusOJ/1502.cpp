#include <iostream>

typedef long long LL;

LL
sn(int &a, int &un) {
	int n = (un - a) + 1;
	return ((LL)n * (2LL * (LL)a + ((LL)n - 1LL))) >> 1;
}

LL
get_ans(int &x) {
	LL ans = 0;
	int l = 0;
	int r = x;
	
	while (l <= r) {
		ans += sn(l, r);
		l += 2;
		r++;
	}
	
	return ans;
}

int
main() {
	int x;
	std::cin >> x;
	
	LL ans = get_ans(x);
	std::cout << ans << std::endl;
	
	return 0;
}

