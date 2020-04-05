#include <cstdio>
#include <iostream>
typedef long long LL;
using namespace std;

char tail[9][15] = {
	"00000000000", "11111111111", "22222222222",
	"33333333333", "44444444444", "55555555555",
	"66666666666", "77777777777", "88888888888"
};

int main()
{
	long long a, b;
	cin >> a >> b;
	
	long long mod = ((a%9)*(b%9))%9;
	printf ("%lld.%s\n", a*b/9, tail[mod]);
	
	return 0;
}

