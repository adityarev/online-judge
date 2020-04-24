#include <cstdio>
#include <algorithm>

typedef long long LL;
using namespace std;

int n;
LL arr[25], lim;

LL solve (int i, LL sum) {
	if (i == n)
		return sum;
	
	if (sum+arr[i] <= lim)
		return max(solve(i+1, sum), solve(i+1, sum+arr[i]));
	else
		return solve(i+1, sum);
}

int main()
{
	int tc;
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%lld", &n, &lim);
		for (int i=0; i<n; i++)
			scanf("%lld", &arr[i]);
		printf("%lld\n", solve(0,0));
	}
	
	return 0;
}
