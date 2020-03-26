#include <cstdio>

#define gc(x) getchar_unlocked(x)
#define pc(x) putchar_unlocked(x)
#define endline pc('\n')

int
getint() {
	int c = gc(), val = 0;
	for (; c < 48 || c > 57; c = gc());
	for (; c > 47 && c < 58; c = gc())
		val = (val << 1) + (val << 3) + c - 48;
	return val;
}

void
show_ans(int N) {
	if (N == 0) {
		pc('1'); endline;
		return;
	}
	if (N == 1) {
		pc('0'); endline;
		return;
	}
	
	if (N & 1) {
		pc('4');
		N--;
	}
	while (N > 0) {
		pc('8');
		N -= 2;
	}
	endline;
}

int
main() {
	int N = getint();
	show_ans(N);
	
	return 0;
}

