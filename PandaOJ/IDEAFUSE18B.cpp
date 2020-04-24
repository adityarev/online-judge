#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>

#define MAX 500002

using namespace std;

vector<int> primes;
string s;
int lookup[256];

void initPrimes() {
	bool is_prime[MAX];
	memset(is_prime, true, sizeof(is_prime));
	
	is_prime[0] = is_prime[1] = false;
	primes.clear();
	
	for (int i = 2; i < MAX; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			
			for (int j = i + i; j < MAX; j += i) {
				is_prime[i] = false;
			}
		}
	}
}

void initLookup(int n) {
	memset(lookup, 0, sizeof(lookup));
	
	for (int i = 0; i < n; i++) {
		lookup[(int)s[i]]++;
	}
}

bool blockCanMade(int n) {
	initLookup(n);
	
	int len = s.length();
	for (int i = n; i < len; i += n) {
		int arr[256];
		memset(arr, 0, sizeof(arr));
		
		int lim = i + n;
		for (int j = i; j < lim; j++) {
			arr[(int)s[j]]++;
		}
		
		for (int j = 'A'; j <= 'Z'; j++) {
			if (arr[j] != lookup[j]) {
				return false;
			}
		}
	}
	
	return true;
}

vector<int> getDivisor(int n) {
	vector<int> divisor;
	divisor.clear();
	
	divisor.push_back(1);
	for (int i = 0; i < primes.size(); i++) {
		if (primes[i] >= n) {
			break;
		}
		
		if (n % primes[i] == 0) {
			divisor.push_back(primes[i]);
		}
	}
	
	return divisor;
}

int getMaxBlock(int n) {
	vector<int> divisor = getDivisor(n);
	
	for (int i = 0; i < divisor.size(); i++) {
		if (blockCanMade(divisor[i])) {
			return (n / divisor[i]);
		}
	}
	
	return 1;
}

int main()
{
	initPrimes();
	
	int tc;
	cin >> tc;
	
	int cases = 1;
	while (tc--) {
		int n;
		cin >> n;
		cin >> s;
		
		int ans = getMaxBlock(n);
		cout << "Case #" << (cases++) << ": " << ans << endl;
	}
	
	return 0;
}
