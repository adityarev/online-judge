#include <cstdio>
#define gc(x) getchar_unlocked(x)
using namespace std;

int numDiv[1000001];
void initDP()
{
	for (int i=3; i<1000001; i++)
		for (int j=i; j<1000001; j+=i)
			numDiv[j]++;
}

int readint () {
	int c=gc(), x=0;
	for (;c<48||c>57; c=gc());
	for (;c>47&&c<58; c=gc())
		x = (x<<1)+(x<<3)+c-48;
	return x;
}

int gcd ( int a, int b )
{
  int c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main()
{
	initDP();
	int tc = readint(), tmp, ans;
	while (tc--)
	{
		tmp = gcd(readint(), readint());
		ans = numDiv[tmp] + 1;
		if (!(tmp&1)) ans++;
		printf ("%d\n", ans);
	}
	return 0;
}
