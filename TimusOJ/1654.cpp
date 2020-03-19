#include <iostream>
#include <vector>

using namespace std;

vector<char> get_ans(string&);
void show_ans(vector<char>&);

int
main() {
	string s;
	cin >> s;
	
	vector<char> ans = get_ans(s);
	show_ans(ans);
	
	return 0;
}


vector<char>
get_ans(string &s) {
	vector<char> ans;
	ans.clear();
	
	for (char c: s) {
		if (ans.size() == 0) {
			ans.push_back(c);
			continue;
		}
		
		if (ans.back() == c) {
			ans.pop_back();
		} else {
			ans.push_back(c);
		}
	}
	
	return ans;
}

void
show_ans(vector<char> &ans) {
	for (char c: ans) {
		cout << c;
	}
	cout << endl;
}

