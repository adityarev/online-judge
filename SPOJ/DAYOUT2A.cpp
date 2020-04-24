#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	stack<string> sStack;
	string s;
	char x;
	
	while ((x=getchar())!=EOF) {
		s = ""; s += x;
		while ((x=getchar())!='\n') {
			if (x==' ') {
				sStack.push(s);
				s = "";
			}
			else s += x;
		}
		sStack.push(s);
		while (!sStack.empty()) {
			cout << sStack.top();
			sStack.pop();
			if (!sStack.empty()) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	return 0;
}
