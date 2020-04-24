#include <cstdio>
#include <algorithm>

typedef long long LL;
using namespace std;

LL gcd ( LL a, LL b )
{
  LL c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main()
{
	int tc, cid = 1;
	LL	a, b, c, d,
		num, denum;
	
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if (a==0 && b==0) printf ("Case %d: 0/1\n", cid++);
		else if (c==0 && d==0) printf ("Case %d: 1/1\n", cid++);
		else {
			num = a*(c+1) + b*(d+1);
			denum = (a+b)*(c+d+1);
			
			LL fpb = gcd(num, denum);
			printf ("Case %d: %lld/%lld\n", cid++, num/fpb, denum/fpb);
		}
	}
	
	return 0;
}
