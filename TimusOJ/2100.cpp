#include <iostream>
#include <string>
using namespace std;

bool is_substring(string &s, string sub_str) {
	return s.find(sub_str) != -1;
}

int main()
{
	int n, count = 2;
	string s;
	
	cin >> n;
	count += n;
	
	for(int i = 0; i < n; i++) {
		cin >> s;
		if (is_substring(s, "+one"))
			count++;
	}
	if (count == 13)
		count++;
	
	cout << count * 100 << endl;
	
	return 0;
}
