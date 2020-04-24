#include <cstdio>
#include <string>
#include <list>
#include <vector>

using namespace std;

vector<int> index[21];
bool digitAtIndex (int num, int ind) {
	int l = 0,
		r = index[num].size() - 1,
		mid;
	
	while (l <= r) {
		mid = (l+r) >> 1;
		if (index[num][mid] == ind)
			return true;
		else if (index[num][mid] < ind)
			l = mid + 1;
		else
			r = mid - 1;
	}
	
	return false;
}

bool exist (int n) {
	list<int> digits;
	while(n) {
		digits.push_front(n%10);
		n /= 10;
	}
	
	int lead = digits.front();
	digits.pop_front();
	
	int lim = index[lead].size();
	for (int i=0; i<lim; i++) {
		bool found = true;
		int	 ind = index[lead][i] + 1;
		
		for (list<int>::iterator it = digits.begin(); it != digits.end(); it++) {
			if (!digitAtIndex(*it, ind)) {
				found = false;
				break;
			} else {
				ind++;
			}
		}
		
		if (found)
			return true;
	}
	
	return false;
}

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
	string s = "";
	char x;
	int ind = 0, ct = 0;
	
	while (s.length() < 100001) {
		s += toString(ct);
		ct++;
	}
	
	for (int i=0; i<s.length(); i++)
		index[s[i]-'0'].push_back(ind++);
	
	puts("0");
	for (int i=1; ; i++) {
		if (!exist(i)) {
			printf("-> %d\n", i);
			break;
		} else {
			printf("%d\n", i);
		}
	}
	
	
	return 0;
}
