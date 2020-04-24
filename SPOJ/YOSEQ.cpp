#include <iostream>
#include <list>
#include <string>

using namespace std;

string toString(int x) {
	list<int> digits;
	while (x) {
		digits.push_front(x%10);
		x /= 10;
	}
	
	string str = "";
	while (!digits.empty()) {
		str += '0' + digits.front();
		digits.pop_front();
	}
	
	return str;
}

int main()
{
	string s;
	cin >> s;
	
	for (int i=0; ; i++) {
		if (s.find(toString(i)) == -1) {
			cout << i << endl;
			break;
		}
	}
	
	return 0;
}
