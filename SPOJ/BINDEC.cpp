#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)

LL
getll() {
	LL c = gc(), val = 0;
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

LL
odd_count_till(LL x) {
	return ((x + 1) >> 1);
}

int
main() {
	int tc = (int)getll();
	
	while (tc--) {
		LL a = getll();
		LL b = getll();
		
		LL l = min(a, b);
		LL r = max(a, b);
		LL ans = odd_count_till(r) - odd_count_till(l - 1);
		
		if (ans == 0LL)
			pc('0'), pc('\n');
		else
			printll(ans), pc('\n');
	}
	
	return 0;
}
