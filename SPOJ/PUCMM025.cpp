#include <cstdio>
#define gc(x) getchar_unlocked(x)
using namespace std;
int main()
{
	int arr[255], ct, sum;
	char x;
	while ((x=gc())!=EOF)
	{
		arr[0] = (int)x-48;
		sum = arr[0]; ct = 1;
		while ((x=gc())!='\n')
			arr[ct] = (int)x-48,
			sum += arr[ct], ct++;
		int ans = 0;
		for (int i=0; i<ct; i++) {
			if (arr[i]==0) continue;
			if (sum%arr[i]==0) ans++;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
