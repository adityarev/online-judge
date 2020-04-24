#include <cstdio>
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	map<int,int> ascii;
	priority_queue<pair<int,int> > out;
	
	bool fir = 1;
	while(cin >> s)
	{
		if (fir) fir = 0;
		else cout << endl;
		
		ascii.clear();
		for (int i=0; i<s.length(); i++) ascii[(int)s[i]]++;
		for (map<int,int>::iterator it=ascii.begin(); it!=ascii.end(); it++)
			out.push(make_pair(-(it->second), (it->first)));
		
		pair<int,int> curr;
		while (!out.empty()) {
			curr = out.top();
			out.pop();
			cout << curr.second << " " << -curr.first << endl;
		}
	}
	
	return 0;
}
