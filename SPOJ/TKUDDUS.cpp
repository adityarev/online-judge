#include <cstdio>
#include <string.h>
#include <algorithm>

#define tail (n-1-i)
using namespace std;

char str[1000005], sub[1000005]; 
int dp[1000005];

bool isSubstring (int p, int n)
{
	int lim = n/2;
	for (int i=0; i<lim; i++) {
		if (str[p+i] != sub[i] || str[p+tail] != sub[tail])
			return 0;
	}
	return 1;
}

void initDP()
{
	memset(dp, 0, sizeof(dp));
	int str_len = strlen(str), sub_len = strlen(sub);
	
	for (int i=0; i<str_len = i++) {
		
	}
}

int main()
{
	int tc, cid = 1, que, a, b;
	scanf ("%d%*c", &tc);
	
	while (tc--)
	{
		scanf ("%s%*c", str);
		scanf ("%s%*c", sub);
		initDP();
		
		scanf ("%d", &que);
		printf ("Case %d:\n", cid++);
		while (que--) {
			scanf ("%d%d", &a, &b);
			printf ("%d\n", dp[b+1] - dp[a]);
		}
	}
	
	return 0;
}
