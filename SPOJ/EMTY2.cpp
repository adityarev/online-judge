#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int tc, cid = 1;
	char x;
	vector<char> str;
	
	scanf("%d%*c", &tc);
	while (tc--)
	{
		str.clear();
		while ((x=getchar())!='\n') {
			if (x=='0' && str.size()>=2 && str[str.size()-2] == '1' && str[str.size()-1] == '0')
				str.pop_back(), str.pop_back();
			else str.push_back(x);
		}
		
		if (str.empty()) printf ("Case %d: yes\n", cid++);
		else printf ("Case %d: no\n", cid++);
	}
	
	return 0;
}
