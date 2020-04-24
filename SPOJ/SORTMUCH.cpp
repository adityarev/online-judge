#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int tc, n;
	double ans;
	
	scanf ("%d", &tc);
	while (tc--)
	{
		scanf ("%d", &n);
		ans = (log(n)/log(3)) *3.0;
		printf ("%d\n", (int)ans);
	}
	
	return 0;
}
