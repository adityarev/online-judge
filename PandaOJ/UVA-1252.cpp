#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string.h>
#define gc(x) getchar_unlocked(x)

typedef long long LL;
using namespace std;

int scanint() {
	int c = gc(), x = 0;
	if (c==EOF) x=-1;
	for (;c<48||c>57; c=gc());
	for (;c>47&&c<58; c=gc()) x = (x<<1)+(x<<3)+c-48;
}

bool prime[100000005];
vector<int> dp;
void initPrime()
{
	int lim = 100000000/2+2;
	prime[0] = prime[1] = 1;
	for (int i=2; i<lim; i++) {
		if (!prime[i]) {
			dp.push_back(i);
			for (int j=i+i; j<100000001; j+=i)
				prime[j] = 1;
		}
	}
}

int main()
{
	initPrime();
	
	int n, sz = dp.size();
	while ((n=scanint()) != EOF)
	{
		int p = 0, rem = n-dp[p];
		bool found = 0;
		
		while (p<sz && rem >= n>>1) {
			if (!prime[rem]) {
				found = 1;
				printf("%d is the sum of %d and %d.\n", n, dp[p], rem);
				break;
			}
			p++;
		}
		if (!found) printf ("%d is not the sum of two primes!\n", n);
	}
	
	return 0;
}
