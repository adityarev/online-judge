#include <iostream>

template<typename T> T
gcd(T a, T b) {
	if (a == 0)
		return b;
	return gcd(b % a, a);
}

int
main() {
	// Your code goes here
	
	return 0;
}

