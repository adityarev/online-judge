#include <cstdio>
#include <algorithm>
#define sc(x) scanf("%d",&(x))
#define FOR(i,a,b) for(i=a;i<=b;i++)
using namespace std;
int arr[1005][1005];
int main()
{
	int tc,n,i,j,x,res;
	sc(tc);
	while (tc--) {
		sc(n);
		FOR(i,0,n) arr[0][i] = arr[i][0] = 0;
		FOR(i,1,n) FOR(j,1,i) sc(x), arr[i][j]=x+max(arr[i-1][j],arr[i-1][j-1]);
		res = 0; FOR(i,1,n) res = max(res,arr[n][i]);
		printf("%d\n",res);
	}
	return 0;
}
