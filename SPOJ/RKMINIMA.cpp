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

int
main() {
	int tc = (int)getll();
	
	while (tc--) {
		LL m = getll();
		
		if (m == 0LL)
			puts("Tora is fearless");
		else if (m == 1LL)
			puts("Ushio is sad");
		else
			pc('-'), printll((m + 1LL) >> 1), pc('\n');
	}
	
	return 0;
}

