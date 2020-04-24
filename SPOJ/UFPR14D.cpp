#include <cstdio>
#define gc(x) getchar_unlocked(x)
using namespace std;
int readint () {
	int c=gc(), x=0;
	for (;c<48||c>57; c=gc());
	for (;c>47&&c<58; c=gc())
		x = (x<<1)+(x<<3)+c-48;
	return x;
}
int dp[100005];
int main()
{
	int n, que, a, b;
	n = readint();
	for (int i=1; i<=n; i++)
		dp[i] = dp[i-1] + readint();
	que = readint();
	while (que--) {
		a = readint(); b = readint();
		printf ("%d\n", dp[b]-dp[a-1]);
	}
	return 0;
}
