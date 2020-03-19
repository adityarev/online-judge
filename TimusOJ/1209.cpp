#include <cstdio>
#include <cmath>

typedef long long LL;

using namespace std;

bool isOne(LL x) {
	LL req = 2LL * (x - 1);
	LL n = (LL)sqrt(req);
	
	return (LL)(n * (LL)(n + 1LL)) == req;
}

int main()
{
	int tc;
	scanf("%d", &tc);
	
	bool first_out = true;
	
	while (tc--) {
		LL x;
		scanf("%lld", &x);
		
		first_out ? first_out = false : putchar(' ');
		putchar((isOne(x) ? '1' : '0'));
	}
	putchar('\n');
	
	return 0;
}

