#include <cstdio>
using namespace std;

int arr[10005];
void initCase(int n) {
	for (int i=0; i<=n; i++)
		arr[i] = 0;
}

void createArrVal(int n) {
	int curr = 0;
	for (int i=0; i<n; i++) {
		curr += arr[i];
		arr[i] = curr;
	}
}

int scanint() {
	int c = getchar(), x = 0;
	for (;c<48||c>57; c=getchar());
	for (;c>47&&c<58; c=getchar())
		x = (x<<1)+(x<<3)+c-48;
	return x;
}

int main()
{
	int tc, n, u, que,
		l, r, val, ind;
	
	tc = scanint();
	while (tc--) {
		n = scanint();
		u = scanint();
		
		initCase(n);
		while(u--) {
			l = scanint();
			r = scanint();
			val = scanint();
			arr[l] += val;
			arr[r+1] -= val;
		}
		createArrVal(n);
		
		que = scanint();
		while (que--)
			printf("%d\n", arr[scanint()]);
	}
	
	return 0;
}
