#include <cstdio>
#include <algorithm>
using namespace std;

int getAns (int n)
{
	for (int i=2; i*i<=n; i++) {
		if (i*i==n) return 2;
		else {
			int ct = 0;
			while (!(n%i)) ct++, n/=i;
			if (n==1) return ct;
		}
	}
	return 1;
}

int main()
{
	int n;
	while (scanf("%d",&n) && n)
		printf ("%d\n", getAns(n));	
	return 0;
}
