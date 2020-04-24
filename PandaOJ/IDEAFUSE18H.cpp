#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int tc;
	cin >> tc;
	
	int cases = 1;
	while (tc--) {
		int n;
		cin >> n;
		
		int original_sum = 0;
		int min_val = INT_MAX;
		
		for (int i = 0; i < 10; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			
			int val = a + b + c;
			min_val = min(min_val, val);
			
			original_sum += val;
		}
		
		int max_val = INT_MIN;
		for (int i = 0; i < n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			
			int val = a + b + c;
			max_val = max(max_val, val);
		}
		
		int subtitute_sum = original_sum - min_val + max_val;
		
		cout << "Case #" << (cases++) << ": " << max(original_sum, subtitute_sum) << endl;
	}
	
	return 0;
}
