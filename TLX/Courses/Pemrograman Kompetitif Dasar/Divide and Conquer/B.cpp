#include <iostream>
#include <queue>

typedef long long LL;

template<typename T> std::pair<T,bool>
modexp(T num, T power, T mod) {
	T res = 1;
	bool overflow = false;
	
	while (power > 0) {
		if (num >= mod) {
			overflow = true;
			num %= mod;
		}
		if (power & 1)
			res = (res * num);
		
		power = power >> 1;
		num = (num * num);
		
		if (res >= mod) {
			overflow = true;
			res %= mod;
		}
	}
	
	return {res, overflow};
}

std::string
get_last_six_digit(LL num) {
	std::string str = "000000";
	
	for (int i = 5; i >= 0 && num != 0LL; i--) {
		str[i] = (char)('0' + num % 10);
		num /= 10;
	}
	
	return str;
}

int
main() {
	LL a, b;
	std::cin >> a >> b;
	
	std::pair<LL,bool> ans = modexp<LL>(a, b, 1e6);
	
	LL res = ans.first;
	bool overflow = ans.second;
	
	if (overflow)
		std::cout << get_last_six_digit(res) << std::endl;
	else
		std::cout << res << std::endl;
	
	return 0;
}
