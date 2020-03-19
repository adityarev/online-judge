#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define gc(x) getchar(x)
#define pc(x) putchar(x)

typedef long long LL;

int
getint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

void
printll(LL val) {
	if (val == 0LL)
		return;
	printll(val / 10);
	pc('0' + (val % 10));
}

#define MAX 10000002

int spf[MAX] = {0, 0};
LL dp[MAX] = {0LL, 0LL};

void
init_global() {
	// Init Smallest Factor
	for (int i = 2; i < MAX; i++) {
		if (spf[i] == 0) {
			for (int j = i; j < MAX; j += i)
				spf[j] = i;
		}
	}
	
	// Init DP
	for (int i = 2; i < MAX; i++)
		dp[i] = dp[i - 1] + (LL)spf[i];
}

int
main() {
	init_global();
	
	int tc = getint();
	
	while (tc--) {
		int n = getint();
		printll(dp[n]), pc('\n');
	}
	
	return 0;
}

