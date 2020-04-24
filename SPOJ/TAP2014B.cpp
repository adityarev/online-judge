#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int main()
{
	int tc, n, n_digit;
	stack<char> out;
	
	scanf ("%d", &tc);
	while (tc--)
	{
		scanf ("%d", &n);
		int val = 3;
		while(n>0) {
			if ((n-1) % val < val/3) out.push('+');
			else if ((n-1) % val < val*2/3) out.push('-');
			else out.push('0');
			n -= val/3;
			val *= 3;
		}
		while (!out.empty()) {
			putchar(out.top());
			out.pop();
		}
		puts("");
	}
	
	return 0;
}
