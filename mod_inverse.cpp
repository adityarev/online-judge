#include <iostream>

typedef long long LL;

template<typename T> T
gcd(T a, T b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

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

template<typename T> T
mod_inverse(T num, T mod) {
	// Inverse doesn't exist
	if (gcd(num, mod) != 1)
		return -1;
	
	// Fermat's little theorem
	// a^(m - 1) == 1 (mod m), then
	// a^(-1) == a^(m - 1) (mod m)
	return modexp(num, mod - 2, mod);
}

int
main() {
	// Your code goes here
	
	return 0;
}

