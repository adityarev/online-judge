#include <iostream>
typedef unsigned long long ULL;
using namespace std;

ULL gcd ( ULL a, ULL b )
{
  if ( a==0 ) return b;
  return gcd ( b%a, a );
}

int main()
{
	ULL a, b, c;
	cin >> a >> b >> c;
	cout << gcd(a, gcd(b,c)) << endl;
	return 0;
}
