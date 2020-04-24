#include <cstdio>
#define MOD 100000007
typedef long long LL;
using namespace std;

LL dp[1005];
int main()
{
	dp[0] = 1;
	for (int i=1; i<1001; i++)
		dp[i] = (dp[i-1]<<1)%MOD;
	
	int tc, n, cid=1;
	LL x, sum;
	
	scanf ("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		sum = 0;
		for (int i=0; i<n; i++)
			scanf ("%lld", &x),
			sum += x;
		sum %= MOD;
		printf ("Case %d: %lld\n", cid++, (sum*dp[n-1])%MOD);
	}
	
	return 0;
}
