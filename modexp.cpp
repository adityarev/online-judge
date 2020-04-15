#include <iostream>

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
	// Your code goes here
	
	return 0;
}

