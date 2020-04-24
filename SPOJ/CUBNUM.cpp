#include <cstdio>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

int dp[100005];
void initDP()
{
	double x;
	for (int i=1; i<100001; i++) {
		x = pow(i,1./3.);
		if (x==floor(x)) dp[i] = 1;
		else {
			int lim = (int)x, minVal = INT_MAX;
			for (int j=1; j<=lim; j++)
				minVal = min(minVal, 1+dp[i-j*j*j]);
			dp[i] = minVal;
		}
	}
}

int main()
{
	int x, cid=1;
	initDP();
	while (scanf("%d",&x)!=EOF) printf("Case #%d: %d\n", cid++, dp[x]);
	return 0;
}
