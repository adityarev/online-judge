#include <algorithm>
#include <iostream>

typedef long long LL;

LL
get_ans(LL a, LL b) {
	if (a % 11LL == 0LL)
		a /= 11LL;
	else
		b /= 11LL;
	
	return a * b;
}

int
main() {
	LL a, b;
	std::cin >> a >> b;
	
	LL ans = get_ans(a, b);
	std::cout << ans << std::endl;
	
	return 0;
}

