#include <cstdio>
#include <cstring>
#include <map>

#define gc(x) getchar_unlocked(x)
#define MAX 1e7

typedef long long LL;

using namespace std;

int scanint() {
	int c = gc(), x = 0;
	
	for (; c<48 || c>57; c = gc());
	for (; c>47 && c<58; c = gc())
		x = (x << 1) + (x << 3) + c - 48;
	
	return x;
}

LL BIT[(int)(MAX + 2)];
map<int,int> counter;

LL getSum(int index) {
	LL sum = 0LL;
	
	index = index + 1;
	while (index > 0) {
		sum += BIT[index];
		index -= index & (-index);
	}
	
	return sum;
}

void updateBIT(int index, LL val) {
	index = index + 1;
	while (index <= MAX) {
		BIT[index] += val;
		index += index & (-index);
	}
}

void runCase() {
	memset(BIT, 0, sizeof(BIT));
	counter.clear();
	
	int n;
	n = scanint();
	
	LL ans = 0LL;
	for (int i = 0; i < n; i++) {
		int x;
		x = scanint();
		
		updateBIT(x, ++counter[x]);
		ans += (getSum(MAX) - getSum(x));
	}
	
	printf("%lld\n", ans);
}

int main()
{
	int tc;
	tc = scanint();
	
	while (tc--) {
		runCase();
	}
	
	return 0;
}
