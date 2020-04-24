#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	map<string,int> accounts;
	int tc, n;
	char x;
	
	scanf("%d%*c", &tc);
	while (tc--)
	{
		accounts.clear();
		scanf ("%d%*c", &n);
		
		while (n--) {
			string s = "";
			while ((x=getchar())!='\n') s += x;
			accounts[s]++;
		}
		
		for (map<string,int>::iterator it=accounts.begin(); it!=accounts.end(); it++)
			cout << it->first << " " << it->second << endl;
		
		if (tc) cout << endl;
	}
	
	return 0;
}
