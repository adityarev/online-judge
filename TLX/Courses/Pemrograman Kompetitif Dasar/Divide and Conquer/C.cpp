#include <iostream>
#include <climits>

typedef long long LL;

template<typename T> T
modexp(T num, T power, T mod) {
	T res = 1;
	
	num %= mod;
	if (num == 0)
		return 0;
	
	while (power > 0) {
		if (power & 1)
			res = (res * num) % mod;
		power = power >> 1;
		num = (num * num) % mod;
	}
	
	return res;
}

int
main() {
	LL a, b, c, n;
	std::cin >> a >> b >> c >> n;
	
	LL ans = a;
	for (int i = 0; i < (int)c; i++)
		ans = modexp<LL>(ans, b, n);
	
	std::cout << (ans + 1LL) << std::endl;
	
	return 0;
}

