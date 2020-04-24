#include <iostream>
#include <algorithm>

typedef long long LL;
using namespace std;

LL specials[] = {987654312678, 987898765678, 987896545674, 456789234576,
				 987896512307, 987654888999, 999999993425};

bool isSpecial(LL x)
{
	for (int i=0; i<7; i++)
		if (x == specials[i])
			return 1;
	return 0;
}

int main()
{
	int tc;
	LL x;
	
	cin >> tc;
	while (tc--)
	{
		cin >> x;
		if (isSpecial(x)) cout << "Special Number" << endl;
		else cout << "Just a number" << endl;
	}
	
	return 0;
}
