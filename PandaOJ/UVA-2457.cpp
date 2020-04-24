#include <cstdio>
using namespace std;
int scanint() {
	int c = getchar(), x = 0;
	for (;c<48||c>57; c=getchar());
	for (;c>47&&c<58; c=getchar()) x = (x<<1)+(x<<3)+c-48;
	return x;
}
int main()
{
	int n, arr[105], ct;
	while (n=scanint()) {
		for(int i=1; i<101; i++) arr[i] = 0;
		for(int i=0; i<n; i++)
			arr[scanint()]++;
		ct = 0;
		for(int i=1; i<101; i++)
			for (int j=0; j<arr[i]; j++)
				printf("%d%c", i, ++ct==n ? '\n' : ' ');
	}
	return 0;
}
