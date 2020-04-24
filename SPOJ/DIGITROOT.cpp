#include <iostream>
#include <string>
#include <vector>

using namespace std;

int modulo(string s, int mod) {
	vector<int> bigInt;
	bigInt.clear();
	
	for (int i = 0; i < s.length(); i++) {
		bigInt.push_back(s[i] - '0');
	}
	
	int res = 0;
	for (int i = 0; i < bigInt.size(); i++) {
		res *= 10;
		res += bigInt[i];
		res %= mod;
	}
	
	return res;
}

int main()
{
	int ans[9][6] = {
		9, 9, 9, 9, 9, 9,
		1, 1, 1, 1, 1, 1,
		1, 2, 4, 8, 7, 5,
		9, 9, 9, 9, 9, 9,
		1, 4, 7, 1, 4, 7,
		1, 5, 7, 8, 4, 2,
		9, 9, 9, 9, 9, 9,
		1, 7, 4, 1, 7, 4,
		1, 8, 1, 8, 1, 8
	};
	
	string a, b;
	cin >> a >> b;
	
	int mod1 = modulo(a, 9);
	int mod2 = modulo(b, 6);
	
//	cout << mod1 << " " << mod2 << endl;
	
	if ((a == "3" || a == "6") && b == "0") {
		cout << a << endl;
	} else {
		cout << ans[mod1][mod2] << endl;
	}
	
	return 0;
}

