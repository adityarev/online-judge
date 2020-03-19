#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

string get_ans(vector<string> &numbers, int &n) {
	sort(numbers.begin(), numbers.end());
	
	for (int i = 1; i < n; i++) {
		if (numbers[i].find(numbers[i - 1]) == 0)
			return "NO";
	}
	
	return "YES";
}

int main()
{
	int tc;
	cin >> tc;
	
	while (tc--) {
		int n;
		cin >> n;
		
		vector<string> numbers(n);
		for (int i = 0; i < n; i++)
			cin >> numbers[i];
		
		cout << get_ans(numbers, n) << endl;
	}
	
	return 0;
}

