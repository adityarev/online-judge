#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n;
		cin >> n;
		
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			long long int x;
			cin >> x;
			
			sum += x;
			sum %= (long long)n;
		}
		
		if (sum == 0LL)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
	return 0;
}

