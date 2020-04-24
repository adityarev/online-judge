#include <iostream>
#define MOD 1000000007

typedef long long LL;
using namespace std;

LL dp[50005];
int main()
{
	dp[0] = dp[1] = 1;
	for (int i=2; i<50001; i++)
		dp[i] = (dp[i-1]<<1) % MOD;
		
	int tc, x;
	cin >> tc;
	while (tc--)
		cin >> x,
		cout << dp[x] << endl;
	
	return 0;
}
