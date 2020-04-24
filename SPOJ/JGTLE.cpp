#include <cstdio>
typedef long long LL;
using namespace std;

LL sumN (LL x)
{
	return x*(x+1)/2;
}

int main()
{
	int tc, cid = 1;
	LL a, b, c;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%lld%lld%lld", &a, &b, &c);
		printf ("Case %d: %lld\n", cid++, a*sumN(b)*sumN(c));
	}
	return 0;
}
