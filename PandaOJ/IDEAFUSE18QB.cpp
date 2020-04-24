#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	char c;
	int x = 0, y = 0;
	
	while ((c=getchar()) != '\n' && c != EOF) {
		if (c == 'N') {
			x++;
		} else if (c == 'S') {
			x--;
		} else if (c == 'E') {
			y++;
		} else if (c == 'W') {
			y--;
		} else {
			continue;
		}
	}
	
	printf("%d\n", abs(x) + abs(y));
	
	return 0;
}
