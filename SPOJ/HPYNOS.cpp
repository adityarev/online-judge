#include <iostream>
#include <map>
using namespace std;

map<int, bool> taken;
int main()
{
	int n;
	cin >> n;
	
	int ct = 0;
	while (n != 1) {
		taken[n] = 1;
		
		int tmp = 0;
		while (n) {
			tmp += (n%10)*(n%10);
			n /= 10;
		}
		ct++;
		n = tmp;
		
		if (taken[n]) {
			cout << -1 << endl;
			break;
		}
	}
	if (!taken[n]) cout << ct << endl;
	
	return 0;
}
