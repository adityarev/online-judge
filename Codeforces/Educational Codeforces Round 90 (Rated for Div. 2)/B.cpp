#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iterator>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define gc(x) getchar(x)
#define pc(x) putchar(x)
#define endline pc('\n')

using namespace std;

typedef long long LL;

string
create_ans(int len, char c) {
	string ans = "";
	for (int i = 0; i < len; i++)
		ans += c;
	return ans;
}

int
main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		string s;
		cin >> s;
		
		int r_count = 0;
		int s_count = 0;
		int p_count = 0;
		
		for (const char& c: s) {
			if (c == 'R')
				r_count++;
			else if (c == 'S')
				s_count++;
			else
				p_count++;
		}
		
		if (r_count == s_count && s_count == p_count) {
			cout << s << endl;
			continue;
		}
		
		int max_count = max(max(r_count, s_count), p_count);
		
		if (r_count == max_count)
			cout << create_ans(s.length(), 'P') << endl;
		else if (s_count == max_count)
			cout << create_ans(s.length(), 'R') << endl;
		else
			cout << create_ans(s.length(), 'S') << endl;
	}
	
	return 0;
}

