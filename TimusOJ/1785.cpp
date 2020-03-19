#include <iostream>

using namespace std;

string get_ans(int n) {
	switch(n) {
		case 1 ... 4:
			return "few";
		case 5 ... 9:
			return "several";
		case 10 ... 19:
			return "pack";
		case 20 ... 49:
			return "lots";
		case 50 ... 99:
			return "horde";
		case 100 ... 249:
			return "throng";
		case 250 ... 499:
			return "swarm";
		case 500 ... 999:
			return "zounds";
		default:
			return "legion";
	}
	
	return "";
}

int main()
{
	int n;
	cin >> n;
	
	string ans = get_ans(n);
	cout << ans << endl;
	
	return 0;
}

