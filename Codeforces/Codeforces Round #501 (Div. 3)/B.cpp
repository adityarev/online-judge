#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int
main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	string t;
	cin >> t;
	
	string temp_s = s;
	string temp_t = t;
	
	sort(temp_s.begin(), temp_s.end());
	sort(temp_t.begin(), temp_t.end());
	
	if (temp_s != temp_t) {
		puts("-1");
		return 0;
	}
	
	vector<int> ans;
	
	for (int i = 0; i < n; i++) {
		string find_t = "";
		find_t += t[i];
		
		int ind = i + s.substr(i, n - i).find(find_t);
		
		while (ind > i) {
			ans.push_back(ind);
			swap(s[ind], s[ind - 1]);
			ind--;
		}
	}
	
	int sz = (int)ans.size();
	
	cout << sz << endl;
	for (int i = 0; i < sz; i++)
		cout << ans[i] << (i == sz - 1 ? "\n" : " ");
	
	return 0;
}

