#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

const double SQRT2 = std::sqrt(2.0);

void
set_shortcut(
	std::vector<std::vector<bool> > &shortcut,
	int &k
) {
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		shortcut[x][y] = true;
	}
}

void
construct_dp(
	std::vector<std::vector<double> > &dp,
	std::vector<std::vector<bool> > &shortcut
) {
	int r = dp.size();
	int c = dp[0].size();
	
	for (int i = 1; i < c; i++)
		dp[0][i] = dp[0][i - 1] + 1.0;
	for (int i = 1; i < r; i++)
		dp[i][0] = dp[i - 1][0] + 1.0;
	
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			double left = dp[i][j - 1] + 1.0;
			double down = dp[i - 1][j] + 1.0;
			double min_dist = std::min(left, down);
			
			if (shortcut[i][j]) {
				double left_down = dp[i - 1][j - 1] + SQRT2;
				min_dist = std::min(min_dist, left_down);
			}
			
			dp[i][j] = min_dist;
		}
	}
}

int
main() {
	int r, c;
	scanf("%d %d", &r, &c);
	
	int k;
	scanf("%d", &k);
	
	std::vector<std::vector<bool> > shortcut(r + 1, std::vector<bool>(c + 1, false));
	set_shortcut(shortcut, k);
	
	std::vector<std::vector<double> > dp(r + 1, std::vector<double>(c + 1, 0.0));
	construct_dp(dp, shortcut);
	
	int ans = (int)std::round(dp[r][c] * 100.0);
	printf("%d\n", ans);
	
	return 0;
}

