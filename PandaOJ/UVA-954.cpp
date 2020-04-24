#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	int tc, n, a, b;
	stack<int> in, out;
	
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d", &n);
		while (n--) {
			scanf("%d %d", &a, &b);
			in.push(a+b);
		}
		
		int carry = 0, x;
		while (!in.empty()) {
			x = in.top();
			in.pop();
			carry += x;
			out.push(carry%10);
			carry/=10;
		}
		if (carry!=0) out.push(carry);
		
		while (!out.empty())
			putchar('0'+out.top()),
			out.pop();
		puts("");
		
		if (tc) puts("");
	}
	
	return 0;
}
