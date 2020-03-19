#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	
	vector<int> ids[101];
	
	for (int i = 0; i < n; i++) {
		int id, m;
		cin >> id >> m;
		
		ids[m].push_back(id);
	}
	
	for (int i = 100; i >= 0; i--)
		for (int id : ids[i])
			cout << id << " " << i << endl;
	
	return 0;
}

