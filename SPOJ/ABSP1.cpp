#include <cstdio>
#include <algorithm>
#include <map>

typedef long long LL;
using namespace std;

int scanint() {
	int c = getchar(), x = 0;
	for (;c<48||c>57; c=getchar());
	for (;c>47&&c<58; c=getchar())
		x = (x<<1)+(x<<3)+c-48;
	return x;
}

LL scanll() {
	LL c = getchar(), x = 0;
	for (;c<48||c>57; c=getchar());
	for (;c>47&&c<58; c=getchar())
		x = (x<<1)+(x<<3)+c-48;
	return x;
}

LL arr[10005] = {0};
int main()
{
	int tc, n, ct;
	LL x;
	
	tc = scanint();
	while (tc--) {
		n = scanint();
		
		for (int i=1; i<=n; i++) {
			x = scanll();
			arr[i] = arr[i-1] + x;
		}
		
		LL ans = 0;
		for (int i=1; i<n; i++)
			ans += (arr[n]-arr[i]) - (arr[i]-arr[i-1]) * (LL)(n-i);
		printf("%lld\n", ans);
	}
	
	return 0;
}
