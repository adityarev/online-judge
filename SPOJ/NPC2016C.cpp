#include <bits/stdc++.h>

typedef long long LL;

using namespace std;

LL get_next_val(const LL &temp, const LL &x) {
	static vector<LL> values = {
		1LL, 11LL, 111LL, 1111LL, 11111LL, 111111LL,
		1111111LL, 11111111LL, 111111111LL, 1111111111LL,
		11111111111LL, 111111111111LL, 1111111111111LL
	};
	
	LL min_diff = LLONG_MAX;
	LL next_val;
	
	for (LL val : values) {
		int plus_val = temp + val;
		int minus_val = temp - val;
		int diff = min((LL)abs(x - plus_val), (LL)abs(x - minus_val));
		
		if (diff < min_diff) {
			next_val = val;
			min_diff = diff;
		}
	}
	
	return next_val;
}

pair<int,LL> get_next_temp(const LL &temp, const LL &x, const LL &val, char sign) {
	LL diff = (LL)abs(temp - x);
	LL multiplier = diff / val;
	
	if (multiplier == 0LL)
		multiplier = 1LL;
	
	LL adder = multiplier * val;
	
	return {(int)multiplier, (sign == '+' ? (temp + adder) : (temp - adder))};
}

int main()
{
	int tc;
	cin >> tc;
	
	while (tc--) {
		LL x;
		cin >> x;
		
		LL temp = 0LL;
		int counter = 0;
		
		while (temp != x) {
			LL val = get_next_val(temp, x);
			LL plus_diff = (LL)abs(x - (temp + val));
			LL minus_diff = (LL)abs(x - (temp - val));
			
			pair<int,LL> next_step = (plus_diff <= minus_diff ?
				get_next_temp(temp, x, val, '+')
				: get_next_temp(temp, x, val, '-')
			);
			int next_counter = next_step.first;
			LL next_temp = next_step.second;
			
			counter += next_counter;
			temp = next_temp;
		}
		
		cout << (counter - 1) << endl;
	}
	
	return 0;
}

