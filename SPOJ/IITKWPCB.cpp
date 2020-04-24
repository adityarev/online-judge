#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	long long tc, x;
	cin >> tc;
	while (tc--) {
		cin >> x;
		if (x < 3) {
			printf("%lld\n", x-1);
		} else {
			if ((x-1)%4 > 1)
				printf ("%lld\n", ((x+1)>>1)-1);
			else
				printf ("%lld\n", (x>>1) - (x&1 ? 0 : 2));
		}
	}
	return 0;
}
