#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

vector<int> prime;
void sieve (int limit)
{
	bool mark[limit+1];
	memset(mark, 1, sizeof(mark));
	
	for (int i=2; i*i<limit; i++) {
		if (mark[i]) {
			for (int j=i+i; j<limit; j+=i)
				mark[j] = 0;
		}
	}
}

void segmentedSieve(int n)
{
	int limit = (int)sqrt(n) + 1;
	sieve(n);
	
	int low = limit, high = 2*limit;
	while (low<n)
	{
		high = min(high, n);
		
		bool mark[limit+1];
		memset(mark, 1, sizeof(mark));
		
		int p_size = prime.size();
		for (int i=0; i<p_size; i++) {
			int loLim = low/prime[i] * prime[i];
			if (loLim < low)
				loLim += prime[i];
			
			for (int j=loLim; j<high; j+=prime[i])
				mark[j-low] = 0;
		}
		
		for (int i=low; i<high; i++)
			if (mark[i - low] == 1)
				prime.push_back(i);
		
		low += limit;
		high += limit;
	}
}

int main()
{
	const int SIZE = 100000002;
	segmentedSieve(SIZE);
	
	int n, sz = prime.size();
	while (scanf("%d", &n)!=EOF)
	{
		int p = 0, rem = n-prime[p];
		bool found = 0;
		
		while (p<sz && rem >= n>>1) {
			if (binary_search (prime.begin(), prime.end(), rem)) {
				found = 1;
				printf("%d is the sum of %d and %d.\n", n, prime[p], rem);
				break;
			}
			p++;
		}
		if (!found) printf ("%d is not the sum of two primes!\n", n);
	}
	
	return 0;
}
