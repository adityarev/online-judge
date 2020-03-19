#include <cstdio>
#include <iostream>
#include <vector>

#define ENUM_SIZE 4

enum {
	RED,
	WHITE,
	RED_BLUE,
	WHITE_BLUE,
};

typedef long long LL;

void
init_dp(std::vector<LL> dp[]) {
	dp[RED].push_back(1LL);
	dp[WHITE].push_back(1LL);
	dp[RED_BLUE].push_back(0LL);
	dp[WHITE_BLUE].push_back(0LL);
}

void
construct_dp(std::vector<LL> dp[], int &n) {
	init_dp(dp);
	
	for (int i = 1; i < n; i++) {
		LL r = dp[WHITE][i - 1] + dp[WHITE_BLUE][i - 1];
		LL w = dp[RED][i - 1] + dp[RED_BLUE][i - 1];
		LL rb = dp[RED][i - 1];
		LL wb = dp[WHITE][i - 1];
		
		dp[RED].push_back(r);
		dp[WHITE].push_back(w);
		dp[RED_BLUE].push_back(rb);
		dp[WHITE_BLUE].push_back(wb);
	}
}

int
main() {
	int n;
	std::cin >> n;
	
	std::vector<LL> dp[ENUM_SIZE];
	construct_dp(dp, n);
	
	LL ans = dp[RED][n - 1] + dp[WHITE][n - 1];
	std::cout << ans << std::endl;
	
	return 0;
}
