#include <algorithm>
#include <cstdio>

using namespace std;

#define MAX 1005

enum { SA, SB, NONE };

int
main() {
	int n;
	scanf("%d", &n);
	
	int samuels[MAX];
	for (int i = 0; i < n; i++)
		scanf("%d", &samuels[i]);
	
	int sebastians[MAX];
	for (int i = 0; i < n; i++)
		scanf("%d", &sebastians[i]);
	
	int dp[3][MAX];
	dp[SA][0] = dp[SB][0] = dp[NONE][0] = 0;
	
	for (int i = 0, curr = 1; i < n; i++, curr++) {
		dp[SA][curr] = samuels[i] + max(dp[SB][i], dp[NONE][i]);
		dp[SB][curr] = sebastians[i] + max(dp[SA][i], dp[NONE][i]);
		dp[NONE][curr] = max(dp[SA][i], dp[SB][i]);
	}
	
	int ans = max(dp[SA][n], max(dp[SB][n], dp[NONE][n]));
	printf("%d\n", ans);
	
	return 0;
}

