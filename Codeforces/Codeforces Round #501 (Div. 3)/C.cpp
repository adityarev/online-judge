#include <algorithm>
#include <iostream>
#include <vector>

typedef long long LL;

using namespace std;

int
main() {
	int n;
	cin >> n;
	
	LL capacity;
	cin >> capacity;
	
	LL sum = 0LL;
	vector<LL> diffs;
	
	for (int i = 0; i < n; i++) {
		LL ori, comp;
		cin >> ori >> comp;
		
		sum += ori;
		diffs.push_back(ori - comp);
	}
	
	int counter = 0;
	
	sort(diffs.begin(), diffs.end(), greater<LL>());
	for (LL& diff: diffs) {
		if (sum <= capacity)
			break;
		
		sum -= diff;
		counter++;
	}
	
	if (sum <= capacity)
		cout << counter << endl;
	else
		cout << -1 << endl;
	
	return 0;
}

