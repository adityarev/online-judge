#include <cstdio>
#include <algorithm>
#define gc(x) getchar_unlocked(x)
typedef long long LL;
using namespace std;
LL arr[300005], dp[300005];
LL scanll() {
	LL c = gc(), x = 0;
	for (;c<48||c>57; c=gc());
	for (;c>47&&c<58; c=gc()) x = (x<<1)+(x<<3)+c-48;
	return x;
}
int main()
{
	int n;
	scanf ("%d", &n);
	for (int i=0; i<n; i++) arr[i] = scanll();
	sort(arr, arr+n);
	for (int i=1; i<=n; i++) dp[i] = dp[i-1] + arr[i-1];
	LL ans = dp[n] - n*arr[0];
	for (int i=1; i<n; i++) ans = min(ans, dp[i] + (dp[n]-dp[i] - (LL)(n-i)*arr[i]));
	printf ("%lld\n", ans);
	return 0;
}
