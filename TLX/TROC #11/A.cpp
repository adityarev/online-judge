#include <cstdio>

void
do_move(char &c, int &x, int &y) {
	if (c == 'R')
		x++;
	if (c == 'L')
		x--;
	if (c == 'U')
		y++;
	if (c == 'D')
		y--;
}

int
main() {
	int x = 0;
	int y = 0;
	
	char c;
	while ((c = getchar_unlocked()) && c != '\n')
		do_move(c, x, y);
	
	printf("%d %d\n", x, y);
	
	return 0;
}

